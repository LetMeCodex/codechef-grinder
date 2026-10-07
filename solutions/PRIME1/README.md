# [Prime Generator (PRIME1)](https://www.codechef.com/problems/PRIME1)
- **Difficulty Rating**: 1069
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to generate all prime numbers within a given range `[m, n]`, inclusive. We are given `t` test cases.
The constraints are:
*   `t` (number of test cases): $1 \le t \le 10$
*   `m` (start of range): $1 \le m \le 10^9$
*   `n` (end of range): $1 \le n \le 10^9$
*   `n - m` (length of range): $0 \le n - m \le 10^5$

For each test case, we need to print the primes in the range `[m, n]`, each on a new line, followed by a blank line.

## Intuition & Mathematical Observation

A standard Sieve of Eratosthenes is efficient for finding primes up to a certain limit `N`. However, here `N` can be as large as $10^9$. A boolean array of size $10^9$ would require $10^9$ bytes (1 GB) of memory, which is too much. Also, sieving up to $10^9$ would be too slow.

The key observation is that the *range length* `n - m` is relatively small (at most $10^5$), even though `n` itself can be very large. This suggests using a **Segmented Sieve**.

The idea behind a Segmented Sieve is:
1.  **Precompute small primes**: Any composite number `X` has at least one prime factor less than or equal to $\sqrt{X}$. For numbers up to $10^9$, we only need prime factors up to $\sqrt{10^9} \approx 31622$. We can precompute all primes up to this limit (let's say `SQRT_MAX_N = 32000`) using a standard Sieve of Eratosthenes.
2.  **Sieve the segment**: For each test case, create a boolean array `is_prime_segment` of size `n - m + 1`. `is_prime_segment[i]` will correspond to the number `m + i`. Initialize all elements to `true`.
3.  **Mark composites**: Iterate through the precomputed small primes `p`. For each `p`:
    *   Find the first multiple of `p` that is greater than or equal to `m`. Let this be `start_val`. This can be calculated as `((m + p - 1) / p) * p`.
    *   An important optimization: we only need to start marking multiples from `p*p`. Any composite `k*p` where `k < p` would have already been marked by a smaller prime factor of `k`. Also, `p` itself is prime and should not be marked. So, `start_val` should be `max(start_val, p*p)`.
    *   Iterate from `start_val` up to `n` in steps of `p`, marking `is_prime_segment[j - m]` as `false`.
4.  **Handle edge cases**:
    *   The number 1 is not prime. If `m = 1`, `is_prime_segment[0]` (corresponding to `m`) must be explicitly set to `false`.
    *   If a precomputed prime `p` itself falls within the range `[m, n]`, it will correctly remain marked `true` because we start marking its multiples from `p*p`.

By following these steps, we efficiently mark all composite numbers in the segment `[m, n]` using only the small primes, and then print the remaining numbers.

## Complexity Analysis

Let `SQRT_MAX_N` be the maximum value for $\sqrt{n}$ (approximately 32000).
Let `N_range` be the maximum length of the segment `n - m + 1` (approximately $10^5$).
Let `T` be the number of test cases (maximum 10).

*   **Time Complexity**:
    1.  **Precomputation (`precompute_primes`)**:
        *   Sieve of Eratosthenes up to `SQRT_MAX_N`: $O(SQRT\_MAX\_N \log \log SQRT\_MAX\_N)$.
        *   Collecting primes into `primes` vector: $O(SQRT\_MAX\_N)$.
        *   Total precomputation: $O(SQRT\_MAX\_N \log \log SQRT\_MAX\_N)$.
            (e.g., $32000 \cdot \log \log 32000 \approx 32000 \cdot 2.3 \approx 7.3 \cdot 10^4$ operations).
    2.  **Per Test Case (`solve`)**:
        *   Initializing `is_prime_segment`: $O(N_{range})$.
        *   Iterating through precomputed primes: For each prime `p` up to $\sqrt{n}$, we iterate through its multiples in the segment `[m, n]`. The number of operations for a prime `p` is roughly `(n - m + 1) / p`. Summing this over all primes `p` up to $\sqrt{n}$ gives approximately $O(N_{range} \log \log \sqrt{n})$.
            (e.g., $10^5 \cdot \log \log 10^9 \approx 10^5 \cdot 2.3 \approx 2.3 \cdot 10^5$ operations).
        *   Printing results: $O(N_{range})$.
        *   Total per test case: $O(N_{range} \log \log \sqrt{n})$.
    3.  **Overall Time Complexity**:
        Summing up precomputation and `T` test cases:
        $O(SQRT\_MAX\_N \log \log SQRT\_MAX\_N + T \cdot N_{range} \log \log \sqrt{N_{max}})$.
        Substituting maximum values:
        $O(32000 \log \log 32000 + 10 \cdot (10^5 \log \log 10^9))$
        $\approx O(7.3 \cdot 10^4 + 10 \cdot (2.3 \cdot 10^5))$
        $\approx O(7.3 \cdot 10^4 + 2.3 \cdot 10^6)$
        $\approx O(2.37 \cdot 10^6)$ operations, which is very efficient and well within typical time limits.

*   **Space Complexity**:
    1.  `sieve_small`: `SQRT_MAX_N` booleans. $O(SQRT\_MAX\_N)$. (e.g., 32000 bytes).
    2.  `primes`: Stores $\pi(SQRT\_MAX\_N)$ integers. $\pi(X) \approx X / \ln X$. So, $O(SQRT\_MAX\_N / \log SQRT\_MAX\_N)$. (e.g., $\pi(32000) \approx 3085$ integers, about 12KB).
    3.  `is_prime_segment`: `N_range` booleans. $O(N_{range})$. (e.g., $10^5$ bytes = 100KB).
    4.  **Total Space Complexity**: $O(SQRT\_MAX\_N + N_{range})$.
        This is approximately $32000 + 10^5$ units of memory, which is well within typical memory limits (e.g., 256MB).

## Solution Code

```cpp
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
```