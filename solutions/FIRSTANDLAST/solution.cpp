#include <bits/stdc++.h> // Includes common headers like iostream, vector, algorithm

// It's common practice in competitive programming to use `using namespace std;` globally.
using namespace std;

void solve() {
    int N;
    cin >> N;
    // Using long long for array elements to be safe, as A_i can be up to 10^9.
    // The sum A_i + A_j can be up to 2 * 10^9, which fits in a 32-bit signed int,
    // but using long long for sums is a good general practice to prevent overflow.
    vector<long long> A(N); 
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    long long max_sum = 0; // A_i >= 1, so the minimum possible sum is 1+1=2. Initializing with 0 is safe.

    // Iterate through all possible pairs (A[i], A[j]) that can become (A_1, A_N)
    // after some rotations. These pairs are always adjacent elements in the original
    // array, considering it cyclically.
    // Specifically, if A[i] becomes the first element (A_1), then the element
    // immediately preceding A[i] in the cyclic array becomes the last element (A_N).
    // In 0-based indexing, the element preceding A[i] is A[(i - 1 + N) % N].
    // The (i - 1 + N) % N ensures correct positive modulo for i=0 (A[-1] becomes A[N-1]).
    for (int i = 0; i < N; ++i) {
        long long current_sum = A[i] + A[(i - 1 + N) % N];
        max_sum = max(max_sum, current_sum);
    }

    cout << max_sum << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t; // Read the number of test cases
    while (t--) { // Loop through each test case
        solve();
    }

    return 0;
}