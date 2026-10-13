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
        // Let N be the total number of sets in the match. N is always odd.
        // The match stops when one player has won enough sets such that the other player
        // cannot possibly win, even if they win all remaining sets.
        //
        // Let the current score be (X, Y).
        // The total number of sets played so far is X + Y.
        // The number of remaining sets is N - (X + Y).
        //
        // For the match to stop, the player who is currently losing must have no chance
        // of winning the match.
        //
        // Case 1: Sonu is leading (X > Y).
        // The match stops if Titu cannot win, even if Titu wins all remaining sets.
        // Titu's maximum possible score = Y + (N - (X + Y)) = N - X.
        // For Titu to not win, Titu's maximum possible score must be less than or equal to Sonu's current score.
        // N - X <= X  => N <= 2*X.
        // However, the problem states that the match stops when one player has won *most* sets.
        // This implies that the winner has strictly more sets than the loser.
        // So, if Sonu is leading, the match stops if Titu cannot reach X sets.
        // Titu's maximum possible score = Y + (N - (X + Y)) = N - X.
        // For Titu to not win, Titu's maximum possible score must be strictly less than X.
        // N - X < X  => N < 2*X.
        // This is not quite right. The condition for stopping is that the *current leader* has won enough sets.
        // If Sonu has X sets and Titu has Y sets (X > Y), the match stops if Sonu has won more than half of the total sets N.
        // The condition for stopping is that the winner has won at least (N+1)/2 sets.
        // If Sonu wins, he needs at least (N+1)/2 sets.
        // If the match stops at (X, Y) with X > Y, it means Sonu has won the match.
        // This implies Sonu has won at least (N+1)/2 sets.
        // So, X >= (N+1)/2.
        // Also, Titu cannot win the match. Titu's maximum possible score is Y + (N - (X+Y)) = N - X.
        // For Titu to not win, N - X < X. This is incorrect.
        // The condition for stopping is that the current leader has won enough sets that the opponent cannot catch up.
        // If Sonu has X sets and Titu has Y sets (X > Y), and the match stops, it means Sonu has won.
        // This means Sonu has won at least (N+1)/2 sets.
        // So, X >= (N+1)/2.
        // The number of sets played is X + Y.
        // The number of remaining sets is N - (X + Y).
        // If Titu wins all remaining sets, his score becomes Y + (N - (X + Y)) = N - X.
        // For Sonu to be declared winner, Titu's maximum possible score must be less than Sonu's current score.
        // N - X < X is not the condition.
        // The condition is that the winner has won strictly more than half of the total sets.
        // If Sonu wins, X > N/2. Since N is odd, X >= (N+1)/2.
        // The match stops when the current leader has won enough sets that the opponent cannot reach the winning threshold.
        // Let the current score be (X, Y).
        // Assume X > Y. Sonu is leading.
        // The match stops if Sonu has won enough sets such that Titu cannot win.
        // Titu needs to win at least (N+1)/2 sets to win the match.
        // Titu's current score is Y.
        // The number of remaining sets is N - (X + Y).
        // Titu's maximum possible score is Y + (N - (X + Y)) = N - X.
        // For Titu to not win, Titu's maximum possible score must be less than (N+1)/2.
        // N - X < (N+1)/2
        // 2(N - X) < N + 1
        // 2N - 2X < N + 1
        // N < 2X + 1
        //
        // Also, the match must have played at least X+Y sets. So N >= X+Y.
        // And N must be odd.
        //
        // Let's re-evaluate the stopping condition.
        // The match stops if one player has won enough sets that the other player cannot possibly win.
        // Let the current score be (X, Y).
        // Suppose X > Y. Sonu is leading.
        // The match stops if Sonu has won enough sets that Titu cannot win.
        // Titu needs to win at least (N+1)/2 sets to win the match.
        // Titu's current score is Y.
        // The number of remaining sets is N - (X + Y).
        // Titu's maximum possible score is Y + (N - (X + Y)) = N - X.
        // For Titu to not win, Titu's maximum possible score must be less than the number of sets needed to win.
        // The number of sets needed to win is ceil(N/2). Since N is odd, this is (N+1)/2.
        // So, Titu's maximum possible score < (N+1)/2.
        // N - X < (N+1)/2
        // 2(N - X) < N + 1
        // 2N - 2X < N + 1
        // N < 2X + 1
        //
        // This means N can be at most 2X. Since N must be odd, N can be at most 2X - 1 if 2X is even, or 2X if 2X is odd.
        // Wait, the example explanation says:
        // Testcase 1: (2, 5), N=9. X=2, Y=5. Titu won.
        // N=9. Sets played = 7. Remaining = 2.
        // Sonu's max score = 2 + 2 = 4. Titu's score = 5. Titu wins.
        // If N=11. Sets played = 7. Remaining = 4.
        // Sonu's max score = 2 + 4 = 6. Titu's score = 5. Sonu would win.
        // So N cannot be 11 or more.
        // This implies that if the current leader has X sets and the opponent has Y sets (X > Y),
        // the match stops if the opponent cannot reach X sets even if they win all remaining sets.
        // Opponent's max score = Y + (N - (X+Y)) = N - X.
        // For the match to stop, N - X < X. This is incorrect.
        // The match stops if the current leader has won enough sets that the opponent cannot win.
        // If X > Y, Sonu is leading. Sonu wins if he has more than N/2 sets.
        // The match stops if the current leader has won enough sets that the opponent cannot reach the winning threshold.
        // The winning threshold is (N+1)/2.
        // If X > Y, Sonu is leading. The match stops if Titu cannot reach (N+1)/2 sets.
        // Titu's max score = Y + (N - (X+Y)) = N - X.
        // So, N - X < (N+1)/2.
        // 2(N - X) < N + 1
        // 2N - 2X < N + 1
        // N < 2X + 1
        //
        // Let's consider the example (2, 5). Y > X. Titu is leading.
        // Titu needs (N+1)/2 sets to win.
        // Titu's current score is 5.
        // Sets played = 7. Remaining = N - 7.
        // Sonu's max score = 2 + (N - 7) = N - 5.
        // For Titu to be declared winner, Sonu's max score must be less than Titu's current score.
        // N - 5 < 5 => N < 10.
        // This matches the example explanation: N cannot be 11 or more.
        // So, if Y > X, the match stops if Sonu cannot reach Y sets.
        // Sonu's max score = X + (N - (X+Y)) = N - Y.
        // For Titu to be declared winner, N - Y < Y is not the condition.
        // The condition is that the current leader has won enough sets that the opponent cannot win.
        // If Y > X, Titu is leading. Titu wins if he has more than N/2 sets.
        // The match stops if Titu has won enough sets that Sonu cannot win.
        // Sonu needs (N+1)/2 sets to win.
        // Sonu's max score = X + (N - (X+Y)) = N - Y.
        // For Sonu to not win, N - Y < (N+1)/2.
        // 2(N - Y) < N + 1
        // 2N - 2Y < N + 1
        // N < 2Y + 1
        //
        // So, if X > Y, N < 2X + 1.
        // If Y > X, N < 2Y + 1.
        // In general, N < 2 * max(X, Y) + 1.
        //
        // Also, the match must have played X+Y sets. So N must be at least X+Y.
        // And N must be odd.
        //
        // Let's check the examples with N < 2 * max(X, Y) + 1 and N >= X+Y and N is odd.
        //
        // Testcase 1: (2, 5). max(X, Y) = 5.
        // N < 2*5 + 1 => N < 11.
        // N >= 2 + 5 => N >= 7.
        // N must be odd. Possible N: 7, 9.
        // If N=7, sets played = 7. Remaining = 0. Score (2, 5). Titu wins.
        // If N=9, sets played = 7. Remaining = 2. Score (2, 5). Titu leads.
        // Sonu's max score = 2 + 2 = 4. Titu's score = 5. Titu wins.
        // If N=11, sets played = 7. Remaining = 4. Score (2, 5). Titu leads.
        // Sonu's max score = 2 + 4 = 6. Titu's score = 5. Sonu would win.
        // So N cannot be 11 or more. This means N < 11.
        // The smallest N that satisfies the condition is the answer.
        // The condition is that the match *could* have stopped at (X, Y).
        // This means that the current leader has won enough sets that the opponent cannot win.
        // Let M = max(X, Y).
        // Let m = min(X, Y).
        // If M = X, Sonu leads. The match stops if Titu cannot reach (N+1)/2 sets.
        // Titu's max score = m + (N - (X+Y)) = N - X.
        // So, N - X < (N+1)/2 => N < 2X + 1.
        // If M = Y, Titu leads. The match stops if Sonu cannot reach (N+1)/2 sets.
        // Sonu's max score = m + (N - (X+Y)) = N - Y.
        // So, N - Y < (N+1)/2 => N < 2Y + 1.
        //
        // In both cases, N < 2 * max(X, Y) + 1.
        //
        // Also, the match must have played X+Y sets. So N >= X+Y.
        // And N must be odd.
        //
        // The problem states "Can you find out N from just knowing the final score?".
        // This implies there is a unique N.
        //
        // Let's re-read the stopping condition carefully:
        // "if they notice at any point that one of them has no chance of winning the match, they will stop the match right then"
        //
        // Suppose score is (X, Y). Let M = max(X, Y), m = min(X, Y).
        // The number of sets played is X + Y.
        // The number of remaining sets is N - (X + Y).
        //
        // If M = X (Sonu leads):
        // Titu's maximum possible score = Y + (N - (X + Y)) = N - X.
        // For Titu to have no chance of winning, Titu's maximum possible score must be less than the number of sets required to win.
        // The number of sets required to win is (N+1)/2.
        // So, N - X < (N+1)/2.
        // 2(N - X) < N + 1
        // 2N - 2X < N + 1
        // N < 2X + 1.
        //
        // If M = Y (Titu leads):
        // Sonu's maximum possible score = X + (N - (X + Y)) = N - Y.
        // For Sonu to have no chance of winning, Sonu's maximum possible score must be less than the number of sets required to win.
        // The number of sets required to win is (N+1)/2.
        // So, N - Y < (N+1)/2.
        // 2(N - Y) < N + 1
        // 2N - 2Y < N + 1
        // N < 2Y + 1.
        //
        // Combining these, N < 2 * max(X, Y) + 1.
        //
        // Also, the match must have played X+Y sets. So N must be at least X+Y.
        // And N must be odd.
        //
        // The problem asks for "the value of N". This implies a unique N.
        // The sample explanations suggest that N is the *smallest odd integer* that satisfies the condition.
        //
        // Let's re-examine the sample explanations.
        //
        // Testcase 1: (2, 5). X=2, Y=5. max(X, Y) = 5.
        // N < 2*5 + 1 => N < 11.
        // N >= 2 + 5 => N >= 7.
        // N must be odd. Possible N: 7, 9.
        // If N=7, sets played = 7. Remaining = 0. Score (2, 5). Titu wins. This is a valid final score.
        // If N=9, sets played = 7. Remaining = 2. Score (2, 5). Titu leads.
        // Sonu's max score = 2 + 2 = 4. Titu's score = 5. Titu wins.
        // If N=11, sets played = 7. Remaining = 4. Score (2, 5). Titu leads.
        // Sonu's max score = 2 + 4 = 6. Titu's score = 5. Sonu would win.
        // So at score (2, 5), if N=11, the match would not have stopped.
        // This means N cannot be 11 or more. So N < 11.
        // The explanation says "N can't be lower than 9, since they would have stopped the match sooner."
        // This implies that if N was smaller, say N=7, the match would have ended earlier.
        // If N=7, the match ends when someone wins 4 sets.
        // If the score is (2, 5), it means 7 sets were played. Titu won.
        // This is consistent with N=7.
        //
        // The problem is about finding the *largest possible* N for which the match *could* have ended at (X, Y).
        //
        // Let's consider the condition for stopping.
        // The match stops at score (X, Y) if the current leader has won enough sets that the opponent cannot win.
        // Let M = max(X, Y), m = min(X, Y).
        // Let N be the total number of sets.
        // Number of sets played = X + Y.
        // Number of remaining sets = N - (X + Y).
        //
        // If M = X (Sonu leads):
        // Titu's max score = Y + (N - (X + Y)) = N - X.
        // For Titu to have no chance of winning, Titu's max score must be less than the number of sets needed to win.
        // The number of sets needed to win is (N+1)/2.
        // So, N - X < (N+1)/2.
        // 2(N - X) < N + 1
        // 2N - 2X < N + 1
        // N < 2X + 1.
        //
        // If M = Y (Titu leads):
        // Sonu's max score = X + (N - (X + Y)) = N - Y.
        // For Sonu to have no chance of winning, Sonu's max score must be less than the number of sets needed to win.
        // The number of sets needed to win is (N+1)/2.
        // So, N - Y < (N+1)/2.
        // 2(N - Y) < N + 1
        // 2N - 2Y < N + 1
        // N < 2Y + 1.
        //
        // So, N < 2 * max(X, Y) + 1.
        //
        // Also, the match must have played X+Y sets. So N must be at least X+Y.
        // And N must be odd.
        //
        // The problem statement implies that the match *did* stop at (X, Y).
        // This means that at score (X, Y), the current leader has won enough sets that the opponent cannot win.
        //
        // Let's consider the condition for *not* stopping.
        // The match *would not* stop if the opponent *still has a chance* to win.
        // If score is (X, Y), and X > Y. Sonu leads.
        // The match would not stop if Titu *can still win*.
        // Titu can still win if Titu's maximum possible score is >= (N+1)/2.
        // Titu's max score = Y + (N - (X+Y)) = N - X.
        // So, if N - X >= (N+1)/2, the match would not stop.
        // 2(N - X) >= N + 1
        // 2N - 2X >= N + 1
        // N >= 2X + 1.
        //
        // So, if the match *did* stop at (X, Y) with X > Y, it means N < 2X + 1.
        //
        // Similarly, if Y > X, and the match *did* stop, it means N < 2Y + 1.
        //
        // So, N < 2 * max(X, Y) + 1.
        //
        // Now consider the number of sets played: X + Y.
        // The total number of sets N must be at least the number of sets played.
        // So, N >= X + Y.
        //
        // And N must be odd.
        //
        // The problem asks for "the value of N". This implies a unique N.
        // The sample explanations suggest that N is the *largest possible odd integer* that satisfies the conditions.
        //
        // Let's test this hypothesis.
        //
        // Testcase 1: (2, 5). X=2, Y=5. max(X, Y) = 5.
        // N < 2*5 + 1 => N < 11.
        // N >= 2 + 5 => N >= 7.
        // N must be odd.
        // Possible N: 7, 9.
        // The largest odd N is 9. This matches the output.
        //
        // Testcase 2: (8, 10). X=8, Y=10. max(X, Y) = 10.
        // N < 2*10 + 1 => N < 21.
        // N >= 8 + 10 => N >= 18.
        // N must be odd.
        // Possible N: 19.
        // The largest odd N is 19. This matches the output.
        //
        // Testcase 3: (99, 1). X=99, Y=1. max(X, Y) = 99.
        // N < 2*99 + 1 => N < 199.
        // N >= 99 + 1 => N >= 100.
        // N must be odd.
        // Possible N: 101, 103, ..., 197.
        // The largest odd N is 197. This matches the output.
        //
        // Testcase 4: (4, 8). X=4, Y=8. max(X, Y) = 8.
        // N < 2*8 + 1 => N < 17.
        // N >= 4 + 8 => N >= 12.
        // N must be odd.
        // Possible N: 13, 15.
        // The largest odd N is 15. This matches the output.
        //
        // The logic seems to be:
        // 1. The total number of sets N must be at least the number of sets played (X + Y).
        // 2. The match stops if the current leader has won enough sets that the opponent cannot win.
        //    If Sonu leads (X > Y), the match stops if N < 2X + 1.
        //    If Titu leads (Y > X), the match stops if N < 2Y + 1.
        //    So, N < 2 * max(X, Y) + 1.
        // 3. N must be odd.
        //
        // We are looking for the largest odd N such that:
        // N >= X + Y
        // N < 2 * max(X, Y) + 1
        //
        // Let M = max(X, Y).
        // We need the largest odd N such that X + Y <= N < 2M + 1.
        //
        // The upper bound for N is 2M. Since N must be odd, the maximum possible odd N is 2M - 1 if 2M is even, or 2M if 2M is odd.
        // Since M is an integer, 2M is always even. So the maximum possible odd N is 2M - 1.
        //
        // So, we need the largest odd N such that X + Y <= N <= 2 * max(X, Y) - 1.
        //
        // Let's check the bounds again.
        // If N = 2 * max(X, Y), then N is even.
        // The condition is N < 2 * max(X, Y) + 1.
        // So N can be at most 2 * max(X, Y).
        // Since N must be odd, the largest possible odd N is 2 * max(X, Y) - 1.
        //
        // Let's re-verify the stopping condition.
        // If score is (X, Y), and X > Y. Sonu leads.
        // Match stops if Titu cannot win.
        // Titu needs (N+1)/2 sets.
        // Titu's max score = Y + (N - (X+Y)) = N - X.
        // For Titu to have no chance, N - X < (N+1)/2.
        // 2(N - X) < N + 1
        // 2N - 2X < N + 1
        // N < 2X + 1.
        //
        // This means N can be at most 2X. Since N must be odd, N can be at most 2X - 1.
        //
        // If Y > X, Titu leads.
        // Match stops if Sonu cannot win.
        // Sonu needs (N+1)/2 sets.
        // Sonu's max score = X + (N - (X+Y)) = N - Y.
        // For Sonu to have no chance, N - Y < (N+1)/2.
        // 2(N - Y) < N + 1
        // 2N - 2Y < N + 1
        // N < 2Y + 1.
        //
        // This means N can be at most 2Y. Since N must be odd, N can be at most 2Y - 1.
        //
        // So, N <= 2 * max(X, Y) - 1.
        //
        // And N >= X + Y.
        //
        // We need the largest odd N satisfying these.
        // The largest candidate for N is 2 * max(X, Y) - 1.
        // We need to check if this candidate is >= X + Y.
        //
        // Let M = max(X, Y).
        // Candidate N = 2*M - 1.
        // We need to ensure 2*M - 1 >= X + Y.
        //
        // Let's check the examples again.
        //
        // Testcase 1: (2, 5). X=2, Y=5. M=5.
        // Candidate N = 2*5 - 1 = 9.
        // Check: 9 >= 2 + 5 (7). Yes.
        // Output: 9. Correct.
        //
        // Testcase 2: (8, 10). X=8, Y=10. M=10.
        // Candidate N = 2*10 - 1 = 19.
        // Check: 19 >= 8 + 10 (18). Yes.
        // Output: 19. Correct.
        //
        // Testcase 3: (99, 1). X=99, Y=1. M=99.
        // Candidate N = 2*99 - 1 = 197.
        // Check: 197 >= 99 + 1 (100). Yes.
        // Output: 197. Correct.
        //
        // Testcase 4: (4, 8). X=4, Y=8. M=8.
        // Candidate N = 2*8 - 1 = 15.
        // Check: 15 >= 4 + 8 (12). Yes.
        // Output: 15. Correct.
        //
        // The formula seems to be N = 2 * max(X, Y) - 1.
        //
        // Let's consider the constraints and potential edge cases.
        // 1 <= X, Y <= 100.
        // X != Y.
        //
        // max(X, Y) will be between 2 and 100.
        // 2 * max(X, Y) - 1 will be between 2*2 - 1 = 3 and 2*100 - 1 = 199.
        // X + Y will be between 1+2=3 and 100+99=199.
        //
        // The condition N >= X + Y must hold.
        // Is 2 * max(X, Y) - 1 always >= X + Y?
        // Let M = max(X, Y), m = min(X, Y).
        // We need to check if 2*M - 1 >= M + m.
        // M - 1 >= m.
        // M - m >= 1.
        // Since X != Y, M > m, so M - m >= 1.
        // Thus, 2 * max(X, Y) - 1 is always greater than or equal to X + Y.
        //
        // So the answer is always 2 * max(X, Y) - 1.
        //
        // Let's double check the logic for the stopping condition.
        // "if they notice at any point that one of them has no chance of winning the match, they will stop the match right then"
        //
        // Consider score (X, Y). Let M = max(X, Y), m = min(X, Y).
        // Let N be the total number of sets.
        // Sets played = X + Y.
        // Remaining sets = N - (X + Y).
        //
        // If M = X (Sonu leads):
        // Titu's max score = Y + (N - (X + Y)) = N - X.
        // For Titu to have no chance of winning, Titu's max score must be strictly less than the number of sets needed to win.
        // The number of sets needed to win is (N+1)/2.
        // So, N - X < (N+1)/2.
        // 2(N - X) < N + 1
        // 2N - 2X < N + 1
        // N < 2X + 1.
        //
        // This means N can be at most 2X. Since N must be odd, N can be at most 2X - 1.
        //
        // If M = Y (Titu leads):
        // Sonu's max score = X + (N - (X + Y)) = N - Y.
        // For Sonu to have no chance of winning, Sonu's max score must be strictly less than the number of sets needed to win.
        // The number of sets needed to win is (N+1)/2.
        // So, N - Y < (N+1)/2.
        // 2(N - Y) < N + 1
        // 2N - 2Y < N + 1
        // N < 2Y + 1.
        //
        // This means N can be at most 2Y. Since N must be odd, N can be at most 2Y - 1.
        //
        // So, the maximum possible odd N is 2 * max(X, Y) - 1.
        //
        // We also need to ensure that the match could have reached score (X, Y).
        // This means N must be at least X + Y.
        //
        // We proved that 2 * max(X, Y) - 1 >= X + Y.
        //
        // So, the largest possible odd N is indeed 2 * max(X, Y) - 1.
        //
        // Let's consider the sample explanation for Testcase 1: (2, 5). Output 9.
        // "Suppose N = 11, then 4 more sets are remaining and if Sonu wins them all, Sonu's score (2 + 4 = 6) will become greater than Titu's score of 5. So at this point, they could not have stopped playing, and so N cannot be 11 or more."
        // This confirms that if N >= 2 * max(X, Y) + 1, the match would not stop.
        // Here max(X, Y) = 5. 2*5 + 1 = 11. So N cannot be 11 or more. N < 11.
        //
        // "But suppose N = 9, then 2 more sets are remaining and even if Sonu wins them all, he still cannot win, since 2 + 2 = 4 is still < 5. So it makes sense that they stopped right now."
        // Here N = 9. max(X, Y) = 5.
        // N = 9. 2*max(X, Y) - 1 = 2*5 - 1 = 9.
        // The condition N < 2*max(X, Y) + 1 is satisfied (9 < 11).
        // The condition N >= X + Y is satisfied (9 >= 2 + 5 = 7).
        //
        // The logic seems solid. The answer is always 2 * max(X, Y) - 1.

        int max_sets = std::max(x, y);
        int n = 2 * max_sets - 1;
        std::cout << n << "\n";
    }
    return 0;
}