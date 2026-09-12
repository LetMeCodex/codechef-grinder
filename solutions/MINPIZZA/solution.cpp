#include <bits/stdc++.h> // Includes most standard libraries

// Use the standard namespace to avoid writing std:: repeatedly
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams,
    // which can speed up I/O operations significantly.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation,
    // further improving I/O performance.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare an integer variable T for the number of test cases.
    cin >> T; // Read the number of test cases from standard input.

    // Loop T times, once for each test case.
    while (T--) {
        int N, X; // Declare integer variables N (number of friends) and X (slices each friend wants).
        cin >> N >> X; // Read N and X for the current test case.

        // Calculate the total number of slices required by all friends.
        // N friends * X slices/friend = total_slices_required
        int total_slices_required = N * X;

        // Each pizza consists of 4 slices. We need to find the minimum number of pizzas
        // to satisfy the total slices required. This is a classic ceiling division problem.
        //
        // For positive integers A and B, the ceiling of A/B (ceil(A/B)) can be calculated
        // using integer arithmetic as (A + B - 1) / B.
        // Here, A = total_slices_required and B = 4 (slices per pizza).
        int minimum_pizzas = (total_slices_required + 4 - 1) / 4;
        // This simplifies to (total_slices_required + 3) / 4.

        // Output the calculated minimum number of pizzas to standard output,
        // followed by a newline character as required.
        cout << minimum_pizzas << "\n";
    }

    return 0; // Indicate successful program execution.
}