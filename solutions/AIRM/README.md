# [Airport Management (AIRM)](https://www.codechef.com/problems/AIRM)
- **Difficulty Rating**: 1201
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine the minimum number of runways an airport needs to handle `N` airplanes. For each airplane, we are given its arrival time `A_i` and departure time `D_i`. All times are given in minutes from midnight (0 to 1439). The crucial detail is how runway usage is defined: "An airplane arriving at minute `t` and departing at minute `t` uses a runway at minute `t`." This implies that a runway is needed *only* at the exact minute of arrival and the exact minute of departure, not for the entire duration a plane is on the ground. We need to find the maximum number of runways simultaneously required at any single minute.

## Intuition & Mathematical Observation

The problem statement simplifies the concept of runway usage significantly. Instead of tracking intervals (from arrival to departure), we only care about discrete events: an arrival at minute `t` or a departure at minute `t`.

To find the minimum number of runways required, we need to identify the minute `t` where the demand for runways is highest. At any given minute `t`, the number of runways needed is simply the sum of:
1. The number of airplanes arriving at minute `t`.
2. The number of airplanes departing at minute `t`.

This is because each arrival event at minute `t` requires one runway, and each departure event at minute `t` requires one runway. If multiple planes arrive or depart at the same minute, they each contribute to the demand for runways at that specific minute.

Therefore, the strategy is:
1. Create two frequency arrays (or hash maps), one for arrivals and one for departures. Let's call them `arrivals_at_time` and `departures_at_time`. These arrays will store counts for each minute from 0 to 1439.
2. Iterate through all `N` airplanes. For each airplane `i` with arrival `A_i` and departure `D_i`:
    - Increment `arrivals_at_time[A_i]`.
    - Increment `departures_at_time[D_i]`.
3. Initialize a variable `max_runways_needed` to 0.
4. Iterate through all possible minutes `t` from 0 to 1439. For each minute `t`:
    - Calculate `current_runways_needed = arrivals_at_time[t] + departures_at_time[t]`.
    - Update `max_runways_needed = max(max_runways_needed, current_runways_needed)`.
5. The final value of `max_runways_needed` will be the answer.

The maximum possible time is 1439 (23 hours and 59 minutes). So, our frequency arrays need to be of size 1440 to cover minutes 0 through 1439.

## Complexity Analysis

-   **Time Complexity**:
    -   Reading `N` arrival times: $O(N)$
    -   Reading `N` departure times: $O(N)$
    -   Populating the `arrivals_at_time` and `departures_at_time` frequency arrays: This involves iterating through `N` airplanes, performing constant time operations (array access and increment) for each. So, $O(N)$.
    -   Iterating through all possible minutes (0 to 1439) to find the maximum runway demand: The number of minutes is a constant (1440). This step takes $O(\text{MAX_TIME_MINUTE})$ time.
    -   Combining these, the total time complexity is $O(N + \text{MAX_TIME_MINUTE})$. Since `MAX_TIME_MINUTE` is a constant (1440), this simplifies to $O(N)$. Given $N \le 10^5$, this is very efficient.

-   **Space Complexity**:
    -   Storing `N` arrival times in vector `A`: $O(N)$
    -   Storing `N` departure times in vector `D`: $O(N)$
    -   Storing `arrivals_at_time` frequency array: $O(\text{MAX_TIME_MINUTE})$
    -   Storing `departures_at_time` frequency array: $O(\text{MAX_TIME_MINUTE})$
    -   Combining these, the total space complexity is $O(N + \text{MAX_TIME_MINUTE})$. Since `MAX_TIME_MINUTE` is a constant, this simplifies to $O(N)$. Given $N \le 10^5$, this is well within typical memory limits.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes iostream, vector, algorithm, etc.

// Use the standard namespace to avoid prefixing std::
using namespace std;

// Function to solve a single test case
void solve() {
    int N;
    cin >> N; // Read the number of airplanes

    // Read arrival timings
    // We store them in a vector first. An alternative is to read and
    // immediately update the frequency array, but storing is also fine.
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // Read departure timings
    vector<int> D(N);
    for (int i = 0; i < N; ++i) {
        cin >> D[i];
    }

    // The maximum possible time is 1439 (minutes after midnight).
    // So, we need arrays that can store counts for times 0 through 1439.
    // An array of size 1440 will have indices 0 to 1439.
    const int MAX_TIME_MINUTE = 1440; 
    
    // arrivals_at_time[t] stores the number of planes arriving at minute t.
    vector<int> arrivals_at_time(MAX_TIME_MINUTE, 0);
    // departures_at_time[t] stores the number of planes departing at minute t.
    vector<int> departures_at_time(MAX_TIME_MINUTE, 0);

    // Populate the frequency arrays
    // For each airplane, increment the count for its arrival and departure minute.
    for (int i = 0; i < N; ++i) {
        arrivals_at_time[A[i]]++;
        departures_at_time[D[i]]++;
    }

    int max_runways = 0; // This will store the maximum number of runways needed at any single minute

    // Iterate through all possible minutes from 0 to MAX_TIME_MINUTE - 1 (i.e., 0 to 1439)
    for (int t = 0; t < MAX_TIME_MINUTE; ++t) {
        // At minute 't', the number of runways needed is the sum of
        // planes arriving at 't' and planes departing at 't'.
        int current_runways_needed = arrivals_at_time[t] + departures_at_time[t];
        
        // Update the maximum runways needed if the current minute requires more.
        max_runways = max(max_runways, current_runways_needed);
    }
    
    // Output the minimum number of runways required for this test case.
    cout << max_runways << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams,
    // allowing them to operate independently and often faster.
    // cin.tie(NULL) prevents cout from being flushed before each cin operation,
    // which can further speed up I/O in competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) {
        solve(); // Solve each test case
    }

    return 0;
}
```