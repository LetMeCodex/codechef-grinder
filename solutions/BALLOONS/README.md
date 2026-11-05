# [Coloured Balloons (BALLOONS)](https://www.codechef.com/problems/BALLOONS)
- **Difficulty Rating**: 584
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to calculate the total cost of balloons. We are given `N` different colours of balloons. For each colour `i` (where `i` ranges from 1 to `N`), we are provided with `A_i`, the number of balloons of that specific colour. The cost of a single balloon of colour `i` is `i`. Our task is to find the sum of costs for all balloons across all colours. This needs to be done for `T` test cases.

## Intuition & Mathematical Observation

The problem statement directly provides the rules for calculating the cost:
1.  For any colour `i`, a single balloon of that colour costs `i`.
2.  If there are `A_i` balloons of colour `i`, the total cost for balloons of colour `i` is simply `A_i * i`.

To find the overall total cost for all balloons, we need to sum up the costs for each individual colour. Therefore, the total cost `C` can be expressed as:

$C = (A_1 \times 1) + (A_2 \times 2) + \dots + (A_N \times N)$

This can be written more compactly using summation notation:

$C = \sum_{i=1}^{N} (A_i \times i)$

The solution involves a straightforward iteration:
*   Read the number of test cases, `T`.
*   For each test case:
    *   Initialize a `total_cost` variable to 0.
    *   Read the number of colours, `N`.
    *   Loop from `i = 1` to `N`:
        *   Read `A_i`, the count of balloons for colour `i`.
        *   Add `A_i * i` to `total_cost`.
    *   Print the final `total_cost`.

**Data Type Consideration**:
Given the constraints ($N \le 100$, $A_i \le 100$), the maximum cost for a single colour `i` would be $A_i \times i = 100 \times 100 = 10000$. The maximum total cost would be for $N=100$ colours, each contributing $10000$, leading to $100 \times 10000 = 1,000,000$. An `int` in C++ is typically sufficient to store values up to $2 \times 10^9$, so it would technically suffice. However, using `long long` for `total_cost` is a safer practice in competitive programming to prevent potential integer overflows, especially if constraints were slightly larger or if intermediate calculations could exceed `int` limits. The provided solution correctly uses `long long`.

## Complexity Analysis

*   **Time Complexity**:
    *   The program iterates `T` times for the test cases.
    *   Inside each test case, it reads `N` and then iterates `N` times (from `i=1` to `N`).
    *   Within the inner loop, reading `A_i`, performing multiplication, and addition are all constant time operations, $O(1)$.
    *   Therefore, the total time complexity is $O(T \times N)$.
    *   Given $T \le 100$ and $N \le 100$, the maximum number of operations is approximately $100 \times 100 = 10,000$, which is very efficient and well within typical time limits.

*   **Space Complexity**:
    *   The solution uses a few integer variables (`T`, `N`, `i`, `A_i`) and one `long long` variable (`total_cost`).
    *   These variables occupy a constant amount of memory regardless of the input size `N` or `T`.
    *   No arrays, vectors, or other data structures that scale with input size are used.
    *   Therefore, the space complexity is $O(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries, as requested

// Using the standard namespace, as requested
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare an integer variable T for the number of test cases.
    cin >> T; // Read the number of test cases from standard input.

    // Loop T times, once for each test case.
    while (T--) {
        int N; // Declare an integer variable N for the number of colours.
        cin >> N; // Read the number of colours for the current test case.

        // Declare a long long variable to store the total cost.
        // Using long long is a safe practice to prevent potential integer overflow,
        // even though for the given constraints, int would also suffice.
        long long total_cost = 0;

        // Loop from i = 1 to N.
        // 'i' represents both the colour number and its cost.
        for (int i = 1; i <= N; ++i) {
            int A_i; // Declare an integer variable A_i for the count of balloons of colour i.
            cin >> A_i; // Read the count of balloons of the i-th colour.

            // Calculate the cost for balloons of colour i (A_i * i)
            // and add it to the total_cost.
            // The cast to (long long) before multiplication is not strictly necessary here
            // because A_i * i (max 100*100 = 10000) fits in int,
            // but it's a good habit for larger constraints to prevent intermediate overflow.
            total_cost += (long long)A_i * i; 
        }

        // Output the total cost for the current test case, followed by a newline.
        cout << total_cost << "\n";
    }

    return 0; // Indicate successful program execution.
}
```