# [Complete the credits (CREDITS)](https://www.codechef.com/problems/CREDITS)
- **Difficulty Rating**: 809
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to categorize a given integer `x` into one of three categories: "Overload", "Underload", or "Normal". The categorization rules are as follows:
- If `x` is strictly greater than 65, it's "Overload".
- If `x` is strictly less than 35, it's "Underload".
- Otherwise (if `x` is between 35 and 65, inclusive), it's "Normal".

We are given `t` test cases, and for each test case, we need to read an integer `x` and print the corresponding category.

## Intuition & Mathematical Observation
The problem statement directly provides the conditions for each category. There isn't a complex mathematical observation required here; it's a straightforward application of conditional logic.

We can think of the integer `x` as a value on a number line.
- The "Overload" region is everything to the right of 65 (i.e., `x > 65`).
- The "Underload" region is everything to the left of 35 (i.e., `x < 35`).
- The "Normal" region is the interval between 35 and 65, inclusive (i.e., `35 <= x <= 65`).

The conditions given in the problem are mutually exclusive and cover all possible integer values of `x`. The order of checking these conditions is important for an efficient implementation. A common approach is to check the extreme conditions first (Overload and Underload) and then the middle condition (Normal).

## Complexity Analysis
- **Time Complexity**: $O(1)$
    For each test case, we perform a constant number of comparisons and print operations. Since there are `t` test cases, the total time complexity is $O(t)$. However, if we consider the complexity per test case, it is $O(1)$.

- **Space Complexity**: $O(1)$
    We only use a few variables to store the input `x` and the loop counter `t`. The memory usage does not grow with the input size, making the space complexity constant.

## Solution Code
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    // Optimize C++ standard streams for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; // Variable to store the number of test cases
    cin >> t; // Read the number of test cases

    // Loop through each test case
    while (t--) {
        int x; // Variable to store the input value for the current test case
        cin >> x; // Read the input value

        // Check the conditions for categorization
        if (x > 65) {
            // If x is strictly greater than 65, it's an overload
            cout << "Overload\n";
        } else if (x < 35) {
            // If x is strictly less than 35, it's an underload
            cout << "Underload\n";
        } else {
            // If neither of the above conditions is met, x must be between 35 and 65 (inclusive)
            cout << "Normal\n";
        }
    }

    return 0; // Indicate successful execution
}
```