#ifndef PRIME_GENERATOR_H
#define PRIME_GENERATOR_H

#include <list>
#include <boost/multiprecision/gmp.hpp>

/// @brief Gera os n primeiros números primos e os armazena em uma lista;
/// @param primos Lista onde são armazenados os n primeiros números primos;
/// @param n Quantidade de números primos a serem gerados;
void generate_primes(std::list<int>* primes, long unsigned int n);

#endif