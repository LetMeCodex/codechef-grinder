# [Lucky Number (LUCKYNUM)](https://www.codechef.com/problems/LUCKYNUM)
- **Difficulty Rating**: -1
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine if Chef wins a lottery. Chef's lottery ticket has three digits, say A, B, and C. Chef wins if at least one of these three digits is equal to 7. We are given $T$ test cases, and for each test case, we receive the three digits A, B, and C. We need to output "YES" if Chef wins, and "NO" otherwise.

## Intuition & Mathematical Observation

This problem is a very basic conditional check. The core condition for Chef to win is "at least one of the digits is 7". This can be directly translated into a logical expression: `(A == 7) OR (B == 7) OR (C == 7)`.

If this logical expression evaluates to true, Chef wins, and we should print "YES". Otherwise, if none of the digits are 7 (meaning A is not 7 AND B is not 7 AND C is not 7), Chef does not win, and we should print "NO". There are no complex algorithms, data structures, or mathematical properties required beyond this simple logical check.

## Complexity Analysis

-   **Time Complexity**: $O(T)$
    For each test case, the program performs a constant number of operations: reading three integers, performing three comparisons, and one logical OR operation. This takes $O(1)$ time per test case. Since there are $T$ test cases, the total time complexity is $T \times O(1) = O(T)$.

-   **Space Complexity**: $O(1)$
    The program uses a fixed amount of memory to store variables like `T`, `A`, `B`, and `C`. The memory usage does not depend on the input values or the number of test cases (as variables are reused for each test case). Therefore, the space complexity is constant, $O(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes most standard libraries
using namespace std; // Uses the standard namespace

int main() {
    // Optimize C++ standard streams for competitive programming.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare an integer variable T for the number of test cases
    cin >> T; // Read the number of test cases from standard input

    // Loop T times, once for each test case
    while (T--) {
        int A, B, C; // Declare three integer variables for the digits of the lottery ticket
        cin >> A >> B >> C; // Read the three digits A, B, and C from standard input

        // Check if any of the digits A, B, or C is equal to 7.
        // The problem states Chef wins if AT LEAST ONE of the digits is 7.
        if (A == 7 || B == 7 || C == 7) {
            // If the condition is true, Chef wins, so print "YES"
            cout << "YES\n";
        } else {
            // If the condition is false (none of the digits are 7), Chef does not win, so print "NO"
            cout << "NO\n";
        }
    }

    return 0; // Indicate successful program execution
}
```