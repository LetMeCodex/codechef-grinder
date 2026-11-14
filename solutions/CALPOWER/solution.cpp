#include <bits/stdc++.h> // Includes iostream, string, algorithm, etc.

// Using namespace std; as requested
using namespace std;

void solve() {
    string s;
    cin >> s;

    // Sort the string to arrange characters in ascending order of their ord values.
    // This is because 'a' < 'b' < ... < 'z' lexicographically,
    // which corresponds to their ord values.
    sort(s.begin(), s.end());

    long long total_power = 0;
    for (int i = 0; i < s.length(); ++i) {
        // The character at 0-indexed position i is s[i].
        // Its 1-based position in the sorted string is (i+1).
        // Its ord value is (s[i] - 'a' + 1).
        // Cast (i + 1) to long long to ensure the multiplication is done using long long arithmetic
        // before adding to total_power, preventing potential intermediate overflow.
        total_power += (long long)(i + 1) * (s[i] - 'a' + 1);
    }

    cout << total_power << "\n";
}

int main() {
    // Fast I/O as requested
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}