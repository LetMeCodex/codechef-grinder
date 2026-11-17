# [Chef and Work (CHEFNWRK)](https://www.codechef.com/problems/CHEFNWRK)

- **Difficulty Rating**: 1185
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef has $N$ boxes, each with a specific weight $w_i$. He needs to transport all these boxes to a destination using a container that can carry a maximum weight of $K$ per trip. Chef can only pick up boxes in the order they are given (sequentially). We need to find the minimum number of trips required to transport all boxes. If any single box weighs more than $K$, it is impossible to transport, and we should output `-1`.

## Intuition & Mathematical Observation
1. **Feasibility Check**: Before calculating trips, we must verify if any individual box exceeds the capacity $K$. If $w_i > K$ for any $i$, it is impossible to move that box, so we return `-1`.
2. **Greedy Approach**: Since the boxes must be picked up in the given order, we can use a greedy strategy. We keep adding boxes to the current trip as long as the total weight does not exceed $K$. 
3. **Trip Logic**:
   - Maintain a `current_weight` variable.
   - Iterate through the boxes:
     - If adding the current box to `current_weight` stays within $K$, add it.
     - If it exceeds $K$, increment the `trips` counter and start a new trip with the current box as the first item.
   - After the loop, if `current_weight > 0`, it means there are boxes left that were not counted in a completed trip, so we increment `trips` one last time.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the number of boxes. We iterate through the list of boxes exactly once.
- **Space Complexity**: $O(N)$ to store the weights of the boxes. (Note: This could be optimized to $O(1)$ by processing the input on the fly, but $O(N)$ is well within limits).

## Solution Code

```cpp
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

int main() {
    // Optimize I/O operations
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    while (t--) {
        int n;
        long long k;
        std::cin >> n >> k;
        std::vector<long long> w(n);
        bool possible = true;
        
        for (int i = 0; i < n; ++i) {
            std::cin >> w[i];
            // If any single box is heavier than capacity, it's impossible
            if (w[i] > k) {
                possible = false;
            }
        }

        if (!possible) {
            std::cout << -1 << "\n";
            continue;
        }

        int trips = 0;
        long long current_weight = 0;
        for (int i = 0; i < n; ++i) {
            // Try to fit the box in the current trip
            if (current_weight + w[i] <= k) {
                current_weight += w[i];
            } else {
                // Start a new trip
                trips++;
                current_weight = w[i];
            }
        }
        
        // If there are any boxes left to carry, they need one final trip.
        if (current_weight > 0) {
            trips++;
        }

        std::cout << trips << "\n";
    }
    return 0;
}
```