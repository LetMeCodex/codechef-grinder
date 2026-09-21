# Playlist (SONGS)
- **Difficulty Rating**: 489
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef has a playlist consisting of three songs: A, B, and C. Each song has a duration of $X$ minutes. The songs are played in a repeating cycle: A, B, C, A, B, C, and so on. Chef listens to the playlist for a total duration of $N$ minutes. We need to determine how many times Chef listens to song C *completely*.

## Intuition & Mathematical Observation
The songs are played in a fixed sequence: A, B, C. Each song has a duration of $X$ minutes.
Let's trace the completion times of each song:

- Song A (1st instance) completes at time $X$.
- Song B (1st instance) completes at time $X + X = 2X$.
- Song C (1st instance) completes at time $2X + X = 3X$.

After the first cycle (A, B, C), the sequence repeats:

- Song A (2nd instance) completes at time $3X + X = 4X$.
- Song B (2nd instance) completes at time $4X + X = 5X$.
- Song C (2nd instance) completes at time $5X + X = 6X$.

We can observe a pattern here. Song C is completed at times $3X, 6X, 9X, \dots$. In general, the $k$-th instance of song C is completed at time $k \times 3X$.

Chef listens to the playlist for a total duration of $N$ minutes. To listen to song C completely for the $k$-th time, the total journey time $N$ must be at least the time required to complete the $k$-th instance of song C.
Therefore, we need to find the maximum integer $k$ such that:
$k \times 3X \le N$

To find the maximum $k$, we can rearrange the inequality:
$k \le \frac{N}{3X}$

Since $k$ must be an integer (representing the number of times song C is completed), the maximum value of $k$ is the floor of $\frac{N}{3X}$. In integer arithmetic, for positive numbers, the division operator `/` automatically computes the floor.

Thus, the number of times song C is listened to completely is simply $N / (3X)$ using integer division.

Let's verify with the provided examples:
- **Example 1**: $N=6, X=1$.
  $3X = 3 \times 1 = 3$.
  Number of C completions = $6 / 3 = 2$. (Correct)
- **Example 2**: $N=5, X=1$.
  $3X = 3 \times 1 = 3$.
  Number of C completions = $5 / 3 = 1$ (integer division). (Correct)
- **Example 3**: $N=11, X=2$.
  $3X = 3 \times 2 = 6$.
  Number of C completions = $11 / 6 = 1$ (integer division). (Correct)
- **Example 4**: $N=5, X=8$.
  $3X = 3 \times 8 = 24$.
  Number of C completions = $5 / 24 = 0$ (integer division). (Correct)
- **Example 5**: $N=100, X=9$.
  $3X = 3 \times 9 = 27$.
  Number of C completions = $100 / 27 = 3$ (integer division). (Correct)

The logic holds for all examples.

## Complexity Analysis
- **Time Complexity**: $O(1)$
  The solution involves a single arithmetic calculation for each test case. The number of operations does not depend on the input values $N$ or $X$ (beyond their representation in memory).

- **Space Complexity**: $O(1)$
  The solution uses a constant amount of extra space to store variables like `t`, `n`, `x`, and `num_c_completed`. This space requirement does not grow with the input size.

## Solution Code
```cpp
#include <iostream>

int main() {
    // Optimize C++ standard streams for competitive programming.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C stdio.
    // std::cin.tie(NULL) unties cin from cout, so cin operations don't flush cout.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; // Number of test cases
    std::cin >> t;
    while (t--) {
        int n, x; // N: total journey time, X: duration of each song
        std::cin >> n >> x;

        // The playlist plays songs in the order A, B, C, A, B, C, ...
        // Each song has a duration of X minutes.
        // A full cycle (A -> B -> C) takes 3 * X minutes.
        // Song C is completed at the end of each full cycle.
        // The completion times for song C are 3*X, 6*X, 9*X, ..., k * 3 * X.
        //
        // To find how many times song C is completed within N minutes,
        // we need to find the maximum integer k such that k * 3 * X <= N.
        // This is equivalent to k <= N / (3 * X).
        // The maximum integer k is floor(N / (3 * X)).
        // Integer division in C++ for positive numbers automatically computes the floor.
        int num_c_completed = n / (3 * x);

        std::cout << num_c_completed << "\n";
    }
    return 0;
}
```