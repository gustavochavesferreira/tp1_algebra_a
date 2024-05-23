#include "miller_rabin.h"

int main() {
    mpz_int N; cin >> N;

    cout << "O menor primo maior do que " << N << " é " << find_next_prime(N) << endl;

    return 0;
}