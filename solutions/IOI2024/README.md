# [IOI 2024 (IOI2024)](https://www.codechef.com/problems/IOI2024)
- **Difficulty Rating**: 219
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to determine whether the International Olympiad in Informatics (IOI) 2024 is ongoing on a given day `X` of September. We are provided with the information that IOI 2024 is held from September 1st to September 8th, inclusive. The input `X` will be an integer representing a day in September, with constraints $1 \le X \le 30$. We need to output "YES" if IOI is ongoing on day `X`, and "NO" otherwise.

## Intuition & Mathematical Observation
The problem statement explicitly defines the period during which IOI 2024 is held: September 1st to September 8th, inclusive. This means that if the given day `X` falls within this range, the competition is ongoing. Otherwise, it is not.

Given that `X` represents a day in September and its value is between 1 and 30 (inclusive), we simply need to check if `X` is less than or equal to 8.
- If $1 \le X \le 8$, then IOI 2024 is ongoing.
- If $X > 8$ (which implies $9 \le X \le 30$ given the constraints), then IOI 2024 is not ongoing.

This leads to a straightforward conditional check.

## Complexity Analysis
- **Time Complexity**: $O(1)$
    The solution involves reading a single integer, performing a single comparison, and printing a short string. All these operations take constant time, regardless of the input value `X`.
- **Space Complexity**: $O(1)$
    The solution only uses a single integer variable `X` to store the input. This requires a constant amount of memory.

## Solution Code
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
    // Optimize C++ standard streams for competitive programming.
    // This unties cin from cout and disables synchronization with C's stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Declare an integer variable X to store the input date.
    int X;

    // Read the date X from standard input.
    cin >> X;

    // The problem states that IOI 2024 is held from September 1st to September 8th, inclusive.
    // This means IOI is ongoing on any date X such that 1 <= X <= 8.
    // The constraints specify that 1 <= X <= 30, so X will always be at least 1.
    // Therefore, we only need to check if X is less than or equal to 8.
    if (X <= 8) {
        // If X is within the range [1, 8], IOI is ongoing.
        cout << "YES\n";
    } else {
        // Otherwise, IOI is not ongoing.
        cout << "NO\n";
    }

    // Return 0 to indicate successful execution.
    return 0;
}
```