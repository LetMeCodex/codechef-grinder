#include <bits/stdc++.h> // Required include for competitive programming, includes iostream, map, algorithm, etc.
using namespace std;     // Required namespace

// Global map for memoization.
// Using long long for both key (n) and value (max dollars)
// because n can be up to 10^9 and the result can also exceed 2^31-1.
map<long long, long long> memo;

/**
 * @brief Calculates the maximum amount of American dollars obtainable from a Bytelandian gold coin 'n'.
 *
 * This function uses dynamic programming with memoization to avoid redundant calculations.
 * For a given coin 'n', there are two options:
 * 1. Sell the coin directly for 'n' dollars.
 * 2. Exchange the coin for three smaller coins: n/2, n/3, and n/4 (integer division),
 *    and then recursively find the maximum dollars for each of these smaller coins, summing them up.
 * The function returns the maximum of these two options.
 *
 * @param n The integer value written on the Bytelandian gold coin.
 * @return The maximum amount of American dollars that can be obtained.
 */
long long solve(long long n) {
    // Base case: If n is 0, no dollars can be obtained.
    // For other small values of n (e.g., n=1 to n=11),
    // selling the coin directly (returning n) is often better or equal
    // to exchanging it. The max(n, ...) logic handles this naturally.
    // For example, solve(1) = max(1, solve(0)+solve(0)+solve(0)) = max(1,0) = 1.
    // solve(2) = max(2, solve(1)+solve(0)+solve(0)) = max(2,1) = 2.
    // The first n for which exchanging is better is n=12 (solve(12) = 13).
    if (n == 0) {
        return 0;
    }

    // Memoization check: If the result for 'n' has already been computed and stored,
    // return the stored value directly to avoid re-computation.
    if (memo.count(n)) {
        return memo[n];
    }

    // Recursive step: Calculate the maximum dollars.
    // Compare selling 'n' directly versus exchanging it for n/2, n/3, n/4.
    long long result = max(n, solve(n / 2) + solve(n / 3) + solve(n / 4));

    // Store the computed result in the memoization map before returning.
    // This makes it available for future calls with the same 'n'.
    memo[n] = result;
    return result;
}

int main() {
    // Optimize C++ standard streams for faster input/output operations.
    // This is a common practice in competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    // The problem specifies "several test cases" and provides sample input
    // without an explicit count 't'. This implies reading until End-Of-File (EOF).
    while (cin >> n) {
        // For each test case, clear the memoization map.
        // This ensures that results from previous test cases do not interfere
        // with the current one, treating each test case independently.
        // Given the small number of test cases (max 10) and the small number
        // of states per test case (approx 570), clearing the map is efficient enough.
        memo.clear(); 
        
        // Call the solve function to get the maximum dollars for the current 'n'
        // and print the result followed by a newline.
        cout << solve(n) << "\n";
    }

    return 0; // Indicate successful program execution.
}