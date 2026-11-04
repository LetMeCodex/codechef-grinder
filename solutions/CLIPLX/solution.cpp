#include <bits/stdc++.h> // Includes iostream, algorithm, etc.

using namespace std; // Use standard namespace

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin from cout and disables synchronization with C's stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of testcases

    // Loop through each testcase
    while (T--) {
        int X, Y;
        cin >> X >> Y; // Read the required points (X) and remaining matches (Y)

        // Calculate the minimum number of matches RCB must win.
        // To minimize wins, we assume all non-winning matches are ties (1 point each).
        // If RCB wins W matches, they get 2*W points.
        // The remaining (Y - W) matches can be tied, giving (Y - W) points.
        // Total points = 2*W + (Y - W) = W + Y.
        // We need W + Y >= X.
        // This implies W >= X - Y.
        // Since the number of wins cannot be negative, the minimum wins is max(0, X - Y).
        int min_wins = max(0, X - Y);
        
        // Output the result for the current testcase, followed by a newline.
        cout << min_wins << "\n";
    }

    return 0; // Indicate successful execution
}