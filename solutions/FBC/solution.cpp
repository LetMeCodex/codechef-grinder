#include <bits/stdc++.h> // Includes all standard libraries as requested

using namespace std; // Uses the standard namespace as requested

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cout from flushing before cin reads input.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare an integer variable T for the number of test cases.
    cin >> T; // Read the number of test cases from standard input.

    // Loop T times, once for each test case.
    while (T--) {
        int K, X; // Declare integer variables K and X for bucket capacity and current water.
        cin >> K >> X; // Read K and X for the current test case.

        // Calculate the maximum amount of extra water that can be filled.
        // This is simply the difference between the total capacity (K)
        // and the amount of water already present (X).
        int extra_water = K - X;

        // Print the calculated extra water followed by a newline character.
        // The newline character ensures each output is on a separate line as per format.
        cout << extra_water << "\n";
    }

    return 0; // Indicate successful program execution.
}