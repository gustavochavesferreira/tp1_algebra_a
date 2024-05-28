#include "crt.h"
#include "bsgs.h"
#include "generator.h"
#include "miller_rabin.h"
#include "factorization.h"
#include "pohlig_hellman.h"
#include "prime_generator.h"
#include "naive_discrete_log.h"

int main() {
    mpz_int N, a; 
    cout << "Insira os números N e a, respectivamente: ";
    cin >> N >> a;
        
    mpz_int next_prime = find_next_prime(N);
    cout << "O menor primo maior do que " << N << " é " << next_prime << endl;

    mpz_int generator = find_generator(next_prime);
    cout << "Um gerador de Z(" << next_prime << ") é " << generator << endl;

    mpz_int naive_discrete_log_bsgs = naive_discrete_log(generator, a, next_prime);
    cout << "Utilizando força bruta, o Logaritmo Discreto de (" << a << " mod " << next_prime << ") na base " << generator << " é " << naive_discrete_log_bsgs << endl;

    mpz_int bsgs_discrete_log = baby_stp_giant_step(generator, a, next_prime);
    cout << "Utilizando Baby-Step-Giant-Step, o Logaritmo Discreto de (" << a << " mod " << next_prime << ") na base " << generator << " é " << bsgs_discrete_log << endl;

    mpz_int ph_discrete_log = pohlig_hellman(generator, a, next_prime);
    cout << "Utilizando Pohlig-Hellman, o Logaritmo Discreto de (" << a << " mod " << next_prime << ") na base " << generator << " é " << ph_discrete_log << endl;
    
    return 0;
}