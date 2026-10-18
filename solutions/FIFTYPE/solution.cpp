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