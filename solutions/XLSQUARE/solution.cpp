#include <bits/stdc++.h> // Includes iostream, cmath, etc. as requested

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin from cout and prevents synchronization with C's stdio.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T; // Read the number of test cases

    while (T--) {
        int N, A;
        std::cin >> N >> A; // Read N and A for the current test case

        // Calculate k, the largest integer such that k*k <= N.
        // This is equivalent to k = floor(sqrt(N)).
        // We add a small epsilon (1e-9) to sqrt(N) before casting to int.
        // This helps to mitigate potential floating-point precision errors
        // where sqrt(N) might be slightly less than an integer (e.g., 2.999... for sqrt(9)),
        // which would incorrectly floor to (integer - 1).
        int k = static_cast<int>(sqrt(N) + 1e-9);

        // After casting, k might still be one too high if sqrt(N) was very close to
        // (integer + 1) and the epsilon pushed it over, or if sqrt(N) was a perfect integer
        // and the epsilon made it slightly larger, causing an incorrect round-up.
        // This check ensures that k*k does not exceed N. If it does, we decrement k.
        // N is up to 10^5, so k is at most 316. k*k is at most 316*316 = 99856,
        // which fits comfortably in an 'int'.
        if (k * k > N) {
            k--;
        }

        // The side length of the largest mega square is k * A.
        // Max k*A = 316 * 10^4 = 3,160,000, which also fits in an 'int'.
        std::cout << k * A << "\n"; // Print the result followed by a newline
    }

    return 0; // Indicate successful execution
}