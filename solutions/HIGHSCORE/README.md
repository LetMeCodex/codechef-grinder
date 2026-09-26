# [Score High (HIGHSCORE)](https://www.codechef.com/problems/HIGHSCORE)
- **Difficulty Rating**: 672
- **Solved in**: 1 attempt(s)

## Problem Summary

Chef is participating in a contest with $N$ problems. Each problem has one of four possible correct answers: 'A', 'B', 'C', or 'D'. Chef doesn't know the correct answers. We are given the total counts of problems whose correct answer is 'A' ($NA$), 'B' ($NB$), 'C' ($NC$), and 'D' ($ND$). Chef wants to choose a strategy to mark the answers for all $N$ problems such that he can *guarantee* a certain minimum score, regardless of how the correct answers are distributed among the problems. The task is to find the maximum score Chef can guarantee.

## Intuition & Mathematical Observation

The core of this problem lies in understanding what a "guaranteed score" means. A guaranteed score is the minimum score Chef will achieve *in the worst-case scenario*, irrespective of how the correct answers are arranged, given their total counts ($NA, NB, NC, ND$). Chef wants to maximize this worst-case score.

Let's consider Chef's possible strategies:

1.  **Strategy 1: Mark all $N$ problems with option 'A'.**
    If Chef marks every problem with 'A', then he will correctly answer exactly $NA$ problems, because there are $NA$ problems whose correct answer is 'A'. This score of $NA$ is guaranteed, as no matter which specific problems have 'A' as their correct answer, Chef will mark them correctly.

2.  **Strategy 2: Mark all $N$ problems with option 'B'.**
    Similarly, if Chef marks every problem with 'B', he will guarantee $NB$ marks.

3.  **Strategy 3: Mark all $N$ problems with option 'C'.**
    This strategy guarantees $NC$ marks.

4.  **Strategy 4: Mark all $N$ problems with option 'D'.**
    This strategy guarantees $ND$ marks.

Now, Chef wants to maximize his *guaranteed* score. Since each of the above strategies guarantees a specific score ($NA, NB, NC,$ or $ND$), Chef should choose the strategy that yields the highest among these guaranteed scores.

Therefore, the maximum score Chef can guarantee is $\max(NA, NB, NC, ND)$.

Why can't Chef do better with a more complex strategy (e.g., marking some problems 'A' and some 'B')?
If Chef uses a mixed strategy, say marking $X$ problems with 'A' and $Y$ problems with 'B', an "adversary" (the problem setter) could arrange the correct answers in a way that minimizes Chef's score. For example, if Chef marks a problem as 'A', the adversary could make its correct answer 'B' (if $NB$ is high), thus reducing Chef's score. The simple strategy of picking one option and marking *all* problems with it is the most robust way to guarantee a score, as it ensures that all problems of that chosen type will be correctly answered. Any deviation from this strategy opens up possibilities for the adversary to minimize Chef's score below this guaranteed maximum.

## Complexity Analysis

*   **Time Complexity**: For each test case, the program reads 5 integers ($N, NA, NB, NC, ND$) and then performs a single `max` operation on four integers. These are constant-time operations. If there are $T$ test cases, the total time complexity will be $O(T)$.
*   **Space Complexity**: The program uses a few integer variables to store $T, N, NA, NB, NC, ND$, and the result. This is a constant amount of memory, independent of the input size $N$ or the number of test cases $T$. Thus, the space complexity is $O(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes iostream, algorithm, etc.
using namespace std; // Use standard namespace

int main() {
    // Enable fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) {
        int N;
        cin >> N; // Read N (number of problems). N is not directly used in the calculation,
                  // but it's part of the input format.

        int NA, NB, NC, ND;
        cin >> NA >> NB >> NC >> ND; // Read the counts of problems for each option

        // The maximum marks Chef can guarantee is the maximum among NA, NB, NC, and ND.
        // This is because Chef's optimal strategy to guarantee marks is to mark all problems
        // with the single option that has the highest count.
        // For example, if NA is the highest count, Chef marks all N problems as 'A'.
        // Since there are exactly NA problems whose correct answer is 'A', Chef will correctly
        // answer all NA of them, thus guaranteeing NA marks. This score is guaranteed
        // irrespective of which specific problems have 'A' as the answer.
        // Any other strategy (e.g., marking different problems with different options)
        // would allow an adversary to arrange the correct answers in a way that minimizes
        // Chef's score, potentially leading to a lower guaranteed score.
        int max_guaranteed_score = max({NA, NB, NC, ND});

        cout << max_guaranteed_score << "\n"; // Output the result for the current test case
    }

    return 0;
}
```