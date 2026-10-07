#include <bits/stdc++.h> // Includes all standard libraries

using namespace std; // Uses the standard namespace

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams,
    // which can speed up I/O operations.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation,
    // further improving performance.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare an integer variable T for the number of test cases.
    cin >> T; // Read the number of test cases from standard input.

    // Loop T times, once for each test case.
    while (T--) {
        int S; // Declare an integer variable S for the duration of the video in seconds.
        cin >> S; // Read the duration S for the current test case.

        // Calculate the total worth of the video in words.
        // The problem states:
        // 1. A video has 24 frames (pictures) per second.
        // 2. The video has a duration of S seconds.
        //    So, total frames = 24 * S.
        // 3. Each frame is worth 1000 words.
        //    So, total worth = (total frames) * 1000.
        // Combining these: total worth = (24 * S) * 1000 words.

        // Constraints: 1 <= S <= 100.
        // Maximum possible value for S is 100.
        // Max total worth = (24 * 100) * 1000 = 2400 * 1000 = 2,400,000.
        // This value fits comfortably within a standard 32-bit integer type (like 'int' in C++,
        // which typically handles values up to 2 * 10^9).
        // However, using 'long long' for the result is a good practice in competitive programming
        // to prevent potential overflow issues, especially if constraints were larger.
        long long total_worth = (long long)24 * S * 1000; 
        // We cast 24 to long long to ensure the entire multiplication is performed using
        // long long arithmetic, although for these specific constraints, 'int' would suffice.

        // Output the calculated total worth, followed by a newline character.
        cout << total_worth << "\n";
    }

    return 0; // Indicate successful program execution.
}