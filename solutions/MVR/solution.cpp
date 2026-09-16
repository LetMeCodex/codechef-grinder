#include <bits/stdc++.h> // Includes most standard libraries

// It's common practice in competitive programming to use the entire std namespace
// to avoid repeatedly typing std::
using namespace std; 

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Declare four integer variables to store the input values:
    // A: Messi's goals
    // B: Messi's assists
    // X: Ronaldo's goals
    // Y: Ronaldo's assists
    int A, B, X, Y;

    // Read the four space-separated integers from the standard input.
    cin >> A >> B >> X >> Y;

    // Calculate Messi's total points.
    // Each goal is 2 points, each assist is 1 point.
    int messi_points = (A * 2) + B;

    // Calculate Ronaldo's total points using the same logic.
    int ronaldo_points = (X * 2) + Y;

    // Compare the total points of Messi and Ronaldo.
    if (messi_points > ronaldo_points) {
        // If Messi has more points, print "Messi".
        cout << "Messi\n";
    } else if (ronaldo_points > messi_points) {
        // If Ronaldo has more points, print "Ronaldo".
        cout << "Ronaldo\n";
    } else {
        // If neither has more points, they must have an equal number of points.
        cout << "Equal\n";
    }

    // Return 0 to indicate successful execution of the program.
    return 0;
}