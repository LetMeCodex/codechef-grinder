#include <bits/stdc++.h>
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare an integer variable T to store the number of test cases.
    cin >> T; // Read the number of test cases from standard input.

    // Loop T times, once for each test case.
    while (T--) {
        int X, Y; // Declare two integer variables X and Y for bike and car travel times.
        cin >> X >> Y; // Read the travel times for bike (X) and car (Y) for the current test case.

        // Compare the travel times to determine which option is faster or if they are the same.
        if (X < Y) {
            // If X (bike time) is less than Y (car time), bike is faster.
            cout << "BIKE\n";
        } else if (Y < X) {
            // If Y (car time) is less than X (bike time), car is faster.
            cout << "CAR\n";
        } else {
            // If neither of the above conditions is true, then X must be equal to Y.
            // In this case, both options take the same time.
            cout << "SAME\n";
        }
    }

    return 0; // Indicate successful program execution.
}