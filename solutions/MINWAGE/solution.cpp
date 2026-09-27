#include <bits/stdc++.h> // Include all standard libraries

using namespace std; // Use standard namespace

int main() {
    // Optimize C++ standard streams for competitive programming.
    // This unties cin/cout from the C standard streams and prevents flushing
    // of cout before cin, leading to faster input/output operations.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Declare an integer variable X to store Chef's income per hour.
    int X;

    // Read the input value for X from standard input.
    // According to the problem statement, X is on the first and only line.
    cin >> X;

    // The minimum wage in Chefland is 11 dollars per hour.
    // We need to check if Chef's income X is strictly above the minimum wage.
    // This translates to the condition X > 11.
    if (X > 11) {
        // If X is strictly greater than 11, output "YES".
        // Use "\n" for a newline character as required.
        cout << "YES\n";
    } else {
        // Otherwise (if X is 11 or less), output "NO".
        cout << "NO\n";
    }

    // Return 0 to indicate successful program execution.
    return 0;
}