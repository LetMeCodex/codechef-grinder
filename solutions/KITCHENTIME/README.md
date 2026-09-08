# Kitchen Timings (KITCHENTIME)

- **Difficulty Rating**: 273
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to calculate the duration for which a chef works. We are given the start time and the end time of the chef's work. The input consists of multiple test cases. For each test case, we are given two integers, $X$ and $Y$, representing the start and end times, respectively. We need to output the difference between the end time and the start time. It is guaranteed that $Y \ge X$.

## Intuition & Mathematical Observation

The core of this problem is to find the difference between two given times. If a chef starts working at time $X$ and finishes at time $Y$, the total time spent working is simply the difference between the finish time and the start time.

Mathematically, if $X$ is the start time and $Y$ is the end time, the duration is given by:

Duration = End Time - Start Time
Duration = $Y - X$

Since the problem statement guarantees that $Y \ge X$, the duration will always be non-negative, which makes sense for a time duration.

## Complexity Analysis

- **Time Complexity**: $O(1)$ per test case.
    The solution involves reading two integers and performing a single subtraction and printing the result. These operations take constant time. Since there are $T$ test cases, the total time complexity is $O(T)$. However, when analyzing the complexity *per test case*, it is $O(1)$.

- **Space Complexity**: $O(1)$.
    The solution uses a fixed number of variables ($T$, $X$, $Y$, and `duration`) regardless of the input size. Therefore, the space complexity is constant.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard C++ libraries

// Use the standard namespace to avoid prefixing standard library elements with std::
using namespace std;

int main() {
    // Optimize C++ standard streams for competitive programming.
    // This unties cin from cout and prevents synchronization with C's stdio,
    // leading to faster input/output operations.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare an integer variable to store the number of test cases
    cin >> T; // Read the number of test cases from standard input

    // Loop T times, once for each test case
    while (T--) {
        int X, Y; // Declare two integer variables for the start and end times
        cin >> X >> Y; // Read the start time X and end time Y for the current test case

        // Calculate the duration Chef works.
        // Since X is the start time and Y is the end time, and Y >= X,
        // the duration is simply their difference.
        int duration = Y - X;

        // Print the calculated duration followed by a newline character.
        // Using "\n" is generally faster than endl in competitive programming
        // because endl also flushes the output buffer.
        cout << duration << "\n";
    }

    return 0; // Indicate successful program execution
}
```