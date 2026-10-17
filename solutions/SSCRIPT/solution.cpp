#include <bits/stdc++.h> // Includes iostream, string, algorithm, etc.

// Using namespace std; as requested by problem statement
using namespace std;

void solve() {
    int N, K;
    cin >> N >> K; // Read N and K
    string S;
    cin >> S; // Read the string S

    int current_consecutive_stars = 0; // Counter for the current sequence of '*'
    int max_consecutive_stars = 0;     // Stores the maximum length found so far

    // Iterate through the string
    for (int i = 0; i < N; ++i) {
        if (S[i] == '*') {
            // If the character is a star, increment the current counter
            current_consecutive_stars++;
        } else {
            // If it's not a star, the current sequence of stars is broken.
            // Update max_consecutive_stars with the length of the just-ended sequence.
            max_consecutive_stars = max(max_consecutive_stars, current_consecutive_stars);
            // Reset the current counter for the next potential sequence.
            current_consecutive_stars = 0;
        }
    }
    // After the loop, there might be a sequence of stars at the very end of the string.
    // We need one final update to ensure this last sequence is considered.
    max_consecutive_stars = max(max_consecutive_stars, current_consecutive_stars);

    // Check if the maximum consecutive stars found is at least K
    if (max_consecutive_stars >= K) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    // Fast I/O as requested by problem statement
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) {
        solve(); // Solve each test case
    }

    return 0;
}