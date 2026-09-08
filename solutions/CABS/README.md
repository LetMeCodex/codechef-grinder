# [The Cheaper Cab (CABS)](https://www.codechef.com/problems/CABS)

- **Difficulty Rating**: 399
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to compare the prices of two different cab services. Given the price of the first cab ($X$) and the price of the second cab ($Y$), we need to determine which one is cheaper. If the first is cheaper, output `FIRST`. If the second is cheaper, output `SECOND`. If both prices are equal, output `ANY`.

## Intuition & Mathematical Observation
This is a straightforward conditional logic problem. We are given two integers, $X$ and $Y$, and we need to perform a three-way comparison:
1. If $X < Y$, the first service is the better choice.
2. If $Y < X$, the second service is the better choice.
3. If $X = Y$, the cost is identical, so either choice is acceptable.

By using simple `if-else if-else` statements, we can evaluate these conditions efficiently for every test case provided.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant number of comparisons, resulting in $O(1)$ per test case.
- **Space Complexity**: $O(1)$, as we only use a few integer variables to store the input values regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries

// Using the standard namespace to avoid writing std:: repeatedly
using namespace std;

// Function to solve a single test case
void solve() {
    int X, Y; // Declare variables for the prices of the two cab services
    cin >> X >> Y; // Read the prices X and Y from input

    // Compare the prices to determine which cab service is cheaper
    if (X < Y) {
        // If the first cab service (X) is cheaper than the second (Y)
        cout << "FIRST\n"; 
    } else if (Y < X) {
        // If the second cab service (Y) is cheaper than the first (X)
        cout << "SECOND\n";
    } else { // X == Y
        // If both cab services have the same price
        cout << "ANY\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams,
    // which can speed up I/O operations.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation,
    // further speeding up I/O.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare variable for the number of test cases
    cin >> T; // Read the number of test cases

    // Loop through each test case
    while (T--) {
        solve(); // Call the solve function to handle the current test case
    }

    return 0; // Indicate successful execution of the program
}
```