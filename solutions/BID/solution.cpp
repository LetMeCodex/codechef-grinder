#include <iostream> // Only include necessary header for input/output

// Function to solve a single test case
void solve() {
    int N;
    std::cin >> N; // Read the number of players

    // Initialize total attack and defense powers for both teams.
    // Using int, as max sum (2000 * 1000 = 2,000,000) fits comfortably in a 32-bit signed int.
    int total_attA = 0;
    int total_defA = 0;
    int total_attP = 0;
    int total_defP = 0;

    // Read attack powers for Team A and sum them up
    for (int i = 0; i < N; ++i) {
        int val;
        std::cin >> val;
        total_attA += val;
    }

    // Read defense powers for Team A and sum them up
    for (int i = 0; i < N; ++i) {
        int val;
        std::cin >> val;
        total_defA += val;
    }

    // Read attack powers for Team P and sum them up
    for (int i = 0; i < N; ++i) {
        int val;
        std::cin >> val;
        total_attP += val;
    }

    // Read defense powers for Team P and sum them up
    for (int i = 0; i < N; ++i) {
        int val;
        std::cin >> val;
        total_defP += val;
    }

    // Apply Pep's bidding strategy
    // Pep bids for Team A if its total attack AND total defense are strictly greater than Team P's
    if (total_attA > total_attP && total_defA > total_defP) {
        std::cout << "A\n";
    } 
    // Pep bids for Team P if its total attack AND total defense are strictly greater than Team A's
    else if (total_attP > total_attA && total_defP > total_defA) {
        std::cout << "P\n";
    } 
    // Otherwise, if neither team strictly dominates in both categories, Pep bids for a draw
    else {
        std::cout << "DRAW\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output operations.
    std::ios_base::sync_with_stdio(false); // Unties C++ streams from C standard streams
    std::cin.tie(NULL);                     // Prevents cin from flushing cout

    int T;
    std::cin >> T; // Read the number of test cases
    while (T--) { // Loop through each test case
        solve(); // Call the solve function for the current test case
    }

    return 0; // Indicate successful execution
}