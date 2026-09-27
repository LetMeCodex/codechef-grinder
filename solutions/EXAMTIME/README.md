# [TCS Examination (EXAMTIME)](https://www.codechef.com/problems/EXAMTIME)
- **Difficulty Rating**: 1006
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine the winner between two students, Dragon and Sloth, based on their scores in three subjects: Data Structures and Algorithms (DSA), Theory of Computation (TOC), and Discrete Mathematics (DM). The ranking is determined by a hierarchical set of rules:

1.  **Primary Rule**: The student with the higher **total score** across all three subjects gets a better rank.
2.  **First Tie-breaker**: If the total scores are tied, the student with the higher **DSA score** gets a better rank.
3.  **Second Tie-breaker**: If both total scores and DSA scores are tied, the student with the higher **TOC score** gets a better rank.
4.  **Final Outcome**: If all three criteria (total score, DSA score, and TOC score) are tied, then the result is an overall "TIE".

We need to output "DRAGON", "SLOTH", or "TIE" for each test case based on these rules.

## Intuition & Mathematical Observation

The problem statement explicitly lays out a clear, step-by-step hierarchical comparison process. Our intuition should be to directly translate these rules into conditional logic in our code.

1.  **Calculate Totals**: The first step is to calculate the sum of scores for Dragon ($D_{total} = D_{dsa} + D_{toc} + D_{dm}$) and Sloth ($S_{total} = S_{dsa} + S_{toc} + S_{dm}$).
2.  **Compare Totals**: We first compare $D_{total}$ and $S_{total}$.
    *   If $D_{total} > S_{total}$, Dragon wins.
    *   If $S_{total} > D_{total}$, Sloth wins.
    *   If $D_{total} = S_{total}$, we move to the first tie-breaker.
3.  **Compare DSA Scores (Tie-breaker 1)**: If total scores are equal, we compare $D_{dsa}$ and $S_{dsa}$.
    *   If $D_{dsa} > S_{dsa}$, Dragon wins.
    *   If $S_{dsa} > D_{dsa}$, Sloth wins.
    *   If $D_{dsa} = S_{dsa}$, we move to the second tie-breaker.
4.  **Compare TOC Scores (Tie-breaker 2)**: If total scores and DSA scores are both equal, we compare $D_{toc}$ and $S_{toc}$.
    *   If $D_{toc} > S_{toc}$, Dragon wins.
    *   If $S_{toc} > D_{toc}$, Sloth wins.
    *   If $D_{toc} = S_{toc}$, all criteria are tied, resulting in an overall TIE.

This approach directly implements the problem's logic using nested `if-else if-else` statements, ensuring that the rules are applied in the specified order of precedence. No complex algorithms or data structures are required beyond basic arithmetic and comparisons.

## Complexity Analysis

*   **Time Complexity**: For each test case, the solution performs a fixed number of operations:
    *   Reading 6 integer inputs.
    *   Performing 2 integer additions to calculate total scores.
    *   A series of at most 5 comparisons (e.g., `D_total > S_total`, `S_total > D_total`, `D_dsa > S_dsa`, `S_dsa > D_dsa`, `D_toc > S_toc`, `S_toc > D_toc`).
    All these operations take constant time. Therefore, for $T$ test cases, the total time complexity is $O(T)$.

*   **Space Complexity**: The solution uses a fixed number of integer variables to store the scores for each subject and the total scores for both students. This amount of memory (a few integer variables) does not depend on the magnitude of the scores or the number of test cases. Hence, the space complexity is $O(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries for competitive programming

// Use the standard namespace to avoid repeatedly typing std::
using namespace std;

// Function to solve a single test case
void solve() {
    // Declare variables for Dragon's scores in DSA, TOC, and DM
    int D_dsa, D_toc, D_dm;
    // Read Dragon's scores from input
    cin >> D_dsa >> D_toc >> D_dm;

    // Declare variables for Sloth's scores in DSA, TOC, and DM
    int S_dsa, S_toc, S_dm;
    // Read Sloth's scores from input
    cin >> S_dsa >> S_toc >> S_dm;

    // Calculate the total score for Dragon
    int D_total = D_dsa + D_toc + D_dm;
    // Calculate the total score for Sloth
    int S_total = S_dsa + S_toc + S_dm;

    // Apply the ranking rules hierarchically

    // Rule 1: Compare total scores
    if (D_total > S_total) {
        // If Dragon has a higher total score, Dragon gets a better rank
        cout << "DRAGON\n";
    } else if (S_total > D_total) {
        // If Sloth has a higher total score, Sloth gets a better rank
        cout << "SLOTH\n";
    } else {
        // If total scores are tied, proceed to Rule 2: Compare DSA scores
        if (D_dsa > S_dsa) {
            // If Dragon has a higher DSA score, Dragon gets a better rank
            cout << "DRAGON\n";
        } else if (S_dsa > D_dsa) {
            // If Sloth has a higher DSA score, Sloth gets a better rank
            cout << "SLOTH\n";
        } else {
            // If DSA scores are also tied, proceed to Rule 3: Compare TOC scores
            if (D_toc > S_toc) {
                // If Dragon has a higher TOC score, Dragon gets a better rank
                cout << "DRAGON\n";
            } else if (S_toc > D_toc) {
                // If Sloth has a higher TOC score, Sloth gets a better rank
                cout << "SLOTH\n";
            } else {
                // If all criteria (total, DSA, TOC) are tied, it's an overall tie
                cout << "TIE\n";
            }
        }
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output operations.
    // `ios_base::sync_with_stdio(false)` unties C++ streams from C standard streams.
    // `cin.tie(NULL)` prevents `cin` from flushing `cout` before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Variable to store the number of test cases
    cin >> T; // Read the number of test cases from input

    // Loop through each test case
    while (T--) {
        solve(); // Call the solve function for the current test case
    }

    return 0; // Indicate successful program execution
}
```