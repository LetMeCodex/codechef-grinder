#include <bits/stdc++.h> // Includes all standard libraries
using namespace std; // Uses the standard namespace

void solve() {
    int N;
    cin >> N; // Read N

    vector<int> A(N); // Declare a vector of N integers
    for (int i = 0; i < N; ++i) {
        cin >> A[i]; // Read elements into the vector
    }

    sort(A.begin(), A.end()); // Sort the array in non-decreasing order

    // After sorting, A[0] is the smallest, A[N-1] is the largest.
    // A[1] is the second smallest, A[N-2] is the second largest.

    // Case 1: We choose to change the smallest element (A[0]).
    // The remaining N-1 elements are A[1], A[2], ..., A[N-1].
    // The minimum among these is A[1], and the maximum is A[N-1].
    // To minimize max-min, we change A[0] to be any value within [A[1], A[N-1]].
    // The resulting max-min difference will be A[N-1] - A[1].
    int diff1 = A[N-1] - A[1];

    // Case 2: We choose to change the largest element (A[N-1]).
    // The remaining N-1 elements are A[0], A[1], ..., A[N-2].
    // The minimum among these is A[0], and the maximum is A[N-2].
    // To minimize max-min, we change A[N-1] to be any value within [A[0], A[N-2]].
    // The resulting max-min difference will be A[N-2] - A[0].
    int diff2 = A[N-2] - A[0];

    // The overall minimum possible value of max(A) - min(A)
    // is the smaller of these two possibilities.
    // (Changing any other element A[k] where 0 < k < N-1 would result in a difference
    // of A[N-1] - A[0], which is always greater than or equal to diff1 and diff2).
    cout << min(diff1, diff2) << "\n";
}

int main() {
    // Fast I/O to speed up input and output operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) {
        solve(); // Solve each test case
    }

    return 0;
}