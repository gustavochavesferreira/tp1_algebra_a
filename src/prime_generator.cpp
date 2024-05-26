#include "prime_generator.h"

void generatePrimes(std::list<int>* primes, int n){
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