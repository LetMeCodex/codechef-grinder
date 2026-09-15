# [Maximum Submissions (MAXIMUMSUBS)](https://www.codechef.com/problems/MAXIMUMSUBS)
- **Difficulty Rating**: 435
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to calculate the maximum number of submissions a participant can make in a programming contest. We are given the contest duration in minutes, `X`. The rules for submissions are:
1.  A participant can make 1 submission every 30 seconds.
2.  No submissions are allowed in the last 5 seconds of the contest.

We need to find the maximum possible number of submissions for a given `X`.

## Intuition & Mathematical Observation

To maximize the number of submissions, the participant should make their first submission as early as possible (at time 0 seconds) and subsequent submissions exactly 30 seconds apart. We also need to account for the restriction on submissions in the last 5 seconds.

Let's break down the problem:

1.  **Units Conversion**: The contest duration `X` is given in minutes, but the submission rules are in seconds. So, the first step is to convert the contest duration to seconds:
    `total_seconds = X * 60`

2.  **Effective End Time for Submissions**: The problem states that no submissions are allowed in the last 5 seconds. This means if the contest ends at `total_seconds`, any submission at time `t` must satisfy `t < total_seconds - 5`.
    Let `effective_end_time = total_seconds - 5`.
    A submission is valid if its time `t` is strictly less than `effective_end_time`. In other words, the latest possible second a submission can be made is `effective_end_time - 1`.

3.  **Sequence of Submissions**: The participant makes submissions at times `0, 30, 60, 90, ...`. If `k` is the total number of submissions (1-indexed), the `k`-th submission occurs at time `(k-1) * 30`.

4.  **Combining Constraints**: The time of the `k`-th submission, `(k-1) * 30`, must be strictly less than `effective_end_time`:
    `(k-1) * 30 < effective_end_time`

5.  **Deriving the Formula**: Since all values are integers, the inequality `A < B` is equivalent to `A <= B - 1`.
    So, we can rewrite the inequality as:
    `(k-1) * 30 <= effective_end_time - 1`

    To find the maximum possible `k`, we divide both sides by 30. Since we are dealing with integer division (which truncates towards zero for positive numbers), we get:
    `k-1 <= (effective_end_time - 1) / 30`

    Finally, add 1 to both sides to solve for `k`:
    `k <= (effective_end_time - 1) / 30 + 1`

    Since we want the *maximum* number of submissions, `k` will be exactly `(effective_end_time - 1) / 30 + 1`.

    This formula effectively calculates the number of multiples of 30 (starting from 0) that are strictly less than `effective_end_time`. This is a common pattern for `floor((N-1)/D) + 1` when finding the count of `0, D, 2D, ..., kD` such that `kD < N`.

**Example**:
Let `X = 1` minute.
1.  `total_seconds = 1 * 60 = 60` seconds.
2.  `effective_end_time = 60 - 5 = 55` seconds.
3.  Using the formula:
    `max_submissions = (55 - 1) / 30 + 1`
    `= 54 / 30 + 1`
    `= 1 + 1` (integer division `54 / 30` is `1`)
    `= 2`

    Let's verify manually:
    *   Submission 1: At time 0. (0 < 55, valid)
    *   Submission 2: At time 30. (30 < 55, valid)
    *   Submission 3: At time 60. (60 is not < 55, invalid)
    So, 2 submissions are indeed possible.

## Complexity Analysis

-   **Time Complexity**: $O(1)$
    The `solve()` function performs a fixed number of arithmetic operations (multiplication, subtraction, division, addition) and input/output operations. These are all constant-time operations. The `main()` function calls `solve()` `T` times, so the total time complexity is $O(T)$. Since `T` is the number of test cases and not directly related to the input size of a single test case, for each test case, the complexity is $O(1)$.

-   **Space Complexity**: $O(1)$
    The solution uses a few integer variables (`X`, `total_seconds`, `effective_end_time`, `max_submissions`) to store intermediate results. The amount of memory used does not depend on the input value `X`. Therefore, the space complexity is constant.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes most standard libraries

// Use standard namespace for convenience
using namespace std;

// Function to solve a single test case
void solve() {
    int X; // Duration of the contest in minutes
    cin >> X;

    // Convert contest duration from minutes to seconds
    int total_seconds = X * 60;

    // The participant cannot make any submission in the last 5 seconds.
    // This means submissions must be made at a time 't' such that t < (total_seconds - 5).
    // Let effective_end_time be the first second when submissions are NOT allowed.
    int effective_end_time = total_seconds - 5;

    // A participant can make 1 submission every 30 seconds.
    // To maximize submissions, the participant should make the first submission at time 0,
    // and subsequent submissions exactly 30 seconds apart.
    // The sequence of submission times would be: 0, 30, 60, ..., (k-1)*30.
    // The last submission, at time (k-1)*30, must satisfy:
    // (k-1)*30 < effective_end_time
    //
    // This inequality is equivalent to:
    // (k-1)*30 <= effective_end_time - 1 (since all values are integers)
    //
    // Divide by 30 (using integer division, which truncates towards zero for positive numbers):
    // k-1 <= (effective_end_time - 1) / 30
    //
    // Add 1 to both sides to find the maximum possible value for k:
    // k = (effective_end_time - 1) / 30 + 1
    int max_submissions = (effective_end_time - 1) / 30 + 1;

    // Output the result for the current test case, followed by a newline
    cout << max_submissions << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin from cout and prevents synchronization with C's stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Number of test cases
    cin >> T; // Read the number of test cases

    // Loop through each test case
    while (T--) {
        solve(); // Call the solve function for each test case
    }

    return 0; // Indicate successful execution
}
```