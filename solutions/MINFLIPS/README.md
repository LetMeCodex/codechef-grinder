# [Minimum number of Flips (MINFLIPS)](https://www.codechef.com/problems/MINFLIPS)
- **Difficulty Rating**: 781
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to find the minimum number of operations (flips) required to make the sum of all elements in an array equal to zero. The array consists only of `1`s and `-1`s. A flip operation changes a `1` to a `-1`, or a `-1` to a `1`. If it's impossible to achieve a sum of zero, we should output `-1`.

## Intuition & Mathematical Observation

The core of this problem lies in understanding how a flip operation affects the total sum of the array.

1.  **Effect of a Flip:**
    *   If we flip a `1` to a `-1`, the element's value changes by `(-1) - (1) = -2`. Consequently, the total sum of the array decreases by `2`.
    *   If we flip a `-1` to a `1`, the element's value changes by `(1) - (-1) = +2`. Consequently, the total sum of the array increases by `2`.

2.  **Parity Observation:**
    Notice that in both cases, a single flip operation changes the total sum by exactly `2` (either `+2` or `-2`). This is a crucial observation: **each flip changes the sum by an even number.**
    This implies that the parity of the total sum never changes.
    *   If the initial sum `S` is even, then `S ± 2`, `S ± 4`, etc., will always be even.
    *   If the initial sum `S` is odd, then `S ± 2`, `S ± 4`, etc., will always be odd.

3.  **Impossibility Condition:**
    Our target sum is `0`, which is an even number.
    Therefore, if the initial sum of the array elements is odd, it is impossible to reach a sum of `0` because any number of flips will only result in an odd sum. In this scenario, we should output `-1`.

4.  **Minimum Flips for Even Sum:**
    If the initial sum `S` is even, it is possible to reach `0`.
    *   We need to change the sum from `S` to `0`. The total absolute change required is `|S|`.
    *   Since each flip operation changes the sum by `2`, the minimum number of flips required to achieve a total change of `|S|` is simply `|S| / 2`.
    *   For example, if `S = 4`, we need to reduce the sum by `4`. Each flip of `1` to `-1` reduces the sum by `2`. So, `4 / 2 = 2` flips are needed.
    *   If `S = -6`, we need to increase the sum by `6`. Each flip of `-1` to `1` increases the sum by `2`. So, `6 / 2 = 3` flips are needed.

**Algorithm:**
1.  Read the number of elements `N`.
2.  Calculate the `current_sum` of all elements in the array.
3.  Check the parity of `current_sum`:
    *   If `current_sum % 2 != 0` (i.e., `current_sum` is odd), print `-1`.
    *   If `current_sum % 2 == 0` (i.e., `current_sum` is even), print `abs(current_sum) / 2`.

## Complexity Analysis

-   **Time Complexity**: $O(N)$
    For each test case, we iterate through the `N` elements of the array once to calculate their sum. All other operations (reading `N`, checking parity, printing) take constant time. If there are `T` test cases, the total time complexity would be $O(T \cdot N)$.

-   **Space Complexity**: $O(1)$
    We only use a few integer variables to store `N`, `current_sum`, and `val`. The amount of memory used does not depend on the input size `N`.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries

// Using the standard namespace as requested
using namespace std;

void solve() {
    int N;
    cin >> N; // Read the length of the array
    int current_sum = 0;
    for (int i = 0; i < N; ++i) {
        int val;
        cin >> val; // Read each element
        current_sum += val; // Add it to the total sum
    }

    // The core logic:
    // Each operation (flipping 1 to -1 or -1 to 1) changes the sum by exactly 2.
    // For example, 1 becomes -1: sum changes by -2.
    // -1 becomes 1: sum changes by +2.
    // This means the parity of the sum never changes.
    // If the initial sum is odd, it's impossible to make it 0 (which is even).
    if (current_sum % 2 != 0) {
        cout << -1 << "\n";
    } else {
        // If the initial sum is even, we need to change it to 0.
        // The total change required is |current_sum|.
        // Since each operation changes the sum by 2, the minimum number of operations
        // is |current_sum| / 2.
        cout << abs(current_sum) / 2 << "\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common competitive programming practice.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) {
        solve(); // Call the solve function for each test case
    }

    return 0; // Indicate successful execution
}
```