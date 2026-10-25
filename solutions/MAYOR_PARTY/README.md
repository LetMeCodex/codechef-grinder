# [Peaceful Party (MAYOR_PARTY)](https://www.codechef.com/problems/MAYOR_PARTY)
- **Difficulty Rating**: 898
- **Solved in**: 3 attempt(s)

## Problem Summary

The problem asks us to help a mayor organize a party. There are three regions: A, B, and C, with `PA`, `PB`, and `PC` people respectively. There are specific conflict rules:
1.  If people from region A and region B are invited, a conflict occurs.
2.  If people from region B and region C are invited, a conflict occurs.

The goal is to invite the maximum possible number of people to the party while ensuring no conflicts arise.

## Intuition & Mathematical Observation

Let's analyze the conflict rules:
*   **A & B conflict**: This means we cannot invite people from both A and B simultaneously.
*   **B & C conflict**: This means we cannot invite people from both B and C simultaneously.

Notice that region B is involved in both conflict rules. This suggests that region B is a critical point.

Consider the possible scenarios to avoid conflicts:

1.  **Invite people from region B**:
    If we invite people from region B, then to avoid conflict with A, we cannot invite people from A. Similarly, to avoid conflict with C, we cannot invite people from C.
    Therefore, if we decide to invite people from region B, we can *only* invite people from region B.
    Total people invited in this scenario: `PB`.

2.  **Do NOT invite people from region B**:
    If we decide not to invite anyone from region B, then the conflicts involving B (A & B, B & C) are automatically avoided.
    Since there is no explicit conflict rule between A and C, we can invite people from both region A and region C without any issues.
    Total people invited in this scenario: `PA + PC`.

These are the only two valid strategies that guarantee no conflicts. To maximize the number of invited people, we simply need to choose the better of these two options.

Thus, the maximum number of people we can invite is `max(PB, PA + PC)`.

## Complexity Analysis

*   **Time Complexity**: $O(T)$
    The program reads `T` test cases. For each test case, it performs a constant number of operations: reading three integers, one `std::max` comparison, and printing one integer. Each of these operations takes constant time, $O(1)$. Therefore, the total time complexity is directly proportional to the number of test cases, $O(T)$.

*   **Space Complexity**: $O(1)$
    The program uses a fixed number of variables (`T`, `PA`, `PB`, `PC`, `max_invited`) regardless of the input values (other than `T` itself, which determines the number of iterations, not the memory per iteration). This means the memory usage does not grow with the input size, resulting in constant space complexity.

## Solution Code

```cpp
#include <iostream> // Required for input/output operations (std::cin, std::cout)
#include <algorithm> // Required for std::max

int main() {
    // Optimize C++ standard streams for competitive programming.
    // This unties cin from cout and disables synchronization with C's stdio.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T; // Variable to store the number of test cases
    std::cin >> T; // Read the number of test cases

    // Loop through each test case
    while (T--) {
        int PA, PB, PC; // Declare variables for people in regions A, B, C
        std::cin >> PA >> PB >> PC; // Read the number of people for the current test case

        // The core logic:
        // There are two valid scenarios to avoid conflict:
        // 1. Invite only people from region B. Total people: PB
        // 2. Invite only people from regions A and C. Total people: PA + PC
        // We want to maximize the invited people, so we choose the maximum of these two options.
        int max_invited = std::max(PB, PA + PC);

        std::cout << max_invited << std::endl; // Output the maximum number of invited people
    }

    return 0; // Indicate successful execution
}
```