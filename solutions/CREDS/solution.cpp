#include <bits/stdc++.h> // Include all standard libraries

using namespace std; // Use the standard namespace

int main() {
    // Optimize C++ standard streams for competitive programming.
    // `ios_base::sync_with_stdio(false)` unties C++ streams from C standard streams,
    // potentially speeding up I/O operations.
    // `cin.tie(NULL)` prevents `cin` from flushing `cout` before each input operation,
    // further speeding up I/O.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases

    while (T--) { // Loop T times, processing each test case
        int X, Y, Z;
        // Read the number of RTP, Audit, and Non-RTP courses for the current test case.
        cin >> X >> Y >> Z; 

        // Calculate the total credits based on the given distribution:
        // - Each RTP course gives 4 credits.
        // - Each Audit course gives 2 credits.
        // - Each Non-RTP course gives 0 credits.
        // The total credits will be (X * 4) + (Y * 2) + (Z * 0).
        // Since (Z * 0) is always 0, it simplifies to (X * 4) + (Y * 2).
        int total_credits = (X * 4) + (Y * 2); 

        // Print the calculated total credits for the current test case,
        // followed by a newline character as required by the output format.
        cout << total_credits << "\n";
    }

    return 0; // Indicate successful execution of the program
}