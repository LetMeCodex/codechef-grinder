# Tekken (TEKKEN)
- **Difficulty Rating**: 947
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem describes a fighting scenario involving three characters: Anna (A), Bob (B), and Claudio (C). They fight in pairs. When two characters fight, say with health $X$ and $Y$, both their healths are reduced by $\min(X, Y)$. This means the character with lower health is eliminated (health becomes 0), and the character with higher health has their health reduced by the amount of the lower health. Anna wants to know if she can win, meaning if she can survive a fight. She can choose the order of fights.

## Intuition & Mathematical Observation

Anna wants to maximize her chances of survival. This means she wants to fight her opponents when they are as weak as possible. The optimal strategy for Anna is to let Bob and Claudio fight each other first.

Let's analyze the fight between Bob (B) and Claudio (C):
- If $B > C$, Bob wins. Bob's health becomes $B - C$. Claudio's health becomes $0$.
- If $C > B$, Claudio wins. Claudio's health becomes $C - B$. Bob's health becomes $0$.
- If $B = C$, both their healths become $0$.

In all cases, the winner of the fight between Bob and Claudio will have a health of $|B - C|$, and the loser will have a health of $0$.

Now, Anna (A) will fight the survivor of the Bob-Claudio match.
- If Bob won, Anna fights Bob with health $|B - C|$. Anna's health will be reduced by $\min(A, |B - C|)$.
- If Claudio won, Anna fights Claudio with health $|B - C|$. Anna's health will be reduced by $\min(A, |B - C|)$.
- If both were eliminated, Anna doesn't need to fight anyone and trivially wins. This case is covered by $|B-C| = 0$.

Anna wins if her health remains strictly positive after this fight. This means her initial health $A$ must be strictly greater than the health of the opponent she faces. The opponent's health is $|B - C|$.

Therefore, Anna wins if and only if $A > |B - C|$.

## Complexity Analysis

- **Time Complexity**: $O(1)$
    The solution involves reading three numbers and performing a constant number of arithmetic operations (subtraction, absolute value, comparison). This is independent of the input size.

- **Space Complexity**: $O(1)$
    The solution uses a fixed number of variables to store the health values and intermediate results. The memory usage does not grow with the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Anna (A), Bob (B), and Claudio (C) fight in pairs.
 * Each fight reduces both players' health by min(X, Y).
 * Effectively, the player with lower health becomes 0, and the player with
 * higher health reduces by the amount of the lower health.
 * 
 * To maximize Anna's final health, we want her to fight the opponents 
 * after they have potentially weakened each other.
 * 
 * Optimal Strategy:
 * 1. Let Bob and Claudio fight first. The winner (the one with more health) 
 *    will have health = abs(B - C).
 * 2. Anna then fights the winner of the first match.
 * 3. Anna's final health will be A - abs(B - C).
 * 4. If A - abs(B - C) > 0, then Anna has positive health.
 * 
 * This is equivalent to checking if A > abs(B - C).
 */

void solve() {
    long long A, B, C;
    // Read Anna's, Bob's, and Claudio's health
    if (!(cin >> A >> B >> C)) return;

    // The health of the opponent Anna faces after Bob and Claudio fight each other
    // is the absolute difference between their initial healths.
    long long opponent_health = abs(B - C);

    // Anna wins if her initial health is strictly greater than the 
    // remaining health of the opponent she faces last.
    if (A > opponent_health) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    // Read the number of test cases
    if (!(cin >> t)) return 0;
    // Process each test case
    while (t--) {
        solve();
    }
    return 0;
}
```