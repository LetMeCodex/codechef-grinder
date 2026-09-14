#include <bits/stdc++.h> // Includes most standard libraries

using namespace std; // Allows using standard namespace elements without std:: prefix

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare an integer variable T for the number of test cases
    cin >> T; // Read the number of test cases

    // Loop T times, once for each test case
    while (T--) {
        int X, Y, Z; // Declare integer variables for X, Y, and Z
        cin >> X >> Y >> Z; // Read the values of X, Y, and Z for the current test case

        // Calculate the total number of chapters.
        // X courses * Y units/course = total units
        // total units * Z chapters/unit = total chapters
        // The maximum value for X*Y*Z is 1000*1000*1000 = 1,000,000,000,
        // which fits within a standard 32-bit signed integer (max ~2*10^9).
        long long total_chapters = (long long)X * Y * Z; 
        // Using long long for total_chapters is a safe practice to prevent potential overflow,
        // even though int would suffice for the given constraints.
        // Casting X to long long before multiplication ensures the intermediate product
        // is also computed as long long, preventing overflow if X, Y, Z were larger.

        cout << total_chapters << "\n"; // Print the calculated total chapters followed by a newline
    }

    return 0; // Indicate successful program execution
}