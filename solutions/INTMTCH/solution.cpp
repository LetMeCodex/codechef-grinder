#include <bits/stdc++.h>

using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cout from flushing before cin reads input.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Declare two integer variables to store the number of goals scored by Chefland (X)
    // and Byteland (Y), respectively.
    int X, Y;

    // Read the two space-separated integers X and Y from standard input.
    cin >> X >> Y;

    // Calculate the absolute difference between the goals scored by both teams.
    // The std::abs() function (from <cmath>, included by <bits/stdc++.h>)
    // returns the absolute value of its argument.
    int difference = abs(X - Y);

    // Check if the absolute difference in goals is at most 2.
    // If it is, Chef finds the match interesting.
    if (difference <= 2) {
        // Output "Interesting" followed by a newline character.
        cout << "Interesting\n";
    } else {
        // Otherwise, Chef finds the match boring.
        // Output "Boring" followed by a newline character.
        cout << "Boring\n";
    }

    // Return 0 to indicate successful execution of the program.
    return 0;
}