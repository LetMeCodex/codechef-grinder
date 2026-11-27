#include <iostream> // Required for input/output operations (cin, cout)

void solve() {
    int N;
    std::cin >> N; // Read the size of the grid N

    // Iterate through each row
    for (int i = 0; i < N; ++i) {
        // Iterate through each column in the current row
        for (int j = 0; j < N; ++j) {
            std::cout << 1; // Print '1' for the current cell
            if (j < N - 1) {
                std::cout << " "; // Print a space after the number if it's not the last in the row
            }
        }
        std::cout << '\n'; // Move to the next line after printing all numbers in a row, using '\n' for faster I/O
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is common practice in competitive programming.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T; // Read the number of test cases

    // Loop through each test case
    while (T--) {
        solve(); // Call the solve function for each test case
    }

    return 0; // Indicate successful execution
}