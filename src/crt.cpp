#include "crt.h"

mpz_int extended_euclidean(mpz_int a, mpz_int b, mpz_int& x, mpz_int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    mpz_int x1, y1;
    mpz_int d = extended_euclidean(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

mpz_int modular_inverse(mpz_int a, mpz_int m) {
    mpz_int x, y;
    mpz_int g = extended_euclidean(a, m, x, y);
    x = (x % m + m) % m;
    return x;
}

mpz_int crt(vector<Congruence> const& congruences) {
    mpz_int M = 1;
    for (auto const& congruence : congruences) 
        M *= congruence.m;

    mpz_int solution = 0;
    for (auto const& congruence : congruences) {
        mpz_int a_i = congruence.a;
        mpz_int M_i = M / congruence.m;
        mpz_int N_i = modular_inverse(M_i, congruence.m);
        solution = (solution + a_i * M_i % M * N_i) % M;
    }
    return solution;
}