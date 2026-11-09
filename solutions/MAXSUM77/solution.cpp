#include <bits/stdc++.h> // Includes iostream, vector, algorithm, numeric etc.

// It's common in competitive programming to use `using namespace std;`
// for brevity, though in larger projects, explicit `std::` prefix is preferred.
using namespace std;

void solve() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // Calculate prefix sums.
    // pref[j] will store the sum of elements A[0]...A[j-1].
    // pref[0] = 0 (sum of an empty prefix).
    // This allows calculating sum of A[L...R] as pref[R+1] - pref[L].
    vector<long long> pref(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        pref[i + 1] = pref[i] + A[i];
    }

    long long max_sum = 0; // Initialize with 0, as A_i >= 1, sums will be positive.

    // We need to remove K elements in total.
    // Let 'i' be the number of elements removed from the beginning.
    // Then, 'K - i' elements must be removed from the end.
    // 'i' can range from 0 (remove all K from end) to K (remove all K from beginning).
    for (int i = 0; i <= K; ++i) {
        // 'start_idx' is the 0-indexed position of the first remaining element.
        // If 'i' elements are removed from the beginning, the first remaining element is A[i].
        int start_idx = i;
        
        // 'end_idx' is the 0-indexed position of the last remaining element.
        // If 'K - i' elements are removed from the end,
        // the original array has N elements (0 to N-1).
        // The last (K-i) elements are A[N-(K-i)], ..., A[N-1].
        // So, the last remaining element is A[N - (K - i) - 1].
        int end_idx = N - (K - i) - 1;

        // The sum of elements from A[start_idx] to A[end_idx] (inclusive)
        // using prefix sums is pref[end_idx + 1] - pref[start_idx].
        long long current_sum = pref[end_idx + 1] - pref[start_idx];
        
        // Update the maximum sum found so far.
        max_sum = max(max_sum, current_sum);
    }

    cout << max_sum << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common competitive programming optimization.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Number of test cases
    cin >> T;
    while (T--) {
        solve(); // Solve each test case
    }

    return 0;
}