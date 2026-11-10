#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

void solve() {
    int N;
    std::cin >> N; // Read N
    std::vector<int> C(N); // Declare a vector to store item costs
    for (int i = 0; i < N; ++i) {
        std::cin >> C[i]; // Read item costs
    }

    int max_spent = 0; // Initialize max_spent to 0

    // We will use a set to store costs of items encountered so far.
    // This allows us to efficiently find the maximum cost C[k] such that k < i and C[k] <= C[i].
    std::set<int> seen_costs;

    for (int i = 0; i < N; ++i) {
        // Case 1: Chef buys only one item (item i).
        // The maximum single item cost is considered.
        max_spent = std::max(max_spent, C[i]);

        // Case 2: Chef buys two items, with item i being the second item.
        // We need to find a previous item k (k < i) such that C[k] <= C[i].
        // To maximize C[k] + C[i], we need the largest C[k] that satisfies C[k] <= C[i].
        // `seen_costs` contains all C[k] for k < i.
        
        // Find the first element in seen_costs that is strictly greater than C[i].
        auto it = seen_costs.upper_bound(C[i]);

        // If `it` is not the beginning of the set, it means there is at least one element
        // in seen_costs that is less than or equal to C[i].
        if (it != seen_costs.begin()) {
            // Move `it` back one position to point to the largest element <= C[i].
            --it;
            // Update max_spent with the sum of C[i] and the found C[k].
            max_spent = std::max(max_spent, C[i] + *it);
        }

        // Add the current item's cost to the set for future iterations.
        seen_costs.insert(C[i]);
    }

    std::cout << max_spent << "\n"; // Output the maximum amount Chef can spend
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T; // Read the number of test cases
    while (T--) { // Loop through each test case
        solve(); // Solve the current test case
    }

    return 0; // Indicate successful execution
}