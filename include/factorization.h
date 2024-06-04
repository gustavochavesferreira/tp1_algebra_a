#ifndef FACTORIZATION
#define FACTORIZATION

#include <vector>
#include <boost/timer/timer.hpp>
#include <boost/multiprecision/gmp.hpp>

using namespace std;
using namespace boost::multiprecision;
using namespace boost::timer;

struct Factors {
    vector<mpz_int> primes;
    vector<mpz_int> exponents;
};

Factors default_composite_factorization(mpz_int n, bool &factorization_time_limit_exceeded);

#endif
