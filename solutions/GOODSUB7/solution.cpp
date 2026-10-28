#include <bits/stdc++.h> // Includes iostream, vector, etc.

using namespace std; // As requested

void solve() {
    int N;
    cin >> N; // Read the length of the array
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i]; // Read array elements
    }

    // Constraints state 1 <= N <= 100, so N will never be 0.
    // Thus, a good subsequence of length at least 1 always exists (any single element).
    // Initialize max_length to 1, as we can always pick at least one element.
    int max_length = 1;
    // Store the parity of the first element chosen for our good subsequence.
    // A[0] is always the first element we consider for our subsequence.
    int last_parity = A[0] % 2; 

    // Iterate from the second element to the end of the array
    for (int i = 1; i < N; ++i) {
        int current_parity = A[i] % 2;
        // If the current element's parity is different from the last chosen element's parity,
        // we can extend our good subsequence.
        if (current_parity != last_parity) {
            max_length++; // Increment the length of the good subsequence
            last_parity = current_parity; // Update the last chosen parity
        }
        // If current_parity == last_parity, we cannot include A[i] right after the
        // previous element, so we skip it and look for the next suitable element.
    }
    cout << max_length << "\n"; // Output the maximum length found
}

int main() {
    // Optimize C++ standard streams for competitive programming.
    // Unties cin from cout and disables synchronization with C stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) { // Loop T times to solve each test case
        solve(); 
    }
    return 0;
}