#include <iostream> // Required for std::cin, std::cout
#include <algorithm> // Required for std::min

// Function to solve a single test case
void solve() {
    // Declare variables using long long to handle potential large values for R
    // and intermediate products like N*X, preventing overflow.
    long long X, Y, N, R;
    std::cin >> X >> Y >> N >> R;

    // Step 1: Check if it's even possible to buy N burgers.
    // The cheapest way to buy N burgers is to buy all N as normal burgers.
    // If the cost of N normal burgers (N * X) exceeds the available money R,
    // then it's impossible to buy N burgers at all.
    if (N * X > R) {
        std::cout << -1 << "\n";
        return; // Exit this test case
    }

    // Step 2: Calculate the maximum number of premium burgers Chef can afford based on budget.
    // The additional cost for one premium burger compared to one normal burger is (Y - X).
    // The total money available for these "upgrades" is R - N*X (after hypothetically paying for N normal burgers).
    // So, (R - N*X) / (Y - X) gives the maximum number of "upgrades" Chef can afford.
    long long max_premium_by_budget = (R - N * X) / (Y - X);

    // Step 3: Determine the final number of premium burgers.
    // The number of premium burgers cannot exceed the total number of burgers N.
    // It also cannot exceed the amount calculated from the budget (max_premium_by_budget).
    // So, we take the minimum of these two constraints.
    long long num_premium = std::min(N, max_premium_by_budget);

    // Step 4: Calculate the number of normal burgers.
    // Since Chef must buy exactly N burgers, the rest must be normal burgers.
    long long num_normal = N - num_premium;

    // Step 5: Output the results.
    std::cout << num_normal << " " << num_premium << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) prevents std::cout from flushing before std::cin reads input.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T; // Number of test cases
    std::cin >> T; // Read the number of test cases
    while (T--) { // Loop through each test case
        solve(); // Call the solve function for the current test case
    }

    return 0; // Indicate successful execution
}