# [Elections in Chefland (ELECTN)](https://www.codechef.com/problems/ELECTN)
- **Difficulty Rating**: 604
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine the number of eligible voters in Chefland. We are given the total number of people (`N`) and a minimum age requirement (`X`) to be eligible to vote. Following this, the ages of all `N` people are provided. For each person, we need to check if their age is greater than or equal to `X`. If it is, they are an eligible voter. We must output the total count of eligible voters. This process needs to be repeated for multiple test cases.

## Intuition & Mathematical Observation

The core of this problem is a simple conditional check and counting.

1.  **Iterate through people**: We need to examine each person's age individually. Since there are `N` people, a loop that runs `N` times is appropriate.
2.  **Check eligibility**: For each person, we compare their age (`age`) with the minimum required age (`X`). The problem states "at least X years old", which translates directly to the condition `age >= X`.
3.  **Count eligible voters**: We maintain a counter, initialized to zero. Every time a person's age satisfies the eligibility condition (`age >= X`), we increment this counter.
4.  **Output**: After checking all `N` people, the final value of the counter represents the total number of eligible voters for that test case.

There are no complex mathematical observations or advanced algorithms required; it's a direct implementation of the given rules.

## Complexity Analysis

*   **Time Complexity**: $O(T \cdot N)$
    *   The program consists of an outer `while` loop that runs `T` times (for each test case).
    *   Inside each test case, there's a `for` loop that iterates `N` times (once for each person).
    *   Within the inner `for` loop, operations like reading an age, comparison (`age >= X`), and incrementing a counter are all constant time operations, $O(1)$.
    *   Therefore, for each test case, the time taken is proportional to `N`.
    *   The total time complexity is `T` (number of test cases) multiplied by `N` (number of people per test case), resulting in $O(T \cdot N)$.

*   **Space Complexity**: $O(1)$
    *   The program uses a fixed number of variables: `T`, `N`, `X`, `eligible_voters_count`, and `age`.
    *   These variables occupy a constant amount of memory regardless of the input size (`N` or `T`).
    *   No arrays, vectors, or other data structures are used to store input values (ages are processed one by one).
    *   Thus, the space complexity is constant, $O(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes most standard libraries, as requested

// Using the standard namespace to avoid writing std::repeatedly
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin from cout and disables synchronization with C's stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare an integer variable T for the number of test cases
    cin >> T; // Read the number of test cases

    // Loop through each test case
    while (T--) {
        int N; // Declare N for the number of people
        int X; // Declare X for the minimum voting age
        cin >> N >> X; // Read N and X for the current test case

        int eligible_voters_count = 0; // Initialize a counter for eligible voters

        // Loop N times to read the age of each person
        for (int i = 0; i < N; ++i) {
            int age; // Declare a variable to store the current person's age
            cin >> age; // Read the age of the current person

            // Check if the person's age meets the minimum requirement
            // A person needs to be "at least X years old", which means age >= X
            if (age >= X) {
                eligible_voters_count++; // If eligible, increment the counter
            }
        }

        // Output the total number of eligible voters for the current test case
        // Each output should be on a new line, as indicated by "\n"
        cout << eligible_voters_count << "\n";
    }

    return 0; // Indicate successful program execution
}
```