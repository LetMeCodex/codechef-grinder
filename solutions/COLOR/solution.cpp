#include <bits/stdc++.h> // Includes iostream, string, algorithm, etc.

using namespace std; // Use standard namespace

void solve() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    int countR = 0;
    int countG = 0;
    int countB = 0;

    // Count occurrences of each color
    for (char c : S) {
        if (c == 'R') {
            countR++;
        } else if (c == 'G') {
            countG++;
        } else { // c == 'B'
            countB++;
        }
    }

    // The minimum number of rooms to repaint is achieved by choosing the target color
    // that is already present in the maximum number of rooms.
    // The number of repaints will be N - (count of the most frequent color).
    int max_count = max({countR, countG, countB}); 

    cout << N - max_count << "\n";
}

int main() {
    // Fast I/O: Unties cin/cout from C stdio and disables synchronization.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) { // Loop through each test case
        solve();
    }

    return 0;
}