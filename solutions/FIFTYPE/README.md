# [Chef and Battery  (FIFTYPE)](https://www.codechef.com/problems/FIFTYPE)
- **Difficulty Rating**: 901
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to find the minimum time required to reach exactly 50% battery level, starting from an initial battery level `N`. In one minute, we have two options:
1. **Charge the phone**: The battery level increases by 2%.
2. **Use the phone**: The battery level decreases by 3%.

The battery level must always remain between 0% and 100% (inclusive). We need to output the minimum time for each test case.

## Intuition & Mathematical Observation

This problem is a classic shortest path problem on an unweighted graph. We are looking for the minimum number of "steps" (minutes) to go from a starting state (`N`) to a target state (50%). Each step has a cost of 1 minute. Breadth-First Search (BFS) is the ideal algorithm for finding the shortest path in terms of the number of edges in an unweighted graph.

Let's define our graph:
- **Nodes**: Each possible battery level from 0% to 100% is a node in our graph. There are 101 such nodes.
- **Edges**: From any given battery level `L`, we can transition to:
    - `L + 2` (by charging), if `L + 2 <= 100`.
    - `L - 3` (by using), if `L - 3 >= 0`.
    Each transition represents an edge with a weight of 1 (1 minute).

The BFS algorithm will explore states layer by layer, guaranteeing that the first time we reach the target state (50%), it will be via the shortest possible path.

**Algorithm Steps:**
1.  **Base Case**: If the initial battery level `N` is already 50%, the time taken is 0.
2.  **Initialization**:
    *   Create a queue for BFS, storing pairs of `{battery_level, time_taken}`.
    *   Create a `dist` array (or vector) of size 101, initialized with -1 (or infinity) to store the minimum time to reach each battery level. `dist[i]` will store the minimum minutes to reach `i%` battery.
3.  **Start BFS**:
    *   Push `{N, 0}` into the queue.
    *   Set `dist[N] = 0`.
4.  **Process Queue**: While the queue is not empty:
    *   Dequeue the front element: `{current_level, current_time}`.
    *   **Check Target**: If `current_level` is 50, we have found the minimum time. Print `current_time` and terminate for this test case.
    *   **Explore Neighbors**:
        *   **Charge**: Calculate `next_level_charge = current_level + 2`.
            *   If `next_level_charge <= 100` (within bounds) AND `dist[next_level_charge]` is -1 (unvisited):
                *   Set `dist[next_level_charge] = current_time + 1`.
                *   Enqueue `{next_level_charge, current_time + 1}`.
        *   **Use**: Calculate `next_level_discharge = current_level - 3`.
            *   If `next_level_discharge >= 0` (within bounds) AND `dist[next_level_discharge]` is -1 (unvisited):
                *   Set `dist[next_level_discharge] = current_time + 1`.
                *   Enqueue `{next_level_discharge, current_time + 1}`.

Since the battery levels are integers from 0 to 100, a `std::vector<int> dist(101, -1)` is an efficient way to manage visited states and their minimum times.

## Complexity Analysis

-   **Time Complexity**:
    *   The number of possible battery levels (nodes in our graph) is fixed at 101 (from 0 to 100). Let $V = 101$.
    *   From each battery level, there are at most two possible transitions (charging or discharging). So, the maximum number of edges $E$ is approximately $2 \times V$.
    *   BFS complexity is $O(V + E)$.
    *   In this problem, $V = 101$ and $E \approx 2 \times 101 = 202$.
    *   Therefore, the time complexity for a single test case is $O(101 + 202)$, which is a constant time operation.
    *   Given $T$ test cases, the total time complexity will be $O(T \times (V + E)) = O(T \times 101)$. Since 101 is a small constant, this is effectively $O(T)$.

-   **Space Complexity**:
    *   We use a `dist` vector of size 101 to store the minimum time to reach each battery level.
    *   The queue for BFS, in the worst case, might store up to $V$ elements (all possible battery levels).
    *   Thus, the space complexity is $O(V) = O(101)$, which is also a constant.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes most standard libraries

// Using namespace std; as requested by the problem statement
using namespace std;

void solve() {
    int N;
    cin >> N;

    // Base case: If battery is already at 50%, time taken is 0.
    if (N == 50) {
        cout << 0 << "\n";
        return;
    }

    // BFS approach to find the minimum time
    // queue stores pairs: {battery_level, time_taken}
    queue<pair<int, int>> q; 
    
    // dist[level] stores the minimum time to reach 'level'.
    // Initialize with -1 to indicate unvisited states.
    vector<int> dist(101, -1); 

    // Start with the initial level N at time 0
    q.push({N, 0}); 
    dist[N] = 0;    // Mark initial level as visited with time 0

    while (!q.empty()) {
        int current_level = q.front().first;
        int current_time = q.front().second;
        q.pop();

        // If we have reached the target level 50%, this is the minimum time
        // because BFS explores states in increasing order of time.
        if (current_level == 50) {
            cout << current_time << "\n";
            return; // Found the minimum time, exit for this test case
        }

        // Option 1: Charge the phone
        int next_level_charge = current_level + 2;
        // Check if the new level is within the valid range [0, 100]
        if (next_level_charge <= 100) { 
            // If this level hasn't been visited yet (or found with a longer path,
            // but BFS guarantees first visit is shortest)
            if (dist[next_level_charge] == -1) { 
                dist[next_level_charge] = current_time + 1; // Update min time
                q.push({next_level_charge, current_time + 1}); // Add to queue
            }
        }

        // Option 2: Use the phone (discharge)
        int next_level_discharge = current_level - 3;
        // Check if the new level is within the valid range [0, 100]
        if (next_level_discharge >= 0) { 
            // If this level hasn't been visited yet
            if (dist[next_level_discharge] == -1) { 
                dist[next_level_discharge] = current_time + 1; // Update min time
                q.push({next_level_discharge, current_time + 1}); // Add to queue
            }
        }
    }
    // This part of the code should theoretically not be reached
    // as 50% battery level is always reachable from any N in [0, 100].
    // For example, from 0, charge 25 times to 50. From 100, discharge until below 50, then charge.
}

int main() {
    // Fast I/O setup as requested
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) { // Loop through each test case
        solve(); // Call the function to solve each test case
    }

    return 0;
}
```