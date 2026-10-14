#include <bits/stdc++.h> // Includes most standard libraries

using namespace std; // Common in competitive programming

void solve() {
    int N, M;
    cin >> N >> M;

    // A chocolate bar of size N x M can be divided into 2 equal pieces
    // if a cut can be made either horizontally or vertically such that
    // the two resulting pieces have equal dimensions.

    // Case 1: Horizontal cut
    // If N is even, we can cut the N rows into N/2 and N/2.
    // This results in two pieces of size (N/2) x M. These are equal.
    // So, if N % 2 == 0, it's possible.

    // Case 2: Vertical cut
    // If M is even, we can cut the M columns into M/2 and M/2.
    // This results in two pieces of size N x (M/2). These are equal.
    // So, if M % 2 == 0, it's possible.

    // If either N is even OR M is even, it's possible to make such a cut.
    // If both N and M are odd, then N*M is odd, meaning the total number of pieces
    // is odd. It's impossible to divide an odd number of pieces into two equal integer parts.
    // In this case, neither N nor M is even, so no valid cut can be made.

    if (N % 2 == 0 || M % 2 == 0) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
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