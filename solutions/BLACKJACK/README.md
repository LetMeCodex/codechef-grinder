# [Blackjack (BLACKJACK)](https://www.codechef.com/problems/BLACKJACK)
- **Difficulty Rating**: 681
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem describes a simplified game of Blackjack. Chef is dealt two cards, `A` and `B`. To win, Chef needs the total sum of his cards to be exactly 21. Chef can draw a third card, `C`. The value of card `C` must be an integer between 1 and 10 (inclusive). We need to determine if Chef can win by drawing a valid third card. If he can, output the value of `C`. Otherwise, output -1.

## Intuition & Mathematical Observation

The core of the problem is to find a third card `C` such that the sum of all three cards (`A`, `B`, and `C`) equals 21.
Mathematically, this can be expressed as:
`A + B + C = 21`

From this equation, we can easily find the required value for `C`:
`C = 21 - A - B`

Once we calculate `C`, we need to check if this `C` is a valid card according to the problem rules. A valid card `C` must satisfy two conditions:
1. `C` must be greater than or equal to 1 (`C >= 1`).
2. `C` must be less than or equal to 10 (`C <= 10`).

If the calculated `C` falls within this range (i.e., `1 <= C <= 10`), then Chef can draw this card and win. In this case, we print `C`.
If `C` is less than 1 (meaning `A + B` is already 21 or more, so Chef would bust or already have 21 without needing a third card, or even with a 1, would exceed 21) or `C` is greater than 10 (meaning `A + B` is too low, and even drawing a 10 won't bring the total to 21), then Chef cannot win by drawing a valid card. In this scenario, we print -1.

## Complexity Analysis

-   **Time Complexity**: $O(T)$
    The program processes `T` test cases. For each test case, it performs a constant number of operations: reading two integers, one subtraction, two comparisons, and one print operation. These operations take constant time, $O(1)$. Since these constant-time operations are repeated `T` times, the total time complexity is $O(T)$.

-   **Space Complexity**: $O(1)$
    The program uses a fixed number of integer variables (`T`, `A`, `B`, `C`) regardless of the input values or the number of test cases. These variables occupy a constant amount of memory. Therefore, the space complexity is $O(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes common standard libraries like iostream

using namespace std; // Allows using standard library elements without the std:: prefix

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Variable to store the number of test cases
    cin >> T; // Read the number of test cases

    // Loop through each test case
    while (T--) {
        int A, B; // Variables to store the first two numbers drawn
        cin >> A >> B; // Read the two numbers for the current test case

        // Calculate the required third number (C) to make the sum 21
        int C = 21 - A - B;

        // Check if the calculated C is a valid number (between 1 and 10 inclusive)
        if (C >= 1 && C <= 10) {
            // If C is valid, print C
            cout << C << "\n";
        } else {
            // If C is not valid (either too low or too high), Chef cannot win.
            // Print -1 as per problem statement.
            cout << -1 << "\n";
        }
    }

    return 0; // Indicate successful program execution
}
```