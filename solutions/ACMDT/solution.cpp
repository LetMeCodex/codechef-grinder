#include <iostream>
#include <algorithm> // For std::max and std::min
#include <vector>    // For std::max({initializer_list})

// Function for ceiling division (a / b) for positive integers
long long ceil_div(long long a, long long b) {
    // This handles cases where a is 0 correctly (0/b = 0)
    // and positive a, b.
    // For a=0, b>0: (0+b-1)/b = (b-1)/b = 0.
    // For a>0, b>0: (a+b-1)/b correctly computes ceil(a/b).
    return (a + b - 1) / b;
}

void solve() {
    long long B, G, X, Y, N;
    std::cin >> B >> G >> X >> Y >> N;

    // Initial check: A single room must be able to satisfy minimum boy and girl counts
    // and total capacity. If X boys and Y girls are placed, total people is X+Y.
    // This must not exceed N.
    if (X + Y > N) {
        std::cout << -1 << "\n";
        return;
    }

    // Calculate upper bound for K (number of rooms)
    // Each room must have at least X boys and at least Y girls.
    // So, K rooms can accommodate at most K*X boys and K*Y girls.
    // Thus, B >= K*X  => K <= B/X
    // And G >= K*Y  => K <= G/Y
    // K_upper_bound is the minimum of these two maximums.
    long long k_upper_bound = std::min(B / X, G / Y);

    // Calculate lower bounds for K (number of rooms)
    // 1. Each room can have at most N-Y boys (because it must have at least Y girls).
    //    To accommodate B boys, we need at least ceil(B / (N-Y)) rooms.
    long long k_lower_bound_boys = ceil_div(B, N - Y);

    // 2. Each room can have at most N-X girls (because it must have at least X boys).
    //    To accommodate G girls, we need at least ceil(G / (N-X)) rooms.
    long long k_lower_bound_girls = ceil_div(G, N - X);

    // 3. Each room can have at most N people in total.
    //    To accommodate B+G people, we need at least ceil((B+G) / N) rooms.
    long long k_lower_bound_total_people = ceil_div(B + G, N);

    // K_lower_bound is the maximum of these three minimums.
    // Note: N-Y, N-X, N are guaranteed to be positive if X+Y <= N.
    // If X+Y <= N, then X <= N-Y. Since X >= 1, N-Y >= 1.
    // Similarly, Y <= N-X. Since Y >= 1, N-X >= 1.
    // Also N >= X+Y >= 1+1 = 2. So N >= 1.
    // Thus, no division by zero or negative denominators.
    long long k_lower_bound = std::max({k_lower_bound_boys, k_lower_bound_girls, k_lower_bound_total_people});

    // If the minimum required rooms (k_lower_bound) is greater than
    // the maximum possible rooms (k_upper_bound), then it's impossible.
    if (k_lower_bound > k_upper_bound) {
        std::cout << -1 << "\n";
    } else {
        // Otherwise, the minimum number of rooms is k_lower_bound.
        std::cout << k_lower_bound << "\n";
    }
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