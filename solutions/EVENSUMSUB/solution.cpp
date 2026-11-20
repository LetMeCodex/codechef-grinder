#include <bits/stdc++.h> // Includes iostream, vector, numeric, algorithm etc.
using namespace std; // Use standard namespace

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    long long total_sum = 0; // Use long long for sum, though int would suffice for given constraints (max sum 50*10^4 = 5*10^5)
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        total_sum += A[i];
    }

    if (total_sum % 2 == 0) {
        // If the total sum of the array is even, the entire array is the largest subarray with an even sum.
        cout << N << "\n";
    } else {
        // If the total sum is odd, we cannot take the entire array.
        // We need to remove a prefix or a suffix such that the remaining sum is even.
        // To change an odd sum to an even sum, we must remove a part whose sum is odd.
        // To maximize the length of the remaining subarray, we must remove the shortest possible prefix/suffix whose sum is odd.
        
        // Find the index of the first odd number from the left.
        // If A[L] is the first odd number from the left, then sum(A[0...L]) is odd.
        // Removing A[0...L] leaves A[L+1...N-1], whose sum is (total_sum - sum(A[0...L])) = odd - odd = even.
        // Its length is N - (L+1).
        int first_odd_idx = -1;
        for (int i = 0; i < N; ++i) {
            if (A[i] % 2 != 0) {
                first_odd_idx = i;
                break;
            }
        }

        // Find the index of the first odd number from the right.
        // If A[R] is the first odd number from the right, then sum(A[R...N-1]) is odd.
        // Removing A[R...N-1] leaves A[0...R-1], whose sum is (total_sum - sum(A[R...N-1])) = odd - odd = even.
        // Its length is R.
        int last_odd_idx = -1;
        for (int i = N - 1; i >= 0; --i) {
            if (A[i] % 2 != 0) {
                last_odd_idx = i;
                break;
            }
        }
        
        // Since total_sum is odd, there must be at least one odd number in the array.
        // Thus, first_odd_idx and last_odd_idx will always be valid indices (not -1).

        // Candidate length 1: Remove prefix up to first_odd_idx.
        // The remaining subarray starts at first_odd_idx + 1 and ends at N-1.
        // Its length is N - (first_odd_idx + 1).
        int len_after_removing_prefix = N - (first_odd_idx + 1);

        // Candidate length 2: Remove suffix from last_odd_idx.
        // The remaining subarray starts at 0 and ends at last_odd_idx - 1.
        // Its length is last_odd_idx.
        int len_after_removing_suffix = last_odd_idx;
        
        cout << max(len_after_removing_prefix, len_after_removing_suffix) << "\n";
    }
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