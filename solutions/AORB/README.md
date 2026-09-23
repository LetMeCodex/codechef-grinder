# [A or B (AORB)](https://www.codechef.com/problems/AORB)
- **Difficulty Rating**: 728
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to calculate the maximum possible score Chef can achieve by solving two problems, A and B.
- Problem A takes `X` minutes to solve. Its score is `500 - (submission_time_A * 2)`.
- Problem B takes `Y` minutes to solve. Its score is `1000 - (submission_time_B * 4)`.

The key detail is that `submission_time` depends on the order in which Chef solves the problems. If Chef solves problem A first, then B, problem A is submitted at `X` minutes, and problem B is submitted at `X + Y` minutes. Similarly, if Chef solves problem B first, then A, problem B is submitted at `Y` minutes, and problem A is submitted at `Y + X` minutes. We need to find the maximum total score.

## Intuition & Mathematical Observation

The problem states that Chef has to solve both problems A and B. Since there are only two problems, there are only two possible orders in which Chef can solve them:
1.  Solve Problem A first, then Problem B.
2.  Solve Problem B first, then Problem A.

We can calculate the total points for each of these two scenarios and then choose the maximum of the two.

Let's derive the formulas for each case:

**Case 1: Chef solves Problem A first, then Problem B.**

*   **Points from Problem A**:
    *   Time taken to solve A: `X` minutes.
    *   Submission time for A: `X` minutes.
    *   Score from A: `500 - (X * 2)`

*   **Points from Problem B**:
    *   Time taken to solve B: `Y` minutes.
    *   Submission time for B: `X + Y` minutes (since A was solved first, taking `X` minutes).
    *   Score from B: `1000 - ((X + Y) * 4)`

*   **Total Points for Case 1**:
    `P_A_first = (500 - 2*X) + (1000 - 4*(X + Y))`
    `P_A_first = 500 - 2*X + 1000 - 4*X - 4*Y`
    `P_A_first = 1500 - 6*X - 4*Y`

**Case 2: Chef solves Problem B first, then Problem A.**

*   **Points from Problem B**:
    *   Time taken to solve B: `Y` minutes.
    *   Submission time for B: `Y` minutes.
    *   Score from B: `1000 - (Y * 4)`

*   **Points from Problem A**:
    *   Time taken to solve A: `X` minutes.
    *   Submission time for A: `Y + X` minutes (since B was solved first, taking `Y` minutes).
    *   Score from A: `500 - ((Y + X) * 2)`

*   **Total Points for Case 2**:
    `P_B_first = (1000 - 4*Y) + (500 - 2*(Y + X))`
    `P_B_first = 1000 - 4*Y + 500 - 2*Y - 2*X`
    `P_B_first = 1500 - 2*X - 6*Y`

Finally, the maximum points Chef can score is `max(P_A_first, P_B_first)`.

## Complexity Analysis

*   **Time Complexity**: $O(1)$ per test case.
    For each test case, the solution performs a fixed number of arithmetic operations (multiplications, additions, subtractions) and one comparison (`std::max`). These operations take constant time, regardless of the input values `X` and `Y`. Since there are `T` test cases, the total time complexity is $O(T)$. Given `T` is up to 1000, this is extremely efficient.

*   **Space Complexity**: $O(1)$ per test case.
    The solution uses a constant amount of memory to store a few integer variables (`X`, `Y`, `score_A_first`, `score_B_first`). This memory usage does not scale with the input values.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes iostream, algorithm, etc.

// Function to solve a single test case
void solve() {
    int X, Y;
    // Read the time required to solve problems A and B
    std::cin >> X >> Y;

    // Calculate points if Chef attempts Problem A first, then Problem B.
    // Problem A is submitted after X minutes. Points: 500 - (X * 2)
    // Problem B is submitted after X + Y minutes. Points: 1000 - ((X + Y) * 4)
    // Total points for this order: (500 - 2*X) + (1000 - 4*(X + Y))
    // Simplified formula: 1500 - 6*X - 4*Y
    int score_A_first = 1500 - 6 * X - 4 * Y;

    // Calculate points if Chef attempts Problem B first, then Problem A.
    // Problem B is submitted after Y minutes. Points: 1000 - (Y * 4)
    // Problem A is submitted after Y + X minutes. Points: 500 - ((Y + X) * 2)
    // Total points for this order: (1000 - 4*Y) + (500 - 2*(Y + X))
    // Simplified formula: 1500 - 2*X - 6*Y
    int score_B_first = 1500 - 2 * X - 6 * Y;

    // The maximum points Chef can score is the maximum of these two possibilities.
    std::cout << std::max(score_A_first, score_B_first) << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T; // Variable to store the number of test cases
    std::cin >> T; // Read the number of test cases
    while (T--) { // Loop through each test case
        solve(); // Call the solve function for the current test case
    }

    return 0; // Indicate successful execution
}
```