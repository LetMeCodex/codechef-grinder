# [Multiple of 3 (MULT3)](https://www.codechef.com/problems/MULT3)
- **Difficulty Rating**: 297
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to find the nearest multiple of 3 to a given integer `N`. If there are two multiples of 3 that are equidistant from `N`, we should choose the smaller one.

## Intuition & Mathematical Observation

The core idea revolves around the remainder when `N` is divided by 3. Any integer `N` can be expressed in one of three forms:
1.  `N = 3k` (N is a multiple of 3)
2.  `N = 3k + 1` (N has a remainder of 1 when divided by 3)
3.  `N = 3k + 2` (N has a remainder of 2 when divided by 3)

Let's analyze each case to find the nearest multiple of 3:

*   **Case 1: `N % 3 == 0`**
    If `N` is already a multiple of 3, then `N` itself is the nearest multiple of 3.
    *   Example: If `N = 6`, `6 % 3 == 0`. The nearest multiple is `6`.

*   **Case 2: `N % 3 == 1`**
    If `N` has a remainder of 1 when divided by 3 (e.g., `N = 4`).
    *   The previous multiple of 3 is `N - 1` (e.g., `4 - 1 = 3`). This is 1 unit away from `N`.
    *   The next multiple of 3 is `N + 2` (e.g., `4 + 2 = 6`). This is 2 units away from `N`.
    Since `N - 1` is 1 unit away and `N + 2` is 2 units away, `N - 1` is the nearest multiple of 3.
    *   Example: If `N = 4`, `4 % 3 == 1`. The nearest multiple is `4 - 1 = 3`.

*   **Case 3: `N % 3 == 2`**
    If `N` has a remainder of 2 when divided by 3 (e.g., `N = 5`).
    *   The previous multiple of 3 is `N - 2` (e.g., `5 - 2 = 3`). This is 2 units away from `N`.
    *   The next multiple of 3 is `N + 1` (e.g., `5 + 1 = 6`). This is 1 unit away from `N`.
    Since `N + 1` is 1 unit away and `N - 2` is 2 units away, `N + 1` is the nearest multiple of 3.
    *   Example: If `N = 5`, `5 % 3 == 2`. The nearest multiple is `5 + 1 = 6`.

Notice that in all cases, there is a unique nearest multiple of 3 in terms of distance. The condition "If there are two multiples of 3 equidistant from N, choose the smaller one" does not actually come into play for this problem, as the distances are always 1 and 2 (or 0 for `N` itself).

The solution directly implements this logic using `if-else if-else` statements based on the value of `N % 3`.

## Complexity Analysis

*   **Time Complexity**: $O(1)$
    The program performs a fixed number of operations regardless of the input value `N`: reading an integer, a modulo operation, a few comparisons, and potentially one arithmetic operation (subtraction or addition), followed by printing. All these operations take constant time.

*   **Space Complexity**: $O(1)$
    The program uses a constant amount of memory to store a few integer variables (`N`, `remainder`). The memory usage does not scale with the input value `N`.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries
using namespace std; // Uses the standard namespace

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin from cout and prevents synchronization with C's stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; // Declare an integer variable N to store the input.
    cin >> N; // Read the integer N from standard input.

    // Calculate the remainder when N is divided by 3.
    // This remainder determines how far N is from the nearest multiple of 3.
    int remainder = N % 3;

    // Based on the remainder, determine the nearest multiple of 3.
    if (remainder == 0) {
        // If N is already a multiple of 3 (remainder is 0),
        // N itself is the nearest multiple of 3.
        cout << N << "\n";
    } else if (remainder == 1) {
        // If N has a remainder of 1 when divided by 3 (e.g., 1, 4, 7, 10),
        // then N-1 is a multiple of 3 and is 1 unit away from N.
        // The next multiple of 3, N+2, would be 2 units away.
        // Thus, N-1 is the nearest multiple of 3.
        cout << N - 1 << "\n";
    } else { // remainder == 2
        // If N has a remainder of 2 when divided by 3 (e.g., 2, 5, 8),
        // then N+1 is a multiple of 3 and is 1 unit away from N.
        // The previous multiple of 3, N-2, would be 2 units away.
        // Thus, N+1 is the nearest multiple of 3.
        cout << N + 1 << "\n";
    }

    return 0; // Indicate successful program execution.
}
```