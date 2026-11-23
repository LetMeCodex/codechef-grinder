# [Lift Requests (LIFTME)](https://www.codechef.com/problems/LIFTME)
- **Difficulty Rating**: 1247
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to calculate the total number of floors traveled by a lift. The lift starts at floor 0 (ground floor). We are given `Q` requests. Each request consists of a source floor `f_i` and a destination floor `d_i`. For each request, the lift first travels from its current position to `f_i`, picks up the passenger, and then travels from `f_i` to `d_i`, dropping off the passenger. We need to sum up all these travel distances for all `Q` requests and output the total. The total number of floors `N` is also given, but it's largely irrelevant to the calculation of travel distance.

## Intuition & Mathematical Observation

The problem can be solved by directly simulating the lift's movement and accumulating the distances traveled.

1.  **Initial State**: The lift begins at `current_floor = 0`. We need a variable, `total_travel`, initialized to 0, to keep track of the cumulative distance. Since the total travel distance can be very large (up to $10^5$ requests, each potentially traveling $2 \times 10^9$ floors, leading to $2 \times 10^{14}$ total floors), `total_travel` must be a `long long` to prevent integer overflow.

2.  **Processing Each Request**: For each of the `Q` requests `(f_i, d_i)`:
    *   **Movement 1: To Source Floor**: The lift travels from its `current_floor` to the source floor `f_i`. The distance covered in this leg is `abs(f_i - current_floor)`. This distance is added to `total_travel`. After this movement, the lift is now at `f_i`, so we update `current_floor = f_i`.
    *   **Movement 2: To Destination Floor**: The lift then travels from its current position (which is now `f_i`) to the destination floor `d_i`. The distance covered in this leg is `abs(d_i - current_floor)` (or `abs(d_i - f_i)` since `current_floor` was just updated to `f_i`). This distance is also added to `total_travel`. After this movement, the lift is now at `d_i`, so we update `current_floor = d_i`.

3.  **Final Result**: After processing all `Q` requests, the value stored in `total_travel` will be the answer.

The number of floors `N` is a red herring; it does not affect the calculation of distances, as we only care about the absolute difference between floor numbers.

## Complexity Analysis

*   **Time Complexity**:
    *   For each test case, we read `N` and `Q` once.
    *   We then iterate `Q` times, once for each request.
    *   Inside the loop, we perform a constant number of operations: reading two integers, two `abs()` calls, two additions, and two assignments.
    *   Thus, for a single test case, the time complexity is $O(Q)$.
    *   Given `T` test cases, the total time complexity is $O(T \cdot Q)$.
    *   With $T \le 10$ and $Q \le 10^5$, the maximum number of operations is approximately $10 \times 10^5 = 10^6$, which is well within typical time limits for competitive programming (usually $10^8$ operations per second).

*   **Space Complexity**:
    *   We only use a few variables to store `N`, `Q`, `total_travel`, `current_floor`, `f_i`, and `d_i`. These are all constant in number and do not depend on the input size `N` or `Q`.
    *   Therefore, the space complexity is $O(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes most standard libraries, as requested by the problem statement.

using namespace std; // Uses the entire std namespace, as requested.

// Function to solve a single test case
void solve() {
    int N, Q;
    cin >> N >> Q; // Read N (number of floors) and Q (number of requests)

    long long total_travel = 0; // Use long long to prevent integer overflow, as total travel can be very large.
    int current_floor = 0;      // The lift starts at floor 0 (ground floor).

    // Process each of the Q requests sequentially
    for (int i = 0; i < Q; ++i) {
        int f_i, d_i;
        cin >> f_i >> d_i; // Read source floor (f_i) and destination floor (d_i) for the current request

        // First movement: Lift travels from its current_floor to the source floor f_i.
        // The distance traveled is the absolute difference between the current floor and f_i.
        total_travel += abs(f_i - current_floor);
        current_floor = f_i; // Update the lift's current position to f_i.

        // Second movement: Lift travels from the source floor f_i (which is now current_floor) to the destination floor d_i.
        // The distance traveled is the absolute difference between f_i and d_i.
        total_travel += abs(d_i - current_floor);
        current_floor = d_i; // Update the lift's current position to d_i.
    }

    // After serving all requests, print the total number of floors traveled.
    cout << total_travel << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) {  // Loop T times, once for each test case
        solve();   // Call the solve function for each test case
    }

    return 0; // Indicate successful program execution.
}
```