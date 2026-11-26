#include <iostream>

int main() {
    // Optimize C++ standard streams for faster input/output.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t; // Read the number of testcases

    while (t--) {
        long long n, k;
        std::cin >> n >> k; // Read N and K for each testcase

        long long max_score;

        // To maximize the score of the K-th ranked team, we assume this team is Team 1.
        // This is because Team 1 has the lowest team number, which is a disadvantage in tie-breaking.
        // By making it Team 1, if other teams have the same score, they will rank higher,
        // allowing Team 1 to be K-th even with a high score.

        // Team 1 plays N-1 games in total.
        // It plays N-K games against teams K+1, ..., N.
        // It plays K-1 games against teams 2, ..., K.

        // Strategy:
        // 1. Make Team 1 win all its games against teams K+1, ..., N.
        //    This gives (N-K) wins. Points: 2 * (N-K).
        //    These teams (K+1 to N) will have lower scores than Team 1 (or at most 0 points if they lose all games).

        // 2. Now consider the games among teams 1, ..., K.
        //    There are K teams in this sub-tournament. Team 1 plays K-1 games here.
        //    To make Team 1 the K-th ranked team overall, there must be K-1 teams ranked above it.
        //    We can achieve this by making teams 2, ..., K rank above Team 1.
        //    The most points Team 1 can get while being ranked K-th among teams 1, ..., K
        //    is if all teams 1, ..., K have the same score, or scores that are just enough to rank higher.

        //    Case A: K is odd.
        //    In a round-robin tournament with K (odd) teams, it's possible for all teams to win (K-1)/2 games.
        //    So, Team 1 can win (K-1)/2 games against teams 2, ..., K.
        //    This contributes 2 * ((K-1)/2) = K-1 points.
        //    In this scenario, teams 1, ..., K all have the same total score.
        //    Due to tie-breaking (higher team number is better), Team 1 (lowest number) will be ranked K-th among these K teams.
        //    Total score for Team 1 = 2 * (N-K) + (K-1).

        //    Case B: K is even.
        //    In a round-robin tournament with K (even) teams, it's impossible for all teams to have the same number of wins.
        //    The total number of wins is K*(K-1)/2. The average wins per team is (K-1)/2, which is not an integer.
        //    It's possible to arrange games such that K/2 teams win K/2 games (score K points)
        //    and K/2 teams win (K/2 - 1) games (score K-2 points).
        //    To maximize Team 1's score while ensuring it's K-th, we want it to have the highest possible score
        //    among the teams that are ranked lowest in this group.
        //    Team 1 can achieve (K-2) points from these internal games by winning (K-2)/2 games.
        //    The other K-1 teams (2, ..., K) can be arranged such that K-1 teams rank above Team 1.
        //    Total score for Team 1 = 2 * (N-K) + (K-2).

        if (k % 2 != 0) { // K is odd
            max_score = 2 * (n - k) + (k - 1);
        } else { // K is even
            max_score = 2 * (n - k) + (k - 2);
        }
        
        std::cout << max_score << "\n";
    }

    return 0;
}