# [Triplet Maximization (MAX123)](https://www.codechef.com/problems/MAX123)
- **Difficulty Rating**: 994
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to form triplets using a given count of '1's (`X`) and '2's (`Y`). Each triplet must contain exactly three numbers. We are guaranteed that the total number of elements `X + Y` is always a multiple of 3, meaning all numbers can be used to form triplets.

The score for each type of triplet is defined as follows:
- (1,1,1) triplet: Score of 1
- (1,1,2) triplet: Score of 2
- (1,2,2) triplet: Score of 2
- (2,2,2) triplet: Score of 2

Our goal is to maximize the total score obtained from all formed triplets.

## Intuition & Mathematical Observation

The key observation is that any triplet containing at least one '2' (i.e., (1,1,2), (1,2,2), (2,2,2)) gives a score of 2, while the (1,1,1) triplet gives a score of 1. To maximize the total score, we should try to maximize the number of triplets that score 2, which is equivalent to minimizing the number of (1,1,1) triplets.

A '2' is most effective at preventing (1,1,1) triplets when it's used in a (1,1,2) configuration, as it "covers" two '1's. If we have an abundance of '1's, we should prioritize forming (1,1,2) triplets to use up as many '1's as possible with the available '2's.

Let `N = (X + Y) / 3` be the total number of triplets that will be formed, since `X+Y` is guaranteed to be a multiple of 3.

We can analyze two main cases:

**Case 1: We have enough '2's to prevent any (1,1,1) triplets.**
This happens when the number of '1's (`X`) can be entirely "covered" by the '2's. Since each '2' can cover up to two '1's (in a (1,1,2) triplet), we have enough '2's if `X <= 2 * Y`.
In this scenario, we can ensure that every '1' is paired with at least one '2', or that all '1's are used up in (1,1,2) triplets, and any remaining '2's form (1,2,2) or (2,2,2) triplets. In any case, no (1,1,1) triplets will be formed.
Since all `N` triplets will contain at least one '2', each will contribute 2 to the score.
Total score = `2 * N = 2 * (X + Y) / 3`.

**Case 2: We have too many '1's relative to '2's.**
This happens when `X > 2 * Y`. In this situation, we don't have enough '2's to prevent all (1,1,1) triplets.
To minimize (1,1,1) triplets, we should use all `Y` '2's to form (1,1,2) triplets.
- We form `Y` triplets of type (1,1,2).
- These `Y` triplets use `Y` '2's and `2 * Y` '1's.
- The score from these triplets is `Y * 2`.
- After forming these, we are left with `X - 2 * Y` '1's and `0` '2's.
- The remaining `X - 2 * Y` '1's must be grouped into (1,1,1) triplets.
- The number of such (1,1,1) triplets is `(X - 2 * Y) / 3`.
- The score from these triplets is `(X - 2 * Y) / 3 * 1`.

Combining the scores from both types of triplets:
Total score = `(Y * 2) + ((X - 2 * Y) / 3)`
Total score = `(6 * Y + X - 2 * Y) / 3`
Total score = `(X + 4 * Y) / 3`.

This covers all scenarios and provides a direct formula for each case. It's important to use `long long` for calculations involving `X` and `Y` as they can be up to `10^9`, and `X + 4*Y` can exceed the capacity of a 32-bit integer.

## Complexity Analysis

-   **Time Complexity**: $O(T)$
    The solution processes each of the `T` test cases independently. For each test case, it performs a constant number of arithmetic operations (reading inputs, comparisons, additions, multiplications, divisions). The `std::ios_base::sync_with_stdio(false);` and `std::cin.tie(NULL);` lines optimize I/O and run in constant time once. Thus, the total time complexity is directly proportional to the number of test cases, $O(T)$. Given $T \le 100$, this is extremely efficient.

-   **Space Complexity**: $O(1)$
    The solution uses a fixed number of variables (`T`, `X`, `Y`, `total_score`) regardless of the input values or the number of test cases. These variables occupy a constant amount of memory. Therefore, the space complexity is constant, $O(1)$.

## Solution Code

```cpp
#include <iostream> // Required for input/output operations

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T; // Variable to store the number of test cases
    std::cin >> T; // Read the number of test cases

    // Loop through each test case
    while (T--) {
        long long X, Y; // Variables to store the number of 1's and 2's.
                        // Using long long for X and Y to handle large inputs up to 10^9.
        std::cin >> X >> Y; // Read X and Y for the current test case

        long long total_score; // Use long long for score to prevent overflow,
                               // as X + 4*Y can exceed 2*10^9.

        // Case 1: We have enough '2's to pair with all '1's such that no (1,1,1) triplets are formed.
        // Each '2' can effectively "cover" up to two '1's in a (2,1,1) triplet.
        // If X <= 2*Y, it means we have enough '2's to ensure all '1's are part of a triplet
        // that contains at least one '2'. Thus, all (X+Y)/3 triplets will contribute 2 to the score.
        if (X <= 2 * Y) {
            total_score = 2LL * (X + Y) / 3;
        }
        // Case 2: We have too many '1's relative to '2's.
        // We use all 'Y' twos to cover 2*Y ones (by forming Y triplets of type (2,1,1)).
        // This leaves X - 2*Y ones that cannot be paired with any '2'.
        // These remaining (X - 2*Y) ones must be grouped into (1,1,1) triplets.
        // The number of such (1,1,1) triplets is (X - 2*Y) / 3.
        // These (X - 2*Y) / 3 triplets will contribute 1 each to the score.
        // The remaining triplets (the Y triplets of type (2,1,1)) will contribute 2 each to the score.
        // The simplified formula for this case is (X + 4*Y) / 3.
        else { // X > 2 * Y
            total_score = (X + 4LL * Y) / 3;
        }
        
        // Output the maximum possible score for the current test case, followed by a newline
        std::cout << total_score << "\n";
    }

    return 0; // Indicate successful execution
}
```