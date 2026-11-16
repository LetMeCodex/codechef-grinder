#include <iostream> // Only include iostream for input/output, which is sufficient for this problem

// Use the standard namespace to avoid writing std:: repeatedly
using namespace std;

// Function to solve a single test case
void solve() {
    int X1, Y1, X2, Y2;
    // Read the coordinates of the two rooks
    cin >> X1 >> Y1 >> X2 >> Y2;

    // Two rooks attack each other if they are in the same row OR the same column.
    // They are in the same column if their X-coordinates are equal (X1 == X2).
    // They are in the same row if their Y-coordinates are equal (Y1 == Y2).
    if (X1 == X2 || Y1 == Y2) {
        // If either condition is true, they attack
        cout << "YES\n"; // Using '\n' is generally faster than std::endl as it doesn't force a flush
    } else {
        // Otherwise, they do not attack
        cout << "NO\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output
    // This unties cin from cout and disables synchronization with C's stdio
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    // Read the number of test cases
    cin >> T;
    // Loop through each test case
    while (T--) {
        solve(); // Call the solve function for the current test case
    }

    return 0; // Indicate successful execution
}