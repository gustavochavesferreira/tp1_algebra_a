#include "prime_generator.h"

void generate_primes(std::list<int>* primes, long unsigned int n) {
    int i = 2;
    while(primes->size()<n ){
        bool isPrime = true;
        for(auto it = primes->begin(); it != primes->end() && isPrime; ++it){
            if (i%*it == 0) isPrime = false;
        }
        if (isPrime) primes->push_back(i);
        i++;
    }
}