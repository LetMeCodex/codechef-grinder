#include <iostream>
#include <algorithm> // For std::min if needed, though not strictly here

int main() {
    // Optimize C++ standard streams for competitive programming
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T; // Read the number of test cases
    while (T--) {
        long long N, K, X, Y; // Use long long for N, X, Y to handle large values and intermediate products
        std::cin >> N >> K >> X >> Y; // Read input for each test case

        long long total_cost;

        if (X <= Y) {
            // Red lamps are cheaper or equal.
            // To minimize cost and satisfy "at least K red",
            // we buy all N lamps as red.
            total_cost = N * X;
        } else {
            // Blue lamps are cheaper.
            // We must buy at least K red lamps.
            // To minimize cost, we buy exactly K red lamps
            // and the remaining N-K lamps as blue lamps.
            total_cost = K * X + (N - K) * Y;
        }
        std::cout << total_cost << "\n";
    }
    return 0;
}