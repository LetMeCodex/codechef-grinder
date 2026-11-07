#include <iostream>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        int x, y;
        std::cin >> x >> y;

        // Team A has 2 more kicks (5 total - 3 taken)
        // Team B has 1 more kick (5 total - 4 taken)

        // To end in a draw, the final scores must be equal.
        // Let A_final be the final score of team A, and B_final be the final score of team B.
        // We need A_final = B_final.

        // Minimum possible final score for A: x (if they miss both remaining kicks)
        // Maximum possible final score for A: x + 2 (if they score in both remaining kicks)
        // So, x <= A_final <= x + 2

        // Minimum possible final score for B: y (if they miss the remaining kick)
        // Maximum possible final score for B: y + 1 (if they score in the remaining kick)
        // So, y <= B_final <= y + 1

        // For a draw to be possible, there must be an overlap between the possible final scores of A and B.
        // Specifically, there must exist a score 'S' such that:
        // x <= S <= x + 2  AND  y <= S <= y + 1

        // This means the maximum possible score for B must be at least the minimum possible score for A,
        // AND the maximum possible score for A must be at least the minimum possible score for B.

        // Condition 1: Max B score >= Min A score
        // y + 1 >= x

        // Condition 2: Max A score >= Min B score
        // x + 2 >= y

        // Combining these, we need to check if there's a common score 'S' that both can achieve.
        // The range of possible final scores for A is [x, x+2].
        // The range of possible final scores for B is [y, y+1].

        // A draw is possible if the intersection of these two ranges is non-empty.
        // The intersection is non-empty if:
        // max(x, y) <= min(x+2, y+1)

        // Let's analyze the conditions:
        // For A to potentially reach a score S, S must be in [x, x+2].
        // For B to potentially reach a score S, S must be in [y, y+1].

        // If team A scores 'a' more goals and team B scores 'b' more goals,
        // where 0 <= a <= 2 and 0 <= b <= 1.
        // Final score for A = x + a
        // Final score for B = y + b
        // We need x + a = y + b for some valid a and b.

        // This is equivalent to checking if there's a target score 'S' such that:
        // S can be formed by A (i.e., x <= S <= x+2)
        // S can be formed by B (i.e., y <= S <= y+1)

        // The minimum possible final score for A is x.
        // The maximum possible final score for A is x + 2.
        // The minimum possible final score for B is y.
        // The maximum possible final score for B is y + 1.

        // For a draw to be possible, there must be an overlap in their achievable score ranges.
        // The highest score B can achieve is y+1. If A can also achieve at least y+1, then a draw is possible.
        // So, x+2 >= y+1.
        // The lowest score A can achieve is x. If B can also achieve at least x, then a draw is possible.
        // So, y+1 >= x.

        // Let's check the possible final scores for A and B.
        // A's possible final scores: x, x+1, x+2
        // B's possible final scores: y, y+1

        // We need to see if any of A's possible scores match any of B's possible scores.
        // This means checking if any score S in {x, x+1, x+2} is also in {y, y+1}.

        // This is true if:
        // (x == y) OR (x == y+1) OR
        // (x+1 == y) OR (x+1 == y+1) OR
        // (x+2 == y) OR (x+2 == y+1)

        // Let's simplify this.
        // The range of scores A can achieve is [x, x+2].
        // The range of scores B can achieve is [y, y+1].
        // A draw is possible if these two ranges overlap.
        // Two intervals [a, b] and [c, d] overlap if max(a, c) <= min(b, d).
        // Here, a=x, b=x+2, c=y, d=y+1.
        // So, overlap exists if max(x, y) <= min(x+2, y+1).

        // Let's test this condition:
        // max(x, y) <= min(x+2, y+1)

        // Example 1: x=1, y=2
        // max(1, 2) = 2
        // min(1+2, 2+1) = min(3, 3) = 3
        // 2 <= 3. YES.
        // A can score 1 (current) + 1 (in 4th) = 2. B can score 2 (current) + 0 (in 5th) = 2. Draw.

        // Example 2: x=3, y=0
        // max(3, 0) = 3
        // min(3+2, 0+1) = min(5, 1) = 1
        // 3 <= 1. False. NO.
        // A's range: [3, 5]. B's range: [0, 1]. No overlap.

        // Example 3: x=1, y=1
        // max(1, 1) = 1
        // min(1+2, 1+1) = min(3, 2) = 2
        // 1 <= 2. YES.
        // A can score 1 (current) + 0 (in 4th) + 1 (in 5th) = 2.
        // B can score 1 (current) + 1 (in 5th) = 2. Draw.

        // The condition max(x, y) <= min(x+2, y+1) seems correct.

        // Let's re-verify the logic.
        // Team A has 2 kicks left. Their final score will be X + (goals in 2 kicks).
        // Goals in 2 kicks can be 0, 1, or 2.
        // So A's final score can be X, X+1, or X+2.

        // Team B has 1 kick left. Their final score will be Y + (goals in 1 kick).
        // Goals in 1 kick can be 0 or 1.
        // So B's final score can be Y or Y+1.

        // For a draw, there must be a score S such that:
        // S is in {X, X+1, X+2} AND S is in {Y, Y+1}.

        // This means we need to check if any of the following are true:
        // X == Y
        // X == Y+1
        // X+1 == Y
        // X+1 == Y+1
        // X+2 == Y
        // X+2 == Y+1

        // Let's check these conditions directly.
        bool possible = false;
        // Check if A's possible scores can match B's possible scores.
        // A's possible scores: x, x+1, x+2
        // B's possible scores: y, y+1

        // Can A's score x match B's score y?
        if (x == y) possible = true;
        // Can A's score x match B's score y+1?
        if (x == y + 1) possible = true;

        // Can A's score x+1 match B's score y?
        if (x + 1 == y) possible = true;
        // Can A's score x+1 match B's score y+1?
        if (x + 1 == y + 1) possible = true;

        // Can A's score x+2 match B's score y?
        if (x + 2 == y) possible = true;
        // Can A's score x+2 match B's score y+1?
        if (x + 2 == y + 1) possible = true;

        if (possible) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
    return 0;
}