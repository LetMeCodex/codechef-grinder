# Greater Average (AVGPROBLEM)

- **Difficulty Rating**: 500
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine if the average of two given integers, $A$ and $B$, is strictly greater than a third integer, $C$. We are given $T$ test cases, and for each test case, we receive three integers $A$, $B$, and $C$.

## Intuition & Mathematical Observation

The core of the problem lies in comparing the average of $A$ and $B$ with $C$. Mathematically, we need to check if:

$$ \frac{A + B}{2} > C $$

A direct implementation of this inequality might involve floating-point division, which can sometimes lead to precision issues. To avoid this, we can manipulate the inequality to work solely with integers.

Since $A$, $B$, and $C$ are positive integers, we can multiply both sides of the inequality by 2 without changing the direction of the inequality:

$$ 2 \times \frac{A + B}{2} > 2 \times C $$

This simplifies to:

$$ A + B > 2 \times C $$

This integer-based comparison is robust and avoids any potential floating-point inaccuracies. Therefore, the condition to check is simply whether the sum of $A$ and $B$ is strictly greater than twice the value of $C$.

## Complexity Analysis

- **Time Complexity**: $O(1)$
    For each test case, we perform a constant number of arithmetic operations (addition and multiplication) and a comparison. Since the number of operations does not depend on the input values $A$, $B$, or $C$, the time complexity per test case is $O(1)$. With $T$ test cases, the total time complexity is $O(T)$.

- **Space Complexity**: $O(1)$
    We only use a few variables to store the input integers and the loop counter. The amount of memory used does not grow with the input size, making the space complexity $O(1)$.

## Solution Code

```cpp
#include <iostream>

int main() {
    // Optimize C++ standard streams for competitive programming.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C stdio.
    // std::cin.tie(NULL) unties cin from cout.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; // Variable to store the number of test cases.
    std::cin >> t; // Read the number of test cases.

    // Loop through each test case.
    while (t--) {
        int a, b, c; // Variables to store the three integers for the current test case.
        std::cin >> a >> b >> c; // Read the three integers.

        // The problem asks to check if the average of A and B is strictly greater than C.
        // Mathematically, this is (A + B) / 2 > C.
        // To avoid floating-point arithmetic and potential precision issues,
        // we can multiply both sides of the inequality by 2.
        // Since A, B, and C are positive integers, multiplying by 2 preserves the inequality.
        // The condition becomes A + B > 2 * C.

        if (a + b > 2 * c) {
            // If the condition is met, print "YES".
            std::cout << "YES\n";
        } else {
            // Otherwise, print "NO".
            std::cout << "NO\n";
        }
    }

    return 0; // Indicate successful execution.
}
```