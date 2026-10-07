# [Find the Direction (FACEDIR)](https://www.codechef.com/problems/FACEDIR)
- **Difficulty Rating**: 880
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine the final direction a person is facing after a given number of seconds, `X`. The person starts by facing North. Every second, they turn 90 degrees clockwise. We need to output the final direction (North, East, South, or West).

## Intuition & Mathematical Observation

Let's trace the direction changes:
*   **0 seconds**: Starts facing **North**.
*   **1 second**: Turns 90 degrees clockwise from North to **East**.
*   **2 seconds**: Turns 90 degrees clockwise from East to **South**.
*   **3 seconds**: Turns 90 degrees clockwise from South to **West**.
*   **4 seconds**: Turns 90 degrees clockwise from West to **North**.
*   **5 seconds**: Turns 90 degrees clockwise from North to **East**.

We can observe a clear cycle of 4 directions: North -> East -> South -> West -> North. After every 4 seconds, the person returns to facing North. This means the final direction depends only on the remainder when the total number of seconds, `X`, is divided by 4.

Let `remainder = X % 4`:
*   If `remainder == 0`: The person completes full cycles and ends up facing **North**. (e.g., 0, 4, 8 seconds)
*   If `remainder == 1`: The person is one step clockwise from North, facing **East**. (e.g., 1, 5, 9 seconds)
*   If `remainder == 2`: The person is two steps clockwise from North, facing **South**. (e.g., 2, 6, 10 seconds)
*   If `remainder == 3`: The person is three steps clockwise from North, facing **West**. (e.g., 3, 7, 11 seconds)

This mathematical observation allows us to solve the problem efficiently using the modulo operator.

## Complexity Analysis

*   **Time Complexity**: For each test case, we perform a single modulo operation (`x % 4`) and a few constant-time comparisons (`if-else`) to print the result. All these operations take constant time, $O(1)$. Since there are `T` test cases, the total time complexity is $O(T \times 1) = O(T)$.
*   **Space Complexity**: We only use a few integer variables (`x`, `remainder`, `t`) to store input and intermediate results. This requires a constant amount of memory, $O(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries as requested

using namespace std; // Uses the standard namespace as requested

void solve() {
    int x;
    cin >> x; // Read the number of seconds, X

    // Calculate the remainder when X is divided by 4.
    // This remainder determines the final direction due to the 4-direction cycle.
    int remainder = x % 4;

    // Based on the remainder, output the corresponding direction.
    if (remainder == 0) {
        cout << "North\n";
    } else if (remainder == 1) {
        cout << "East\n";
    } else if (remainder == 2) {
        cout << "South\n";
    } else { // remainder == 3
        cout << "West\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common competitive programming practice.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t; // Read the number of testcases

    // Loop through each testcase
    while (t--) {
        solve(); // Call the solve function for the current testcase
    }

    return 0; // Indicate successful execution
}
```