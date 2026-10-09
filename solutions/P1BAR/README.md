# Basketball Score (P1BAR)
- **Difficulty Rating**: 206
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to calculate the total score in a basketball game given the number of 3-pointers and 2-pointers made. Each 3-pointer contributes 3 points, and each 2-pointer contributes 2 points.

## Intuition & Mathematical Observation
The problem is a straightforward calculation. We are given two quantities:
1. The number of 3-pointers made.
2. The number of 2-pointers made.

To find the total score, we need to multiply the count of each type of shot by its respective point value and then sum these products.

Let $X$ be the number of 3-pointers made.
Let $Y$ be the number of 2-pointers made.

The points from 3-pointers will be $X \times 3$.
The points from 2-pointers will be $Y \times 2$.

The total score is the sum of these two:
Total Score = $(X \times 3) + (Y \times 2)$

This is a direct application of arithmetic.

## Complexity Analysis
- **Time Complexity**: $O(1)$
The solution involves a fixed number of arithmetic operations (two multiplications and one addition) and two input/output operations. The time taken does not depend on the magnitude of the input values $X$ and $Y$, hence it's constant time.

- **Space Complexity**: $O(1)$
The solution uses a fixed amount of memory to store the input variables ($X$, $Y$) and the result variable (`total_score`). This memory usage is constant and does not grow with the input size.

## Solution Code
```cpp
#include <bits/stdc++.h> // Includes most standard libraries

using namespace std; // Uses the standard namespace

int main() {
    // Optimize C++ standard streams for competitive programming.
    // This unties cin/cout from the C standard streams and disables synchronization
    // with C's stdio, making I/O operations faster.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Declare two integer variables X and Y to store the number of 3-pointers and 2-pointers.
    int X, Y;

    // Read the two integers X and Y from standard input.
    cin >> X >> Y;

    // Calculate the total score.
    // Each 3-pointer is worth 3 points, so X 3-pointers contribute X * 3 points.
    // Each 2-pointer is worth 2 points, so Y 2-pointers contribute Y * 2 points.
    // The total score is the sum of these two contributions.
    int total_score = (X * 3) + (Y * 2);

    // Print the calculated total score to standard output, followed by a newline character.
    cout << total_score << "\n";

    // Return 0 to indicate successful execution of the program.
    return 0;
}
```