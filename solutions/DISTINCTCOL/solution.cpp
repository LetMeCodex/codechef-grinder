#include <iostream> // Required for standard input/output operations (cin, cout)
#include <algorithm> // Required for std::max function

void solve() {
    int N;
    std::cin >> N; // Read the number of different types of colors

    int max_balls = 0; // Initialize a variable to store the maximum number of balls of any single color.
                       // Since A_i >= 1, initializing with 0 is safe.

    // Loop N times to read the count of balls for each color
    for (int i = 0; i < N; ++i) {
        int A_i;
        std::cin >> A_i; // Read the number of balls for the current color

        // Update max_balls if the current A_i is greater than the previously found maximum
        max_balls = std::max(max_balls, A_i);
    }

    // The minimum number of boxes required is the maximum number of balls of any single color.
    // This is because each ball of the most numerous color must go into a distinct box.
    std::cout << max_balls << "\n"; // Output the result followed by a newline
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming to prevent TLE (Time Limit Exceeded)
    // on problems with large inputs.
    std::ios_base::sync_with_stdio(false); // Untie C++ streams from C standard streams
    std::cin.tie(NULL);                   // Untie cin from cout

    int T;
    std::cin >> T; // Read the number of test cases

    // Loop through each test case
    while (T--) {
        solve(); // Call the solve function to handle the current test case
    }

    return 0; // Indicate successful program execution
}