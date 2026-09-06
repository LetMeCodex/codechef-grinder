# [Find Remainder (FLOW002)](https://www.codechef.com/problems/FLOW002)
- **Difficulty Rating**: 421
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem "Find Remainder" asks us to perform a basic arithmetic operation for a given number of test cases. For each test case, we are provided with two positive integers, `A` and `B`. Our task is to calculate and print the remainder when `A` is divided by `B`.

## Intuition & Mathematical Observation

The problem statement directly asks for the remainder of a division. In C++ (and most other programming languages), there is a dedicated operator for this purpose: the modulo operator (`%`).

Given two integers `A` and `B`, the expression `A % B` directly computes the remainder when `A` is divided by `B`. For example:
*   `10 % 3` evaluates to `1` (since $10 = 3 \times 3 + 1$)
*   `15 % 5` evaluates to `0` (since $15 = 5 \times 3 + 0$)
*   `7 % 2` evaluates to `1` (since $7 = 2 \times 3 + 1$)

Therefore, the most straightforward and efficient approach is to simply read `A` and `B` for each test case and then print the result of `A % B`. No complex mathematical observations or algorithms are required beyond understanding the basic definition and operation of the modulo operator.

## Complexity Analysis

-   **Time Complexity**: $O(T)$
    *   For each test case, we perform a constant number of operations: reading two integers (`A` and `B`), performing a modulo operation (`A % B`), and printing the result. Each of these operations takes $O(1)$ time.
    *   Since there are `T` test cases, the total time complexity is $T \times O(1) = O(T)$.

-   **Space Complexity**: $O(1)$
    *   We only use a few integer variables (`T`, `A`, `B`) to store the number of test cases, the input values for each test case, and loop counters. The amount of memory used does not depend on the magnitude of the input numbers or the number of test cases (beyond the initial `T` itself), making it constant space.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes most standard libraries, useful in competitive programming.
using namespace std;

int main() {
    // Optimize C++ standard streams for competitive programming.
    // This unties cin/cout from the C standard streams and
    // prevents synchronization overhead, making I/O faster.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare an integer T to store the number of test cases.
    cin >> T; // Read the total number of test cases.

    // Loop T times, once for each test case.
    while (T--) {
        int A, B; // Declare two integers A and B for the current test case.
        cin >> A >> B; // Read the two integers A and B.

        // Calculate the remainder when A is divided by B using the modulo operator (%).
        // Print the result followed by a newline character.
        cout << (A % B) << "\n";
    }

    return 0; // Indicate successful execution of the program.
}
```