# [Erase and Maximize (DICEERMAX)](https://www.codechef.com/problems/DICEERMAX)
- **Difficulty Rating**: 1226
- **Solved in**: 3 attempt(s)

## Problem Summary

The problem describes a two-step process involving $N$ dice, aiming to maximize a final score.

1.  **Erase (Step 1):** You roll $N$ dice. Let their initial outcomes be $x_1, x_2, \ldots, x_N$. You then choose some $k$ dice that *initially rolled a '6'* and replace them with new rolls. The remaining $N-k$ dice (those that initially rolled less than '6', or those that initially rolled '6' but were not chosen for replacement) keep their values. After this replacement, the sum of all $N$ dice must be exactly $S$.

2.  **Maximize (Step 2):** Based on the final values of the $N$ dice after Step 1, a score is calculated. For each die:
    *   If its value is '6', it contributes '5' to the score.
    *   If its value is less than '6' (i.e., $1, 2, 3, 4, 5$), it contributes '6' to the score.
    The goal is to maximize this total score.

## Intuition & Mathematical Observation

The core of this problem lies in understanding how to optimize the choices in Step 1 to maximize the score in Step 2. The problem asks for the *maximum possible score*, which implies we can make optimal choices for the initial dice rolls and subsequent re-rolls to satisfy the sum $S$ and then maximize the Step 2 score.

Let's analyze the scoring in **Step 2** first.
Suppose after Step 1, there are $N_6'$ dice with value '6' and $N_{<6}'$ dice with value less than '6'.
The total number of dice is $N$, so $N_6' + N_{<6}' = N$.
The score in Step 2 will be $N_6' \times 5 + N_{<6}' \times 6$.
Substituting $N_{<6}' = N - N_6'$ into the score formula:
Score $= N_6' \times 5 + (N - N_6') \times 6$
Score $= 5N_6' + 6N - 6N_6'$
Score $= 6N - N_6'$

To maximize this score, we need to minimize $N_6'$, the number of dice that end up as '6' after Step 1.

Now, let's consider **Step 1** and the sum $S$.
After Step 1, the sum of the $N$ dice must be exactly $S$. We have $N_6'$ dice with value '6' and $N_{<6}'$ dice with values $y_i \in \{1, \ldots, 5\}$.
The total sum is $S = N_6' \times 6 + \sum_{i=1}^{N_{<6}'} y_i$.
To achieve sum $S$ while minimizing $N_6'$ (our goal for maximizing the final score), we should maximize the contribution from the $N_{<6}'$ dice. The maximum value a die can take if it's less than '6' is '5'.
So, to minimize $N_6'$, we assume all $N_{<6}'$ dice are '5'.
This gives us the inequality: $S \le N_6' \times 6 + N_{<6}' \times 5$.
Substitute $N_{<6}' = N - N_6'$:
$S \le N_6' \times 6 + (N - N_6') \times 5$
$S \le 6N_6' + 5N - 5N_6'$
$S \le N_6' + 5N$

From this, we can find the minimum possible value for $N_6'$:
$N_6' \ge S - 5N$.
Since the number of dice cannot be negative, $N_6' \ge 0$.
Combining these, the minimum number of dice that must be '6' after Step 1 is $N_{6,min}' = \max(0, S - 5N)$.

This $N_{6,min}'$ is the minimum count of '6's required to achieve sum $S$, assuming all other dice are '5's. It's always possible to achieve sum $S$ with this configuration: have $N_{6,min}'$ dice as '6's, and the remaining $N - N_{6,min}'$ dice as '5's (or adjusted to lower values if $S < N_{6,min}' \times 6 + (N - N_{6,min}') \times 5$). The problem's phrasing about choosing $k$ dice that *rolled* a '6' is a bit of a red herring; the optimal strategy allows us to effectively control the initial rolls and re-rolls to reach this minimal $N_{6,min}'$ configuration.

Finally, substitute $N_{6,min}'$ back into the score formula:
Maximum Score $= 6N - N_{6,min}'$
Maximum Score $= 6N - \max(0, S - 5N)$.

This is the formula implemented in the solution code.

## Complexity Analysis

*   **Time Complexity**: The solution performs a fixed number of arithmetic operations (subtraction, multiplication, addition) and one `std::max` call for each test case. These operations take constant time. If there are $T$ test cases, the total time complexity is $O(T)$.
*   **Space Complexity**: The solution uses a few integer variables (`N`, `S`, `k_min`, `max_score`, `T`). This is a constant amount of memory, regardless of the input values $N$ and $S$. Therefore, the space complexity is $O(1)$.

## Solution Code

```cpp
#include <iostream> // Required for std::cin, std::cout, std::endl
#include <algorithm> // Required for std::max

// Function to solve a single test case
void solve() {
    // N and S can be very large according to problem constraints (N up to 10^9, S up to 6*10^9).
    // Using 'int' for N and S will lead to integer overflow on most systems.
    // 'long long' must be used to correctly handle these values.
    long long N, S; 
    // Read N and S for the current test case
    std::cin >> N >> S;

    // k_min represents the minimum number of dice that must be '6'
    // after replacement to achieve the target sum S.
    // To minimize this count (and thus maximize the final score),
    // we assume the (N - k_min) dice that are NOT '6'
    // contribute their maximum possible value, which is '5'.
    // So, the sum S must satisfy:
    // S <= k_min * 6 (from k_min dice that are '6') + (N - k_min) * 5 (from N-k_min dice that are '5')
    // S <= 6*k_min + 5*N - 5*k_min
    // S <= k_min + 5*N
    // This implies k_min >= S - 5*N.
    // Also, k_min cannot be negative, so k_min >= 0.
    // Thus, k_min is the maximum of 0 and (S - 5*N).
    long long k_min = std::max(0LL, S - 5 * N); // Use 0LL for long long literal

    // The score in the second step is maximized by minimizing the number of '6's
    // after Step 1. The formula for the score is 6N - (number of '6's).
    // We found the minimum number of '6's required is k_min.
    // So, the maximum possible score is 6 * N - k_min.
    long long max_score = 6 * N - k_min;

    // Output the maximum score for the current test case
    std::cout << max_score << std::endl;
}

int main() {
    // Optimize C++ standard streams for competitive programming
    // This unties cin from cout and disables synchronization with C stdio,
    // leading to faster input/output operations.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T; // T is usually small enough for 'int'
    // Read the number of test cases
    std::cin >> T;
    // Loop through each test case
    while (T--) {
        solve(); // Call the solve function for each test case
    }

    return 0; // Indicate successful execution
}
```