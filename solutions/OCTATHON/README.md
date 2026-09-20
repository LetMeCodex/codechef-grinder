# [October Marathon (OCTATHON)](https://www.codechef.com/problems/OCTATHON)
- **Difficulty Rating**: 319
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine the type of medal Chefina receives in a marathon based on her finishing time, denoted by `X` hours. The rules for medal distribution are as follows:
- If Chefina finishes in strictly less than 3 hours (`X < 3`), she receives a **GOLD** medal.
- If Chefina finishes in 3 hours or more but strictly less than 6 hours (`3 <= X < 6`), she receives a **SILVER** medal.
- If Chefina finishes in 6 hours or more (`X >= 6`), she receives a **BRONZE** medal.

We need to read the integer `X` and print the corresponding medal type.

## Intuition & Mathematical Observation

This problem is a direct application of conditional logic. We are given a set of mutually exclusive conditions based on the value of `X`, and for each condition, a specific output is required. The most straightforward approach is to use `if-else if-else` statements to check these conditions in order.

1. First, check if `X < 3`. If true, print "GOLD".
2. If the first condition is false (meaning `X >= 3`), then check if `X < 6`. If true, print "SILVER".
3. If both previous conditions are false (meaning `X >= 3` AND `X >= 6`, which simplifies to `X >= 6`), then print "BRONZE".

There are no complex mathematical observations or algorithms needed; it's a simple mapping from an input range to a string output.

## Complexity Analysis

-   **Time Complexity**: $O(1)$
    The program performs a fixed number of operations regardless of the input value `X`. It reads one integer, performs at most two comparisons, and prints one string. All these operations take constant time. Therefore, the time complexity is constant.

-   **Space Complexity**: $O(1)$
    The program uses a single integer variable `X` to store the input. This requires a constant amount of memory, irrespective of the value of `X`. No additional data structures are used that would scale with input size. Therefore, the space complexity is constant.

## Solution Code

```cpp
#include <bits/stdc++.h> // Standard header for competitive programming
using namespace std;     // Using the standard namespace

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Declare an integer variable X to store the time taken by Chefina.
    int X;

    // Read the input value for X.
    cin >> X;

    // Apply the conditional logic to determine the medal type based on X.
    // The conditions are checked in order:
    // 1. If X is less than 3 hours, it's a GOLD medal.
    if (X < 3) {
        cout << "GOLD\n";
    }
    // 2. Else if X is less than 6 hours (and we already know it's >= 3 hours from the previous check),
    //    it's a SILVER medal.
    else if (X < 6) { // This implicitly means X >= 3 and X < 6
        cout << "SILVER\n";
    }
    // 3. Else (if X is not less than 3 and not less than 6, meaning X is greater than or equal to 6 hours),
    //    it's a BRONZE medal.
    else { // This implicitly means X >= 6
        cout << "BRONZE\n";
    }

    // Return 0 to indicate successful execution of the program.
    return 0;
}
```