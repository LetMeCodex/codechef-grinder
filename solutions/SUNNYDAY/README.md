# [Sunny Day (SUNNYDAY)](https://www.codechef.com/problems/SUNNYDAY)
- **Difficulty Rating**: -1
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to determine if a given integer `x` represents a "sunny day". The condition for a sunny day is that `x` must be strictly greater than 24. We need to read an integer `t` representing the number of test cases, and for each test case, read an integer `x` and print "YES" if `x > 24`, and "NO" otherwise.

## Intuition & Mathematical Observation
The problem statement directly provides the condition for a "sunny day": `x > 24`. There's no complex logic or hidden pattern to discover. It's a straightforward comparison.

The core of the problem is to implement this simple conditional check for multiple test cases.

## Complexity Analysis
- **Time Complexity**: $O(T)$
  The program iterates through `t` test cases. For each test case, it performs a constant number of operations: reading an integer, performing a comparison, and printing a string. Therefore, the total time complexity is directly proportional to the number of test cases, `t`.

- **Space Complexity**: $O(1)$
  The program uses a fixed amount of memory to store variables like `t` and `x`, regardless of the input size. No additional data structures that grow with the input are used.

## Solution Code
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    // Optimize C++ standard streams for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; // Variable to store the number of test cases
    cin >> t; // Read the number of test cases

    // Loop through each test case
    while (t--) {
        int x; // Variable to store the input integer for the current test case
        cin >> x; // Read the integer x

        // Check if x is strictly greater than 24
        if (x > 24) {
            cout << "YES\n"; // If x > 24, it's a sunny day
        } else {
            cout << "NO\n"; // Otherwise, it's not a sunny day
        }
    }

    return 0; // Indicate successful execution
}
```