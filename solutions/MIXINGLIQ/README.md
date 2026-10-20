# [Mixing Liquids (MIXINGLIQ)](https://www.codechef.com/problems/MIXINGLIQ)
- **Difficulty Rating**: 553
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given two quantities: `a` representing the amount of orange syrup and `b` representing the amount of water. We want to mix these to create a new liquid where the ratio of orange syrup to water is exactly 1:2. Our goal is to find the maximum total amount of the new liquid we can create.

## Intuition & Mathematical Observation
The problem states that the final mixture must have a syrup-to-water ratio of 1:2. This means for every 1 unit of orange syrup used, we must use 2 units of water.

Let $S$ be the amount of orange syrup we use, and $W$ be the amount of water we use.
According to the required ratio, we must have:
$W = 2 \times S$

We are also constrained by the available amounts of syrup and water:
$S \le a$ (we cannot use more syrup than we have)
$W \le b$ (we cannot use more water than we have)

Now, let's substitute the ratio requirement ($W = 2 \times S$) into the water constraint:
$2 \times S \le b$

This inequality can be rewritten to find an upper bound for $S$ based on the available water:
$S \le \frac{b}{2}$

So, to create the mixture, the amount of syrup we use, $S$, must satisfy two conditions simultaneously:
1. $S \le a$ (limited by available syrup)
2. $S \le \frac{b}{2}$ (limited by available water to maintain the 1:2 ratio)

To maximize the total amount of the new liquid, we need to maximize the amount of syrup used, $S$. The maximum possible integer value for $S$ that satisfies both conditions is the minimum of the two upper bounds:
$S_{max} = \min\left(a, \left\lfloor \frac{b}{2} \right\rfloor\right)$

Since we are dealing with integer amounts, we take the floor of $b/2$.

Once we determine the maximum amount of syrup we can use ($S_{max}$), the corresponding amount of water we will use is $W_{max} = 2 \times S_{max}$.

The total amount of the new liquid created will be the sum of the syrup and water used:
Total Liquid = $S_{max} + W_{max}$
Total Liquid = $S_{max} + (2 \times S_{max})$
Total Liquid = $3 \times S_{max}$

Therefore, the maximum total amount of liquid is $3 \times \min\left(a, \left\lfloor \frac{b}{2} \right\rfloor\right)$.

## Complexity Analysis
- **Time Complexity**: $O(1)$
  The solution involves a few arithmetic operations and a `min` function. These operations take constant time, regardless of the input values of `a` and `b`. The loop runs `t` times, where `t` is the number of test cases. Thus, for each test case, the time complexity is $O(1)$. The total time complexity for `t` test cases is $O(t)$.

- **Space Complexity**: $O(1)$
  The solution uses a fixed number of variables (`t`, `a`, `b`, `max_syrup_to_use`, `total_juice`) to store input and intermediate results. The memory usage does not grow with the input size. Thus, the space complexity is $O(1)$.

## Solution Code
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        long long a, b;
        cin >> a >> b;

        // The ratio of orange syrup to water must be 1:2.
        // This means for every 1 unit of syrup, we need 2 units of water.
        // Let 's' be the amount of syrup used and 'w' be the amount of water used.
        // We must have w = 2 * s.
        // Also, s <= A and w <= B.
        // Substituting w = 2*s into w <= B, we get 2*s <= B, which means s <= B/2.
        // So, the amount of syrup we can use, 's', must satisfy:
        // s <= A (we have enough syrup)
        // s <= B/2 (we have enough water for the syrup)
        // To maximize the total juice (s + w = s + 2*s = 3*s), we need to maximize 's'.
        // The maximum possible integer value for 's' is min(A, B/2).

        long long max_syrup_to_use = min(a, b / 2);

        // The total juice made is syrup used + water used.
        // If we use 'max_syrup_to_use' units of syrup, we will use 2 * 'max_syrup_to_use' units of water.
        // Total juice = max_syrup_to_use + 2 * max_syrup_to_use = 3 * max_syrup_to_use.
        long long total_juice = 3 * max_syrup_to_use;

        cout << total_juice << "\n";
    }
    return 0;
}
```