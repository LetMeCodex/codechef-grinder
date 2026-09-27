#include <bits/stdc++.h>

using namespace std;

int main() {
    // Optimize C++ standard streams for competitive programming.
    // This unties cin from cout and prevents synchronization with C's stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int X; // Declare an integer variable to store the day Shreyan can go.
    cin >> X; // Read the input value for X.

    // The Algomaniac finals are held on March 17.
    // We need to check if Shreyan's available day (X) is the same as the finals day.
    if (X == 17) {
        // If X is 17, Shreyan can attend the finals.
        cout << "YAY\n";
    } else {
        // Otherwise, Shreyan cannot attend the finals.
        cout << "NO\n";
    }

    return 0; // Indicate successful program execution.
}