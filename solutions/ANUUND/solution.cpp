#include <bits/stdc++.h> // Includes iostream, vector, algorithm, etc.

using namespace std; // Use standard namespace

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // Iterate through the array up to N-2 to check pairs (A[i], A[i+1])
    // The loop condition N-1 ensures we always access A[i] and A[i+1] safely.
    // For N=1, the loop (i < N-1) will not execute, which is correct as there are no pairs to check.
    for (int i = 0; i < N - 1; ++i) {
        if (i % 2 == 0) { // Even index: A[i] <= A[i+1]
            if (A[i] > A[i+1]) {
                swap(A[i], A[i+1]);
            }
        } else { // Odd index: A[i] >= A[i+1]
            if (A[i] < A[i+1]) {
                swap(A[i], A[i+1]);
            }
        }
    }

    // Output the rearranged array
    for (int i = 0; i < N; ++i) {
        cout << A[i] << (i == N - 1 ? "" : " "); // Print space between numbers, no space after last
    }
    cout << "\n"; // Newline after each test case output
}

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) { // Loop through each test case
        solve();
    }

    return 0;
}