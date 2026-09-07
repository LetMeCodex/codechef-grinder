# [Biryani classes (BIRYANI)](https://www.codechef.com/problems/BIRYANI)
- **Difficulty Rating**: 257
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to calculate the total cost of biryani for a given number of customers and the price per biryani. We are given two integers: `x`, the number of customers, and `y`, the price of one biryani. We need to output the total cost.

## Intuition & Mathematical Observation
The problem is a straightforward multiplication problem. If there are `x` customers and each customer buys one biryani at a price of `y`, the total cost will be the product of the number of customers and the price per biryani.

Mathematically, this can be represented as:
Total Cost = Number of Customers × Price per Biryani
Total Cost = `x` × `y`

The problem statement implies that each customer will buy exactly one biryani. Therefore, we just need to multiply the two given values.

## Complexity Analysis
- **Time Complexity**: $O(1)$
  The solution involves a single multiplication operation for each test case. The number of operations does not depend on the input size (beyond the fixed time to read the input).

- **Space Complexity**: $O(1)$
  The solution uses a constant amount of extra space to store variables like `t`, `x`, and `y`. This space requirement does not grow with the input size.

## Solution Code
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    // Optimize C++ standard streams for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; // Variable to store the number of test cases
    cin >> t; // Read the number of test cases

    // Loop through each test case
    while (t--) {
        long long x, y; // x: number of customers, y: price per biryani
        cin >> x >> y; // Read the input values for the current test case

        // Calculate the total cost by multiplying the number of customers by the price per biryani
        // Use long long for the result to avoid potential integer overflow, as x and y can be large.
        cout << x * y << "\n"; // Print the total cost followed by a newline character
    }

    return 0; // Indicate successful execution
}
```