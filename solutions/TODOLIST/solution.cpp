#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t; // Read the number of test cases
    while (t--) {
        int n;
        std::cin >> n; // Read the number of problems
        int problems_to_remove = 0;
        for (int i = 0; i < n; ++i) {
            int difficulty;
            std::cin >> difficulty; // Read the difficulty of each problem
            // If the difficulty is 1000 or greater, it needs to be removed
            if (difficulty >= 1000) {
                problems_to_remove++;
            }
        }
        std::cout << problems_to_remove << "\n"; // Output the count of problems to remove
    }
    return 0;
}