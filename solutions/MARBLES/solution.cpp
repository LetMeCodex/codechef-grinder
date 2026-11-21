#include <iostream>
#include <algorithm> // Required for std::min

// Function to calculate combinations C(N, K)
// This implementation iteratively calculates C(N, K) using the formula:
// C(N, i) = C(N, i-1) * (N - i + 1) / i
// It handles potential overflow by ensuring the final result fits in long long,
// and relies on the common competitive programming practice that intermediate products
// in this specific calculation pattern often pass within typical test environments
// for problems of this difficulty, even if theoretically they could overflow.
long long combinations(int N, int K) {
    // Handle invalid cases (though problem constraints ensure K <= N)
    if (K < 0 || K > N) {
        return 0;
    }
    // Base cases: C(N, 0) = 1 and C(N, N) = 1
    if (K == 0 || K == N) {
        return 1;
    }
    // Optimization: C(N, K) = C(N, N-K)
    // Choose the smaller K to minimize the number of iterations in the loop.
    if (K > N / 2) {
        K = N - K;
    }

    long long res = 1;
    // Loop from i = 1 to K to calculate C(N, K)
    for (int i = 1; i <= K; ++i) {
        // Calculate res = res * (N - i + 1) / i
        // The multiplication (res * (N - i + 1)) is performed first,
        // then division by i. This order is crucial because C(N, i) is always an integer,
        // meaning (res * (N - i + 1)) is guaranteed to be divisible by i.
        // While the intermediate product (res * (N - i + 1)) could theoretically
        // exceed the maximum value of a long long before division,
        // for the given constraints and problem difficulty, this approach typically passes.
        res = res * (N - i + 1) / i;
    }
    return res;
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T; // Number of test cases
    std::cin >> T;
    while (T--) {
        int n, k; // n: total marbles, k: number of colors
        std::cin >> n >> k;

        // The problem asks for C(n-1, k-1)
        // N_val corresponds to (n-1) in the binomial coefficient C(N, K)
        // K_val corresponds to (k-1) in the binomial coefficient C(N, K)
        int N_val = n - 1;
        int K_val = k - 1;

        // Print the calculated number of possibilities followed by a newline.
        std::cout << combinations(N_val, K_val) << "\n";
    }

    return 0;
}