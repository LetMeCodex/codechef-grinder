#include <bits/stdc++.h> // Includes iostream, vector, algorithm, limits, etc.
using namespace std; // Use standard namespace for brevity

void solve() {
    int N;
    cin >> N;

    // Initialize min_val with the maximum possible integer value
    // to ensure any A[i] will be smaller.
    int min_val = numeric_limits<int>::max(); 
    int min_idx = -1; // To store the 1-based index of the minimum element

    for (int i = 1; i <= N; ++i) {
        int current_A_val;
        cin >> current_A_val;

        // If the current element is strictly less than the current minimum,
        // update min_val and min_idx. This correctly finds the
        // smallest index if there are multiple occurrences of the minimum value.
        if (current_A_val < min_val) {
            min_val = current_A_val;
            min_idx = i;
        }
    }
    cout << min_idx << "\n"; // Output the 1-based index
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Number of test cases
    cin >> T;
    while (T--) { // Loop through each test case
        solve();
    }

    return 0;
}