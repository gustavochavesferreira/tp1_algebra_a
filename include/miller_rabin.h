#ifndef MILLER_RABIN
#define MILLER_RABIN

#include <boost/random.hpp>
#include <boost/multiprecision/gmp.hpp>

using namespace std;
using namespace boost::multiprecision;
using namespace boost::random;

bool single_test(mpz_int a, mpz_int N);

bool miller_rabin(mpz_int N, int k=40);

mpz_int find_next_prime(mpz_int N);

#endif

