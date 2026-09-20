#include <iostream> // Required for standard input/output operations (cin, cout)
#include <bits/stdc++.h> // A common header in competitive programming that includes many standard libraries

// Using the standard namespace to avoid repeatedly writing std::
using namespace std;

// Function to solve a single test case
void solve() {
    int W, X, Y, Z;
    // Read the four space-separated integers for the current test case
    cin >> W >> X >> Y >> Z;

    // Calculate the total amount of water added to the bucket
    // Water flow rate (Y) * Time (Z)
    int water_added = Y * Z;

    // Calculate the total potential water level if the bucket could hold it all
    // Initial water (W) + Water added
    int total_potential_water = W + water_added;

    // Compare the total potential water with the maximum capacity (X)
    if (total_potential_water > X) {
        // If total water exceeds capacity, it overflows
        cout << "overflow\n";
    } else if (total_potential_water == X) {
        // If total water exactly matches capacity, it's filled
        cout << "filled\n";
    } else { // total_potential_water < X
        // If total water is less than capacity, it's unfilled
        cout << "unfilled\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    // Read the number of test cases
    cin >> T;
    // Loop T times, calling the solve function for each test case
    while (T--) {
        solve();
    }

    return 0; // Indicate successful execution
}