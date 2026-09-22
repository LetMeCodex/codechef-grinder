#include <bits/stdc++.h> // Includes common headers like iostream, cmath, algorithm

// Using the standard namespace to avoid repeatedly typing std::
using namespace std;

// Function to solve a single test case
void solve() {
    int x1, y1, x2, y2;
    // Read the coordinates of the two points
    cin >> x1 >> y1 >> x2 >> y2;

    // Calculate the absolute difference in x-coordinates
    // abs() function is used to get the absolute value
    int diff_x = abs(x1 - x2);
    
    // Calculate the absolute difference in y-coordinates
    int diff_y = abs(y1 - y2);

    // The Chessboard Distance is defined as the maximum of these two differences
    // max() function returns the larger of its two arguments
    int result = max(diff_x, diff_y);
    
    // Output the calculated Chessboard Distance followed by a newline
    cout << result << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    // Read the number of test cases
    cin >> t;
    // Loop through each test case
    while (t--) {
        solve(); // Call the solve function for the current test case
    }

    return 0; // Indicate successful program execution
}