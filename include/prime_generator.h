#ifndef PRIME_GENERATOR_H
#define PRIME_GENERATOR_H

#include <list>
#include <boost/multiprecision/gmp.hpp>

// Gera os n primeiros números primos e os armazena em uma lista
void generate_primes(std::list<int>* primes, long unsigned int n);

#endif