#include <bits/stdc++.h> // Include all standard libraries

using namespace std; // Use the standard namespace

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin/cout from the C standard streams and disables synchronization.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases

    while (T--) {
        int X, Y, Z;
        cin >> X >> Y >> Z; // Read the dimensions (X, Y) and budget (Z) for the current test case

        // Calculate the area of a single wall.
        // X and Y are in meters, so X * Y gives area in square meters.
        int area_per_wall = X * Y;

        // Calculate the total cost to paint one wall completely.
        // The cost is 2 rupees per square meter.
        int cost_per_wall = area_per_wall * 2;

        // Calculate the maximum number of walls Chef can paint completely.
        // This is the total budget divided by the cost of one wall.
        // Integer division automatically truncates the decimal part,
        // effectively performing the floor operation, which is what we need
        // since Chef can only paint a whole number of walls completely.
        // Note: cost_per_wall will always be at least 2 (since X, Y >= 1),
        // so division by zero is not possible.
        int max_walls = Z / cost_per_wall;

        // Output the result for the current test case, followed by a newline.
        cout << max_walls << "\n";
    }

    return 0; // Indicate successful execution
}