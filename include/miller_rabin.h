#ifndef MILLER_RABIN_H
#define MILLER_RABIN_H

#include <boost/random.hpp>
#include <boost/multiprecision/gmp.hpp>

using namespace std;
using namespace boost::multiprecision;
using namespace boost::random;

// Emprega um teste unitário de Miller-Rabin, que determina com 75% de precisão números primos
bool single_test(mpz_int a, mpz_int N);

// Realiza k testes unitários de Miller-Rabin, a fim de aumentar consideravelmente a probabilidade de acerto sobre a primalidade de N
bool miller_rabin(mpz_int N, int k=40);

// Testa para "n" primos em memória se o número X é divisível por alguns deles, e portanto, não pode ser primo
bool is_composite_with_small_factors(mpz_int X, list<int> n_first_primes);

// Utiliza os "n" primos em memória e o Teste de Miller-Rabin para encontrar probalisticamente o menor primo maior do que N
mpz_int find_next_prime(mpz_int N, int number_of_primes);

#endif