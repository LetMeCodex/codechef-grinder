# [Interior Design (INTRDSGN)](https://www.codechef.com/problems/INTRDSGN)
- **Difficulty Rating**: 373
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem presents a scenario where Chef needs to choose between two interior design styles. Each style has two associated costs: one for materials and one for labor. For the first style, the material cost is $X_1$ and the labor cost is $Y_1$. For the second style, the material cost is $X_2$ and the labor cost is $Y_2$. Chef wants to choose the style that results in the minimum total cost. The task is to output this minimum total cost. The problem involves multiple test cases.

## Intuition & Mathematical Observation

The problem is quite straightforward and primarily involves basic arithmetic and comparison.

1.  **Calculate Total Cost for Each Style**: For any given style, its total cost is simply the sum of its material cost and labor cost.
    *   For the first style, the total cost will be $X_1 + Y_1$.
    *   For the second style, the total cost will be $X_2 + Y_2$.

2.  **Compare and Find Minimum**: Once we have the total costs for both styles, Chef will choose the one that costs less. This means we need to find the minimum of the two calculated total costs.

There are no complex algorithms, data structures, or advanced mathematical concepts required. It's a direct application of addition and comparison.

## Complexity Analysis

*   **Time Complexity**: $O(T)$
    For each test case, we perform a fixed number of operations: four integer reads, two additions, one comparison, and one integer print. These operations take constant time, $O(1)$. Since there are $T$ test cases, the total time complexity will be $T \times O(1)$, which simplifies to $O(T)$.

*   **Space Complexity**: $O(1)$
    We use a constant number of integer variables to store the input values ($X_1, Y_1, X_2, Y_2$), the number of test cases ($T$), and the calculated total costs (`cost1`, `cost2`, `min_cost`). The memory usage does not grow with the input values or the number of test cases (beyond the fixed number of variables). Therefore, the space complexity is constant, $O(1)$.

## Solution Code

```cpp
#include <iostream> // Required for cin, cout
#include <algorithm> // Required for std::min

int main() {
    // Optimize C++ standard streams for competitive programming.
    // This unties cin from cout and disables synchronization with C's stdio.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T; // Declare variable for the number of test cases
    std::cin >> T; // Read the number of test cases

    // Loop through each test case
    while (T--) {
        int X1, Y1, X2, Y2; // Declare variables for costs
        // Read the four space-separated integers for the current test case
        std::cin >> X1 >> Y1 >> X2 >> Y2;

        // Calculate the total cost for the first style
        int cost1 = X1 + Y1;
        // Calculate the total cost for the second style
        int cost2 = X2 + Y2;

        // Chef chooses the style with the lower total cost.
        // Use std::min to find the minimum of the two costs.
        int min_cost = std::min(cost1, cost2);

        // Output the minimum cost followed by a newline character
        std::cout << min_cost << "\n";
    }

    return 0; // Indicate successful execution
}
```