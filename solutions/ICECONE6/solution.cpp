#include <bits/stdc++.h> // Includes common standard libraries like iostream, algorithm, etc.

using namespace std; // Allows using standard library elements without the std:: prefix

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases

    while (T--) { // Loop T times, once for each test case
        int X, Y, N;
        cin >> X >> Y >> N; // Read initial ice cream (X), melting rate (Y), and time (N)

        // Calculate the total amount of ice cream that melts over N minutes.
        // Each minute, Y grams melt, so after N minutes, Y * N grams melt.
        int melted_amount = Y * N;

        // Calculate the amount of ice cream theoretically remaining.
        // This could be negative if more ice cream melts than initially present.
        int remaining_amount = X - melted_amount;

        // Ice cream cannot be negative. If the calculated remaining_amount is less than 0,
        // it means all the ice cream has melted, and 0 grams are left.
        // std::max(0, remaining_amount) ensures the output is never negative.
        int final_amount = max(0, remaining_amount);

        cout << final_amount << "\n"; // Output the final amount of ice cream left, followed by a newline
    }

    return 0; // Indicate successful program execution
}