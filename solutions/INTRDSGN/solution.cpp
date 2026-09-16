#include <iostream> // Required for cin, cout
#include <algorithm> // Required for std::min

int main() {
    // Optimize C++ standard streams for competitive programming.
    // This unties cin from cout and disables synchronization with C's stdio.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T; // Declare variable for the number of test cases
    std::cin >> T; // Read the number of test cases

    // Loop through each test case
    while (T--) {
        int X1, Y1, X2, Y2; // Declare variables for costs
        // Read the four space-separated integers for the current test case
        std::cin >> X1 >> Y1 >> X2 >> Y2;

        // Calculate the total cost for the first style
        int cost1 = X1 + Y1;
        // Calculate the total cost for the second style
        int cost2 = X2 + Y2;

        // Chef chooses the style with the lower total cost.
        // Use std::min to find the minimum of the two costs.
        int min_cost = std::min(cost1, cost2);

        // Output the minimum cost followed by a newline character
        std::cout << min_cost << "\n";
    }

    return 0; // Indicate successful execution
}