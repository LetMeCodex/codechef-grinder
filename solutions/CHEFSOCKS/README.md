# [Chef and Socks (CHEFSOCKS)](https://www.codechef.com/problems/CHEFSOCKS)
- **Difficulty Rating**: 212
- **Solved in**: 1 attempt(s)

## Problem Summary

Chef wants to buy a pair of socks. The socks cost `A` rupees. Chef has `X` rupees saved up, and his parents give him an additional `Y` rupees. The task is to determine if Chef has enough money to buy the socks. If he can afford them, output "YES"; otherwise, output "NO".

The input consists of a single line with three space-separated integers: `A`, `X`, and `Y`.
Constraints: `1 <= A, X, Y <= 100`.

## Intuition & Mathematical Observation

The problem is a straightforward application of basic arithmetic and comparison.

1.  **Calculate Total Money**: Chef's total money is the sum of the money he saved (`X`) and the money he received from his parents (`Y`). So, `Total Money = X + Y`.
2.  **Compare with Cost**: Once we have Chef's total money, we compare it with the cost of the socks (`A`).
    *   If `Total Money >= A`, Chef has enough money to buy the socks.
    *   If `Total Money < A`, Chef does not have enough money.

This logic directly translates to an `if-else` condition. Given the small constraints (`A, X, Y <= 100`), the sum `X + Y` will not exceed `200`, which easily fits within standard integer types, so there are no concerns about overflow.

## Complexity Analysis

*   **Time Complexity**: $O(1)$
    The solution involves a fixed number of operations: reading three integers, one addition, one comparison, and one print operation. These operations take constant time regardless of the input values (within their given constraints). Therefore, the time complexity is constant.

*   **Space Complexity**: $O(1)$
    The solution uses a fixed amount of memory to store a few integer variables (`A`, `X`, `Y`, and `total_money_chef_has`). The memory usage does not scale with the input values. Therefore, the space complexity is constant.

## Solution Code

```cpp
#include <bits/stdc++.h> // Required include for competitive programming

// Required using namespace std;
using namespace std;

int main() {
    // Required fast I/O setup for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Declare three integer variables:
    // A: the cost of the socks
    // X: the amount of money Chef has saved up
    // Y: the additional money Chef received from his parents
    int A, X, Y;

    // Read the three space-separated integers from the first and only line of input.
    // The problem statement explicitly describes a single line of input for A, X, and Y,
    // implying a single test case. Therefore, a loop for multiple test cases is not used
    // as it is not "requested by the problem statement" itself.
    cin >> A >> X >> Y;

    // Calculate the total amount of money Chef has after receiving money from his parents.
    // The constraints (1 <= A, X, Y <= 100) ensure that X + Y will not exceed 200,
    // which easily fits within an 'int' data type, so no overflow issues.
    int total_money_chef_has = X + Y;

    // Compare Chef's total money with the cost of the socks.
    // If Chef's total money is greater than or equal to the cost of the socks,
    // he can afford them.
    if (total_money_chef_has >= A) {
        // Output "YES" followed by a newline character.
        // The problem states that output can be in any case, but "YES" is standard.
        cout << "YES\n";
    } else {
        // Otherwise, Chef cannot afford the socks.
        // Output "NO" followed by a newline character.
        // The problem states that output can be in any case, but "NO" is standard.
        cout << "NO\n";
    }

    // Return 0 to indicate successful execution.
    return 0;
}
```