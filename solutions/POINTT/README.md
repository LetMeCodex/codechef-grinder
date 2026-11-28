# [Points Table (POINTT)](https://www.codechef.com/problems/POINTT)
- **Difficulty Rating**: 314
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem describes a game between two players, Alice and Bob, each having two scores: a primary score and a secondary score. We are given Alice's primary score (X), Alice's secondary score (Y), Bob's primary score (A), and Bob's secondary score (B). The task is to determine the winner based on a specific set of rules:

1.  **Primary Score Comparison**: The player with a strictly higher primary score wins.
2.  **Secondary Score Comparison (if primary scores are equal)**: If both players have the same primary score, the player with a strictly higher secondary score wins.
3.  **Tie-breaker (if all scores are equal)**: If both primary and secondary scores are equal for both players, Alice wins.

We need to output "Alice" or "Bob" accordingly.

## Intuition & Mathematical Observation

The problem essentially defines a hierarchical comparison logic. We need to follow the rules strictly in the given order. This is a classic case for using nested `if-else if-else` statements.

The intuition is straightforward:
1.  First, we compare Alice's primary score (`X`) with Bob's primary score (`A`).
    *   If `X > A`, Alice wins.
    *   If `A > X`, Bob wins.
    *   If `X == A`, we proceed to the next level of comparison.
2.  If primary scores are equal, we then compare Alice's secondary score (`Y`) with Bob's secondary score (`B`).
    *   If `Y > B`, Alice wins.
    *   If `B > Y`, Bob wins.
    *   If `Y == B`, we proceed to the final tie-breaker rule.
3.  If both primary and secondary scores are equal (`X == A` AND `Y == B`), the problem statement explicitly says Alice wins.

There are no complex mathematical observations or algorithms required; it's a direct implementation of the given conditional rules.

## Complexity Analysis

*   **Time Complexity**: $O(1)$
    The solution involves reading four integer inputs, performing a constant number of comparisons (at most two primary score comparisons and two secondary score comparisons), and printing one string. The number of operations is fixed and does not depend on the magnitude of the input scores or any other variable input size. Therefore, the time complexity is constant.

*   **Space Complexity**: $O(1)$
    The program uses a fixed amount of memory to store four integer variables (`X`, `Y`, `A`, `B`) and some minimal overhead for input/output buffers. This memory usage does not grow with the input values. Hence, the space complexity is constant.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes iostream and many other useful headers

// Using namespace std as requested
using namespace std;

int main() {
    // Fast I/O as requested
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Declare variables for scores
    int X, Y, A, B;

    // Read input: Alice's primary (X) and secondary (Y) scores,
    // Bob's primary (A) and secondary (B) scores.
    cin >> X >> Y >> A >> B;

    // Determine the winner based on the rules:
    // 1. Compare primary scores
    if (X > A) {
        // Alice's primary score is strictly greater than Bob's. Alice wins.
        cout << "Alice\n";
    } else if (A > X) {
        // Bob's primary score is strictly greater than Alice's. Bob wins.
        cout << "Bob\n";
    } else {
        // Primary scores are equal (X == A). Proceed to compare secondary scores.
        // 2. Compare secondary scores
        if (Y > B) {
            // Alice's secondary score is strictly greater than Bob's. Alice wins.
            cout << "Alice\n";
        } else if (B > Y) {
            // Bob's secondary score is strictly greater than Alice's. Bob wins.
            cout << "Bob\n";
        } else {
            // Both primary and secondary scores are equal (X == A and Y == B).
            // 3. Apply tiebreaker rule: Alice wins.
            cout << "Alice\n";
        }
    }

    return 0;
}
```