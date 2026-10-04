#include <bits/stdc++.h> // Includes all standard libraries, as requested

// Using namespace std; is requested
using namespace std;

void solve() {
    int N;
    cin >> N; // Read the number of times Chef has to pluck a string

    long long total_skipped_strings = 0; // Use long long to prevent integer overflow
                                         // Max N is 10^5, max skip is ~10^6, so sum can be ~10^11

    int prev_S;
    cin >> prev_S; // Read the first string number (S_1)

    // Iterate from the second string (S_2) up to S_N
    for (int i = 1; i < N; ++i) {
        int current_S;
        cin >> current_S; // Read the current string number (S_i)

        // The number of strings skipped between two strings A and B is |A - B| - 1.
        // For example, from 1 to 6, strings 2,3,4,5 are skipped. |6-1|-1 = 5-1 = 4.
        // From 10 to 11, no strings are skipped. |11-10|-1 = 1-1 = 0.
        total_skipped_strings += abs(current_S - prev_S) - 1;

        // Update prev_S to current_S for the next iteration
        prev_S = current_S;
    }

    cout << total_skipped_strings << "\n"; // Output the total number of skipped strings
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of testcases
    while (T--) {
        solve(); // Call the solve function for each testcase
    }

    return 0; // Indicate successful execution
}