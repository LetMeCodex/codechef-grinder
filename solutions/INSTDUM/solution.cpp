#include <bits/stdc++.h> // Includes all standard libraries for competitive programming

// Using namespace std; is common in competitive programming to avoid
// repeatedly typing std:: before standard library elements.
using namespace std; 

// Function to solve a single test case
void solve() {
    int N;
    cin >> N; // Read the total number of balls played

    long long total_runs = 0; // Initialize cumulative runs scored.
                              // Using long long to be safe, though int would suffice for given constraints.
    int count_100_strike_rate = 0; // Initialize counter for times strike rate is exactly 100

    // Loop through each ball played.
    // 'i' represents the current number of balls played (from 1 to N).
    for (int i = 1; i <= N; ++i) { 
        int A_i;
        cin >> A_i; // Read runs scored on the i-th ball
        total_runs += A_i; // Add runs to the cumulative total

        // Check if the strike rate is exactly 100.
        // The condition (total_runs / i) * 100 == 100 simplifies to total_runs == i.
        if (total_runs == i) { 
            count_100_strike_rate++; // Increment counter if strike rate is 100
        }
    }

    // Output the total number of times the strike rate was 100 for this test case.
    cout << count_100_strike_rate << "\n"; 
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin/cout from C's stdio and disables synchronization,
    // which is crucial for problems with large inputs/outputs.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) { // Loop through each test case
        solve(); // Call the solve function for the current test case
    }

    return 0; // Indicate successful program execution
}