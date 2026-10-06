# [Genes (GENE01)](https://www.codechef.com/problems/GENE01)
- **Difficulty Rating**: 826
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to determine the eye color of a child given the eye colors of its two parents. The possible eye colors are 'R' (brown), 'G' (green), and 'B' (blue). The problem statement provides a crucial piece of information: 'R' is the most common, 'G' is the rarest, and 'B' is in between. The rule for determining the child's eye color is that it will most likely be the *most common* eye color among the two parents.

## Intuition & Mathematical Observation

The core of the problem lies in understanding the "most common" rule. We can establish a hierarchy of commonality for the eye colors:
**R (brown) > B (blue) > G (green)**

This hierarchy directly translates to how we should decide the child's eye color.

1.  **If both parents have the same eye color:** The child will inherit that same eye color. This is straightforward. For example, if both parents are 'R', the child will be 'R'.

2.  **If the parents have different eye colors:** We need to pick the eye color that is "more common" between the two. Using our hierarchy:
    *   If one parent is 'R' and the other is 'B' or 'G', 'R' is the most common overall and thus the most common between the two parents. The child will be 'R'.
    *   If neither parent is 'R', but one is 'B' and the other is 'G', then 'B' is more common than 'G' according to our hierarchy. The child will be 'B'.
    *   The case where both parents are 'G' is covered by point 1.

We can implement this logic by checking the parent colors.

Let's consider all possible pairs of parent eye colors and apply the rule:

| Parent 1 | Parent 2 | Most Common Between Parents | Child's Eye Color |
| :------- | :------- | :-------------------------- | :---------------- |
| R        | R        | R                           | R                 |
| R        | B        | R (R > B)                   | R                 |
| R        | G        | R (R > G)                   | R                 |
| B        | R        | R (R > B)                   | R                 |
| B        | B        | B                           | B                 |
| B        | G        | B (B > G)                   | B                 |
| G        | R        | R (R > G)                   | R                 |
| G        | B        | B (B > G)                   | B                 |
| G        | G        | G                           | G                 |

The logic in the code directly implements these observations:
*   If `parent1 == parent2`, output `parent1`.
*   Else, if either parent is 'R', output 'R'.
*   Else, if either parent is 'B', output 'B'.
*   The only remaining case is if neither is 'R' and neither is 'B', which implies both must be 'G'. This case is already handled by the first `if` statement (`parent1 == parent2`), but if it were to be reached here, it would correctly imply 'G'.

## Complexity Analysis

-   **Time Complexity**: $O(1)$
    The solution involves a fixed number of comparisons and conditional checks, regardless of the input size (which is always two characters).

-   **Space Complexity**: $O(1)$
    The solution uses a constant amount of extra space to store the parent characters and perform operations.

## Solution Code

```cpp
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

int main() {
    // Optimize C++ standard streams for competitive programming
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    char parent1, parent2;
    // Read the eye colors of the two parents
    std::cin >> parent1 >> parent2;

    // The problem states a hierarchy of commonality:
    // R (brown) is most common, G (green) is rarest, B (blue) is in between.
    // Hierarchy: R > B > G.
    // The child's eye color is determined by the most common color between the two parents.

    // Case 1: Both parents have the same eye color.
    // The child will inherit this color.
    if (parent1 == parent2) {
        std::cout << parent1 << "\n";
    } else {
        // Case 2: Parents have different eye colors.
        // We need to determine which of the two parent colors is more common based on the hierarchy R > B > G.

        // If 'R' is one of the parent colors, it's the most common overall and thus the most common between the two.
        if (parent1 == 'R' || parent2 == 'R') {
            std::cout << 'R' << "\n";
        }
        // If 'R' is not present, and 'B' is one of the parent colors, then 'B' is more common than 'G'.
        // This covers cases like (B, G) or (G, B).
        // Note: (B, B) is already handled by the first if.
        else if (parent1 == 'B' || parent2 == 'B') {
            std::cout << 'B' << "\n";
        }
        // If neither parent is 'R' and neither is 'B', then both parents must be 'G'.
        // This case (G, G) is already handled by the first if statement.
        // However, if we were to reach this point, it would imply both are 'G',
        // and 'G' would be the correct output.
        else {
            // This branch is logically for the case where both parents are 'G'.
            // Since the problem guarantees valid inputs ('R', 'G', 'B'),
            // and the first `if` handles `parent1 == parent2`, this `else` block
            // is technically only reachable if `parent1` and `parent2` are both 'G'.
            // But to be explicit and cover all possibilities if the logic were slightly different:
            // If neither is R and neither is B, they must both be G.
            std::cout << 'G' << "\n";
        }
    }

    return 0;
}
```