# [Vishesh and his Popcorn Combo (POPCORN)](https://www.codechef.com/problems/POPCORN)
- **Difficulty Rating**: 990
- **Solved in**: 2 attempt(s)

## Problem Summary

The problem asks us to help Vishesh choose the best popcorn combo at a movie theatre. There are three combos available: Combo A, Combo B, and Combo C. Each combo consists of two items, and we are given the preparation time for each of these two items. Vishesh believes that a longer total preparation time means more satisfaction. Our task is to determine the maximum total preparation time Vishesh can achieve by choosing one of the three combos. We need to do this for multiple test cases.

**Input:**
- An integer `T`, the number of test cases.
- For each test case:
    - Two integers `A1`, `A2` (preparation times for Combo A's items).
    - Two integers `B1`, `B2` (preparation times for Combo B's items).
    - Two integers `C1`, `C2` (preparation times for Combo C's items).

**Output:**
- For each test case, print the maximum total preparation time among the three combos.

**Constraints:**
- $1 \le T \le 1000$
- $1 \le A_1, A_2, B_1, B_2, C_1, C_2 \le 100$

## Intuition & Mathematical Observation

The problem statement directly tells us that Vishesh wants the combo with the "maximum total time to prepare". This simplifies the problem significantly. For each combo, we simply need to calculate its total preparation time by summing the times of its two items. Once we have the total preparation times for all three combos, we then find the largest among these three sums.

Let's denote the preparation times for Combo A as $A_1$ and $A_2$. Its total preparation time will be $S_A = A_1 + A_2$.
Similarly, for Combo B, $S_B = B_1 + B_2$.
And for Combo C, $S_C = C_1 + C_2$.

The problem then reduces to finding the maximum value among $S_A$, $S_B$, and $S_C$.
Mathematically, we need to compute $\max(S_A, S_B, S_C)$.

There are no complex algorithms, data structures, or advanced mathematical concepts required. It's a straightforward application of addition and comparison operations.

## Complexity Analysis

Given the constraints: $1 \le T \le 1000$ and $1 \le A_1, A_2, B_1, B_2, C_1, C_2 \le 100$.

-   **Time Complexity**: $O(T)$
    For each test case, the operations performed are:
    1.  Reading 6 integer values: This is a constant number of operations.
    2.  Calculating 3 sums (e.g., `A1 + A2`): This involves 3 additions, a constant number of operations.
    3.  Finding the maximum of 3 values: This involves at most 2 comparisons, a constant number of operations.
    4.  Printing the result: A constant number of operations.
    Since all operations per test case take constant time, the total time complexity for $T$ test cases will be $T \times O(1) = O(T)$.

-   **Space Complexity**: $O(1)$
    For each test case, we declare a fixed number of variables to store the input values (`A1`, `A2`, `B1`, `B2`, `C1`, `C2`), their sums (`satisfactionA`, `satisfactionB`, `satisfactionC`), and the maximum sum (`maxSatisfaction`). The number of these variables does not depend on the magnitude of the input values or the number of test cases (beyond storing `T` itself). Thus, the memory usage remains constant regardless of the input size.

## Solution Code

```cpp
#include <iostream> // Required for input/output operations (cin, cout)
#include <algorithm> // Required for std::max

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming to prevent TLE on large inputs.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T; // Declare an integer variable T to store the number of test cases
    std::cin >> T; // Read the value of T from the input

    // Loop T times, once for each test case
    while (T--) {
        // Declare long long variables for combo A's times.
        // Although problem constraints (up to 100) mean 'int' would suffice,
        // 'long long' is a safe practice in competitive programming to prevent
        // potential overflow issues with larger constraints.
        long long A1, A2; 
        std::cin >> A1 >> A2; // Read A1 and A2
        long long satisfactionA = A1 + A2; // Calculate satisfaction for combo A

        long long B1, B2; // Declare long long variables for combo B's times
        std::cin >> B1 >> B2; // Read B1 and B2
        long long satisfactionB = B1 + B2; // Calculate satisfaction for combo B

        long long C1, C2; // Declare long long variables for combo C's times
        std::cin >> C1 >> C2; // Read C1 and C2
        long long satisfactionC = C1 + C2; // Calculate satisfaction for combo C

        // Find the maximum satisfaction among the three combos.
        // std::max can take an initializer list {val1, val2, val3} in C++11 and later,
        // which is convenient for finding the maximum of more than two values.
        long long maxSatisfaction = std::max({satisfactionA, satisfactionB, satisfactionC});

        std::cout << maxSatisfaction << std::endl; // Print the maximum satisfaction followed by a newline
    }

    return 0; // Indicate successful program execution
}
```