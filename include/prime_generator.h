#ifndef PRIME_GENERATOR_H
#define PRIME_GENERATOR_H

#include <list>

/// @brief Gera os n primeiros números primos e os armazena em uma lista;
/// @param primos Lista onde são armazenados os n primeiros números primos;
/// @param n Quantidade de números primos a serem gerados;
void generatePrimes(std::list<int>* primos, int n);

#endif