#include <bits/stdc++.h> // Required include for competitive programming

// Required namespace
using namespace std;

// Function to solve a single test case
void solve() {
    int X, Y;
    // Read the maximum rebatable amount X and the actual damage cost Y
    cin >> X >> Y;

    // According to the policy:
    // - If the amount required for repairing the damage (Y) is <= X lakhs,
    //   that amount (Y) is rebated in full.
    // - If the amount required for repairing the damage (Y) is > X lakhs,
    //   only the maximum rebatable amount (X) is rebated.
    // This logic can be concisely expressed as the minimum of X and Y.
    cout << min(X, Y) << "\n";
}

int main() {
    // Optimize C++ standard streams for competitive programming.
    // This unties cin/cout from the C standard streams and prevents flushing
    // cout before cin, leading to faster input/output operations.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    // Read the number of test cases
    cin >> t;
    // Loop through each test case
    while (t--) {
        solve();
    }

    return 0;
}