#include <iostream> // Required for standard input/output operations

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T; // Read the number of testcases

    while (T--) {
        long long X, K;
        std::cin >> X >> K; // Read X and K for the current testcase

        // Calculate N = X * K.
        // N can be up to 10^9 (10^8 * 10^8 is not possible due to X*K <= 10^9 constraint),
        // so 'long long' is appropriate for N to avoid overflow if X or K are large.
        long long N = X * K;

        // Calculate the minimum LCM:
        // As derived, the minimum LCM is 2 * X.
        // This is achieved by picking i = X and j = 2X.
        // This pair is always valid because:
        // 1. X <= X (true)
        // 2. X < 2X (true for X >= 1)
        // 3. 2X <= N (true because N = X * K and K >= 2, so N >= 2X)
        // The result 2*X can be up to 2 * 10^8, which fits in 'long long'.
        long long min_lcm = 2 * X;

        // Calculate the maximum LCM:
        // As derived, the maximum LCM is (N - 1) * N.
        // This is achieved by picking i = N - 1 and j = N.
        // This pair is always valid because:
        // 1. X <= N - 1 (true, as N >= 2X and X >= 1 implies N-1 >= X)
        // 2. N - 1 < N (true)
        // 3. N <= N (true)
        // For consecutive integers, GCD(N-1, N) = 1, which minimizes the denominator
        // in LCM(i, j) = (i * j) / GCD(i, j).
        // The product (N-1) * N can be up to (10^9 - 1) * 10^9 approx 10^18,
        // which requires 'long long'.
        long long max_lcm = (N - 1) * N;

        // Output the minimum and maximum LCM values, separated by a space,
        // followed by a newline character.
        std::cout << min_lcm << " " << max_lcm << "\n";
    }

    return 0; // Indicate successful execution
}