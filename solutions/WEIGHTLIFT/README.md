# [Weightlifting (WEIGHTLIFT)](https://www.codechef.com/problems/WEIGHTLIFT)
- **Difficulty Rating**: 270
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem describes a weightlifting competition with three distinct rounds: Squat, Bench Press, and Deadlift. For each round, a participant makes two attempts. The rule states that the best score (maximum weight lifted) from the two attempts in each round is considered for that round's score. The final total score for the participant is the sum of their best scores from all three rounds.

We are given six integer values as input:
- `A1`, `A2`: Scores for the two attempts in the Squat round.
- `B1`, `B2`: Scores for the two attempts in the Bench Press round.
- `C1`, `C2`: Scores for the two attempts in the Deadlift round.

The task is to calculate and print the participant's total score.

## Intuition & Mathematical Observation

The problem statement directly provides the method for calculating the total score. There are no hidden complexities or advanced algorithms required. The core idea is to apply the "best of two attempts" rule for each round and then sum these best scores.

Let's break it down:
1.  **For the Squat round**: The best score will be the maximum of `A1` and `A2`. Mathematically, this is $\max(A1, A2)$.
2.  **For the Bench Press round**: The best score will be the maximum of `B1` and `B2`. Mathematically, this is $\max(B1, B2)$.
3.  **For the Deadlift round**: The best score will be the maximum of `C1` and `C2`. Mathematically, this is $\max(C1, C2)$.

Once we have these three individual best scores, the total score is simply their sum:
Total Score = $\max(A1, A2) + \max(B1, B2) + \max(C1, C2)$.

This approach is a direct translation of the problem description into a simple arithmetic computation.

## Complexity Analysis

*   **Time Complexity**: $O(1)$
    The solution involves reading a fixed number of inputs (6 integers), performing a fixed number of `max` operations (3 times), and a fixed number of additions (2 times), followed by printing a single output. All these operations take constant time, irrespective of the input values (as long as they fit within standard integer types). Therefore, the total time complexity is constant.

*   **Space Complexity**: $O(1)$
    The solution uses a fixed number of variables to store the input scores (`A1`, `A2`, `B1`, `B2`, `C1`, `C2`), the best scores for each round (`round1_score`, `round2_score`, `round3_score`), and the final total score (`total_score`). The amount of memory used does not depend on the magnitude of the input values or any other variable factor. Hence, the space complexity is constant.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes necessary headers like iostream and algorithm

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin from cout and prevents synchronization with C's stdio.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    // Declare variables to store the scores for each attempt in the three rounds.
    int A1, A2, B1, B2, C1, C2;

    // Read the six scores from the standard input.
    std::cin >> A1 >> A2 >> B1 >> B2 >> C1 >> C2;

    // Calculate the best score for Round 1 (Squat) by taking the maximum of A1 and A2.
    int round1_score = std::max(A1, A2);

    // Calculate the best score for Round 2 (Bench Press) by taking the maximum of B1 and B2.
    int round2_score = std::max(B1, B2);

    // Calculate the best score for Round 3 (Deadlift) by taking the maximum of C1 and C2.
    int round3_score = std::max(C1, C2);

    // Calculate the total score by summing the best scores from all three rounds.
    int total_score = round1_score + round2_score + round3_score;

    // Print the calculated total score to the standard output, followed by a newline character.
    std::cout << total_score << "\n";

    return 0; // Indicate successful execution.
}
```