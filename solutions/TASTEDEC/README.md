# [Tasty Decisions (TASTEDEC)](https://www.codechef.com/problems/TASTEDEC)
- **Difficulty Rating**: 324
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to help Chef decide which packet to eat: a packet of chocolates or a packet of candies.
We are given:
1.  The tastiness value `X` for a single bar of chocolate. The chocolate packet contains 2 such bars.
2.  The tastiness value `Y` for a single piece of candy. The candy packet contains 5 such pieces.

Chef wants to eat the packet with the higher *total* tastiness. If both packets have the same total tastiness, he will eat either. We need to output "Chocolate", "Candy", or "Either" based on this decision.

## Intuition & Mathematical Observation

The core of this problem is to calculate the total tastiness for each packet and then compare these two values.

1.  **Total Tastiness of Chocolate Packet**:
    *   There are 2 chocolate bars.
    *   Each chocolate bar has a tastiness of `X`.
    *   Therefore, the total tastiness of the chocolate packet is `2 * X`.

2.  **Total Tastiness of Candy Packet**:
    *   There are 5 pieces of candy.
    *   Each piece of candy has a tastiness of `Y`.
    *   Therefore, the total tastiness of the candy packet is `5 * Y`.

3.  **Comparison**:
    *   If `(2 * X) > (5 * Y)`, the chocolate packet is tastier.
    *   If `(5 * Y) > (2 * X)`, the candy packet is tastier.
    *   If `(2 * X) == (5 * Y)`, both packets have the same total tastiness.

This involves simple arithmetic operations (multiplication) and conditional comparisons.

## Complexity Analysis

-   **Time Complexity**: $O(1)$ per test case.
    For each test case, we perform two multiplications and a few comparisons. These operations take constant time regardless of the input values `X` and `Y`. If there are `T` test cases, the total time complexity will be $O(T)$.
-   **Space Complexity**: $O(1)$.
    We only use a few integer variables to store `X`, `Y`, and the calculated total tastiness values. The memory usage remains constant irrespective of the input values or the number of test cases.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes common standard libraries like iostream

// Use the standard namespace to avoid writing std::repeatedly
using namespace std;

// Function to solve a single test case
void solve() {
    int X, Y;
    // Read the tastiness of one bar of chocolate (X) and one piece of candy (Y)
    cin >> X >> Y;

    // Calculate the total tastiness for a packet of chocolate
    // One packet contains 2 bars, each with tastiness X.
    int chocolate_tastiness = 2 * X;

    // Calculate the total tastiness for a packet of candy
    // One packet contains 5 pieces, each with tastiness Y.
    int candy_tastiness = 5 * Y;

    // Compare the total tastiness values to decide which packet is better
    if (chocolate_tastiness > candy_tastiness) {
        // If chocolate packet is tastier
        cout << "Chocolate\n";
    } else if (candy_tastiness > chocolate_tastiness) {
        // If candy packet is tastier
        cout << "Candy\n";
    } else {
        // If both packets have the same tastiness
        cout << "Either\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cout from flushing before cin reads input.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    // Read the number of test cases
    cin >> T;
    // Loop through each test case
    while (T--) {
        solve(); // Call the solve function for the current test case
    }

    return 0; // Indicate successful execution
}
```