# [Dracula Eats (CHEAT)](https://www.codechef.com/problems/CHEAT)
- **Difficulty Rating**: 763
- **Solved in**: 1 attempt(s)

## Problem Summary

Dracula decides to eat for $N$ consecutive days, starting on a Monday. We need to determine how many times he eats on a Tuesday within these $N$ days.

## Intuition & Mathematical Observation

Let's map the days of the week to day numbers, starting from 1:
*   Day 1: Monday
*   Day 2: Tuesday
*   Day 3: Wednesday
*   Day 4: Thursday
*   Day 5: Friday
*   Day 6: Saturday
*   Day 7: Sunday

The cycle then repeats:
*   Day 8: Monday
*   Day 9: Tuesday
*   ...and so on.

We are interested in Tuesdays. From the mapping, Tuesdays occur on Day 2, Day 9, Day 16, and generally on days of the form $2 + 7k$, where $k$ is a non-negative integer.

We need to count how many such days ($2 + 7k$) are less than or equal to $N$.

Let's consider the cases:

1.  **If $N < 2$**:
    *   If $N=1$ (Dracula eats only on Monday), he never reaches a Tuesday. So, the count is 0.
    *   This is handled by the `if (N < 2)` condition in the code.

2.  **If $N \ge 2$**:
    *   Dracula will always eat on Day 2, which is a Tuesday. So, there is at least one Tuesday. This accounts for the `1 + ...` part of the formula.
    *   After Day 2, subsequent Tuesdays occur every 7 days. We need to find how many full 7-day cycles occur within the remaining days.
    *   The days remaining after Day 2 are Day 3, Day 4, ..., up to Day $N$. The total number of these remaining days is $N - 2$.
    *   Each full 7-day period within these $N-2$ days will contain exactly one additional Tuesday. For example, days 3-9 contain Day 9 (a Tuesday), days 10-16 contain Day 16 (a Tuesday), and so on.
    *   The number of full 7-day cycles in $N-2$ days can be found using integer division: `(N - 2) / 7`.
    *   Therefore, the total number of Tuesdays is `1` (for Day 2) + `(N - 2) / 7` (for all subsequent Tuesdays).

Let's test with examples:
*   $N=1$: `count_tuesdays = 0` (correct, handled by `if`).
*   $N=2$: `1 + (2 - 2) / 7 = 1 + 0 / 7 = 1 + 0 = 1`. (Correct, Day 2).
*   $N=8$: `1 + (8 - 2) / 7 = 1 + 6 / 7 = 1 + 0 = 1`. (Correct, only Day 2).
*   $N=9$: `1 + (9 - 2) / 7 = 1 + 7 / 7 = 1 + 1 = 2`. (Correct, Day 2 and Day 9).
*   $N=15$: `1 + (15 - 2) / 7 = 1 + 13 / 7 = 1 + 1 = 2`. (Correct, Day 2 and Day 9).
*   $N=16$: `1 + (16 - 2) / 7 = 1 + 14 / 7 = 1 + 2 = 3`. (Correct, Day 2, Day 9, and Day 16).

The logic holds for all cases.

## Complexity Analysis
-   **Time Complexity**: $O(T)$
    The solution involves a loop that runs `T` times (for each test case). Inside the loop, we perform a constant number of arithmetic operations (subtraction, division, addition) and input/output operations. These operations take constant time, $O(1)$. Therefore, the total time complexity is directly proportional to the number of test cases, $O(T)$.
-   **Space Complexity**: $O(1)$
    The solution uses a fixed number of integer variables (`T`, `N`, `count_tuesdays`) regardless of the input values of $N$ or $T$. No data structures that grow with input size are used. Hence, the space complexity is constant.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries

// Using namespace std; as requested
using namespace std;

int main() {
    // Fast I/O as requested
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) {
        int N;
        cin >> N; // Read N for each test case

        int count_tuesdays;
        if (N < 2) {
            // If N is 1 (only Monday), no Tuesdays are encountered.
            count_tuesdays = 0;
        } else {
            // The first Tuesday is on day 2. This accounts for 1 Tuesday.
            // For any subsequent Tuesdays, they occur every 7 days.
            // The number of days remaining after the first Tuesday is N - 2.
            // Each full 7-day cycle within these remaining days (starting from day 3)
            // adds one more Tuesday.
            // (N - 2) / 7 performs integer division, giving the number of full 7-day cycles.
            // So, total Tuesdays = 1 (for day 2) + (number of additional 7-day cycles).
            count_tuesdays = 1 + (N - 2) / 7;
        }
        cout << count_tuesdays << "\n"; // Output the result followed by a newline
    }
    return 0;
}

```