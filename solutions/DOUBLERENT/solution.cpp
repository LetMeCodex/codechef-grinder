#include <bits/stdc++.h> // Include all standard libraries

using namespace std; // Use standard namespace

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Declare an integer variable X to store the initial rent.
    // Constraints: 1 <= X <= 10, so 'int' is sufficient.
    int X;

    // Read the initial rent X from standard input.
    cin >> X;

    // Calculate the final rent.
    // The problem states the owner decided to "double" the rent.
    // So, the final rent is 2 times the initial rent X.
    int final_rent = 2 * X;

    // Output the final rent to standard output, followed by a newline character.
    cout << final_rent << "\n";

    // Return 0 to indicate successful execution of the program.
    return 0;
}