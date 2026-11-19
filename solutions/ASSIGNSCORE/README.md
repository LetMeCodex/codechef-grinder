# [Assignment Score (ASSIGNSCORE)](https://www.codechef.com/problems/ASSIGNSCORE)
- **Difficulty Rating**: 794
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to calculate the minimum score Chef needs on their last assignment to pass a course. There are a total of $N+1$ assignments. We are given the scores for the first $N$ assignments. Each assignment has a maximum possible score of 100. To pass the course, the Chef's total score across all $N+1$ assignments must be at least 50% of the maximum possible total marks. If it's impossible for Chef to pass, even with a perfect score on the last assignment, we should output -1.

## Intuition & Mathematical Observation

Let's denote the score Chef needs on the last assignment as $X$.
The problem states there are $N+1$ assignments in total.
The maximum score for each assignment is 100.
Therefore, the maximum possible total marks for all $N+1$ assignments is $(N+1) \times 100$.

To pass the course, Chef's total score must be at least 50% of the maximum possible total marks.
So, the required passing score is $0.5 \times (N+1) \times 100 = (N+1) \times 50$.

Let $S$ be the sum of scores Chef obtained in the first $N$ assignments. This sum is calculated by reading the $N$ scores provided in the input.

The total score Chef will achieve is $S + X$.
For Chef to pass, this total score must be greater than or equal to the required passing score:
$S + X \ge (N+1) \times 50$

To find the minimum score $X$ needed, we can rearrange the inequality:
$X \ge (N+1) \times 50 - S$

Let $X_{min\_math} = (N+1) \times 50 - S$. This is the minimum score mathematically required for Chef to pass.

Now, we must consider the practical constraints on $X$:
1.  A score cannot be negative. So, $X$ must be at least 0. If $X_{min\_math}$ is negative (meaning Chef has already scored enough or more than enough with the first $N$ assignments), then Chef needs a minimum of 0 on the last assignment. Thus, the actual minimum score needed is $\max(0, X_{min\_math})$.
2.  The maximum score Chef can get on any assignment is 100. So, $X$ cannot exceed 100.

Combining these, let $X_{final} = \max(0, X_{min\_math})$.
If $X_{final} > 100$, it means even if Chef scores a perfect 100 on the last assignment, they still cannot reach the passing threshold. In this scenario, it's impossible to pass, and we should output -1.
Otherwise, if $X_{final} \le 100$, then $X_{final}$ is the minimum score Chef needs on the last assignment to pass.

**Step-by-step derivation:**
1.  Read $N$.
2.  Calculate `current_sum` by reading $N$ scores.
3.  Calculate `required_total_score = (N + 1) * 50`.
4.  Calculate `min_X_needed_mathematically = required_total_score - current_sum`.
5.  Adjust for non-negative scores: `final_min_X = max(0, min_X_needed_mathematically)`.
6.  Check for impossibility: If `final_min_X > 100`, output -1.
7.  Otherwise, output `final_min_X`.

## Complexity Analysis

*   **Time Complexity**:
    *   Reading $N$: $O(1)$.
    *   Loop to read $N$ scores and calculate `current_sum`: This loop runs $N$ times. In each iteration, we perform a constant number of operations (read an integer, add to sum). So, this part takes $O(N)$ time.
    *   Calculations for `required_total_score`, `min_X_needed_mathematically`, `final_min_X`, and the final comparison/output are all $O(1)$ operations.
    *   Since there are $T$ test cases, and each test case takes $O(N)$ time, the total time complexity will be $O(T \times N)$.
    *   Given $N$ is up to $10^5$ and $T$ is up to $10^3$, $T \times N$ could be $10^3 \times 10^5 = 10^8$, which might be tight but usually passes for simple operations. The constraints on $N$ are $1 \le N \le 10^5$, and $T$ is $1 \le T \le 1000$. The total sum of $N$ over all test cases is $10^5$. This means the total time complexity is actually $O(\sum N)$, which is $O(10^5)$ in total, making it very efficient.

*   **Space Complexity**:
    *   We only store a few integer variables (`N`, `current_sum`, `score`, `required_total_score`, `min_X_needed_mathematically`, `final_min_X`, `T`). These require a constant amount of memory, regardless of the input $N$.
    *   Therefore, the space complexity is $O(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes iostream, algorithm, etc.

// Using namespace std; is requested by the problem statement.
using namespace std;

void solve() {
    int N;
    cin >> N;
    
    int current_sum = 0; // Sum of scores from the first N assignments
    for (int i = 0; i < N; ++i) {
        int score;
        cin >> score;
        current_sum += score;
    }
    
    // Calculate the total score required to pass (50% of maximum possible total marks)
    // Total assignments = N + 1
    // Max marks per assignment = 100
    // Max total marks = (N + 1) * 100
    // Required score to pass = (N + 1) * 100 * 0.5 = (N + 1) * 50
    int required_total_score = (N + 1) * 50;
    
    // Calculate the minimum score X needed on the last assignment mathematically
    // current_sum + X >= required_total_score
    // X >= required_total_score - current_sum
    int min_X_needed_mathematically = required_total_score - current_sum;
    
    // The score X cannot be negative. So, take the maximum of 0 and the mathematically needed score.
    int final_min_X = max(0, min_X_needed_mathematically);
    
    // Check if it's possible to achieve final_min_X.
    // The maximum score Chef can get on the last assignment is 100.
    if (final_min_X > 100) {
        // If even with a perfect 100, Chef cannot reach the passing threshold, it's impossible.
        cout << -1 << "\n";
    } else {
        // Otherwise, Chef needs final_min_X score to pass.
        cout << final_min_X << "\n";
    }
}

int main() {
    // Fast I/O setup as requested
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T; // Number of test cases
    cin >> T;
    while (T--) {
        solve(); // Solve each test case
    }
    
    return 0;
}
```