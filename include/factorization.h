#ifndef FACTORIZATION
#define FACTORIZATION

#include <boost/multiprecision/gmp.hpp>
#include <vector>

using namespace std;
using namespace boost::multiprecision;

struct Factors {
    vector<mpz_int> primes;
    vector<mpz_int> exponents;
};

Factors default_factorization(mpz_int n);

#endif
