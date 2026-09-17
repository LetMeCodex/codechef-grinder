# [Couple Game (COUGAME)](https://www.codechef.com/problems/COUGAME)

- **Difficulty Rating**: 347
- **Solved in**: 1 attempt(s)

## Problem Summary
In a group consisting of $G$ girls and $B$ boys, we need to form as many boy-girl couples as possible. Each couple must consist of exactly one boy and one girl. Given that $B > G$, we need to determine how many boys will remain single after forming the maximum possible number of couples.

## Intuition & Mathematical Observation
- Since each couple requires exactly one girl and one boy, the total number of couples that can be formed is limited by the number of girls available ($G$).
- We can pair all $G$ girls with $G$ boys.
- After forming $G$ couples, we will have used $G$ boys.
- The number of boys remaining is the total number of boys minus the number of boys paired with girls: $B - G$.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases, as we perform a constant time subtraction operation for each test case.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have G girls and B boys, where B > G.
 * Each team consists of exactly 1 girl and 1 boy.
 * To maximize the number of teams, we pair each girl with one boy.
 * Since there are G girls, we can form at most G teams.
 * Each team uses 1 boy, so G boys are used.
 * The number of boys remaining is B - G.
 * 
 * Time Complexity: O(T) where T is the number of test cases.
 * Space Complexity: O(1).
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long g, b;
        cin >> g >> b;
        
        // The number of boys left over is simply the difference
        // between the total number of boys and the number of girls.
        long long result = b - g;
        
        cout << result << "\n";
    }
    
    return 0;
}
```