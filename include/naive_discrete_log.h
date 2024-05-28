#ifndef NAIVE_DISCRETE_LOG
#define NAIVE_DISCRETE_LOG

#include <boost/multiprecision/gmp.hpp>

using namespace std;
using namespace boost::multiprecision;

mpz_int naive_discrete_log(const mpz_int& h, const mpz_int& g, const mpz_int& p);

#endif
