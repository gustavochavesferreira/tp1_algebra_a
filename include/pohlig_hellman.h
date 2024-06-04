#ifndef POHLIG_HELLMAN
#define POHLIG_HELLMAN

#include <boost/random.hpp>
#include <boost/multiprecision/gmp.hpp>

using namespace std;
using namespace boost::multiprecision;

mpz_int number_base_pi(mpz_int pi, vector<mpz_int> base_pi_digits);

mpz_int pohlig_hellman(mpz_int g, mpz_int y, mpz_int p, bool &pohlig_hellman_time_limit_exceeded, bool print_info);

#endif