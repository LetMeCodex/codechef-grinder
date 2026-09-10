# [Second Largest (FLOW017)](https://www.codechef.com/problems/FLOW017)
- **Difficulty Rating**: 730
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to read three distinct integers, `A`, `B`, and `C`, for several test cases. For each test case, we need to find and print the second largest among these three integers.

## Intuition & Mathematical Observation

Given three distinct integers, the "second largest" integer is the one that is neither the absolute smallest nor the absolute largest. In other words, it's the number that is greater than one of the other two numbers and smaller than the remaining one.

Let's consider the three numbers `a`, `b`, and `c`.
If `a` is the second largest, it must satisfy one of these two conditions:
1. `a` is greater than `b` AND `a` is less than `c` (i.e., `b < a < c`)
2. `a` is less than `b` AND `a` is greater than `c` (i.e., `c < a < b`)

The provided solution directly implements this logic using `if-else if` statements:
- It first checks if `a` satisfies the condition to be the second largest.
- If not, it checks if `b` satisfies the condition.
- If neither `a` nor `b` is the second largest, then by elimination (since there are only three distinct numbers), `c` *must* be the second largest.

This approach is straightforward and efficient for a fixed small number of elements (three in this case).

## Complexity Analysis

-   **Time Complexity**: $O(T)$
    For each test case, the program reads three integers and performs a constant number of comparisons and logical operations. These operations take constant time, $O(1)$. Since there are $T$ test cases, the total time complexity is $T \times O(1) = O(T)$.

-   **Space Complexity**: $O(1)$
    The program uses a fixed amount of memory to store variables like `t`, `a`, `b`, and `c`, regardless of the input values or the number of test cases. This constant memory usage leads to an $O(1)$ space complexity.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes common libraries like iostream

using namespace std; // Uses the standard namespace

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; // Declare an integer variable 't' for the number of test cases
    cin >> t; // Read the number of test cases

    while (t--) { // Loop 't' times, decrementing 't' in each iteration
        int a, b, c; // Declare three integer variables for the input numbers
        cin >> a >> b >> c; // Read the three integers for the current test case

        // Check if 'a' is the second largest
        // 'a' is second largest if it's between 'b' and 'c'
        if ((a > b && a < c) || (a < b && a > c)) {
            cout << a << "\n"; // If 'a' is second largest, print 'a'
        } 
        // Else, check if 'b' is the second largest
        // 'b' is second largest if it's between 'a' and 'c'
        else if ((b > a && b < c) || (b < a && b > c)) {
            cout << b << "\n"; // If 'b' is second largest, print 'b'
        } 
        // If neither 'a' nor 'b' is the second largest, then 'c' must be
        else {
            cout << c << "\n"; // Print 'c'
        }
    }

    return 0; // Indicate successful execution
}

```