# [Table Strength (STRONGTABLE)](https://www.codechef.com/problems/STRONGTABLE)
- **Difficulty Rating**: 1211
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to find the maximum possible total weight a table can support. We are given `N` table legs, each with a specific strength `W_i`. If we choose a subset of these legs to support the table, the table's total strength is calculated as: `(number of chosen legs) * (minimum strength among the chosen legs)`. Our goal is to select a subset of legs such that this product is maximized.

## Intuition & Mathematical Observation

Let's denote the number of chosen legs as `k` and the minimum strength among them as `W_min`. We want to maximize `k * W_min`.

Consider a specific leg with strength `W_j`. If we decide that `W_j` will be the *minimum* strength leg in our chosen subset, then to maximize the total weight for this specific `W_min` value, we should include `W_j` and *all other legs* whose strength is greater than or equal to `W_j`. This is because including more legs (as long as their strength is `>= W_j`) increases `k` without changing `W_min`, thus increasing the product `k * W_min`.

This leads to a straightforward strategy:
1.  **Sort the leg strengths**: Sort all `N` leg strengths in non-decreasing order. Let the sorted strengths be `w_0, w_1, ..., w_{n-1}`.
2.  **Iterate and calculate**: For each leg `w_i` (from `i = 0` to `n-1`), consider it as the potential minimum strength leg (`W_min = w_i`).
    *   If `w_i` is the minimum strength, then all legs from `w_i` to `w_{n-1}` (inclusive) can be part of the subset, as their strengths are all greater than or equal to `w_i`.
    *   The number of such legs is `(n - i)`.
    *   The total weight this configuration can support is `(n - i) * w_i`.
3.  **Find the maximum**: Calculate this product for every `i` and keep track of the maximum value found. This maximum value will be our answer.

**Example:**
Leg strengths: `[10, 20, 5, 15]`
1.  **Sorted strengths**: `[5, 10, 15, 20]` (where `n=4`)
2.  **Calculations**:
    *   If `w_0 = 5` is `W_min`: Legs `[5, 10, 15, 20]`. Count = 4. Weight = `4 * 5 = 20`.
    *   If `w_1 = 10` is `W_min`: Legs `[10, 15, 20]`. Count = 3. Weight = `3 * 10 = 30`.
    *   If `w_2 = 15` is `W_min`: Legs `[15, 20]`. Count = 2. Weight = `2 * 15 = 30`.
    *   If `w_3 = 20` is `W_min`: Legs `[20]`. Count = 1. Weight = `1 * 20 = 20`.
3.  **Maximum weight**: `max(20, 30, 30, 20) = 30`.

**Data Type Consideration**: The number of legs `N` can be up to `10^5`, and individual leg strength `W_i` can be up to `10^9`. Their product `N * W_i` can therefore be up to `10^5 * 10^9 = 10^{14}`. This value exceeds the capacity of a standard 32-bit integer (`int`), which typically holds up to `~2 * 10^9`. Thus, `long long` must be used for storing the `max_possible_weight` and intermediate product calculations to prevent overflow.

## Complexity Analysis

*   **Time Complexity**:
    *   Reading `N` leg strengths: $O(N)$
    *   Sorting the `N` leg strengths: $O(N \log N)$
    *   Iterating through the sorted strengths (the `for` loop): $O(N)$ iterations, each involving constant time operations (multiplication, comparison).
    *   Total time complexity for one test case: $O(N) + O(N \log N) + O(N) = O(N \log N)$.
    *   Given `T` test cases, the overall time complexity is $O(T \cdot N \log N)$.

*   **Space Complexity**:
    *   Storing `N` leg strengths in a `std::vector`: $O(N)$
    *   Other variables (integers, long longs) use constant space: $O(1)$
    *   Total space complexity: $O(N)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries

using namespace std; // Use standard namespace

// Function for fast I/O
void fast_io() {
    ios_base::sync_with_stdio(false); // Untie C-style I/O from C++ streams
    cin.tie(NULL);                     // Untie cin from cout
}

void solve() {
    int n;
    cin >> n; // Read the number of table legs
    vector<int> w(n); // Vector to store leg strengths. int is sufficient for individual W_i.
    for (int i = 0; i < n; ++i) {
        cin >> w[i]; // Read each leg strength
    }

    sort(w.begin(), w.end()); // Sort the leg strengths in non-decreasing order

    long long max_possible_weight = 0; // Initialize maximum possible weight to 0.
                                       // Use long long to prevent overflow, as N*W_i can be up to 10^14.

    // Iterate through each leg strength to consider it as the minimum strength in a subset
    for (int i = 0; i < n; ++i) {
        // If w[i] is chosen as the minimum strength leg,
        // we should include all legs with strength >= w[i] to maximize the total weight.
        // Since 'w' is sorted, these legs are w[i], w[i+1], ..., w[n-1].
        // The number of such legs is (n - i).
        long long current_legs_count = n - i;
        long long current_min_strength = w[i]; // Casts int to long long for multiplication
        
        // Calculate the total weight this specific configuration can bear
        long long current_possible_weight = current_legs_count * current_min_strength;
        
        // Update the overall maximum possible weight
        max_possible_weight = max(max_possible_weight, current_possible_weight);
    }
    
    cout << max_possible_weight << "\n"; // Output the result for the current test case
}

int main() {
    fast_io(); // Call the fast I/O function
    int t;
    cin >> t; // Read the number of test cases
    while (t--) { // Loop through each test case
        solve(); // Solve the current test case
    }
    return 0; // Indicate successful execution
}
```