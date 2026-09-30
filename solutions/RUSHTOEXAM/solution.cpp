#include <bits/stdc++.h> // Includes all standard libraries

// Using the standard namespace to avoid writing std:: repeatedly
using namespace std;

int main() {
    // Optimize C++ standard streams for competitive programming.
    // This unties cin/cout from the C standard I/O library and
    // prevents flushing cout before cin reads, speeding up I/O.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // The problem statement describes a single test case:
    // "The first and only line contains 3 integers - N, M and A."
    // We will follow this specific input format, which implies a single test case.
    // Therefore, we read N, M, A directly without a loop for multiple test cases.

    int N, M, A; // Declare variables for hours (N), pages to read (M), pages per hour (A)

    // Read the three integers from standard input
    cin >> N >> M >> A;

    // Calculate the total number of pages Chef can read in N hours.
    // Given the constraints (N <= 24, A <= 10), the maximum value for N * A is 24 * 10 = 240.
    // This value fits comfortably within an 'int' data type, so no overflow risk.
    int pages_chef_can_read = N * A;

    // Compare the pages Chef can read with the required pages M.
    // If Chef can read a number of pages greater than or equal to M, he can finish.
    if (pages_chef_can_read >= M) {
        // If Chef can read enough pages, print "Yes" followed by a newline.
        cout << "Yes\n";
    } else {
        // Otherwise, Chef cannot read enough pages, print "No" followed by a newline.
        cout << "No\n";
    }

    return 0; // Indicate successful execution
}