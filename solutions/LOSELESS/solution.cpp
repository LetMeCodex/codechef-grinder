#include <iostream>
#include <algorithm> // For std::max

// Function to compute ceil(a/b) for integer a and positive integer b.
// C++ integer division truncates towards zero.
// If a is non-negative, ceil(a/b) is (a + b - 1) / b.
// If a is negative, ceil(a/b) is a / b (e.g., ceil(-5/2) = -2, and -5/2 in C++ is -2).
long long ceil_div(long long a, long long b) {
    if (a >= 0) {
        return (a + b - 1) / b;
    } else {
        return a / b;
    }
}

void solve() {
    long long M, N;
    std::cin >> M >> N;

    // Let W = number of wins, T = number of ties, L = number of losses.
    // Total matches: W + T + L = M
    // Total points: 3W + T = N (Losses contribute 0 points)

    // From total points equation, T = N - 3W.
    // Substitute T into total matches equation to find L:
    // L = M - W - T
    // L = M - W - (N - 3W)
    // L = M - N + 2W

    // To minimize L, we need to minimize W.
    // Constraints on W:
    // 1. W >= 0 (Number of wins cannot be negative)
    // 2. T >= 0  => N - 3W >= 0 => 3W <= N => W <= N/3
    // 3. L >= 0  => M - N + 2W >= 0 => 2W >= N - M => W >= (N - M)/2

    // The minimum W must satisfy W >= 0 and W >= ceil((N - M)/2).
    // So, the minimum W is max(0, ceil((N - M)/2)).
    // The problem guarantees that a solution exists, which implies that
    // this minimum W will also satisfy W <= N/3.

    long long W_lower_bound = ceil_div(N - M, 2);
    long long min_W = std::max(0LL, W_lower_bound);

    // Calculate the minimum number of losses using the derived formula and min_W.
    long long min_L = M - N + 2 * min_W;

    std::cout << min_L << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T; // Read the number of test cases.
    while (T--) {
        solve(); // Solve each test case.
    }

    return 0;
}