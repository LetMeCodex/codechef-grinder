#include <bits/stdc++.h> // Required header for competitive programming

// Required namespace usage
using namespace std;

void solve() {
    int N;
    cin >> N;
    long long total_sum_A = 0; // Using long long for sum to be safe, though int is sufficient for given constraints.
    for (int i = 0; i < N; ++i) {
        int A_i;
        cin >> A_i;
        total_sum_A += A_i;
    }

    // The maximum number of breaks is calculated as (total sum of lengths) - (initial number of sticks).
    // Each break operation increases the number of sticks by one.
    // The process of breaking stops when all sticks have a length of 1, as sticks of length 1 cannot be broken further into two positive integer lengths.
    // The total sum of lengths of all sticks remains constant throughout the breaking process.
    // If we start with N sticks and their total length is S = sum(A_i),
    // and we perform K breaks, we will end up with N + K sticks.
    // When the process stops, all N + K sticks will have length 1.
    // Therefore, the total length of these final sticks is (N + K) * 1 = N + K.
    // Since the total length is invariant, S = N + K.
    // Thus, the maximum number of breaks K = S - N.
    long long breaks = total_sum_A - N;
    cout << breaks << "\n";
}

int main() {
    // Fast I/O as required by competitive programming standards
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) { // Loop through each test case
        solve();
    }

    return 0;
}