#include <iostream> // Required for cin and cout

int main() {
    // Optimize C++ standard streams for competitive programming.
    // This unties cin/cout from the C standard I/O library and
    // prevents flushing cout before each cin, speeding up I/O.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T; // Declare an integer variable T for the number of test cases.
    std::cin >> T; // Read the number of test cases from standard input.

    // Loop T times, once for each test case.
    while (T--) {
        int X, Y; // Declare integer variables X (fuel) and Y (distance).
        std::cin >> X >> Y; // Read X and Y for the current test case.

        // Calculate the maximum distance Chef can travel with X litres of fuel.
        // Chef can travel 5 kilometres per litre.
        int max_distance_possible = X * 5;

        // Check if the maximum distance Chef can travel is sufficient to reach home.
        if (max_distance_possible >= Y) {
            // If Chef can travel Y kilometres or more, output YES.
            std::cout << "YES\n";
        } else {
            // Otherwise, Chef cannot reach home, output NO.
            std::cout << "NO\n";
        }
    }

    return 0; // Indicate successful program execution.
}