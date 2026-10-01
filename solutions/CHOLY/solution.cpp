#include <bits/stdc++.h> // Includes most standard libraries

// Using namespace std; is common in competitive programming to avoid typing std::
using namespace std;

int main() {
    // Optimize C++ standard streams for competitive programming.
    // Unties cin from cout and disables synchronization with C's stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int X, Y, Z;
    // Read the number of wins, draws, and losses so far.
    cin >> X >> Y >> Z;

    // The problem asks if our team can still win the round.
    // A team wins if they receive *strictly* more points than the opposing team.
    // There are 4 games in total.
    // Points: Win = 1, Draw = 0.5, Loss = 0.

    // Let's calculate current points:
    // Our team's current points: X * 1 + Y * 0.5 + Z * 0 = X + 0.5Y
    // Opponent's current points: X * 0 + Y * 0.5 + Z * 1 = 0.5Y + Z

    // Number of games remaining: R = 4 - (X + Y + Z)

    // To determine if our team *can still win*, we assume the best possible outcome
    // for our team in the remaining games: our team wins all R remaining games.
    // If our team wins R games:
    //   Our team gains R * 1 = R points.
    //   Opponent gains R * 0 = 0 points.

    // Our team's maximum possible final points: P_my_final = (X + 0.5Y) + R
    // Opponent's minimum possible final points: P_opp_final = (0.5Y + Z)

    // Our team wins if P_my_final > P_opp_final:
    // (X + 0.5Y + R) > (0.5Y + Z)

    // Substitute R = 4 - (X + Y + Z):
    // X + 0.5Y + (4 - X - Y - Z) > 0.5Y + Z
    // X + 0.5Y + 4 - X - Y - Z > 0.5Y + Z
    // Simplify the inequality:
    // (X - X) + (0.5Y - Y) + 4 - Z > 0.5Y + Z
    // 0 - 0.5Y + 4 - Z > 0.5Y + Z
    // 4 - Z > 0.5Y + 0.5Y + Z
    // 4 - Z > Y + Z
    // 4 > Y + 2Z

    // So, we just need to check if 4 is strictly greater than Y + 2Z.
    if (4 > (Y + 2 * Z)) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }

    return 0;
}