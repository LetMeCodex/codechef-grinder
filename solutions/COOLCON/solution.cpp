#include <bits/stdc++.h> // Includes all standard libraries as per problem instructions

using namespace std; // Brings all names from the std namespace into the current scope

int main() {
    // Optimize C++ standard streams for competitive programming.
    // This unties cin/cout from C's stdio and prevents flushing cout before cin.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Variable to store the number of test cases
    cin >> T; // Read the number of test cases

    // Loop through each test case
    while (T--) {
        int X, Y; // Variables to store initial and final temperatures
        cin >> X >> Y; // Read X and Y for the current test case

        long long total_seconds = 0; // Accumulator for total time, initialized to 0.
                                     // Using long long to be safe, though int would suffice for given constraints.
        int current_temp = X;        // Start cooling from the initial temperature X

        // Loop as long as the current temperature is above the target temperature Y
        while (current_temp > Y) {
            // Calculate the time needed to reduce the temperature by 1 degree.
            // The formula is ceil(current_temp / 10).
            // In integer arithmetic, ceil(A / B) for positive A, B is (A + B - 1) / B.
            // For A = current_temp and B = 10, this becomes (current_temp + 10 - 1) / 10,
            // which simplifies to (current_temp + 9) / 10.
            int time_needed_for_decrement = (current_temp + 9) / 10;

            // Add the calculated time for this 1-degree reduction to the total
            total_seconds += time_needed_for_decrement;

            // Decrease the temperature by 1 degree for the next iteration
            current_temp--;
        }

        // Output the total time calculated for the current test case, followed by a newline
        cout << total_seconds << "\n";
    }

    return 0; // Indicate successful program execution
}