# [Tax in Chefland (TAXES)](https://www.codechef.com/problems/TAXES)
- **Difficulty Rating**: 276
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to calculate the net income of Chef after tax deductions. Chef's total income is given as `X` rupees. The tax rules are as follows:
- If Chef's total income `X` is strictly greater than 100 rupees, a tax of 10 rupees is deducted.
- Otherwise (if `X` is 100 rupees or less), no tax is deducted.

We need to output Chef's net income after applying these tax rules for several test cases.

## Intuition & Mathematical Observation

The problem statement directly provides the conditions for tax deduction, making it a straightforward conditional logic problem.

The core logic can be translated directly into an `if-else` statement:
1. **Check the condition**: Is `X > 100`?
2. **If true**: The income `X` is strictly greater than 100. According to the rules, a tax of 10 rupees is deducted. So, the net income will be `X - 10`.
3. **If false**: The income `X` is 100 or less. According to the rules, no tax is deducted. So, the net income will remain `X`.

No complex mathematical formulas or observations are required beyond understanding the "strictly greater than" condition.

## Complexity Analysis

-   **Time Complexity**: $O(T)$
    For each test case, the program performs a constant number of operations: reading an integer, a single comparison, a potential subtraction, and printing an integer. These operations take $O(1)$ time. Since there are $T$ test cases, the total time complexity is $T \times O(1) = O(T)$.

-   **Space Complexity**: $O(1)$
    The program uses a few variables (`X`, `t`) to store input and loop counters. These variables consume a constant amount of memory, regardless of the input values or the number of test cases. Therefore, the space complexity is $O(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h>

using namespace std;

void solve() {
    int X; // Declare X to store the total income
    cin >> X; // Read the total income X for the current test case

    // Check if the total income is strictly greater than 100.
    // If it is, a tax of 10 rupees is deducted.
    if (X > 100) {
        cout << X - 10 << "\n"; // Output the income after deducting 10 rupees tax
    } else {
        // If the total income is 100 or less, no tax is deducted.
        cout << X << "\n"; // Output the original income as no tax is applied
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output operations.
    // This is a common practice in competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; // Declare t to store the number of test cases
    cin >> t; // Read the number of test cases

    // Loop through each test case
    while (t--) {
        solve(); // Call the solve function to handle the current test case
    }

    return 0; // Indicate successful program execution
}
```