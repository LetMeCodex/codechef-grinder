#include <iostream>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        int a, b;
        std::cin >> a >> b;
        // The game ends when either Alice or Bob reaches 7 points.
        // The minimum number of additional points needed is the difference
        // between 7 and the current higher score.
        // If Alice's score is A and Bob's score is B,
        // Alice needs 7 - A more points to win.
        // Bob needs 7 - B more points to win.
        // The game ends when the first person reaches 7 points.
        // So, the minimum number of additional points is the minimum of
        // (7 - A) and (7 - B).
        int points_for_alice_to_win = 7 - a;
        int points_for_bob_to_win = 7 - b;
        std::cout << std::min(points_for_alice_to_win, points_for_bob_to_win) << "\n";
    }
    return 0;
}