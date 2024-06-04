#include "factorization.h"
#include "timer_info.h"

#define ONE_MINUTE 60 * 1000000000LL

Factors default_composite_factorization(mpz_int n, bool &factorization_time_limit_exceeded) {
    factorization_time_limit_exceeded = false;
    
    cpu_timer timer;
    nanosecond_type const time_limit(ONE_MINUTE);

    Factors factors_n;
    for (mpz_int d = 2; d * d <= n; d++) {

        cpu_times const elapsed_times(timer.elapsed());
        nanosecond_type const elapsed(elapsed_times.system + elapsed_times.user);
        
        if (elapsed >= time_limit) {
            factorization_time_limit_exceeded = true;
            return factors_n;
        }

        if (n % d == 0) {
            mpz_int exp = 0;
            factors_n.primes.push_back(d);
            while (n % d == 0) {
                n /= d;
                exp++;
            }
            factors_n.exponents.push_back(exp);
        }
    }

    if (n > 1) {
        factors_n.primes.push_back(n);
        factors_n.exponents.push_back(1);
    }

    return factors_n;
}