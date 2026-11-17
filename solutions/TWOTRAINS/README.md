# [Two Trains (TWOTRAINS)](https://www.codechef.com/problems/TWOTRAINS)
- **Difficulty Rating**: 1230
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem describes two trains, A and B, that need to travel from station 1 to station N. There are `N-1` segments between stations. For each segment `i` (from station `i` to station `i+1`), a travel time `P_i` is given. Both trains start at station 1 at time 0.

The crucial constraint is that **Train B cannot depart from station `i` to station `i+1` until Train A has already arrived at station `i+1`**. Train A travels without any such restrictions. The goal is to find the minimum time Train B arrives at station N.

## Intuition & Mathematical Observation

Let's track the arrival times of both trains at each station.

1.  **Train A's Movement**: Train A travels without any constraints. Its arrival time at station `k+1` is simply its arrival time at station `k` plus the travel time `P_k` for that segment. We can maintain a running sum for Train A's arrival times.

2.  **Train B's Movement and the Constraint**: This is the core of the problem.
    *   Suppose Train B arrives at station `k` at time `arrival_B[k]`.
    *   Train B wants to depart from station `k` to station `k+1`.
    *   The constraint states that Train B cannot depart from station `k` until Train A has arrived at station `k+1`. Let `arrival_A[k+1]` be the time Train A arrives at station `k+1`.
    *   Therefore, Train B must wait until the later of two events:
        1.  It arrives at station `k` (`arrival_B[k]`).
        2.  Train A arrives at station `k+1` (`arrival_A[k+1]`).
    *   So, Train B's departure time from station `k` is `max(arrival_B[k], arrival_A[k+1])`.
    *   After departing, Train B travels for `P_k` time to reach station `k+1`.
    *   Thus, Train B's arrival time at station `k+1` is `arrival_B[k+1] = max(arrival_B[k], arrival_A[k+1]) + P_k`.

**Optimized Approach (using only current states):**

We don't need to store all arrival times in arrays. We can use two variables to keep track of the current state:
*   `current_time_A`: Represents the time Train A arrives at the *next* station in the sequence.
*   `current_time_B`: Represents the time Train B arrives at the *current* station.

Let's trace this for a segment from station `i` to `i+1` with travel time `p_val`:

*   **Initialization**: Both trains start at station 1 at time 0. So, `current_time_A = 0` and `current_time_B = 0`.
*   **Loop for `N-1` segments**:
    *   Read `p_val` (travel time from station `i` to `i+1`).
    *   **Update Train A**: Train A travels from station `i` to `i+1`. Its arrival time at station `i+1` will be its previous arrival time at station `i` plus `p_val`.
        *   `current_time_A = current_time_A + p_val;`
        *   *(After this step, `current_time_A` holds Train A's arrival time at station `i+1`.)*
    *   **Update Train B**: Train B is currently at station `i` (arrived at `current_time_B`). It wants to depart for station `i+1`. It must wait until Train A has arrived at station `i+1` (which is `current_time_A` after its update).
        *   Train B's departure time from station `i` is `max(current_time_B, current_time_A)`.
        *   Train B's arrival time at station `i+1` will be its departure time plus `p_val`.
        *   `current_time_B = std::max(current_time_B, current_time_A) + p_val;`
        *   *(After this step, `current_time_B` holds Train B's arrival time at station `i+1`.)*

After iterating through all `N-1` segments, `current_time_B` will hold the final arrival time of Train B at station N.

## Complexity Analysis

*   **Time Complexity**: $O(N)$
    *   For each test case, the solution iterates `N-1` times in a `for` loop. Inside the loop, operations like reading input, addition, and `std::max` are all constant time operations ($O(1)$).
    *   Since there are `T` test cases, the total time complexity is $O(T \cdot N)$. Given the constraints (`N` up to $10^5$, `T` up to $10^5$, but `T * N` up to $2 \cdot 10^5$), this approach is efficient enough.

*   **Space Complexity**: $O(1)$
    *   The solution uses a fixed number of variables (`n`, `current_time_A`, `current_time_B`, `p_val`, `t`) regardless of the input size `N`. No arrays or dynamic data structures are used.
    *   This makes the space complexity constant.

## Solution Code

```cpp
#include <iostream> // Required for std::cin, std::cout
#include <algorithm> // Required for std::max

// Function to solve a single test case
void solve() {
    int n;
    std::cin >> n; // Read the number of stations

    long long current_time_A = 0; // Tracks the arrival time of Train A at the *next* station.
                                  // Initially, A is at station 1 at time 0.
    long long current_time_B = 0; // Tracks the arrival time of Train B at the *current* station.
                                  // Initially, B is at station 1 at time 0.

    // The loop iterates N-1 times, corresponding to the N-1 segments between stations.
    // P_i denotes the time to travel from station i to station i+1.
    // In each iteration, we process one P_value, moving trains from station `k` to `k+1`.
    // `k` goes from 1 to N-1.
    for (int i = 0; i < n - 1; ++i) {
        int p_val;
        std::cin >> p_val; // Read P_{i+1} (using 0-indexed loop variable for convenience)

        // Train A's movement:
        // Train A travels from station (i+1) to (i+2) (using 1-indexed station numbers).
        // `current_time_A` currently holds the time A reached station (i+1).
        // After adding `p_val`, `current_time_A` will hold the time A reaches station (i+2).
        current_time_A += p_val;

        // Train B's movement:
        // Train B is currently at station (i+1) at `current_time_B`.
        // It wants to depart from station (i+1) to go to station (i+2).
        // The safety constraint: B cannot depart from station (i+1) unless A has already reached station (i+2).
        // A reaches station (i+2) at `current_time_A`.
        // So, B must wait until `current_time_A` if it arrives earlier.
        // The departure time for B from station (i+1) is `max(current_time_B, current_time_A)`.
        // After departing, B travels for `p_val` time to reach station (i+2).
        // So, `current_time_B` is updated to B's arrival time at station (i+2).
        current_time_B = std::max(current_time_B, current_time_A) + p_val;
    }

    // After the loop, `current_time_B` holds the time Train B reaches station N.
    std::cout << current_time_B << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common competitive programming optimization.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t; // Read the number of test cases
    while (t--) {
        solve(); // Solve each test case
    }

    return 0;
}
```