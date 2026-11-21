#include <iostream>

// Function to calculate the total number of prime factors of n (counting multiplicity)
// This is often denoted as Omega(n)
int count_total_prime_factors(int n) {
    int count = 0;
    // Iterate from 2 up to sqrt(n)
    for (int i = 2; i * i <= n; ++i) {
        // If i divides n, it's a prime factor
        while (n % i == 0) {
            count++;
            n /= i;
        }
    }
    // If n is still greater than 1 after the loop, it means the remaining n is a prime factor itself
    // (e.g., if n was initially a prime number, or if it's the largest prime factor)
    if (n > 1) {
        count++;
    }
    return count;
}

int main() {
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T;
    while (T--) {
        int X, K;
        std::cin >> X >> K;

        // The problem asks if there exists an integer A such that:
        // 1. A has exactly X positive integer divisors.
        // 2. A has exactly K prime numbers among its divisors (i.e., K distinct prime factors).
        //
        // Let A = p_1^a_1 * p_2^a_2 * ... * p_m^a_m be the prime factorization of A,
        // where p_i are distinct primes and a_i >= 1.
        //
        // From condition 2, m = K.
        // So, A = p_1^a_1 * p_2^a_2 * ... * p_K^a_K.
        //
        // From condition 1, the number of divisors of A is X.
        // The formula for the number of divisors is (a_1+1)(a_2+1)...(a_K+1).
        // So, X = (a_1+1)(a_2+1)...(a_K+1).
        //
        // Since a_i >= 1, it implies a_i+1 >= 2 for all i.
        // Thus, we need to determine if X can be expressed as a product of K integers,
        // each of which is greater than or equal to 2.
        //
        // This is equivalent to checking if X has at least K prime factors,
        // when counting multiplicity.
        //
        // If X has fewer than K prime factors (counting multiplicity), it's impossible.
        // If X has exactly P prime factors (counting multiplicity), and P >= K,
        // we can always construct such a product.
        // Let X = q_1 * q_2 * ... * q_P be the prime factors of X.
        // We can set a_1+1 = q_1, ..., a_{K-1}+1 = q_{K-1}, and
        // a_K+1 = q_K * q_{K+1} * ... * q_P.
        // Since all q_i >= 2, all a_i+1 >= 2, which means all a_i >= 1.
        // The product (a_1+1)...(a_K+1) will be X.
        //
        // So the condition is simply: count_total_prime_factors(X) >= K.

        int omega_X = count_total_prime_factors(X);

        if (omega_X >= K) {
            std::cout << 1 << "\n";
        } else {
            std::cout << 0 << "\n";
        }
    }

    return 0;
}