#include <bits/stdc++.h> // Includes all standard libraries

using namespace std; // Uses the standard namespace

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Declare four integer variables to store the input values:
    // A: coins rewarded to the winner
    // B: coins rewarded to the loser
    // X: goals scored by Chef
    // Y: goals scored by Chefina
    int A, B, X, Y;

    // Read the four space-separated integers from the standard input.
    cin >> A >> B >> X >> Y;

    // Determine the winner of the game.
    // The player scoring the maximum goals wins.
    // We need to find out if Chef won or lost to determine the coins Chef receives.
    if (X > Y) {
        // If Chef's goals (X) are greater than Chefina's goals (Y),
        // Chef wins the game.
        // The winner receives A gold coins.
        cout << A << "\n";
    } else {
        // If Chef's goals (X) are not greater than Chefina's goals (Y),
        // and it's given that X != Y, this implies X < Y.
        // Therefore, Chef loses the game.
        // The loser receives B gold coins.
        cout << B << "\n";
    }

    // Return 0 to indicate successful execution of the program.
    return 0;
}