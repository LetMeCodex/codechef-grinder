# [Water Mixing (WTRMIXING)](https://www.codechef.com/problems/WTRMIXING)
- **Difficulty Rating**: 694
- **Solved in**: 1 attempt(s)

## Problem Summary

Chef has a container of water at an initial temperature `A`. He wants to adjust its temperature to a target temperature `B`. To do this, he has two resources:
1.  `X` litres of hot water: Each litre of hot water increases the current temperature by 1 degree.
2.  `Y` litres of cold water: Each litre of cold water decreases the current temperature by 1 degree.

The task is to determine if Chef can achieve the target temperature `B` using the available hot and cold water.

## Intuition & Mathematical Observation

The problem boils down to comparing the current temperature `A` with the target temperature `B` and then checking if Chef has enough resources to bridge the difference. There are three distinct scenarios:

1.  **Current temperature `A` is already equal to the target temperature `B` (`A == B`)**:
    If the water is already at the desired temperature, Chef doesn't need to do anything. Thus, it's possible to achieve the target. The answer is "YES".

2.  **Target temperature `B` is higher than the current temperature `A` (`B > A`)**:
    Chef needs to *increase* the temperature. The required increase is `B - A` degrees. Since each litre of hot water increases the temperature by 1 degree, Chef needs `B - A` litres of hot water. He has `X` litres of hot water available.
    If the required hot water (`B - A`) is less than or equal to the available hot water (`X`), then it's possible. The answer is "YES".
    Otherwise, he doesn't have enough hot water, and it's not possible. The answer is "NO".

3.  **Target temperature `B` is lower than the current temperature `A` (`B < A`)**:
    Chef needs to *decrease* the temperature. The required decrease is `A - B` degrees. Since each litre of cold water decreases the temperature by 1 degree, Chef needs `A - B` litres of cold water. He has `Y` litres of cold water available.
    If the required cold water (`A - B`) is less than or equal to the available cold water (`Y`), then it's possible. The answer is "YES".
    Otherwise, he doesn't have enough cold water, and it's not possible. The answer is "NO".

These three cases cover all possibilities, and the solution directly implements this logic using `if-else if-else` statements.

## Complexity Analysis

*   **Time Complexity**: $O(1)$ per test case.
    For each test case, the solution performs a fixed number of operations: reading four integers, a few comparisons, and at most one subtraction. These operations take constant time, irrespective of the input values (within their given constraints). Since there are `T` test cases, the total time complexity is $O(T)$.

*   **Space Complexity**: $O(1)$.
    The solution uses a constant amount of memory to store a few integer variables (`A`, `B`, `X`, `Y`, `hot_water_needed`, `cold_water_needed`, `T`). The memory usage does not grow with the input values or the number of test cases.

## Solution Code

```cpp
#include <bits/stdc++.h> 
using namespace std;

void solve() {
    int A, B, X, Y;
    cin >> A >> B >> X >> Y;

    if (A == B) {
        // If the initial temperature is already the desired temperature,
        // Chef doesn't need to add any water.
        cout << "YES\n";
    } else if (B > A) {
        // If the desired temperature is higher than the initial temperature,
        // Chef needs to increase the temperature by adding hot water.
        // The required temperature increase is B - A degrees.
        // Each litre of hot water increases temperature by 1 degree.
        int hot_water_needed = B - A;
        
        // Check if Chef has enough hot water.
        if (hot_water_needed <= X) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    } else { // B < A
        // If the desired temperature is lower than the initial temperature,
        // Chef needs to decrease the temperature by adding cold water.
        // The required temperature decrease is A - B degrees.
        // Each litre of cold water decreases temperature by 1 degree.
        int cold_water_needed = A - B;
        
        // Check if Chef has enough cold water.
        if (cold_water_needed <= Y) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}

int main() {
    // Optimize C++ standard streams for competitive programming.
    // This unties cin/cout from the C standard I/O library and
    // prevents flushing cout before cin, speeding up I/O operations.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) {
        solve(); // Solve each test case
    }

    return 0;
}
```