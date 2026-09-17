# [Broken Phone (BROKENPHONE)](https://www.codechef.com/problems/BROKENPHONE)
- **Difficulty Rating**: 451
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to help a user decide what to do with their broken phone. We are given two integer values:
1. `X`: The cost to repair the broken phone.
2. `Y`: The cost to buy a new phone.

Based on these costs, we need to output one of three options:
- "REPAIR": If repairing the phone is cheaper than buying a new one.
- "NEW PHONE": If buying a new phone is cheaper than repairing the old one.
- "ANY": If both options cost the same.

This decision needs to be made for `T` independent test cases.

## Intuition & Mathematical Observation

This problem is a direct comparison between two costs. We simply need to evaluate the relationship between `X` and `Y` using standard comparison operators.

1.  **If `X < Y`**: The cost of repairing (`X`) is strictly less than the cost of buying a new phone (`Y`). In this scenario, it is more economical to repair the phone.
    *   Output: "REPAIR"

2.  **If `X > Y`**: The cost of repairing (`X`) is strictly greater than the cost of buying a new phone (`Y`). In this scenario, it is more economical to buy a new phone.
    *   Output: "NEW PHONE"

3.  **If `X == Y`**: The cost of repairing (`X`) is exactly equal to the cost of buying a new phone (`Y`). Since both options cost the same, either choice is equally valid from a financial perspective.
    *   Output: "ANY"

This logic can be implemented using a simple `if-else if-else` structure.

## Complexity Analysis

-   **Time Complexity**: $O(T)$
    For each of the $T$ test cases, the program performs a constant number of operations: reading two integers (`x` and `y`), comparing them, and printing a short string. These operations do not depend on the magnitude of `x` or `y`, only on their existence. Therefore, the total time complexity is directly proportional to the number of test cases, $T$.

-   **Space Complexity**: $O(1)$
    The program uses a fixed amount of memory regardless of the input values or the number of test cases. It only stores a few integer variables (`t`, `x`, `y`) at any given time. No data structures that grow with input size are utilized.

## Solution Code

```cpp
#include <iostream>
#include <string>
#include <algorithm>

int main() {
    // Optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) prevents std::cout from flushing before std::cin reads input.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; // Declare variable for the number of test cases
    std::cin >> t; // Read the number of test cases

    // Loop through each test case
    while (t--) {
        int x, y; // Declare variables for repair cost (x) and new phone cost (y)
        std::cin >> x >> y; // Read the costs for the current test case

        // Apply the decision logic based on cost comparison
        if (x < y) {
            // If repair is cheaper
            std::cout << "REPAIR\n";
        } else if (x > y) {
            // If new phone is cheaper
            std::cout << "NEW PHONE\n";
        } else {
            // If both cost the same
            std::cout << "ANY\n";
        }
    }

    return 0; // Indicate successful execution
}

```