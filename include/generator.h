#ifndef GENERATOR
#define GENERATOR

#include <vector>
#include <boost/multiprecision/gmp.hpp>
#include "factorization.h"

using namespace std;
using namespace boost::multiprecision;

// Utiliza exponenciação binária para calcular a^b
mpz_int exponentiation(mpz_int a, mpz_int b);

// Utiliza exponenciação binária para calcular a^b mod p
mpz_int modular_exponentiation(mpz_int a, mpz_int exponent, mpz_int p);

// Encontra o gerador do grupo multiplicativo Zp, sendo p um número primo
mpz_int find_generator(mpz_int p, bool &high_order_element, Factors &p_antecessor_factors);

#endif
