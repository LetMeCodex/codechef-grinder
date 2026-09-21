#include <bits/stdc++.h> // Required header as per problem instructions

using namespace std; // Required namespace as per problem instructions

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare variable for the number of test cases
    cin >> T; // Read the number of test cases

    // Loop through each test case
    while (T--) {
        int X, Y; // Declare variables for geyser capacity (X) and bucket capacity (Y)
        cin >> X >> Y; // Read X and Y for the current test case

        // Calculate the total water required for one person to take a bath.
        // One person needs 2 buckets, and each bucket holds Y litres.
        int water_needed_per_person = 2 * Y;

        // Calculate the maximum number of people that can take a bath.
        // This is done by dividing the total water available in the geyser (X)
        // by the water needed per person.
        // Integer division automatically handles the "maximum whole number of people".
        int max_people = X / water_needed_per_person;

        // Output the result for the current test case, followed by a newline.
        cout << max_people << "\n";
    }

    return 0; // Indicate successful program execution
}