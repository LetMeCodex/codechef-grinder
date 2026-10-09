#include <bits/stdc++.h> // Includes most standard libraries

using namespace std; // Uses the standard namespace

int main() {
    // Optimize C++ standard streams for competitive programming.
    // This unties cin/cout from the C standard streams and disables synchronization
    // with C's stdio, making I/O operations faster.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Declare two integer variables X and Y to store the number of 3-pointers and 2-pointers.
    int X, Y;

    // Read the two integers X and Y from standard input.
    cin >> X >> Y;

    // Calculate the total score.
    // Each 3-pointer is worth 3 points, so X 3-pointers contribute X * 3 points.
    // Each 2-pointer is worth 2 points, so Y 2-pointers contribute Y * 2 points.
    // The total score is the sum of these two contributions.
    int total_score = (X * 3) + (Y * 2);

    // Print the calculated total score to standard output, followed by a newline character.
    cout << total_score << "\n";

    // Return 0 to indicate successful execution of the program.
    return 0;
}