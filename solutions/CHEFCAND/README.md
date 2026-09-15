# [Chef and Candies (CHEFCAND)](https://www.codechef.com/problems/CHEFCAND)
- **Difficulty Rating**: 570
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine the minimum number of candy packets Chef needs to buy. Chef has `N` children, and each child requires 1 candy. This means Chef needs a total of `N` candies. Chef already possesses `X` candies. Candies are sold in packets, with each packet containing exactly 4 candies. We need to output the minimum number of packets Chef must purchase.

## Intuition & Mathematical Observation

1.  **Total Candies Required**: Chef needs `N` candies in total, as there are `N` children and each needs one candy.
2.  **Candies Chef Already Has**: Chef currently has `X` candies.
3.  **Candies Still Needed**: The number of additional candies Chef needs to acquire is `N - X`.
    *   **Case 1: Chef has enough or more candies.** If `N - X <= 0`, it means Chef already has `N` or more candies. In this scenario, Chef doesn't need to buy any additional packets. The answer is `0`.
    *   **Case 2: Chef needs more candies.** If `N - X > 0`, Chef needs `N - X` more candies. Let `needed_candies = N - X`.
4.  **Calculating Packets to Buy**: Candies are sold in packets of 4. To get `needed_candies`, Chef must buy enough packets to cover this amount. Since we want the *minimum* number of packets, we need to perform a **ceiling division**.
    *   For example, if Chef needs 1 candy, they must buy 1 packet (getting 4 candies).
    *   If Chef needs 4 candies, they must buy 1 packet.
    *   If Chef needs 5 candies, they must buy 2 packets (getting 8 candies).
    *   The formula for ceiling division `ceil(a/b)` for positive integers `a` and `b` using integer arithmetic is `(a + b - 1) / b`.
    *   In our case, `a = needed_candies` and `b = 4`. So, the minimum number of packets to buy will be `(needed_candies + 4 - 1) / 4`.

Combining these observations, we first calculate `needed_candies = N - X`. If this value is less than or equal to 0, the answer is 0. Otherwise, we apply the ceiling division formula to `needed_candies` and 4.

## Complexity Analysis

*   **Time Complexity**: $O(1)$ per test case.
    *   Inside the `solve()` function, we perform a few basic arithmetic operations (subtraction, comparison, addition, division) and input/output operations. All these operations take constant time.
    *   Since the `main()` function calls `solve()` `T` times, the total time complexity will be $O(T)$.
*   **Space Complexity**: $O(1)$
    *   We only use a few integer variables (`N`, `X`, `needed_candies`, `packets_to_buy`) to store input and intermediate results. This requires a constant amount of extra space, regardless of the input values.

## Solution Code

```cpp
#include <bits/stdc++.h> // Required by problem statement

// Use standard namespace as required by problem statement
using namespace std;

void solve() {
    int N, X;
    cin >> N >> X; // Read N (number of children) and X (candies Chef already has)

    // Calculate how many more candies Chef needs.
    // If N - X is positive, Chef needs more candies.
    // If N - X is zero or negative, Chef already has enough or more candies.
    int needed_candies = N - X;

    if (needed_candies <= 0) {
        // Chef already has enough or more candies than required.
        // No packets need to be bought.
        cout << 0 << "\n";
    } else {
        // Chef needs 'needed_candies' more candies.
        // Candies are available in packets of 4.
        // To find the minimum number of packets, we need to perform a ceiling division.
        // For positive integers 'a' and 'b', ceil(a/b) can be calculated using integer arithmetic
        // as (a + b - 1) / b. Here, 'a' is needed_candies and 'b' is 4.
        int packets_to_buy = (needed_candies + 4 - 1) / 4;
        cout << packets_to_buy << "\n";
    }
}

int main() {
    // Enable fast I/O as required by problem statement
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) { // Loop T times, calling solve() for each test case
        solve();
    }

    return 0;
}
```