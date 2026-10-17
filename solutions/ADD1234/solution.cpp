#include <bits/stdc++.h> // Includes iostream, algorithm, etc.
using namespace std;

void solve() {
    int X, Y, Z;
    cin >> X >> Y >> Z;

    // Calculate the maximum number of pairs that sum to 4 using one '1' and one '3'.
    // This is limited by the minimum count of available '1's and '3's.
    int pairs_1_3 = min(X, Z);

    // Calculate the maximum number of pairs that sum to 4 using two '2's.
    // This is limited by half the count of available '2's (integer division).
    int pairs_2_2 = Y / 2;

    // The total maximum number of pairs is the sum of these two independent counts.
    int total_pairs = pairs_1_3 + pairs_2_2;

    cout << total_pairs << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) { // Loop through each test case
        solve();
    }

    return 0;
}