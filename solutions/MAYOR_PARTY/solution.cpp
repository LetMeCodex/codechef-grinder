#include <iostream> // Required for input/output operations (std::cin, std::cout)
#include <algorithm> // Required for std::max

int main() {
    // Optimize C++ standard streams for competitive programming.
    // This unties cin from cout and disables synchronization with C's stdio.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T; // Variable to store the number of test cases
    std::cin >> T; // Read the number of test cases

    // Loop through each test case
    while (T--) {
        int PA, PB, PC; // Declare variables for people in regions A, B, C
        std::cin >> PA >> PB >> PC; // Read the number of people for the current test case

        // The core logic:
        // There are two valid scenarios to avoid conflict:
        // 1. Invite only people from region B. Total people: PB
        // 2. Invite only people from regions A and C. Total people: PA + PC
        // We want to maximize the invited people, so we choose the maximum of these two options.
        int max_invited = std::max(PB, PA + PC);

        std::cout << max_invited << std::endl; // Output the maximum number of invited people
    }

    return 0; // Indicate successful execution
}