# [Get Subscription (SUBSCRIBE)](https://www.codechef.com/problems/SUBSCRIBE)
- **Difficulty Rating**: 315
- **Solved in**: 1 attempt(s)

## Problem Summary

Chef plans to conduct a lecture for his students, which will last for `X` minutes. The meeting platform he uses has a free tier that supports meetings up to a maximum of 30 minutes. If Chef's lecture duration `X` exceeds 30 minutes, he will need to purchase a subscription. Otherwise, if `X` is 30 minutes or less, he does not need a subscription. The task is to determine whether Chef needs to take a subscription for his lecture.

## Intuition & Mathematical Observation

The problem statement directly provides the condition for needing a subscription: "If Chef needs a meeting of duration X, and X is greater than 30 minutes, then a subscription is required. Otherwise, it's not."

This translates into a simple conditional check:
- If `X > 30`, then the answer is "YES".
- If `X <= 30`, then the answer is "NO".

There are no complex algorithms, data structures, or mathematical formulas required. It's a straightforward comparison.

## Complexity Analysis

-   **Time Complexity**: $O(T)$
    -   For each test case, we read an integer `X` ($O(1)$), perform a single comparison ($O(1)$), and print a string ($O(1)$).
    -   Since there are `T` test cases, the total time complexity will be $T$ times the constant work per test case, resulting in $O(T)$.

-   **Space Complexity**: $O(1)$
    -   In each test case, we only use a few integer variables (`X`, `T`) to store input and loop counters. These variables consume a constant amount of memory, regardless of the input values or the number of test cases.
    -   Therefore, the space complexity is constant, $O(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes common standard library headers

using namespace std; // Uses the standard namespace

void solve() {
    int X; // Declare an integer variable X to store the lecture duration
    cin >> X; // Read the duration of the lecture from standard input

    // The meeting platform supports a meeting of maximum 30 minutes without subscription.
    // If Chef needs a meeting of duration X, and X is greater than 30 minutes,
    // then a subscription is required. Otherwise, it's not.
    if (X > 30) {
        cout << "YES\n"; // If X is greater than 30, Chef needs a subscription
    } else {
        cout << "NO\n";  // Otherwise (X is 30 or less), Chef does not need a subscription
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming to prevent TLE (Time Limit Exceeded).
    ios_base::sync_with_stdio(false); // Unties C++ streams from C standard streams
    cin.tie(NULL); // Unties cin from cout, preventing flushes

    int T; // Declare an integer variable T to store the number of test cases
    cin >> T; // Read the number of test cases

    // Loop through each test case
    while (T--) {
        solve(); // Call the solve function for the current test case
    }

    return 0; // Indicate successful program execution
}

```