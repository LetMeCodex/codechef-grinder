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