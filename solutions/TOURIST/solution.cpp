#include <bits/stdc++.h> // Includes iostream, cmath, algorithm, limits, etc.

// Use the standard namespace as requested
using namespace std;

void solve() {
    int N, A, B;
    cin >> N >> A >> B;

    // Initialize min_distance with the maximum possible integer value.
    // This ensures that any valid distance calculated will be smaller
    // and correctly update min_distance.
    int min_distance = numeric_limits<int>::max();

    for (int i = 0; i < N; ++i) {
        int X, Y;
        cin >> X >> Y;

        // Calculate Manhattan distance between Chef's current position (A, B)
        // and the current attraction (X, Y).
        // Manhattan distance = |x1 - x2| + |y1 - y2|
        int current_distance = abs(A - X) + abs(B - Y);

        // Update min_distance if the current attraction is closer.
        min_distance = min(min_distance, current_distance);
    }

    // Output the minimum distance found for the current test case.
    cout << min_distance << "\n";
}

int main() {
    // Enable fast I/O operations. This is a standard optimization in competitive programming
    // to speed up input and output, especially for problems with large I/O.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) { // Loop through each test case
        solve(); // Call the solve function to handle the current test case
    }

    return 0; // Indicate successful program execution
}