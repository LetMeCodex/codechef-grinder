#include <bits/stdc++.h> // Includes most standard libraries

// Use the standard namespace to avoid writing std:: repeatedly
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cout from flushing before cin reads input.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare an integer variable T for the number of test cases
    cin >> T; // Read the number of test cases from input

    // Loop T times, once for each test case
    while (T--) {
        int N, X, Y; // Declare integer variables for N, X, and Y
        cin >> N >> X >> Y; // Read N, X, and Y for the current test case

        // Calculate the maximum total pages Chef can read in Y days.
        // Chef reads at most X pages per day, so over Y days, the maximum is X * Y.
        int max_pages_chef_can_read = X * Y;

        // Check if the total pages N are less than or equal to
        // the maximum pages Chef can read.
        if (N <= max_pages_chef_can_read) {
            // If N is less than or equal, Chef can complete the book.
            cout << "YES\n"; 
        } else {
            // Otherwise, Chef cannot complete the book.
            cout << "NO\n";
        }
    }

    return 0; // Indicate successful program execution
}