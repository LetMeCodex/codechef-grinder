# [Calorie Intake (CALINTAKE)](https://www.codechef.com/problems/CALINTAKE)
- **Difficulty Rating**: 247
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to determine how many more calories Chef can consume without exceeding his daily calorie limit. Chef has a daily limit of `X` calories. He has already eaten `Y` sweets, and each sweet contains `Z` calories. We need to output the remaining calories Chef can eat. If Chef has already exceeded his daily limit, we should output `-1`.

## Intuition & Mathematical Observation
The core idea is to first calculate the total calories Chef has already consumed and then compare this amount with his daily limit.

1.  **Calculate Consumed Calories**: Chef has eaten `Y` sweets, and each sweet has `Z` calories. Therefore, the total calories Chef has consumed so far is simply the product `Y * Z`.

2.  **Check Against Limit**:
    *   If the `consumed_calories` (`Y * Z`) are strictly greater than the daily limit `X`, it means Chef has already overeaten. In this scenario, as per the problem statement, we should output `-1`.
    *   If the `consumed_calories` (`Y * Z`) are less than or equal to the daily limit `X`, it means Chef is still within his limit or exactly at it. He can potentially eat more.

3.  **Calculate Remaining Calories**: If Chef is within or at his limit, the number of additional calories he can consume is the difference between his daily limit and the calories he has already consumed: `X - (Y * Z)`.

This problem boils down to a simple arithmetic calculation followed by a conditional check.

## Complexity Analysis
-   **Time Complexity**: $O(1)$
    The program performs a fixed number of operations: reading three integers, one multiplication, one subtraction, one comparison, and one print operation. These operations take constant time, irrespective of the magnitude of the input values (within standard integer limits). Therefore, the time complexity is constant.

-   **Space Complexity**: $O(1)$
    The program uses a fixed number of integer variables (`X`, `Y`, `Z`, `consumed_calories`) to store input and intermediate results. No dynamic data structures or arrays are used that would scale with input size. Thus, the memory usage remains constant, leading to a constant space complexity.

## Solution Code
```cpp
#include <bits/stdc++.h> // Includes iostream and other standard libraries

using namespace std; // Allows using standard library elements without the std:: prefix

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Declare three integer variables to store the input values.
    int X, Y, Z;

    // Read the three integers X, Y, and Z from standard input.
    cin >> X >> Y >> Z;

    // Calculate the total calories Chef has already consumed.
    // This is the product of the number of sweets (Y) and calories per sweet (Z).
    int consumed_calories = Y * Z;

    // Check if the consumed calories exceed the daily limit X.
    if (consumed_calories > X) {
        // If Chef has exceeded the limit, print -1 as required.
        cout << -1 << "\n";
    } else {
        // If Chef has not exceeded the limit, calculate the remaining calories
        // he can eat by subtracting consumed calories from the limit.
        // Then, print this remaining amount.
        cout << X - consumed_calories << "\n";
    }

    // Return 0 to indicate successful execution of the program.
    return 0;
}
```