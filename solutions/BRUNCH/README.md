# [Sunday Brunch (BRUNCH)](https://www.codechef.com/problems/BRUNCH)
- **Difficulty Rating**: 648
- **Solved in**: 1 attempt(s)

## Problem Summary

Chef has `X` plates of food. Each of his neighbors requires `Y` plates of food to be completely fed. Chef has at most 20 neighbors. The task is to determine the maximum number of neighbors Chef can completely feed.

## Intuition & Mathematical Observation

The problem asks us to find how many neighbors Chef can feed given his total plates and the requirement per neighbor, with an upper limit on the number of neighbors.

1.  **Plates per neighbor**: Each neighbor needs `Y` plates.
2.  **Total plates available**: Chef has `X` plates.
3.  **Maximum neighbors based on plates**: To find out how many neighbors Chef can *potentially* feed with `X` plates, where each takes `Y` plates, we perform integer division: `X / Y`. This gives us the maximum number of groups of `Y` plates that can be formed from `X` plates. For example, if `X = 10` and `Y = 3`, Chef can feed `10 / 3 = 3` neighbors completely, with 1 plate remaining.

4.  **Constraint on neighbors**: Chef only has at most 20 neighbors. This means even if he has enough plates to feed, say, 30 neighbors, he can still only feed a maximum of 20 because he doesn't have more neighbors than that.

5.  **Combining the observations**: The actual number of neighbors Chef can feed is limited by two factors:
    *   The number of neighbors he can feed based on the available plates (`X / Y`).
    *   The total number of neighbors he actually has (which is at most 20).

    Therefore, the final answer is the minimum of these two values: `min(X / Y, 20)`.

## Complexity Analysis

*   **Time Complexity**: For each test case, the solution involves reading two integers, performing one integer division, one `min` operation, and printing one integer. All these operations take constant time. Thus, for `T` test cases, the total time complexity is $O(T)$.
*   **Space Complexity**: The solution uses a few integer variables (`X`, `Y`, `T`, and the result) to store input and intermediate values. The amount of memory used does not depend on the input size. Therefore, the space complexity is $O(1)$.

## Solution Code

```cpp
#include <iostream> // Required for cin and cout
#include <algorithm> // Required for std::min

// It's common in competitive programming to include <bits/stdc++.h>
// which pulls in most standard library headers.
// For this specific problem, iostream and algorithm are sufficient.

// Using namespace std; is common in competitive programming to avoid
// repeatedly typing std::
using namespace std;

void solve() {
    int X, Y;
    cin >> X >> Y; // Read the number of plates Chef prepared (X) and plates each person takes (Y)

    // Calculate how many neighbours Chef can feed based on the total plates available.
    // Integer division X / Y automatically gives floor(X / Y), which is what we need
    // for "completely" feeding neighbours.
    int neighbours_fed_by_plates = X / Y;

    // Chef only has 20 neighbours. So, the maximum number of neighbours he can feed
    // cannot exceed 20, even if he has enough plates for more.
    // We take the minimum of the neighbours he can feed based on plates
    // and the actual total number of neighbours he has (20).
    int max_neighbours_completely_fed = min(neighbours_fed_by_plates, 20);

    // Output the result for the current test case, followed by a newline.
    cout << max_neighbours_completely_fed << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases

    // Loop through each test case
    while (T--) {
        solve(); // Call the solve function for each test case
    }

    return 0; // Indicate successful execution
}
```