#include <bits/stdc++.h> // Includes most standard libraries

using namespace std; // Use the standard namespace

int main() {
    // Optimize C++ standard streams for competitive programming.
    // This unties cin/cout from C's stdio and prevents flushing cout before cin.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Declare two integer variables X and Y.
    // X: number of Leo's fans, who want a free kick session.
    // Y: number of Ronald's fans, who want a penalty session.
    int X, Y;

    // Read the two space-separated integers from the first and only line of input.
    // The problem statement implies a single test case by describing the input
    // as "The first and only line of input contains two space-separated integers X and Y".
    cin >> X >> Y;

    // The problem states that the training session with more interested players will be held.
    // It is guaranteed that X != Y, so there will be no tie in the number of fans.

    // If X (number of Leo's fans) is greater than Y (number of Ronald's fans),
    // then more players want a free kick session.
    if (X > Y) {
        cout << "FREEKICK\n";
    }
    // Otherwise (since X != Y, this implies Y > X),
    // more players want a penalty session.
    else { // Y > X
        cout << "PENALTY\n";
    }

    // The program successfully executed.
    return 0;
}