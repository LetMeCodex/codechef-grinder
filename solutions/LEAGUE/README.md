# [Farmers League (LEAGUE)](https://www.codechef.com/problems/LEAGUE)
- **Difficulty Rating**: 883
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to find the maximum possible difference in points between the first-placed team and the second-placed team in a football league. There are `N` teams in total. Each team plays every other team exactly once. Points are awarded as follows: 3 points for a win, 1 point for a draw, and 0 points for a loss.

## Intuition & Mathematical Observation

To maximize the difference between the first-placed team's points ($P_1$) and the second-placed team's points ($P_2$), we need to achieve two things simultaneously:
1. **Maximize $P_1$**: The highest possible score for any team is achieved by winning all its games.
2. **Minimize $P_2$**: The second-placed team should have the lowest possible score while still being strictly second (or tied for second, but we want the minimum possible *maximum* score for the second position).

Let's analyze these two points:

**1. Maximizing $P_1$ (Points of the first-placed team):**
A team plays $N-1$ games in total. If a team (let's call it Team A) wins all its $N-1$ games, its total points will be $3 \times (N-1)$. This is the maximum possible score any team can achieve. So, we assume the first-placed team (Team A) achieves $P_1 = 3 \times (N-1)$ points.

**2. Minimizing $P_2$ (Points of the second-placed team):**
Since Team A won all its games, it defeated all other $N-1$ teams. This means the second-placed team (Team B) must have lost its game against Team A.
Team B's score will therefore come from its remaining $N-2$ games against the other $N-2$ teams (excluding Team A).
To minimize the score of the second-placed team (Team B), we need to arrange the results of the games among the $N-1$ teams (excluding Team A) such that the highest score among them is as low as possible. This highest score will be $P_2$.

Consider the $N-1$ teams that lost to Team A. Let $K = N-1$. These $K$ teams play a round-robin tournament among themselves. Each of these $K$ teams plays $K-1 = N-2$ games.
We want to find the minimum possible maximum score any team can achieve in this $K$-team sub-tournament. This minimum maximum score will be $P_2$.
A common strategy to minimize the maximum score in a round-robin tournament of $M$ teams (where each plays $M-1$ games) is to arrange results such that the "winner" of this sub-tournament wins $\lceil (M-1)/2 \rceil$ games and loses the rest (no draws are necessary to achieve this minimum maximum, and can sometimes increase scores).
In our case, $M = K = N-1$, so each team plays $M-1 = N-2$ games.
Thus, the second-placed team (Team B) will achieve its minimum possible maximum score by winning $\lceil (N-2)/2 \rceil$ games and losing the remaining games against the other $N-2$ teams. Its score will be $P_2 = 3 \times \lceil (N-2)/2 \rceil$.

Let's analyze $P_2$ based on the parity of $N$:

*   **Case 1: $N$ is even.**
    If $N$ is even, then $N-2$ is also even.
    Let $N-2 = 2m$ for some integer $m$.
    Then $\lceil (N-2)/2 \rceil = \lceil 2m/2 \rceil = m = (N-2)/2$.
    So, $P_2 = 3 \times (N-2)/2$.
    The maximum difference is $P_1 - P_2 = 3(N-1) - 3(N-2)/2$.
    $P_1 - P_2 = \frac{6(N-1) - 3(N-2)}{2} = \frac{6N - 6 - 3N + 6}{2} = \frac{3N}{2}$.

*   **Case 2: $N$ is odd.**
    If $N$ is odd, then $N-2$ is also odd.
    Let $N-2 = 2m+1$ for some integer $m$.
    Then $\lceil (N-2)/2 \rceil = \lceil (2m+1)/2 \rceil = \lceil m + 0.5 \rceil = m+1$.
    We can write $m+1 = (2m+1+1)/2 = (N-2+1)/2 = (N-1)/2$.
    So, $P_2 = 3 \times (N-1)/2$.
    The maximum difference is $P_1 - P_2 = 3(N-1) - 3(N-1)/2$.
    $P_1 - P_2 = \frac{6(N-1) - 3(N-1)}{2} = \frac{3(N-1)}{2}$.

These two cases cover all possible values of $N \ge 2$. The solution code implements exactly this logic.

**Example for N=4 (even):**
$P_1 = 3 \times (4-1) = 9$.
$P_2 = 3 \times (4-2)/2 = 3 \times 1 = 3$.
Difference = $9 - 3 = 6$.
Using formula: $3N/2 = 3 \times 4 / 2 = 6$.

**Example for N=3 (odd):**
$P_1 = 3 \times (3-1) = 6$.
$P_2 = 3 \times (3-1)/2 = 3 \times 1 = 3$.
Difference = $6 - 3 = 3$.
Using formula: $3(N-1)/2 = 3 \times (3-1) / 2 = 3$.

The logic holds for both even and odd $N$.

## Complexity Analysis

*   **Time Complexity**: $O(T)$
    The solution processes `T` test cases. For each test case, it reads an integer `N` and performs a few constant-time arithmetic operations (multiplication, subtraction, division, modulo). These operations do not depend on the magnitude of `N`. Therefore, the total time complexity is directly proportional to the number of test cases, $O(T)$.

*   **Space Complexity**: $O(1)$
    The solution uses a fixed number of variables (`T`, `N`, `result`) regardless of the input size `N`. No data structures that grow with `N` are used. Hence, the space complexity is constant.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes common C++ headers

// Use the standard namespace to avoid prefixing std::
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) prevents std::cout from being flushed before each std::cin operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Variable to store the number of test cases
    cin >> T; // Read the number of test cases

    // Loop through each test case
    while (T--) {
        long long N; // N can be up to 10^9. Calculations involving N might exceed
                     // the capacity of a 32-bit integer, so long long is used.
        cin >> N; // Read the number of teams for the current test case

        long long result; // Variable to store the calculated maximum difference

        // The strategy to maximize the difference is:
        // 1. The winning team (Team A) wins all its games.
        //    Team A plays N-1 games, so P_A = 3 * (N-1) points.
        // 2. The second-placed team (Team B) should have the minimum possible score
        //    while still being the second-highest. This is achieved by distributing
        //    points as evenly as possible among the remaining N-1 teams (excluding Team A).
        //    All N-1 teams lost to Team A. These N-1 teams play a round-robin among themselves.
        //    Let K = N-1. Each of these K teams plays K-1 = N-2 games.
        //    The minimum possible maximum score for a team in a K-team round-robin
        //    is achieved by winning ceil((K-1)/2) games and losing the rest.
        //    So, P_2 = 3 * ceil((N-2)/2).

        if (N % 2 == 0) {
            // Case 1: N is even.
            // N-2 is even. So, ceil((N-2)/2) = (N-2)/2.
            // P_2 = 3 * (N-2)/2.
            // Difference = P_A - P_2 = 3*(N-1) - 3*(N-2)/2
            //            = (6*(N-1) - 3*(N-2)) / 2
            //            = (6N - 6 - 3N + 6) / 2
            //            = 3N / 2
            result = (3 * N) / 2;
        } else {
            // Case 2: N is odd.
            // N-2 is odd. So, ceil((N-2)/2) = (N-2+1)/2 = (N-1)/2.
            // P_2 = 3 * (N-1)/2.
            // Difference = P_A - P_2 = 3*(N-1) - 3*(N-1)/2
            //            = (6*(N-1) - 3*(N-1)) / 2
            //            = 3*(N-1) / 2
            result = (3 * (N - 1)) / 2;
        }
        
        // Output the result for the current test case, followed by a newline.
        cout << result << "\n";
    }

    return 0; // Indicate successful execution
}
```