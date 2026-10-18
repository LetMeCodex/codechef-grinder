#include <bits/stdc++.h> // Includes iostream, algorithm, etc.

// Using namespace std; as per problem instruction
using namespace std;

void solve() {
    int N, l, r;
    cin >> N >> l >> r;

    int current_happiness = 0;
    int max_happiness = 0;
    int min_happiness = 0;

    for (int i = 0; i < N; ++i) {
        int A_i;
        cin >> A_i;

        // Check if A_i is within the loved range [l, r]
        if (A_i >= l && A_i <= r) {
            current_happiness++; // Increase happiness if loved
        } else {
            current_happiness--; // Decrease happiness otherwise
        }

        // Update maximum and minimum happiness encountered so far
        max_happiness = max(max_happiness, current_happiness);
        min_happiness = min(min_happiness, current_happiness);
    }

    // Output the maximum and minimum happiness
    cout << max_happiness << " " << min_happiness << "\n";
}

int main() {
    // Fast I/O as per problem instruction
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) {
        solve(); // Solve each test case
    }

    return 0;
}