#include <bits/stdc++.h> // Includes most standard libraries, as requested.

// Using the standard namespace to avoid writing std:: repeatedly.
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams,
    // which can be slower due to synchronization with C's stdio.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation,
    // further speeding up I/O.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare an integer variable T for the number of test cases.
    cin >> T; // Read the number of test cases from standard input.

    // Loop T times, processing one test case in each iteration.
    while (T--) {
        int N, M; // Declare integer variables N (current temperature) and M (target temperature).
        cin >> N >> M; // Read N and M for the current test case.

        // The problem states that it takes X minutes to drop the temperature
        // from X degrees Celsius to X-1 degrees Celsius.
        // We need to find the total time to drop from N degrees to M degrees.
        // This means we sum the minutes for each 1-degree drop:
        // From N to N-1: N minutes
        // From N-1 to N-2: N-1 minutes
        // ...
        // From M+1 to M: M+1 minutes
        //
        // The total time is the sum: N + (N-1) + ... + (M+1).
        // This is an arithmetic series.
        // The sum of integers from 1 to K is given by the formula: K * (K + 1) / 2.
        //
        // So, the sum N + (N-1) + ... + (M+1) can be calculated as:
        // (Sum of integers from 1 to N) - (Sum of integers from 1 to M)
        // = (N * (N + 1) / 2) - (M * (M + 1) / 2)

        // Calculate the sum of integers from 1 to N.
        // We use `long long` for the intermediate product `N * (N + 1)`
        // to prevent potential integer overflow, although for N <= 40,
        // `int` would be sufficient as 40 * 41 = 1640 fits in an int.
        long long sum_up_to_N = (long long)N * (N + 1) / 2;

        // Calculate the sum of integers from 1 to M.
        long long sum_up_to_M = (long long)M * (M + 1) / 2;

        // The total minutes required is the difference between these two sums.
        long long total_minutes = sum_up_to_N - sum_up_to_M;

        // Print the calculated total minutes for the current test case,
        // followed by a newline character for proper formatting.
        cout << total_minutes << "\n";
    }

    return 0; // Indicate successful execution of the program.
}