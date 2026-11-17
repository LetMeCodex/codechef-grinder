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