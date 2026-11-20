# [Judging Delay (JDELAY)](https://www.codechef.com/problems/JDELAY)
- **Difficulty Rating**: 964
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine the number of "late" submissions for a programming contest. We are given `T` test cases. For each test case, we are provided with `N` submissions. For each submission, we know its submission time `S` and the time `J` when its verdict was announced (judging time). A submission is considered "late" if the time taken for judging (i.e., `J - S`) is strictly greater than 5 minutes. Our task is to output the total count of such late submissions for each test case.

## Intuition & Mathematical Observation

The core of this problem lies in a simple conditional check. For each submission, we are given two time points: `S` (submission time) and `J` (judging time). The duration for which the submission was pending judgment is `J - S`. The problem statement defines a "late" submission as one where this duration is strictly greater than 5 minutes.

So, for every submission, we need to perform the following check:
If `(J - S) > 5`, then this submission is late.

Our strategy will be:
1. Read the number of test cases, `T`.
2. Loop `T` times for each test case:
    a. Initialize a counter, say `late_submissions_count`, to 0.
    b. Read the number of submissions for the current test case, `N`.
    c. Loop `N` times to process each submission:
        i. Read the submission time `S` and judging time `J`.
        ii. Check if `J - S > 5`.
        iii. If the condition is true, increment `late_submissions_count`.
    d. After processing all `N` submissions, print the final `late_submissions_count`.

This approach directly translates the problem statement into a straightforward counting mechanism. No complex data structures or algorithms are required.

## Complexity Analysis

-   **Time Complexity**: $O(\sum N)$
    -   There are `T` test cases.
    -   For each test case, we read `N` and then iterate `N` times.
    -   Inside the loop, we perform constant time operations: reading two integers, one subtraction, and one comparison.
    -   Therefore, for a single test case, the time complexity is $O(N)$.
    -   Since we do this for `T` test cases, the total time complexity is the sum of `N` over all test cases, which can be written as $O(\sum N)$. If `N_{max}` is the maximum value of `N` across all test cases, this can also be expressed as $O(T \cdot N_{max})$ in the worst case. Given typical constraints (e.g., $T \le 100$, $N \le 1000$), this would be roughly $100 \times 1000 = 10^5$ operations, which is very efficient and well within typical time limits.

-   **Space Complexity**: $O(1)$
    -   We use a few integer variables (`T`, `N`, `S`, `J`, `late_submissions_count`) to store input and maintain the count.
    -   The amount of memory used by these variables is constant and does not depend on the input size `N`.
    -   Hence, the space complexity is constant.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries

// Use standard namespace to avoid prefixing standard library elements with std::
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams,
    // which can be slow due to synchronization.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation,
    // further speeding up I/O.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare variable for the number of test cases
    cin >> T; // Read the number of test cases from standard input

    // Loop through each test case
    while (T--) {
        int N; // Declare variable for the number of submissions in the current test case
        cin >> N; // Read the number of submissions for the current test case

        int late_submissions_count = 0; // Initialize a counter for submissions judged late

        // Loop N times to read details for each submission
        for (int i = 0; i < N; ++i) {
            int S, J; // Declare variables for submission time (S) and judging time (J)
            cin >> S >> J; // Read submission time and judging time for the current submission

            // Calculate the delay for the current submission.
            // The problem asks to determine how many submissions received their verdicts
            // after a delay of more than 5 minutes.
            // This translates to the condition: (Judging Time - Submission Time) > 5.
            if (J - S > 5) {
                late_submissions_count++; // Increment the counter if the delay meets the condition
            }
        }

        // After processing all submissions for the current test case,
        // print the total count of late submissions.
        // Use "\n" instead of endl for potentially faster output, as endl also flushes the buffer.
        cout << late_submissions_count << "\n";
    }

    return 0; // Indicate successful program execution
}
```