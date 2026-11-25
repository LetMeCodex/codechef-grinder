# [Chef and Semi-Primes (CHEFPRMS)](https://www.codechef.com/problems/CHEFPRMS)
- **Difficulty Rating**: -1
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine if a given integer `N` can be expressed as the sum of two semi-primes. A semi-prime is defined as a product of two *distinct* prime numbers. The input `N` is an integer between 1 and 200, inclusive.

For example, 6 is a semi-prime (2 * 3), 10 is a semi-prime (2 * 5), 14 is a semi-prime (2 * 7), 15 is a semi-prime (3 * 5), etc. Numbers like 4 (2 * 2) are not semi-primes by this definition because the prime factors are not distinct.

## Intuition & Mathematical Observation

The key constraint in this problem is the very small maximum value of `N` (up to 200). This immediately suggests that a precomputation approach would be highly efficient. We can precompute all semi-primes up to `MAX_N_VAL = 200` once, and then answer each test case quickly using these precomputed values.

Here's the detailed strategy:

1.  **Understanding Semi-Primes**:
    *   A semi-prime is `p1 * p2` where `p1` and `p2` are prime numbers and `p1 != p2`.
    *   The smallest prime numbers are 2, 3, 5, 7, 11, ...
    *   The smallest possible semi-prime is `2 * 3 = 6`. This is an important observation, as any semi-prime must be at least 6.

2.  **Precomputation Strategy (up to `MAX_N_VAL = 200`)**:
    *   **Step 1: Find all prime numbers up to `MAX_N_VAL`**.
        We use the Sieve of Eratosthenes for this. This algorithm efficiently marks all prime numbers within a given range. We store these primes in a `vector<int> primes`.
    *   **Step 2: Generate all semi-primes up to `MAX_N_VAL`**.
        *   We iterate through all unique pairs of primes `(p1, p2)` from our `primes` vector. To ensure `p1 != p2`, we pick `p1 = primes[i]` and `p2 = primes[j]` where `j > i`.
        *   For each pair, we calculate their product `product = p1 * p2`.
        *   If `product` is less than or equal to `MAX_N_VAL`, we mark `product` as a semi-prime by setting `is_semiprime[product] = true` in a boolean array.
        *   **Optimization**: If `p1 * p2` exceeds `MAX_N_VAL`, we can `break` the inner loop (for `p2`). This is because any subsequent `p2` (which would be larger) will also result in a product greater than `MAX_N_VAL`, making further calculations with the current `p1` unnecessary.

3.  **Solving for Each Test Case**:
    *   After the `is_semiprime` array is fully populated, for a given input `N`, we need to find if there exist two semi-primes, `sp1` and `sp2`, such that `sp1 + sp2 = N`.
    *   We can iterate through all possible values for `sp1`.
        *   Since the smallest semi-prime is 6, `sp1` must be at least 6.
        *   Also, `sp2 = N - sp1` must also be at least 6. This implies `sp1 <= N - 6`.
    *   So, we iterate `sp1` from 6 up to `N - 6`.
    *   For each `sp1`, we check if `is_semiprime[sp1]` is true.
    *   If `sp1` is indeed a semi-prime, we calculate `sp2 = N - sp1`.
    *   Then, we check if `sp2` is also a semi-prime by looking up `is_semiprime[sp2]`.
    *   If both `sp1` and `sp2` are semi-primes, we have found a valid pair. We print "YES" and immediately stop processing for this test case.
    *   If the loop completes without finding such a pair, it means `N` cannot be expressed as the sum of two semi-primes, so we print "NO".

This approach is highly efficient because the precomputation is performed only once at the beginning, and the subsequent lookups and iterations for each test case are very fast due to the small `N` constraint.

## Complexity Analysis

Let `MAX_N_VAL` be the maximum possible value of `N` (200).
Let `P` be the number of prime numbers up to `MAX_N_VAL`. For `MAX_N_VAL = 200`, there are 46 prime numbers.

