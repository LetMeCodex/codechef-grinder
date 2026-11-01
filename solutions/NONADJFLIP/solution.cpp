#include <bits/stdc++.h> // Includes iostream, string, etc.

// Using namespace std; is requested by the problem statement.
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    bool has_one = false;
    // Check if the string contains any '1's
    for (char c : s) {
        if (c == '1') {
            has_one = true;
            break; // Found a '1', no need to check further
        }
    }

    if (!has_one) {
        // If no '1's, string is already all '0's.
        cout << 0 << "\n";
        return;
    }

    // If we reach here, there is at least one '1'.
    // Now, check for adjacent '1's.
    bool has_adjacent_ones = false;
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] == '1' && s[i+1] == '1') {
            has_adjacent_ones = true;
            break; // Found adjacent '1's, no need to check further
        }
    }

    if (has_adjacent_ones) {
        // If there are adjacent '1's, we need 2 operations.
        cout << 2 << "\n";
    } else {
        // If there are '1's but no adjacent '1's, we need 1 operation.
        cout << 1 << "\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t; // Read the number of test cases.
    while (t--) {
        solve(); // Solve each test case.
    }
    return 0;
}