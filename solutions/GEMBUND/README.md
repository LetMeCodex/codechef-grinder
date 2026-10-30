# [Gem Bundles (GEMBUND)](https://www.codechef.com/problems/GEMBUND)
- **Difficulty Rating**: 603
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to find the maximum number of coins we can earn given a certain count of red (R), blue (B), and green (G) gems. We have two ways to earn coins:
1.  **Form a bundle**: Combine 1 red, 1 blue, and 1 green gem to form a bundle. Each bundle sells for 10 coins.
2.  **Sell individually**: Sell any single gem (red, blue, or green) for 3 coins.

We need to calculate the maximum total coins for `T` test cases.

## Intuition & Mathematical Observation

The core of this problem lies in deciding how to best utilize the gems. Let's compare the profitability:
*   **Bundle**: 10 coins for 3 gems (1 red + 1 blue + 1 green). This averages to `10/3 ≈ 3.33` coins per gem.
*   **Individual**: 3 coins for 1 gem.

Since forming a bundle yields more coins per gem on average (3.33 vs 3), it is always more profitable to form a bundle if we have the necessary gems. Therefore, our strategy should be to maximize the number of bundles first, and then sell any remaining gems individually.

1.  **Maximize Bundles**: To form a bundle, we need one of each gem type. The number of bundles we can form is limited by the gem type with the minimum count. For example, if we have 5 red, 3 blue, and 7 green gems, we can only form `min(5, 3, 7) = 3` bundles.
    *   Let `num_bundles = min(R, B, G)`.
    *   Coins from bundles = `num_bundles * 10`.

2.  **Sell Remaining Gems Individually**: After forming `num_bundles`, we will have `R - num_bundles` red gems, `B - num_bundles` blue gems, and `G - num_bundles` green gems remaining. At least one of these counts will be zero (because `num_bundles` was the minimum count), meaning we cannot form any more bundles. All these remaining gems must be sold individually.
    *   Total remaining gems = `(R - num_bundles) + (B - num_bundles) + (G - num_bundles)`.
    *   Coins from individual gems = `(Total remaining gems) * 3`.

3.  **Total Coins**: The maximum total coins will be the sum of coins from bundles and coins from individual gems.
    *   `Total Coins = (num_bundles * 10) + ((R - num_bundles) + (B - num_bundles) + (G - num_bundles)) * 3`.

This strategy guarantees maximum coins because we prioritize the more profitable operation (bundles) and then clear out all remaining assets (individual gems).

## Complexity Analysis

*   **Time Complexity**: For each test case, we perform a constant number of operations: reading three integers, finding the minimum of three numbers, and a few arithmetic calculations. Since there are `T` test cases, the total time complexity is **O(T)**.
*   **Space Complexity**: We only use a few integer variables to store gem counts, bundle counts, and coin totals. This is a constant amount of memory regardless of the input values. Thus, the space complexity is **O(1)**.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes iostream, algorithm, etc. as per instructions
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin from cout and disables synchronization with C's stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Variable to store the number of test cases
    cin >> T; // Read the number of test cases

    // Loop through each test case
    while (T--) {
        int R, B, G; // Variables to store the counts of red, blue, and green gems
        cin >> R >> B >> G; // Read the gem counts for the current test case

        // Calculate the maximum number of bundles that can be formed.
        // A bundle requires 1 red, 1 blue, and 1 green gem.
        // The number of bundles is limited by the gem type with the minimum count.
        // std::min({R, B, G}) uses an initializer list (C++11 feature) to find the minimum of three values.
        int num_bundles = min({R, B, G});

        // Calculate coins earned from selling bundles.
        // Each bundle sells for 10 coins.
        // Using long long for coins to be safe, though int would suffice given the constraints.
        long long coins_from_bundles = (long long)num_bundles * 10;

        // Calculate the number of remaining gems of each type after forming bundles.
        int remaining_R = R - num_bundles;
        int remaining_B = B - num_bundles;
        int remaining_G = G - num_bundles;

        // Calculate coins earned from selling individual gems.
        // These remaining gems cannot form another bundle (because at least one type is now 0).
        // Each individual gem sells for 3 coins.
        long long coins_from_individuals = (long long)(remaining_R + remaining_B + remaining_G) * 3;

        // The total maximum coins earned is the sum of coins from bundles and individual gems.
        long long total_coins = coins_from_bundles + coins_from_individuals;

        // Output the result for the current test case, followed by a newline.
        cout << total_coins << "\n";
    }

    return 0; // Indicate successful execution
}
```