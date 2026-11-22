#include <bits/stdc++.h> // Includes iostream and other standard libraries

int main() {
    // Optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) prevents cin from flushing cout before each input operation.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; // Declare an integer variable 't' to store the number of test cases.
    std::cin >> t; // Read the number of test cases from standard input.

    // Loop through each test case.
    while (t--) {
        int x1, x2; // Declare integer variables for Chef's and friend's initial positions.
        std::cin >> x1 >> x2; // Read X1 and X2 for the current test case.

        // Chef's position after 't_seconds': X1 + t_seconds
        // Friend's position after 't_seconds': X2 + 2 * t_seconds
        // They meet if X1 + t_seconds = X2 + 2 * t_seconds
        // Solving for t_seconds: t_seconds = X1 - X2
        // For a meeting to occur, t_seconds must be non-negative (t_seconds >= 0).
        // Thus, X1 - X2 >= 0, which simplifies to X1 >= X2.

        if (x1 >= x2) {
            // If Chef's initial position is greater than or equal to his friend's, they will meet.
            std::cout << "YES\n";
        } else {
            // Otherwise, Chef starts behind and moves slower, so they will never meet.
            std::cout << "NO\n";
        }
    }

    return 0; // Indicate successful program execution.
}