#include <bits/stdc++.h> // Includes common standard libraries like iostream

using namespace std; // Allows using standard library elements without the std:: prefix

int main() {
    // Optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases

    while (T--) { // Loop T times for each test case
        int N, X;
        cin >> N >> X; // Read N (number of groups) and X (Chef's roll number)

        // The problem states that groups are formed such that:
        // (1, 2N), (2, 2N-1), ..., (N, N+1)
        // Observe that the sum of roll numbers in each pair is constant:
        // 1 + 2N = 2N + 1
        // 2 + (2N-1) = 2N + 1
        // ...
        // N + (N+1) = 2N + 1
        // So, if Chef's roll number is X, and his partner's roll number is P,
        // then X + P must equal 2N + 1.
        // Therefore, P = (2N + 1) - X.
        int partner_roll_number = (2 * N + 1) - X;

        // Output the calculated partner's roll number, followed by a newline.
        cout << partner_roll_number << "\n";
    }

    return 0; // Indicate successful execution
}