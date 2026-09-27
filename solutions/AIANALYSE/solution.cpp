#include <bits/stdc++.h> // Include all standard libraries

using namespace std; // Use the standard namespace

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin from cout and prevents synchronization with C's stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int C; // Declare an integer variable 'C' to store the number of characters in the code.
    
    // Read the single integer 'C' from standard input.
    cin >> C;

    // The AI feature is available only on codes that are at most 1000 characters long.
    // We check if the given number of characters 'C' satisfies this condition.
    if (C <= 1000) {
        // If C is less than or equal to 1000, the feature is available.
        // Output "Yes" followed by a newline character.
        cout << "Yes\n";
    } else {
        // If C is greater than 1000, the feature is not available.
        // Output "No" followed by a newline character.
        cout << "No\n";
    }

    return 0; // Indicate successful program execution.
}