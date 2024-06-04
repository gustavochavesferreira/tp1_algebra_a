#include <ctime>
#include <iostream>
#include "generator.h"
#include "miller_rabin.h"
#include "prime_generator.h"

bool single_test(mpz_int a, mpz_int N) {
    mpz_int exp = N - 1;

    while(!(exp & 1)) 
        exp = exp >> 1;

    if (modular_exponentiation(a, exp, N) == 1) 
        return true;

    while(exp < (N-1)) {
        if(modular_exponentiation(a, exp, N) == (N-1)) 
            return true;
    
        exp = exp << 1;
    }

    return false;
}

bool miller_rabin(mpz_int N, int k) {
    mpz_int a;

    for(int i=0, seed=0; i<k; i++, seed++) {
        mt19937 mt(seed);
        boost::random::uniform_int_distribution<mpz_int> teste(2, N-1);
        a = teste(mt);

        if(!single_test(a, N)) 
            return false;
    }
    
    return true;
}

bool is_composite_with_small_factors(mpz_int X, list<int> n_first_primes) {
    for(auto prime : n_first_primes) 
        if(X % prime == 0 && X != prime)
            return true;
    
    return false;
}

mpz_int find_next_prime(mpz_int N, int number_of_primes) {
    list<int> n_first_primes;
    generate_primes(&n_first_primes, number_of_primes);

    mpz_int original_N = N; 

    if(N % 2 == 0) {
        N++;
        if(!(is_composite_with_small_factors(N, n_first_primes)))
            if(miller_rabin(N)) {
                cout << "O menor primo maior do que " << original_N << " é " << N << endl;                
                return N;
            }
    }

    do {
        N+=2;
    } while(is_composite_with_small_factors(N, n_first_primes) || !miller_rabin(N));

    cout << "O menor primo maior do que " << original_N << " é " << N << endl;    
                
    return N;
}