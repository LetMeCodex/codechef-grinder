#include <bits/stdc++.h> // Includes common libraries like iostream and algorithm

// Using namespace std; is a common practice in competitive programming
// and is explicitly requested by the problem statement.
using namespace std; 

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a standard competitive programming optimization and is explicitly requested.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases

    // Loop through each test case
    while (T--) {
        int X, Y;
        cin >> X >> Y; // Read X (number of students) and Y (chairs Chef already has)

        // Determine the minimum number of new chairs Chef must buy.
        // If the number of students (X) is greater than the number of chairs Chef has (Y),
        // Chef needs to buy X - Y chairs.
        // If X is less than or equal to Y, Chef already has enough chairs (or more),
        // so no new chairs need to be bought (0 chairs).
        // This logic can be concisely expressed using std::max(0, X - Y).
        int chairs_to_buy = max(0, X - Y);

        // Output the result for the current test case, followed by a newline.
        cout << chairs_to_buy << "\n";
    }

    return 0; // Indicate successful execution
}