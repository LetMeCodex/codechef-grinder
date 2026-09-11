# [Donation Drive (DONDRIVE)](https://www.codechef.com/problems/DONDRIVE)
- **Difficulty Rating**: 272
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine the number of additional donations required to reach a specific target. For each test case, we are given two integers: `N`, which represents the total target number of donations, and `X`, which represents the number of donations already collected. Our task is to calculate and output how many more donations are needed to reach `N`. This process needs to be repeated for `T` independent test cases.

## Intuition & Mathematical Observation

The problem is a straightforward application of basic arithmetic. If a total of `N` donations are required, and `X` donations have already been successfully collected, then the number of donations still pending or remaining to be collected is simply the difference between the target and the collected amount.

Mathematically, this can be expressed as:
`Remaining Donations = Target Donations - Collected Donations`
`Remaining Donations = N - X`

For example, if the target `N` is 10 donations and `X` donations have already been collected, say 3, then `10 - 3 = 7` more donations are needed.

## Complexity Analysis

*   **Time Complexity**: $O(T)$
    *   The program first reads the number of test cases, `T`.
    *   Inside the `while (T--)` loop, for each test case, it performs a constant number of operations: reading two integers (`N` and `X`), performing one subtraction, and printing one integer. Each of these operations takes constant time, $O(1)$.
    *   Since these constant-time operations are executed `T` times, the total time complexity is directly proportional to `T`, making it $O(T)$.

*   **Space Complexity**: $O(1)$
    *   The program uses a fixed number of integer variables (`T`, `N`, `X`, `remaining_donations`) to store input and intermediate results. The memory consumed by these variables does not depend on the input values `N` or `X`, nor does it scale with the number of test cases `T` (as variables are reused for each test case).
    *   Therefore, the space complexity is constant, $O(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries

using namespace std; // Uses the standard namespace

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams,
    // which can speed up I/O operations.
    // cin.tie(NULL) prevents cout from flushing before cin reads input,
    // further optimizing I/O when mixing cin and cout.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare an integer variable T to store the number of test cases.
    cin >> T; // Read the number of test cases from standard input.

    // Loop T times, processing one test case in each iteration.
    while (T--) {
        int N, X; // Declare integer variables N and X for the target and collected donations.
        cin >> N >> X; // Read the target number of donations (N) and the collected donations (X)
                        // for the current test case.

        // Calculate the remaining number of donations needed.
        // The target is N donations, and X donations have already been collected.
        // The difference (N - X) gives the number of donations still required.
        int remaining_donations = N - X;

        // Print the calculated remaining donations to standard output,
        // followed by a newline character to ensure each result is on a new line.
        cout << remaining_donations << "\n";
    }

    return 0; // Indicate successful program execution.
}
```