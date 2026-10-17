# [Adding 123 to 4 (ADD1234)](https://www.codechef.com/problems/ADD1234)
- **Difficulty Rating**: -1
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to find the maximum number of times we can form the sum '4' using a given count of digits '1', '2', and '3'. We are provided with three integers: `X` (count of '1's), `Y` (count of '2's), and `Z` (count of '3's). Each digit can be used at most once to form a '4', but we want to maximize the total number of '4's formed across all available digits.

## Intuition & Mathematical Observation

To form the sum '4' using only the digits '1', '2', and '3', we need to consider all possible combinations:

1.  **Using '1' and '3'**:
    *   `1 + 3 = 4`
    *   This combination uses one '1' and one '3'.

2.  **Using '2' and '2'**:
    *   `2 + 2 = 4`
    *   This combination uses two '2's.

3.  **Other combinations**:
    *   `1 + 1 + 1 + 1 = 4` (uses four '1's) - Not possible as we only have '1', '2', '3'.
    *   `1 + 1 + 2 = 4` (uses two '1's and one '2') - Not possible as we only have '1', '2', '3'.
    *   Any combination involving three '1's or more '1's, or three '2's, or three '3's, etc., would exceed the sum of 4 or not be possible with the given digits. For example, `1+1+1+1` is not possible because we are only given digits 1, 2, 3, not an unlimited supply of them. The problem implies using the *given* digits. The most straightforward interpretation is to use the digits 1, 2, 3 *as values* to sum to 4.

Crucially, the two valid ways to form '4' (`1+3` and `2+2`) are **independent** of each other in terms of the digits they consume. Using a '1' and a '3' does not affect the count of '2's, and using two '2's does not affect the count of '1's or '3's. This means we can maximize the number of pairs for each type independently and then sum them up to get the total maximum number of '4's.

Let's calculate the maximum for each type:

*   **For `1 + 3 = 4` pairs**:
    The number of such pairs is limited by the minimum of available '1's (`X`) and available '3's (`Z`).
    So, `pairs_1_3 = min(X, Z)`.

*   **For `2 + 2 = 4` pairs**:
    The number of such pairs is limited by how many pairs of '2's we can form from the available '2's (`Y`). Each pair requires two '2's.
    So, `pairs_2_2 = Y / 2` (using integer division, as we can only form whole pairs).

The total maximum number of '4's will be the sum of these two independent counts:
`total_pairs = pairs_1_3 + pairs_2_2`.

## Complexity Analysis

*   **Time Complexity**: $O(1)$ per test case.
    The `solve()` function involves reading three integers, performing two `min` operations, one division, one addition, and printing an integer. All these operations take constant time. Since there are `T` test cases, the total time complexity will be $O(T)$.

*   **Space Complexity**: $O(1)$.
    The solution uses a fixed number of integer variables (`X`, `Y`, `Z`, `pairs_1_3`, `pairs_2_2`, `total_pairs`, `T`). The memory usage does not depend on the input values, making it constant.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes iostream, algorithm, etc.
using namespace std;

void solve() {
    int X, Y, Z;
    cin >> X >> Y >> Z;

    // Calculate the maximum number of pairs that sum to 4 using one '1' and one '3'.
    // This is limited by the minimum count of available '1's and '3's.
    int pairs_1_3 = min(X, Z);

    // Calculate the maximum number of pairs that sum to 4 using two '2's.
    // This is limited by half the count of available '2's (integer division).
    int pairs_2_2 = Y / 2;

    // The total maximum number of pairs is the sum of these two independent counts.
    int total_pairs = pairs_1_3 + pairs_2_2;

    cout << total_pairs << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) { // Loop through each test case
        solve();
    }

    return 0;
}
```