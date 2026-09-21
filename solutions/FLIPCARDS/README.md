# [Flip the cards (FLIPCARDS)](https://www.codechef.com/problems/FLIPCARDS)
- **Difficulty Rating**: 641
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem presents a scenario with $N$ cards on a table. Out of these $N$ cards, $X$ cards are face up, and the remaining $N-X$ cards are face down. In a single operation, we can flip any one card. The goal is to determine the minimum number of operations required to make *all* cards either face up or *all* cards face down.

## Intuition & Mathematical Observation

We are looking for the minimum number of flips to achieve one of two target states:
1.  All cards are face up.
2.  All cards are face down.

Let's analyze the operations needed for each target state:

**Case 1: Make all cards face up.**
*   We currently have $X$ cards that are already face up. These do not need to be flipped.
*   We currently have $N-X$ cards that are face down. To make them face up, each of these $N-X$ cards must be flipped once.
*   Therefore, the total number of operations required to make all cards face up is $N-X$.

**Case 2: Make all cards face down.**
*   We currently have $X$ cards that are face up. To make them face down, each of these $X$ cards must be flipped once.
*   We currently have $N-X$ cards that are already face down. These do not need to be flipped.
*   Therefore, the total number of operations required to make all cards face down is $X$.

The problem asks for the *minimum* number of operations to achieve *either* of these two states. So, we simply need to compare the operations required for Case 1 and Case 2 and choose the smaller value.

Thus, the minimum number of operations is $\min(X, N-X)$.

## Complexity Analysis

-   **Time Complexity**: The solution involves reading two integers ($N$ and $X$) and performing a single `min` operation and a print operation for each test case. These are all constant time operations, $O(1)$. Since there are $T$ test cases, the total time complexity is $O(T)$.
-   **Space Complexity**: The solution only uses a few integer variables to store $T$, $N$, and $X$. This amount of memory is constant and does not depend on the input size. Therefore, the space complexity is $O(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; // Number of test cases
    cin >> t;
    while (t--) {
        int n, x; // n: total cards, x: cards face-up
        cin >> n >> x;

        // We have X cards face-up and N-X cards face-down.
        // Option 1: Make all cards face-up.
        //   This requires flipping the N-X face-down cards. Operations = N-X.
        // Option 2: Make all cards face-down.
        //   This requires flipping the X face-up cards. Operations = X.
        // We want the minimum number of operations, so we choose the smaller of these two options.
        cout << min(x, n - x) << "\n";
    }
    return 0;
}

```