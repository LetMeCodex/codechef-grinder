#include <bits/stdc++.h>

using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Declare an integer variable X to store the total points scored by the team.
    int X;

    // Read the total points X from standard input.
    cin >> X;

    // Check if the team has scored 12 or more points.
    // According to the problem statement, a team qualifies if they score 12 or more points.
    if (X >= 12) {
        // If the team has scored 12 or more points, print "Yes".
        // The output format requires "Yes" or "No", case-insensitive, so "Yes" is fine.
        cout << "Yes\n";
    } else {
        // Otherwise (if X is less than 12), the team does not qualify. Print "No".
        cout << "No\n";
    }

    // Return 0 to indicate successful execution of the program.
    return 0;
}