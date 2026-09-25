#include <bits/stdc++.h> // Includes all standard libraries

// Using the standard namespace to avoid writing std:: repeatedly
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams,
    // which can speed up I/O operations.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation,
    // further speeding up I/O.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Variable to store the number of test cases
    cin >> T; // Read the number of test cases from input

    // Loop through each test case
    while (T--) {
        int X, Y; // Variables to store the amount of petrol (X liters)
                  // and the distance to DAIICT (Y kilometers)
        cin >> X >> Y; // Read X and Y for the current test case

        // Chef needs to travel to DAIICT and then return home.
        // So, the total distance to be covered is twice the distance to DAIICT.
        int total_distance_needed = 2 * Y;

        // The car runs 15 kilometers using 1 liter of petrol.
        // With X liters of petrol, Chef can cover a maximum distance of X * 15 kilometers.
        int max_distance_possible = X * 15;

        // Determine if Chef has enough petrol to cover the total required distance.
        // If the maximum distance Chef can cover is greater than or equal to
        // the total distance needed, then it's possible.
        if (max_distance_possible >= total_distance_needed) {
            cout << "YES\n"; // Print YES if it's possible
        } else {
            cout << "NO\n"; // Print NO otherwise
        }
    }

    return 0; // Indicate successful program execution
}