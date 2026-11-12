# Itz Simple (SPC2025Q2)
- **Difficulty Rating**: 791
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to determine who has a greater total height, Ved or Varun, after distributing a set of chairs with varying heights. Ved starts with an initial height `k`, and Varun starts with an initial height `p`. There are `n` chairs with given heights. The rule for distributing the chairs is as follows:
1. Find the maximum height among all the chairs.
2. Ved gets to pick *one* chair of the maximum height.
3. All other chairs (including any remaining chairs of the maximum height) are given to Varun.

We need to output "Ved" if Ved's total height is greater, "Varun" if Varun's total height is greater, and "Equal" if their total heights are the same.

## Intuition & Mathematical Observation
The core of the problem lies in correctly distributing the chairs according to the rules.

1.  **Finding the Maximum Chair Height**: The first step is to identify the maximum height among all the `n` chairs. This can be done by iterating through the array of chair heights and keeping track of the maximum value encountered.

2.  **Ved's Chair**: Ved is guaranteed to get *one* chair of the maximum height. This is a crucial point. If there are multiple chairs with the maximum height, Ved still only gets one of them.

3.  **Varun's Chairs**: Varun gets *all* the remaining chairs. This includes:
    *   All chairs that are *not* of the maximum height.
    *   Any chairs that *are* of the maximum height, *except* for the one that Ved picks.

4.  **Calculating Total Heights**:
    *   Ved's total height will be his initial height `k` plus the height of the single maximum-height chair he picks.
    *   Varun's total height will be his initial height `p` plus the sum of the heights of all the chairs he receives.

**Let's formalize this:**

Let `a` be the array of chair heights.
Let `max_chair_height` be the maximum value in `a`.

Ved's total height = `k` + `max_chair_height`

Varun's total height = `p` + (Sum of all chair heights in `a` - `max_chair_height`)

This is because if we sum all chair heights and subtract one instance of `max_chair_height`, we are left with the sum of heights of all chairs *except* the one Ved took.

**Example Walkthrough:**
Suppose `n = 3`, `k = 10`, `p = 5`, and chair heights `a = [5, 8, 8]`.

1.  `max_chair_height` = 8.
2.  Ved gets one chair of height 8.
3.  Varun gets the chair of height 5 and the other chair of height 8.

Ved's total height = `k` + `max_chair_height` = 10 + 8 = 18.
Varun's total height = `p` + (height of chair 1) + (height of chair 2) = 5 + 5 + 8 = 18.
In this case, the heights are equal.

**Alternative Calculation for Varun:**
The provided code implements a slightly different, but equivalent, logic for calculating Varun's height. It iterates through the chairs:
*   If a chair has the `max_chair_height` and Ved hasn't taken one yet, Ved takes it.
*   Otherwise (if the chair is not the max height, or if it is the max height but Ved already took one), Varun takes it.

This approach is also correct and might be more intuitive to implement directly from the problem statement.

Let's trace the code's logic with the example `a = [5, 8, 8]`, `k = 10`, `p = 5`:
`max_chair_height = 8`.
`ved_total_height = k = 10`.
`varun_total_height = p = 5`.
`ved_got_max = false`.

Iteration 1: `a[0] = 5`. `a[0]` is not `max_chair_height`. `varun_total_height += 5` (becomes 10).
Iteration 2: `a[1] = 8`. `a[1]` is `max_chair_height`. `ved_got_max` is `false`. So, `ved_total_height += 8` (becomes 18). `ved_got_max` becomes `true`.
Iteration 3: `a[2] = 8`. `a[2]` is `max_chair_height`. `ved_got_max` is `true`. So, `varun_total_height += 8` (becomes 18).

Finally, compare `ved_total_height` (18) and `varun_total_height` (18). They are equal.

This logic correctly assigns one max-height chair to Ved and all others to Varun.

## Complexity Analysis
- **Time Complexity**: $O(N)$
    The code iterates through the input array `a` twice:
    1. Once to find the `max_chair_height`. This takes $O(N)$ time.
    2. Once to distribute the chairs and calculate the total heights. This also takes $O(N)$ time.
    Therefore, the total time complexity is $O(N) + O(N) = O(N)$, where $N$ is the number of chairs.

- **Space Complexity**: $O(N)$
    The code uses a `std::vector<int> a(n)` to store the heights of the `n` chairs. This requires $O(N)$ space. The other variables use constant space.
    Therefore, the total space complexity is $O(N)$.

## Solution Code
```cpp
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

int main() {
    // Optimize C++ standard streams for competitive programming
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; // Number of test cases
    std::cin >> t;
    while (t--) {
        int n; // Number of chairs
        long long k, p; // Ved's initial height, Varun's initial height
        std::cin >> n >> k >> p;

        std::vector<int> a(n); // Vector to store chair heights
        int max_chair_height = 0; // Variable to store the maximum chair height

        // Read chair heights and find the maximum height
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
            if (a[i] > max_chair_height) {
                max_chair_height = a[i];
            }
        }

        long long ved_total_height = k; // Initialize Ved's total height
        long long varun_total_height = p; // Initialize Varun's total height

        bool ved_got_max = false; // Flag to ensure Ved only gets one max-height chair

        // Distribute chairs based on the rules
        for (int i = 0; i < n; ++i) {
            if (a[i] == max_chair_height) {
                // If the current chair is the maximum height
                if (!ved_got_max) {
                    // If Ved hasn't received a max-height chair yet, he takes this one
                    ved_total_height += a[i];
                    ved_got_max = true; // Mark that Ved has received his max-height chair
                } else {
                    // If Ved already has a max-height chair, Varun gets this one
                    varun_total_height += a[i];
                }
            } else {
                // If the current chair is not the maximum height, Varun gets it
                varun_total_height += a[i];
            }
        }

        // Compare total heights and print the result
        if (ved_total_height > varun_total_height) {
            std::cout << "Ved\n";
        } else if (varun_total_height > ved_total_height) {
            std::cout << "Varun\n";
        } else {
            std::cout << "Equal\n";
        }
    }
    return 0;
}
```