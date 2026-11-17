#include <iostream> // Required for input/output operations (cin, cout)
#include <algorithm> // Required for std::max

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming to prevent TLE on large inputs.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T; // Declare an integer variable T to store the number of test cases
    std::cin >> T; // Read the value of T from the input

    // Loop T times, once for each test case
    while (T--) {
        long long A1, A2; // Declare long long variables for combo A's times
        std::cin >> A1 >> A2; // Read A1 and A2
        long long satisfactionA = A1 + A2; // Calculate satisfaction for combo A

        long long B1, B2; // Declare long long variables for combo B's times
        std::cin >> B1 >> B2; // Read B1 and B2
        long long satisfactionB = B1 + B2; // Calculate satisfaction for combo B

        long long C1, C2; // Declare long long variables for combo C's times
        std::cin >> C1 >> C2; // Read C1 and C2
        long long satisfactionC = C1 + C2; // Calculate satisfaction for combo C

        // Find the maximum satisfaction among the three combos.
        // std::max can take an initializer list {val1, val2, val3} in C++11 and later.
        long long maxSatisfaction = std::max({satisfactionA, satisfactionB, satisfactionC});

        std::cout << maxSatisfaction << std::endl; // Print the maximum satisfaction followed by a newline
    }

    return 0; // Indicate successful program execution
}