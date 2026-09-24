#include <bits/stdc++.h> // Includes common libraries like iostream

using namespace std; // Use the standard namespace

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare an integer variable T for the number of test cases.
    cin >> T; // Read the number of test cases.

    // Loop through each test case.
    while (T--) {
        int X, Y; // Declare integer variables X and Y for rental cost and purchase cost.
        cin >> X >> Y; // Read X and Y for the current test case.

        // Calculate the maximum number of months.
        // We need M * X < Y, which is equivalent to M * X <= Y - 1.
        // Dividing by X (which is >= 1), we get M <= (Y - 1) / X.
        // Since M must be an integer, the maximum M is floor((Y - 1) / X).
        // In C++, integer division `(Y - 1) / X` automatically computes the floor
        // for positive operands.
        int result = (Y - 1) / X;

        // Output the result for the current test case, followed by a newline.
        cout << result << "\n";
    }

    return 0; // Indicate successful execution.
}