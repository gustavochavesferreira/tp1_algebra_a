#include "factorization.h"

Factors default_factorization(mpz_int n) {
    Factors factors_n;
    
    for (mpz_int d = 2; d * d <= n; d++) {
        if (n % d == 0) {
            mpz_int exp = 0;
            factors_n.primes.push_back(d);
            while (n % d == 0) {
                n /= d;
                exp++;
            }
            factors_n.exponents.push_back(exp);
        }    
    }
    if (n > 1) {
        factors_n.primes.push_back(n);
        factors_n.exponents.push_back(1);
    }
    return factors_n;
}