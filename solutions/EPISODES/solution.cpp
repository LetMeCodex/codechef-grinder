#include <bits/stdc++.h> // Includes most standard libraries, as requested by the problem

using namespace std; // Uses the standard namespace, as requested by the problem

int main() {
    // Optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare an integer variable T to store the number of test cases.
    cin >> T; // Read the number of test cases from standard input.

    // Loop T times, once for each test case.
    while (T--) {
        int N, K; // Declare integer variables N and K for episodes and minutes per episode.
        cin >> N >> K; // Read N and K for the current test case.

        // Calculate the total time in minutes.
        // N * K will not overflow an int because N <= 30 and K < 60,
        // so max total_minutes = 30 * 59 = 1770.
        int total_minutes = N * K;

        // Calculate the number of full hours.
        // Integer division automatically truncates the decimal part.
        int H = total_minutes / 60;

        // Calculate the remaining minutes.
        // The modulo operator (%) gives the remainder, which will be < 60.
        int M = total_minutes % 60;

        // Output the calculated hours and minutes, separated by a space,
        // followed by a newline character for the next test case's output.
        cout << H << " " << M << "\n";
    }

    return 0; // Indicate successful program execution.
}