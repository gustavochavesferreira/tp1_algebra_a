#include "generator.h"
#include "timer_info.h"
#include "naive_discrete_log.h"

#define ONE_MINUTE 60 * 1000000000LL

mpz_int naive_discrete_log(const mpz_int g, const mpz_int a, const mpz_int p, bool print_info) {
    // Medida de tempo
    nanosecond_type const time_limit(ONE_MINUTE);
    cpu_timer timer;

    for (mpz_int exponent = 1; exponent < p; ++exponent) {
        // Medida de tempo
        cpu_times const elapsed_times(timer.elapsed());
        nanosecond_type const elapsed(elapsed_times.system + elapsed_times.user);
        if(elapsed >= time_limit) {
            if(print_info) 
                cout << "Não foi possível calcular o Logaritmo Discreto com força bruta" << endl << endl;
            return -1;
        }

        mpz_int current_value = modular_exponentiation(g, exponent, p);
        if (current_value == a) {
            if(print_info) {
                cout << "Utilizando força bruta, o Logaritmo Discreto é " << exponent << endl;
                cout << "O valor foi calculado em ";
                print_timer_info(elapsed);
                cout << endl;
            }
            return exponent;
        }
    }
    
    return -1;
}