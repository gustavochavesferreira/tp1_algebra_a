#include "bsgs.h"

mpz_int baby_stp_giant_step(mpz_int a, mpz_int b, mpz_int m) {
    a = a % m;
    b = b % m;

    mpz_int n = sqrt(m) + 1;

    mpz_int an = 1;
    for (mpz_int i = 0; i < n; ++i)
        an = (an * a) % m;

    unordered_map<mpz_int, mpz_int> vals;
    for (mpz_int q = 0, cur = b; q <= n; ++q) {
        vals[cur] = q;
        cur = (cur * a) % m;
    }

    for (mpz_int p = 1, cur = 1; p <= n; ++p) {
        cur = (cur * an) % m;
        if (vals.count(cur)) {
            mpz_int ans = n * p - vals[cur];
            return ans;
        }
    }
    return -1;
}