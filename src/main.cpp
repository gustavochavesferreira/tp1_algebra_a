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
    mpz_int N, a;
    cout << "Digite os números 'N' e 'a': ";
    cin >> N >> a;

    while(N <= 0) {
        cout << "O número N deve ser positivo! Por favor, digite os números 'N' e 'a' novamente: ";
        cin >> N >> a;
    }
    cout << endl;

    mpz_int p = find_next_prime(N, NUM_PRECOMPUTED_PRIMES);

    // Tratando o caso em que o número 'a' for negativo
    // Encontramos um novo a<p que deixa o mesmo resto na divisão por p do que o anterior negativo
    if(a < 0) {
        a = a % p;
        a = p + a;
    }
    
    bool high_order_element;
    Factors p_antecessor_factors;
    mpz_int g = find_generator(p, high_order_element, p_antecessor_factors);

    if(!high_order_element) {
        pohlig_hellman(g, a, p, p_antecessor_factors, true);
    
        baby_step_giant_step(g, a, p, p, true);

        naive_discrete_log(g, a, p, true);
    }
     
    return 0;
}