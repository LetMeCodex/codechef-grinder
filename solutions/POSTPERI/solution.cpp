#include <bits/stdc++.h> // Includes all standard libraries like iostream, algorithm, limits

// Using namespace std; is common in competitive programming to avoid writing std::
using namespace std; 

// Function to solve a single test case
void solve() {
    int N, M, K;
    // Read the maximum allowed length (N), maximum allowed width (M),
    // and the target perimeter (K) for the current test case.
    cin >> N >> M >> K; 

    // Initialize min_diff to the maximum possible integer value.
    // This ensures that any valid difference found will be smaller.
    int min_diff = numeric_limits<int>::max(); 

    // Iterate through all possible integer lengths 'l' from 1 to N.
    for (int l = 1; l <= N; ++l) {
        // Iterate through all possible integer widths 'w' from 1 to M.
        for (int w = 1; w <= M; ++w) {
            // Calculate the perimeter for the current length and width.
            int perimeter = 2 * (l + w);
            
            // Calculate the absolute difference between the current perimeter and the target K.
            int current_diff = abs(perimeter - K);
            
            // Update min_diff if the current difference is smaller than the smallest found so far.
            min_diff = min(min_diff, current_diff);
        }
    }
    // Output the minimum possible difference for the current test case, followed by a newline.
    cout << min_diff << "\n"; 
}

int main() {
    // Optimize C++ standard streams for faster input/output operations.
    // This is a common practice in competitive programming to prevent TLE (Time Limit Exceeded).
    ios_base::sync_with_stdio(false); // Unties C++ streams from C standard streams
    cin.tie(NULL); // Unties cin from cout, preventing flushes

    int T;
    cin >> T; // Read the number of test cases

    // Loop T times, calling the solve function for each test case.
    while (T--) {
        solve();
    }

    return 0; // Indicate successful program execution
}