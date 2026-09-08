#include <bits/stdc++.h> // Includes all standard libraries

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin/cout from the C standard I/O library and
    // disables synchronization with C's stdio.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    // Declare two integer variables to store the input values.
    // X: total count of 'All Problems' in the Beginner section.
    // Y: count of 'Attempted' problems among them.
    int X, Y;

    // Read the two space-separated integers from standard input.
    std::cin >> X >> Y;

    // Calculate the number of 'Un-attempted' problems.
    // This is simply the total problems minus the attempted problems.
    int unattempted_problems = X - Y;

    // Print the result to standard output, followed by a newline character.
    std::cout << unattempted_problems << "\n";

    // Indicate successful execution of the program.
    return 0;
}