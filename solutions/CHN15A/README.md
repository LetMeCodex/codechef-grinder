# Mutated Minions (CHN15A)
- **Difficulty Rating**: 777
- **Solved in**: 2 attempt(s)

## Problem Summary

The problem asks us to count how many minions, after being mutated by a factor `K`, will have a "power level" that is a multiple of 7. We are given `N` minions, each with an initial power level. For each minion, its mutated power level is calculated as `(initial_power_level + K) % 7`. We need to output the total count of minions whose mutated power level is exactly 0 (since a multiple of 7 is congruent to 0 modulo 7).

## Intuition & Mathematical Observation

The core of the problem lies in understanding the modulo operation. We are given an initial power level, let's call it `p`, and a mutation factor `K`. The mutated power level is `(p + K) % 7`. We are interested in the cases where this mutated power level is a multiple of 7.

Mathematically, a number is a multiple of 7 if and only if it is congruent to 0 modulo 7. Therefore, we are looking for the number of minions where:

`(initial_power_level + K) % 7 == 0`

This condition directly translates to the check we need to perform for each minion. The problem statement implies that the initial power levels are given as integers. The modulo operator `%` in C++ (and most programming languages) handles negative numbers in a way that might be relevant if `initial_power_level + K` could be negative. However, in competitive programming contexts, power levels are typically non-negative. Even if `initial_power_level + K` were negative, the behavior of the modulo operator in C++ for negative operands is such that `a % n` will have the same sign as `a`. For example, `-1 % 7` is `-1`. However, the problem statement implies we are looking for a result of 0, which is a multiple of 7.

Let's consider the properties of modular arithmetic.
If `(p + K) % 7 == 0`, it means that `p + K` is perfectly divisible by 7.
This is equivalent to saying that `p + K = 7m` for some integer `m`.
Rearranging, `p = 7m - K`.
Taking modulo 7 on both sides:
`p % 7 = (7m - K) % 7`
`p % 7 = (-K) % 7`

This observation is interesting but not strictly necessary for the direct implementation. The most straightforward approach is to directly check the condition `(initial_power_level + K) % 7 == 0`.

The problem statement mentions that the input `initial_char` is an integer. It's important to note that the problem statement uses `initial_char` which might be a bit misleading, but the context and the example imply it's an integer representing power level.

The problem is quite direct: iterate through each minion, calculate its mutated power level, and check if it's a multiple of 7.

## Complexity Analysis

- **Time Complexity**: $O(N)$
    The program reads the number of test cases `T`. For each test case, it reads `N` and `K`. Then, it iterates `N` times to read the initial power level of each minion and perform a constant number of operations (addition, modulo, comparison, increment). Therefore, the time complexity for each test case is proportional to `N`. Since there are `T` test cases, the total time complexity is $O(T \times N)$. However, if we consider the input size as the total number of minions across all test cases, the complexity is $O(\sum N)$. Given the typical constraints in competitive programming, this linear scan is efficient.

- **Space Complexity**: $O(1)$
    The program uses a few integer variables (`T`, `N`, `K`, `wolverine_count`, `initial_char`) to store the input and the count. The amount of memory used does not depend on the input size `N` or `T` (beyond storing the current values). Thus, the space complexity is constant.

## Solution Code

```cpp
#include <iostream>
#include <vector> // Although vector is included, it's not used in the final solution.

int main() {
    // Optimize C++ standard streams for competitive programming.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C stdio.
    // std::cin.tie(NULL) unties cin from cout, so cin operations don't flush cout.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T; // Number of test cases
    std::cin >> T;

    while (T--) { // Loop through each test case
        int N; // Number of minions
        int K; // Mutation factor
        std::cin >> N >> K;

        int wolverine_count = 0; // Counter for minions that become "Wolverines"

        for (int i = 0; i < N; ++i) { // Iterate through each minion
            int initial_power_level; // Initial power level of the minion
            std::cin >> initial_power_level;

            // Calculate the mutated power level and check if it's a multiple of 7.
            // A number is a multiple of 7 if its remainder when divided by 7 is 0.
            if ((initial_power_level + K) % 7 == 0) {
                wolverine_count++; // Increment the count if the condition is met
            }
        }
        std::cout << wolverine_count << std::endl; // Output the total count for the current test case
    }

    return 0; // Indicate successful execution
}
```