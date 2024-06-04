#include "crt.h"
#include "bsgs.h"
#include "generator.h"
#include "miller_rabin.h"
#include "factorization.h"
#include "pohlig_hellman.h"
#include "prime_generator.h"
#include "naive_discrete_log.h"

#define NUM_PRECOMPUTED_PRIMES 100

int main() {
    mpz_int N, a; cin >> N >> a;
    
    mpz_int p = find_next_prime(N, NUM_PRECOMPUTED_PRIMES);
    
    bool high_order_element;
    Factors p_antecessor_factors;
    mpz_int g = find_generator(p, high_order_element, p_antecessor_factors);

    if(!high_order_element) {
        pohlig_hellman(g, a, p, p_antecessor_factors, true);
    
        baby_step_giant_step(g, a, p, true);

        naive_discrete_log(g, a, p, true);
    }
    
    return 0;
}