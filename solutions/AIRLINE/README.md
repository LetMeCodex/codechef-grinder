# Airline Restrictions (AIRLINE)
- **Difficulty Rating**: 1042
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine if it's possible to board a flight given certain weight restrictions. We are given the weights of three items: `A`, `B`, and `C`. We also have two weight limits: `D` for the total weight of check-in baggage and `E` for the weight of carry-on baggage.

The rules are:
1. We must choose *exactly two* items to be check-in baggage.
2. The *remaining* item will be carry-on baggage.
3. The total weight of the two check-in items must not exceed `D`.
4. The weight of the carry-on item must not exceed `E`.

We need to output "YES" if there's at least one combination of items that satisfies these conditions, and "NO" otherwise.

## Intuition & Mathematical Observation

The core of the problem lies in exploring all possible combinations of assigning items to check-in and carry-on baggage and checking if any of these combinations meet the given constraints.

There are three items (`A`, `B`, `C`) and we need to select two for check-in. This naturally leads to three distinct scenarios:

1.  **Items A and B are check-in baggage, Item C is carry-on baggage.**
    *   Condition: `(A + B <= D)` AND `(C <= E)`

2.  **Items A and C are check-in baggage, Item B is carry-on baggage.**
    *   Condition: `(A + C <= D)` AND `(B <= E)`

3.  **Items B and C are check-in baggage, Item A is carry-on baggage.**
    *   Condition: `(B + C <= D)` AND `(A <= E)`

If *any* of these three scenarios hold true, then it's possible to board the flight, and we should output "YES". If *none* of these scenarios are true after checking all of them, then it's impossible, and we should output "NO".

The problem is straightforward and doesn't require complex mathematical insights beyond simple arithmetic and logical comparisons. The key is to systematically check each valid assignment.

## Complexity Analysis

*   **Time Complexity**: $O(1)$
    The solution involves a fixed number of comparisons and arithmetic operations for each test case. Regardless of the input values of `A`, `B`, `C`, `D`, and `E`, the number of checks performed is constant (at most 3 scenarios). Therefore, the time complexity per test case is constant. If there are `t` test cases, the total time complexity is $O(t)$.

*   **Space Complexity**: $O(1)$
    The solution uses a fixed number of variables to store the input values and a boolean flag. The memory usage does not grow with the input size. Therefore, the space complexity is constant.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes common standard libraries like iostream

// Use the standard namespace to avoid prefixing std::
using namespace std;

// Function to solve a single test case
void solve() {
    int A, B, C, D, E;
    // Read the five space-separated integers for the current test case
    cin >> A >> B >> C >> D >> E;

    // A boolean variable to track if any valid combination is found
    bool possible = false;

    // Scenario 1: Check-in bags A and B, carry bag C
    // Check if sum of A and B is within D AND C is within E
    if ((A + B <= D) && (C <= E)) {
        possible = true;
    }
    // Scenario 2: Check-in bags A and C, carry bag B
    // Only check this if a solution hasn't been found yet
    else if ((A + C <= D) && (B <= E)) {
        possible = true;
    }
    // Scenario 3: Check-in bags B and C, carry bag A
    // Only check this if a solution hasn't been found yet
    else if ((B + C <= D) && (A <= E)) {
        possible = true;
    }

    // Output "YES" if any scenario was possible, otherwise "NO"
    if (possible) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    // Read the number of test cases
    cin >> t;
    // Loop through each test case
    while (t--) {
        solve(); // Call the solve function for the current test case
    }

    return 0; // Indicate successful program termination
}
```