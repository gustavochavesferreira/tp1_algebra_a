#include "generator.h"

mpz_int exponentiation(mpz_int a, mpz_int exponent) {
    mpz_int res = 1;
    while (exponent > 0) {
        if (exponent & 1)
            res = res * a;
        a = a * a;
        exponent >>= 1;
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

mpz_int find_generator(mpz_int p, bool &high_order_element, Factors &p_antecessor_factors) {
    high_order_element = false;
    bool factorization_time_limit_exceeded;
    p_antecessor_factors = default_composite_factorization(p - 1, factorization_time_limit_exceeded);

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

    mpz_int generator = 1;
    for(unsigned long i=0; i<generator_factors.size(); i++) 
        generator = (generator * generator_factors[i]) % p; 

    if(factorization_time_limit_exceeded) {
        high_order_element = true;

        mpz_int last_b_exponent = 1;
        for(unsigned long int i=0; i<p_antecessor_factors.primes.size(); i++) 
            last_b_exponent *= (exponentiation(p_antecessor_factors.primes[i], p_antecessor_factors.exponents[i]));
        
        mpz_int min_order = last_b_exponent;

        mpz_int a = 2;
        while(modular_exponentiation(a, last_b_exponent, p) == 1) 
            a++;

        mpz_int last_bi = modular_exponentiation(a, last_b_exponent, p);
        generator_factors.push_back(last_bi);

        generator = (generator * generator_factors[generator_factors.size()-1]) % p;

        cout << "Não foi possível computar um gerador!" << endl;
        cout << "Um elemento de ordem alta é " << generator << endl;
        cout << "A ordem mínima é " << min_order << endl;

        return generator;
    }

    cout << "Um gerador de Z(" << p << ") é " << generator << endl;

    return generator;
}