#ifndef MILLER_RABIN_H
#define MILLER_RABIN_H

#include <boost/random.hpp>
#include <boost/multiprecision/gmp.hpp>

using namespace std;
using namespace boost::multiprecision;
using namespace boost::random;

bool single_test(mpz_int a, mpz_int N);

bool miller_rabin(mpz_int N, int k=40);

bool is_composite_with_small_factors(mpz_int X, list<int> n_first_primes);

mpz_int find_next_prime(mpz_int N, int number_of_primes);

#endif