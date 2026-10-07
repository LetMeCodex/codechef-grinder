#include <iostream> // For std::cin, std::cout
#include <vector>   // For std::vector
#include <cmath>    // For std::sqrt (though not directly used in final code, sqrt(N) is conceptual)
#include <algorithm> // For std::max

// Max value for n is 10^9. We need to sieve primes up to sqrt(10^9) approx 31622.
// A slightly larger constant like 32000 is chosen for safety and simplicity.
const int SQRT_MAX_N = 32000; 

// Global vectors to store precomputed primes and their sieve status.
// These are initialized once and reused across all test cases.
std::vector<int> primes;
std::vector<bool> sieve_small(SQRT_MAX_N + 1, true);

// Function to precompute primes up to SQRT_MAX_N using a standard Sieve of Eratosthenes.
void precompute_primes() {
    sieve_small[0] = sieve_small[1] = false; // 0 and 1 are not prime numbers.
    for (int p = 2; p * p <= SQRT_MAX_N; ++p) {
        if (sieve_small[p]) { // If p is prime
            // Mark all multiples of p as composite, starting from p*p.
            // Multiples smaller than p*p would have already been marked by smaller primes.
            for (int i = p * p; i <= SQRT_MAX_N; i += p)
                sieve_small[i] = false;
        }
    }
    // Collect all prime numbers found into the 'primes' vector.
    for (int p = 2; p <= SQRT_MAX_N; ++p) {
        if (sieve_small[p]) {
            primes.push_back(p);
        }
    }
}

// Function to solve a single test case.
void solve() {
    long long m, n;
    std::cin >> m >> n;

    // Create a boolean array for the segment [m, n].
    // is_prime_segment[i] corresponds to the number m + i.
    // Initialize all elements to 'true', assuming all numbers in the segment are potentially prime.
    std::vector<bool> is_prime_segment(n - m + 1, true);

    // Handle the special case where m is 1. The number 1 is not a prime number.
    if (m == 1) {
        is_prime_segment[0] = false; 
    }

    // Iterate through the precomputed list of small primes.
    for (int p : primes) {
        // Optimization: If p*p exceeds n, then p cannot have any composite multiples
        // within the range [m, n] that haven't already been marked by smaller primes.
        // The smallest composite multiple of p is p*p. If p*p is greater than n,
        // then p cannot mark any composite in the current segment.
        // If p itself is in [m, n], it will correctly remain marked as true.
        if ((long long)p * p > n) { 
            break; 
        }

        // Calculate the first multiple of p that is greater than or equal to m.
        // This is equivalent to ceil(m/p) * p.
        long long start_val = (m + p - 1) / p * p;

        // Ensure we start marking from at least p*p.
        // Multiples of p less than p*p (e.g., 2p, 3p, ..., (p-1)p) would have
        // already been marked by their smaller prime factors.
        // Also, p itself is prime and should not be marked as composite.
        start_val = std::max(start_val, (long long)p * p);

        // Mark all multiples of p in the segment [m, n] as composite.
        for (long long j = start_val; j <= n; j += p) {
            // 'j - m' gives the correct 0-based index in the 'is_prime_segment' array.
            is_prime_segment[j - m] = false;
        }
    }

    // Print all numbers in the segment that are still marked as prime.
    for (long long i = 0; i <= n - m; ++i) {
        if (is_prime_segment[i]) {
            std::cout << m + i << "\n";
        }
    }
    std::cout << "\n"; // Print a blank line after each test case's output as per problem statement.
}

int main() {
    // Optimize C++ standard streams for faster input/output operations.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    precompute_primes(); // Call the precomputation function once before processing any test cases.

    int t;
    std::cin >> t; // Read the number of test cases.
    while (t--) {
        solve(); // Solve each test case.
    }

    return 0;
}