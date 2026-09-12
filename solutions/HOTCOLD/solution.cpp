#include <bits/stdc++.h> // Includes all standard libraries

using namespace std; // Allows using standard library elements without std:: prefix

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation,
    // which can speed up programs that mix cin and cout.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare an integer variable T for the number of test cases.
    cin >> T; // Read the number of test cases from standard input.

    // Loop T times, once for each test case.
    // The T-- decrements T after each iteration, stopping when T becomes 0.
    while (T--) {
        int C; // Declare an integer variable C for the temperature.
        cin >> C; // Read the temperature for the current test case.

        // According to the problem statement, Chef considers the climate HOT
        // if the temperature is *above* 20. This means strictly greater than 20.
        if (C > 20) {
            cout << "HOT\n"; // If C is greater than 20, print "HOT" followed by a newline.
        } else {
            // Otherwise (if C is 20 or less), Chef considers it COLD.
            cout << "COLD\n"; // Print "COLD" followed by a newline.
        }
    }

    return 0; // Indicate successful program execution.
}