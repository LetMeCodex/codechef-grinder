# Round Robin Ranks (RRR)
- **Difficulty Rating**: -1
- **Solved in**: 3 attempt(s)

## Problem Summary
In a round-robin tournament with $N$ teams, each team plays every other team exactly once. A win earns 2 points, a draw 1 point, and a loss 0 points. If two teams have the same score, the team with the higher index (team number) wins the tie-breaker. We are given $N$ and $K$, and we need to find the maximum possible score for the $K$-th ranked team.

## Intuition & Mathematical Observation

The problem asks for the maximum possible score of the $K$-th ranked team. To maximize this score, we should try to assign scores such that the $K$-th ranked team has the highest possible score while still being the $K$-th ranked team.

Let's consider the teams numbered from 1 to $N$. The tie-breaking rule states that a higher team number wins ties. This means that if two teams have the same score, the team with the larger index will be ranked higher.

To maximize the score of the $K$-th ranked team, it's beneficial to make this team have the lowest possible team number among the top $K$ teams. This is because if we want to achieve a certain score for the $K$-th ranked team, and there are ties, the lower indexed teams will naturally fall to lower ranks. Therefore, we can assume that **Team 1** is the $K$-th ranked team.

Team 1 plays $N-1$ games in total. These games can be divided into two groups:
1. Games against teams with indices greater than $K$ (i.e., teams $K+1, K+2, \dots, N$). There are $N-K$ such teams.
2. Games against teams with indices less than or equal to $K$ (i.e., teams $2, 3, \dots, K$). There are $K-1$ such teams.

To maximize Team 1's score while ensuring it is the $K$-th ranked team, we can adopt the following strategy:

**Part 1: Games against teams $K+1, \dots, N$**
Team 1 should win all its games against these $N-K$ teams. This is because these teams have higher indices than Team 1. If Team 1 wins against them, it secures $2 \times (N-K)$ points. These wins also ensure that teams $K+1, \dots, N$ will have scores less than or equal to $2 \times (N-K-1)$ (if they win all their other games) or even 0 points, thus ensuring they are ranked below the top $K$ teams.

**Part 2: Games against teams $2, \dots, K$**
Now, we need to consider the $K-1$ games Team 1 plays against teams $2, \dots, K$. In this sub-tournament of $K$ teams (Team 1 to Team $K$), we want Team 1 to be ranked $K$-th. This means there must be $K-1$ teams ranked above Team 1.

We can achieve this by carefully arranging the outcomes of the games among teams $1, \dots, K$. The goal is to give Team 1 the highest possible score such that $K-1$ teams can be ranked above it.

Consider the properties of a round-robin tournament with $K$ participants:

*   **If $K$ is odd:**
    In a round-robin tournament with an odd number of participants ($K$), it is possible for every team to win exactly $(K-1)/2$ games. If Team 1 wins $(K-1)/2$ games against teams $2, \dots, K$, it gets $2 \times (K-1)/2 = K-1$ points from these games.
    If all teams from 1 to $K$ manage to achieve the same total score (by winning $(K-1)/2$ games within this group and potentially losing/drawing against teams outside this group in a way that balances scores), then due to the tie-breaking rule (higher team number wins), Team 1 (with the lowest index) will be ranked $K$-th among these $K$ teams.
    So, the total score for Team 1 would be $2 \times (N-K)$ (from games against teams $K+1$ to $N$) + $(K-1)$ (from games against teams $2$ to $K$).

*   **If $K$ is even:**
    In a round-robin tournament with an even number of participants ($K$), it's impossible for all teams to have the same number of wins. The total number of wins is $K(K-1)/2$. The average number of wins per team is $(K-1)/2$, which is not an integer.
    A common outcome in such tournaments is that approximately half the teams win $\lfloor (K-1)/2 \rfloor$ games and the other half win $\lceil (K-1)/2 \rceil$ games.
    To ensure Team 1 is ranked $K$-th, we need $K-1$ teams to rank above it. We can arrange the scores such that $K-1$ teams have scores higher than Team 1. The maximum score Team 1 can achieve while still being ranked $K$-th among teams $1, \dots, K$ is if it wins $(K-2)/2$ games against teams $2, \dots, K$. This gives $2 \times (K-2)/2 = K-2$ points.
    With this, we can construct a scenario where teams $2, \dots, K$ are ranked above Team 1. For example, teams $2, \dots, K$ can be arranged to have higher scores.
    So, the total score for Team 1 would be $2 \times (N-K)$ (from games against teams $K+1$ to $N$) + $(K-2)$ (from games against teams $2$ to $K$).

Combining these observations:
- If $K$ is odd, the maximum score for the $K$-th ranked team is $2(N-K) + (K-1)$.
- If $K$ is even, the maximum score for the $K$-th ranked team is $2(N-K) + (K-2)$.

This logic assumes that $K \ge 2$. If $K=1$, the 1st ranked team's score is simply the maximum possible score any team can achieve, which is $2(N-1)$ by winning all games. However, the problem constraints usually imply $K \ge 1$. The formula for odd $K$ works for $K=1$ if we interpret $K-1=0$ points from internal games, giving $2(N-1)$. The formula for even $K$ would require $K \ge 2$. Let's check the constraints or typical problem behavior. If $K=1$, the answer is $2(N-1)$. The formula $2(N-K) + (K-1)$ for odd $K$ gives $2(N-1) + (1-1) = 2(N-1)$ when $K=1$. So the odd case formula covers $K=1$.

The logic seems sound for $K \ge 1$.

## Complexity Analysis

- **Time Complexity**: $O(T)$, where $T$ is the number of testcases. For each testcase, we perform a few arithmetic operations, which take constant time.
- **Space Complexity**: $O(1)$. We only use a few variables to store input and the result.

## Solution Code

```cpp
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
            // If K=1, K-1 = 0. This correctly gives 2*(N-1) points.
            max_score = 2 * (n - k) + (k - 1);
        } else { // K is even
            // This case requires K >= 2. If K=0, this would be problematic, but K is usually >= 1.
            // If K=2, K-2 = 0. This gives 2*(N-2) points.
            max_score = 2 * (n - k) + (k - 2);
        }
        
        std::cout << max_score << "\n";
    }

    return 0;
}
```