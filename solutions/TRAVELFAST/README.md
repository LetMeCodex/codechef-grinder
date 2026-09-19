# [Car or Bike (TRAVELFAST)](https://www.codechef.com/problems/TRAVELFAST)
- **Difficulty Rating**: 571
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine the faster mode of travel between a bike and a car. We are given two integer values: `X`, representing the time taken to travel by bike, and `Y`, representing the time taken to travel by car. Our task is to compare these two times and output:
- "BIKE" if the bike takes less time than the car (`X < Y`).
- "CAR" if the car takes less time than the bike (`Y < X`).
- "SAME" if both the bike and the car take the same amount of time (`X == Y`).

This comparison needs to be performed for multiple test cases.

## Intuition & Mathematical Observation

The problem is a straightforward comparison task. We are given two quantities, `X` and `Y`, and we need to determine their relative order. The core idea is to use conditional statements to check the three possible relationships between `X` and `Y`:

1.  **Is `X` less than `Y`?** If `X < Y`, it means the bike is faster.
2.  **Is `Y` less than `X`?** If `Y < X`, it means the car is faster.
3.  **If neither of the above is true, then `X` must be equal to `Y`.** In this case, both modes of transport take the same time.

No complex mathematical formulas or algorithms are required; a simple `if-else if-else` structure is sufficient to implement this logic.

## Complexity Analysis

-   **Time Complexity**: $O(T)$
    -   For each test case, the program performs a constant number of operations: reading two integers (`X` and `Y`), comparing them, and printing a string. These operations take $O(1)$ time.
    -   Since there are `T` test cases, the total time complexity is $T \times O(1) = O(T)$.

-   **Space Complexity**: $O(1)$
    -   The program uses a fixed amount of memory regardless of the input values or the number of test cases. It only stores a few integer variables (`T`, `X`, `Y`) at any given time. This constant memory usage leads to an $O(1)$ space complexity.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare an integer variable T to store the number of test cases.
    cin >> T; // Read the number of test cases from standard input.

    // Loop T times, once for each test case.
    while (T--) {
        int X, Y; // Declare two integer variables X and Y for bike and car travel times.
        cin >> X >> Y; // Read the travel times for bike (X) and car (Y) for the current test case.

        // Compare the travel times to determine which option is faster or if they are the same.
        if (X < Y) {
            // If X (bike time) is less than Y (car time), bike is faster.
            cout << "BIKE\n";
        } else if (Y < X) {
            // If Y (car time) is less than X (bike time), car is faster.
            cout << "CAR\n";
        } else {
            // If neither of the above conditions is true, then X must be equal to Y.
            // In this case, both options take the same time.
            cout << "SAME\n";
        }
    }

    return 0; // Indicate successful program execution.
}
```