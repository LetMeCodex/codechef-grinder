# [Rain in Chefland (RAINFALL1)](https://www.codechef.com/problems/RAINFALL1)
- **Difficulty Rating**: 328
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to categorize the amount of rainfall in Chefland based on a given integer `x`, which represents the rainfall in millimeters.
- If `x` is less than 3 mm, the rainfall is considered "LIGHT".
- If `x` is greater than or equal to 3 mm and less than 7 mm, the rainfall is considered "MODERATE".
- If `x` is greater than or equal to 7 mm, the rainfall is considered "HEAVY".

We need to read the number of test cases `t`, and for each test case, read the rainfall amount `x` and print the corresponding category.

## Intuition & Mathematical Observation
The problem statement directly provides the conditions for categorizing the rainfall. There isn't a complex mathematical observation required; it's a straightforward application of conditional logic. We just need to translate the given rules into `if-else if-else` statements.

The conditions are:
1. `x < 3`  => "LIGHT"
2. `3 <= x < 7` => "MODERATE"
3. `x >= 7` => "HEAVY"

These three conditions are mutually exclusive and cover all possible non-negative integer values of `x` (rainfall is typically non-negative).

## Complexity Analysis
- **Time Complexity**: $O(1)$
  For each test case, we perform a constant number of comparisons and print operations. Since the number of test cases is `t`, the total time complexity for `t` test cases is $O(t)$. However, if we consider the complexity per test case, it is $O(1)$.

- **Space Complexity**: $O(1)$
  We only use a few variables (`t`, `x`) to store input and intermediate values. The memory usage does not grow with the input size, making the space complexity constant.

## Solution Code
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    // Optimize C++ standard streams for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; // Number of test cases
    cin >> t;

    // Loop through each test case
    while (t--) {
        int x; // Rainfall amount in millimeters
        cin >> x;

        // Apply the conditions to categorize the rainfall
        if (x < 3) {
            // If rainfall is less than 3 mm
            cout << "LIGHT\n";
        } else if (x >= 3 && x < 7) {
            // If rainfall is between 3 mm (inclusive) and 7 mm (exclusive)
            cout << "MODERATE\n";
        } else { // x >= 7
            // If rainfall is 7 mm or more
            cout << "HEAVY\n";
        }
    }

    return 0;
}
```