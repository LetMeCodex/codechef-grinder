# [Which Mixture (MIXTURE)](https://www.codechef.com/problems/MIXTURE)
- **Difficulty Rating**: 841
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine the state of a mixture based on the quantities of two components, A and B. We are given the following rules:
1. If both component A and component B are present (i.e., their quantities are greater than 0), the mixture is a "Solution".
2. If component A is present but component B is not (i.e., quantity of A > 0 and quantity of B = 0), the mixture is a "Solid".
3. If component B is present but component A is not (i.e., quantity of B > 0 and quantity of A = 0), the mixture is a "Liquid".

We need to process multiple test cases, for each of which we read the quantities of A and B and print the corresponding state.

## Intuition & Mathematical Observation

The problem is a straightforward conditional logic exercise. We need to check the given conditions in a specific order to correctly classify the mixture. The conditions are mutually exclusive and cover all valid scenarios where A and B are non-negative integers.

Let's analyze the conditions:
1. **`a > 0 && b > 0`**: This is the most specific case where both components are present. If this condition is true, it's a "Solution".
2. **`b == 0`**: If the first condition (`a > 0 && b > 0`) is false, and `b` is 0, it implies that `a` must be greater than 0 (because if `a` were also 0, it wouldn't fit the "Solid" or "Liquid" definitions, and the problem constraints usually ensure valid inputs that fit one of the categories). This scenario corresponds to "Solid".
3. **`a == 0`**: If the first two conditions are false, and `a` is 0, it implies that `b` must be greater than 0. This scenario corresponds to "Liquid".

The order of checking these conditions in an `if-else if` structure is important to ensure correctness. The provided solution code correctly implements this logic by first checking for "Solution", then "Solid", and finally "Liquid".

## Complexity Analysis

-   **Time Complexity**: $O(T)$
    The program reads `T` test cases. For each test case, it performs a constant number of operations: reading two integers, a few comparisons, and printing a string. Each of these operations takes constant time, $O(1)$. Therefore, the total time complexity is directly proportional to the number of test cases, $T$.

-   **Space Complexity**: $O(1)$
    The program uses a fixed amount of memory regardless of the input values or the number of test cases. It only stores a few integer variables (`t`, `a`, `b`) to manage the loop and input values. This constant memory usage leads to an $O(1)$ space complexity.

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
        int a, b; // Variables to store quantities of component A and B
        std::cin >> a >> b; // Read quantities A and B for the current test case

        // Apply the problem's rules using if-else if statements
        if (a > 0 && b > 0) {
            // Rule 1: Both A and B are present
            std::cout << "Solution\n";
        } else if (b == 0) {
            // Rule 2: B is not present (and A must be present, as per problem context)
            std::cout << "Solid\n";
        } else if (a == 0) {
            // Rule 3: A is not present (and B must be present, as per problem context)
            std::cout << "Liquid\n";
        }
    }

    return 0; // Indicate successful execution
}

```