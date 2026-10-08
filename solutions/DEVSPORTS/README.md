# [Devendra and Water Sports (DEVSPORTS)](https://www.codechef.com/problems/DEVSPORTS)
- **Difficulty Rating**: 859
- **Solved in**: 1 attempt(s)

## Problem Summary

Devendra has an initial amount of `Z` rupees. He has already spent `Y` rupees. Now, he wants to try three different water sports, which cost `A`, `B`, and `C` rupees respectively. The task is to determine if Devendra has enough money remaining to try all three water sports. If he does, print "YES"; otherwise, print "NO".

## Intuition & Mathematical Observation

The problem is a straightforward arithmetic check. To solve it, we need to perform two main calculations and then a comparison:

1.  **Calculate Devendra's remaining money:** He started with `Z` rupees and has already spent `Y` rupees. So, the money he currently has available is `Z - Y`.
2.  **Calculate the total cost of the three water sports:** To try all three sports, he needs to pay `A + B + C` rupees.
3.  **Compare:** If his `remaining_money` is greater than or equal to the `total_sport_cost`, he can afford them. Otherwise, he cannot.

This can be expressed as a simple condition: `(Z - Y) >= (A + B + C)`.

## Complexity Analysis

*   **Time Complexity**: $O(1)$ per test case, or $O(T)$ for $T$ test cases.
    For each test case, the solution involves a few constant-time arithmetic operations (one subtraction, two additions) and one comparison. These operations take a fixed amount of time regardless of the input values. If there are $T$ test cases, the total time complexity will be $T$ times the constant time per test case, which simplifies to $O(T)$.

*   **Space Complexity**: $O(1)$.
    The solution uses a fixed number of integer variables (`Z`, `Y`, `A`, `B`, `C`, `remaining_money`, `total_sport_cost`, `t`) to store input and intermediate results. The memory usage does not depend on the magnitude of the input values or the number of test cases (beyond the variable `t` itself). Therefore, the space complexity is constant.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries

using namespace std; // Use standard namespace

// Function to solve a single test case
void solve() {
    // Declare five integer variables to store the input values
    int Z, Y, A, B, C;
    
    // Read the initial money (Z), money already spent (Y),
    // and prices of the three water sports (A, B, C)
    cin >> Z >> Y >> A >> B >> C;

    // Calculate the money Devendra has remaining after his initial spending
    int remaining_money = Z - Y;

    // Calculate the total cost required to try each of the three water sports once
    int total_sport_cost = A + B + C;

    // Check if Devendra's remaining money is sufficient to cover the total cost
    if (remaining_money >= total_sport_cost) {
        // If he has enough money, print "YES"
        cout << "YES\n";
    } else {
        // Otherwise, print "NO"
        cout << "NO\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin/cout from C's stdio and prevents flushing cout before cin.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Declare an integer variable to store the number of test cases
    int t;
    
    // Read the number of test cases
    cin >> t;

    // Loop through each test case
    while (t--) {
        // Call the solve function for the current test case
        solve();
    }

    // Indicate successful program execution
    return 0;
}
```