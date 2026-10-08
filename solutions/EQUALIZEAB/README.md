# [Equalize AB (EQUALIZEAB)](https://www.codechef.com/problems/EQUALIZEAB)
- **Difficulty Rating**: 1069
- **Solved in**: 1 attempt(s)

## Problem Summary

Given two integers $A$ and $B$, and a positive integer $X$. We can perform two types of operations:
1. Increase $A$ by $X$ and decrease $B$ by $X$.
2. Decrease $A$ by $X$ and increase $B$ by $X$.

The goal is to determine if it's possible to make $A$ and $B$ equal using any number of these operations.

## Intuition & Mathematical Observation

Let the initial values be $A_{init}$ and $B_{init}$. After applying an operation, the new values $A_{new}$ and $B_{new}$ will be:

**Operation 1:** $A_{new} = A_{init} + X$, $B_{new} = B_{init} - X$
**Operation 2:** $A_{new} = A_{init} - X$, $B_{new} = B_{init} + X$

Let's analyze the sum and difference of $A$ and $B$ under these operations.

**Sum:**
- For Operation 1: $A_{new} + B_{new} = (A_{init} + X) + (B_{init} - X) = A_{init} + B_{init}$.
- For Operation 2: $A_{new} + B_{new} = (A_{init} - X) + (B_{init} + X) = A_{init} + B_{init}$.

This means the sum $A+B$ is an **invariant**. If we can make $A$ and $B$ equal to some value $K$, then their sum will be $K+K = 2K$. This implies that the sum $A+B$ must always be an even number. Therefore, a necessary condition for $A$ and $B$ to be made equal is that their initial sum $(A_{init} + B_{init})$ must be even. If $(A_{init} + B_{init})$ is odd, it's impossible to make them equal.

**Difference:**
Let $D = A - B$.
- For Operation 1: $A_{new} - B_{new} = (A_{init} + X) - (B_{init} - X) = A_{init} - B_{init} + 2X = D + 2X$.
- For Operation 2: $A_{new} - B_{new} = (A_{init} - X) - (B_{init} + X) = A_{init} - B_{init} - 2X = D - 2X$.

This shows that each operation changes the difference $A-B$ by either $+2X$ or $-2X$.
If we want to make $A$ and $B$ equal, the final difference $A_{final} - B_{final}$ must be $0$.
This means the initial difference $(A_{init} - B_{init})$ must be reachable from $0$ by adding or subtracting multiples of $2X$. In other words, the initial difference $(A_{init} - B_{init})$ must be a multiple of $2X$.
Since we are concerned with the magnitude of the difference, we can consider the absolute difference $|A - B|$. If $A$ and $B$ can be made equal, then $|A_{init} - B_{init}|$ must be a multiple of $2X$.

Combining these observations:
1. The sum $A+B$ must be even.
2. The absolute difference $|A-B|$ must be a multiple of $2X$.

If both these conditions are met, can we always make $A$ and $B$ equal?
Let $A_{init}$ and $B_{init}$ be the initial values.
If $(A_{init} + B_{init})$ is even, then $A_{init}$ and $B_{init}$ have the same parity (both even or both odd).
If $|A_{init} - B_{init}|$ is a multiple of $2X$, let $|A_{init} - B_{init}| = k \cdot (2X)$ for some non-negative integer $k$.
Without loss of generality, assume $A_{init} \ge B_{init}$. Then $A_{init} - B_{init} = k \cdot (2X)$.
We need to reach a state where $A = B$.
We can repeatedly apply Operation 1 (increase $A$ by $X$, decrease $B$ by $X$) if $A > B$. Each application reduces the difference by $2X$.
If $A_{init} - B_{init} = k \cdot (2X)$, we can apply Operation 1 exactly $k$ times.
After $k$ applications of Operation 1:
New $A = A_{init} + k \cdot X$
New $B = B_{init} - k \cdot X$
The difference becomes $(A_{init} + k \cdot X) - (B_{init} - k \cdot X) = A_{init} - B_{init} + 2k \cdot X = k \cdot (2X) + 2k \cdot X = 0$.
So, $A$ and $B$ become equal.

If $B_{init} > A_{init}$, then $B_{init} - A_{init} = k \cdot (2X)$. We can repeatedly apply Operation 2 (decrease $A$ by $X$, increase $B$ by $X$). Each application reduces the difference $B-A$ by $2X$.
After $k$ applications of Operation 2:
New $A = A_{init} - k \cdot X$
New $B = B_{init} + k \cdot X$
The difference becomes $(B_{init} + k \cdot X) - (A_{init} - k \cdot X) = B_{init} - A_{init} + 2k \cdot X = k \cdot (2X) + 2k \cdot X = 0$.
So, $A$ and $B$ become equal.

Therefore, the two conditions are both necessary and sufficient.

The conditions can be checked as:
1. $(A + B) \% 2 == 0$
2. `std::abs(A - B) % (2 * X) == 0`

Note that if $A$ and $B$ are already equal, then $|A-B| = 0$. Since $X$ is positive, $2X$ is also positive. $0$ is a multiple of any non-zero number, so $0 \% (2X) == 0$ holds true. The sum $A+B = 2A$ is also even. So, if $A$ and $B$ are initially equal, the conditions are met, and the answer is "YES", which is correct.

## Complexity Analysis

- **Time Complexity**: $O(1)$
  The solution involves a few arithmetic operations (addition, subtraction, modulo, absolute value) and comparisons. These operations take constant time. The main loop iterates $T$ times, where $T$ is the number of test cases. For each test case, the `solve()` function runs in $O(1)$ time. Therefore, the total time complexity is $O(T)$. If we consider the complexity per test case, it's $O(1)$.

- **Space Complexity**: $O(1)$
  The solution uses a fixed number of variables ($A, B, X, T$, and temporary variables for calculations) regardless of the input size. Thus, the space complexity is constant.

## Solution Code

```cpp
#include <iostream> // Required for standard input/output operations (cin, cout)
#include <cmath>    // Required for std::abs (absolute value function)

void solve() {
    long long A, B, X; // Use long long to handle values up to 10^9 safely
    std::cin >> A >> B >> X;

    // Condition 1: The sum A+B must be even.
    // The sum A+B is an invariant under the given operations.
    // If A and B become equal to some value K, their sum will be K+K = 2K, which is always even.
    // Therefore, if the initial sum (A+B) is odd, it's impossible to make A and B equal.
    if ((A + B) % 2 != 0) {
        std::cout << "NO\n";
        return; // No need to check further conditions
    }

    // Condition 2: The absolute difference |A-B| must be a multiple of 2X.
    // Let D = A-B.
    // Operation 1 changes D to D + 2X.
    // Operation 2 changes D to D - 2X.
    // In each step, the difference A-B changes by +/- 2X.
    // To make A and B equal, the final difference must be 0.
    // This means the initial difference (A-B) must be reachable from 0 by adding/subtracting multiples of 2X.
    // Equivalently, (A-B) must be a multiple of 2X.
    long long diff = std::abs(A - B);
    
    // If diff is 0, A and B are already equal, which satisfies the condition.
    // (0 is a multiple of any non-zero number, so 0 % (2*X) == 0 holds true).
    if (diff % (2 * X) == 0) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) prevents cin from flushing cout before each input operation.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T; // Variable to store the number of test cases
    std::cin >> T; // Read the number of test cases
    while (T--) { // Loop through each test case
        solve(); // Call the solve function for each test case
    }

    return 0; // Indicate successful execution
}
```