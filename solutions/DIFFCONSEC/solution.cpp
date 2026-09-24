#include <bits/stdc++.h> // Required header
using namespace std;     // Required namespace

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int operations = 0;
    // Iterate through the string to check adjacent characters.
    // The loop runs from i = 0 to n-2, checking pairs (s[i], s[i+1]).
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] == s[i+1]) {
            operations++;
            // When s[i] == s[i+1], we must perform an operation.
            // This operation involves inserting a character (e.g., '1' if s[i]=='0')
            // between s[i] and s[i+1].
            // Example: "00" -> "010".
            // This fixes the current pair (s[i], s[i+1]).
            // The character s[i+1] (original) is now preceded by the inserted character.
            // However, s[i+1] is still followed by s[i+2] (original).
            // The pair (s[i+1], s[i+2]) might still be problematic (e.g., "000").
            // "000" -> "0100" (1 op). Now we need to check the next pair.
            // The next pair to check is effectively (s[i+1], s[i+2]) from the original string.
            // The loop's `++i` naturally moves to `i+1` for the next iteration,
            // which correctly checks `s[i+1]` against `s[i+2]`.
            // No extra `i++` is needed here.
        }
    }
    cout << operations << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); // Fast I/O
    cin.tie(NULL);                   // Untie cin from cout

    int t;
    cin >> t; // Read the number of test cases
    while (t--) {
        solve(); // Solve each test case
    }
    return 0;
}