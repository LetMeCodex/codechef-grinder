# [Butterfly (BFLY)](https://www.codechef.com/problems/BFLY)
- **Difficulty Rating**: 824
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine if it's possible to arrange `R` red, `G` green, and `B` blue butterflies in a single line such that no two butterflies of the same color are adjacent. We are given the counts `R`, `G`, and `B`, which can be as large as $10^8$. There are multiple test cases.

## Intuition & Mathematical Observation

The core of this problem lies in a common combinatorial principle: can we arrange items of different types such that no two items of the same type are adjacent?

Let's denote the counts of the three colors as `R`, `G`, and `B`.
1.  **Find the maximum count**: Identify the color with the highest number of butterflies. Let this maximum count be `max_val`. For example, `max_val = std::max({R, G, B})`.
2.  **Calculate the total count**: Sum up all the butterflies: `total_sum = R + G + B`.
3.  **Calculate the sum of other colors**: The count of butterflies that are *not* of the `max_val` color is `sum_of_others = total_sum - max_val`.

Now, consider the condition for a valid arrangement:
If the most frequent color (`max_val`) constitutes more than half of the total butterflies (`total_sum`), it's impossible to arrange them without two of that color being adjacent. This is because even if you try to separate every butterfly of the `max_val` color with a butterfly of another color, you will run out of "other" butterflies before you can separate all instances of the `max_val` color.

Mathematically, this condition can be expressed as:
If `max_val > total_sum / 2`, then it's impossible.
This is equivalent to `2 * max_val > total_sum`.
Substituting `total_sum = max_val + sum_of_others`, we get:
`2 * max_val > max_val + sum_of_others`
`max_val > sum_of_others`

Conversely, if `max_val <= total_sum / 2` (which means `max_val <= sum_of_others`), it is always possible to construct such an arrangement. A greedy strategy can be used: always place a butterfly of the most frequent color if it doesn't violate the adjacency rule, otherwise place a butterfly of another color. Since no single color is a strict majority, this strategy will always succeed.

Therefore, the condition for a "YES" answer is `max_val <= sum_of_others`.

**Example:**
*   `R=5, G=2, B=1`
    *   `max_val = 5` (Red)
    *   `total_sum = 5 + 2 + 1 = 8`
    *   `sum_of_others = 8 - 5 = 3`
    *   Is `max_val <= sum_of_others`? `5 <= 3` is `false`. So, output "NO".
    *   (Trying to arrange: `R G R B R G R`. The last `R` is adjacent to another `R`.)

*   `R=3, G=2, B=2`
    *   `max_val = 3` (Red)
    *   `total_sum = 3 + 2 + 2 = 7`
    *   `sum_of_others = 7 - 3 = 4`
    *   Is `max_val <= sum_of_others`? `3 <= 4` is `true`. So, output "YES".
    *   (Possible arrangement: `R G R B R G B`)

The solution implements this direct comparison.

## Complexity Analysis

*   **Time Complexity**: $O(T)$
    For each test case, the solution performs a constant number of operations: reading three integers, finding the maximum of three numbers, performing a few arithmetic operations, and a comparison. These operations take $O(1)$ time. Since there are $T$ test cases, the total time complexity is $O(T)$.

*   **Space Complexity**: $O(1)$
    The solution uses a fixed number of `long long` variables to store `R`, `G`, `B`, `max_val`, `total_sum`, and `sum_of_others`. This amount of memory is constant and does not depend on the input values (other than the number of test cases).

## Solution Code

```cpp
#include <iostream>   // Required for input/output operations (std::cin, std::cout)
#include <algorithm>  // Required for std::max (used with an initializer list)
#include <vector>     // Not strictly necessary for this solution, but often included with <algorithm> or <bits/stdc++.h>

void solve() {
    long long R, G, B; // Use long long to handle values up to 10^8 and their sums
    std::cin >> R >> G >> B;

    // The problem can be solved by checking if the largest count among R, G, B
    // is less than or equal to the sum of the other two counts.

    // Find the maximum of the three numbers.
    // std::max can take an initializer list {R, G, B} in C++11 and later.
    long long max_val = std::max({R, G, B});

    // Calculate the sum of all three numbers.
    long long total_sum = R + G + B;

    // The sum of the other two numbers is simply total_sum - max_val.
    long long sum_of_others = total_sum - max_val;

    // If the largest count is less than or equal to the sum of the other two,
    // then a valid assignment is possible. Otherwise, it's not.
    // This condition (max_val <= sum_of_others) is equivalent to max_val <= (total_sum / 2).
    // If one color constitutes more than half of the total butterflies, it's impossible
    // to arrange them without two of that color being adjacent. Otherwise, it's always possible.
    if (max_val <= sum_of_others) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T; // Variable to store the number of test cases
    std::cin >> T; // Read the number of test cases

    // Loop through each test case
    while (T--) {
        solve(); // Call the solve function for each test case
    }

    return 0; // Indicate successful execution
}
```