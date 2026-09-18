#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef has X levels to complete.
 * Each level takes Y minutes.
 * A break of Z minutes is taken after every 3 levels, 
 * but not after the final level if the game is completed.
 * 
 * Total time = (Total time spent playing) + (Total time spent on breaks)
 * Total time spent playing = X * Y
 * Number of breaks = (X - 1) / 3 (using integer division)
 * Total time spent on breaks = ((X - 1) / 3) * Z
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long x, y, z;
        cin >> x >> y >> z;

        // Calculate total playing time
        long long total_playing_time = x * y;

        // Calculate number of breaks
        // A break occurs after every 3 levels, but not after the last level.
        // If X = 3, breaks = 0. If X = 4, breaks = 1.
        // The formula (x - 1) / 3 correctly handles this.
        long long num_breaks = (x - 1) / 3;
        long long total_break_time = num_breaks * z;

        long long total_time = total_playing_time + total_break_time;

        cout << total_time << "\n";
    }

    return 0;
}