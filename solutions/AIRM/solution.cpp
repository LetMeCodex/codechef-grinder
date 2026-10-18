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