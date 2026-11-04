# [Interesting Match (INTMTCH)](https://www.codechef.com/problems/INTMTCH)
- **Difficulty Rating**: 240
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem describes a football match between Chefland and Byteland. Chefland scored $X$ goals and Byteland scored $Y$ goals. Chef considers a match "interesting" if the absolute difference between the goals scored by both teams is at most 2. Otherwise, he finds the match "boring". We need to determine and output whether Chef finds the given match interesting or boring.

## Intuition & Mathematical Observation

The problem statement directly provides the condition for an "interesting" match: "the absolute difference between the goals scored by both teams is at most 2".
Let $X$ be the goals scored by Chefland and $Y$ be the goals scored by Byteland.
The absolute difference between their scores is $|X - Y|$.
The condition for an interesting match can be translated directly into the inequality:
$|X - Y| \le 2$

If this condition is true, the output should be "Interesting". Otherwise, if $|X - Y| > 2$, the output should be "Boring".
The solution simply involves reading the two scores, calculating their absolute difference, and then applying this conditional check.

## Complexity Analysis

-   **Time Complexity**: $O(1)$
    The program performs a fixed number of operations regardless of the input values:
    1.  Reading two integers ($X$ and $Y$).
    2.  Calculating the absolute difference `abs(X - Y)`.
    3.  A single comparison (`difference <= 2`).
    4.  Printing a string ("Interesting" or "Boring").
    All these operations take constant time.

-   **Space Complexity**: $O(1)$
    The program uses a constant amount of memory to store a few integer variables (`X`, `Y`, `difference`). The memory usage does not depend on the magnitude of the input values.

## Solution Code

```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cout from flushing before cin reads input.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Declare two integer variables to store the number of goals scored by Chefland (X)
    // and Byteland (Y), respectively.
    int X, Y;

    // Read the two space-separated integers X and Y from standard input.
    cin >> X >> Y;

    // Calculate the absolute difference between the goals scored by both teams.
    // The std::abs() function (from <cmath>, included by <bits/stdc++.h>)
    // returns the absolute value of its argument.
    int difference = abs(X - Y);

    // Check if the absolute difference in goals is at most 2.
    // If it is, Chef finds the match interesting.
    if (difference <= 2) {
        // Output "Interesting" followed by a newline character.
        cout << "Interesting\n";
    } else {
        // Otherwise, Chef finds the match boring.
        // Output "Boring" followed by a newline character.
        cout << "Boring\n";
    }

    // Return 0 to indicate successful execution of the program.
    return 0;
}
```