#include <bits/stdc++.h>

using namespace std;

void solve() {
    int X;
    cin >> X; // Read the duration of the lecture

    // The meeting platform supports a meeting of maximum 30 minutes without subscription.
    // If Chef needs a meeting of duration X, and X is greater than 30 minutes,
    // then a subscription is required. Otherwise, it's not.
    if (X > 30) {
        cout << "YES\n"; // Chef needs to take a subscription
    } else {
        cout << "NO\n";  // Chef does not need to take a subscription
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases

    // Loop through each test case
    while (T--) {
        solve(); // Call the solve function for the current test case
    }

    return 0; // Indicate successful execution
}