#include <iostream> // Required for standard input/output operations (cin, cout)
#include <cmath>    // Required for std::abs (absolute value function)

void solve() {
    long long A, B, X; // Use long long to handle values up to 10^9 safely
    std::cin >> A >> B >> X;

    // Condition 1: The sum A+B must be even.
    // The sum A+B is an invariant under the given operations.
    // If A and B become equal to some value K, their sum will be K+K = 2K, which is always even.
    // Therefore, if the initial sum (A+B) is odd, it's impossible to make A and B equal.
    if ((A + B) % 2 != 0) {
        std::cout << "NO\n";
        return; // No need to check further conditions
    }

    // Condition 2: The absolute difference |A-B| must be a multiple of 2X.
    // Let D = A-B.
    // Operation 1 changes D to D + 2X.
    // Operation 2 changes D to D - 2X.
    // In each step, the difference A-B changes by +/- 2X.
    // To make A and B equal, the final difference must be 0.
    // This means the initial difference (A-B) must be reachable from 0 by adding/subtracting multiples of 2X.
    // Equivalently, (A-B) must be a multiple of 2X.
    long long diff = std::abs(A - B);
    
    // If diff is 0, A and B are already equal, which satisfies the condition.
    // (0 is a multiple of any non-zero number, so 0 % (2*X) == 0 holds true).
    if (diff % (2 * X) == 0) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) prevents cin from flushing cout before each input operation.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T; // Variable to store the number of test cases
    std::cin >> T; // Read the number of test cases
    while (T--) { // Loop through each test case
        solve(); // Call the solve function for each test case
    }

    return 0; // Indicate successful execution
}