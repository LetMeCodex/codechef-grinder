# [Let Me Eat Cake! (CAKEHALF)](https://www.codechef.com/problems/CAKEHALF)
- **Difficulty Rating**: 753
- **Solved in**: 1 attempt(s)

## Problem Summary

Alice and Bob have a cake, initially with `A` and `B` slices respectively. Charlie wants to eat slices until Alice and Bob have an equal number of slices. The process is as follows:
1. If Alice has more slices (`A > B`), Charlie eats `ceil(A/2)` slices from Alice.
2. If Bob has more slices (`B > A`), Charlie eats `ceil(B/2)` slices from Bob.
3. If `A == B`, the process stops.

We need to find the total number of slices Charlie eats. This process is repeated for `T` test cases.

## Intuition & Mathematical Observation

The core of the problem lies in understanding the `ceil(X/2)` operation and how it affects the number of slices.

Let's analyze `ceil(X/2)`:
- If `X` is an even number, say `X = 2k`, then `ceil(X/2) = k = X/2`. After Charlie eats, `X` becomes `X - k = k = X/2`.
- If `X` is an odd number, say `X = 2k + 1`, then `ceil(X/2) = k + 1 = (X+1)/2`. After Charlie eats, `X` becomes `X - (k+1) = k = (X-1)/2`.

In integer arithmetic, for any positive integer `X`, the expression `(X + 1) / 2` correctly calculates `ceil(X/2)`. For example:
- If `X = 10` (even), `(10 + 1) / 2 = 11 / 2 = 5` (integer division). `ceil(10/2) = 5`.
- If `X = 5` (odd), `(5 + 1) / 2 = 6 / 2 = 3` (integer division). `ceil(5/2) = 3`.

The problem states that Charlie continues eating until `A == B`. In each step, the person with more slices has their slices reduced by approximately half. This means the difference between `A` and `B` will decrease rapidly. Since the number of slices is always positive and strictly decreasing for the larger pile, the process is guaranteed to terminate when `A` becomes equal to `B`.

Given the constraints (`A, B` up to $10^9$), a direct simulation of this process will be efficient enough. Each step roughly halves the larger number of slices, which implies a logarithmic number of steps.

Let's trace an example: `A=10, B=3`
1. `A > B`. Charlie eats `(10 + 1) / 2 = 5` slices from Alice.
   `total_eaten_slices = 5`. `A` becomes `10 - 5 = 5`. Current state: `A=5, B=3`.
2. `A > B`. Charlie eats `(5 + 1) / 2 = 3` slices from Alice.
   `total_eaten_slices = 5 + 3 = 8`. `A` becomes `5 - 3 = 2`. Current state: `A=2, B=3`.
3. `B > A`. Charlie eats `(3 + 1) / 2 = 2` slices from Bob.
   `total_eaten_slices = 8 + 2 = 10`. `B` becomes `3 - 2 = 1`. Current state: `A=2, B=1`.
4. `A > B`. Charlie eats `(2 + 1) / 2 = 1` slice from Alice.
   `total_eaten_slices = 10 + 1 = 11`. `A` becomes `2 - 1 = 1`. Current state: `A=1, B=1`.
5. `A == B`. The process stops. Total slices eaten by Charlie: `11`.

This simulation approach directly matches the problem description and is efficient.

## Complexity Analysis

-   **Time Complexity**:
    In each iteration of the `while` loop, the larger of `A` or `B` is reduced to approximately half its value (specifically, `floor(X/2)` slices remain). The maximum initial value for `A` and `B` is $10^9$. The number of operations required to reduce a number `N` to 1 by repeatedly halving it is $O(\log N)$. Therefore, the `while` loop runs at most $O(\log(\max(A, B)))$ times.
    Given $\max(A, B) \le 10^9$, $\log_2(10^9) \approx 30$. So, the loop executes a very small constant number of times per test case.
    For `T` test cases, the total time complexity is $O(T \cdot \log(\max(A, B)))$.
    With $T \le 10^5$, the total operations would be roughly $10^5 \times 30 \approx 3 \times 10^6$, which is well within typical time limits for competitive programming problems.

-   **Space Complexity**:
    The solution uses a few integer variables (`A`, `B`, `total_eaten_slices`, `slices_to_eat`, `T`) to store input and intermediate results. This amount of memory is constant and does not depend on the input values `A` or `B`.
    Therefore, the space complexity is $O(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries as per problem instructions

// Use the entire std namespace as requested by problem instructions.
using namespace std;

// Function to solve a single test case
void solve() {
    int A, B;
    cin >> A >> B; // Read Alice's and Bob's initial slices

    int total_eaten_slices = 0; // Initialize total slices eaten by Charlie

    // Continue the process as long as Alice and Bob have different numbers of slices
    while (A != B) {
        if (A > B) {
            // Alice has more slices. Charlie eats half of Alice's slices, rounded up.
            // (X + 1) / 2 calculates ceil(X / 2.0) using integer division for positive X.
            int slices_to_eat = (A + 1) / 2;
            total_eaten_slices += slices_to_eat; // Add to total eaten
            A -= slices_to_eat; // Update Alice's slices
        } else { // B > A
            // Bob has more slices. Charlie eats half of Bob's slices, rounded up.
            int slices_to_eat = (B + 1) / 2;
            total_eaten_slices += slices_to_eat; // Add to total eaten
            B -= slices_to_eat; // Update Bob's slices
        }
    }

    // Output the total slices Charlie ate for this test case
    cout << total_eaten_slices << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common competitive programming optimization.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases

    // Loop through each test case
    while (T--) {
        solve(); // Call the solve function for the current test case
    }

    return 0; // Indicate successful execution
}
```