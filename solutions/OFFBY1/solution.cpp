#include <bits/stdc++.h> // Includes all standard libraries

// Use the standard namespace
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin from cout and prevents synchronization with C's stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Declare two integer variables to store the input numbers A and B.
    int A, B;

    // Read the two space-separated integers A and B from standard input.
    cin >> A >> B;

    // Calculate the sum of A and B.
    // According to the problem, the calculator first computes A + B.
    int sum = A + B;

    // The calculator then appends an extra '1' to the end of the result.
    // Mathematically, appending '1' to an integer X is equivalent to X * 10 + 1.
    // For example, if sum is 8, 8 * 10 + 1 = 81.
    // If sum is 16, 16 * 10 + 1 = 161.
    int calculator_output = sum * 10 + 1;

    // Print the final calculated output to standard output, followed by a newline character.
    cout << calculator_output << "\n";

    // Return 0 to indicate successful program execution.
    return 0;
}