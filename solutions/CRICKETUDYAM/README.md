# [Cricket Tournament (CRICKETUDYAM)](https://www.codechef.com/problems/CRICKETUDYAM)
- **Difficulty Rating**: 669
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine if a cricket tournament, played in a knockout (single-elimination) format, can be considered "interesting". We are given the total number of teams participating, `N`, and a minimum required number of matches, `M`, for the tournament to be deemed "interesting". A tournament is "interesting" if at least `M` matches are played. We need to output "YES" if it's possible for the tournament to be interesting, and "NO" otherwise.

## Intuition & Mathematical Observation

The core of this problem lies in understanding the fundamental property of a knockout (single-elimination) tournament.

In a knockout tournament:
1.  Each match played results in one team being eliminated and one team advancing.
2.  To determine a single winner from `N` participating teams, exactly `N-1` teams must be eliminated.
3.  Since each match eliminates exactly one team, it follows that a total of `N-1` matches must be played in the entire tournament to crown a single champion. This holds true regardless of the number of rounds or how the teams are initially bracketed.

For example:
*   If `N = 2` teams, 1 match is played (2-1 = 1).
*   If `N = 3` teams, 2 matches are played (3-1 = 2).
*   If `N = 4` teams, 3 matches are played (4-1 = 3).

The problem states that a tournament is "interesting" if at least `M` matches are played. Since we know that exactly `N-1` matches will always be played in a knockout tournament with `N` teams, we simply need to check if this fixed number of matches (`N-1`) meets the minimum requirement `M`.

Therefore, the condition for an "interesting" tournament is:
`N - 1 >= M`

If this condition is true, we print "YES"; otherwise, we print "NO".

## Complexity Analysis

-   **Time Complexity**: $O(T)$
    For each test case, the solution performs a constant number of operations: reading two integers (`N` and `M`), performing a simple subtraction (`N-1`), and a comparison. Since there are `T` test cases, the total time complexity is directly proportional to the number of test cases, making it $O(T)$.

-   **Space Complexity**: $O(1)$
    The solution uses a fixed number of integer variables (`T`, `N`, `M`, `actual_matches_played`) regardless of the input values of `N` or `M`. This means the memory usage does not grow with the input size, resulting in constant space complexity.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes most standard libraries, common in competitive programming.

// Using the standard namespace to avoid prefixing std:: to every standard library element.
using namespace std; 

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin from cout and disables synchronization with C's stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare an integer variable T to store the number of test cases.
    cin >> T; // Read the number of test cases from standard input.

    // Loop T times, once for each test case.
    while (T--) {
        int N, M; // Declare integers N and M for the number of teams and minimum matches.
        cin >> N >> M; // Read N and M for the current test case.

        // In a knockout tournament with N teams, exactly N-1 matches are played
        // to determine a single winner. Each match eliminates one team, and N-1
        // teams must be eliminated to leave one winner.
        int actual_matches_played = N - 1;

        // The tournament is "interesting" if at least M matches are played.
        // Since exactly (N-1) matches are always played, we check if (N-1) is
        // greater than or equal to M.
        if (actual_matches_played >= M) {
            cout << "YES\n"; // If N-1 >= M, it's possible, so print "YES".
        } else {
            cout << "NO\n"; // Otherwise, it's not possible, so print "NO".
        }
    }

    return 0; // Indicate successful program execution.
}
```