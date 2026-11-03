# [Failing Grades (FAIL)](https://www.codechef.com/problems/FAIL)
- **Difficulty Rating**: 697
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine if a student maintains their scholarship based on a series of test scores. The scholarship is lost if, at any point after any test, the student's average score across all tests taken *so far* falls below 40. We are given the total number of tests, `N`, and then `N` individual test scores. We need to output "Yes" if the scholarship is maintained throughout all `N` tests, and "No" otherwise.

## Intuition & Mathematical Observation

The core requirement is to check the average score *after each test*. This means we need to keep track of two things as we process the scores:
1.  The cumulative sum of scores obtained so far.
2.  The number of tests taken so far.

Let `S_k` be the sum of scores after `k` tests, and `k` be the number of tests taken. The average score after `k` tests is `S_k / k`. The scholarship is lost if `S_k / k < 40` for any `k` from 1 to `N`.

To avoid potential precision issues with floating-point arithmetic when calculating averages, it's always best to work with integers if possible. We can transform the inequality `S_k / k < 40` into an equivalent integer-only comparison:

Since `k` (the number of tests) is always positive, we can multiply both sides by `k` without changing the direction of the inequality:
`S_k < 40 * k`

This transformation allows us to perform all calculations using integer types, which is safer and generally more efficient in competitive programming.

**Algorithm Steps:**

1.  Initialize a variable `current_sum` to 0 to store the sum of scores. Using `long long` for `current_sum` is a good defensive practice, even if `int` might suffice for the given constraints, to prevent potential overflow in similar problems with larger inputs.
2.  Initialize a boolean flag `scholarship_lost` to `false`. This flag will become `true` if the average condition is ever violated.
3.  Iterate `N` times, representing each test from the first to the `N`-th. Let `i` be the loop counter (0-indexed), so `(i + 1)` represents the number of tests taken so far.
    a.  Read the `score` for the current test.
    b.  **Crucially**: If `scholarship_lost` is already `true`, it means the scholarship has already been lost in a previous step. We don't need to perform any further checks for this test case. However, we *must* continue reading the remaining scores for the current test case to ensure the input stream is correctly positioned for subsequent test cases. Therefore, we only update `current_sum` and check the condition if `scholarship_lost` is `false`.
    c.  Add the current `score` to `current_sum`.
    d.  The number of tests taken so far is `k = (i + 1)`.
    e.  Check the condition: `current_sum < 40LL * (i + 1)`. The `40LL` ensures that the multiplication `40 * (i + 1)` is performed using `long long` arithmetic, which is good practice when dealing with `long long` sums.
    f.  If this condition is true, set `scholarship_lost = true`.
4.  After the loop finishes, check the `scholarship_lost` flag:
    *   If `scholarship_lost` is `true`, print "No".
    *   Otherwise, print "Yes".

This approach correctly checks the condition after *each* test and efficiently stops evaluating the condition once the scholarship is lost, while still consuming all necessary input.

## Complexity Analysis

*   **Time Complexity**:
    *   For each test case, we iterate through `N` test scores. Inside the loop, we perform a constant number of operations (reading input, addition, comparison).
    *   There are `T` test cases.
    *   Therefore, the total time complexity is $O(T \cdot N)$.
    *   Given the constraints ($T \le 100$, $N \le 100$), the maximum number of operations is approximately $100 \times 100 = 10^4$, which is very efficient and well within typical time limits for competitive programming problems.

*   **Space Complexity**:
    *   We use a few variables to store `N`, `current_sum`, `score`, and `scholarship_lost`. These variables require a constant amount of memory regardless of the input size.
    *   Therefore, the space complexity is $O(1)$ per test case.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes most standard libraries like iostream, vector, etc.

// Using namespace std; as requested
using namespace std;

void solve() {
    int N;
    cin >> N; // Read the number of tests

    long long current_sum = 0; // Initialize sum of scores. Using long long as a safe practice.
    bool scholarship_lost = false; // Flag to track if scholarship is lost

    // Iterate through each test
    for (int i = 0; i < N; ++i) {
        int score;
        cin >> score; // Read the score for the current test

        // Only perform checks if the scholarship hasn't been lost yet.
        // We must still read all remaining scores for the current test case
        // to ensure correct input parsing for subsequent test cases.
        if (!scholarship_lost) {
            current_sum += score; // Add current score to the total sum

            // The number of tests taken so far is (i + 1).
            // Check if the average (current_sum / (i + 1)) is less than 40.
            // This is equivalent to current_sum < 40 * (i + 1) to avoid floating-point arithmetic.
            // Using 40LL ensures the multiplication is performed using long long,
            // preventing potential overflow if (i + 1) were very large (though not an issue here).
            if (current_sum < 40LL * (i + 1)) {
                scholarship_lost = true; // Scholarship lost
            }
        }
    }

    // Output the result based on the flag
    if (scholarship_lost) {
        cout << "No\n";
    } else {
        cout << "Yes\n";
    }
}

int main() {
    // Enable fast I/O as requested for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) { // Loop through each test case
        solve(); // Solve the current test case
    }

    return 0;
}
```