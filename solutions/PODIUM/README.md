# [Podium Finish (PODIUM)](https://www.codechef.com/problems/PODIUM)
- **Difficulty Rating**: 341
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem describes a competitive programming scenario where Chef is participating. We are given two pieces of information:
1. The time gap ($A$) between Chef (who finished 3rd) and the runner-up (who finished 2nd).
2. The time gap ($B$) between the runner-up (2nd) and the winner (1st).

The task is to calculate and output the total time gap between Chef and the winner.

## Intuition & Mathematical Observation

Let's denote the finishing times as follows:
- $T_C$: Chef's finishing time
- $T_R$: Runner-up's finishing time
- $T_W$: Winner's finishing time

From the problem statement, we can deduce the following relationships:
1. The time gap between Chef and the runner-up is $A$. Since Chef finished after the runner-up, this means $T_C - T_R = A$.
2. The time gap between the runner-up and the winner is $B$. Since the runner-up finished after the winner, this means $T_R - T_W = B$.

We are asked to find the total time gap between Chef and the winner, which is $T_C - T_W$.

We can express $T_C$ in terms of $T_R$ and $A$:
$T_C = T_R + A$

And we can express $T_R$ in terms of $T_W$ and $B$:
$T_R = T_W + B$

Now, substitute the expression for $T_R$ into the equation for $T_C$:
$T_C = (T_W + B) + A$
$T_C = T_W + B + A$

To find the total gap between Chef and the winner, we rearrange the equation:
$T_C - T_W = A + B$

This shows that the total time gap between Chef and the winner is simply the sum of the individual gaps. This is an intuitive result: if you have a series of consecutive gaps, the total gap across the entire series is the sum of the individual gaps.

## Complexity Analysis

-   **Time Complexity**: $O(T)$
    The program processes $T$ test cases. For each test case, it performs a constant number of operations: two integer reads (`cin >> A >> B`), one addition (`A + B`), and one integer print (`cout << total_gap`). Since the number of operations per test case is constant, the total time complexity is directly proportional to the number of test cases, $T$.

-   **Space Complexity**: $O(1)$
    The program uses a fixed amount of memory regardless of the input values or the number of test cases. It declares a few integer variables (`T`, `A`, `B`, `total_gap`) to store the current test case's data. This memory usage does not grow with the input size, hence the space complexity is constant.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes most standard libraries

using namespace std; // Allows using standard library elements without the std:: prefix

int main() {
    // Optimize C++ standard streams for competitive programming.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams,
    // which can speed up I/O operations.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation,
    // further speeding up I/O.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare an integer variable 'T' to store the number of test cases.
    cin >> T; // Read the number of test cases from standard input.

    // Loop 'T' times, once for each test case.
    // The T-- decrements T after each iteration, and the loop continues as long as T is non-zero.
    while (T--) {
        int A, B; // Declare two integer variables 'A' and 'B' for the time gaps.
        cin >> A >> B; // Read the two space-separated integers A and B for the current test case.

        // The problem states that A is the time gap between Chef (3rd) and the runner-up (2nd),
        // and B is the time gap between the runner-up (2nd) and the winner (1st).
        // To find the total time gap between Chef and the winner, we simply add these two gaps.
        // Chef's time = Runner-up's time + A
        // Runner-up's time = Winner's time + B
        // Substituting the second into the first:
        // Chef's time = (Winner's time + B) + A
        // Chef's time - Winner's time = A + B
        int total_gap = A + B;

        // Print the calculated total_gap followed by a newline character.
        // The "\n" ensures that each output for a test case is on a new line,
        // as required by typical competitive programming output formats.
        cout << total_gap << "\n";
    }

    return 0; // Indicate successful program execution.
}
```