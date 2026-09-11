# [Off By One (OFFBY1)](https://www.codechef.com/problems/OFFBY1)
- **Difficulty Rating**: 271
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem describes a faulty calculator that takes two numbers, `A` and `B`, as input. Instead of just computing their sum, `A + B`, the calculator performs an additional step: it appends an extra digit `1` to the end of the calculated sum. The task is to determine and output the final result produced by this faulty calculator.

For example, if `A = 3` and `B = 5`:
1. The calculator first computes `A + B = 3 + 5 = 8`.
2. Then, it appends `1` to `8`, resulting in `81`.

## Intuition & Mathematical Observation

The core of this problem lies in understanding how to "append an extra digit 1 at the end of the result" mathematically.

Let's say the sum of `A` and `B` is `S`.
If `S` is a single-digit number, e.g., `S = 8`, appending `1` makes it `81`.
If `S` is a multi-digit number, e.g., `S = 16`, appending `1` makes it `161`.

This operation can be generalized: to append a digit `D` to the end of a number `N`, you effectively multiply `N` by 10 (which shifts all its digits one place to the left, adding a `0` at the end) and then add `D`.

In this specific problem, the digit to be appended is always `1`.
So, if the sum `A + B` is `S`, the final output will be `S * 10 + 1`.

Following this logic:
1. Read the two input integers, `A` and `B`.
2. Calculate their sum: `sum = A + B`.
3. Apply the "append 1" operation: `final_output = sum * 10 + 1`.
4. Print `final_output`.

## Complexity Analysis

-   **Time Complexity**: $O(1)$
    The program performs a fixed number of operations regardless of the magnitude of `A` and `B` (within integer limits). These operations include reading two integers, one addition, one multiplication, one addition, and printing one integer. All these are constant-time operations.

-   **Space Complexity**: $O(1)$
    The program uses a constant amount of memory to store a few integer variables (`A`, `B`, `sum`, `calculator_output`). The memory usage does not scale with the input values.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries

// Use the standard namespace
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin from cout and prevents synchronization with C's stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Declare two integer variables to store the input numbers A and B.
    int A, B;

    // Read the two space-separated integers A and B from standard input.
    cin >> A >> B;

    // Calculate the sum of A and B.
    // According to the problem, the calculator first computes A + B.
    int sum = A + B;

    // The calculator then appends an extra '1' to the end of the result.
    // Mathematically, appending '1' to an integer X is equivalent to X * 10 + 1.
    // For example, if sum is 8, 8 * 10 + 1 = 81.
    // If sum is 16, 16 * 10 + 1 = 161.
    int calculator_output = sum * 10 + 1;

    // Print the final calculated output to standard output, followed by a newline character.
    cout << calculator_output << "\n";

    // Return 0 to indicate successful program execution.
    return 0;
}
```