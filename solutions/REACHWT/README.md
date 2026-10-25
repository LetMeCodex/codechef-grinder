# [Reach Weight (REACHWT)](https://www.codechef.com/problems/REACHWT)
- **Difficulty Rating**: 530
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to find the minimum cost to achieve a total weight of `N` kilograms. We are given two types of weights:
1.  A 1 kg weight costs 20 rupees.
2.  A 2 kg weight costs 30 rupees.

We need to calculate this minimum cost for `T` independent test cases.

## Intuition & Mathematical Observation

The core idea to minimize the total cost is to use the most cost-effective weights as much as possible. Let's compare the cost per kilogram for each weight type:

*   **1 kg weight**: Costs 20 rupees for 1 kg. So, the cost is 20 rupees/kg.
*   **2 kg weight**: Costs 30 rupees for 2 kg. So, the cost is 30 / 2 = 15 rupees/kg.

Since the 2 kg weight is cheaper per kilogram (15 rupees/kg) compared to the 1 kg weight (20 rupees/kg), our strategy should be to maximize the use of 2 kg weights.

Here's the step-by-step approach:

1.  **Maximize 2 kg weights**: To achieve a total weight of `N` kg, we should use as many 2 kg weights as possible. The maximum number of 2 kg weights we can use without exceeding `N` is `N / 2` (using integer division).
    *   Let `num_2kg = N / 2`.
    *   The total weight covered by these 2 kg weights will be `num_2kg * 2`.

2.  **Handle remaining weight**: After using `num_2kg` two-kilogram weights, there might be some weight remaining that needs to be covered. The remaining weight will be `N - (num_2kg * 2)`. This is equivalent to `N % 2` (the remainder when `N` is divided by 2).
    *   The remaining weight will always be either 0 kg (if `N` is even) or 1 kg (if `N` is odd).
    *   Let `num_1kg = N % 2`.

3.  **Calculate total cost**:
    *   The cost for `num_2kg` weights is `num_2kg * 30`.
    *   The cost for `num_1kg` weights is `num_1kg * 20`.
    *   The total minimum cost is `(num_2kg * 30) + (num_1kg * 20)`.

This strategy guarantees the minimum cost because it prioritizes the more efficient 2 kg weights, only using the less efficient 1 kg weights when absolutely necessary to cover an odd remaining kilogram.

**Example:**
If `N = 5`:
*   `num_2kg = 5 / 2 = 2` (We use two 2 kg weights, covering 4 kg).
*   `num_1kg = 5 % 2 = 1` (We need one 1 kg weight to cover the remaining 1 kg).
*   Total cost = `(2 * 30) + (1 * 20) = 60 + 20 = 80`.

## Complexity Analysis

*   **Time Complexity**: For each test case, the solution performs a constant number of arithmetic operations (division, modulo, multiplication, addition). These operations take $O(1)$ time. Since there are `T` test cases, the total time complexity is $O(T \times 1) = O(T)$.

*   **Space Complexity**: The solution uses a few integer variables (`N`, `num_1kg`, `num_2kg`, `total_cost`, `T`) to store input and intermediate results. The amount of memory used does not depend on the input size `N` or `T`. Therefore, the space complexity is $O(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries

using namespace std; // Adheres to the instruction to use namespace std

void solve() {
    int N;
    cin >> N; // Read N for the current test case

    // Calculate the number of 2 kg weights.
    // We want to maximize the use of 2 kg weights because they are cheaper per kg.
    // N / 2 (integer division) gives the maximum number of 2 kg weights we can use.
    int num_2kg = N / 2;

    // Calculate the number of 1 kg weights.
    // The remaining weight after using num_2kg two-kilogram weights is N - (num_2kg * 2).
    // This is equivalent to N % 2 for positive N.
    int num_1kg = N % 2;

    // Calculate the total cost.
    // Using long long for total_cost to be safe against potential overflow,
    // although for N <= 100, int would suffice (max cost 1500).
    long long total_cost = (long long)num_1kg * 20 + (long long)num_2kg * 30;

    cout << total_cost << "\n"; // Output the minimum total cost
}

int main() {
    // Fast I/O setup as per critical instructions.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) { // Loop through each test case
        solve(); // Call the solve function for each test case
    }

    return 0; // Indicate successful execution
}
```