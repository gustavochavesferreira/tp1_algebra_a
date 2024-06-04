#include "crt.h"
#include "bsgs.h"
#include "generator.h"
#include "miller_rabin.h"
#include "factorization.h"
#include "pohlig_hellman.h"
#include "prime_generator.h"
#include "naive_discrete_log.h"

int main() {
    mpz_int N, a; cin >> N >> a;
    mpz_int p = find_next_prime(N, 100);
    cout << "O menor primo maior do que " << N << " é " << p << endl;

    mpz_int min_order;
    bool high_order_element;
    mpz_int g = find_generator(p, high_order_element, min_order);
    if(high_order_element) {
        cout << "Não foi possível computar um gerador!" << endl;
        cout << "Um elemento de ordem alta é " << g << endl;
        cout << "A ordem mínima é " << min_order << endl;
        return 0;
    }
    cout << "Um gerador de Z(" << p << ") é " << g << endl;

    bool pohlig_hellman_time_limit_exceeded;
    pohlig_hellman(g, a, p, pohlig_hellman_time_limit_exceeded, true);
    if(pohlig_hellman_time_limit_exceeded) cout << "Não foi possível calcular o Logaritmo Discreto com Pohlig-Hellman" << endl;
    
    bool bsgs_time_limit_exceeded;
    baby_step_giant_step(g, a, p, bsgs_time_limit_exceeded, true);
    if(bsgs_time_limit_exceeded) cout << "Não foi possível calcular o Logaritmo Discreto com Baby-Step-Giant-Step" << endl;

    bool naive_discrete_log_time_limit_exceeded;
    naive_discrete_log(g, a, p, naive_discrete_log_time_limit_exceeded, true);
    if(naive_discrete_log_time_limit_exceeded) cout << "Não foi possível calcular o Logaritmo Discreto com força bruta" << endl;
    
    return 0;
}