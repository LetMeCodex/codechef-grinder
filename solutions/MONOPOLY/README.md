# [Monopoly in Chefland (MONOPOLY)](https://www.codechef.com/problems/MONOPOLY)
- **Difficulty Rating**: 482
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine if a "monopoly" exists among three companies in Chefland. We are given the production quantities of these three companies, $R_1, R_2,$ and $R_3$. A monopoly is defined as a situation where one company produces strictly more than the sum of the products of the other two companies. We need to output "Yes" if a monopoly exists, and "No" otherwise. This check needs to be performed for multiple test cases.

## Intuition & Mathematical Observation

The problem statement directly provides the condition for a monopoly. Let the production quantities be $R_1, R_2,$ and $R_3$. A monopoly exists if any of the following conditions are true:

1.  Company 1 produces strictly more than the sum of Company 2 and Company 3: $R_1 > R_2 + R_3$
2.  Company 2 produces strictly more than the sum of Company 1 and Company 3: $R_2 > R_1 + R_3$
3.  Company 3 produces strictly more than the sum of Company 1 and Company 2: $R_3 > R_1 + R_2$

If any one of these conditions holds, then it's a monopoly. If none of them hold, it's not a monopoly.
The solution simply involves reading the three production quantities and checking these three conditions using logical OR (`||`). If the expression `(R1 > R2 + R3) || (R2 > R1 + R3) || (R3 > R1 + R2)` evaluates to true, we print "Yes"; otherwise, we print "No".

The problem specifies that $R_i$ can be up to $10^9$, so their sum can exceed the range of a 32-bit integer. Therefore, `long long` should be used for $R_1, R_2, R_3$ to prevent overflow when calculating sums like $R_1 + R_2$.

## Complexity Analysis

-   **Time Complexity**: $O(T)$
    The program consists of a loop that runs $T$ times (where $T$ is the number of test cases). Inside the loop, we perform a constant number of operations: reading three `long long` integers, a few additions, a few comparisons, and printing a string. Each of these operations takes constant time, $O(1)$. Therefore, the total time complexity is $T \times O(1) = O(T)$.

-   **Space Complexity**: $O(1)$
    The program uses a fixed number of variables (`t`, `r1`, `r2`, `r3`) regardless of the input values or the number of test cases. No data structures that grow with input size are used. Thus, the space complexity is constant, $O(1)$.

## Solution Code

```cpp
#include <iostream>
#include <algorithm> // Not strictly necessary for this problem, but often included

int main() {
    // Optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) prevents std::cout from flushing before std::cin reads input.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; // Variable to store the number of test cases
    std::cin >> t; // Read the number of test cases

    while (t--) { // Loop through each test case
        long long r1, r2, r3; // Variables to store production quantities (using long long for sums up to 2*10^9)
        std::cin >> r1 >> r2 >> r3; // Read the three production quantities

        // Check the monopoly condition:
        // If any one company produces strictly more than the sum of the other two, it's a monopoly.
        if (r1 > r2 + r3 || r2 > r1 + r3 || r3 > r1 + r2) {
            std::cout << "Yes\n"; // Output "Yes" if it's a monopoly
        } else {
            std::cout << "No\n"; // Output "No" otherwise
        }
    }

    return 0; // Indicate successful execution
}

```