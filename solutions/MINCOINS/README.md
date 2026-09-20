# Minimum number of coins (MINCOINS)
- **Difficulty Rating**: 711
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to find the minimum number of coins required to form a given amount `x`, using only coins of denominations 5 and 10. If it's impossible to form the amount `x`, we should output -1.

## Intuition & Mathematical Observation

We are given two coin denominations: 5 and 10. Our goal is to represent a target amount `x` using the minimum total number of coins. Let `num_5` be the number of 5-rupee coins and `num_10` be the number of 10-rupee coins. We want to minimize `num_5 + num_10` such that:

$10 \times \text{num\_10} + 5 \times \text{num\_5} = x$

where `num_10 >= 0` and `num_5 >= 0` are integers.

First, let's consider the condition for impossibility. Since both denominations are multiples of 5, any sum formed by these coins must also be a multiple of 5. Therefore, if the target amount `x` is not divisible by 5, it's impossible to form it using these coins. In this case, we should output -1.

Now, assuming `x` is divisible by 5, we need to find the minimum number of coins. To minimize the total number of coins (`num_5 + num_10`), we should prioritize using the coin with the larger denomination as much as possible. This is a greedy approach. The larger denomination is 10.

Let's try to use as many 10-rupee coins as possible. The maximum number of 10-rupee coins we can use without exceeding `x` is `x / 10` (integer division). Let this be `num_10_max = x / 10`.

If we use `num_10_max` coins of denomination 10, the amount covered is `num_10_max * 10`. The remaining amount that needs to be covered by 5-rupee coins is:

`remaining_amount = x - (num_10_max * 10)`

Since `x` is divisible by 5, and `num_10_max * 10` is also divisible by 5, the `remaining_amount` will always be divisible by 5.
Furthermore, because `num_10_max` is the largest integer such that `num_10_max * 10 <= x`, the `remaining_amount` will be either 0 or 5.

- If `remaining_amount` is 0, it means `x` was perfectly divisible by 10, and we don't need any 5-rupee coins. So, `num_5 = 0`.
- If `remaining_amount` is 5, it means `x` had a remainder of 5 when divided by 10. We need exactly one 5-rupee coin to cover this remaining amount. So, `num_5 = 1`.

In general, the number of 5-rupee coins needed is `num_5 = remaining_amount / 5`.

The total minimum number of coins will then be `num_10_max + num_5`.

Let's verify this. Suppose `x = 25`.
`x % 5 == 0`, so it's possible.
`num_10_max = 25 / 10 = 2`.
Amount covered by 10s = `2 * 10 = 20`.
`remaining_amount = 25 - 20 = 5`.
`num_5 = 5 / 5 = 1`.
Total coins = `num_10_max + num_5 = 2 + 1 = 3`. (Two 10s and one 5).

Suppose `x = 30`.
`x % 5 == 0`, so it's possible.
`num_10_max = 30 / 10 = 3`.
Amount covered by 10s = `3 * 10 = 30`.
`remaining_amount = 30 - 30 = 0`.
`num_5 = 0 / 5 = 0`.
Total coins = `num_10_max + num_5 = 3 + 0 = 3`. (Three 10s).

This greedy strategy works because using a 10-rupee coin is always more efficient than using two 5-rupee coins to cover the same value (1 coin vs 2 coins). By maximizing the use of 10s, we ensure we are using the minimum number of coins.

## Complexity Analysis

- **Time Complexity**: $O(1)$
  The solution involves a few arithmetic operations (modulo, division, subtraction, addition) and a loop that runs `t` times, where `t` is the number of test cases. For each test case, the operations are constant time. Therefore, the total time complexity is $O(t)$. If we consider the complexity per test case, it's $O(1)$.

- **Space Complexity**: $O(1)$
  The solution uses a fixed amount of extra space for variables like `t`, `x`, `num_10`, `remaining_amount`, and `num_5`, regardless of the input size. Thus, the space complexity is $O(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    // Optimize C++ standard streams for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; // Number of test cases
    cin >> t;
    while (t--) {
        int x; // The target amount
        cin >> x;

        // If x is not divisible by 5, it's impossible to form it using denominations 5 and 10.
        // This is because any sum of multiples of 5 and 10 will always be a multiple of 5.
        if (x % 5 != 0) {
            cout << -1 << "\n";
        } else {
            // To minimize the number of coins, we should prioritize using coins of denomination 10.
            // Let num_10 be the number of 10 rupee coins and num_5 be the number of 5 rupee coins.
            // We want to minimize num_10 + num_5 such that 10 * num_10 + 5 * num_5 = x.

            // The maximum number of 10 rupee coins we can use is x / 10 (integer division).
            // This is a greedy approach: use the largest denomination as much as possible.
            int num_10 = x / 10;

            // Calculate the remaining amount after using the maximum possible 10 rupee coins.
            int remaining_amount = x - (num_10 * 10);

            // The remaining amount must be paid using 5 rupee coins.
            // Since x is divisible by 5 and we used as many 10s as possible,
            // the remaining_amount will be either 0 or 5.
            // If remaining_amount is 0, we need 0 coins of 5.
            // If remaining_amount is 5, we need 1 coin of 5.
            int num_5 = remaining_amount / 5;

            // The total minimum number of coins is the sum of 10 rupee coins and 5 rupee coins.
            cout << num_10 + num_5 << "\n";
        }
    }
    return 0;
}
```