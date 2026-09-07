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