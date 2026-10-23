# [Competition of 4 (COMP4)](https://www.codechef.com/problems/COMP4)
- **Difficulty Rating**: 247
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to calculate the prize money awarded for a specific rank `X` in a competition. We are given that the rank `X` will always be an integer between 1 and 4 (inclusive). The prize money for rank `i` is defined by the formula: `1000 * 2^(4 - i)`. We need to output the prize money corresponding to the given rank `X`.

## Intuition & Mathematical Observation

The core of the problem lies in evaluating the given formula `1000 * 2^(4 - i)` for the possible values of `i` (which is `X` in our case). Since `X` is constrained to be between 1 and 4, we can simply calculate the prize money for each of these four possible ranks:

1.  **For Rank `X = 1`**:
    Prize = `1000 * 2^(4 - 1)`
    Prize = `1000 * 2^3`
    Prize = `1000 * 8`
    Prize = `8000`

2.  **For Rank `X = 2`**:
    Prize = `1000 * 2^(4 - 2)`
    Prize = `1000 * 2^2`
    Prize = `1000 * 4`
    Prize = `4000`

3.  **For Rank `X = 3`**:
    Prize = `1000 * 2^(4 - 3)`
    Prize = `1000 * 2^1`
    Prize = `1000 * 2`
    Prize = `2000`

4.  **For Rank `X = 4`**:
    Prize = `1000 * 2^(4 - 4)`
    Prize = `1000 * 2^0`
    Prize = `1000 * 1`
    Prize = `1000`

Given that there are only four possible input values for `X`, the most straightforward and efficient approach is to use a direct mapping. An `if-else if` ladder (or a `switch` statement) can check the value of `X` and print the pre-calculated prize money directly. This avoids any floating-point calculations or power functions, making the solution robust and extremely fast.

## Complexity Analysis

*   **Time Complexity**: $O(1)$
    The solution involves reading a single integer input, performing a constant number of comparisons (at most 4 `if-else if` checks), and printing a single integer output. All these operations take constant time, regardless of the input value (within its small constraints).

*   **Space Complexity**: $O(1)$
    The solution uses a single integer variable (`x`) to store the input. The memory usage remains constant irrespective of the input value.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin from cout and disables synchronization with C's stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x; // Declare an integer variable to store the rank.
    cin >> x; // Read the rank X from standard input.

    // The prize money for rank i is 1000 * 2^(4 - i)
    // Let's list the prize money for each possible rank:
    // Rank 1: 1000 * 2^(4 - 1) = 1000 * 2^3 = 1000 * 8 = 8000
    // Rank 2: 1000 * 2^(4 - 2) = 1000 * 2^2 = 1000 * 4 = 4000
    // Rank 3: 1000 * 2^(4 - 3) = 1000 * 2^1 = 1000 * 2 = 2000
    // Rank 4: 1000 * 2^(4 - 4) = 1000 * 2^0 = 1000 * 1 = 1000

    // Since the constraints are very small (1 <= X <= 4),
    // a direct mapping using if-else if statements is the simplest and most efficient approach.
    
    if (x == 1) {
        cout << 8000 << "\n"; // If rank is 1, print 8000.
    } else if (x == 2) {
        cout << 4000 << "\n"; // If rank is 2, print 4000.
    } else if (x == 3) {
        cout << 2000 << "\n"; // If rank is 3, print 2000.
    } else if (x == 4) {
        cout << 1000 << "\n"; // If rank is 4, print 1000.
    }

    return 0; // Indicate successful execution.
}

```