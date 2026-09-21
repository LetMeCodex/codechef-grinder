# Air Hockey (AIRHOCKEY)
- **Difficulty Rating**: 366
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem describes a simplified game of air hockey. Two players, Alice and Bob, are playing. The game ends when either Alice or Bob reaches a score of 7. We are given the current scores of Alice and Bob, say `a` and `b` respectively. We need to determine the minimum number of additional points that need to be scored in the game for it to end.

## Intuition & Mathematical Observation
The game ends as soon as *either* player reaches 7 points. This means we are interested in the scenario where the *first* player to reach 7 points does so.

Let Alice's current score be `a` and Bob's current score be `b`.

*   To win, Alice needs to score `7 - a` more points.
*   To win, Bob needs to score `7 - b` more points.

Since the game ends when the *first* player reaches 7 points, the total number of additional points required for the game to end is the minimum of the points each player needs to reach 7.

Therefore, the minimum number of additional points is `min(7 - a, 7 - b)`.

For example:
*   If Alice has 3 points and Bob has 5 points (`a=3`, `b=5`):
    *   Alice needs `7 - 3 = 4` more points.
    *   Bob needs `7 - 5 = 2` more points.
    *   The minimum is `min(4, 2) = 2`. The game will end when Bob scores 2 more points, reaching 7.
*   If Alice has 6 points and Bob has 2 points (`a=6`, `b=2`):
    *   Alice needs `7 - 6 = 1` more point.
    *   Bob needs `7 - 2 = 5` more points.
    *   The minimum is `min(1, 5) = 1`. The game will end when Alice scores 1 more point, reaching 7.

The problem statement guarantees that `a` and `b` are less than 7, so `7 - a` and `7 - b` will always be positive.

## Complexity Analysis
- **Time Complexity**: $O(1)$
    The solution involves a fixed number of arithmetic operations and a call to `std::min` for each test case. The number of test cases is read from input, but the computation per test case is constant.

- **Space Complexity**: $O(1)$
    The solution uses a few integer variables to store the input scores and intermediate calculations. The memory usage is constant and does not depend on the input size.

## Solution Code
```cpp
#include <iostream>
#include <algorithm> // Required for std::min

int main() {
    // Optimize C++ standard streams for competitive programming
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; // Number of test cases
    std::cin >> t;
    while (t--) {
        int a, b; // Alice's score and Bob's score
        std::cin >> a >> b;

        // The game ends when either Alice or Bob reaches 7 points.
        // We need to find the minimum number of additional points required
        // for the game to conclude.

        // Points Alice needs to reach 7
        int points_for_alice_to_win = 7 - a;

        // Points Bob needs to reach 7
        int points_for_bob_to_win = 7 - b;

        // The game ends when the first player reaches 7.
        // Therefore, the minimum number of additional points is the minimum
        // of the points each player needs.
        std::cout << std::min(points_for_alice_to_win, points_for_bob_to_win) << "\n";
    }
    return 0;
}
```