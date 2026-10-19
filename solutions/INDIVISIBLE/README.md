# [Indivisible (INDIVISIBLE)](https://www.codechef.com/problems/INDIVISIBLE)
- **Difficulty Rating**: 787
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to find a positive integer $K$ that is strictly less than 100, such that $K$ does not divide any of three given integers $A$, $B$, and $C$. We are guaranteed that such a $K$ always exists under the given constraints.

In simpler terms, we need to find an integer $K$ where $1 < K < 100$ (since $K=1$ divides all positive integers) such that:
$A \pmod K \neq 0$
$B \pmod K \neq 0$
$C \pmod K \neq 0$

## Intuition & Mathematical Observation

1.  **Constraints on K**: The problem states that $K$ must be a positive integer strictly less than 100. This means $K$ can take values from $1, 2, \dots, 99$.
2.  **The Case of K=1**: Any positive integer is divisible by 1. Therefore, $A \pmod 1 = 0$, $B \pmod 1 = 0$, and $C \pmod 1 = 0$. This means $K=1$ can never satisfy the condition that $K$ does *not* divide $A$, $B$, and $C$. So, we can exclude $K=1$ from our search.
3.  **Small Search Space**: Since $K$ can only range from $2$ to $99$, there are at most $99 - 2 + 1 = 98$ possible values for $K$. This is a very small number.
4.  **Brute Force Approach**: Given the small search space, we can simply iterate through all possible values of $K$ starting from $2$ up to $99$. For each $K$, we check if it satisfies the condition: $A \pmod K \neq 0$ AND $B \pmod K \neq 0$ AND $C \pmod K \neq 0$.
5.  **Guaranteed Existence**: The problem statement guarantees that a valid $K$ will always exist. This means our loop will definitely find an answer and terminate. As soon as we find the first such $K$, we can print it and stop, as any valid $K$ is acceptable.

This brute-force approach is efficient enough due to the extremely small upper bound on $K$.

## Complexity Analysis

*   **Time Complexity**: For each test case, we iterate through values of $K$ from $2$ to $99$. In the worst case, we might check all $98$ possible values of $K$. Inside the loop, we perform constant-time operations (modulo and comparisons). Therefore, the time taken per test case is constant, specifically $O(98)$, which simplifies to $O(1)$. If there are $T$ test cases, the total time complexity will be $O(T \times 98) = O(T)$.
*   **Space Complexity**: We only use a few integer variables to store $A, B, C, K$, and the number of test cases $T$. This requires a constant amount of memory, so the space complexity is $O(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries

// Use the standard namespace to avoid prefixing std::
using namespace std;

// Function to solve a single test case
void solve() {
    int A, B, C;
    // Read the three integers for the current test case
    cin >> A >> B >> C;

    // Iterate through possible values of K.
    // K must be a positive integer strictly less than 100, so K ranges from 1 to 99.
    // K=1 always divides any positive integer, so it can never satisfy the condition.
    // Thus, we can start checking from K=2.
    for (int K = 2; K < 100; ++K) {
        // Check if K does not divide A AND K does not divide B AND K does not divide C
        if (A % K != 0 && B % K != 0 && C % K != 0) {
            // If all conditions are met, K is a valid answer.
            // Print K followed by a newline character.
            // Then, return from the function as any valid K is acceptable and we found one.
            cout << K << "\n";
            return;
        }
    }
    // The problem statement guarantees that a valid K will always exist under the given constraints.
    // Therefore, the loop will always find a K and return, so this line should theoretically not be reached.
}

int main() {
    // Optimize C++ standard streams for competitive programming.
    // This unties cin from cout and disables synchronization with C's stdio library,
    // leading to faster input/output operations.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Variable to store the number of test cases
    cin >> T; // Read the number of test cases

    // Loop through each test case
    while (T--) {
        solve(); // Call the solve function for the current test case
    }

    return 0; // Indicate successful program execution
}

```