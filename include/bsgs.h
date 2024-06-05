#ifndef BSGS
#define BSGS

#include <boost/multiprecision/gmp.hpp>
#include <unordered_map>

using namespace std;
using namespace boost::multiprecision;

// Calcula o logaritmo discreto de (a mod p) na base g utilizando o algoritmo "Baby-Step-Giant-Step"
// Imprime informações relativas ao tempo de execução caso o parâmetro print_info seja true
mpz_int baby_step_giant_step(mpz_int g, mpz_int a, mpz_int p, mpz_int num_stored_congruences, bool print_info);

#endif