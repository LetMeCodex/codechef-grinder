# [Spell Splice (CMIX)](https://www.codechef.com/problems/CMIX)
- **Difficulty Rating**: 910
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to find the maximum possible "combined strength" by selecting any two distinct spells from a given list of `N` spells. Each spell `i` is characterized by its volatility `V[i]` and agility `A[i]`. The combined strength of two spells, say spell `i` and spell `j`, is defined by the formula: `(A[i] * V[j]) + (V[i] * A[j])`. We need to output the maximum combined strength found across all possible unique pairs of spells.

## Intuition & Mathematical Observation

The core of this problem is to iterate through all possible unique pairs of spells and calculate their combined strength according to the given formula. Since we need to find the *maximum* combined strength, we'll keep track of the highest value encountered so far.

1.  **Iterating through pairs**: We have `N` spells. To select two *distinct* spells, say spell `i` and spell `j`, we can use nested loops. The outer loop can iterate from `i = 0` to `N-1`. The inner loop should then iterate from `j = i + 1` to `N-1`. This ensures that:
    *   `i` and `j` are always distinct (`j` starts after `i`).
    *   Each pair is considered only once (e.g., `(spell_0, spell_1)` is considered, but `(spell_1, spell_0)` is not, as their combined strength would be the same due to the commutative nature of addition and multiplication).

2.  **Combined Strength Calculation**: For each pair `(i, j)`, we calculate `current_strength = (A[i] * V[j]) + (V[i] * A[j])`.

3.  **Finding Maximum**: We initialize a variable `max_strength` to 0 (since all `V` and `A` values are positive, combined strength will always be positive). After calculating `current_strength` for a pair, we update `max_strength = max(max_strength, current_strength)`.

4.  **Data Types**: The problem constraints state `V[i]` and `A[i]` are up to 1000.
    *   An intermediate product like `A[i] * V[j]` can be up to `1000 * 1000 = 1,000,000`.
    *   The sum `(A[i] * V[j]) + (V[i] * A[j])` can be up to `1,000,000 + 1,000,000 = 2,000,000`.
    *   A standard 32-bit signed integer can hold values up to approximately `2 * 10^9`, so `int` would technically suffice. However, using `long long` for `V`, `A`, `current_strength`, and `max_strength` is a safer practice in competitive programming to prevent potential overflow issues, especially if constraints were slightly larger or if intermediate calculations could exceed `int` limits.

Given `N` is small (up to 100), this brute-force approach of checking all pairs will be very efficient.

## Complexity Analysis

*   **Time Complexity**:
    *   Reading `N` pairs of `V` and `A` values takes $O(N)$ time.
    *   The nested loops iterate through all unique pairs of spells. The outer loop runs `N` times, and the inner loop runs approximately `N/2` times on average. The total number of pairs is $N \times (N-1) / 2$, which simplifies to $O(N^2)$.
    *   Inside the inner loop, calculations (multiplication, addition) and comparison are constant time operations, $O(1)$.
    *   Therefore, the time complexity per test case is $O(N^2)$.
    *   Given `N <= 100`, $N^2 = 100^2 = 10,000$. With `T <= 100` test cases, the total operations would be around $100 \times 10,000 = 10^6$, which is well within typical time limits (usually $10^8$ operations per second).

*   **Space Complexity**:
    *   We use two vectors, `V` and `A`, each storing `N` `long long` integers to store the spell data.
    *   This requires $O(N)$ space.
    *   Given `N <= 100`, this is a very small amount of memory.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes iostream, vector, algorithm, etc.

using namespace std; // Standard namespace for convenience

void solve() {
    int N;
    cin >> N;
    
    // Using long long for V and A to be absolutely safe, though int would suffice for values up to 1000.
    // The product A[i] * V[j] can be up to 1000 * 1000 = 1,000,000.
    // The sum (A[i] * V[j]) + (V[i] * A[j]) can be up to 2,000,000.
    // These fit in a standard 32-bit signed int (max ~2*10^9).
    // However, using long long for the result 'current_strength' and 'max_strength' is good practice
    // to prevent overflow if intermediate products exceed int limits, or if constraints were slightly larger.
    vector<long long> V(N); // Vector to store volatilities
    vector<long long> A(N); // Vector to store strengths
    
    // Read spell data
    for (int i = 0; i < N; ++i) {
        cin >> V[i] >> A[i];
    }
    
    long long max_strength = 0; // Initialize max_strength to 0. All combined strengths will be positive.
    
    // Iterate through all unique pairs of spells (i, j) where i < j
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            // Calculate combined strength for spells i and j
            long long current_strength = (A[i] * V[j]) + (V[i] * A[j]);
            
            // Update max_strength if current_strength is greater
            max_strength = max(max_strength, current_strength);
        }
    }
    
    // Output the maximum strength for the current test case
    cout << max_strength << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin from cout and prevents synchronization with C's stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T; // Number of test cases
    cin >> T;
    while (T--) { // Loop through each test case
        solve();
    }
    
    return 0; // Indicate successful execution
}
```