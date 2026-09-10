# [Puzzle Hunt (PUZHUNT)](https://www.codechef.com/problems/PUZHUNT)

- **Difficulty Rating**: 279
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to determine if a team of size $N$ is eligible to participate in a puzzle hunt. According to the rules, a team is only valid if the number of members is at least 6 and at most 8 (inclusive). Given an integer $N$, we need to output "Yes" if $6 \le N \le 8$, and "No" otherwise.

## Intuition & Mathematical Observation
The problem defines a simple range-based condition. We are given an integer $N$ where $1 \le N \le 10$. 
- If $N$ is 6, 7, or 8, the condition is satisfied.
- For any other value in the given range (1, 2, 3, 4, 5, 9, 10), the condition is not satisfied.

We can implement this using a simple conditional `if-else` statement or a logical comparison: `(N >= 6 && N <= 8)`.

## Complexity Analysis
- **Time Complexity**: $O(1)$ — The solution performs a constant number of comparisons regardless of the input size.
- **Space Complexity**: $O(1)$ — We only use a single integer variable to store the input, requiring constant extra space.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: PUZHUNT
 * The team size must be between 6 and 8 inclusive.
 * Constraints: 1 <= N <= 10.
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return 0;

    // Check if N is in the range [6, 8]
    if (N >= 6 && N <= 8) {
        cout << "Yes" << "\n";
    } else {
        cout << "No" << "\n";
    }

    return 0;
}
```