#include <bits/stdc++.h> // Includes most standard libraries, as requested

using namespace std; // As requested, to avoid typing std:: repeatedly

void solve() {
    int N, K;
    cin >> N >> K; // Read N (number of sweets) and K (calorie limit)

    int current_calories_consumed = 0; // Tracks total calories eaten so far
    int sweets_eaten_count = 0;        // Tracks number of sweets eaten

    // Iterate through the sweets in order
    for (int i = 0; i < N; ++i) {
        int A_i;
        cin >> A_i; // Read the calorie count of the current sweet

        // Check if eating this sweet would exceed the daily calorie limit
        if (current_calories_consumed + A_i <= K) {
            // If it doesn't exceed, eat the sweet
            current_calories_consumed += A_i; // Add its calories to the total
            sweets_eaten_count++;             // Increment the count of sweets eaten
        } else {
            // If eating this sweet would exceed the limit, Sushil stops.
            // He will not eat this sweet or any further sweets.
            // We need to consume the remaining A_i values for this test case
            // from the input buffer to ensure the next test case reads correctly.
            for (int j = i + 1; j < N; ++j) {
                int dummy;
                cin >> dummy; // Read and discard remaining sweet calorie counts
            }
            break; // Exit the loop as Sushil stops eating
        }
    }
    
    // Output the maximum number of sweets Sushil could eat
    cout << sweets_eaten_count << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output operations.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cout from being flushed before each cin operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) {  // Loop T times, decrementing T each time
        solve();   // Call the solve function for each test case
    }

    return 0; // Indicate successful execution
}