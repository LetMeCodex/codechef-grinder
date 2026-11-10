#include <iostream>
#include <algorithm> // Required for std::max

int main() {
    // Optimize C++ standard streams for faster input/output.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t; // Read the number of test cases
    while (t--) { // Loop through each test case
        long long C, D, L;
        std::cin >> C >> D >> L; // Read cats, dogs, and legs

        // Calculate the minimum possible number of legs on the ground.
        // All D dogs are always on the ground.
        // The maximum number of cats that can ride is 2*D.
        // The remaining cats (C - 2*D, if positive) must be on the ground.
        long long cats_standing_min = std::max(0LL, C - 2 * D);
        long long min_total_legs = (cats_standing_min + D) * 4;

        // Calculate the maximum possible number of legs on the ground.
        // This happens when all cats and all dogs are standing.
        long long max_total_legs = (C + D) * 4;

        // Check if the given L is possible.
        // 1. L must be a multiple of 4.
        // 2. L must be within the calculated range [min_total_legs, max_total_legs].
        if (L % 4 == 0 && L >= min_total_legs && L <= max_total_legs) {
            std::cout << "yes\n";
        } else {
            std::cout << "no\n";
        }
    }
    return 0;
}