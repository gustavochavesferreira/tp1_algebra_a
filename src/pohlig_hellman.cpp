#include "crt.h"
#include "bsgs.h"
#include "generator.h"
#include "timer_info.h"
#include "factorization.h"
#include "pohlig_hellman.h"
#include "naive_discrete_log.h"

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

mpz_int pohlig_hellman(mpz_int g, mpz_int y, mpz_int p, Factors p_antecessor_factors, bool print_info) {    
    // Medida de tempo
    cpu_timer timer;
    nanosecond_type const time_limit(ONE_MINUTE);
    vector<Congruence> crt_congruences;
    for(unsigned long int i=0; i<p_antecessor_factors.primes.size(); i++) {
        mpz_int current_prime = p_antecessor_factors.primes[i];
        mpz_int current_prime_exponent = p_antecessor_factors.exponents[i];
        vector<mpz_int> base_pi_digits;

        mpz_int base_generator_exponent = ((p-1) / (current_prime));
        mpz_int base_generator = modular_exponentiation(g, base_generator_exponent, p);

        for(unsigned long int j=0; j<p_antecessor_factors.exponents[i]; j++) {
            mpz_int new_exponent_denominator = exponentiation(current_prime, j+1);
            mpz_int new_exponent = ((p-1) / (new_exponent_denominator));

            mpz_int new_y = modular_exponentiation(y, new_exponent, p);
            
            mpz_int m = 1;

            unsigned long int already_found_digits = j;

            for(unsigned long int k=0; k<already_found_digits; k++) {
                // Medida de tempo
                cpu_times const elapsed_times(timer.elapsed());
                nanosecond_type const elapsed(elapsed_times.system + elapsed_times.user);
                if(elapsed >= time_limit) {
                    if(print_info) 
                        cout << "Não foi possível calcular o Logaritmo Discreto com Pohlig-Hellman" << endl;
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

            mpz_int new_digit = naive_discrete_log(base_generator, new_remainder, p, false);

            base_pi_digits.push_back(new_digit);
        }

        Congruence i_congruence;
        i_congruence.a = number_base_pi(current_prime, base_pi_digits);
        i_congruence.m = exponentiation(current_prime, current_prime_exponent);
        
        crt_congruences.push_back(i_congruence);
    }

    mpz_int ans = crt(crt_congruences);
    
    // Medida de tempo
    cpu_times const elapsed_times(timer.elapsed());
    nanosecond_type const elapsed(elapsed_times.system + elapsed_times.user);
    if(print_info) {
        cout << "Utilizando Pohlig-Hellman, o Logaritmo Discreto é " << ans;
        cout << " - O valor foi calculado em ";
        print_timer_info(elapsed);
    }

    return ans;

}   