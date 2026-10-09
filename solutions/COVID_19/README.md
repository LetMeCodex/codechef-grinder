# Covid and Theatre Tickets (COVID_19)

- **Difficulty Rating**: 1077
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to calculate the maximum number of tickets that can be sold for a theatre with $N$ rows and $M$ seats per row, subject to two conditions:
1. Within any given row, there must be at least one empty seat between any two occupied seats.
2. Between any two rows that have people seated, there must be at least one completely empty row.

## Intuition & Mathematical Observation

Let's break down the problem by considering the constraints on seating arrangements.

**Constraint 1: Within a row**

Consider a single row with $M$ seats. To maximize the number of people in this row while ensuring at least one empty seat between them, we should place people in seats 1, 3, 5, and so on.

*   If $M=1$, we can seat 1 person.
*   If $M=2$, we can seat 1 person (e.g., in seat 1).
*   If $M=3$, we can seat 2 people (e.g., in seats 1 and 3).
*   If $M=4$, we can seat 2 people (e.g., in seats 1 and 3).
*   If $M=5$, we can seat 3 people (e.g., in seats 1, 3, and 5).

This pattern suggests that the maximum number of people we can seat in a row of $M$ seats is $\lceil M/2 \rceil$. In integer arithmetic, this can be calculated as `(M + 1) / 2`.

**Constraint 2: Between rows**

Now consider the $N$ rows. To maximize the number of rows that can have people seated, we must ensure at least one empty row between any two occupied rows. This means we can use rows 1, 3, 5, and so on.

*   If $N=1$, we can use 1 row.
*   If $N=2$, we can use 1 row (either row 1 or row 2).
*   If $N=3$, we can use 2 rows (rows 1 and 3).
*   If $N=4$, we can use 2 rows (rows 1 and 3, or rows 1 and 4, or rows 2 and 4). The maximum is 2.
*   If $N=5$, we can use 3 rows (rows 1, 3, and 5).

This pattern suggests that the maximum number of rows we can use for seating people is $\lceil N/2 \rceil$. In integer arithmetic, this can be calculated as `(N + 1) / 2`.

**Combining the Constraints**

To find the total maximum number of tickets, we multiply the maximum number of active rows by the maximum number of people that can be seated in each of those active rows.

Maximum tickets = (Maximum active rows) $\times$ (Maximum people per row)
Maximum tickets = $\lceil N/2 \rceil \times \lceil M/2 \rceil$
Maximum tickets = `((N + 1) / 2) * ((M + 1) / 2)`

The problem constraints state that $N$ and $M$ are at most 100.
The maximum number of active rows would be `(100 + 1) / 2 = 50`.
The maximum number of people per row would be `(100 + 1) / 2 = 50`.
The total tickets would be at most $50 \times 50 = 2500$. This value fits within a standard `int` data type. However, using `long long` for the total tickets is a good practice to avoid potential overflow issues in similar problems with larger constraints.

## Complexity Analysis

*   **Time Complexity**: $O(1)$
    For each test case, we perform a constant number of arithmetic operations (reading input, calculating the result, and printing). The number of test cases $T$ is processed linearly, but the work per test case is constant.

*   **Space Complexity**: $O(1)$
    We only use a few variables to store the input values and the result. The memory usage does not depend on the input size $N$ or $M$.

## Solution Code

```cpp
#include <bits/stdc++.h>

// The problem statement explicitly asks for using namespace std;
using namespace std;

int main() {
    // The problem statement explicitly asks for fast I/O inside main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases

    // Loop T times for each test case
    while (T--) {
        int N, M;
        cin >> N >> M; // Read N (number of rows) and M (seats per row)

        // Guideline 1: Within a row, there must be at least one empty seat between people.
        // To maximize people in a row, we seat them at positions 1, 3, 5, ...
        // For M seats, the number of people that can be seated is ceil(M/2).
        // In integer arithmetic, (M + 1) / 2 achieves this.
        // Example: M=1 -> (1+1)/2 = 1; M=2 -> (2+1)/2 = 1; M=3 -> (3+1)/2 = 2; M=4 -> (4+1)/2 = 2; M=5 -> (5+1)/2 = 3.
        int max_people_per_row = (M + 1) / 2;

        // Guideline 2: Between rows, there must be at least one completely empty row.
        // To maximize the number of rows with people, we choose rows 1, 3, 5, ...
        // For N rows, the number of active rows (rows with people) is ceil(N/2).
        // In integer arithmetic, (N + 1) / 2 achieves this.
        // Example: N=1 -> (1+1)/2 = 1; N=2 -> (2+1)/2 = 1; N=3 -> (3+1)/2 = 2; N=4 -> (4+1)/2 = 2; N=5 -> (5+1)/2 = 3.
        int max_active_rows = (N + 1) / 2;

        // The total maximum number of tickets is the product of the maximum active rows
        // and the maximum people that can be seated in each of those active rows.
        // The maximum possible value for N, M is 100.
        // max_active_rows <= (100+1)/2 = 50.
        // max_people_per_row <= (100+1)/2 = 50.
        // Total tickets <= 50 * 50 = 2500, which fits comfortably in an 'int'.
        // Using 'long long' for total_tickets is a safe practice, though not strictly necessary here.
        long long total_tickets = (long long)max_active_rows * max_people_per_row;

        // Output the result followed by a newline, as requested.
        cout << total_tickets << "\n";
    }

    return 0;
}
```