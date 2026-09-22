# [Apples and Oranges (APPLORNG)](https://www.codechef.com/problems/APPLORNG)
- **Difficulty Rating**: 355
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to determine if Bob has enough money to purchase 1 kg of apples and 1 kg of oranges. We are given Bob's total money `X`, the cost of 1 kg of apples `A`, and the cost of 1 kg of oranges `B`. We need to output "Yes" if Bob can afford both, and "No" otherwise.

## Intuition & Mathematical Observation
The core idea behind this problem is very straightforward. To buy 1 kg of apples and 1 kg of oranges, Bob needs to spend a combined amount equal to the sum of their individual costs.

1.  **Calculate Total Cost**: The total cost to buy 1 kg of apples and 1 kg of oranges will be `A + B`.
2.  **Compare with Bob's Money**: Bob can afford both if his money `X` is greater than or equal to the `total_cost`. That is, if `X >= (A + B)`.
3.  **Output**: If the condition `X >= (A + B)` is true, print "Yes". Otherwise, print "No".

This is a simple arithmetic calculation followed by a conditional check.

## Complexity Analysis
-   **Time Complexity**: $O(1)$
    *   The program performs a fixed number of operations regardless of the input values:
        *   Reading three integers (`X`, `A`, `B`).
        *   One addition operation (`A + B`).
        *   One comparison operation (`X >= total_cost`).
        *   One print operation.
    *   All these operations take constant time.
-   **Space Complexity**: $O(1)$
    *   The program uses a fixed number of variables (`X`, `A`, `B`, `total_cost_for_both`) to store input and intermediate results. The memory usage does not scale with the magnitude of the input values.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes common headers like iostream

// Use the standard namespace to avoid writing std:: before standard library elements
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Declare variables to store Bob's money (X), cost of apples (A), and cost of oranges (B).
    // According to constraints (1 <= X, A, B <= 10^5), 'int' is sufficient.
    int X, A, B;

    // Read Bob's money from the first line of input.
    cin >> X;

    // Read the costs of apples and oranges from the second line of input.
    cin >> A >> B;

    // Calculate the total cost required to buy 1 kg of apples and 1 kg of oranges.
    int total_cost_for_both = A + B;

    // Check if Bob has enough money (X) to cover the total cost.
    if (X >= total_cost_for_both) {
        // If Bob has enough money, print "Yes".
        cout << "Yes\n";
    } else {
        // Otherwise, Bob does not have enough money, print "No".
        cout << "No\n";
    }

    // Return 0 to indicate successful execution of the program.
    return 0;
}
```