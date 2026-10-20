#include <bits/stdc++.h> // Includes common standard libraries like iostream

using namespace std; // Allows using standard library elements without the std:: prefix

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int X, Y; // Declare variables for length and width
    cin >> X >> Y; // Read the length (X) and width (Y) from standard input

    // Calculate the perimeter of the rectangular park.
    // The perimeter is 2 * (length + width).
    int perimeter = 2 * (X + Y);

    // Check if the calculated perimeter is at least 1000 meters.
    // If it is, Chef can achieve the fitness goal.
    if (perimeter >= 1000) {
        cout << "YES\n"; // Print "YES" followed by a newline
    } else {
        // If the perimeter is less than 1000 meters, Chef cannot achieve the goal.
        cout << "NO\n"; // Print "NO" followed by a newline
    }

    return 0; // Indicate successful execution
}