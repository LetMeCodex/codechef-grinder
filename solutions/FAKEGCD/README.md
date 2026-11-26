# [Fake GCD (FAKEGCD)](https://www.codechef.com/problems/FAKEGCD)
- **Difficulty Rating**: 1362
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to find a permutation $A = [A_1, A_2, \ldots, A_N]$ of integers from $1$ to $N$ such that the greatest common divisor (GCD) of the sequence $[1+A_1, 2+A_2, \ldots, N+A_N]$ is strictly greater than $1$. We need to output any such valid permutation.

## Intuition & Mathematical Observation

The core requirement is that $\text{gcd}(1+A_1, 2+A_2, \ldots, N+A_N) > 1$.
A simple way to ensure that the GCD of a set of numbers is greater than $1$ is to make all numbers in the set divisible by a common prime number, for example, $2$. If all terms $(i+A_i)$ are even, then their GCD will be at least $2$, which satisfies the condition $ > 1$.

For a sum $(X+Y)$ to be even, $X$ and $Y$ must have the same parity:
*   If $X$ is odd, $Y$ must be odd.
*   If $X$ is even, $Y$ must be even.

Applying this to our problem, for each term $(i+A_i)$ to be even, $i$ and $A_i$ must have the same parity.
That is:
*   If $i$ is odd, $A_i$ must be odd.
*   If $i$ is even, $A_i$ must be even.

Now, we need to find a permutation $A$ of $1, \ldots, N$ that satisfies this parity condition for all $i$. The simplest permutation that achieves this is the identity permutation: $A_i = i$ for all $i$ from $1$ to $N$.

Let's verify this choice:
1.  **Is $A_i = i$ a valid permutation?** Yes, it's a permutation of $1, \ldots, N$ where each element maps to itself.
2.  **Does $A_i = i$ satisfy the parity condition?**
    *   If $i$ is odd, then $A_i = i$ is also odd. (Same parity)
    *   If $i$ is even, then $A_i = i$ is also even. (Same parity)
    So, $i$ and $A_i$ always have the same parity.
3.  **What are the terms $(i+A_i)$ with $A_i = i$?**
    The terms become $(i+i) = 2i$.
    The sequence we need to find the GCD of is $[2 \cdot 1, 2 \cdot 2, 2 \cdot 3, \ldots, 2 \cdot N]$.
4.  **What is the GCD of this sequence?**
    $\text{gcd}(2 \cdot 1, 2 \cdot 2, \ldots, 2 \cdot N) = 2 \cdot \text{gcd}(1, 2, \ldots, N)$.
    The GCD of the sequence $[1, 2, \ldots, N]$ is $1$, because $1$ is present in the sequence.
    Therefore, $\text{gcd}(2 \cdot 1, 2 \cdot 2, \ldots, 2 \cdot N) = 2 \cdot 1 = 2$.

Since $2 > 1$, the permutation $A = [1, 2, \ldots, N]$ (i.e., $A_i = i$) is a valid solution. The problem asks for any valid permutation, so this simple construction works perfectly.

## Complexity Analysis

*   **Time Complexity**: For each test case, we read an integer $N$ and then iterate from $1$ to $N$ to print $N$ numbers. This takes $O(N)$ time. Given that the sum of $N$ over all test cases is limited (typically $2 \cdot 10^5$), this approach is very efficient.
*   **Space Complexity**: We only store a few integer variables ($N$, loop counter $i$, etc.) and do not use any data structures that scale with $N$. Thus, the space complexity is $O(1)$ per test case.

## Solution Code

```cpp
#include <bits/stdc++.h> // Required header for competitive programming on CodeChef

// Use the standard namespace as requested
using namespace std;

void solve() {
    int N;
    cin >> N; // Read N for the current test case

    // The problem asks for a permutation A of values from 1 to N
    // such that gcd([1+A_1, 2+A_2, ..., N+A_N]) > 1.
    //
    // A simple and effective strategy is to make all terms (i + A_i) even.
    // If all terms are even, their GCD will be at least 2, which satisfies the condition (> 1).
    //
    // For (i + A_i) to be even, i and A_i must have the same parity.
    // That is, if i is odd, A_i must be odd.
    // If i is even, A_i must be even.
    //
    // The simplest permutation that achieves this is A_i = i for all i from 1 to N.
    // This is a valid permutation of values from 1 to N.
    //
    // With A_i = i, the terms become (i + A_i) = (i + i) = 2*i.
    // The sequence is [2*1, 2*2, 2*3, ..., 2*N].
    // All elements in this sequence are even.
    // The GCD of this sequence is gcd([2, 4, 6, ..., 2N]) = 2 * gcd([1, 2, 3, ..., N]).
    // Since 1 is present in [1, 2, 3, ..., N], gcd([1, 2, 3, ..., N]) = 1.
    // Therefore, gcd([2, 4, 6, ..., 2N]) = 2 * 1 = 2.
    // Since 2 > 1, this permutation satisfies the condition.
    //
    // The problem states that any valid permutation is acceptable.
    // Thus, printing 1 2 ... N is a correct and optimal solution.

    for (int i = 1; i <= N; ++i) {
        // Print the current number i.
        // Add a space after it unless it's the last number in the sequence.
        cout << i << (i == N ? "" : " ");
    }
    cout << "\n"; // Print a newline character after each test case's output
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming to prevent TLE (Time Limit Exceeded).
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) { // Loop through each test case
        solve(); // Call the solve function to handle the current test case
    }

    return 0; // Indicate successful program execution
}
```