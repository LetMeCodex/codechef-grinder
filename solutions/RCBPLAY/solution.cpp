#include <iostream>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        int x, y, z;
        std::cin >> x >> y >> z;
        // To qualify, RCB needs at least Y points.
        // They currently have X points.
        // They need at least Y - X more points.
        // Let the number of wins be w, draws be d, and losses be l.
        // w + d + l = z (total remaining games)
        // Points from remaining games = 2*w + 1*d + 0*l = 2*w + d
        // Total points = X + 2*w + d
        // We need X + 2*w + d >= Y
        // This is equivalent to 2*w + d >= Y - X

        // To maximize the points from remaining games, RCB should win as many games as possible.
        // The maximum possible points from Z games is when they win all Z games.
        // In this case, w = Z, d = 0, l = 0.
        // Maximum points from remaining games = 2 * Z.
        // So, the maximum total points RCB can achieve is X + 2 * Z.

        // If the maximum possible total points (X + 2*Z) is less than the required points (Y),
        // then it's impossible to qualify.
        // Otherwise, it is possible.

        if (x + 2 * z >= y) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
    return 0;
}