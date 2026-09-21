#include <bits/stdc++.h> // Includes all standard libraries, as per problem instructions

// Use the standard namespace to avoid writing std:: repeatedly
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Variable to store the number of test cases
    cin >> T; // Read the number of test cases

    // Loop through each test case
    while (T--) {
        int X, Y, Z; // Variables to store mango weight, truck weight, and bridge capacity
        cin >> X >> Y >> Z; // Read X, Y, and Z for the current test case

        // Calculate the maximum weight capacity available for mangoes.
        // This is the total bridge capacity minus the truck's weight.
        // Since Y <= Z, remaining_capacity will always be non-negative.
        int remaining_capacity = Z - Y;

        // Calculate the maximum number of mangoes.
        // Divide the remaining capacity by the weight of a single mango.
        // Integer division automatically handles the floor operation for non-negative results.
        int max_mangoes = remaining_capacity / X;

        // Output the result for the current test case, followed by a newline.
        cout << max_mangoes << "\n";
    }

    return 0; // Indicate successful program execution
}