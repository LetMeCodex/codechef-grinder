# [Messi vs Ronaldo (MVR)](https://www.codechef.com/problems/MVR)
- **Difficulty Rating**: 316
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to compare the performance of two legendary football players, Messi and Ronaldo, based on their goals and assists. We are given Messi's goals (`A`) and assists (`B`), and Ronaldo's goals (`X`) and assists (`Y`). The scoring system is defined as:
*   Each goal is worth **2 points**.
*   Each assist is worth **1 point**.

Our task is to calculate the total points for both players and then determine who has more points. We should print "Messi" if Messi has more points, "Ronaldo" if Ronaldo has more points, and "Equal" if both players have the same number of points.

## Intuition & Mathematical Observation

The core idea is straightforward: we need to translate the given goals and assists into a total point score for each player according to the specified rules. Once we have these two total scores, a simple comparison will tell us the winner or if it's a tie.

Let's define the point calculation:
*   **Messi's Total Points**: If Messi scores `A` goals and makes `B` assists, his total points will be `(A * 2) + (B * 1)`.
*   **Ronaldo's Total Points**: Similarly, if Ronaldo scores `X` goals and makes `Y` assists, his total points will be `(X * 2) + (Y * 1)`.

After calculating both `messi_points` and `ronaldo_points`, we perform a three-way comparison:
1.  If `messi_points > ronaldo_points`, Messi wins.
2.  If `ronaldo_points > messi_points`, Ronaldo wins.
3.  Otherwise (if neither of the above is true), `messi_points == ronaldo_points`, meaning it's a tie.

This approach directly implements the problem's rules and requires no complex algorithms or data structures.

## Complexity Analysis

*   **Time Complexity**: $O(1)$
    The solution involves a fixed number of operations regardless of the input values:
    *   Reading four integer inputs.
    *   Two multiplications and two additions to calculate Messi's points.
    *   Two multiplications and two additions to calculate Ronaldo's points.
    *   A few comparisons and one print operation.
    All these operations take constant time. Therefore, the overall time complexity is constant.

*   **Space Complexity**: $O(1)$
    The solution uses a fixed number of integer variables to store the inputs (`A`, `B`, `X`, `Y`) and the calculated points (`messi_points`, `ronaldo_points`). The memory usage does not grow with the magnitude of the input values. Thus, the space complexity is constant.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes most standard libraries

// It's common practice in competitive programming to use the entire std namespace
// to avoid repeatedly typing std::
using namespace std; 

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Declare four integer variables to store the input values:
    // A: Messi's goals
    // B: Messi's assists
    // X: Ronaldo's goals
    // Y: Ronaldo's assists
    int A, B, X, Y;

    // Read the four space-separated integers from the standard input.
    cin >> A >> B >> X >> Y;

    // Calculate Messi's total points.
    // Each goal is 2 points, each assist is 1 point.
    int messi_points = (A * 2) + B;

    // Calculate Ronaldo's total points using the same logic.
    int ronaldo_points = (X * 2) + Y;

    // Compare the total points of Messi and Ronaldo.
    if (messi_points > ronaldo_points) {
        // If Messi has more points, print "Messi".
        cout << "Messi\n";
    } else if (ronaldo_points > messi_points) {
        // If Ronaldo has more points, print "Ronaldo".
        cout << "Ronaldo\n";
    } else {
        // If neither has more points, they must have an equal number of points.
        cout << "Equal\n";
    }

    // Return 0 to indicate successful execution of the program.
    return 0;
}
```