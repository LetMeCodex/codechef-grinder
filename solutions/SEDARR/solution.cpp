#include <bits/stdc++.h> // Includes all standard libraries

// Using namespace std for brevity as requested
using namespace std;

void solve() {
    int N;
    int K; // K up to 10^5, int is sufficient.
    cin >> N >> K;

    long long current_sum = 0; // Max sum is 100 * 10^5 = 10^7. Fits in int, but long long is safer practice.
    for (int i = 0; i < N; ++i) {
        int A_i; // A_i up to 10^5, int is sufficient.
        cin >> A_i;
        current_sum += A_i;
    }

    // If the current sum is already divisible by K, 0 operations are needed.
    if (current_sum % K == 0) {
        cout << 0 << "\n";
    } else {
        // If the current sum is not divisible by K, we can always make it divisible
        // by changing just one element.
        // For example, pick any A_j. We want (current_sum - A_j + A_j') % K == 0.
        // We can always find a positive integer A_j' to satisfy this.
        // Thus, 1 operation is always sufficient if the sum is not already divisible.
        cout << 1 << "\n";
    }
}

int main() {
    // Fast I/O setup as requested
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) { // Loop through each test case
        solve();
    }

    return 0;
}