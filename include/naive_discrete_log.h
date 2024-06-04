#ifndef NAIVE_DISCRETE_LOG
#define NAIVE_DISCRETE_LOG

#include <boost/multiprecision/gmp.hpp>
#include <boost/timer/timer.hpp>

using namespace std;
using namespace boost::multiprecision;
using namespace boost::timer;

mpz_int naive_discrete_log(const mpz_int& g, const mpz_int& a, const mpz_int& p, bool &naive_discrete_log_time_limit_exceeded, bool print_info);

#endif
