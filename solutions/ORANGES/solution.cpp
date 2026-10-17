#include <bits/stdc++.h> // Includes all standard libraries

// Use the standard namespace to avoid prefixing std::
using namespace std;

// Function to solve a single test case
void solve() {
    int N, K;
    cin >> N >> K; // Read N (number of oranges) and K (target slices)

    // Calculate the minimum possible total slices Chef could have eaten.
    // This happens if all N oranges had 10 slices each.
    int min_possible_slices = N * 10;

    // Calculate the maximum possible total slices Chef could have eaten.
    // This happens if all N oranges had 12 slices each.
    int max_possible_slices = N * 12;

    // Check if the target K falls within the possible range [min_possible_slices, max_possible_slices].
    // If K is within this range, it's possible to achieve it.
    // Otherwise, it's not possible.
    if (K >= min_possible_slices && K <= max_possible_slices) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin/cout from the C standard streams and disables synchronization.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases

    // Loop through each test case
    while (T--) {
        solve(); // Call the solve function for the current test case
    }

    return 0; // Indicate successful program execution
}