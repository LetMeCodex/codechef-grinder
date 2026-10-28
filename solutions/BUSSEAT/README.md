# [Bus Seating (BUSSEAT)](https://www.codechef.com/problems/BUSSEAT)
- **Difficulty Rating**: 640
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem describes a bus with `N` rows, and each row has two seats. `K` people are boarding the bus. The rule for seating is that people prefer to sit alone. This means if there's an empty row, a person will take one seat in that row, leaving the other seat empty. Only when all `N` rows have at least one person (i.e., are "half-full") and more people board, will they be forced to sit next to someone who is already seated. The task is to determine the total number of people who end up sitting next to someone else.

## Intuition & Mathematical Observation

Let's analyze the seating process based on the number of rows (`N`) and the number of people (`K`):

1.  **Each row has two seats.** This means a row can either be empty, have one person (sitting alone), or have two people (sitting next to each other).
2.  **People prefer to sit alone.** This is the primary rule. A person will always try to find an empty row first.

Now, consider two main cases:

*   **Case 1: `K <= N` (Number of people is less than or equal to the number of rows)**
    *   In this scenario, each of the `K` people can find a unique, entirely empty row.
    *   They will each take one seat in a different row, leaving the other seat in their respective rows empty.
    *   Since everyone gets to sit in their own row without anyone else, no one is forced to sit next to another person.
    *   Therefore, the total count of people sitting next to someone else is **0**.

*   **Case 2: `K > N` (Number of people is greater than the number of rows)**
    *   The first `N` people will follow the preference rule: each will occupy one seat in a different row. At this point, all `N` rows are "half-full" (one person per row), and no one is sitting next to anyone.
    *   There are `K - N` people remaining.
    *   These `K - N` people cannot find an empty row. They are forced to sit next to someone in an already occupied row.
    *   When one of these `K - N` people sits down next to someone, two people in that specific row are now sitting next to each other: the new person and their seatmate.
    *   Since each of the `K - N` remaining people will cause such an event, and each such event adds 2 people to the "sitting next to someone" count, the total count will be `2 * (K - N)`.

This logic covers all possibilities and directly leads to the solution.

## Complexity Analysis

*   **Time Complexity**: $O(T)$
    *   The program iterates `T` times, once for each test case.
    *   Inside the loop, it performs constant-time operations: reading two integers (`N`, `K`), a simple comparison (`K <= N`), a basic arithmetic operation (`K - N`), and printing the result.
    *   Thus, the total time complexity is directly proportional to the number of test cases, `T`.

*   **Space Complexity**: $O(1)$
    *   The program uses a fixed number of variables (`T`, `N`, `K`) regardless of the input values or the number of test cases.
    *   The memory usage does not grow with the input size.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes most standard libraries

using namespace std; // Use the standard namespace

int main() {
    // Fast I/O setup to speed up input and output operations.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases

    while (T--) { // Loop T times, processing each test case
        int N, K;
        cin >> N >> K; // Read N (number of rows) and K (number of people) for the current test case

        // Apply the derived logic:
        // If K (number of people) is less than or equal to N (number of rows),
        // every person can find an empty row and sit alone.
        // In this scenario, no one ends up sitting next to somebody else.
        if (K <= N) {
            cout << 0 << "\n"; // Output 0 as the count
        } 
        // If K (number of people) is greater than N (number of rows),
        // the first N people will occupy N distinct rows, making them half-full.
        // The remaining (K - N) people will not find any empty rows.
        // They must sit next to someone in an already occupied row.
        // Each time a person sits next to someone, two people (the new person and their seatmate)
        // are now sitting next to somebody else.
        // So, the total count is 2 times the number of people who were forced to sit next to someone.
        else {
            cout << 2 * (K - N) << "\n"; // Output 2 * (K - N) as the count
        }
    }

    return 0; // Indicate successful program execution
}
```