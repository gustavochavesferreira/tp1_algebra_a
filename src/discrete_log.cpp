#include <boost/multiprecision/gmp.hpp>
#include <iostream>
#include <unordered_map>
#include <limits>
#include <cmath>

#include "discrete_log.h"
#include "powmod.h"

using namespace boost::multiprecision;
using namespace std;


// Função de conversão para long com verificação de limites
long safe_mpz_class_to_long(const mpz_int& value) {
    if (value > std::numeric_limits<long>::max() || value < std::numeric_limits<long>::min()) {
        throw std::overflow_error("Valor fora dos limites de long");
    }
    return value.convert_to<long>(); // Usa convert_to do Boost para converter para long
}


// Implementação ingênua do logaritmo discreto usando método de força bruta
mpz_int naive_discrete_log(const mpz_int& h, const mpz_int& g, const mpz_int& p) {
    for (mpz_int exponent = 0; exponent < p; ++exponent) {
        mpz_int current_value = powmod_gmp(g, exponent, p);
        if (current_value == h) {
            return exponent;
        }
    }
    return -1; // se nenhum logaritmo discreto for encontrado
}


// Baby-step Giant-step para logaritmo discreto
mpz_int bsgs_discrete_log(const mpz_int &a, const mpz_int &b, const mpz_int &m) {
    mpz_int a_mod = a % m;
    mpz_int b_mod = b % m;
    mpz_int k = 1;
    mpz_int add = 0;
    mpz_int g;
    mpz_int mm = m;  // Variable copy for manipulation

    while ((g = gcd(a_mod, mm)) > 1) {
        if (b_mod == k)
            return add;
        if (b_mod % g != 0)
            return -1;
        b_mod /= g;
        mm /= g;
        add++;
        k = (k * a_mod / g) % mm;
    }

    // Converta o resultado de sqrt(m.convert_to<double>()) para mpz_int explicitamente
    const mpz_int n = static_cast<mpz_int>(sqrt(m.convert_to<double>())) + 1;
    mpz_int an = 1;

    std::unordered_map<mpz_int, mpz_int> vals;
    for (mpz_int i = 0; i < n; ++i) {
        an = (an * a_mod) % mm;
    }

    mpz_int cur = b_mod;
    for (mpz_int q = 0; q <= n; ++q) {
        vals[cur] = q;
        cur = (cur * a_mod) % mm;
    }

    cur = k;
    for (mpz_int p = 1; p <= n; ++p) {
        cur = (cur * an) % mm;
        if (vals.count(cur)) {
            mpz_int ans = n * p - vals[cur] + add;
            return ans;
        }
    }

    return -1;
}
