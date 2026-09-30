#include <bits/stdc++.h> // Includes iostream, algorithm, etc.

// Using namespace std for convenience in competitive programming
using namespace std;

void solve() {
    int H, X, Y;
    cin >> H >> X >> Y;

    // Strategy 1: Don't use the special attack at all.
    // All damage comes from normal attacks.
    // Number of normal attacks needed = ceil(H / X)
    // Using integer division: (H + X - 1) / X
    int attacks_no_special = (H + X - 1) / X;

    // Strategy 2: Use the special attack exactly once.
    int attacks_with_special;
    if (H - Y <= 0) {
        // If the special attack alone is enough to defeat the boss (or overkills),
        // only 1 attack (the special attack) is needed.
        attacks_with_special = 1;
    } else {
        // The special attack deals Y damage.
        // Remaining health = H - Y.
        // This remaining health must be dealt by normal attacks.
        int remaining_health = H - Y;
        // Number of normal attacks needed for remaining health = ceil(remaining_health / X)
        // Using integer division: (remaining_health + X - 1) / X
        int normal_attacks_after_special = (remaining_health + X - 1) / X;
        // Total attacks = 1 (for special attack) + normal_attacks_after_special
        attacks_with_special = 1 + normal_attacks_after_special;
    }

    // The minimum number of attacks is the better of the two strategies.
    cout << min(attacks_no_special, attacks_with_special) << "\n";
}

int main() {
    // Optimize C++ standard streams for competitive programming.
    // Unties cin from cout and disables synchronization with C stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) { // Loop through each test case
        solve(); // Call the solve function for each test case
    }

    return 0; // Indicate successful execution
}