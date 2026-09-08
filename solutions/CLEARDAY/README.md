# [Clear Day (CLEARDAY)](https://www.codechef.com/problems/CLEARDAY)
- **Difficulty Rating**: 233
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem states that a week consists of exactly 7 days. We are given two integers, $X$ and $Y$, representing the number of rainy days and cloudy days in that week, respectively. The task is to determine and output the number of "clear days" in the week.

## Intuition & Mathematical Observation

This is a very basic arithmetic problem. We know the total number of days in a week is fixed at 7. If we are given the number of days that are rainy ($X$) and the number of days that are cloudy ($Y$), then the remaining days must be clear days.

The fundamental idea is to subtract the non-clear days from the total number of days:
$$ \text{Clear Days} = \text{Total Days in a Week} - \text{Rainy Days} - \text{Cloudy Days} $$

Substituting the given values:
$$ \text{Clear Days} = 7 - X - Y $$

This direct subtraction gives us the required answer.

## Complexity Analysis

-   **Time Complexity**: $O(1)$
    The program performs a fixed number of operations: reading two integers, one subtraction, and printing one integer. These operations take constant time, irrespective of the input values (as they are within standard integer limits). Thus, the time complexity is constant.

-   **Space Complexity**: $O(1)$
    The program uses a few integer variables (`x`, `y`, `clear_days`) to store the input and the result. The memory required for these variables is constant and does not depend on the magnitude of the input values. Hence, the space complexity is constant.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes common headers like iostream

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int x, y; // Declare two integer variables for rainy and cloudy days
    std::cin >> x >> y; // Read the number of rainy days (X) and cloudy days (Y)

    // Calculate the number of clear days.
    // A week has 7 days.
    // Clear days = Total days - Rainy days - Cloudy days
    int clear_days = 7 - x - y;

    // Print the calculated number of clear days, followed by a newline.
    std::cout << clear_days << "\n";

    return 0; // Indicate successful execution
}

```