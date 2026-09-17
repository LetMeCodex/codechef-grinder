# [Tyre problem (TYRE)](https://www.codechef.com/problems/TYRE)
- **Difficulty Rating**: 452
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to calculate the total number of tyres required for a given number of bikes and cars. We are provided with two integers, $N$ representing the number of bikes and $M$ representing the number of cars. We know that each bike has 2 tyres and each car has 4 tyres. The task is to find the sum of tyres for all bikes and all cars. This calculation needs to be performed for multiple test cases.

## Intuition & Mathematical Observation

The problem is a simple arithmetic calculation. We need to determine the total number of tyres based on the fixed number of tyres per vehicle type.

1.  **Tyres for Bikes**: If there are $N$ bikes, and each bike has 2 tyres, the total number of tyres contributed by bikes will be $N \times 2$.
2.  **Tyres for Cars**: If there are $M$ cars, and each car has 4 tyres, the total number of tyres contributed by cars will be $M \times 4$.
3.  **Total Tyres**: To get the grand total, we simply sum the tyres from bikes and cars: $(N \times 2) + (M \times 4)$.

This formula can be directly applied for each test case. No complex data structures or algorithms are required.

## Complexity Analysis

-   **Time Complexity**: $O(T)$
    For each test case, we perform a constant number of operations: two multiplications, one addition, and one output operation. These operations take constant time, $O(1)$. Since there are $T$ test cases, the total time complexity will be $T \times O(1)$, which simplifies to $O(T)$.

-   **Space Complexity**: $O(1)$
    We only use a few integer variables to store the number of test cases ($t$), the number of bikes ($n$), the number of cars ($m$), and the calculated total tyres ($total\_tyres$). The memory used by these variables is constant and does not depend on the input values $N$ or $M$. Therefore, the space complexity is $O(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Required include for competitive programming

// Required namespace
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; // Declare an integer variable 't' to store the number of test cases.
    cin >> t; // Read the number of test cases from standard input.

    // Loop through each test case. The 't--' decrements 't' after each iteration
    // and the loop continues as long as 't' is greater than 0.
    while (t--) {
        int n, m; // Declare integer variables 'n' for bikes and 'm' for cars.
        cin >> n >> m; // Read the number of bikes (N) and cars (M) for the current test case.

        // Calculate the total number of tyres.
        // Each bike has 2 tyres, so N bikes have N * 2 tyres.
        // Each car has 4 tyres, so M cars have M * 4 tyres.
        // The total is the sum of tyres from bikes and cars.
        int total_tyres = (n * 2) + (m * 4);

        // Output the calculated total number of tyres for the current test case.
        // A newline character ("\n") is appended to ensure each output is on a new line,
        // as required by the output format.
        cout << total_tyres << "\n";
    }

    return 0; // Indicate successful program execution.
}
```