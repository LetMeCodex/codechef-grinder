#include <bits/stdc++.h> // Includes all standard libraries, common in competitive programming

using namespace std; // Allows using standard library elements without the std:: prefix

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Declare two integer variables to store the number of students (N)
    // and the number of seats (M).
    int N, M;

    // Read the values of N and M from standard input.
    cin >> N >> M;

    // Check the condition for Chef's happiness.
    // Chef is happy if the bus is not full, which means there are fewer students
    // than seats (N < M).
    if (N < M) {
        // If N is less than M, print "YES" followed by a newline character.
        cout << "YES\n";
    } else {
        // If N is not less than M, given the constraint N <= M, it must be that N == M.
        // In this case, the bus is full, and Chef is not happy.
        // Print "NO" followed by a newline character.
        cout << "NO\n";
    }

    // Return 0 to indicate successful program execution.
    return 0;
}