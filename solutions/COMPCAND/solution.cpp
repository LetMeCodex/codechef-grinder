#include <bits/stdc++.h> // Includes common C++ headers like iostream

using namespace std; // Use the standard namespace

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare variable for the number of testcases
    cin >> T; // Read the number of testcases

    while (T--) { // Loop T times for each testcase
        int N, K; // Declare variables for candy length N and bite size K
        cin >> N >> K; // Read N and K for the current testcase

        if (N == 0) {
            // If candy length is 0, no bites are needed.
            cout << 0 << "\n";
        } else if (N % K == 0) {
            // If N is perfectly divisible by K, we can eat the entire candy.
            // The number of bites will be N / K.
            cout << N / K << "\n";
        } else {
            // If N is not perfectly divisible by K, after taking as many K-unit bites
            // as possible, there will be a remaining piece of candy with length
            // N % K. This remaining piece will be positive but less than K,
            // making it impossible to take another K-unit bite.
            cout << -1 << "\n";
        }
    }

    return 0; // Indicate successful program execution
}