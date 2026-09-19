#include <bits/stdc++.h> // Includes most standard libraries

using namespace std; // Allows using standard library elements without the std:: prefix

int main() {
    // Optimize C++ standard streams for competitive programming.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams,
    // which can speed up I/O operations.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation,
    // further speeding up I/O.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare an integer variable 'T' to store the number of test cases.
    cin >> T; // Read the number of test cases from standard input.

    // Loop 'T' times, once for each test case.
    // The T-- decrements T after each iteration, and the loop continues as long as T is non-zero.
    while (T--) {
        int A, B; // Declare two integer variables 'A' and 'B' for the time gaps.
        cin >> A >> B; // Read the two space-separated integers A and B for the current test case.

        // The problem states that A is the time gap between Chef (3rd) and the runner-up (2nd),
        // and B is the time gap between the runner-up (2nd) and the winner (1st).
        // To find the total time gap between Chef and the winner, we simply add these two gaps.
        // Chef's time = Runner-up's time + A
        // Runner-up's time = Winner's time + B
        // Substituting the second into the first:
        // Chef's time = (Winner's time + B) + A
        // Chef's time - Winner's time = A + B
        int total_gap = A + B;

        // Print the calculated total_gap followed by a newline character.
        // The "\n" ensures that each output for a test case is on a new line,
        // as required by typical competitive programming output formats.
        cout << total_gap << "\n";
    }

    return 0; // Indicate successful program execution.
}