# [Sign Moves (SIGNMOVE)](https://www.codechef.com/problems/SIGNMOVE)
- **Difficulty Rating**: 1126
- **Solved in**: 1 attempt(s)

## Problem Summary

Chef starts at an initial position of $0$. He performs $N$ moves. For each move $i$ (from $1$ to $N$):
*   If Chef's current position is non-negative (i.e., $\ge 0$), he moves $i$ steps backward. His new position becomes `current_position - i`.
*   If Chef's current position is negative (i.e., $< 0$), he moves $i$ steps forward. His new position becomes `current_position + i`.

The task is to determine Chef's final position after $N$ moves.

## Intuition & Mathematical Observation

Let's trace Chef's position for small values of $N$ to identify a pattern. Let $P_k$ denote Chef's position after $k$ moves, with $P_0 = 0$.

*   **N = 1**:
    *   $P_0 = 0$ (non-negative)
    *   $P_1 = P_0 - 1 = 0 - 1 = -1$.
    *   Final position for $N=1$: **-1**

*   **N = 2**:
    *   $P_0 = 0$ (non-negative)
    *   $P_1 = P_0 - 1 = -1$.
    *   $P_1 = -1$ (negative)
    *   $P_2 = P_1 + 2 = -1 + 2 = 1$.
    *   Final position for $N=2$: **1**

*   **N = 3**:
    *   $P_0 = 0 \to P_1 = -1$.
    *   $P_1 = -1 \to P_2 = 1$.
    *   $P_2 = 1$ (non-negative)
    *   $P_3 = P_2 - 3 = 1 - 3 = -2$.
    *   Final position for $N=3$: **-2**

*   **N = 4**:
    *   $P_0 = 0 \to P_1 = -1 \to P_2 = 1 \to P_3 = -2$.
    *   $P_3 = -2$ (negative)
    *   $P_4 = P_3 + 4 = -2 + 4 = 2$.
    *   Final position for $N=4$: **2**

*   **N = 5**:
    *   $P_0 = 0 \to P_1 = -1 \to P_2 = 1 \to P_3 = -2 \to P_4 = 2$.
    *   $P_4 = 2$ (non-negative)
    *   $P_5 = P_4 - 5 = 2 - 5 = -3$.
    *   Final position for $N=5$: **-3**

Summarizing the final positions:
*   $N=1 \to -1$
*   $N=2 \to 1$
*   $N=3 \to -2$
*   $N=4 \to 2$
*   $N=5 \to -3$

We can observe a clear pattern:
*   If $N$ is **even**, the final position is $N/2$.
*   If $N$ is **odd**, the final position is $-(N/2 + 1)$ (using integer division for $N/2$).

Let's formally prove this pattern using mathematical induction.

**Hypothesis:** For any $k \ge 0$:
*   If $k$ is even, $P_k = k/2$. (Note: $P_k \ge 0$ for $k \ge 0$)
*   If $k$ is odd, $P_k = -(k+1)/2$. (Note: $P_k < 0$ for $k \ge 1$)

**Base Cases:**
*   For $k=0$: $P_0 = 0$. $0$ is even, and $0/2 = 0$. The hypothesis holds.
*   For $k=1$: $P_0=0 \ge 0$, so $P_1 = P_0 - 1 = 0 - 1 = -1$. $1$ is odd, and $-(1+1)/2 = -2/2 = -1$. The hypothesis holds.
*   For $k=2$: $P_1=-1 < 0$, so $P_2 = P_1 + 2 = -1 + 2 = 1$. $2$ is even, and $2/2 = 1$. The hypothesis holds.

**Inductive Step:** Assume the hypothesis holds for some arbitrary $k \ge 0$. We need to show it holds for $k+1$.

**Case 1: $k$ is even.**
By our inductive hypothesis, $P_k = k/2$. Since $k$ is even and $k \ge 0$, $P_k \ge 0$.
For the $(k+1)$-th move, Chef's position $P_k$ is non-negative, so he moves backward:
$P_{k+1} = P_k - (k+1)$
Substitute $P_k = k/2$:
$P_{k+1} = k/2 - (k+1)$
$P_{k+1} = (k - 2(k+1))/2$
$P_{k+1} = (k - 2k - 2)/2$
$P_{k+1} = (-k - 2)/2 = -(k+2)/2$

Since $k$ is even, $k+1$ is odd. According to our hypothesis for an odd index $(k+1)$, the position should be $-((k+1)+1)/2 = -(k+2)/2$. This matches our derived $P_{k+1}$. Also, $-(k+2)/2$ is negative (for $k \ge 0$), consistent with $k+1$ being odd.

**Case 2: $k$ is odd.**
By our inductive hypothesis, $P_k = -(k+1)/2$. Since $k$ is odd and $k \ge 1$, $P_k < 0$.
For the $(k+1)$-th move, Chef's position $P_k$ is negative, so he moves forward:
$P_{k+1} = P_k + (k+1)$
Substitute $P_k = -(k+1)/2$:
$P_{k+1} = -(k+1)/2 + (k+1)$
$P_{k+1} = (-(k+1) + 2(k+1))/2$
$P_{k+1} = (k+1)/2$

Since $k$ is odd, $k+1$ is even. According to our hypothesis for an even index $(k+1)$, the position should be $(k+1)/2$. This matches our derived $P_{k+1}$. Also, $(k+1)/2$ is non-negative (for $k \ge 1$), consistent with $k+1$ being even.

Since the hypothesis holds for the base cases and the inductive step, the pattern is proven correct by mathematical induction. We can directly apply this pattern to find the final position for any given $N$.

## Complexity Analysis

*   **Time Complexity**: $O(1)$ per test case.
    The solution involves reading the input $N$ and then performing a constant number of arithmetic operations (modulo, division, addition, negation) to determine the final position. This takes constant time, regardless of the value of $N$. Since there are $T$ test cases, the total time complexity is $O(T)$.

*   **Space Complexity**: $O(1)$.
    The solution uses a fixed number of variables (`T`, `N`, `final_position`) to store input and results. The memory usage does not depend on the input size $N$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries

// Using the standard namespace as requested
using namespace std;

int main() {
    // Fast I/O setup as requested
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases

    while (T--) {
        long long N; // N can be up to 10^9, so long long is necessary to prevent overflow
        cin >> N; // Read N for the current test case

        long long final_position;

        // Based on the mathematical observation and proof:
        // If N is even, final position is N / 2.
        // If N is odd, final position is -(N / 2 + 1).
        // (Note: N/2 here uses integer division, e.g., 3/2 = 1).

        if (N % 2 == 0) {
            // N is even
            final_position = N / 2;
        } else {
            // N is odd
            // For odd N, integer division N/2 (e.g., 3/2) truncates to (N-1)/2 (e.g., 1).
            // So, N/2 + 1 correctly calculates (N-1)/2 + 1, which simplifies to (N+1)/2.
            final_position = -(N / 2 + 1);
        }

        cout << final_position << "\n"; // Output the final position followed by a newline
    }

    return 0; // Indicate successful execution
}
```