#include <bits/stdc++.h> // Includes iostream, string, algorithm, etc.

// Use the standard namespace as requested
using namespace std;

void solve() {
    int n;
    cin >> n; // Read the length of the strings
    string s, r;
    cin >> s >> r; // Read the binary strings S and R

    // Count the number of '1's in string S
    int s_ones = 0;
    for (char c : s) {
        if (c == '1') {
            s_ones++;
        }
    }
    // Alternatively, using std::count:
    // int s_ones = count(s.begin(), s.end(), '1');

    // Count the number of '1's in string R
    int r_ones = 0;
    for (char c : r) {
        if (c == '1') {
            r_ones++;
        }
    }
    // Alternatively, using std::count:
    // int r_ones = count(r.begin(), r.end(), '1');

    // If the counts of '1's are equal, then S can be transformed into R
    if (s_ones == r_ones) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    // Optimize C++ standard streams for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t; // Read the number of test cases
    while (t--) {
        solve(); // Solve each test case
    }

    return 0;
}