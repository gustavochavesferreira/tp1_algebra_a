#include "generator.h"

mpz_int exponentiation(mpz_int a, mpz_int b) {
    mpz_int res = a;
    for(mpz_int i=1; i<b; i++) 
        res *= a;

    return res;
}

mpz_int find_generator(mpz_int p) {
    Factors p_antecessor_factors = default_factorization(p - 1);
    vector<mpz_int> generator_factors;

    for(unsigned long i=0; i<p_antecessor_factors.primes.size(); i++) {
        mpz_int a = 2;
        mpz_int test_exp = ((p-1) / p_antecessor_factors.primes[i]);

        while(powm(a, test_exp, p) == 1) 
            a++;
        
        mpz_int a_exp = ((p-1) / (exponentiation(p_antecessor_factors.primes[i], p_antecessor_factors.exponents[i])));

        mpz_int bi = exponentiation(a, a_exp);

        generator_factors.push_back(bi);
    }

    mpz_int generator = generator_factors[0];
    for(unsigned long i=1; i<generator_factors.size(); i++) {
        generator *= (generator_factors[i]); 
        generator = generator % p;
    }

    return generator;
}

void test_generator(mpz_int g, mpz_int p) {
    vector<mpz_int> all_num;
    all_num.push_back(g);

    for(mpz_int i=2; i<p; i++) 
        all_num.push_back(powm(g, i, p));
    
    sort(all_num.begin(), all_num.end());

    for(mpz_int num : all_num) cout << num << endl;
}