#include "naive_discrete_log.h"

mpz_int naive_discrete_log(const mpz_int& g, const mpz_int& h, const mpz_int& p) {
    for (mpz_int exponent = 1; exponent < p; ++exponent) {
        mpz_int current_value = powm(g, exponent, p);
        if (current_value == h) {
            return exponent;
        }
    }
    return -1; // se nenhum logaritmo discreto for encontrado
}