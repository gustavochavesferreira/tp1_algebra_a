#ifndef CRT
#define CRT

#include <boost/multiprecision/gmp.hpp>

using namespace std;
using namespace boost::multiprecision;

// Struct auxiliar para armazenar uma congruência da forma x = a mod m, empregada no Teorema Chinês dos Restos
struct Congruence {
    mpz_int a, m;
};

// Aplica o alogritmo da divisão extendido para encontrar os coeficientes "x" e "y" da combinação linear de "a" e "b" que resulta em 1
mpz_int extended_euclidean(mpz_int a, mpz_int b, mpz_int& x, mpz_int& y);

// Calcula o inverso modular de (a mod n)
mpz_int modular_inverse(mpz_int a, mpz_int n);

// Resolve um sistema de congruências modulares utilizando o Teorema Chinês dos Restos
mpz_int crt(vector<Congruence> const& congruences);

#endif
