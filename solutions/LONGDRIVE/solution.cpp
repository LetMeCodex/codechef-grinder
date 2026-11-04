#include <bits/stdc++.h> // Includes all standard libraries

using namespace std; // Use the standard namespace

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) {
        int X, Y;
        cin >> X >> Y; // Read X and Y for each test case

        // Calculate the numerator for the ceiling division formula.
        // This represents the "deficit" in total distance needed to reach target Y,
        // considering the initial 10 hours and the difference in speeds.
        // H * (100 - Y) >= 10 * (Y - X)
        // So, numerator = 10 * (Y - X)
        int numerator = 10 * (Y - X);

        // Calculate the denominator for the ceiling division formula.
        // This represents the "effective speed gain" per additional hour
        // relative to the target average speed Y.
        // (100 km/h - Y km/h) is the extra distance covered per hour
        // beyond what's needed to maintain Y km/h for that hour.
        // Denominator = 100 - Y
        int denominator = 100 - Y;
        
        // Calculate H using the ceiling division formula: (A + B - 1) / B
        // This gives the minimum integer H such that H >= numerator / denominator.
        // Constraints ensure denominator (100 - Y) is always positive (Y < 100).
        int H = (numerator + denominator - 1) / denominator;
        
        cout << H << "\n"; // Output the minimum number of additional hours
    }

    return 0;
}