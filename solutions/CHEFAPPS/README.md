# Chef and his Apps (CHEFAPPS)

- **Difficulty Rating**: 702
- **Solved in**: 1 attempt(s)

## Problem Summary

Chef has a device with $S$ MB of memory. Currently, two apps are installed: App X with size $x$ MB and App Y with size $y$ MB. Chef wants to install a new app, App Z, which requires $z$ MB of free memory. Chef can uninstall existing apps to free up memory. The goal is to find the minimum number of apps Chef needs to uninstall to install App Z.

## Intuition & Mathematical Observation

The problem asks for the minimum number of uninstalls. This suggests we should check the possibilities in increasing order of uninstalls: 0, 1, and then 2.

1.  **0 Uninstalls**:
    If Chef uninstalls no apps, the currently used memory is $x + y$. The available memory is $S - (x + y)$. If this available memory is greater than or equal to $z$ (i.e., $S - (x + y) \ge z$), then Chef can install App Z without uninstalling anything. The answer is 0.

2.  **1 Uninstall**:
    If 0 uninstalls are not enough, Chef must uninstall at least one app. To maximize the available memory after uninstalling *one* app, Chef should uninstall the *larger* of the two existing apps (App X or App Y).
    *   If Chef uninstalls App X, the remaining used memory is $y$, and the available memory is $S - y$.
    *   If Chef uninstalls App Y, the remaining used memory is $x$, and the available memory is $S - x$.

    If either of these scenarios provides enough memory for App Z (i.e., $S - y \ge z$ OR $S - x \ge z$), then Chef can install App Z by uninstalling just one app. This condition can be simplified: we need to check if the memory remaining after uninstalling the *smaller* of the two apps is sufficient. If we uninstall the smaller app (let's say it's $x$), the remaining memory is $S - y$. If we uninstall the larger app (let's say it's $y$), the remaining memory is $S - x$. The most memory we can free up by uninstalling one app is by removing the larger one. However, to check if *any* single uninstall works, we need to see if uninstalling *either* app is sufficient. This means we check if $S - x \ge z$ or $S - y \ge z$. This is equivalent to checking if $S - \min(x, y) \ge z$. If this condition holds, the answer is 1.

3.  **2 Uninstalls**:
    If neither 0 nor 1 uninstall is sufficient, Chef must uninstall both App X and App Y. After uninstalling both, the used memory becomes 0, and the available memory is $S$. Since the problem constraints typically imply that $z \le S$ (or at least that it's possible to install Z if enough memory is freed), uninstalling both apps will always provide enough memory. Therefore, if the previous two conditions are not met, the answer must be 2.

The logic flows directly from these observations: check for 0 uninstalls, then 1 uninstall, and if neither works, conclude 2 uninstalls are necessary.

## Complexity Analysis

-   **Time Complexity**: $O(1)$
    The solution involves a fixed number of arithmetic operations and comparisons for each test case. The operations do not depend on the input values $S, x, y, z$ in terms of scaling.

-   **Space Complexity**: $O(1)$
    The solution uses a constant amount of extra space to store variables like $t, s, x, y, z$, and intermediate calculations. This space requirement does not grow with the input size.

## Solution Code

```cpp
#include <iostream>
#include <algorithm> // Required for std::min

int main() {
    // Optimize C++ standard streams for competitive programming
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; // Number of test cases
    std::cin >> t;
    while (t--) {
        int s, x, y, z; // Total memory, App X size, App Y size, App Z size
        std::cin >> s >> x >> y >> z;

        // Calculate memory currently used by App X and App Y
        int current_used = x + y;
        // Calculate memory available if no apps are uninstalled
        int available_memory_0_uninstalls = s - current_used;

        // Case 1: Check if 0 uninstalls are sufficient
        if (available_memory_0_uninstalls >= z) {
            std::cout << 0 << "\n";
        } else {
            // Case 2: Check if 1 uninstall is sufficient
            // To maximize free space with 1 uninstall, we should uninstall the larger app.
            // However, we only need to check if *either* uninstall works.
            // If we uninstall X, available memory is S - Y.
            // If we uninstall Y, available memory is S - X.
            // We need to check if (S - Y >= Z) OR (S - X >= Z).
            // This is equivalent to checking if S - std::min(X, Y) >= Z.
            // This means, after removing the smaller app, is there enough space?
            // Or, more precisely, if we remove the larger app, is there enough space?
            // The condition S - std::min(x, y) >= z checks if removing the smaller app
            // leaves enough space. If it does, then removing the larger app
            // (which leaves S - max(x,y) space) would also leave enough space.
            // The most direct check for 1 uninstall is:
            // Is S - x >= z OR S - y >= z?
            // This is equivalent to: S - std::min(x, y) >= z.
            if (s - std::min(x, y) >= z) {
                std::cout << 1 << "\n";
            } else {
                // Case 3: If 0 or 1 uninstall is not enough, 2 uninstalls are necessary.
                // Uninstalling both X and Y leaves S memory, which is always sufficient
                // as Z <= S is implied or achievable.
                std::cout << 2 << "\n";
            }
        }
    }
    return 0;
}
```