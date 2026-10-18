#include <bits/stdc++.h> // Includes most standard libraries

using namespace std; // Adhering to the instruction

void solve() {
    int X, Y;
    cin >> X >> Y; // Read current position X and starting die value Y

    // Calculate the exact number of steps Chef needs to move to reach 50.
    int target_steps = 50 - X;

    // Calculate the minimum possible sum from rolling two dice.
    // Each die can show values from Y to Y+5.
    // The minimum value for a single die is Y.
    // So, the minimum sum for two dice is Y + Y = 2Y.
    int min_roll_sum = 2 * Y;

    // Calculate the maximum possible sum from rolling two dice.
    // The maximum value for a single die is Y+5.
    // So, the maximum sum for two dice is (Y+5) + (Y+5) = 2Y + 10.
    int max_roll_sum = 2 * Y + 10;

    // Chef can win if the required 'target_steps' falls within the
    // possible range of sums from the two dice.
    if (target_steps >= min_roll_sum && target_steps <= max_roll_sum) {
        cout << "Yes\n"; // If possible, output "Yes"
    } else {
        cout << "No\n";  // Otherwise, output "No"
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin from cout and disables synchronization with C's stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Variable to store the number of test cases
    cin >> T; // Read the number of test cases
    while (T--) { // Loop T times, once for each test case
        solve(); // Call the solve function for each test case
    }

    return 0; // Indicate successful execution
}