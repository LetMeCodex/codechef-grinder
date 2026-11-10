#include <bits/stdc++.h> // Includes iostream, string, etc.

// Using namespace std; as requested
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    // The problem states N >= 2, so we don't need to handle N=0 or N=1 explicitly.
    // The number of distinct strings is 1 + (number of times S[i] != S[i+1]).
    // This is equivalent to counting the number of "blocks" of identical characters.
    // For example, if S = "10110":
    // Blocks are "1", "0", "11", "0". Total 4 blocks.
    //
    // Let's trace the logic:
    // Initial distinct_strings_count = 1 (for the first character/block).
    //
    // For i = 0: S[0] ('1') vs S[1] ('0') -> different, increment count.
    // For i = 1: S[1] ('0') vs S[2] ('1') -> different, increment count.
    // For i = 2: S[2] ('1') vs S[3] ('1') -> same, count remains unchanged.
    // For i = 3: S[3] ('1') vs S[4] ('0') -> different, increment count.
    //
    // The loop iterates from i=0 to n-2.
    // Each time s[i] != s[i+1], it signifies the start of a new block of characters,
    // which means deleting s[i+1] will produce a string distinct from deleting s[i].
    // Thus, we increment our count of distinct strings.

    int distinct_strings_count = 1; // Start with 1 for the first block/character
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] != s[i+1]) {
            distinct_strings_count++;
        }
    }
    cout << distinct_strings_count << "\n";
}

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t; // Read the number of test cases
    while (t--) {
        solve(); // Solve each test case
    }

    return 0;
}