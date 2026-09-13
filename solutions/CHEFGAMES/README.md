# [Chefland Games (CHEFGAMES)](https://www.codechef.com/problems/CHEFGAMES)
- **Difficulty Rating**: 550
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem describes a game with Chef, consisting of four rounds. For each round, the result is given as an integer: `1` if Chef wins the round, and `0` if Chef loses the round. We are given the results of all four rounds (`r1`, `r2`, `r3`, `r4`).

The objective is to determine if Chef is "IN" or "OUT" of the game. The problem statement specifies the condition: Chef is considered "IN" if he loses *all* four rounds. Otherwise, if he wins even a single round, he is "OUT". We need to print "IN" or "OUT" accordingly for each test case.

## Intuition & Mathematical Observation

The core of the problem lies in a very direct conditional check. Chef is "IN" *only if* he loses all four rounds. This translates directly to checking if the result of every single round is `0`.

If `r1 = 0` AND `r2 = 0` AND `r3 = 0` AND `r4 = 0`, then Chef has lost all four rounds, and thus he is "IN".
In any other scenario, meaning if at least one of `r1`, `r2`, `r3`, or `r4` is `1` (indicating a win in that round), then Chef has not lost *all* four rounds. In such cases, he is "OUT".

Therefore, the logic is a simple boolean check:
`if (r1 == 0 && r2 == 0 && r3 == 0 && r4 == 0)` then print "IN".
`else` print "OUT".

## Complexity Analysis

-   **Time Complexity**: $O(T)$
    The program reads `T` test cases. For each test case, it performs a constant number of operations:
    1.  Reading four integers (`r1`, `r2`, `r3`, `r4`). This is a fixed number of input operations.
    2.  Performing a single logical `AND` check on four conditions. This is a constant time operation.
    3.  Printing a short string ("IN\n" or "OUT\n"). This is also a constant time operation.
    Since each test case is processed in constant time, the total time complexity is directly proportional to the number of test cases, $O(T)$.

-   **Space Complexity**: $O(1)$
    The program uses a fixed amount of memory regardless of the input size or the number of test cases. It declares a few integer variables (`t`, `r1`, `r2`, `r3`, `r4`) to store input and loop counters. No data structures that grow with input size are used. Hence, the space complexity is constant, $O(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes common libraries like iostream

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; // Variable to store the number of test cases
    std::cin >> t; // Read the number of test cases

    // Loop through each test case
    while (t--) {
        int r1, r2, r3, r4; // Variables to store the results of the four rounds
        std::cin >> r1 >> r2 >> r3 >> r4; // Read the results for the current test case

        // Check if Chef lost all four rounds (all results are 0)
        if (r1 == 0 && r2 == 0 && r3 == 0 && r4 == 0) {
            std::cout << "IN\n"; // If all are 0, Chef is "IN"
        } else {
            std::cout << "OUT\n"; // Otherwise (if at least one is 1), Chef is "OUT"
        }
    }

    return 0; // Indicate successful execution
}

```