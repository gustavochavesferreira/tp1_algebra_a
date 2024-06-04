#ifndef POHLIG_HELLMAN
#define POHLIG_HELLMAN

#include <boost/random.hpp>
#include <boost/multiprecision/gmp.hpp>

using namespace std;
using namespace boost::multiprecision;

// Calcula o valor em base decimal de um número cujos dígitos foram fornecidos em base Pi
mpz_int number_base_pi(mpz_int pi, vector<mpz_int> base_pi_digits);

// Calcula o logaritmo discreto de (a mod p) na base g utilizando o algoritmo de "Pohlig-Hellman"
// Imprime informações relativas ao tempo de execução caso o parâmetro print_info seja true
mpz_int pohlig_hellman(mpz_int g, mpz_int y, mpz_int p, Factors p_antecessor_factors, bool print_info);

#endif