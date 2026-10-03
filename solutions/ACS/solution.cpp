#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int p;
        cin >> p;

        if (p < 0 || p > 1000) {
            cout << -1 << "\n";
        } else {
            // The maximum score is 10 problems * 100 points/problem = 1000 points.
            // The minimum score is 0 problems * 1 point/problem = 0 points.
            // Any score outside this range is invalid.
            // The problem states there are 10 problems, each worth 1 or 100 points.
            // Let 'x' be the number of 100-point problems and 'y' be the number of 1-point problems.
            // We know x + y <= 10 (total number of problems).
            // The total score P = 100*x + 1*y.
            // We want to find the total number of solved problems, which is x + y.

            // We can iterate through all possible numbers of 100-point problems (from 0 to 10).
            // For each number of 100-point problems, we check if the remaining score can be formed by 1-point problems.
            // The number of 100-point problems can be at most 10.
            // The maximum score from 100-point problems is 10 * 100 = 1000.
            // So, the number of 100-point problems can be at most p / 100.
            // Also, the number of 100-point problems cannot exceed 10.

            int solved_problems = -1;

            for (int num_100_point = 0; num_100_point <= 10; ++num_100_point) {
                int score_from_100 = num_100_point * 100;
                if (score_from_100 <= p) {
                    int remaining_score = p - score_from_100;
                    // The remaining score must be formed by 1-point problems.
                    // The number of 1-point problems is equal to the remaining score.
                    int num_1_point = remaining_score;

                    // The total number of problems solved is num_100_point + num_1_point.
                    // This total must not exceed 10.
                    if (num_100_point + num_1_point <= 10) {
                        // We found a valid combination. Since we are iterating from
                        // fewer 100-point problems to more, and the problem asks for
                        // *the* number of problems solved, we can assume there's a unique solution
                        // or any valid solution is acceptable. The problem implies a unique count.
                        // The greedy approach of maximizing 100-point problems first is optimal.
                        // Let's re-evaluate.
                        // P = 100*x + y, where x+y <= 10.
                        // We want to maximize x+y.
                        // If we fix x, then y = P - 100*x.
                        // We need x + (P - 100*x) <= 10
                        // P - 99*x <= 10
                        // P - 10 <= 99*x
                        // x >= (P - 10) / 99
                        // Also, x must be <= 10 and 100*x <= P.
                        // And y = P - 100*x must be >= 0.

                        // Let's try a greedy approach: maximize the number of 100-point problems.
                        int max_100_point_problems = min(10, p / 100);
                        int current_score = max_100_point_problems * 100;
                        int current_problems = max_100_point_problems;

                        if (current_score <= p) {
                            int remaining_p = p - current_score;
                            // The remaining points must be from 1-point problems.
                            // The number of 1-point problems is remaining_p.
                            // The total number of problems is max_100_point_problems + remaining_p.
                            if (max_100_point_problems + remaining_p <= 10) {
                                solved_problems = max_100_point_problems + remaining_p;
                                break; // Found the solution
                            }
                        }
                    }
                }
            }
            
            // The loop above is a bit complex. Let's simplify.
            // We want to find x and y such that 100*x + y = P, x+y <= 10, x >= 0, y >= 0.
            // We want to output x+y.
            // The number of 100-point problems 'x' can range from 0 to 10.
            // For a given 'x', the score from these problems is 100*x.
            // The remaining score must be 'y', so y = P - 100*x.
            // We need to check two conditions:
            // 1. y >= 0 (meaning P >= 100*x)
            // 2. x + y <= 10 (meaning x + (P - 100*x) <= 10)

            int ans = -1;
            for (int x = 0; x <= 10; ++x) {
                int score_100 = x * 100;
                if (score_100 <= p) {
                    int y = p - score_100;
                    if (y >= 0 && x + y <= 10) {
                        ans = x + y;
                        break; // Found a valid combination, and since we iterate x from 0 upwards,
                               // this will find the solution with the minimum number of 100-point problems
                               // that satisfies the conditions. The problem implies a unique number of solved problems.
                               // Let's verify if this greedy choice is correct.
                               // If P = 103, x=1, score_100=100, y=3. x+y=4. Valid.
                               // If P = 6, x=0, score_100=0, y=6. x+y=6. Valid.
                               // If P = 1000, x=10, score_100=1000, y=0. x+y=10. Valid.
                               // If P = 142,
                               // x=0: score_100=0, y=142. x+y=142 > 10. Invalid.
                               // x=1: score_100=100, y=42. x+y=43 > 10. Invalid.
                               // x=2: score_100=200 > 142. Stop.
                               // So, 142 is invalid.

                               // The loop correctly finds the solution.
                               // The problem statement implies that if a score is achievable, there is a unique number of problems solved.
                               // Let's consider if multiple combinations of (x, y) could yield the same total score P and also satisfy x+y <= 10.
                               // Suppose we have two pairs (x1, y1) and (x2, y2) such that:
                               // 100*x1 + y1 = P
                               // 100*x2 + y2 = P
                               // x1 + y1 <= 10
                               // x2 + y2 <= 10
                               // And we want to show that x1 + y1 = x2 + y2.
                               // From the first two equations: 100*x1 + y1 = 100*x2 + y2
                               // y1 = P - 100*x1
                               // y2 = P - 100*x2
                               // Substitute into the inequality:
                               // x1 + (P - 100*x1) <= 10  => P - 99*x1 <= 10
                               // x2 + (P - 100*x2) <= 10  => P - 99*x2 <= 10
                               // This means that for any valid solution (x, y), P - 99*x <= 10.
                               // If we iterate x from 0 to 10, the first x that satisfies P - 100*x >= 0 and x + (P - 100*x) <= 10 will give us the answer.
                               // The number of problems solved is x + y = x + (P - 100*x) = P - 99*x.
                               // If there were two valid pairs (x1, y1) and (x2, y2) with x1 != x2, then P - 99*x1 would be different from P - 99*x2.
                               // This implies that the number of solved problems would be different.
                               // However, the problem statement implies a unique number of solved problems.
                               // This suggests that for a given valid score P, there is only one pair (x, y) that satisfies the conditions.
                               // Let's re-read: "determine the number of problems solved by the participant."
                               // This implies a unique answer.
                               // The constraints are P <= 1000.
                               // The maximum number of 100-point problems is 10.
                               // If P = 103:
                               // x=0: y=103. x+y=103 > 10. Invalid.
                               // x=1: y=3. x+y=4. Valid. ans=4. Break.
                               // If P = 1000:
                               // x=0..9: y will be large, x+y > 10.
                               // x=10: y=0. x+y=10. Valid. ans=10. Break.
                               // If P = 100:
                               // x=0: y=100. x+y=100 > 10. Invalid.
                               // x=1: y=0. x+y=1. Valid. ans=1. Break.
                               // If P = 101:
                               // x=0: y=101. x+y=101 > 10. Invalid.
                               // x=1: y=1. x+y=2. Valid. ans=2. Break.
                               // If P = 109:
                               // x=0: y=109. x+y=109 > 10. Invalid.
                               // x=1: y=9. x+y=10. Valid. ans=10. Break.
                               // If P = 110:
                               // x=0: y=110. x+y=110 > 10. Invalid.
                               // x=1: y=10. x+y=11 > 10. Invalid.
                               // x=2: y=-90. Invalid.
                               // So 110 is invalid.

                               // The loop correctly finds the unique answer if one exists.
                               // The condition `score_100 <= p` ensures `y >= 0`.
                               // The condition `x + y <= 10` ensures the total number of problems is within limits.
                               // The loop iterates `x` from 0 to 10. The first `x` that satisfies both conditions will give the correct `x+y`.
                               // Since `x+y = P - 99*x`, if there were two valid `x` values, say `x1` and `x2`, then `P - 99*x1` would be different from `P - 99*x2`, meaning different numbers of solved problems.
                               // The problem implies a unique number of solved problems for a valid score.
                               // This means there can be at most one `x` in the range [0, 10] such that `100*x <= P` and `x + (P - 100*x) <= 10`.
                               // The loop finds this `x` and calculates `x+y`.
                               // If no such `x` is found, `ans` remains -1.
                                break; // Exit the loop once a valid combination is found.
                    }
                }
            }
            cout << ans << "\n";
        }
    }
    return 0;
}