# [Carrot Collection (CARRCOL)](https://www.codechef.com/problems/CARRCOL)
- **Difficulty Rating**: 914
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to find the maximum number of carrots a rabbit can collect. There are $N$ clearings arranged linearly, each containing a certain number of carrots. A bear patrols a contiguous range of clearings from $L$ to $R$ (1-indexed). The rabbit cannot enter any clearing that the bear patrols. The rabbit can start in any clearing that is *not* patrolled by the bear and can move to adjacent clearings as long as they are also not patrolled.

## Intuition & Mathematical Observation

The core of the problem lies in understanding the rabbit's movement capabilities and the constraints imposed by the bear's patrol.

1.  **Bear's Patrol Zone**: The bear patrols clearings from index $L$ to $R$ (inclusive, 1-indexed). In a 0-indexed array representation, this corresponds to indices $L-1$ to $R-1$.

2.  **Rabbit's Safe Zones**: The rabbit can only visit clearings *outside* the bear's patrol zone. These safe zones are:
    *   **Left Safe Zone**: Clearings from 1 to $L-1$ (0-indexed: $0$ to $L-2$).
    *   **Right Safe Zone**: Clearings from $R+1$ to $N$ (0-indexed: $R$ to $N-1$).

3.  **Rabbit's Movement**: The rabbit can start in *any* clearing within a safe zone. Crucially, the problem states the rabbit can move left/right as many times as they like. This implies that if the rabbit starts in any clearing within a *connected component* of safe clearings, it can reach *all* other clearings within that same connected component.

4.  **Connected Components of Safe Zones**: The safe zones form two distinct, non-overlapping segments:
    *   The segment from index $0$ to $L-2$.
    *   The segment from index $R$ to $N-1$.

    These are the only two connected components of safe clearings. The rabbit cannot move between these two segments because the bear's patrol zone lies in between.

5.  **Maximizing Carrots**: Since the rabbit can collect all carrots from any single connected component of safe clearings it chooses to enter, the optimal strategy is to pick the connected component that yields the maximum total number of carrots.
    *   If the rabbit starts in the left safe zone (indices $0$ to $L-2$), it can collect the sum of carrots from all clearings in this range.
    *   If the rabbit starts in the right safe zone (indices $R$ to $N-1$), it can collect the sum of carrots from all clearings in this range.

    The maximum number of carrots the rabbit can collect is therefore the maximum of these two sums.

6.  **Edge Cases and Guarantees**: The problem statement guarantees that either $L > 1$ or $R < N$. This ensures that at least one of the safe zones is non-empty.
    *   If $L=1$, the left safe zone is empty.
    *   If $R=N$, the right safe zone is empty.
    *   If $L>1$, the left safe zone exists.
    *   If $R<N$, the right safe zone exists.

    The code handles these cases by checking if $l > 1$ before summing the left zone and if $r < n$ before summing the right zone. If a zone is empty, its sum will naturally be 0.

Therefore, the solution involves calculating the sum of carrots in the left safe zone (if it exists) and the sum of carrots in the right safe zone (if it exists), and then returning the larger of these two sums.

## Complexity Analysis

-   **Time Complexity**: $O(N)$
    The code iterates through the input array `a` twice in the worst case: once to calculate the sum of carrots in the left safe zone and once for the right safe zone. Each iteration takes time proportional to the size of the respective safe zone. Since the total number of elements processed across both sums is at most $N$, the overall time complexity is linear with respect to the number of clearings, $N$.

-   **Space Complexity**: $O(N)$
    The code uses a `std::vector<int> a` to store the number of carrots in each clearing. This vector requires $O(N)$ space. The other variables use constant extra space.

## Solution Code

```cpp
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

int main() {
    // Optimize C++ standard streams for competitive programming
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; // Number of test cases
    std::cin >> t;
    while (t--) {
        int n; // Number of clearings
        int l, r; // Bear's patrol range (1-indexed)
        std::cin >> n >> l >> r;

        std::vector<int> a(n); // Carrots in each clearing (0-indexed)
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
        }

        long long max_carrots = 0; // Variable to store the maximum carrots collected

        // The bear patrols clearings L to R (1-indexed).
        // In 0-indexed array, this is indices L-1 to R-1.
        // The rabbit cannot visit indices from L-1 to R-1.

        // The rabbit can start in any clearing not patrolled by the bear.
        // These are clearings 1 to L-1 (indices 0 to L-2)
        // and clearings R+1 to N (indices R to N-1).

        // Case 1: Rabbit starts in the left safe zone (clearings 1 to L-1)
        // If L > 1, the left safe zone is non-empty.
        // The rabbit can reach all clearings from index 0 to L-2.
        if (l > 1) {
            long long current_carrots_left = 0;
            // Sum carrots from index 0 up to (but not including) L-1
            for (int i = 0; i < l - 1; ++i) {
                current_carrots_left += a[i];
            }
            // Update max_carrots if this zone yields more
            max_carrots = std::max(max_carrots, current_carrots_left);
        }

        // Case 2: Rabbit starts in the right safe zone (clearings R+1 to N)
        // If R < N, the right safe zone is non-empty.
        // The rabbit can reach all clearings from index R to N-1.
        if (r < n) {
            long long current_carrots_right = 0;
            // Sum carrots from index R up to N-1
            for (int i = r; i < n; ++i) {
                current_carrots_right += a[i];
            }
            // Update max_carrots if this zone yields more
            max_carrots = std::max(max_carrots, current_carrots_right);
        }
        
        // The problem guarantees that either L > 1 or R < N, meaning at least one
        // safe zone is guaranteed to exist. The rabbit will choose the zone
        // that offers the maximum total carrots.

        std::cout << max_carrots << "\n";
    }
    return 0;
}
```