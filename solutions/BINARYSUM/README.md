# [Binary Sum (BINARYSUM)](https://www.codechef.com/problems/BINARYSUM)
- **Difficulty Rating**: 1015
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine if it's possible to construct a binary string $S$ of length $N$ such that it contains exactly $K$ ones, and for all $1 \le i < N$, the character $S_i$ is different from $S_{i+1}$. We need to output "YES" if such a string exists, and "NO" otherwise. This needs to be done for $T$ test cases.

## Intuition & Mathematical Observation

The core constraint is $S_i \neq S_{i+1}$ for all $1 \le i < N$. This condition implies that adjacent characters in the string must always be different. Such a string must alternate between '0' and '1'.

There are only two possible patterns for a binary string that satisfies this alternating condition:
1.  **Starts with '0'**: The string will look like "010101..."
2.  **Starts with '1'**: The string will look like "101010..."

Let's analyze the number of '1's (which is $K$) for each of these patterns, given the string length $N$.

### Case 1: String starts with '0' ("010101...")

*   If $N=1$: "0" (0 ones)
*   If $N=2$: "01" (1 one)
*   If $N=3$: "010" (1 one)
*   If $N=4$: "0101" (2 ones)
*   If $N=5$: "01010" (2 ones)

Observing the pattern, the number of '1's in a string of length $N$ starting with '0' is $\lfloor N/2 \rfloor$.
For example:
*   $N=4: \lfloor 4/2 \rfloor = 2$ ones.
*   $N=5: \lfloor 5/2 \rfloor = 2$ ones.
In C++ integer division, `N / 2` correctly computes $\lfloor N/2 \rfloor$ for positive $N$.

### Case 2: String starts with '1' ("101010...")

*   If $N=1$: "1" (1 one)
*   If $N=2$: "10" (1 one)
*   If $N=3$: "101" (2 ones)
*   If $N=4$: "1010" (2 ones)
*   If $N=5$: "10101" (3 ones)

Observing the pattern, the number of '1's in a string of length $N$ starting with '1' is $\lceil N/2 \rceil$.
For example:
*   $N=4: \lceil 4/2 \rceil = 2$ ones.
*   $N=5: \lceil 5/2 \rceil = 3$ ones.
In C++ integer arithmetic, $\lceil N/2 \rceil$ for positive $N$ can be calculated as `(N + 1) / 2`.

### Conclusion

A valid binary string satisfying the given conditions exists if and only if the target number of ones, $K$, matches one of these two possible counts:
1.  $K = \lfloor N/2 \rfloor$ (if the string starts with '0')
2.  $K = \lceil N/2 \rceil$ (if the string starts with '1')

Therefore, the solution is to calculate these two possible counts and check if the given $K$ is equal to either of them.

## Complexity Analysis

*   **Time Complexity**: For each test case, we perform a few constant-time arithmetic operations (integer division, addition) and a comparison. This takes $O(1)$ time per test case. Since there are $T$ test cases, the total time complexity is $O(T)$.
*   **Space Complexity**: We only use a few integer variables to store $N$, $K$, and the calculated counts. This requires a constant amount of memory, $O(1)$, per test case.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes most standard libraries

using namespace std; // Use the standard namespace

void solve() {
    int N, K;
    cin >> N >> K;

    // The condition S_i != S_{i+1} means the string must alternate between '0' and '1'.
    // There are two possible patterns for such a string:
    // 1. Starts with '0': S = "010101..."
    // 2. Starts with '1': S = "101010..."

    // Let's analyze the number of '1's (which is K) for each pattern.

    // Pattern 1: String starts with '0' (e.g., "0", "01", "010", "0101", "01010")
    // The number of '1's in this pattern is floor(N/2).
    // In C++ integer division, N / 2 computes floor(N/2) for positive N.
    int k_if_starts_with_0 = N / 2;

    // Pattern 2: String starts with '1' (e.g., "1", "10", "101", "1010", "10101")
    // The number of '1's in this pattern is ceil(N/2).
    // In C++ integer arithmetic, ceil(N/2) for positive N can be calculated as (N + 1) / 2.
    int k_if_starts_with_1 = (N + 1) / 2;

    // A valid binary string exists if and only if the given K matches one of these two possible counts of '1's.
    if (K == k_if_starts_with_0 || K == k_if_starts_with_1) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output operations.
    // This is a common practice in competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Number of test cases
    cin >> T; // Read the number of test cases
    while (T--) { // Loop T times
        solve(); // Call the solve function for each test case
    }

    return 0; // Indicate successful execution
}
```