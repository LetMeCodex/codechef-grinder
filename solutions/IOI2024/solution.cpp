#include <bits/stdc++.h>

using namespace std;

int main() {
    // Optimize C++ standard streams for competitive programming.
    // This unties cin from cout and disables synchronization with C's stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Declare an integer variable X to store the input date.
    int X;

    // Read the date X from standard input.
    cin >> X;

    // The problem states that IOI 2024 is held from September 1st to September 8th, inclusive.
    // This means IOI is ongoing on any date X such that 1 <= X <= 8.
    // The constraints specify that 1 <= X <= 30, so X will always be at least 1.
    // Therefore, we only need to check if X is less than or equal to 8.
    if (X <= 8) {
        // If X is within the range [1, 8], IOI is ongoing.
        cout << "YES\n";
    } else {
        // Otherwise, IOI is not ongoing.
        cout << "NO\n";
    }

    // Return 0 to indicate successful execution.
    return 0;
}