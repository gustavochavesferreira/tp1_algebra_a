#ifndef GENERATOR
#define GENERATOR

#include <vector>
#include <boost/multiprecision/gmp.hpp>
#include "factorization.h"

using namespace std;
using namespace boost::multiprecision;

mpz_int exponentiation(mpz_int a, mpz_int b);

mpz_int find_generator(mpz_int prime);

void test_generator(mpz_int g, mpz_int p);

#endif
