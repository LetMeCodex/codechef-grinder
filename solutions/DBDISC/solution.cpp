#include <iostream> // Required for cin, cout
#include <vector>   // Required for std::vector
#include <algorithm> // Required for std::max, std::min

// Function to solve a single test case
void solve() {
    int N, K;
    std::cin >> N >> K; // Read N (number of food items) and K (Chef's budget)

    // Read item costs A_i into a vector
    std::vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> A[i];
    }

    // Read item tastiness values B_i into a vector
    std::vector<int> B(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> B[i];
    }

    int max_tastiness = 0; // Initialize maximum tastiness found to 0.
                            // This handles the case where no pair fits the budget.

    // Iterate through all unique pairs of items (i, j)
    // The outer loop picks the first item (index i).
    for (int i = 0; i < N; ++i) {
        // The inner loop picks the second item (index j), ensuring j is always greater than i
        // to avoid duplicate pairs (e.g., (0,1) and (1,0) are the same) and self-pairing.
        for (int j = i + 1; j < N; ++j) {
            int cost1 = A[i];
            int tastiness1 = B[i];
            int cost2 = A[j];
            int tastiness2 = B[j];

            // Determine the more expensive and less expensive item costs
            int C_max = std::max(cost1, cost2);
            int C_min = std::min(cost1, cost2);

            // Calculate the discount for the more expensive item.
            // Discount is min(50% of C_max, 100 rupees).
            // Since A_i is guaranteed to be an even integer, C_max / 2 will be an integer.
            int discount = std::min(C_max / 2, 100);

            // Calculate the effective cost of the more expensive item after applying the discount
            int effective_C_max = C_max - discount;

            // Calculate the total cost for this pair of items
            int total_cost = C_min + effective_C_max;

            // Calculate the total tastiness for this pair of items
            int total_tastiness = tastiness1 + tastiness2;

            // Check if the total cost is within Chef's budget K
            if (total_cost <= K) {
                // If it is, update max_tastiness if this pair offers higher total tastiness
                max_tastiness = std::max(max_tastiness, total_tastiness);
            }
        }
    }

    // Print the maximum tastiness found for this test case.
    // If no pair was found within budget, max_tastiness remains 0, which is the required output.
    std::cout << max_tastiness << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output operations.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) prevents std::cout from being flushed before each std::cin operation.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T; // Read the number of test cases
    while (T--) {
        solve(); // Call the solve function for each test case
    }

    return 0; // Indicate successful program execution
}