Here's a clean, high-quality solution writeup in GitHub-Flavored Markdown for the CodeChef problem "Two Rooks".

---

# [Two Rooks (TWOROOKS)](https://www.codechef.com/problems/TWOROOKS)
- **Difficulty Rating**: 957
- **Solved in**: 2 attempt(s)

## Problem Summary

The problem asks us to determine if two rooks, placed on a standard chessboard, attack each other. We are given the coordinates of the two rooks: $(X_1, Y_1)$ for the first rook and $(X_2, Y_2)$ for the second rook. We need to output "YES" if they attack each other, and "NO" otherwise.

## Intuition & Mathematical Observation

The fundamental rule for a rook's movement and attack on a chessboard is that it can move and attack any piece in the same row or the same column.

Therefore, two rooks attack each other if and only if:
1. They are in the same column. This means their X-coordinates must be equal ($X_1 = X_2$).
2. OR they are in the same row. This means their Y-coordinates must be equal ($Y_1 = Y_2$).

If either of these conditions is true, the rooks attack each other. If neither condition is true, they do not attack each other. This translates directly into a simple conditional check: `if (X1 == X2 || Y1 == Y2)`.

## Complexity Analysis

-   **Time Complexity**: $O(T)$
    For each test case, we read four integer coordinates and perform a constant number of operations (two comparisons and one logical OR). This takes constant time, $O(1)$. Since there are $T$ test cases, the total time complexity will be $T \times O(1) = O(T)$.

-   **Space Complexity**: $O(1)$
    We only store a few integer variables ($X_1, Y_1, X_2, Y_2, T$) at any point in time. The amount of memory used does not depend on the input values (other than the fixed size of an integer), making the space complexity constant.

## Solution Code

```cpp
#include <iostream> // Only include iostream for input/output, which is sufficient for this problem

// Use the standard namespace to avoid writing std::repeatedly
using namespace std;

// Function to solve a single test case
void solve() {
    int X1, Y1, X2, Y2;
    // Read the coordinates of the two rooks
    cin >> X1 >> Y1 >> X2 >> Y2;

    // Two rooks attack each other if they are in the same row OR the same column.
    // They are in the same column if their X-coordinates are equal (X1 == X2).
    // They are in the same row if their Y-coordinates are equal (Y1 == Y2).
    if (X1 == X2 || Y1 == Y2) {
        // If either condition is true, they attack
        cout << "YES\n"; // Using '\n' is generally faster than std::endl as it doesn't force a flush
    } else {
        // Otherwise, they do not attack
        cout << "NO\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output
    // This unties cin from cout and disables synchronization with C's stdio
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    // Read the number of test cases
    cin >> T;
    // Loop through each test case
    while (T--) {
        solve(); // Call the solve function for the current test case
    }

    return 0; // Indicate successful execution
}
```