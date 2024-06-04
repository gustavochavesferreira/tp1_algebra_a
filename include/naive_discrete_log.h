#ifndef NAIVE_DISCRETE_LOG
#define NAIVE_DISCRETE_LOG

#include <boost/multiprecision/gmp.hpp>
#include <boost/timer/timer.hpp>

using namespace std;
using namespace boost::multiprecision;
using namespace boost::timer;

// Calcula o logaritmo discreto de (a mod p) na base g utilizando força bruta
// Imprime informações relativas ao tempo de execução caso o parâmetro print_info seja true
mpz_int naive_discrete_log(const mpz_int g, const mpz_int a, const mpz_int p, bool print_info);

#endif
