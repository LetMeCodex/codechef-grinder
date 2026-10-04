#include <bits/stdc++.h> // Includes most standard library headers

using namespace std; // Brings all names from the std namespace into the current scope

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of testcases
    while (T--) { // Loop T times, decrementing T in each iteration
        int x, y, xr, yr, D;
        // Read the five integers for the current testcase
        // x: current food supply
        // y: current water supply
        // xr: food required per day
        // yr: water required per day
        // D: number of days to build the boat
        cin >> x >> y >> xr >> yr >> D;

        // Calculate the total food required for D days.
        // The maximum value for D * xr is 10 * 10 = 100, which fits in an int.
        int total_food_required = D * xr;

        // Calculate the total water required for D days.
        // The maximum value for D * yr is 10 * 10 = 100, which fits in an int.
        int total_water_required = D * yr;

        // Check if Chef has sufficient supplies for both food and water.
        // Both conditions must be true for Chef to survive.
        if (x >= total_food_required && y >= total_water_required) {
            cout << "YES\n"; // If both conditions are met, Chef can reach the shore.
        } else {
            cout << "NO\n"; // Otherwise, Chef cannot reach the shore.
        }
    }

    return 0; // Indicate successful execution
}