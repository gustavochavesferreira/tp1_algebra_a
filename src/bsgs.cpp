#include "bsgs.h"
#include "generator.h"
#include "timer_info.h"

#define ONE_MINUTE 60 * 1000000000LL

// g^x = a mod p
mpz_int baby_step_giant_step(mpz_int g, mpz_int a, mpz_int p, bool &bsgs_time_limit_exceeded, bool print_info) {
    bsgs_time_limit_exceeded = false;
    nanosecond_type const time_limit(ONE_MINUTE);
    cpu_timer timer;

    g = g % p; 
    a = a % p;

    mpz_int n = sqrt(p) + 1;
    mpz_int gn = modular_exponentiation(g, n, p);

    unordered_map<mpz_int, mpz_int> congruences_list;
    for (mpz_int q = 0, congruence = a; q <= n; ++q) {
        cpu_times const elapsed_times(timer.elapsed());
        nanosecond_type const elapsed(elapsed_times.system + elapsed_times.user);

        if(elapsed >= time_limit) {
            bsgs_time_limit_exceeded = true;
            return -1;
        }

        congruences_list[congruence] = q;
        congruence = (congruence * g) % p;
    }

    for (mpz_int q = 1, congruence; q <= n; ++q) {
        cpu_times const elapsed_times(timer.elapsed());
        nanosecond_type const elapsed(elapsed_times.system + elapsed_times.user);

        if(elapsed >= time_limit) {
            bsgs_time_limit_exceeded = true;
            return -1;
        }

        congruence = modular_exponentiation(gn, q, p);
        if (congruences_list.count(congruence)) {
            mpz_int ans = n * q - congruences_list[congruence];

            if(print_info) {
                cout << "Utilizando Baby-Step-Giant-Step, o Logaritmo Discreto é " << ans;
                cout << " - O valor foi calculado em ";
                print_timer_info(elapsed);
            }

            return ans;
        }
    }
    
    return -1;
}