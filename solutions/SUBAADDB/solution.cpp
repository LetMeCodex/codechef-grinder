#include <bits/stdc++.h> // Includes all standard libraries for competitive programming

using namespace std; // Allows using standard library components without the std:: prefix

int main() {
    // Optimize C++ standard streams for faster input/output operations.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare an integer variable T to store the number of test cases.
    cin >> T; // Read the number of test cases from standard input.

    // Loop T times, processing each test case.
    while (T--) {
        int N, A, B; // Declare integer variables N, A, B for the current test case.
        cin >> N >> A >> B; // Read the initial string length N, and parameters A and B.

        // Calculate the amount by which the string length is reduced in each operation.
        // An operation replaces a substring of length A with one of length B.
        // Since B < A, the net change in length is A - B (a reduction).
        int length_reduction_per_op = A - B;

        // Continue performing operations as long as the string's current length (N)
        // is greater than or equal to A.
        while (N >= A) {
            // Reduce the string's length by 'length_reduction_per_op'.
            N -= length_reduction_per_op;
        }

        // Once the loop terminates, N is the final length of the string,
        // because it's no longer possible to find a substring of length A to modify.
        cout << N << "\n"; // Output the final length followed by a newline character.
    }

    return 0; // Indicate successful program execution.
}