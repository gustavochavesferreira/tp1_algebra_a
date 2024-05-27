#ifndef DISCRETE_LOG_H
#define DISCRETE_LOG_H

#include <boost/multiprecision/gmp.hpp>

using namespace boost::multiprecision;

long safe_mpz_class_to_long(const mpz_int& value);
mpz_int naive_discrete_log(const mpz_int& h, const mpz_int& g, const mpz_int& p);
mpz_int bsgs_discrete_log(const mpz_int &a, const mpz_int &b, const mpz_int &m);

#endif