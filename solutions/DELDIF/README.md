# [Deletion and Difference (DELDIF)](https://www.codechef.com/problems/DELDIF)
- **Difficulty Rating**: 1343
- **Solved in**: 2 attempt(s)

## Problem Summary

The problem asks us to find the minimum possible length of an array $A$ of length $N$ after performing a series of operations. There are two types of operations, both of which reduce the array length by one:
1. **Non-zero operation**: Choose two identical non-zero elements, say $X$ and $X$. Remove both $X$'s from the array and add a single $0$ to the array.
2. **Zero operation**: Choose two identical zero elements, $0$ and $0$. Remove both $0$'s from the array and add a single $0$ to the array.

Our goal is to maximize the total number of operations performed to achieve the smallest possible array length.

## Intuition & Mathematical Observation

The core idea is to maximize the number of operations, as each operation reduces the array length by one. Both types of operations essentially allow us to replace any pair of identical elements with a single $0$.

Let's analyze the operations:
1.  **Processing Non-Zero Elements**:
    *   Consider any non-zero value $X$ that appears in the array. If we have `count[X]` occurrences of $X$, we can form `count[X] / 2` pairs of $(X, X)$.
    *   Each such pair can be removed and replaced by a $0$. This constitutes one operation.
    *   Therefore, for each distinct non-zero value $X$, we can perform `count[X] / 2` operations.
    *   The total number of operations from non-zero elements, let's call it `K_non_zero`, will be the sum of `count[X] / 2` for all $X > 0$.
    *   Crucially, each of these `K_non_zero` operations also *generates* a new $0$.

2.  **Processing Zero Elements**:
    *   After performing all possible non-zero operations, we will have an updated count of zeros. This count will be the initial number of zeros (`count[0]`) plus all the `K_non_zero` zeros generated from the non-zero operations. Let's call this `current_zeros`.
    *   Now, we apply the zero operation: two $0$'s are replaced by one $0$.
    *   If we have `k` zeros, we can perform `k-1` operations to reduce them all to a single $0$, provided `k >= 1`. For example:
        *   `0` zeros: `0` operations.
        *   `1` zero: `0` operations (cannot form a pair).
        *   `2` zeros: `1` operation (`(0,0) -> 0`).
        *   `3` zeros: `2` operations (`(0,0) -> 0`, leaving `0,0`; then `(0,0) -> 0`, leaving `0`).
    *   This can be mathematically expressed as `max(0LL, current_zeros - 1)`. Let's call this `K_zero`.

3.  **Total Operations and Minimum Length**:
    *   The total number of operations performed is `total_operations = K_non_zero + K_zero`.
    *   Each operation reduces the array length by one.
    *   Therefore, the minimum possible length of the array will be `N - total_operations`.

This strategy is optimal because both operations reduce the array length by one and produce a $0$. Since $0$s can then be further reduced, generating $0$s is always beneficial. The order of operations (non-zero pairs first, then zero pairs) doesn't affect the total number of operations, as non-zero elements can only be paired with identical non-zero elements, and zeros can only be paired with identical zeros.

## Complexity Analysis

-   **Time Complexity**: $O(N)$
    *   Reading `N`: $O(1)$.
    *   Initializing the `freq` vector of size `N+1`: $O(N)$.
    *   Reading `N` elements and populating the `freq` array: This loop runs `N` times, with each operation (reading and incrementing frequency) taking $O(1)$ time. Total $O(N)$.
    *   Calculating `K_non_zero`: This loop iterates from `1` to `N` (inclusive). Each iteration involves constant time arithmetic. Total $O(N)$.
    *   Calculating `current_zeros`, `K_zero`, `total_operations`, and `min_length`: All these are constant time $O(1)$ operations.
    *   For `T` test cases, the total time complexity will be $O(T \cdot N)$.

-   **Space Complexity**: $O(N)$
    *   The `freq` vector stores counts for numbers from `0` to `N`. This requires $N+1$ integer elements, leading to $O(N)$ space.
    *   All other variables (`N`, `val`, `K_non_zero`, `current_zeros`, etc.) use constant $O(1)$ space.

## Solution Code

```cpp
#include <iostream> // Required for input/output operations (cin, cout)
#include <vector>   // Required for std::vector
#include <algorithm> // Required for std::max

// Function to solve a single test case
void solve() {
    int N;
    std::cin >> N; // Read the length of the array

    // Use a frequency array to store counts of elements.
    // Since A_i can be up to N, an array of size N+1 is needed to cover indices 0 to N.
    // Initialize all counts to 0.
    std::vector<int> freq(N + 1, 0); 
    
    // Read array elements and populate the frequency array
    for (int i = 0; i < N; ++i) {
        int val;
        std::cin >> val;
        freq[val]++;
    }

    // K_non_zero: Number of operations performed using non-zero elements.
    // Each pair of identical non-zero elements (X, X) is removed and a 0 is added.
    // This counts as one operation, reducing array length by 1.
    long long K_non_zero = 0; 
    // Iterate for values from 1 to N (non-zero elements)
    for (int v = 1; v <= N; ++v) { 
        K_non_zero += freq[v] / 2; // Each pair (freq[v]/2) contributes one operation
    }

    // current_zeros: Total number of 0s available after processing all non-zero elements.
    // This includes original 0s (freq[0]) and 0s generated from K_non_zero operations.
    long long current_zeros = freq[0] + K_non_zero; 
    
    // K_zero: Number of operations performed using 0s.
    // If there are 'k' zeros, we can perform 'k-1' operations to reduce them to a single 0 (if k >= 1).
    // If k=0, 0 operations. If k=1, 0 operations. If k=2, 1 operation. If k=3, 2 operations.
    // This is correctly captured by std::max(0LL, current_zeros - 1).
    long long K_zero = std::max(0LL, current_zeros - 1); 

    // total_operations: Sum of operations from non-zero elements and zero elements.
    // Each operation reduces the array length by 1.
    long long total_operations = K_non_zero + K_zero;

    // The minimum possible length of the array is the initial length minus the total operations performed.
    long long min_length = N - total_operations;

    std::cout << min_length << "\n"; // Output the result for the current test case
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common competitive programming optimization.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T; // Read the number of test cases
    while (T--) {
        solve(); // Call the solve function for each test case
    }

    return 0; // Indicate successful execution
}
```