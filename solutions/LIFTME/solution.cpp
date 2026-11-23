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