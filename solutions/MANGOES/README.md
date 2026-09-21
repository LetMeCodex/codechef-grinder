# [The Mango Truck (MANGOES)](https://www.codechef.com/problems/MANGOES)
- **Difficulty Rating**: 482
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine the maximum number of mangoes a truck can carry while crossing a bridge. We are given three integers:
*   `X`: The weight of a single mango.
*   `Y`: The weight of the truck itself.
*   `Z`: The maximum weight capacity of the bridge.

The total weight (truck + mangoes) must not exceed the bridge's capacity `Z`. We need to find the largest integer number of mangoes that can be carried.

## Intuition & Mathematical Observation

The core idea is to figure out how much weight capacity is *left* on the bridge after accounting for the truck's weight.

1.  **Bridge Capacity for Cargo**: The bridge has a total capacity of `Z`. The truck itself weighs `Y`. Therefore, the maximum weight that can be added *on top of the truck* (i.e., for mangoes) is `Z - Y`. Let's call this `remaining_capacity`.
    *   `remaining_capacity = Z - Y`

2.  **Number of Mangoes**: Each mango weighs `X`. To find out how many mangoes can fit into the `remaining_capacity`, we simply divide the `remaining_capacity` by the weight of one mango. Since we can only carry whole mangoes, we take the floor of this division.
    *   `max_mangoes = remaining_capacity / X`

    In C++, for positive integers, integer division `A / B` automatically performs the floor operation, which is exactly what we need here.

Combining these steps, the maximum number of mangoes is `(Z - Y) / X`.

## Complexity Analysis

*   **Time Complexity**: $O(T)$
    The program processes `T` test cases. For each test case, it performs a fixed number of arithmetic operations (two subtractions, one division) and input/output operations. These operations take constant time, $O(1)$. Therefore, the total time complexity is directly proportional to the number of test cases, $O(T)$.

*   **Space Complexity**: $O(1)$
    The solution uses a constant amount of extra space regardless of the input values (other than `T`). It declares a few integer variables (`T`, `X`, `Y`, `Z`, `remaining_capacity`, `max_mangoes`) whose memory usage does not scale with the magnitude of `X`, `Y`, or `Z`.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries, as per problem instructions

// Use the standard namespace to avoid writing std:: repeatedly
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Variable to store the number of test cases
    cin >> T; // Read the number of test cases

    // Loop through each test case
    while (T--) {
        int X, Y, Z; // Variables to store mango weight, truck weight, and bridge capacity
        cin >> X >> Y >> Z; // Read X, Y, and Z for the current test case

        // Calculate the maximum weight capacity available for mangoes.
        // This is the total bridge capacity minus the truck's weight.
        // Since Y <= Z, remaining_capacity will always be non-negative.
        int remaining_capacity = Z - Y;

        // Calculate the maximum number of mangoes.
        // Divide the remaining capacity by the weight of a single mango.
        // Integer division automatically handles the floor operation for non-negative results.
        int max_mangoes = remaining_capacity / X;

        // Output the result for the current test case, followed by a newline.
        cout << max_mangoes << "\n";
    }

    return 0; // Indicate successful program execution
}
```