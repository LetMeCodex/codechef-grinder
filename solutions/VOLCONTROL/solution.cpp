#include <iostream> // Required for standard input/output operations (cin, cout)
#include <cmath>    // Required for the std::abs function to calculate absolute difference

// Using the standard namespace to avoid repeatedly writing std::
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin from cout and disables synchronization with C's stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare an integer variable T to store the number of test cases.
    cin >> T; // Read the number of test cases from standard input.

    // Loop T times, once for each test case.
    while (T--) {
        int X, Y; // Declare integer variables X and Y for initial and final volume.
        cin >> X >> Y; // Read X and Y for the current test case.

        // Calculate the minimum number of button presses.
        // This is simply the absolute difference between the initial and final volume.
        // std::abs() function returns the absolute value of its argument.
        int presses = abs(X - Y);

        // Output the calculated number of presses, followed by a newline character.
        // The newline ensures that each test case's output is on a separate line.
        cout << presses << "\n";
    }

    return 0; // Indicate successful program execution.
}