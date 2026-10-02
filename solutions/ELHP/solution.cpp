#include <bits/stdc++.h> // Include all standard libraries

// Use the standard namespace
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin/cout from the C standard streams and prevents flushing
    // of cout before cin operations, which can speed up I/O significantly.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Declare two integer variables to store the votes received by Chef (X)
    // and his rival Chefu (Y).
    // The constraints (1 <= X, Y <= 100) ensure that 'int' is sufficient
    // to store these values and any intermediate calculations (like 2*Y, which
    // would be at most 200).
    int X, Y;

    // Read the two space-separated integers from the standard input.
    cin >> X >> Y;

    // Chef dominates the election if he received "at least double" the number
    // of votes Chefu received. This condition can be expressed as X >= 2 * Y.
    if (X >= 2 * Y) {
        // If the condition is true, Chef dominated the election.
        // Print "Yes" followed by a newline character.
        cout << "Yes\n";
    } else {
        // If the condition is false, Chef did not dominate the election.
        // Print "No" followed by a newline character.
        cout << "No\n";
    }

    // Return 0 to indicate successful execution of the program.
    return 0;
}