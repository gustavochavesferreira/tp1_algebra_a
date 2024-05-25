#include "miller_rabin.h"

int main() {
    mpz_int N; cin >> N;
    mpz_int res = find_next_prime(N);

    cout << "O menor primo maior do que " << N << " é " << res << endl;

    return 0;
}