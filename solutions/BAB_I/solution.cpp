#include <iostream> // For std::cin, std::cout
#include <algorithm> // For std::min
#include <cmath>    // For std::abs (specifically for long long)
#include <climits>  // For LLONG_MAX

// It's good practice to put the solution logic for a single test case in a function.
void solve() {
    int N;
    std::cin >> N; // Read the number of elements

    long long min_abs_val = LLONG_MAX; // Initialize with the largest possible long long value
                                       // This ensures any abs(A_i) will be smaller.

    bool found_zero = false; // Flag to track if any element is 0

    for (int i = 0; i < N; ++i) {
        long long A_i;
        std::cin >> A_i; // Read each element

        if (A_i == 0) {
            found_zero = true; // If 0 is found, set the flag
        }
        // Update min_abs_val with the minimum of its current value and the absolute value of A_i
        min_abs_val = std::min(min_abs_val, std::abs(A_i));
    }

    if (found_zero) {
        // If any element was 0, no such X exists because 0 is always in [-X, X] for X >= 0.
        std::cout << -1 << "\n";
    } else {
        // If no zero was found, min_abs_val will be at least 1 (since all A_i are non-zero).
        // The condition is |A_i| > X for all i, which means X < |A_i| for all i.
        // This implies X < min(|A_i|).
        // Since X must be an integer, the maximum integer X satisfying X < min(|A_i|) is min(|A_i|) - 1.
        // This value is guaranteed to be non-negative because min_abs_val >= 1.
        std::cout << min_abs_val - 1 << "\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) prevents std::cout from flushing before std::cin reads input.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T; // Read the number of test cases
    while (T--) {
        solve(); // Solve each test case
    }

    return 0;
}