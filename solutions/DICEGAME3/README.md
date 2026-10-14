# [Dice Game 3 (DICEGAME3)](https://www.codechef.com/problems/DICEGAME3)
- **Difficulty Rating**: 889
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem describes a dice game played for $N$ rounds. In each round, a player rolls a standard six-sided die (values 1 to 6). The score for a roll is its face value, with one special rule: if the *previous* roll was a 1, the *current* roll's value is doubled. The goal is to maximize the total score after $N$ rolls.

## Intuition & Mathematical Observation

The core of this problem lies in understanding and exploiting the doubling rule: "If the previous roll was 1, the current roll's value is doubled." To maximize our score, we want to trigger this doubling effect as often as possible, and when it's triggered, we want the doubled roll to be as high as possible.

Let's analyze the contribution of different roll sequences:

1.  **Single Roll**: If $N=1$, we just roll once. To maximize, we roll a 6. Score: 6.
2.  **Two Rolls**: Consider a sequence of two rolls, `[A, B]`.
    *   **Case 1: `A = 1`**: The second roll `B` will be doubled. To maximize `B`, we choose `B=6`.
        *   Score for `A`: 1
        *   Score for `B`: $2 \times 6 = 12$
        *   Total for `[1, 6]`: $1 + 12 = 13$.
    *   **Case 2: `A > 1`**: The second roll `B` will *not* be doubled. To maximize `A` and `B`, we choose `A=6, B=6`.
        *   Score for `A`: 6
        *   Score for `B`: 6
        *   Total for `[6, 6]`: $6 + 6 = 12$.
    *   Comparing these, the `[1, 6]` sequence yields 13 points, which is better than any other two-roll sequence (e.g., `[1, 5]` gives $1 + 2 \times 5 = 11$; `[6, 6]` gives $6+6=12$).

This observation suggests that the `[1, 6]` pair is the most efficient way to gain points over two rolls.

Now, let's consider longer sequences. If we have `[1, 6, 1, 6, ...]`:
*   The first `[1, 6]` pair gives 13 points.
*   For the next `1`, the previous roll was `6` (not `1`), so this `1` is not doubled. It contributes 1 point.
*   For the next `6`, the previous roll was `1`, so this `6` is doubled. It contributes $2 \times 6 = 12$ points.
*   So, each subsequent `[1, 6]` pair also contributes $1 + 12 = 13$ points.

This confirms that the optimal strategy is to form as many `[1, 6]` pairs as possible.

**Algorithm:**

1.  **Calculate full pairs**: Determine how many full `[1, 6]` pairs can be formed. This is `N / 2`.
2.  **Score from pairs**: Each pair contributes 13 points. So, the score from pairs is `(N / 2) * 13`.
3.  **Handle odd `N`**: If $N$ is odd, there will be one roll remaining after forming all possible `[1, 6]` pairs. The sequence would look like `[1, 6, 1, 6, ..., 1, 6, X]`. The last `6` in the final `[1, 6]` pair means the *previous* roll for `X` was `6`. Since `6` is not `1`, this last roll `X` will *not* be doubled. To maximize its contribution, we choose `X=6`.
4.  **Add remaining roll's score**: If $N$ is odd, add 6 to the total score.

**Example:**
*   $N=1$: `num_pairs = 0`. Score = $0 \times 13 = 0$. $N$ is odd, so add 6. Total = 6. (Optimal: `[6]`)
*   $N=2$: `num_pairs = 1`. Score = $1 \times 13 = 13$. $N$ is even. Total = 13. (Optimal: `[1, 6]`)
*   $N=3$: `num_pairs = 1`. Score = $1 \times 13 = 13$. $N$ is odd, so add 6. Total = 19. (Optimal: `[1, 6, 6]`)
*   $N=4$: `num_pairs = 2`. Score = $2 \times 13 = 26$. $N$ is even. Total = 26. (Optimal: `[1, 6, 1, 6]`)

This strategy covers all cases and maximizes the score.

## Complexity Analysis

*   **Time Complexity**: For each test case, the solution involves a few basic arithmetic operations (integer division, multiplication, addition, modulo). These operations take constant time. Therefore, the time complexity per test case is $O(1)$. If there are $T$ test cases, the total time complexity is $O(T)$.

*   **Space Complexity**: The solution uses a few integer variables (`N`, `score`, `num_pairs`) to store intermediate values. The amount of memory used does not depend on the input size $N$. Therefore, the space complexity is $O(1)$.

## Solution Code

```cpp
#include <iostream> // Required for standard input/output operations (cin, cout)

void solve() {
    int N;
    std::cin >> N; // Read the number of rounds for the current test case
    
    long long score = 0; // Initialize score to 0. Using long long for safety,
                         // though for N up to 10^5, max score (649993) fits in int.
    
    // The optimal strategy is to alternate between rolling a 1 and a 6.
    // A sequence like [1, 6] yields a score of:
    // 1 (for the first roll) + 2*6 (for the second roll, since previous was 1) = 1 + 12 = 13.
    // This pair [1, 6] is the most efficient way to get points per two rolls.
    // Any other pair [A, B]:
    // - If A=1, B!=6: [1, B] gives 1 + 2*B. Max B is 5, gives 1+10=11. Less than 13.
    // - If A!=1: [A, B] gives A + B. Max A=6, B=6, gives 6+6=12. Less than 13.
    // So, [1, 6] is indeed the best 2-roll sequence.
    
    // Calculate how many full [1, 6] pairs can be formed.
    int num_pairs = N / 2;
    
    // Each pair contributes 13 to the score.
    score = (long long)num_pairs * 13;
    
    // If N is odd, there's one roll remaining after forming all possible [1, 6] pairs.
    // The sequence would look like [1, 6, 1, 6, ..., 1, 6, X].
    // The last roll X would be preceded by a 6 (the second roll of the last [1, 6] pair).
    // Since the previous roll was 6 (not 1), the last roll X will contribute X to the score, not 2*X.
    // To maximize this, we choose X=6.
    if (N % 2 == 1) {
        score += 6; // Add 6 for the last remaining roll
    }
    
    std::cout << score << "\n"; // Output the maximum possible score
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) prevents std::cout from flushing before std::cin reads input.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int T;
    std::cin >> T; // Read the number of test cases
    while (T--) { // Loop through each test case
        solve(); // Call the solve function for each test case
    }
    
    return 0; // Indicate successful execution
}

```