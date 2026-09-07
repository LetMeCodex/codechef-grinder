# [Mahasena (AMR15A)](https://www.codechef.com/problems/AMR15A)

- **Difficulty Rating**: 533
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to determine if an army is "ready for battle." We are given $N$ soldiers, each carrying a certain number of weapons. A soldier is considered "lucky" if they carry an even number of weapons and "unlucky" if they carry an odd number. The army is considered ready for battle if the number of lucky soldiers is strictly greater than the number of unlucky soldiers.

## Intuition & Mathematical Observation
The core of the problem is a simple parity check. For each soldier, we check if their weapon count $W$ is even or odd using the modulo operator ($W \pmod 2$). 
- If $W \pmod 2 == 0$, the soldier is lucky.
- If $W \pmod 2 \neq 0$, the soldier is unlucky.

By maintaining two counters and incrementing them based on these conditions, we can determine the final state of the army by comparing the two counts. Since we only need to know if `lucky > unlucky`, we do not need to store the individual weapon counts in an array, allowing for $O(1)$ auxiliary space.

## Complexity Analysis
- **Time Complexity**: $O(N)$, where $N$ is the number of soldiers. We iterate through the input list exactly once.
- **Space Complexity**: $O(1)$, as we only use a few integer variables to keep track of the counts regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Mahasena (AMR15A)
 * Approach:
 * 1. Read the number of soldiers N.
 * 2. Iterate through the N weapon counts.
 * 3. Maintain two counters: 'lucky' (even) and 'unlucky' (odd).
 * 4. Compare the counters: if lucky > unlucky, print "READY FOR BATTLE", else "NOT READY".
 * 
 * Time Complexity: O(N) where N is the number of soldiers.
 * Space Complexity: O(1) as we only store counters.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    int lucky = 0;
    int unlucky = 0;

    for (int i = 0; i < n; ++i) {
        int weapons;
        cin >> weapons;
        
        // Check if the number of weapons is even or odd
        if (weapons % 2 == 0) {
            lucky++;
        } else {
            unlucky++;
        }
    }

    // Determine if the army is ready based on the condition:
    // lucky count must be strictly greater than unlucky count.
    if (lucky > unlucky) {
        cout << "READY FOR BATTLE" << "\n";
    } else {
        cout << "NOT READY" << "\n";
    }

    return 0;
}
```