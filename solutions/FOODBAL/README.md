# Food Balance (FOODBAL)

- **Difficulty Rating**: 215
- **Solved in**: 1 attempt(s)

## Problem Summary

Chef is presented with two dishes. Each dish has a certain amount of fat and protein. Chef wants to choose the dish that is "more balanced" in terms of fat and protein. A dish is considered more balanced if the absolute difference between its fat and protein content is smaller. If both dishes have the same absolute difference, Chef considers them equally balanced.

The input consists of four integers: $F_1, P_1, F_2, P_2$, representing the fat and protein content of the first and second dishes, respectively. The output should be "First" if the first dish is more balanced, "Second" if the second dish is more balanced, and "Both" if they are equally balanced.

## Intuition & Mathematical Observation

The problem defines "balanced" based on the absolute difference between the fat and protein content of a dish. A smaller absolute difference implies a more balanced dish.

Let $F_1$ and $P_1$ be the fat and protein content of the first dish.
Let $F_2$ and $P_2$ be the fat and protein content of the second dish.

The balance of the first dish can be quantified by $|F_1 - P_1|$.
The balance of the second dish can be quantified by $|F_2 - P_2|$.

Chef's decision logic is as follows:
1. If $|F_1 - P_1| < |F_2 - P_2|$, Chef chooses the "First" dish.
2. If $|F_2 - P_2| < |F_1 - P_1|$, Chef chooses the "Second" dish.
3. If $|F_1 - P_1| = |F_2 - P_2|$, Chef considers "Both" dishes equally balanced.

This directly translates into a simple conditional logic.

## Complexity Analysis

- **Time Complexity**: $O(1)$
    The solution involves a fixed number of arithmetic operations (subtraction, absolute value) and comparisons. These operations take constant time, regardless of the input values.

- **Space Complexity**: $O(1)$
    The solution uses a fixed number of variables to store the input values and intermediate results (differences). The memory usage does not grow with the input size.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes common headers like iostream, cmath, etc.

// Using namespace std; is common in competitive programming to avoid prefixing standard library elements with std::
using namespace std; 

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Declare four integer variables to store the fat and protein quantities for two dishes.
    int F1, P1, F2, P2;

    // Read the four space-separated integers from the standard input.
    // F1, P1 are for the first dish; F2, P2 are for the second dish.
    cin >> F1 >> P1 >> F2 >> P2;

    // Calculate the absolute difference between fat and protein for the first dish.
    // The abs() function (from <cmath> or <cstdlib>) returns the absolute value.
    int diff1 = abs(F1 - P1);

    // Calculate the absolute difference between fat and protein for the second dish.
    int diff2 = abs(F2 - P2);

    // Compare the calculated differences to determine Chef's choice.
    if (diff1 < diff2) {
        // If the first dish has a smaller difference, Chef chooses the first dish.
        cout << "First\n";
    } else if (diff2 < diff1) {
        // If the second dish has a smaller difference, Chef chooses the second dish.
        cout << "Second\n";
    } else { // This condition implies diff1 == diff2
        // If both dishes have the same difference, Chef considers them equivalent.
        cout << "Both\n";
    }

    // Return 0 to indicate successful execution of the program.
    return 0;
}
```