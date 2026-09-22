# [Self Defence Training (SELFDEF)](https://www.codechef.com/problems/SELFDEF)
- **Difficulty Rating**: 716
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine the number of eligible participants for a self-defence training camp. We are given $N$ participants, and for each participant, their age $A_i$. A person is considered eligible if their age is strictly greater than 9 and strictly less than 61. This means an eligible person must have an age $A_i$ such that $10 \le A_i \le 60$. We need to output the total count of eligible participants for each test case.

## Intuition & Mathematical Observation

The problem is a straightforward counting task. We need to iterate through each participant's age and apply a simple conditional check.

The eligibility condition is clearly defined:
1. Age must be strictly greater than 9 ($A_i > 9$).
2. Age must be strictly less than 61 ($A_i < 61$).

Combining these two conditions, a participant is eligible if their age $A_i$ satisfies $10 \le A_i \le 60$.

Our approach will be:
1. Initialize a counter for eligible participants to zero.
2. For each participant, read their age.
3. Check if the age falls within the range $[10, 60]$ (inclusive).
4. If it does, increment the counter.
5. After checking all participants, print the final count.

There are no complex mathematical observations or tricky edge cases beyond directly implementing this condition.

## Complexity Analysis

-   **Time Complexity**: $O(N)$ per test case, or $O(\sum N)$ over all test cases.
    For each test case, we iterate through $N$ participants. Inside the loop, we perform a constant number of operations (reading an integer, two comparisons, and potentially an increment). Thus, the time taken is directly proportional to the number of participants $N$. If there are $T$ test cases and $N_i$ participants in the $i$-th test case, the total time complexity is $O(\sum_{i=1}^{T} N_i)$.

-   **Space Complexity**: $O(1)$
    We only use a few integer variables to store the number of test cases (`t`), number of participants (`n`), the current participant's age (`age`), and the count of eligible participants (`eligible_count`). These variables occupy a constant amount of memory regardless of the input size $N$. We do not store all ages in an array or any data structure that scales with $N$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes common headers like iostream

// Use the standard namespace to avoid writing std:: repeatedly
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
    // until 't' becomes 0.
    while (t--) {
        int n; // Declare an integer variable 'n' to store the number of participants
               // for the current test case.
        cin >> n; // Read the number of participants.

        int eligible_count = 0; // Initialize a counter for eligible participants to 0.

        // Loop 'n' times, once for each participant.
        for (int i = 0; i < n; ++i) {
            int age; // Declare an integer variable 'age' to store the current participant's age.
            cin >> age; // Read the age of the current participant.

            // Check the eligibility condition:
            // Age must be strictly greater than 9 (age >= 10)
            // AND strictly less than 61 (age <= 60).
            if (age >= 10 && age <= 60) {
                eligible_count++; // If eligible, increment the counter.
            }
        }
        // After checking all participants for the current test case, print the total
        // number of eligible participants followed by a newline character.
        cout << eligible_count << "\n";
    }

    return 0; // Indicate that the program executed successfully.
}

```