#include <bits/stdc++.h> // Includes iostream, string, vector, algorithm etc.

// The problem statement explicitly asks for 'using namespace std;'
using namespace std; 

void solve() {
    int N, Q;
    cin >> N >> Q; // Use cin directly due to 'using namespace std;'
    string S;
    cin >> S;

    // Variables to keep track of the state
    int overall_max_len = 0;
    char last_char = '\0'; // Initialize with a character that won't match any input ('a'-'z')
    int current_suffix_len = 0;

    // Calculate initial state for S
    // N >= 1 according to constraints, so S is never empty.
    // Initialize with the first character of S
    last_char = S[0];
    current_suffix_len = 1;
    overall_max_len = 1; // Minimum length of a beautiful substring is 1 if N > 0

    // Iterate from the second character to calculate initial overall_max_len
    // and the state of the suffix
    for (int i = 1; i < N; ++i) {
        if (S[i] == last_char) {
            current_suffix_len++;
        } else {
            last_char = S[i];
            current_suffix_len = 1;
        }
        overall_max_len = max(overall_max_len, current_suffix_len); // Use max directly
    }

    vector<int> results;
    results.push_back(overall_max_len); // Store A_0

    // Process queries
    for (int k = 0; k < Q; ++k) {
        char c_new;
        cin >> c_new; // Read the character to append

        if (c_new == last_char) {
            current_suffix_len++; // Extend the current beautiful suffix
        } else {
            last_char = c_new; // Start a new beautiful suffix
            current_suffix_len = 1;
        }
        overall_max_len = max(overall_max_len, current_suffix_len); // Update overall max
        results.push_back(overall_max_len); // Store A_k
    }

    // Print results
    for (int i = 0; i < results.size(); ++i) {
        cout << results[i] << (i == results.size() - 1 ? "" : " ");
    }
    cout << "\n"; // Use "\n" instead of endl for performance
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) {
        solve(); // Solve each test case
    }

    return 0;
}