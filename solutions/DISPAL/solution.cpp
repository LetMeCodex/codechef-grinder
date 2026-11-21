#include <bits/stdc++.h> // Includes all standard libraries

// Using namespace std for convenience as requested
using namespace std;

void solve() {
    int N, X;
    cin >> N >> X;

    // The number of distinct characters in a palindrome is determined by the distinct characters
    // in its first half (specifically, the first ceil(N/2) characters).
    // Let mid_len = ceil(N/2). Using integer division, this is (N+1)/2.
    // We need to use X distinct characters. The maximum number of distinct characters
    // we can use in the first mid_len positions is mid_len itself.
    // So, if X > mid_len, it's impossible to have X distinct characters.
    int mid_len = (N + 1) / 2;

    if (X > mid_len) {
        cout << -1 << "\n";
        return;
    }

    // If it's possible, construct the palindrome.
    // We will use the first X lowercase letters ('a', 'b', ..., 'a'+X-1)
    // to fill the initial part of the string.
    // For the remaining characters in the first half (if any), we can just use 'a'.
    // This ensures that exactly X distinct characters are used.
    
    string result(N, ' '); // Initialize string of length N with spaces

    // Fill the first X characters of the string with 'a', 'b', ..., 'a'+X-1
    for (int i = 0; i < X; ++i) {
        result[i] = 'a' + i;
    }

    // Fill the remaining characters in the first half (from index X up to mid_len-1) with 'a'.
    // This character 'a' is already one of the X distinct characters used.
    // This loop only runs if X < mid_len.
    for (int i = X; i < mid_len; ++i) {
        result[i] = 'a';
    }

    // Complete the palindrome by mirroring the first half to the second half.
    // For a palindrome, S[i] == S[N-1-i].
    // We only need to iterate up to mid_len - 1 because the characters from mid_len onwards
    // are determined by the characters before mid_len.
    for (int i = 0; i < mid_len; ++i) {
        result[N - 1 - i] = result[i];
    }

    cout << result << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}