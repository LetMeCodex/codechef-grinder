#include <bits/stdc++.h> // Includes all standard libraries, as requested.

// Using namespace std; as requested for competitive programming convenience.
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming to prevent TLE (Time Limit Exceeded)
    // on problems with large input/output.
    ios_base::sync_with_stdio(false); // Unties C++ streams from C standard streams.
    cin.tie(NULL);                   // Unties cin from cout, preventing flushes.

    int T; // Declare an integer variable T to store the number of test cases.
    cin >> T; // Read the number of test cases from standard input.

    // Loop T times, once for each test case.
    while (T--) {
        int X, Y, Z; // Declare integer variables X, Y, Z to store the travel times.
        // X: time for flight, Y: time for bus, Z: time for direct train.
        cin >> X >> Y >> Z; // Read X, Y, and Z for the current test case.

        // Calculate the total time taken for the "Plane and Bus" route.
        // X and Y can be up to 10^9. Their sum (X + Y) can be up to 2 * 10^9.
        // A standard 32-bit signed integer can hold values up to approximately 2.1 * 10^9,
        // so 'int' is sufficient to store this sum without overflow.
        int plane_bus_total_time = X + Y;

        // Compare the total time for the "Plane and Bus" route with the "Train" route time.
        if (plane_bus_total_time < Z) {
            // If Plane and Bus is faster, print "PLANEBUS".
            cout << "PLANEBUS\n";
        } else if (plane_bus_total_time > Z) {
            // If Train is faster, print "TRAIN".
            cout << "TRAIN\n";
        } else { // This condition implies plane_bus_total_time == Z
            // If both options take the same amount of time, print "EQUAL".
            cout << "EQUAL\n";
        }
    }

    return 0; // Indicate successful program execution.
}