# Chef Plays Ludo (LUDO)

- **Difficulty Rating**: 260
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine if Chef can place a new token on the board in a game of Ludo, given the number rolled on a die. In Ludo, a player can only place a new token on the board if they roll a 6. Otherwise, if the roll is not a 6, they cannot place a new token.

## Intuition & Mathematical Observation

The core rule of Ludo, as stated in the problem, is that a new token can only be placed on the board if the player rolls a 6. This is a direct and simple condition.

Therefore, the only mathematical observation needed is to check if the input number (the die roll) is equal to 6.

- If the die roll is 6, Chef can place a new token.
- If the die roll is any other number (1, 2, 3, 4, or 5), Chef cannot place a new token.

This leads to a straightforward conditional check.

## Complexity Analysis

- **Time Complexity**: $O(1)$
    The solution involves reading a single integer for each test case and performing a constant number of operations (a comparison and an output). Since the number of operations does not depend on the input value of `X` or the number of test cases `T` (beyond iterating through them), the time complexity per test case is constant. For `T` test cases, the total time complexity is $O(T)$. However, when analyzing the complexity *per test case*, it is $O(1)$.

- **Space Complexity**: $O(1)$
    The solution uses a few integer variables (`T`, `X`) to store input and loop counters. The amount of memory used is constant and does not grow with the input size. Therefore, the space complexity is $O(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries

// Using the standard namespace to avoid writing std:: repeatedly
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
        int X; // Declare an integer variable X for the number rolled on the die
        cin >> X; // Read the number rolled by Chef

        // Check if the rolled number X is 6
        if (X == 6) {
            // If X is 6, Chef can enter a new token
            cout << "YES\n"; // Print "YES" followed by a newline
        } else {
            // If X is not 6, Chef cannot enter a new token
            cout << "NO\n"; // Print "NO" followed by a newline
        }
    }

    return 0; // Indicate successful program execution
}
```