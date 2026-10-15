# [Bowling Balls (BOWLBALL)](https://www.codechef.com/problems/BOWLBALL)
- **Difficulty Rating**: 580
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to count the number of bowling balls whose weight falls within a specified range. We are given `N` bowling balls, and for each ball, its weight. We are also given two integers, `X` and `Y`, representing the lower and upper bounds (inclusive) of the desired weight range. Our task is to output the total count of balls whose weight `W` satisfies `X <= W <= Y`. This process needs to be repeated for `T` test cases.

## Intuition & Mathematical Observation

The problem is a direct application of conditional counting. For each test case, we need to:
1. Initialize a counter to zero.
2. Iterate through all `N` bowling balls.
3. For each ball, read its weight.
4. Check if the ball's weight is greater than or equal to `X` AND less than or equal to `Y`.
5. If the condition is true, increment the counter.
6. After checking all `N` balls, the final value of the counter is the answer for that test case.

There are no complex mathematical observations or advanced algorithms required. It's a straightforward loop and conditional check.

## Complexity Analysis

-   **Time Complexity**: $O(T \cdot N)$
    -   There are `T` test cases.
    -   For each test case, we read `N`, `X`, and `Y` once (constant time).
    -   Then, we iterate `N` times. In each iteration, we read a ball's weight and perform a constant number of comparisons and a potential increment.
    -   Thus, for each test case, the operations are dominated by the loop, taking $O(N)$ time.
    -   The total time complexity across all test cases is $O(T \cdot N)$.

-   **Space Complexity**: $O(1)$
    -   We use a few integer variables (`t`, `n`, `x`, `y`, `count`, `weight`) to store input values and the running count.
    -   The memory used by these variables is constant and does not depend on the input size `N` or the number of test cases `T`.
    -   Therefore, the space complexity is constant.

## Solution Code

```cpp
#include <iostream> // Required for input/output operations (std::cin, std::cout)
#include <vector>   // Not strictly needed for this problem, but often included
#include <algorithm> // Not strictly needed for this problem, but often included

int main() {
    // Optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) prevents std::cout from flushing before std::cin reads input.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; // Declare variable for the number of test cases
    std::cin >> t; // Read the number of test cases

    while (t--) { // Loop through each test case
        int n, x, y; // Declare variables for N (number of balls), X (min weight), Y (max weight)
        std::cin >> n >> x >> y; // Read N, X, and Y for the current test case

        int count = 0; // Initialize a counter for balls within the weight range

        // Loop N times to read the weight of each bowling ball
        for (int i = 0; i < n; ++i) {
            int weight; // Declare variable for the current ball's weight
            std::cin >> weight; // Read the weight of the current ball

            // Check if the ball's weight is within the specified range [X, Y] (inclusive)
            if (weight >= x && weight <= y) {
                count++; // If it is, increment the counter
            }
        }
        // After checking all N balls, print the total count for the current test case
        std::cout << count << "\n";
    }

    return 0; // Indicate successful program execution
}

```