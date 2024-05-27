#ifndef POWMOD_H
#define POWMOD_H

#include <boost/multiprecision/gmp.hpp>
#include <cmath>
#include <unordered_map>

using namespace boost::multiprecision;

mpz_int powmod_gmp(mpz_int a, mpz_int e, mpz_int n);

long long binpow(long long a, long long b, long long m);

#endif
