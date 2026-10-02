# [50-50 Rule (NGRS)](https://www.codechef.com/problems/NGRS)
- **Difficulty Rating**: 524
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine a specific character ('A', 'F', or 'Z') based on two integer inputs, `x` and `y`. These integers represent scores or percentages. The rules for determining the character are as follows:
1. If `x` is less than 50, the output should be 'Z'.
2. Otherwise (if `x` is 50 or greater):
   a. If `y` is less than 50, the output should be 'F'.
   b. Otherwise (if `y` is 50 or greater), the output should be 'A'.

We need to process multiple test cases, applying these rules for each pair of `x` and `y`.

## Intuition & Mathematical Observation

The problem statement directly provides a set of conditional rules. There's no complex mathematical observation or algorithm required beyond translating these rules into a series of `if-else` statements.

The logic can be broken down sequentially:
1. **First Check**: The primary condition is on `x`. If `x < 50`, we immediately know the answer is 'Z', and no further checks are needed.
2. **Second Check (if `x >= 50`)**: If the first condition is false (meaning `x` is 50 or greater), we then proceed to check `y`.
   a. If `y < 50`, the answer is 'F'.
   b. If `y >= 50`, the answer is 'A'.

This forms a simple nested conditional structure. The solution code directly implements this logic using `if-else` statements.

## Complexity Analysis

-   **Time Complexity**: $O(T)$
    For each test case, the program reads two integers (`x` and `y`), performs at most two comparisons, and prints a single character. All these operations take constant time. If there are `T` test cases, the total time complexity will be $T$ times a constant amount of work, which simplifies to $O(T)$.

-   **Space Complexity**: $O(1)$
    The program uses a few integer variables (`t`, `x`, `y`) to store the number of test cases and the input values for each test case. These variables occupy a fixed amount of memory regardless of the input values or the number of test cases. Therefore, the space complexity is constant, $O(1)$.

## Solution Code

```cpp
#include <iostream>

int main() {
    // Optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) prevents std::cout from flushing before std::cin reads input.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; // Variable to store the number of test cases
    std::cin >> t; // Read the number of test cases

    // Loop through each test case
    while (t--) {
        int x, y; // Variables to store the two input integers
        std::cin >> x >> y; // Read x and y for the current test case

        // Apply the 50-50 rule logic
        if (x < 50) {
            // If x is less than 50, output 'Z'
            std::cout << "Z\n";
        } else {
            // If x is 50 or greater, check y
            if (y < 50) {
                // If y is less than 50, output 'F'
                std::cout << "F\n";
            } else {
                // If y is 50 or greater, output 'A'
                std::cout << "A\n";
            }
        }
    }

    return 0; // Indicate successful execution
}

```