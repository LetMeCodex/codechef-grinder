# [Chairs Requirement (CHAIRS_)](https://www.codechef.com/problems/CHAIRS_)
- **Difficulty Rating**: 305
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to calculate the minimum number of additional chairs a chef needs to buy. We are given the number of students who will attend a class ($X$) and the number of chairs the chef already possesses ($Y$). The chef needs at least one chair for each student.

## Intuition & Mathematical Observation
The core of the problem is to ensure that the number of chairs available is at least equal to the number of students.

Let $X$ be the number of students.
Let $Y$ be the number of chairs the chef already has.

The chef needs a total of $X$ chairs.
If the chef already has $Y$ chairs, and $Y \ge X$, then the chef has enough chairs and doesn't need to buy any new ones. The number of chairs to buy is 0.

If the chef has $Y$ chairs, and $Y < X$, then the chef is short of chairs. The number of chairs the chef is short by is $X - Y$. This is exactly the number of new chairs the chef needs to buy.

Combining these two cases, we can say that the number of chairs to buy is:
- $0$ if $X \le Y$
- $X - Y$ if $X > Y$

This can be concisely expressed using the `max` function. The number of chairs to buy is the maximum of 0 and $(X - Y)$. If $(X - Y)$ is negative (meaning $Y > X$), `max(0, X - Y)` will return 0. If $(X - Y)$ is non-negative (meaning $X \ge Y$), `max(0, X - Y)` will return $(X - Y)$.

Therefore, the formula is: `chairs_to_buy = max(0, X - Y)`.

## Complexity Analysis
- **Time Complexity**: $O(1)$
    The solution involves a fixed number of arithmetic operations and comparisons for each test case. The input reading and output writing are also constant time per test case. Since the number of test cases $T$ is read once, and the operations inside the loop are constant time, the total time complexity is $O(1)$ per test case.

- **Space Complexity**: $O(1)$
    The solution uses a fixed amount of memory to store variables like $T$, $X$, $Y$, and `chairs_to_buy`. This memory usage does not depend on the input size, hence the space complexity is $O(1)$.

## Solution Code
```cpp
#include <bits/stdc++.h> // Includes common libraries like iostream and algorithm

// Using namespace std; is a common practice in competitive programming
// and is explicitly requested by the problem statement.
using namespace std; 

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a standard competitive programming optimization and is explicitly requested.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases

    // Loop through each test case
    while (T--) {
        int X, Y;
        cin >> X >> Y; // Read X (number of students) and Y (chairs Chef already has)

        // Determine the minimum number of new chairs Chef must buy.
        // If the number of students (X) is greater than the number of chairs Chef has (Y),
        // Chef needs to buy X - Y chairs.
        // If X is less than or equal to Y, Chef already has enough chairs (or more),
        // so no new chairs need to be bought (0 chairs).
        // This logic can be concisely expressed using std::max(0, X - Y).
        int chairs_to_buy = max(0, X - Y);

        // Output the result for the current test case, followed by a newline.
        cout << chairs_to_buy << "\n";
    }

    return 0; // Indicate successful execution
}
```