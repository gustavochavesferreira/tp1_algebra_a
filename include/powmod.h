#ifndef POWMOD_H
#define POWMOD_H

#include <boost/multiprecision/gmp.hpp>
#include <cmath>
#include <unordered_map>

using namespace boost::multiprecision;

int gcd(int a, int b);

long powmod(long a, long e, long n);

mpz_int powmod_gmp(mpz_int a, mpz_int e, mpz_int n);

long long binpow(long long a, long long b, long long m);

int solve(int a, int b, int m);

#endif
