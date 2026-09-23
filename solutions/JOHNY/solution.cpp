#include <bits/stdc++.h> // Includes iostream, vector, algorithm, iterator, etc.

// Using namespace std as requested by problem instructions
using namespace std;

void solve() {
    int N;
    cin >> N; // Read the number of songs

    vector<int> A(N); // Declare a vector to store song lengths
    for (int i = 0; i < N; ++i) {
        cin >> A[i]; // Read song lengths into the vector
    }

    int K;
    cin >> K; // Read the initial 1-indexed position of "Uncle Johny"

    // K is 1-indexed, so A[K-1] is the length of "Uncle Johny"
    int johny_length = A[K - 1];

    // Sort the array of song lengths in increasing order
    sort(A.begin(), A.end());

    // Find the position of johny_length in the sorted array.
    // Since all lengths are unique, std::lower_bound will return an iterator
    // pointing directly to the element with johny_length.
    auto it = lower_bound(A.begin(), A.end(), johny_length);

    // The 0-indexed position is the distance from the beginning of the vector
    int position_0_indexed = distance(A.begin(), it);

    // Convert to 1-indexed position and print the result
    cout << position_0_indexed + 1 << "\n";
}

int main() {
    // Enable fast I/O as requested by problem instructions
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) {
        solve(); // Solve each test case
    }

    return 0;
}