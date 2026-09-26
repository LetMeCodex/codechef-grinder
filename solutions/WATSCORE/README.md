# [That Is My Score! (WATSCORE)](https://www.codechef.com/problems/WATSCORE)
- **Difficulty Rating**: 1094
- **Solved in**: 3 attempt(s)

## Problem Summary

The problem asks us to calculate the total score for a participant in a programming contest. We are given `N` submissions, each consisting of a problem number `P` and the score `S` obtained for that submission.

Here are the key rules for scoring:
1.  Problems are numbered from 1 to 11.
2.  Only problems 1 through 8 are "scorable". Submissions for problems 9, 10, and 11 do not contribute to the total score.
3.  For each scorable problem (1 to 8), only the *highest* score achieved across all submissions for that specific problem is considered. If a participant submits multiple times for the same problem, only their best score for that problem counts.
4.  The total score is the sum of the highest scores obtained for each of the scorable problems (1 through 8).

We need to process multiple test cases.

## Intuition & Mathematical Observation

The core idea revolves around two main points: filtering irrelevant problems and keeping track of the maximum score for relevant problems.

1.  **Filtering Problems**: The problem statement explicitly states that only problems 1 through 8 are scorable. This means any submission for problems 9, 10, or 11 can be completely ignored. We only need to process submissions where `P` is between 1 and 8 (inclusive).

2.  **Maximum Score per Problem**: For each scorable problem, we need to find the *highest* score. This suggests using an array or a similar data structure to store the current maximum score for each problem.
    *   We can declare an array, say `max_scores`, of size 9 (to easily use 1-based indexing for problems 1 through 8).
    *   Initialize all elements of `max_scores` to 0. This ensures that if a problem receives no submissions, its contribution to the total score remains 0, and any valid score (which are positive) will correctly update the maximum.
    *   When processing a submission `(p, s)`:
        *   First, check if `p` is in the range `[1, 8]`.
        *   If it is, update `max_scores[p]` by taking the maximum of its current value and the new score `s`: `max_scores[p] = std::max(max_scores[p], s)`.

3.  **Calculating Total Score**: After iterating through all `N` submissions and updating `max_scores` accordingly, the final step is to sum up the values in `max_scores` for indices 1 through 8. This sum will be the participant's total score for the test case.

**Example Walkthrough**:
Suppose submissions are `(1, 50), (2, 60), (1, 70), (9, 100), (3, 40), (2, 55)`.
1.  Initialize `max_scores = [0, 0, 0, 0, 0, 0, 0, 0, 0]` (index 0 unused).
2.  `(1, 50)`: `p=1` is scorable. `max_scores[1] = std::max(0, 50) = 50`.
3.  `(2, 60)`: `p=2` is scorable. `max_scores[2] = std::max(0, 60) = 60`.
4.  `(1, 70)`: `p=1` is scorable. `max_scores[1] = std::max(50, 70) = 70`.
5.  `(9, 100)`: `p=9` is not scorable. Ignore.
6.  `(3, 40)`: `p=3` is scorable. `max_scores[3] = std::max(0, 40) = 40`.
7.  `(2, 55)`: `p=2` is scorable. `max_scores[2] = std::max(60, 55) = 60`.
After all submissions, `max_scores = [0, 70, 60, 40, 0, 0, 0, 0, 0]`.
Total score = `max_scores[1] + max_scores[2] + max_scores[3]` (since others are 0) = `70 + 60 + 40 = 170`.

## Complexity Analysis

Let `N` be the number of submissions for a single test case.

-   **Time Complexity**: $O(N)$
    *   **Initialization**: Creating `max_scores` vector of size 9 and initializing its elements takes constant time, $O(1)$.
    *   **Processing Submissions**: We iterate through `N` submissions. For each submission, we perform a constant number of operations: reading two integers, a conditional check (`if (p >= 1 && p <= 8)`), an array access, and a `std::max` operation. All these are $O(1)$ operations. Therefore, processing all `N` submissions takes $O(N)$ time.
    *   **Calculating Total Score**: We iterate from problem 1 to 8 (a fixed number of iterations, 8). In each iteration, we perform an array lookup and an addition, both $O(1)$. Thus, summing the scores takes $O(1)$ time.
    *   **Total**: The dominant factor is processing `N` submissions, so the overall time complexity for one test case is $O(N)$. If there are `T` test cases, and `N_i` is the number of submissions for the $i$-th test case, the total time complexity would be $O(\sum N_i)$.

-   **Space Complexity**: $O(1)$
    *   **`max_scores` vector**: We use a `std::vector<int>` of fixed size 9 to store the maximum scores for problems 1 through 8. Since the size is constant and does not depend on `N`, this consumes $O(1)$ space.
    *   **Other variables**: Variables like `N`, `p`, `s`, `total_score`, `T`, `i` all consume constant space.
    *   **Total**: The overall space complexity is $O(1)$.

## Solution Code

```cpp
#include <iostream> // Required for input/output operations (std::cin, std::cout)
#include <vector>   // Required for std::vector
#include <algorithm> // Required for std::max

// Function to solve a single test case
void solve() {
    int N; // Number of submissions
    std::cin >> N;

    // Create a vector to store the maximum score for each problem.
    // Problems are 1-indexed (1 to 11). Scorable problems are 1 to 8.
    // We'll use an array of size 9, where index 0 is unused, and indices 1-8
    // store the max scores for problems 1-8 respectively.
    // Initialize all scores to 0.
    std::vector<int> max_scores(9, 0); 

    // Process each submission
    for (int i = 0; i < N; ++i) {
        int p, s; // Problem number and score
        std::cin >> p >> s;

        // Check if the problem is scorable (problems 1 through 8)
        if (p >= 1 && p <= 8) {
            // Update the maximum score for this problem if the current submission's score is higher
            max_scores[p] = std::max(max_scores[p], s);
        }
        // Submissions for problems 9, 10, 11 are ignored as they are non-scorable.
    }

    // Calculate the total score by summing up the best scores for scorable problems
    long long total_score = 0; // Use long long for total_score, though int is sufficient given constraints (max 8*100 = 800)
    for (int i = 1; i <= 8; ++i) { // Iterate through scorable problems (1 to 8)
        total_score += max_scores[i];
    }

    // Print the total score for the current test case
    std::cout << total_score << std::endl;
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common competitive programming optimization.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T; // Number of test cases
    std::cin >> T;
    while (T--) { // Loop T times, decrementing T each time
        solve(); // Call the solve function for each test case
    }

    return 0; // Indicate successful execution
}
```