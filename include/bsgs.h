#ifndef BSGS
#define BSGS

#include <boost/multiprecision/gmp.hpp>
#include <unordered_map>

using namespace std;
using namespace boost::multiprecision;

mpz_int baby_step_giant_step(mpz_int g, mpz_int a, mpz_int p, bool &bsgs_time_limit_exceeded, bool print_info);

#endif