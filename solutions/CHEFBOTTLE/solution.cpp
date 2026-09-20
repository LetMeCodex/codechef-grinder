#include <iostream> // Required for cin, cout
#include <algorithm> // Required for std::min

// As per problem instructions, using namespace std; is allowed/encouraged.
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin from cout and prevents synchronization with C's stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Variable to store the number of test cases
    cin >> T; // Read the number of test cases

    // Loop through each test case
    while (T--) {
        int N, X, K; // N: number of bottles, X: capacity per bottle, K: total water in tank
        cin >> N >> X >> K; // Read N, X, and K for the current test case

        // Calculate the maximum number of bottles that can be filled completely
        // based on the available water (K) and bottle capacity (X).
        // Integer division (K / X) correctly gives the count of completely filled bottles.
        int bottles_fillable_by_water = K / X;

        // The final answer is limited by two factors:
        // 1. The actual number of empty bottles Chef has (N).
        // 2. The number of bottles that can be filled with the available water (bottles_fillable_by_water).
        // We take the minimum of these two values to find the maximum number of bottles Chef can fill.
        int max_bottles_filled = min(N, bottles_fillable_by_water);

        // Output the result for the current test case, followed by a newline.
        cout << max_bottles_filled << "\n";
    }

    return 0; // Indicate successful program execution
}