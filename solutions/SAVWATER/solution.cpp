#include <iostream> // Include only necessary headers

// Use the standard namespace
using namespace std;

void solve() {
    int H, x, y, C;
    // Read the four integers for the current test case
    cin >> H >> x >> y >> C;

    // Calculate the water consumption for a single household after the campaign.
    // x liters are for mandatory freshwater use.
    // y liters for greywater-eligible use are reduced to floor(y/2).
    // In C++, integer division `y / 2` automatically performs floor(y/2) for positive y.
    int water_per_household = x + (y / 2);

    // Calculate the total water needed for all H households.
    // The maximum value for H * water_per_household is 10 * (10 + 10/2) = 10 * 15 = 150.
    // This fits within an 'int'. Using 'long long' is good practice but not strictly needed here.
    long long total_water_needed = (long long)H * water_per_household;

    // Compare the total water needed with the total available water C.
    if (total_water_needed <= C) {
        // If sufficient water is available, print "YES".
        cout << "YES\n";
    } else {
        // Otherwise, print "NO".
        cout << "NO\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    // Read the number of test cases
    cin >> T;
    // Loop through each test case
    while (T--) {
        solve(); // Call the solve function for the current test case
    }

    return 0; // Indicate successful execution
}