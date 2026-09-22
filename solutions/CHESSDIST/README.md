# [Chessboard Distance (CHESSDIST)](https://www.codechef.com/problems/CHESSDIST)
- **Difficulty Rating**: 690
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to calculate the "Chessboard Distance" between two given points $(x_1, y_1)$ and $(x_2, y_2)$. The Chessboard Distance is defined as the maximum of the absolute difference in their x-coordinates and the absolute difference in their y-coordinates. We need to compute this distance for multiple test cases.

## Intuition & Mathematical Observation

The problem statement directly provides the definition of the Chessboard Distance. For two points $P_1 = (x_1, y_1)$ and $P_2 = (x_2, y_2)$, the Chessboard Distance (also known as Chebyshev distance or $L_\infty$ distance) is given by the formula:

$$ \text{Chessboard Distance} = \max(|x_1 - x_2|, |y_1 - y_2|) $$

Our task is to simply implement this formula.
1.  Read the coordinates of the two points: $x_1, y_1, x_2, y_2$.
2.  Calculate the absolute difference between the x-coordinates: `diff_x = abs(x1 - x2)`.
3.  Calculate the absolute difference between the y-coordinates: `diff_y = abs(y1 - y2)`.
4.  The final result is the maximum of these two differences: `result = max(diff_x, diff_y)`.
5.  Print the `result`.

This approach directly translates the mathematical definition into code, requiring no complex algorithms or data structures.

## Complexity Analysis

-   **Time Complexity**: $O(T)$
    For each test case, the operations involve reading four integers, performing two subtractions, two absolute value calculations, one maximum calculation, and one print operation. All these operations take constant time, $O(1)$. Since there are $T$ test cases, the total time complexity will be $T \times O(1) = O(T)$. The input/output optimizations (`ios_base::sync_with_stdio(false); cin.tie(NULL);`) improve the constant factor but do not change the asymptotic complexity.

-   **Space Complexity**: $O(1)$
    The solution uses a fixed number of integer variables to store coordinates and intermediate differences (`x1, y1, x2, y2, diff_x, diff_y, result`). The amount of memory used does not depend on the input values or the number of test cases (beyond the loop counter), making the space complexity constant.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes common headers like iostream, cmath, algorithm

// Using the standard namespace to avoid repeatedly typing std::
using namespace std;

// Function to solve a single test case
void solve() {
    int x1, y1, x2, y2;
    // Read the coordinates of the two points
    cin >> x1 >> y1 >> x2 >> y2;

    // Calculate the absolute difference in x-coordinates
    // abs() function is used to get the absolute value
    int diff_x = abs(x1 - x2);
    
    // Calculate the absolute difference in y-coordinates
    int diff_y = abs(y1 - y2);

    // The Chessboard Distance is defined as the maximum of these two differences
    // max() function returns the larger of its two arguments
    int result = max(diff_x, diff_y);
    
    // Output the calculated Chessboard Distance followed by a newline
    cout << result << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    // Read the number of test cases
    cin >> t;
    // Loop through each test case
    while (t--) {
        solve(); // Call the solve function for the current test case
    }

    return 0; // Indicate successful program execution
}

```