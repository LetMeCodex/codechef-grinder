#include <iostream> // Only iostream is needed for input/output

// Using namespace std; is common in competitive programming
using namespace std; 

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Number of test cases
    cin >> T;
    while (T--) {
        int Y; // Maximum number of moves
        cin >> Y;

        long long result; // Use long long for result to be absolutely safe, though int is sufficient for 3*10^6
        if (Y == 0) {
            // If no moves can be performed, X remains 0.
            // Only 1 distinct value: {0}.
            result = 1;
        } else { // For Y >= 1
            // For Y >= 1, the number of distinct values is 3 * Y.
            // This covers Y=1 (3 values: -1, 0, 2) and Y>=2 (e.g., Y=2 gives 6 values).
            // The range of values is [-Y, 2Y]. This range contains 3Y+1 integers.
            // The value 2Y-1 is always unreachable for Y >= 1.
            // Therefore, the number of distinct values is (3Y+1) - 1 = 3Y.
            result = 3LL * Y; // Use 3LL to ensure the multiplication is performed using long long, preventing potential overflow if Y was larger.
        }
        cout << result << "\n"; // Output the result for the current test case
    }
    return 0; // Indicate successful execution
}