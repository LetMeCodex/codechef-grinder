# [Chef and Water Bottles (CHEFBOTTLE)](https://www.codechef.com/problems/CHEFBOTTLE)
- **Difficulty Rating**: 662
- **Solved in**: 1 attempt(s)

## Problem Summary

Chef has `N` empty bottles, each with a capacity of `X` liters. He also has a tank containing `K` liters of water. Chef wants to fill as many bottles as possible completely. The task is to determine the maximum number of bottles Chef can fill.

## Intuition & Mathematical Observation

The problem asks us to find the maximum number of bottles Chef can fill completely. There are two primary constraints that limit this number:

1.  **Amount of Water Available**: Chef has `K` liters of water, and each bottle requires `X` liters to be filled completely. The maximum number of bottles he can fill based solely on the water available is `K / X`. We use integer division here because bottles must be filled *completely*; any remaining water less than `X` cannot fill another bottle.

2.  **Number of Empty Bottles Available**: Chef only possesses `N` empty bottles. Regardless of how much water he has, he cannot fill more than `N` bottles.

To find the actual maximum number of bottles Chef can fill, we must consider both constraints. The final answer will be the minimum of these two limiting factors. If he has enough water for 10 bottles but only 5 bottles, he can only fill 5. If he has 10 bottles but only enough water for 7, he can only fill 7.

Therefore, the maximum number of bottles Chef can fill is `min(N, K / X)`.

## Complexity Analysis

-   **Time Complexity**: $O(T)$
    *   For each test case, the solution performs a constant number of operations: reading three integers (`N`, `X`, `K`), one integer division (`K / X`), one `min` operation, and printing the result. All these operations take constant time, $O(1)$.
    *   Since there are `T` test cases, the total time complexity is $T \times O(1) = O(T)$.

-   **Space Complexity**: $O(1)$
    *   The solution uses a fixed number of integer variables (`T`, `N`, `X`, `K`, `bottles_fillable_by_water`, `max_bottles_filled`) to store input and intermediate results. The memory usage does not depend on the magnitude of the input values (`N`, `X`, `K`) or the number of test cases `T`.
    *   Thus, the space complexity is constant.

## Solution Code

```cpp
#include <iostream> // Required for cin, cout
#include <algorithm> // Required for std::min

// As per problem instructions, using namespace std; is allowed/encouraged.
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin from cout and prevents synchronization with C's stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Variable to store the number of test cases
    cin >> T; // Read the number of test cases

    // Loop through each test case
    while (T--) {
        int N, X, K; // N: number of bottles, X: capacity per bottle, K: total water in tank
        cin >> N >> X >> K; // Read N, X, and K for the current test case

        // Calculate the maximum number of bottles that can be filled completely
        // based on the available water (K) and bottle capacity (X).
        // Integer division (K / X) correctly gives the count of completely filled bottles.
        int bottles_fillable_by_water = K / X;

        // The final answer is limited by two factors:
        // 1. The actual number of empty bottles Chef has (N).
        // 2. The number of bottles that can be filled with the available water (bottles_fillable_by_water).
        // We take the minimum of these two values to find the maximum number of bottles Chef can fill.
        int max_bottles_filled = min(N, bottles_fillable_by_water);

        // Output the result for the current test case, followed by a newline.
        cout << max_bottles_filled << "\n";
    }

    return 0; // Indicate successful program execution
}
```