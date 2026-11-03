# [Cooler (COOLER7)](https://www.codechef.com/problems/COOLER7)
- **Difficulty Rating**: 555
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to calculate the total time required to reduce the temperature of a room from an initial $N$ degrees Celsius to a target $M$ degrees Celsius. The key information given is that it takes $X$ minutes to reduce the temperature from $X$ degrees Celsius to $X-1$ degrees Celsius. We are given $T$ test cases, and for each test case, we need to output the total time.

Constraints:
- $1 \le T \le 1000$
- $1 \le M < N \le 40$

## Intuition & Mathematical Observation

Let's break down the cooling process step by step:
1. To reduce the temperature from $N$ degrees to $N-1$ degrees, it takes $N$ minutes.
2. To reduce the temperature from $N-1$ degrees to $N-2$ degrees, it takes $N-1$ minutes.
3. This pattern continues until we reach the target temperature $M$.
4. The last step will be reducing the temperature from $M+1$ degrees to $M$ degrees, which takes $M+1$ minutes.

So, the total time required is the sum of minutes for each 1-degree drop:
$Total Time = N + (N-1) + (N-2) + \dots + (M+1)$

This is an arithmetic series. We can express this sum using the formula for the sum of the first $k$ natural numbers, which is $\sum_{i=1}^{k} i = \frac{k(k+1)}{2}$.

Our sum $N + (N-1) + \dots + (M+1)$ can be seen as the sum of all integers from $1$ to $N$, minus the sum of all integers from $1$ to $M$.
$\sum_{i=M+1}^{N} i = \left( \sum_{i=1}^{N} i \right) - \left( \sum_{i=1}^{M} i \right)$

Applying the sum formula:
$Total Time = \frac{N(N+1)}{2} - \frac{M(M+1)}{2}$

Given the constraints ($N \le 40$), the maximum value for $N(N+1)/2$ would be for $N=40$: $40 \times 41 / 2 = 820$. This value easily fits within a standard `int` data type. However, using `long long` for intermediate products like `N * (N + 1)` is a good practice to prevent potential overflow in competitive programming, especially if $N$ were much larger. For this problem, it's not strictly necessary but harmless.

## Complexity Analysis

-   **Time Complexity**: For each test case, we perform a constant number of arithmetic operations (multiplications, additions, divisions, subtractions). These operations take constant time. Since there are $T$ test cases, the total time complexity is directly proportional to the number of test cases.
    Therefore, the time complexity is $O(T)$.

-   **Space Complexity**: We use a few variables to store the number of test cases ($T$), the initial and target temperatures ($N$, $M$), and the calculated sums and total minutes. The amount of memory used by these variables is constant and does not depend on the input values $N$ or $M$.
    Therefore, the space complexity is $O(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes most standard libraries, as requested.

// Using the standard namespace to avoid writing std:: repeatedly.
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams,
    // which can be slower due to synchronization with C's stdio.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation,
    // further speeding up I/O.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare an integer variable T for the number of test cases.
    cin >> T; // Read the number of test cases from standard input.

    // Loop T times, processing one test case in each iteration.
    while (T--) {
        int N, M; // Declare integer variables N (current temperature) and M (target temperature).
        cin >> N >> M; // Read N and M for the current test case.

        // The problem states that it takes X minutes to drop the temperature
        // from X degrees Celsius to X-1 degrees Celsius.
        // We need to find the total time to drop from N degrees to M degrees.
        // This means we sum the minutes for each 1-degree drop:
        // From N to N-1: N minutes
        // From N-1 to N-2: N-1 minutes
        // ...
        // From M+1 to M: M+1 minutes
        //
        // The total time is the sum: N + (N-1) + ... + (M+1).
        // This is an arithmetic series.
        // The sum of integers from 1 to K is given by the formula: K * (K + 1) / 2.
        //
        // So, the sum N + (N-1) + ... + (M+1) can be calculated as:
        // (Sum of integers from 1 to N) - (Sum of integers from 1 to M)
        // = (N * (N + 1) / 2) - (M * (M + 1) / 2)

        // Calculate the sum of integers from 1 to N.
        // We use `long long` for the intermediate product `N * (N + 1)`
        // to prevent potential integer overflow, although for N <= 40,
        // `int` would be sufficient as 40 * 41 = 1640 fits in an int.
        long long sum_up_to_N = (long long)N * (N + 1) / 2;

        // Calculate the sum of integers from 1 to M.
        long long sum_up_to_M = (long long)M * (M + 1) / 2;

        // The total minutes required is the difference between these two sums.
        long long total_minutes = sum_up_to_N - sum_up_to_M;

        // Print the calculated total minutes for the current test case,
        // followed by a newline character for proper formatting.
        cout << total_minutes << "\n";
    }

    return 0; // Indicate successful execution of the program.
}
```