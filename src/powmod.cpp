#include <cmath>
#include <gmp.h>
#include <iostream>
#include <numeric>
#include <unordered_map>

#include "../include/powmod.h"

using namespace boost::multiprecision;

// Function to compute GCD if std::gcd is not available
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// https://en.wikibooks.org/wiki/Algorithm_Implementation/Mathematics/Modular_Exponentiation
long powmod(long a, long e, long n) {
    long accum = 1, apow, x;
    apow = a;
    x = e;
    while (x != 0) {
        if (x & 0x01)
            accum = (accum * apow) % n;
        x >>= 1;
        apow = (apow * apow) % n;
    }
    return accum;
}

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

// Returns minimum x for which a ^ x % m = b % m.
int solve(int a, int b, int m) {
    a %= m, b %= m;
    int k = 1, add = 0, g;
    while ((g = gcd(a, m)) > 1) {
        if (b == k)
            return add;
        if (b % g)
            return -1;
        b /= g, m /= g, ++add;
        k = (k * 1ll * a / g) % m;
    }

    int n = sqrt(m) + 1;
    int an = 1;
    for (int i = 0; i < n; ++i)
        an = (an * 1ll * a) % m;
    std::unordered_map<int, int> vals;
    for (int q = 0, cur = b; q <= n; ++q) {
        vals[cur] = q;
        cur = (cur * 1ll * a) % m;
    }

    for (int p = 1, cur = k; p <= n; ++p) {
        cur = (cur * 1ll * an) % m;
        if (vals.count(cur)) {
            int ans = n * p - vals[cur] + add;
            return ans;
        }
    }
    return -1;
}
