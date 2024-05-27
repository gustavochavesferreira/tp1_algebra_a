#include <cmath>
#include <gmp.h>
#include <iostream>
#include <numeric>
#include <unordered_map>

#include "powmod.h"

using namespace boost::multiprecision;

// High to Low powmod algorithm using GMP
mpz_int powmod_gmp(mpz_int a, mpz_int e, mpz_int n) {
    mpz_int result = 1;  // Set result to 1

    if (e == 0) {
        return result;  // If exponent is zero, the result is 1
    }

    mpz_int apow = a;
    int bitptr = mpz_sizeinbase(e.backend().data(), 2) - 1; // Find top bit in exponent
    for (; bitptr >= 0; bitptr--) {
        result = (result * result) % n;  // result <-- result^2 % n
        if (mpz_tstbit(e.backend().data(), bitptr)) {
            result = (result * apow) % n;  // result <-- (result * a) % n
        }
    }
    return result;
}

// https://cp-algorithms.com/algebra/binary-exp.html
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
