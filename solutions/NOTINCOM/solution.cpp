#include <bits/stdc++.h> // Includes iostream, vector, etc.

// Using namespace std; as requested by the problem statement.
using namespace std;

// Max value for Ai, Bi is 10^6.
// We need indices from 1 to 10^6. So array size 10^6 + 1.
// Declared as static global to be zero-initialized once and reused across test cases.
const int MAX_VAL = 1000000;
static bool present_in_B[MAX_VAL + 1]; 

void solve() {
    int N, M;
    cin >> N >> M;

    // Alice's numbers. Storing them in a vector is fine given N <= 10^5.
    // Alternatively, they could be processed one by one without storing the whole vector.
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // Berta's numbers. We need to store them in a vector to:
    // 1. Mark their presence in 'present_in_B'.
    // 2. Efficiently unmark them after processing the current test case.
    vector<int> B_values(M);
    for (int i = 0; i < M; ++i) {
        cin >> B_values[i];
        present_in_B[B_values[i]] = true;
    }

    int common_count = 0;
    // Iterate through Alice's numbers and check if they are present in Berta's collection.
    for (int i = 0; i < N; ++i) {
        if (present_in_B[A[i]]) {
            common_count++;
        }
    }

    // Output the minimal amount of numbers Alice needs to throw away.
    cout << common_count << "\n";

    // Reset 'present_in_B' for the next test case.
    // Only the elements that were marked 'true' in this test case need to be reset.
    for (int i = 0; i < M; ++i) {
        present_in_B[B_values[i]] = false;
    }
}

int main() {
    // Fast I/O as requested.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases.
    while (T--) { // Loop through each test case.
        solve();
    }

    return 0;
}