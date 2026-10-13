#include <bits/stdc++.h> // Includes common standard libraries like iostream

// Using namespace std; is a common practice in competitive programming
// to avoid repeatedly typing std:: before standard library elements.
using namespace std;

void solve() {
    int H, P;
    // Read Darth's initial health H and Chef's initial attack power P
    cin >> H >> P;

    // Simulate the battle turn by turn
    // The loop continues as long as:
    // 1. Darth's health is positive (H > 0) - meaning Darth is still alive.
    // 2. Chef's attack power is positive (P > 0) - meaning Chef can still attack.
    while (H > 0 && P > 0) {
        H -= P;    // Darth's health decreases by the current attack power
        P /= 2;    // Chef's attack power is halved (integer division automatically handles floor)
    }

    // After the loop terminates, one of the conditions (H > 0 or P > 0) must have become false.

    // If H <= 0, it means Darth's health dropped to 0 or below.
    // This implies Chef dealt enough damage before his attack power ran out.
    if (H <= 0) {
        cout << 1 << "\n"; // Chef wins, print 1
    } else {
        // If H > 0, it means P must have become 0 (since the loop terminated).
        // Chef's attack power ran out while Darth was still alive.
        cout << 0 << "\n"; // Chef loses, print 0
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is crucial for problems with large numbers of test cases or large inputs.
    ios_base::sync_with_stdio(false); // Unties C++ streams from C standard streams
    cin.tie(NULL);                   // Prevents cin from flushing cout before each input operation

    int T;
    cin >> T; // Read the number of test cases

    // Loop T times, calling the solve function for each test case
    while (T--) {
        solve();
    }

    return 0; // Indicate successful program execution
}