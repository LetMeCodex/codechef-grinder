#include <bits/stdc++.h> // Includes iostream, vector, numeric, etc.

// Use the standard namespace as requested
using namespace std;

void solve() {
    int n;
    cin >> n; // Read N

    // Use long long for B_i values and their sum, as B_i can be up to 2 * 10^10
    // and sum_b can be up to N * max(B_i) = 10^5 * 2 * 10^10 = 2 * 10^15.
    vector<long long> b(n);
    long long sum_b = 0;

    // Read array B and calculate its sum
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        sum_b += b[i];
    }

    // Derivation:
    // Let S = A_1 + A_2 + ... + A_N be the total sum of array A.
    // For any i (1 <= i <= N):
    // f(i) = A_1 + ... + A_i
    // g(i) = A_i + ... + A_N
    // B_i = f(i) + g(i) = (A_1 + ... + A_i) + (A_i + ... + A_N)
    // Notice that A_i is included in both f(i) and g(i).
    // So, B_i = (A_1 + ... + A_N) + A_i = S + A_i.
    //
    // Now, sum B_i over all i from 1 to N:
    // sum(B_i) = sum(S + A_i) for i=1 to N
    // sum(B_i) = (S + A_1) + (S + A_2) + ... + (S + A_N)
    // sum(B_i) = N * S + (A_1 + A_2 + ... + A_N)
    // sum(B_i) = N * S + S
    // sum(B_i) = (N + 1) * S
    //
    // Therefore, S = sum(B_i) / (N + 1).
    // The problem guarantees that a valid array A exists, so sum(B_i) will be divisible by (N+1).
    long long S = sum_b / (n + 1);

    // Recover A_i using A_i = B_i - S
    for (int i = 0; i < n; ++i) {
        cout << b[i] - S << (i == n - 1 ? "" : " "); // Print A_i, space-separated
    }
    cout << "\n"; // Newline after each test case's output
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is crucial for competitive programming problems with large I/O.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t; // Read the number of test cases
    while (t--) {
        solve(); // Solve each test case
    }

    return 0;
}