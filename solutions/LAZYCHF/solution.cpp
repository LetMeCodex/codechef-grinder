#include <bits/stdc++.h> // Includes iostream, algorithm, etc.

using namespace std; // Use standard namespace for convenience

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin from cout and prevents synchronization with C's stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of testcases

    while (T--) { // Loop T times, decrementing T in each iteration
        int x, m, d;
        cin >> x >> m >> d; // Read the three integers for the current testcase

        // Calculate the time Chef would take due to his laziness.
        // This is the original time multiplied by his laziness factor.
        int lazy_time = x * m;

        // Calculate the maximum time allowed due to the delay limit.
        // This is the original time plus the maximum allowed delay.
        int max_allowed_time = x + d;

        // The actual time taken is the minimum of these two values.
        // Chef will take his lazy_time, but not more than max_allowed_time.
        int result = min(lazy_time, max_allowed_time);

        cout << result << "\n"; // Print the result followed by a newline character
    }

    return 0; // Indicate successful execution
}