# Minimum Pizzas (MINPIZZA)

- **Difficulty Rating**: 546
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to calculate the minimum number of pizzas required to feed a group of friends. We are given the number of friends, `N`, and the number of pizza slices each friend wants, `X`. Each pizza comes with exactly 4 slices.

## Intuition & Mathematical Observation

The core of this problem lies in determining how many total slices are needed and then figuring out how many pizzas are required to provide at least that many slices.

1.  **Total Slices Required**: If there are `N` friends and each friend wants `X` slices, the total number of slices needed is simply the product of `N` and `X`.
    $$ \text{Total Slices} = N \times X $$

2.  **Pizzas Needed**: Each pizza provides 4 slices. To find the minimum number of pizzas, we need to divide the `Total Slices` required by the number of slices per pizza (which is 4). Since we can only buy whole pizzas, if the division results in a fraction, we must round up to the next whole number. This is a classic ceiling division problem.

    For any two positive integers `A` and `B`, the ceiling of `A / B` (i.e., `ceil(A / B)`) can be calculated using integer arithmetic as:
    $$ \text{ceil}(A / B) = (A + B - 1) / B $$

    In our case, `A` is the `Total Slices` required, and `B` is 4 (slices per pizza). So, the minimum number of pizzas is:
    $$ \text{Minimum Pizzas} = \text{ceil}((N \times X) / 4) = (N \times X + 4 - 1) / 4 $$
    This simplifies to:
    $$ \text{Minimum Pizzas} = (N \times X + 3) / 4 $$

The solution involves reading the number of test cases `T`, and then for each test case, reading `N` and `X`, calculating `N * X`, and then applying the ceiling division formula to find the minimum number of pizzas.

## Complexity Analysis

-   **Time Complexity**: $O(1)$
    For each test case, we perform a constant number of arithmetic operations (multiplication, addition, division). Since the number of test cases `T` is read, but the operations per test case are constant, the overall time complexity is $O(1)$ per test case.

-   **Space Complexity**: $O(1)$
    We only use a few integer variables to store the input values (`N`, `X`, `T`) and the result (`minimum_pizzas`). The memory usage does not grow with the input size, making the space complexity constant.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes most standard libraries

// Use the standard namespace to avoid writing std:: repeatedly
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams,
    // which can speed up I/O operations significantly.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation,
    // further improving I/O performance.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare an integer variable T for the number of test cases.
    cin >> T; // Read the number of test cases from standard input.

    // Loop T times, once for each test case.
    while (T--) {
        int N, X; // Declare integer variables N (number of friends) and X (slices each friend wants).
        cin >> N >> X; // Read N and X for the current test case.

        // Calculate the total number of slices required by all friends.
        // N friends * X slices/friend = total_slices_required
        int total_slices_required = N * X;

        // Each pizza consists of 4 slices. We need to find the minimum number of pizzas
        // to satisfy the total slices required. This is a classic ceiling division problem.
        //
        // For positive integers A and B, the ceiling of A/B (ceil(A/B)) can be calculated
        // using integer arithmetic as (A + B - 1) / B.
        // Here, A = total_slices_required and B = 4 (slices per pizza).
        int minimum_pizzas = (total_slices_required + 4 - 1) / 4;
        // This simplifies to (total_slices_required + 3) / 4.

        // Output the calculated minimum number of pizzas to standard output,
        // followed by a newline character as required.
        cout << minimum_pizzas << "\n";
    }

    return 0; // Indicate successful program execution.
}
```