#include <bits/stdc++.h> // Includes iostream, algorithm, cmath, limits, etc.

using namespace std; // Use standard namespace

void solve() {
    int N, X, K;
    cin >> N >> X >> K;

    int min_changes = numeric_limits<int>::max(); // Initialize with a very large value

    // Iterate through all possible number of students S that can go on the trip.
    // S must be a multiple of K and S <= N.
    // We can directly iterate S as multiples of K to ensure S % K == 0.
    for (int S = 0; S <= N; S += K) {
        // S is a valid number of students to go on the trip (multiple of K and <= N).
        // Calculate the number of mind changes needed for this S.
        int current_changes = abs(S - X);
        
        // Update the minimum changes found so far.
        min_changes = min(min_changes, current_changes);
    }
    cout << min_changes << "\n"; // Output the minimum changes for this test case.
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases.
    while (T--) { // Loop through each test case.
        solve(); // Solve the current test case.
    }

    return 0; // Indicate successful execution.
}