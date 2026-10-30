#include <bits/stdc++.h> // Includes common headers like iostream, numeric, etc.

using namespace std; // Use standard namespace

void solve() {
    int N;
    cin >> N; // Read the length of the array

    long long sum_A = 0; // Initialize sum of array A. Using long long for safety, though int is sufficient.
    for (int i = 0; i < N; ++i) {
        int A_i;
        cin >> A_i; // Read each element
        sum_A += A_i; // Add to the total sum
    }

    if (sum_A >= 0) {
        // If the initial sum is already non-negative, no X is needed.
        // The minimum non-negative X is 0.
        cout << 0 << "\n";
    } else {
        // If the initial sum is negative, we need to find X such that S_A + N*X >= 0
        // This means N*X >= -S_A
        // X >= -S_A / N
        // Since X must be an integer, X = ceil(-S_A / N)
        // For positive integers 'a' and 'b', ceil(a/b) can be computed as (a + b - 1) / b using integer division.
        // Here, 'a' is -sum_A (which is positive because sum_A is negative)
        // 'b' is N (which is positive)
        long long required_sum_increase = -sum_A;
        long long X = (required_sum_increase + N - 1) / N;
        cout << X << "\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) {
        solve(); // Solve each test case
    }

    return 0; // Indicate successful execution
}