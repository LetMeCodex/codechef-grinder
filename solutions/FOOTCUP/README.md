# [Football Cup (FOOTCUP)](https://www.codechef.com/problems/FOOTCUP)
- **Difficulty Rating**: 412
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine if Chef likes a football match, given the final scores `X` for the first team and `Y` for the second team. Chef likes a match if two conditions are met:
1.  The match ends in a draw (i.e., both teams score the same number of goals).
2.  At least one goal has been scored in total across both teams.

We need to output "YES" if Chef likes the match, and "NO" otherwise. This needs to be done for `T` test cases.

## Intuition & Mathematical Observation

Let's analyze the two conditions Chef has for liking a match:

1.  **`X == Y`**: The scores must be equal, indicating a draw.
2.  **`X + Y > 0`**: The total number of goals scored must be greater than zero, meaning at least one goal was scored.

We need *both* of these conditions to be true simultaneously. Let's combine them:

If `X == Y` (from condition 1), then substituting `Y` with `X` into condition 2 gives us:
`X + X > 0`
`2 * X > 0`

Since `2` is a positive constant, we can divide both sides by `2` without changing the inequality direction:
`X > 0`

So, for Chef to like the match, the scores must be equal (`X == Y`), AND the number of goals scored by one team (and thus by both, since they are equal) must be greater than zero (`X > 0`).

This combined condition `X == Y && X > 0` automatically satisfies `X + Y > 0` because if `X > 0`, then `Y` must also be `> 0` (since `Y = X`), making `X + Y = 2 * X` definitely greater than `0`.
The only case where `X == Y` but `X + Y` is not `> 0` is when `X = 0` and `Y = 0` (a 0-0 draw). In this specific case, `X > 0` would be false, correctly leading to "NO".

Therefore, the simplified condition to check is `X == Y && X > 0`.

## Complexity Analysis

-   **Time Complexity**: For each test case, the solution performs a constant number of operations: reading two integers, a simple comparison (`X == Y && X > 0`), and printing a string. These operations take $O(1)$ time. Since there are `T` test cases, the total time complexity is $O(T)$.
-   **Space Complexity**: The solution uses a few integer variables (`X`, `Y`, `T`) to store input and loop counters. These variables occupy a constant amount of memory, regardless of the input values or the number of test cases. Therefore, the space complexity is $O(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Required include for competitive programming

// Required namespace
using namespace std;

// Function to solve a single test case
void solve() {
    int X, Y;
    cin >> X >> Y; // Read the goals scored by both teams

    // Chef likes a match if:
    // 1. The match ends in a draw (X == Y)
    // 2. At least one goal has been scored by either team (X + Y > 0)
    //
    // If X == Y, then X + Y > 0 simplifies to 2*X > 0, which means X > 0.
    // So, the combined condition is X == Y AND X > 0.
    if (X == Y && X > 0) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) { // Loop through each test case
        solve(); // Call the solve function for the current test case
    }

    return 0;
}

```