#include <bits/stdc++.h> // Includes all standard libraries, as requested.

using namespace std; // Uses the standard namespace, as requested.

int main() {
    // Enable fast I/O operations, as requested.
    // This unties cin from cout and disables synchronization with C's stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; // Declare N to store the number of members.
    cin >> N; // Read the number of members.

    long long current_total_stamps = 0; // Use long long to prevent integer overflow.
                                        // N can be up to 10^5, and Ci up to 10^9.
                                        // The sum can be up to 10^5 * 10^9 = 10^14,
                                        // which exceeds the capacity of a 32-bit int.
                                        // A long long can hold values up to ~9 * 10^18.

    // Loop N times to read each member's stamp count and sum them up.
    for (int i = 0; i < N; ++i) {
        int C_i; // Declare C_i to store the stamp count for the current member.
        cin >> C_i; // Read the stamp count.
        current_total_stamps += C_i; // Add it to the running total.
    }

    // Calculate the required total number of stamps if each i-th member gets i stamps.
    // This is the sum of an arithmetic series: 1 + 2 + ... + N.
    // The formula for this sum is N * (N + 1) / 2.
    // N can be up to 10^5. So, N * (N + 1) can be approximately 10^5 * 10^5 = 10^10.
    // This intermediate product also requires a long long to prevent overflow before division.
    long long required_total_stamps = (long long)N * (N + 1) / 2;

    // Compare the actual total stamps with the required total stamps.
    // If they are equal, redistribution is possible.
    if (current_total_stamps == required_total_stamps) {
        cout << "YES\n"; // Output YES if possible.
    } else {
        cout << "NO\n"; // Output NO if not possible.
    }

    return 0; // Indicate successful execution.
}