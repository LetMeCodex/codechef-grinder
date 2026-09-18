# Monthly Budget (BUDGET_)

- **Difficulty Rating**: 456
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine if Akshat has enough money to cover his expenses for a month, given his total savings and his daily expenditure. A month is defined as having 30 days.

## Intuition & Mathematical Observation

The core of the problem lies in comparing Akshat's total available money with the total money he will spend over 30 days.

Let:
- $X$ be Akshat's total money.
- $Y$ be Akshat's daily expenditure.

The problem states that a month has 30 days. Therefore, the total expenditure for the month can be calculated as:
Total Monthly Expenditure = Daily Expenditure $\times$ Number of Days
Total Monthly Expenditure = $Y \times 30$

To determine if Akshat has enough money, we need to check if his total money ($X$) is greater than or equal to his total monthly expenditure.
If $X \ge (Y \times 30)$, then Akshat has enough money.
Otherwise, if $X < (Y \times 30)$, Akshat does not have enough money.

The problem involves multiple test cases, so we need to perform this calculation for each given pair of $X$ and $Y$.

## Complexity Analysis

- **Time Complexity**: $O(1)$
    The solution involves a fixed number of arithmetic operations (multiplication and comparison) and input/output operations for each test case. The number of test cases is read once, and then the loop runs for that many iterations. Inside the loop, the operations are constant time. Thus, the time complexity per test case is $O(1)$. If $T$ is the number of test cases, the total time complexity is $O(T)$. However, since the problem constraints usually imply $T$ is relatively small and the operations per test case are constant, it's often described as $O(1)$ per test case.

- **Space Complexity**: $O(1)$
    The solution uses a fixed number of variables ($T$, $X$, $Y$, and `total_expenditure_required`) regardless of the input size. Therefore, the space complexity is constant, $O(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes most standard libraries

// Use the standard namespace to avoid writing std:: repeatedly
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare an integer variable T for the number of test cases
    cin >> T; // Read the number of test cases

    // Loop T times, once for each test case
    while (T--) {
        int X, Y; // Declare integer variables X and Y for total money and daily expenditure
        cin >> X >> Y; // Read X and Y for the current test case

        // Calculate the total money required for 30 days.
        // The problem states the month has 30 days.
        // Daily expenditure is Y, so total expenditure = Y * 30.
        int total_expenditure_required = Y * 30;

        // Check if Akshat has enough money (X) to cover the total expenditure.
        // If X is greater than or equal to total_expenditure_required, he has enough.
        if (X >= total_expenditure_required) {
            cout << "YES\n"; // Output "YES" followed by a newline
        } else {
            cout << "NO\n"; // Output "NO" followed by a newline
        }
    }

    return 0; // Indicate successful execution of the program
}
```