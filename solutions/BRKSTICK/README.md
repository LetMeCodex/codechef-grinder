# [Breaking Sticks (BRKSTICK)](https://www.codechef.com/problems/BRKSTICK)
- **Difficulty Rating**: 596
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to find the maximum number of operations we can perform on a given set of $N$ sticks. Each stick $i$ has an initial length $A_i$. An operation consists of choosing a stick of length $L$ (where $L > 1$) and breaking it into two new sticks of positive integer lengths $L_1$ and $L_2$, such that $L_1 + L_2 = L$. Sticks of length 1 cannot be broken further. We need to output the maximum possible number of operations.

## Intuition & Mathematical Observation
Let's analyze the effect of a single operation:
1.  **Number of Sticks**: When a stick of length $L$ is broken into two sticks of lengths $L_1$ and $L_2$, the original stick is replaced by two new sticks. This means the total number of sticks in our collection increases by one (one stick becomes two).
2.  **Total Length**: The total sum of lengths of all sticks remains constant. If a stick of length $L$ is replaced by two sticks of lengths $L_1$ and $L_2$, where $L_1 + L_2 = L$, the sum of lengths of all sticks in the system does not change.

The process of breaking sticks stops when all sticks have a length of 1. This is because the problem states that an operation can only be performed on a stick of length $L > 1$, and sticks must be broken into positive integer lengths. A stick of length 1 cannot be broken into two positive integer lengths.

Let's denote:
-   $N_{initial}$: The initial number of sticks.
-   $S_{initial}$: The initial total sum of lengths of all sticks, i.e., $S_{initial} = \sum_{i=1}^{N_{initial}} A_i$.
-   $K$: The maximum number of operations performed.

After $K$ operations:
-   The number of sticks will be $N_{final} = N_{initial} + K$, because each operation increases the stick count by one.
-   The total sum of lengths of all sticks will remain $S_{final} = S_{initial}$, due to the invariance of total length.
-   When the process stops, all $N_{final}$ sticks must have a length of 1. Therefore, the total length of these final sticks must be $N_{final} \times 1 = N_{final}$.

Combining these observations:
Since the total length is invariant, $S_{final} = S_{initial}$.
And when the process stops, $S_{final} = N_{final}$.
Therefore, we can equate the initial total sum of lengths to the final number of sticks:
$S_{initial} = N_{final}$

Substituting $N_{final} = N_{initial} + K$:
$S_{initial} = N_{initial} + K$

From this equation, we can easily find the maximum number of operations $K$:
$K = S_{initial} - N_{initial}$

So, the maximum number of breaks is simply the total sum of initial stick lengths minus the initial number of sticks.

## Complexity Analysis
-   **Time Complexity**: $O(N)$ per test case.
    -   Reading $N$ takes $O(1)$.
    -   The loop iterates $N$ times to read each stick length $A_i$ and add it to `total_sum_A`. This takes $O(N)$ time.
    -   Calculating the final result (`total_sum_A - N`) and printing it takes $O(1)$.
    -   Given that the sum of $N$ over all test cases is limited (typically $2 \times 10^5$), the overall time complexity across all test cases will be efficient enough.
-   **Space Complexity**: $O(1)$.
    -   We only use a few variables to store $N$, `total_sum_A`, and `A_i` (temporarily). No data structures that grow with $N$ are used.

## Solution Code
```cpp
#include <bits/stdc++.h> // Required header for competitive programming

// Required namespace usage
using namespace std;

void solve() {
    int N;
    cin >> N;
    // The total sum of stick lengths can be up to N * max(A_i) = 10^5 * 10^9 = 10^14.
    // An 'int' can typically hold up to ~2 * 10^9.
    // A 'long long' can hold up to ~9 * 10^18.
    // Therefore, 'total_sum_A' must be a 'long long' to prevent overflow.
    long long total_sum_A = 0; 
    for (int i = 0; i < N; ++i) {
        int A_i; // Individual A_i values fit within an 'int'.
        cin >> A_i;
        total_sum_A += A_i;
    }

    // The maximum number of breaks is calculated as (total sum of lengths) - (initial number of sticks).
    // Each break operation increases the number of sticks by one.
    // The process of breaking stops when all sticks have a length of 1, as sticks of length 1 cannot be broken further into two positive integer lengths.
    // The total sum of lengths of all sticks remains constant throughout the breaking process.
    // If we start with N sticks and their total length is S = sum(A_i),
    // and we perform K breaks, we will end up with N + K sticks.
    // When the process stops, all N + K sticks will have length 1.
    // Therefore, the total length of these final sticks is (N + K) * 1 = N + K.
    // Since the total length is invariant, S = N + K.
    // Thus, the maximum number of breaks K = S - N.
    long long breaks = total_sum_A - N;
    cout << breaks << "\n";
}

int main() {
    // Fast I/O as required by competitive programming standards
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) { // Loop through each test case
        solve();
    }

    return 0;
}
```