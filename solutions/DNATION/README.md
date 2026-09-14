# [Chef and Donation (DNATION)](https://www.codechef.com/problems/DNATION)

- **Difficulty Rating**: 305
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef earns $X$ rupees and Chefina earns $Y$ rupees, where $Y > X$. To ensure they both have the same amount of money, Chefina decides to donate a portion of her income. We need to calculate the exact amount Chefina must donate so that her remaining income equals Chef's income ($X$).

## Intuition & Mathematical Observation
The problem asks for the difference between Chefina's income ($Y$) and Chef's income ($X$). 

If Chefina has $Y$ and wants to reach $X$, we can set up the equation:
$$Y - \text{Donation} = X$$

Rearranging the equation to solve for the donation amount:
$$\text{Donation} = Y - X$$

Since the problem guarantees $Y > X$, the result will always be a positive integer, representing the amount Chefina needs to give away.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant time subtraction operation.
- **Space Complexity**: $O(1)$, as we only use a few integer variables to store the inputs and the result, regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes most standard libraries

using namespace std; // Allows using standard library elements without the std:: prefix

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare an integer variable T to store the number of test cases.
    cin >> T; // Read the number of test cases from standard input.

    // Loop T times, once for each test case.
    while (T--) {
        int X, Y; // Declare two integer variables X and Y for Chef's and Chefina's income.
        cin >> X >> Y; // Read X and Y for the current test case.

        // The problem states that Chefina earns Y rupees and Chef earns X rupees, with Y > X.
        // To end up with exactly the same amount, they donate the difference between their income.
        // The difference is Y - X. If Chefina donates this amount, she will have Y - (Y - X) = X rupees,
        // which is the same as Chef's income.
        int donation_amount = Y - X;

        // Output the calculated donation amount, followed by a newline character.
        cout << donation_amount << "\n";
    }

    return 0; // Indicate successful program execution.
}
```