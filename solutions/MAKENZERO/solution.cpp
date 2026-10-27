#include <bits/stdc++.h> // Includes all standard libraries, as requested.

// Using the standard namespace to avoid prefixing std::
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams,
    // which can be a bottleneck for large I/O.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation,
    // further speeding up I/O.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases.

    // Loop through each test case.
    while (T--) {
        int N;
        cin >> N; // Read the integer N for the current test case.

        // Based on the analysis using the Frobenius Coin Problem for (3, 4),
        // the largest number that cannot be formed by 3x + 4y (where x, y >= 0) is 5.
        // This means any N > 5 can be made zero.
        // We manually check N = 1, 2, 3, 4, 5:
        // N = 1: NO
        // N = 2: NO
        // N = 3: YES (3 = 3*1)
        // N = 4: YES (4 = 4*1)
        // N = 5: NO (Frobenius number g(3,4) = 5)
        //
        // Therefore, N can be made zero if it's not 1, 2, or 5.
        if (N == 1 || N == 2 || N == 5) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }

    return 0; // Indicate successful execution.
}