#include "generator.h"
#include "timer_info.h"
#include "naive_discrete_log.h"

#define ONE_MINUTE 60 * 1000000000LL

// g^x = a mod p
mpz_int naive_discrete_log(const mpz_int& g, const mpz_int& a, const mpz_int& p, bool &naive_discrete_log_time_limit_exceeded, bool print_info) {
    naive_discrete_log_time_limit_exceeded = false;
    nanosecond_type const time_limit(ONE_MINUTE);
    cpu_timer timer;

    for (mpz_int exponent = 1; exponent < p; ++exponent) {
        cpu_times const elapsed_times(timer.elapsed());
        nanosecond_type const elapsed(elapsed_times.system + elapsed_times.user);

        if(elapsed >= time_limit) {
            naive_discrete_log_time_limit_exceeded = true;
            return -1;
        }

        mpz_int current_value = modular_exponentiation(g, exponent, p);
        if (current_value == a) {
            if(print_info) {
                cout << "Utilizando força bruta, o Logaritmo Discreto é " << exponent;
                cout << " - O valor foi calculado em ";
                print_timer_info(elapsed);
            }
            return exponent;
        }
    }
    
    return -1;
}