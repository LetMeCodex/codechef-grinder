# [Rivalry (CPRIVAL)](https://www.codechef.com/problems/CPRIVAL)
- **Difficulty Rating**: 501
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine which of two players, Dominater or Everule, will have a higher rating after a contest. We are given their initial ratings and the change in their ratings (which can be positive or negative) due to the contest. We need to calculate their final ratings and then print the name of the player with the higher final rating. The problem guarantees that their final ratings will not be equal.

## Intuition & Mathematical Observation

This is a very straightforward problem that primarily tests basic arithmetic and conditional logic.

1.  **Input Reading**: We need to read four integer values:
    *   `R1`: Dominater's initial rating.
    *   `R2`: Everule's initial rating.
    *   `D1`: Dominater's rating change.
    *   `D2`: Everule's rating change.

2.  **Calculate Final Ratings**:
    *   Dominater's final rating will be `R1 + D1`.
    *   Everule's final rating will be `R2 + D2`.

3.  **Comparison and Output**:
    *   Since the problem guarantees that their final ratings will not be equal, one player's final rating will always be strictly greater than the other's.
    *   We compare `final_R1` and `final_R2`.
    *   If `final_R1 > final_R2`, then Dominater has a higher rating, so we print "Dominater".
    *   Otherwise (which implies `final_R2 > final_R1`), Everule has a higher rating, so we print "Everule".

There are no complex mathematical observations or tricky edge cases to consider; it's a direct application of addition and comparison.

## Complexity Analysis

*   **Time Complexity**: $O(1)$
    The program performs a fixed number of operations regardless of the input values:
    *   Reading 4 integers.
    *   Performing 2 additions.
    *   Performing 1 comparison.
    *   Printing a constant-length string.
    All these operations take constant time. Therefore, the overall time complexity is $O(1)$.

*   **Space Complexity**: $O(1)$
    The program uses a fixed number of integer variables to store ratings and rating changes (`R1`, `R2`, `D1`, `D2`, `final_R1`, `final_R2`). The amount of memory used does not depend on the magnitude of the input values or any other variable factor. Therefore, the space complexity is $O(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes iostream and many other useful headers

using namespace std; // Brings all names from std namespace into global scope

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin from cout and disables synchronization with C's stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Declare integer variables to store Dominater's and Everule's initial ratings.
    int R1, R2;
    // Read the initial ratings from the first line of input.
    cin >> R1 >> R2;

    // Declare integer variables to store Dominater's and Everule's rating changes.
    int D1, D2;
    // Read the rating changes from the second line of input.
    cin >> D1 >> D2;

    // Calculate Dominater's final rating after the contest.
    // Final rating = Initial rating + Rating change.
    int final_R1 = R1 + D1;

    // Calculate Everule's final rating after the contest.
    // Final rating = Initial rating + Rating change.
    int final_R2 = R2 + D2;

    // Compare the final ratings to determine who has a higher rating.
    // The problem guarantees that their final ratings will not be equal.
    if (final_R1 > final_R2) {
        // If Dominater's final rating is higher, print "Dominater".
        cout << "Dominater\n";
    } else {
        // Otherwise (if Everule's final rating is higher), print "Everule".
        cout << "Everule\n";
    }

    return 0; // Indicate successful execution of the program.
}
```