*   **Time Complexity**:
    *   **Precomputation**:
        *   **Sieve of Eratosthenes**: To find primes up to `MAX_N_VAL`, the time complexity is approximately $O(MAX\_N\_VAL \log \log MAX\_N\_VAL)$.
        *   **Generating Semi-Primes**: Iterating through pairs of primes takes $O(P^2)$ time.
        *   **Total Precomputation Time**: $O(MAX\_N\_VAL \log \log MAX\_N\_VAL + P^2)$.
    *   **Per Test Case**:
        *   Iterating `sp1` from 6 up to `N-6` takes $O(N)$ time. Each check `is_semiprime[x]` is an $O(1)$ operation.
        *   **Total Per Test Case Time**: $O(N)$.
    *   **Overall Time Complexity**: $O(MAX\_N\_VAL \log \log MAX\_N\_VAL + P^2 + T \cdot N)$, where $T$ is the number of test cases.
        *   With `MAX_N_VAL = 200`, `P = 46`, and `T` up to 100:
            *   $200 \log \log 200 \approx 480$ operations.
            *   $46^2 \approx 2116$ operations.
            *   $100 \cdot 200 = 20000$ operations.
            *   The total operations are roughly $480 + 2116 + 20000 \approx 22600$, which is extremely fast and well within typical time limits for competitive programming (usually $10^8$ operations per second).

*   **Space Complexity**:
    *   `is_prime_sieve` array (used during sieve): $O(MAX\_N\_VAL)$.
    *   `primes` vector: $O(P)$.
    *   `is_semiprime` array: $O(MAX\_N\_VAL)$.
    *   **Overall Space Complexity**: $O(MAX\_N\_VAL)$. This translates to $O(200)$ boolean values and a vector of 46 integers, which is negligible memory usage.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries

using namespace std; // Use the standard namespace

// Maximum value of N as per constraints
const int MAX_N_VAL = 200;

// Global arrays for precomputation
// Stores all prime numbers up to MAX_N_VAL
vector<int> primes;
// is_semiprime[i] is true if i is a semi-prime, false otherwise
bool is_semiprime[MAX_N_VAL + 1];

// Function to precompute primes and semi-primes up to MAX_N_VAL
void precompute() {
    // Sieve of Eratosthenes to find primes up to MAX_N_VAL
    vector<bool> is_prime_sieve(MAX_N_VAL + 1, true);
    is_prime_sieve[0] = is_prime_sieve[1] = false; // 0 and 1 are not prime
    for (int p = 2; p * p <= MAX_N_VAL; ++p) {
        if (is_prime_sieve[p]) {
            // Mark multiples of p as not prime
            for (int i = p * p; i <= MAX_N_VAL; i += p)
                is_prime_sieve[i] = false;
        }
    }
    // Collect all prime numbers into the 'primes' vector
    for (int p = 2; p <= MAX_N_VAL; ++p) {
        if (is_prime_sieve[p]) {
            primes.push_back(p);
        }
    }

    // Generate semi-primes
    // A semi-prime is a product of two distinct primes (p1 * p2 where p1 != p2)
    fill(is_semiprime, is_semiprime + MAX_N_VAL + 1, false); // Initialize all to false
    for (size_t i = 0; i < primes.size(); ++i) {
        for (size_t j = i + 1; j < primes.size(); ++j) { // p2 > p1 ensures distinct primes
            int p1 = primes[i];
            int p2 = primes[j];
            int product = p1 * p2;

            // If product exceeds MAX_N_VAL, all further products with current p1
            // (and larger p2) will also exceed MAX_N_VAL.
            if (product > MAX_N_VAL) {
                break; 
            }
            is_semiprime[product] = true;
        }
    }
}

// Function to solve each test case
void solve() {
    int N;
    cin >> N;

    bool found = false;
    // Iterate through possible values for the first semi-prime (sp1)
    // The smallest semi-prime is 2*3 = 6.
    // sp1 must be less than N, because sp2 = N - sp1 must also be at least 6.
    // So, sp1 can range from 6 up to N-6.
    for (int sp1 = 6; sp1 < N; ++sp1) {
        if (is_semiprime[sp1]) {
            int sp2 = N - sp1;
            // Check if sp2 is also a semi-prime and valid (at least 6)
            if (sp2 >= 6 && is_semiprime[sp2]) {
                found = true;
                break; // Found a pair, no need to check further
            }
        }
    }

    if (found) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Precompute values once before processing any test cases
    precompute();

    int t;
    cin >> t; // Read the number of test cases
    while (t--) {
        solve(); // Solve each test case
    }

    return 0;
}
```