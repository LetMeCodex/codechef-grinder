# [Television Channels (TV)](https://www.codechef.com/problems/TV)
- **Difficulty Rating**: 324
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine the number of working television channels. We are given a single integer `X`, representing the total number of channels available, ranging from 1 to `X`. The problem states that all even-numbered channels have stopped working. This implies that only odd-numbered channels are currently operational. Our task is to count and output the total number of odd-numbered channels from 1 up to `X` (inclusive).

## Intuition & Mathematical Observation

The core of the problem is to count how many odd integers exist in the range `[1, X]`. Let's analyze this based on whether `X` is an even or an odd number.

1.  **If `X` is an even number:**
    Let `X = 2k` for some positive integer `k`.
    The odd numbers in the range `[1, X]` would be `1, 3, 5, ..., (2k - 1)`.
    The count of these numbers is `k`.
    Since `X = 2k`, `k = X / 2`.
    For example, if `X = 100`, the odd channels are `1, 3, ..., 99`. The count is `100 / 2 = 50`.

2.  **If `X` is an odd number:**
    Let `X = 2k + 1` for some non-negative integer `k`.
    The odd numbers in the range `[1, X]` would be `1, 3, 5, ..., (2k + 1)`.
    The count of these numbers is `k + 1`.
    Since `X = 2k + 1`, `X + 1 = 2k + 2`, so `(X + 1) / 2 = k + 1`.
    For example, if `X = 5`, the odd channels are `1, 3, 5`. The count is `(5 + 1) / 2 = 3`.

From these two cases, we can derive a single formula that works for both even and odd `X` using integer division:
The number of working channels is `(X + 1) / 2`.

Let's test this formula with a few examples:
*   If `X = 1`: `(1 + 1) / 2 = 2 / 2 = 1`. (Correct: channel 1)
*   If `X = 2`: `(2 + 1) / 2 = 3 / 2 = 1` (integer division). (Correct: channel 1)
*   If `X = 3`: `(3 + 1) / 2 = 4 / 2 = 2`. (Correct: channels 1, 3)
*   If `X = 4`: `(4 + 1) / 2 = 5 / 2 = 2` (integer division). (Correct: channels 1, 3)

This formula elegantly covers all cases.

## Complexity Analysis

*   **Time Complexity**: $O(1)$
    The solution involves reading a single integer `X`, performing a constant number of arithmetic operations (one addition and one division), and printing a single integer. All these operations take constant time, regardless of the value of `X`.

*   **Space Complexity**: $O(1)$
    The solution uses a fixed amount of memory to store variables like `X` and `working_channels`. The memory usage does not scale with the input value `X`.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries

// Use the standard namespace
using namespace std;

int main() {
    // Optimize C++ standard streams for competitive programming.
    // Unties cin from cout and disables synchronization with C's stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // The problem statement's "Input Format" section specifies:
    // "The first and only line of input contains a single integer X."
    // This indicates that there is only one test case per execution.
    // General instructions about multiple test cases (e.g., `int t; cin >> t; while(t--)`)
    // are overridden by the specific input format for this problem.

    int X; // Declare an integer variable to store the input X
    cin >> X; // Read the value of X from standard input

    // The problem states that all even-numbered channels stopped working.
    // This means only odd-numbered channels are still working.
    // We need to count the number of odd integers from 1 up to X (inclusive).

    // Let's analyze the count of odd numbers:
    // If X is an even number (e.g., X = 2, 4, 6, ..., 100):
    // The odd numbers are 1, 3, 5, ..., X-1.
    // The count of these numbers is X / 2.
    // For example, if X=100, odd numbers are 1, 3, ..., 99. Count = 100 / 2 = 50.

    // If X is an odd number (e.g., X = 1, 3, 5, ..., 5):
    // The odd numbers are 1, 3, 5, ..., X.
    // The count of these numbers is (X + 1) / 2.
    // For example, if X=5, odd numbers are 1, 3, 5. Count = (5 + 1) / 2 = 3.

    // A single formula that works for both even and odd X using integer division is (X + 1) / 2:
    // If X is even (X=2k): (2k + 1) / 2 = k (integer division). This is X/2.
    // If X is odd (X=2k+1): ((2k+1) + 1) / 2 = (2k + 2) / 2 = k + 1 (integer division). This is (X+1)/2.

    int working_channels = (X + 1) / 2;

    // Print the calculated number of working channels, followed by a newline character.
    cout << working_channels << "\n";

    return 0; // Indicate successful program execution
}
```