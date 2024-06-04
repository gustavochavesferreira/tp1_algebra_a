#include "crt.h"
#include "bsgs.h"
#include "generator.h"
#include "timer_info.h"
#include "factorization.h"
#include "pohlig_hellman.h"

#define ONE_MINUTE 60 * 1000000000LL

mpz_int number_base_pi(mpz_int pi, vector<mpz_int> base_pi_digits) {
    mpz_int final_number = 0; 
    mpz_int current_pi = 1;
    for(unsigned long int i=0; i<base_pi_digits.size(); i++) {
        final_number += (base_pi_digits[i] * current_pi);
        current_pi *= pi;
    }
    return final_number;
}

mpz_int pohlig_hellman(mpz_int g, mpz_int y, mpz_int p, bool &pohlig_hellman_time_limit_exceeded, bool print_info) {
    pohlig_hellman_time_limit_exceeded = false;
    
    cpu_timer timer;
    nanosecond_type const time_limit(ONE_MINUTE);
    
    vector<Congruence> crt_congruences;
    bool factorization_time_limit_exceeded;
    Factors phi_p = default_composite_factorization(p-1, factorization_time_limit_exceeded);

    if(factorization_time_limit_exceeded) 
        return -1;
    
    for(unsigned long int i=0; i<phi_p.primes.size(); i++) {
        mpz_int current_prime = phi_p.primes[i];
        mpz_int current_prime_exponent = phi_p.exponents[i];
        vector<mpz_int> base_pi_digits;

        mpz_int base_generator_exponent = ((p-1) / (current_prime));
        mpz_int base_generator = modular_exponentiation(g, base_generator_exponent, p);

        for(unsigned long int j=0; j<phi_p.exponents[i]; j++) {
            mpz_int new_exponent_denominator = exponentiation(current_prime, j+1);
            mpz_int new_exponent = ((p-1) / (new_exponent_denominator));

            mpz_int new_y = modular_exponentiation(y, new_exponent, p);
            
            mpz_int m = 1;

            unsigned long int already_found_digits = j;

            for(unsigned long int k=0; k<already_found_digits; k++) {
                cpu_times const elapsed_times(timer.elapsed());
                nanosecond_type const elapsed(elapsed_times.system + elapsed_times.user);

                if(elapsed >= time_limit) {
                    pohlig_hellman_time_limit_exceeded = true;
                    return -1;
                }

                mpz_int current_generator_exponent_numerator = ((p-1) * (base_pi_digits[k]));
                mpz_int current_generator_exponent_denominator = exponentiation(current_prime, (j+1) - k);
                mpz_int current_generator_exponent = (current_generator_exponent_numerator / current_generator_exponent_denominator);

                mpz_int parcial_m = modular_exponentiation(g, current_generator_exponent, p);
                m = m* parcial_m;
            }

            mpz_int m_inverse = modular_inverse(m, p);  

            mpz_int new_remainder = (new_y * m_inverse) % p;

            bool bsgs_time_limit_exceeded;
            mpz_int new_digit = baby_step_giant_step(base_generator, new_remainder, p, bsgs_time_limit_exceeded, false);
            
            base_pi_digits.push_back(new_digit);
        }

        Congruence i_congruence;
        i_congruence.a = number_base_pi(current_prime, base_pi_digits);
        i_congruence.m = exponentiation(current_prime, current_prime_exponent);
        
        crt_congruences.push_back(i_congruence);
    }

    mpz_int ans = crt(crt_congruences);
    
    cpu_times const elapsed_times(timer.elapsed());
    nanosecond_type const elapsed(elapsed_times.system + elapsed_times.user);

    if(print_info) {
        cout << "Utilizando Pohlig-Hellman, o Logaritmo Discreto é " << ans;
        cout << " - O valor foi calculado em ";
        print_timer_info(elapsed);
    }

    return ans;
}   