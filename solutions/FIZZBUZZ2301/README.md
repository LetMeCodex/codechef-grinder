# [Fan Poll (FIZZBUZZ2301)](https://www.codechef.com/problems/FIZZBUZZ2301)
- **Difficulty Rating**: 273
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem describes a fan poll involving three cricketers: Dhoni, Rohit, and Kohli. We are given the number of votes each player received. The task is to determine if Dhoni won the poll. Dhoni wins if he received strictly more votes than both Rohit and Kohli. A crucial piece of information is that no two players received the same number of votes.

## Intuition & Mathematical Observation

This problem is a direct application of conditional logic and comparison.
Let's denote the votes for Dhoni as `A`, for Rohit as `B`, and for Kohli as `C`.

Dhoni wins the poll if and only if his vote count (`A`) is strictly greater than Rohit's vote count (`B`) AND his vote count (`A`) is strictly greater than Kohli's vote count (`C`).

Mathematically, this can be expressed as: `A > B AND A > C`.

The constraint that "no two players received the same number of votes" simplifies the problem slightly, as we don't need to consider edge cases like `A == B` or `A == C` when determining the maximum. If `A` is not strictly greater than both `B` and `C`, then `A` is not the maximum, and Dhoni did not win.

## Complexity Analysis

-   **Time Complexity**: $O(1)$
    The program performs a fixed number of operations regardless of the input values (within integer limits):
    1.  Reading three integers.
    2.  Performing two comparisons and one logical AND operation.
    3.  Printing a short string ("Yes" or "No").
    All these operations take constant time.

-   **Space Complexity**: $O(1)$
    The program uses a fixed amount of memory to store three integer variables (`A`, `B`, `C`). No dynamic data structures or arrays are used whose size depends on the input.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes most standard libraries, providing access to common functions and data structures.

using namespace std; // Uses the standard namespace to avoid repeatedly writing std::.

int main() {
    // Optimize C++ standard streams for faster input/output operations.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Declare three integer variables to store the number of votes obtained by Dhoni, Rohit, and Kohli.
    // A for Dhoni, B for Rohit, C for Kohli.
    int A, B, C;

    // Read the three space-separated integers (vote counts) from standard input.
    cin >> A >> B >> C;

    // To determine if Dhoni won the poll, we need to check if his votes (A) are strictly
    // greater than the votes of both other players (B and C).
    // The problem guarantees that no two players received the same number of votes,
    // so we don't need to consider equality (e.g., A >= B).
    if (A > B && A > C) {
        // If Dhoni's votes are greater than both Rohit's and Kohli's votes, Dhoni won.
        // Print "Yes" followed by a newline character.
        cout << "Yes\n";
    } else {
        // Otherwise, Dhoni did not receive the maximum number of votes.
        // Print "No" followed by a newline character.
        cout << "No\n";
    }

    // Return 0 to indicate successful execution of the program.
    return 0;
}
```