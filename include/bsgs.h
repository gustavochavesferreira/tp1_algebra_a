#ifndef BSGS
#define BSGS

#include <boost/multiprecision/gmp.hpp>
#include <unordered_map>

using namespace std;
using namespace boost::multiprecision;

mpz_int baby_stp_giant_step(mpz_int a, mpz_int b, mpz_int m);

#endif