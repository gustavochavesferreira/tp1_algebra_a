#ifndef CRT
#define CRT

#include <boost/multiprecision/gmp.hpp>

using namespace std;
using namespace boost::multiprecision;

struct Congruence {
    mpz_int a, m;
};

mpz_int extended_euclidean(mpz_int a, mpz_int b, mpz_int& x, mpz_int& y);

mpz_int modular_inverse(mpz_int a, mpz_int n);

mpz_int crt(vector<Congruence> const& congruences);

#endif
