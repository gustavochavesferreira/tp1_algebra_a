#include "factorization.h"
#include "miller_rabin.h"
#include "generator.h"

int main() {
    mpz_int N; cin >> N;
    mpz_int next_prime = find_next_prime(N);
    mpz_int generator = find_generator(next_prime);

    cout << "O menor primo maior do que " << N << " é " << next_prime << endl;
    cout << "Um gerador de Z(" << next_prime << ") é " << generator << endl;

    return 0;
}