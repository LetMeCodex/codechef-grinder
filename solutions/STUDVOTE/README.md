# [Drumpf for President! (STUDVOTE)](https://www.codechef.com/problems/STUDVOTE)
- **Difficulty Rating**: 1205
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine the size of a student government based on a voting process. There are `N` students, identified by IDs from 1 to `N`. Each student casts exactly one vote for another student (or themselves). A student is eligible to be part of the government if they meet two conditions:

1.  They receive at least `K` votes.
2.  They did *not* vote for themselves.

We need to output the total number of students who satisfy both these conditions. The problem involves multiple test cases.

## Intuition & Mathematical Observation

The core of this problem is to track two distinct pieces of information for each student:
1.  The total number of votes they received.
2.  Whether they voted for themselves.

Once we have this information for all students, we can iterate through them and apply the two eligibility criteria.

Let's break down the approach:

1.  **Data Structures for Tracking:**
    *   To store the vote counts for each student, a `std::vector<int>` named `vote_counts` of size `N+1` (to allow 1-indexed access for student IDs 1 to `N`) is suitable. Initialize all counts to 0.
    *   To track whether a student voted for themselves, a `std::vector<bool>` named `self_voted` of size `N+1` is appropriate. Initialize all entries to `false`.

2.  **Processing Votes (First Pass):**
    *   We need to read `N` votes. For each vote, we know who cast the vote (the `i`-th student, which is `i+1` if `i` is 0-indexed) and who they voted for.
    *   When student `voter_id` votes for `voted_for_id`:
        *   Increment `vote_counts[voted_for_id]`.
        *   If `voter_id == voted_for_id`, then set `self_voted[voter_id] = true`.

3.  **Determining Eligibility (Second Pass):**
    *   After processing all `N` votes, iterate through each student from `student_id = 1` to `N`.
    *   For each `student_id`, check the two conditions:
        *   `vote_counts[student_id] >= K`
        *   `!self_voted[student_id]` (meaning they did *not* vote for themselves)
    *   If both conditions are true, increment a counter for eligible students.

4.  **Output:**
    *   The final value of the counter is the answer for the current test case.

This two-pass approach ensures that all votes are processed before eligibility is checked, and it efficiently gathers the necessary information.

## Complexity Analysis

Let `N` be the number of students and `T` be the number of test cases.

-   **Time Complexity**:
    *   **Initialization**: Creating `vote_counts` and `self_voted` vectors of size `N+1` takes $O(N)$ time.
    *   **First Pass (Processing Votes)**: We iterate `N` times (once for each vote). Inside the loop, operations like reading input, vector access, incrementing, and comparison are all $O(1)$. Thus, this pass takes $O(N)$ time.
    *   **Second Pass (Determining Eligibility)**: We iterate `N` times (once for each student). Inside the loop, vector access and logical comparisons are all $O(1)$. Thus, this pass takes $O(N)$ time.
    *   **Total per test case**: The dominant operations are the two passes, leading to a total time complexity of $O(N) + O(N) + O(N) = O(N)$ for a single test case.
    *   **Overall**: Since there are `T` test cases, the total time complexity will be $O(T \cdot N)$.

-   **Space Complexity**:
    *   `vote_counts` vector: Stores `N+1` integers, so it requires $O(N)$ space.
    *   `self_voted` vector: Stores `N+1` booleans, so it requires $O(N)$ space.
    *   Other variables (N, K, loop counters, `government_size`): These take $O(1)$ space.
    *   **Total**: The total space complexity is dominated by the vectors, resulting in $O(N)$ space.

## Solution Code

```cpp
#include <iostream> // Required for standard input/output operations (cin, cout)
#include <vector>   // Required for std::vector

// It's common in competitive programming to use 'using namespace std;'
// and '#include <bits/stdc++.h>' for convenience.
// For this problem, specific includes are sufficient.

void solve() {
    int N, K;
    std::cin >> N >> K; // Read N (number of students) and K (required votes)

    // vote_counts[j] will store the number of votes student j received.
    // We use N+1 size for 1-indexed student IDs (from 1 to N).
    std::vector<int> vote_counts(N + 1, 0);

    // self_voted[j] will be true if student j voted for themselves.
    // We use N+1 size for 1-indexed student IDs.
    std::vector<bool> self_voted(N + 1, false);

    // Pass 1: Process all N votes
    for (int i = 0; i < N; ++i) {
        int voted_for_student_id;
        std::cin >> voted_for_student_id; // Read who the (i+1)-th student voted for

        int voter_student_id = i + 1; // The current student casting the vote is (i+1)

        // Increment the vote count for the student who received the vote
        vote_counts[voted_for_student_id]++;

        // Check if the student voted for themselves
        if (voter_student_id == voted_for_student_id) {
            self_voted[voter_student_id] = true;
        }
    }

    int government_size = 0; // Counter for eligible students

    // Pass 2: Determine eligible students
    for (int student_id = 1; student_id <= N; ++student_id) {
        // Check if the student received at least K votes AND did not vote for themselves
        if (vote_counts[student_id] >= K && !self_voted[student_id]) {
            government_size++; // This student is eligible
        }
    }

    std::cout << government_size << "\n"; // Output the final size of the student government
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T; // Read the number of test cases
    while (T--) {
        solve(); // Solve each test case
    }

    return 0; // Indicate successful execution
}
```