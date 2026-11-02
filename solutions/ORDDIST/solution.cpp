#include <bits/stdc++.h> // Includes iostream, vector, cmath, algorithm, utility, etc.

// Use standard namespace as requested
using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<int> X(N);
    for (int i = 0; i < N; ++i) {
        cin >> X[i];
    }
    vector<int> Y(N);
    for (int i = 0; i < N; ++i) {
        cin >> Y[i];
    }

    int found_pivot_index = -1;

    // Iterate through each possible pivot X[k] (0-indexed)
    for (int k = 0; k < N; ++k) {
        int P = X[k]; // The pivot value
        
        vector<pair<int, int>> L;
        L.reserve(N); // Pre-allocate memory for efficiency

        // Populate list L with (distance, value) pairs
        for (int j = 0; j < N; ++j) {
            L.push_back({abs(X[j] - P), X[j]});
        }

        // Sort L according to the problem's criteria.
        // std::pair's default comparison works exactly as required:
        // first by first element, then by second element if first elements are equal.
        sort(L.begin(), L.end());

        // Construct the candidate Y sequence from the sorted pairs
        vector<int> Y_candidate(N);
        for (int j = 0; j < N; ++j) {
            Y_candidate[j] = L[j].second;
        }

        // Compare Y_candidate with the given Y
        bool match = true;
        for (int j = 0; j < N; ++j) {
            if (Y_candidate[j] != Y[j]) {
                match = false;
                break; // Mismatch found, no need to check further
            }
        }

        if (match) {
            found_pivot_index = k + 1; // Pivot index is 1-based
            break; // Found a valid pivot, no need to check other pivots
        }
    }

    cout << found_pivot_index << "\n";
}

int main() {
    // Fast I/O setup as requested
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}