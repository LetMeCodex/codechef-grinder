# [Minimum Sum (MINSM)](https://www.codechef.com/problems/MINSM)
- **Difficulty Rating**: 1315
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to find the minimum possible sum of an array $A$ of $N$ positive integers. We are allowed to perform an operation any number of times: choose two distinct indices $i$ and $j$, and replace $A_i$ with $\text{gcd}(A_i, A_j)$. We want to minimize the sum of all elements in the array after applying these operations.

## Intuition & Mathematical Observation

Let's analyze the given operation: $A_i \leftarrow \text{gcd}(A_i, A_j)$.

1.  **Property of GCD**: The greatest common divisor $\text{gcd}(X, Y)$ always divides both $X$ and $Y$. Also, $\text{gcd}(X, Y) \le \min(X, Y)$. This means that applying the operation will never increase the value of $A_i$, and it will always result in a value that divides the original $A_i$.

2.  **Invariant Divisor**: Consider the greatest common divisor of all elements in the *original* array, let's call it $G = \text{gcd}(A_1, A_2, \dots, A_N)$.
    *   If $G$ divides $A_i$ and $G$ divides $A_j$, then $G$ must also divide $\text{gcd}(A_i, A_j)$.
    *   This implies that after any number of operations, every element in the array will *still be a multiple of $G$*.
    *   Since all elements must be positive integers, the minimum possible value any element $A_k$ can take is $G$ itself.

3.  **Achievability**: Can we make all elements in the array equal to $G$?
    *   Yes. We can pick any element, say $A_1$.
    *   Repeatedly apply the operation $A_1 \leftarrow \text{gcd}(A_1, A_k)$ for $k=2, \dots, N$. After these $N-1$ operations, $A_1$ will become $\text{gcd}(A_1, A_2, \dots, A_N)$, which is exactly $G$.
    *   Once we have an element equal to $G$ (e.g., $A_1 = G$), we can then make every other element $A_k$ equal to $G$ by applying $A_k \leftarrow \text{gcd}(A_k, A_1)$. Since $G$ divides $A_k$ (as established in point 2), $\text{gcd}(A_k, G)$ will simply be $G$.
    *   Thus, it is always possible to transform the array such that all its elements become $G$.

4.  **Minimum Sum**: Since each element must be at least $G$, and we can make all elements exactly $G$, the minimum possible sum of the array elements is $N \times G$.

Therefore, the solution is to calculate the GCD of all elements in the initial array and then multiply it by $N$.

## Complexity Analysis

*   **Time Complexity**:
    *   Reading $N$: $O(1)$.
    *   Reading the first element and initializing `current_gcd_val`: $O(1)$.
    *   Looping $N-1$ times:
        *   Inside the loop, we read an element: $O(1)$.
        *   We compute `std::gcd(current_gcd_val, val)`. The Euclidean algorithm for GCD takes $O(\log(\min(\text{current\_gcd\_val}, \text{val})))$ time. Since the maximum value of an element is $10^9$, $\log(10^9)$ is approximately 30.
    *   Total time for GCD computations: $(N-1) \times O(\log(\text{max\_val}))$.
    *   Calculating the final sum and printing: $O(1)$.
    *   For $T$ test cases, the total time complexity is $O(\sum N \cdot \log(\text{max\_val}))$. Given that the sum of $N$ over all test cases does not exceed $2 \cdot 10^5$, and $\text{max\_val} = 10^9$, this is roughly $2 \cdot 10^5 \cdot \log(10^9) \approx 2 \cdot 10^5 \cdot 30 = 6 \cdot 10^6$ operations, which is efficient enough.

    Therefore, the time complexity per test case is $O(N \log(\text{max\_val}))$.

*   **Space Complexity**:
    *   We only store a few variables: `N`, `current_gcd_val`, `val`, `min_sum`. We do not store the entire array.
    *   This requires a constant amount of extra space.

    Therefore, the space complexity is $O(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes iostream, vector, numeric, etc.
using namespace std; // Use standard namespace for convenience

// Function to solve a single test case
void solve() {
    int N; // Length of the array
    cin >> N; // Read N
    
    long long current_gcd_val; // Variable to store the GCD of elements processed so far
    cin >> current_gcd_val; // Read the first element A_1 and initialize current_gcd_val with it
    
    // Iterate through the remaining N-1 elements
    for (int i = 1; i < N; ++i) {
        long long val; // Variable to store the current element being read
        cin >> val; // Read the next element
        // Update current_gcd_val by taking GCD with the new element
        // std::gcd is available in C++17 via <numeric> or <bits/stdc++.h>
        current_gcd_val = std::gcd(current_gcd_val, val); 
    }
    
    // The minimum possible value for each element in the array is the overall GCD (current_gcd_val).
    // We can make all elements equal to this overall GCD.
    // Therefore, the minimum sum is N times the overall GCD.
    long long min_sum = (long long)N * current_gcd_val;
    
    // Output the minimum sum followed by a newline
    cout << min_sum << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T; // Number of test cases
    cin >> T; // Read the number of test cases
    while (T--) { // Loop T times, decrementing T each iteration
        solve(); // Call the solve function for each test case
    }
    
    return 0; // Indicate successful execution
}
```