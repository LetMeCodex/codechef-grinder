# [Advitiya (ADVITIYA)](https://www.codechef.com/problems/ADVITIYA)
- **Difficulty Rating**: 844
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to transform a given 8-character uppercase English string `S` into the target string "ADVITIYA". The only allowed operation is to increment a character. For example, 'A' becomes 'B', 'B' becomes 'C', and 'Z' wraps around to 'A'. We need to find the minimum total number of increment operations required to transform `S` into "ADVITIYA".

## Intuition & Mathematical Observation

1.  **Independent Character Transformations**: The key observation is that the operation on one character of the string `S` does not affect any other character. This means we can calculate the minimum steps required for each character `S[i]` to become `ADVITIYA[i]` independently, and then sum up these individual minimum steps to get the total minimum steps.

2.  **Cyclic Nature of Increments**: The characters increment cyclically, meaning 'Z' wraps around to 'A'. This is crucial for calculating the minimum steps.

3.  **Calculating Minimum Steps for a Single Character**:
    Let's represent each uppercase English letter as an integer from 0 to 25, where 'A' = 0, 'B' = 1, ..., 'Z' = 25.
    Suppose we want to transform character `c1` (with integer value `v1`) into character `c2` (with integer value `v2`).
    Since we can only increment, the minimum steps will always be the direct path.
    *   If `v2 >= v1`: The number of steps is simply `v2 - v1`. For example, 'A' (0) to 'C' (2) takes `2 - 0 = 2` steps.
    *   If `v2 < v1`: This means we need to increment `c1` past 'Z' and then to `c2`. For example, 'Y' (24) to 'B' (1).
        The steps would be: `(25 - v1)` steps to reach 'Z', plus `1` step to reach 'A', plus `v2` steps to reach `c2`.
        Total steps = `(25 - v1) + 1 + v2 = 26 - v1 + v2`.

    Both cases can be elegantly combined using modular arithmetic:
    The minimum steps to transform `v1` to `v2` is `(v2 - v1 + 26) % 26`.
    Let's verify this formula:
    *   'A' (0) to 'C' (2): `(2 - 0 + 26) % 26 = 28 % 26 = 2`. Correct.
    *   'Y' (24) to 'B' (1): `(1 - 24 + 26) % 26 = 3 % 26 = 3`. Correct (Y -> Z -> A -> B).
    *   'A' (0) to 'Z' (25): `(25 - 0 + 26) % 26 = 51 % 26 = 25`. Correct.
    *   'Z' (25) to 'A' (0): `(0 - 25 + 26) % 26 = 1 % 26 = 1`. Correct.

By applying this formula for each of the 8 character positions and summing the results, we get the total minimum steps.

## Complexity Analysis

*   **Time Complexity**: For each test case, we iterate exactly 8 times (once for each character in the 8-character string). Inside the loop, all operations (character to integer conversion, arithmetic, modulo) are constant time. Reading the 8-character string also takes constant time. If there are `T` test cases, the total time complexity is $O(T \times 8)$, which simplifies to $O(T)$ because 8 is a constant. Effectively, it's $O(1)$ per test case.

*   **Space Complexity**: We store the input string `S` (8 characters) and the target string "ADVITIYA" (8 characters). These are fixed-size strings. A few integer variables are used for calculations. Therefore, the space complexity is $O(1)$ (constant space) per test case.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes most standard library headers

// Use the standard namespace as requested
using namespace std;

// Function to solve a single test case
void solve() {
    string s;
    cin >> s; // Read the input string S

    // The target string is fixed as "ADVITIYA"
    string target_str = "ADVITIYA";

    int total_steps = 0; // Initialize total steps for this test case

    // Iterate through each of the 8 characters of the string
    for (int i = 0; i < 8; ++i) {
        // Convert characters to 0-indexed integer values (A=0, B=1, ..., Z=25)
        int val_s = s[i] - 'A';
        int val_target = target_str[i] - 'A';

        // Calculate the minimum steps to transform s[i] to target_str[i]
        // The formula (val_target - val_s + 26) % 26 correctly handles cyclic increments.
        // For example:
        //   'A' (0) to 'B' (1): (1 - 0 + 26) % 26 = 1
        //   'Z' (25) to 'A' (0): (0 - 25 + 26) % 26 = 1
        //   'A' (0) to 'Z' (25): (25 - 0 + 26) % 26 = 25
        int steps_for_char = (val_target - val_s + 26) % 26;

        // Add the steps for the current character to the total
        total_steps += steps_for_char;
    }

    // Output the total minimum steps for the current test case
    cout << total_steps << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) prevents std::cout from flushing before std::cin reads input.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t; // Read the number of test cases
    while (t--) { // Loop through each test case
        solve();   // Call the solve function for each test case
    }

    return 0; // Indicate successful execution
}
```