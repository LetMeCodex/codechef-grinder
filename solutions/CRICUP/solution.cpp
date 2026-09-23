#include <iostream> // Required for cin, cout
#include <cmath>    // Required for abs()
#include <algorithm> // Not strictly needed if using cmath's abs, but good for general utility

int main() {
    // Optimize C++ standard streams for competitive programming.
    // This unties cin from cout and prevents synchronization with C's stdio.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T; // Number of testcases
    std::cin >> T; // Read the number of testcases

    while (T--) { // Loop T times for each testcase
        int X, Y, D; // Skill levels of teams X, Y, and maximum allowed difference D
        std::cin >> X >> Y >> D; // Read X, Y, and D for the current testcase

        // Calculate the absolute difference between the skill levels of the two teams.
        // std::abs() is used to ensure the difference is non-negative.
        int skill_difference = std::abs(X - Y);

        // Check if the calculated skill difference is less than or equal to D.
        if (skill_difference <= D) {
            std::cout << "YES\n"; // If it is, Chef finds the game interesting
        } else {
            std::cout << "NO\n"; // Otherwise, Chef does not find the game interesting
        }
    }

    return 0; // Indicate successful execution
}