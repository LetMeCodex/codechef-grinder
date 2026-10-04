#include <iostream> // Required for std::cin, std::cout

// Declare counts array globally to be zero-initialized by default.
// Max A_i is 100, so an array of size 101 (indices 0-100) is sufficient.
// We will use indices 1 to 100 for animal types.
int counts[101]; 

void solve() {
    int N;
    std::cin >> N;

    // For each test case, reset the counts array.
    // We only care about animal types from 1 to 100.
    for (int i = 1; i <= 100; ++i) {
        counts[i] = 0;
    }

    // Read all animal types and update their counts.
    for (int i = 0; i < N; ++i) {
        int animal_type;
        std::cin >> animal_type;
        counts[animal_type]++;
    }

    // Condition 1: Total number of animals N must be even.
    // If N is odd, it's impossible to split them into two groups of equal size.
    if (N % 2 != 0) {
        std::cout << "NO\n";
        return;
    }

    // Condition 2: The count of each animal type must be even.
    // If any animal type has an odd count, it's impossible to split that type
    // equally between Alice and Bob.
    bool possible = true;
    for (int i = 1; i <= 100; ++i) {
        if (counts[i] % 2 != 0) {
            possible = false;
            break; // Found an odd count, no need to check further
        }
    }

    if (possible) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T; // Number of test cases
    std::cin >> T;
    while (T--) {
        solve(); // Call the function to solve each test case
    }

    return 0; // Indicate successful execution
}