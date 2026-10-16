# [Chef and the Hair Salon (CHEFBARBER)](https://www.codechef.com/problems/CHEFBARBER)
- **Difficulty Rating**: 895
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to calculate the total waiting time for Chef at a hair salon. We are given two integers: `N`, the number of customers already waiting in line, and `M`, the time (in minutes) it takes for a single customer to get a haircut. Chef arrives when these `N` customers are already present. We need to determine how many minutes Chef will have to wait before it's their turn. It's implied that only one barber is working, meaning only one customer can be served at a time.

## Intuition & Mathematical Observation

The core of this problem lies in understanding that Chef must wait for all the customers ahead of them to finish their haircuts.

1.  **Sequential Service**: The problem implies a single barber, so customers are served one by one.
2.  **Customers Ahead**: When Chef arrives, there are `N` customers already waiting. Chef will be the `(N+1)`-th person in line.
3.  **Time per Customer**: Each of these `N` customers takes `M` minutes to get a haircut.
4.  **Total Waiting Time**: To find the total time Chef has to wait, we simply need to sum up the time taken by each of the `N` customers ahead. Since each takes `M` minutes, and there are `N` such customers, the total time is `N` multiplied by `M`.

Therefore, the waiting time for Chef is `N * M`.

## Complexity Analysis

*   **Time Complexity**: $O(T)$
    *   The program iterates `T` times, once for each test case.
    *   Inside the loop, it performs a constant number of operations: reading two integers (`N`, `M`), a single multiplication (`N * M`), and printing the result. These operations take constant time, $O(1)$.
    *   Thus, the total time complexity is proportional to the number of test cases, $O(T)$.

*   **Space Complexity**: $O(1)$
    *   The program uses a few integer variables (`T`, `N`, `M`, `waiting_time`) to store input and intermediate results. The amount of memory used by these variables is constant and does not depend on the input values `N` or `M`, or the number of test cases `T`.
    *   Therefore, the space complexity is constant, $O(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries, common in competitive programming

// Use the standard namespace to avoid writing std:: repeatedly
using namespace std;

int main() {
    // Optimize C++ standard streams for competitive programming.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams,
    // which can speed up I/O operations significantly.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation,
    // further improving I/O performance.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare an integer variable T for the number of test cases
    cin >> T; // Read the number of test cases from standard input

    // Loop T times, once for each test case
    while (T--) {
        int N, M; // Declare integers N (number of customers waiting) and M (minutes per customer)
        cin >> N >> M; // Read N and M for the current test case from standard input

        // Calculate the total waiting time for Chef.
        // Chef arrives after N customers are already waiting.
        // Since each customer takes M minutes and only one person can get a haircut at a time,
        // Chef must wait for all N customers to finish.
        // The total time taken for N customers is N multiplied by M.
        int waiting_time = N * M;

        // Print the calculated waiting time to standard output,
        // followed by a newline character. Using "\n" is generally preferred
        // over `endl` in competitive programming for performance reasons,
        // as `endl` also forces a flush of the output buffer.
        cout << waiting_time << "\n";
    }

    return 0; // Indicate successful execution of the program
}
```