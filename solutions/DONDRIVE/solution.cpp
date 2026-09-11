#include <bits/stdc++.h> // Includes all standard libraries

using namespace std; // Uses the standard namespace

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams,
    // which can speed up I/O operations.
    // cin.tie(NULL) prevents cout from flushing before cin reads input,
    // further optimizing I/O when mixing cin and cout.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare an integer variable T to store the number of test cases.
    cin >> T; // Read the number of test cases from standard input.

    // Loop T times, processing one test case in each iteration.
    while (T--) {
        int N, X; // Declare integer variables N and X for the target and collected donations.
        cin >> N >> X; // Read the target number of donations (N) and the collected donations (X)
                        // for the current test case.

        // Calculate the remaining number of donations needed.
        // The target is N donations, and X donations have already been collected.
        // The difference (N - X) gives the number of donations still required.
        int remaining_donations = N - X;

        // Print the calculated remaining donations to standard output,
        // followed by a newline character to ensure each result is on a new line.
        cout << remaining_donations << "\n";
    }

    return 0; // Indicate successful program execution.
}