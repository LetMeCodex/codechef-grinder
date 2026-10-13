# [Passing Grade (PASSINGGR)](https://www.codechef.com/problems/PASSINGGR)
- **Difficulty Rating**: 629
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to find the minimum possible number of students who pass an exam. We are given the scores of `N` students. A crucial condition is that Chef, who is always student number 1 (the first student in the input), *must* pass the exam. We have the freedom to choose any integer cutoff score for the exam.

## Intuition & Mathematical Observation

The core of this problem lies in understanding how to minimize the number of passing students while satisfying the constraint that Chef must pass.

1.  **Minimizing Passing Students:** To minimize the number of students who pass, we should set the *highest possible* cutoff score. A higher cutoff score means fewer students will meet or exceed it.
2.  **Chef Must Pass:** Let Chef's score be `S_chef`. If we choose a cutoff score `C`, then for Chef to pass, `S_chef` must be greater than or equal to `C` (i.e., `S_chef >= C`).
3.  **Combining the two:** To achieve the highest possible cutoff `C` while ensuring `S_chef >= C`, the optimal choice for `C` is `S_chef` itself.
    *   If we set `C = S_chef`, Chef passes.
    *   If we set `C` higher than `S_chef`, Chef would fail, violating the problem's constraint.
    *   If we set `C` lower than `S_chef`, more students (or the same number) would pass, which is not optimal for minimization.

Therefore, the optimal strategy is to set the passing grade equal to Chef's score. Then, we simply count how many students have a score greater than or equal to Chef's score. This count will be the minimum possible number of passing students under the given conditions.

## Complexity Analysis

-   **Time Complexity**: $O(N)$
    -   Reading `N` student scores takes $O(N)$ time. During this process, Chef's score is identified in $O(1)$ time.
    -   After reading all scores, we iterate through the `N` student scores again to count how many students meet or exceed Chef's score. This takes another $O(N)$ time.
    -   Overall, for each test case, the dominant operation is iterating through the `N` scores, resulting in a total time complexity of $O(N)$.
-   **Space Complexity**: $O(N)$
    -   A `std::vector<int> A` is used to store the `N` student scores, which requires $O(N)$ space.
    -   Other variables like `N`, `chef_score`, `passing_students_count`, and loop counters use $O(1)$ space.
    -   Therefore, the total space complexity is $O(N)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries for competitive programming

// Use the standard namespace to avoid writing std:: repeatedly
using namespace std;

// Function to solve a single test case
void solve() {
    int N;
    cin >> N; // Read the number of students

    // Create a vector to store student scores
    vector<int> A(N);
    int chef_score;

    // Read all student scores and identify Chef's score
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        // Chef is student number 1, which corresponds to index 0 in a 0-indexed array
        if (i == 0) {
            chef_score = A[i]; // Store Chef's score
        }
    }

    int passing_students_count = 0;
    // Iterate through all students to count how many pass with the optimal cutoff.
    // The optimal cutoff is Chef's score (chef_score) because it ensures Chef passes
    // and minimizes the number of other students passing (by setting the highest possible cutoff Chef can clear).
    for (int i = 0; i < N; ++i) {
        if (A[i] >= chef_score) {
            passing_students_count++;
        }
    }

    // Output the minimum number of students that pass for this test case
    cout << passing_students_count << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) prevents cin from flushing cout before each input operation,
    // which can speed up I/O in competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) { // Loop through each test case
        solve(); // Call the solve function for the current test case
    }

    return 0; // Indicate successful execution
}
```