#include <iostream>
#include <vector>
#include <numeric> // For std::gcd in C++17, though not strictly needed for this solution.
#include <algorithm> // For std::sort, not strictly needed for this solution.

void solve() {
    int N;
    long long X; // X can be up to 2*N-1. For N=1000, X can be 1999. int is sufficient for X.
    std::cin >> N >> X;

    // The minimum possible sum of GCDs is N.
    // This occurs when P_1 = 1, making F_1 = 1, and all subsequent F_i = 1.
    // Example: P = [1, 2, ..., N]. Sum = 1 + 1 + ... + 1 = N.
    if (X < N) {
        std::cout << -1 << "\n";
        return;
    }

    // The maximum possible sum of GCDs is 2*N - 1.
    // This occurs when P_1 = N, making F_1 = N.
    // If P_2 = N-1, then F_2 = gcd(N, N-1) = 1.
    // All subsequent F_i will also be 1.
    // Example: P = [N, N-1, N-2, ..., 1]. Sum = N + 1 + 1 + ... + 1 = N + (N-1) = 2*N - 1.
    // The problem constraints state 1 <= X <= 2*N - 1.
    // We've established that if X < N, it's impossible.
    // If N <= X <= 2*N - 1, a solution always exists.

    // We want to construct a permutation such that F_1 = K and F_i = 1 for i = 2, ..., N.
    // The sum for such a permutation would be K + (N-1)*1 = K + N - 1.
    // We need this sum to be equal to X.
    // So, X = K + N - 1, which implies K = X - N + 1.
    // This K will be our P_1.
    // Since N <= X <= 2*N - 1, K will always be in the range [1, N].

    int K = X - N + 1;

    // The permutation will be constructed as:
    // P_1 = K
    // P_2 = 1 (if K != 1, to make gcd(K,1)=1)
    // P_3, ..., P_N are the remaining numbers from {2, ..., N} (excluding K if K != 1) in increasing order.
    // This ensures F_1 = K.
    // If K != 1, then P_2 = 1. F_2 = gcd(K, 1) = 1.
    // If F_2 = 1, then F_3 = gcd(F_2, P_3) = gcd(1, P_3) = 1, and so on.
    // All F_i for i >= 2 will be 1.
    // If K = 1, then P_1 = 1. F_1 = 1.
    // Then P_2 = 2. F_2 = gcd(1, 2) = 1.
    // All F_i for i >= 1 will be 1.
    // This construction works for all N <= X <= 2*N - 1.

    std::cout << K; // Print P_1 = K

    // If K is not 1, we use 1 as P_2 to make F_2 = 1.
    // If K is 1, then 1 is already printed as P_1, so we don't print 1 again.
    if (K != 1) {
        std::cout << " " << 1;
    }

    // Print the remaining numbers from 2 to N, excluding K (and 1 if K != 1).
    // The numbers to consider are 2, 3, ..., N.
    // We iterate through them and print if they are not K.
    // - If K=1: 1 is printed. We then print 2, 3, ..., N.
    // - If K!=1: K and 1 are printed. We then print 2, 3, ..., N, skipping K.
    for (int i = 2; i <= N; ++i) {
        if (i != K) {
            std::cout << " " << i;
        }
    }
    std::cout << "\n";
}

int main() {
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}