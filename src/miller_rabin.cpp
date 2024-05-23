#include <ctime>
#include <iostream>
#include "../include/miller_rabin.h"

bool single_test(mpz_int a, mpz_int N) {
    mpz_int exp = N - 1;

    while(!(exp & 1)) 
        exp = exp >> 1;

    if (powm(a, exp, N) == 1) 
        return true;

    while(exp < (N-1)) {
        if(powm(a, exp, N) == (N-1)) 
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

mpz_int find_next_prime(mpz_int N) {
    if(N % 2 == 0) {
        N++;
        if(miller_rabin(N))
            return N;
    }

    do {
        N+=2;
    } while(!miller_rabin(N));

    return N;
}
