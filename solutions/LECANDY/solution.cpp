#include <bits/stdc++.h> // Includes common headers like iostream, vector, etc.
using namespace std; // Allows using cin, cout, etc. without std:: prefix

void solve() {
    int N; // Number of elephants
    int C; // Total candies available. Max 10^9, fits in a 32-bit signed int.
    cin >> N >> C;

    int required_candies_sum = 0; // Sum of AK. Max 100 * 10000 = 10^6, fits in a 32-bit signed int.
    for (int i = 0; i < N; ++i) {
        int AK; // Candies needed by Kth elephant. Max 10000, fits in a 32-bit signed int.
        cin >> AK;
        required_candies_sum += AK;
    }

    // If the total candies required to make all elephants happy
    // is less than or equal to the total candies available,
    // then it's possible.
    if (required_candies_sum <= C) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
    ios_base::sync_with_stdio(false); // Unties C++ streams from C standard streams.
    cin.tie(NULL); // Unties cin from cout, meaning cin will not flush cout before reading.

    int T; // Number of test cases
    cin >> T;
    while (T--) { // Loop T times, decrementing T each time
        solve(); // Call the function to solve each test case
    }

    return 0; // Indicate successful execution
}