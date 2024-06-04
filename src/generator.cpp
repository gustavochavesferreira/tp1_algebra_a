#include "generator.h"

mpz_int exponentiation(mpz_int a, mpz_int b) {
    mpz_int res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

mpz_int modular_exponentiation(mpz_int a, mpz_int exponent, mpz_int p) {
    a %= p;
    mpz_int res = 1;
    while (exponent > 0) {
        if (exponent & 1)
            res = res * a % p;
        a = a * a % p;
        exponent >>= 1;
    }
    return res;
}

long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

mpz_int find_generator(mpz_int p, bool &high_order_element, mpz_int &min_order) {
    bool factorization_time_limit_exceeded;
    Factors p_antecessor_factors = default_composite_factorization(p - 1, factorization_time_limit_exceeded);

    vector<mpz_int> generator_factors;
    for(unsigned long int i=0; i<p_antecessor_factors.primes.size(); i++) {
        mpz_int test_exp = ((p-1) / p_antecessor_factors.primes[i]);

        mpz_int a = 2;
        while(modular_exponentiation(a, test_exp, p) == 1) 
            a++;
        
        mpz_int a_exp = ((p-1) / (exponentiation(p_antecessor_factors.primes[i], p_antecessor_factors.exponents[i])));
        mpz_int bi = modular_exponentiation(a, a_exp, p);
        generator_factors.push_back(bi);
    }

    if(factorization_time_limit_exceeded) {
        high_order_element = true;

        mpz_int last_b_exponent = 1;
        for(unsigned long int i=0; i<p_antecessor_factors.primes.size(); i++) 
            last_b_exponent *= (exponentiation(p_antecessor_factors.primes[i], p_antecessor_factors.exponents[i]));
        
        min_order = last_b_exponent;

        mpz_int a = 2;
        while(modular_exponentiation(a, last_b_exponent, p) == 1) 
            a++;

        mpz_int last_bi = modular_exponentiation(a, last_b_exponent, p);
        generator_factors.push_back(last_bi);
    }

    mpz_int generator = 1;
    for(unsigned long i=0; i<generator_factors.size(); i++) 
        generator = (generator * generator_factors[i]) % p; 

    return generator;
}

void test_generator(mpz_int g, mpz_int p) {
    vector<mpz_int> all_num;
    all_num.push_back(g);

    for(mpz_int i=2; i<p; i++) 
        all_num.push_back(modular_exponentiation(g, i, p));
    
    sort(all_num.begin(), all_num.end());

    for(mpz_int num : all_num) cout << num << endl;
}