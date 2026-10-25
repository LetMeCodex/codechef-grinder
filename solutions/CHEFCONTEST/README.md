# [Chef and Contest (CHEFCONTEST)](https://www.codechef.com/problems/CHEFCONTEST)
- **Difficulty Rating**: 872
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem describes a programming contest where Chef and Chefina participate. Each participant's total score is determined by their time taken to solve the problem plus a penalty for incorrect submissions. Specifically, each wrong submission adds 10 minutes to their total time. We are given:
*   `X`: Time taken by Chef to solve the problem.
*   `Y`: Time taken by Chefina to solve the problem.
*   `P`: Number of wrong submissions by Chef.
*   `Q`: Number of wrong submissions by Chefina.

The task is to determine who wins the contest (the one with the minimum total time), or if it's a draw.

## Intuition & Mathematical Observation

The core idea is to calculate the total penalty for both Chef and Chefina based on the given rules and then compare these calculated total penalties.

1.  **Calculate Chef's Total Penalty**:
    Chef's base time is `X`. For every wrong submission `P`, an additional `10` minutes are added.
    So, Chef's total penalty = `X + (P * 10)`.

2.  **Calculate Chefina's Total Penalty**:
    Chefina's base time is `Y`. For every wrong submission `Q`, an additional `10` minutes are added.
    So, Chefina's total penalty = `Y + (Q * 10)`.

3.  **Compare Penalties**:
    *   If Chef's total penalty is less than Chefina's total penalty, Chef wins.
    *   If Chefina's total penalty is less than Chef's total penalty, Chefina wins.
    *   If both total penalties are equal, it's a draw.

This logic can be directly translated into `if-else if-else` statements in the code.

## Complexity Analysis

*   **Time Complexity**: $O(T)$
    The program processes `T` test cases. For each test case, it performs a fixed number of operations:
    *   Reading four integers (`X`, `Y`, `P`, `Q`).
    *   Two multiplications and two additions to calculate `chef_penalty` and `chefina_penalty`.
    *   Two comparisons and one print operation.
    All these operations take constant time. Therefore, the total time complexity is directly proportional to the number of test cases, `T`.

*   **Space Complexity**: $O(1)$
    The program uses a constant number of variables (`T`, `X`, `Y`, `P`, `Q`, `chef_penalty`, `chefina_penalty`) regardless of the input values or the number of test cases. No data structures that grow with input size are used. Hence, the space complexity is constant.

## Solution Code

```cpp
#include <iostream> // Required for standard input/output operations

// It's common in competitive programming to include <bits/stdc++.h>
// which includes most standard library headers.
// For this problem, <iostream> is sufficient.
// #include <bits/stdc++.h> 

// Using the standard namespace to avoid repeatedly typing std::
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Variable to store the number of test cases
    cin >> T; // Read the number of test cases

    // Loop through each test case
    while (T--) {
        int X, Y, P, Q; // Variables to store Chef's time, Chefina's time, Chef's wrong submissions, Chefina's wrong submissions
        cin >> X >> Y >> P >> Q; // Read the four integers for the current test case

        // Calculate Chef's total penalty
        // Base time penalty is X minutes.
        // Each wrong submission (P) adds 10 minutes penalty.
        int chef_penalty = X + (P * 10);

        // Calculate Chefina's total penalty
        // Base time penalty is Y minutes.
        // Each wrong submission (Q) adds 10 minutes penalty.
        int chefina_penalty = Y + (Q * 10);

        // Compare the penalties to determine the winner or a draw
        if (chef_penalty < chefina_penalty) {
            // If Chef's penalty is less, Chef wins
            cout << "Chef\n";
        } else if (chefina_penalty < chef_penalty) {
            // If Chefina's penalty is less, Chefina wins
            cout << "Chefina\n";
        } else {
            // If both penalties are equal, it's a draw
            cout << "Draw\n";
        }
    }

    return 0; // Indicate successful execution
}
```