# [Donation Rewards (DOREWARD)](https://www.codechef.com/problems/DOREWARD)
- **Difficulty Rating**: 395
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine the donation reward based on a given integer `x`. The rules are as follows:
- If `x` is less than or equal to 3, the reward is "BRONZE".
- If `x` is greater than 3 but less than or equal to 6, the reward is "SILVER".
- If `x` is greater than 6, the reward is "GOLD".

We are given `t` test cases, and for each test case, we need to output the corresponding reward.

## Intuition & Mathematical Observation

The problem statement directly provides the conditions for assigning each reward. There isn't a complex mathematical derivation required. The core of the problem is to translate these conditional statements into code.

We can observe that the conditions are mutually exclusive and cover all possible positive integer values of `x` (assuming `x` is always positive as per typical competitive programming constraints for such problems).

The conditions can be represented as:
1. `x <= 3`
2. `3 < x <= 6`
3. `x > 6`

These are standard range-based conditional checks.

## Complexity Analysis

- **Time Complexity**: $O(1)$
  For each test case, we perform a fixed number of comparisons and a single output operation. The number of operations does not depend on the input value `x` or the number of test cases `t` (beyond the loop for `t`). Therefore, the time complexity per test case is constant. Since there are `t` test cases, the total time complexity is $O(t)$, but often when analyzing a single test case, it's considered $O(1)$.

- **Space Complexity**: $O(1)$
  We only use a few variables (`t`, `x`) to store input and intermediate values. The memory usage is constant and does not grow with the input size.

## Solution Code

```cpp
#include <iostream>

int main() {
    // Optimize C++ standard streams for competitive programming
    // Disables synchronization with C's stdio and unties cin from cout
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; // Variable to store the number of test cases
    std::cin >> t; // Read the number of test cases

    // Loop through each test case
    while (t--) {
        int x; // Variable to store the donation amount
        std::cin >> x; // Read the donation amount for the current test case

        // Check the conditions for the donation reward
        if (x <= 3) {
            // If x is 3 or less, the reward is BRONZE
            std::cout << "BRONZE\n";
        } else if (x > 3 && x <= 6) {
            // If x is greater than 3 and less than or equal to 6, the reward is SILVER
            // The condition 'x > 3' is implicitly handled by the 'else if'
            // after the first 'if (x <= 3)' fails. So, 'x <= 6' is sufficient here.
            std::cout << "SILVER\n";
        } else { // This covers the case where x > 6
            // If x is greater than 6, the reward is GOLD
            std::cout << "GOLD\n";
        }
    }

    return 0; // Indicate successful execution
}
```