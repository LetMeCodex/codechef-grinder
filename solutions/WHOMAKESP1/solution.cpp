#include <iostream> // Only iostream is needed for input/output

// Use the standard namespace to avoid std:: prefix
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin from cout and prevents synchronization with C's stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int A, B; // Declare two integer variables for Tyro's patience and Dom's attempts

    // Read A and B repeatedly until there is no more input (End Of File - EOF).
    // This handles multiple test cases where the number of test cases 'T' is not explicitly given.
    while (cin >> A >> B) {
        // Compare A and B to determine who makes the problem
        // If Tyro's patience level (A) is less than or equal to Dom's maximum attempts (B),
        // Tyro will be convinced and makes the problem.
        if (A <= B) {
            cout << "Tyro\n"; // Output "Tyro" followed by a newline
        } else {
            // Otherwise (if A > B), Dom gives up before Tyro is convinced,
            // so Dom makes the problem.
            cout << "Dom\n"; // Output "Dom" followed by a newline
        }
    }

    return 0; // Indicate successful execution
}