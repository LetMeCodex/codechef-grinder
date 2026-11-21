#include <iostream>
#include <vector>
#include <numeric> // Not strictly needed for this solution, but often useful
#include <algorithm> // Not strictly needed for this solution, but often useful

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> p(n);

    if (n % 4 == 0) {
        // Construction for N % 4 == 0
        // For 0-indexed array P:
        // P[i] = N/2 - i for 0 <= i < N/2
        // P[N-1-i] = N - i for 0 <= i < N/2
        // This pairs (N/2, N), (N/2-1, N-1), ..., (1, N/2+1)
        // Example N=4:
        // i=0: P[0] = 2, P[3] = 4
        // i=1: P[1] = 1, P[2] = 3
        // Result: [2, 1, 3, 4]
        for (int i = 0; i < n / 2; ++i) {
            p[i] = n / 2 - i;         // Assigns N/2, N/2-1, ..., 1 to P[0]...P[N/2-1]
            p[n - 1 - i] = n - i;     // Assigns N, N-1, ..., N/2+1 to P[N-1]...P[N/2]
        }
    } else { // n % 4 == 2
        // Construction for N % 4 == 2
        // For 0-indexed array P:
        // P[i] = i/2 + 1 if i is even
        // P[i] = N - (i-1)/2 if i is odd
        // Example N=6:
        // i=0 (even): P[0]=1
        // i=1 (odd): P[1]=6
        // i=2 (even): P[2]=2
        // i=3 (odd): P[3]=5
        // i=4 (even): P[4]=3
        // i=5 (odd): P[5]=4
        // Result: [1, 6, 2, 5, 3, 4]
        for (int i = 0; i < n; ++i) {
            if (i % 2 == 0) { // Even index
                p[i] = i / 2 + 1;
            } else { // Odd index
                p[i] = n - (i - 1) / 2;
            }
        }
    }

    // Output the permutation
    for (int i = 0; i < n; ++i) {
        std::cout << p[i] << (i == n - 1 ? "" : " ");
    }
    std::cout << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t; // Read the number of test cases
    while (t--) {
        solve(); // Solve each test case
    }
    return 0;
}