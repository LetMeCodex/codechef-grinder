# [Giant Wheel (GIANT)](https://www.codechef.com/problems/GIANT)
- **Difficulty Rating**: 293
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine if Alice is tall enough to ride a giant wheel. The rule states that a person must have a height of at least 60 centimeters to be allowed on the ride. We are given Alice's height, `X` centimeters, and our task is to print "Yes" if she meets the height requirement, and "No" otherwise.

## Intuition & Mathematical Observation

This problem is a direct application of a simple conditional check. The core requirement is a minimum height.
Our intuition immediately points to a comparison:
1. We need to get Alice's height, `X`.
2. We compare `X` with the minimum required height, which is 60 cm.
3. If `X` is greater than or equal to 60, Alice can ride.
4. Otherwise (if `X` is less than 60), she cannot.

Mathematically, this translates to evaluating the inequality `X >= 60`. If this inequality holds true, the answer is "Yes"; otherwise, it's "No". There are no complex algorithms, data structures, or advanced mathematical concepts required beyond a basic comparison.

## Complexity Analysis

-   **Time Complexity**: $O(1)$
    The program performs a constant number of operations:
    1.  Reading an integer input (`cin >> X`).
    2.  Performing a single comparison (`X >= 60`).
    3.  Printing a string output (`cout << "Yes\n"` or `cout << "No\n"`).
    All these operations take constant time, regardless of the value of `X`. Therefore, the overall time complexity is $O(1)$.

-   **Space Complexity**: $O(1)$
    The program uses a fixed amount of memory to store a single integer variable `X`. This memory usage does not depend on the input value or any other factor. Thus, the space complexity is $O(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes most standard libraries

// Use the standard namespace to avoid prefixing std::
using namespace std;

int main() {
    // Optimize C++ standard streams for competitive programming.
    // This unties cin from cout and disables synchronization with C's stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Declare an integer variable X to store Alice's height.
    int X;

    // Read Alice's height from standard input.
    cin >> X;

    // Check if Alice's height is greater than or equal to the minimum required height (60 cm).
    if (X >= 60) {
        // If Alice's height is sufficient, print "Yes".
        cout << "Yes\n";
    } else {
        // Otherwise (if Alice's height is less than 60 cm), print "No".
        cout << "No\n";
    }

    // The program finishes successfully.
    return 0;
}
```