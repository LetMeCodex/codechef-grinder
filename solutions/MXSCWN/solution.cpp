#include <bits/stdc++.h> // Includes iostream, vector, numeric, algorithm etc.

using namespace std; // As requested

void solve() {
    int N;
    cin >> N; // Read N

    vector<int> A(N);
    long long total_A_sum = 0;
    // Read A_i values and calculate their sum
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        total_A_sum += A[i];
    }

    vector<int> B(N);
    // Initialize min_penalty with a value larger than any possible penalty.
    // Max A_i - B_i is 100 - 1 = 99. So 101 is a safe initial value.
    int min_penalty = 101; 
    // Read B_i values and find the minimum penalty (A_i - B_i)
    for (int i = 0; i < N; ++i) {
        cin >> B[i];
        int penalty = A[i] - B[i];
        min_penalty = min(min_penalty, penalty); // Update min_penalty if current penalty is smaller
    }

    // The maximum score is the sum of all A_i minus the minimum penalty incurred by losing one match.
    long long max_score = total_A_sum - min_penalty;
    cout << max_score << "\n"; // Output the result
}

int main() {
    // Fast I/O setup as requested
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) {
        solve(); // Solve each test case
    }

    return 0;
}