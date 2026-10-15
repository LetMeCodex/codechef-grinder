# [Sandwiches (SANDWICH7)](https://www.codechef.com/problems/SANDWICH7)
- **Difficulty Rating**: 303
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to calculate the maximum number of sandwiches Chef can make given a certain number of bread pieces, ham pieces, and cheese pieces.

Each sandwich requires:
1.  **2 pieces of bread**
2.  **1 piece of filling** (which can be either ham or cheese)

We are given three integers: `B` (bread pieces), `H` (ham pieces), and `C` (cheese pieces). We need to output the maximum possible number of sandwiches.

## Intuition & Mathematical Observation

To determine the maximum number of sandwiches Chef can make, we need to consider the limitations imposed by each ingredient type: bread and fillings.

1.  **Limitation by Bread**:
    Each sandwich requires 2 pieces of bread. If Chef has `B` pieces of bread, the maximum number of sandwiches he can make based solely on bread availability is `B / 2`. We use integer division here because any single leftover piece of bread cannot form a sandwich. For example, if `B=3`, `3 / 2 = 1` sandwich.

2.  **Limitation by Fillings**:
    Each sandwich requires 1 piece of filling. Chef has `H` pieces of ham and `C` pieces of cheese. Since either ham or cheese can be used as the filling, the total number of available filling pieces is `H + C`. Therefore, the maximum number of sandwiches Chef can make based solely on filling availability is `H + C`.

3.  **Overall Maximum Sandwiches**:
    The total number of sandwiches Chef can make is limited by whichever resource (bread or fillings) runs out first. This means the actual maximum number of sandwiches will be the minimum of the two limits calculated above.

    So, the formula for the maximum number of sandwiches is:
    `max_sandwiches = min(B / 2, H + C)`

This simple formula directly gives the answer.

## Complexity Analysis

-   **Time Complexity**: $O(1)$
    The solution involves reading three integer inputs, performing a few constant-time arithmetic operations (one division, one addition, and one `min` operation), and printing one integer output. All these operations take a fixed amount of time regardless of the input values. Therefore, the time complexity is constant.

-   **Space Complexity**: $O(1)$
    The solution uses a fixed number of integer variables to store the input values (`B`, `H`, `C`) and the intermediate/final result (`max_sandwiches_from_bread`, `max_sandwiches_from_fillings`, `result`). The memory usage does not scale with the input values. Therefore, the space complexity is constant.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes common headers like iostream, algorithm, etc.

// It's common practice in competitive programming to use the entire std namespace.
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin from cout and prevents synchronization with C's stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Declare three integer variables to store the input values:
    // B for bread pieces, H for ham pieces, C for cheese pieces.
    int B, H, C;

    // Read the three integers from standard input.
    cin >> B >> H >> C;

    // Calculate the maximum number of sandwiches that can be made based on the
    // available bread. Each sandwich requires 2 pieces of bread.
    // Integer division (B / 2) correctly handles cases where B is odd,
    // as any leftover single piece of bread cannot form a sandwich.
    int max_sandwiches_from_bread = B / 2;

    // Calculate the maximum number of sandwiches that can be made based on the
    // available fillings (ham or cheese). Each sandwich requires 1 piece of
    // either ham or cheese. The total available fillings are H + C.
    int max_sandwiches_from_fillings = H + C;

    // The total number of sandwiches Chef can make is limited by whichever
    // resource (bread or fillings) runs out first. Therefore, the maximum
    // number of sandwiches is the minimum of the two limits calculated above.
    int result = min(max_sandwiches_from_bread, max_sandwiches_from_fillings);

    // Print the calculated maximum number of sandwiches to standard output,
    // followed by a newline character.
    cout << result << "\n";

    // Return 0 to indicate successful execution.
    return 0;
}
```