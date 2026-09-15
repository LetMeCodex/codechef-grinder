# [Favourite Numbers (FAVOURITENUM)](https://www.codechef.com/problems/FAVOURITENUM)

- **Difficulty Rating**: 477
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an integer $A$, we need to determine who claims the number based on specific criteria:
1. **Alice** likes the number if it is both even and divisible by 7.
2. **Bob** likes the number if it is both odd and divisible by 9.
3. **Charlie** takes the number if neither Alice nor Bob likes it.

## Intuition & Mathematical Observation
The problem is a straightforward implementation of conditional logic. We can evaluate the conditions using the modulo operator (`%`):

*   **Alice's Condition**: A number is even if `A % 2 == 0` and divisible by 7 if `A % 7 == 0`. Both must be true.
*   **Bob's Condition**: A number is odd if `A % 2 != 0` (or `A % 2 == 1`) and divisible by 9 if `A % 9 == 0`. Both must be true.
*   **Charlie's Condition**: If the above two `if-else` blocks are not satisfied, we default to Charlie.

Since the constraints are small ($A \le 1000$ and $T \le 100$), a simple $O(1)$ check per test case is highly efficient.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. Each test case performs a constant number of arithmetic operations.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and perform calculations.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Alice likes A if: (A % 2 == 0) AND (A % 7 == 0)
 * Bob likes A if: (A % 2 != 0) AND (A % 9 == 0)
 * Otherwise, Charlie takes it.
 * 
 * Constraints: 1 <= A <= 1000, T <= 100.
 * Time Complexity: O(T)
 * Space Complexity: O(1)
 */

int main() {
    // Optimize standard I/O operations for faster execution
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long a;
        cin >> a;
        
        // Check Alice's condition: Even and multiple of 7
        if (a % 2 == 0 && a % 7 == 0) {
            cout << "Alice" << "\n";
        }
        // Check Bob's condition: Odd and multiple of 9
        else if (a % 2 != 0 && a % 9 == 0) {
            cout << "Bob" << "\n";
        }
        // Otherwise, Charlie
        else {
            cout << "Charlie" << "\n";
        }
    }
    
    return 0;
}
```