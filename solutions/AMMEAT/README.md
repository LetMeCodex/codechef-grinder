# [Andrew and the Meatballs (AMMEAT)](https://www.codechef.com/problems/AMMEAT)
- **Difficulty Rating**: 1275
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to find the minimum number of plates Andrew needs to take to collect at least `M` meatballs. We are given `N` plates, and each plate `i` contains `P_i` meatballs. If it's impossible to collect `M` meatballs even by taking all available plates, we should output -1.

## Intuition & Mathematical Observation

To minimize the number of plates taken, Andrew should always prioritize picking plates that offer the most meatballs. This is a classic greedy approach.

**Why does this greedy strategy work?**
Consider two plates, A and B, with `P_A` and `P_B` meatballs respectively, where `P_A > P_B`. If Andrew needs to reach a target sum `M`, and he has the choice between plate A and plate B (assuming both are available), picking plate A (the one with more meatballs) will get him closer to `M` faster than picking plate B. By maximizing the meatballs collected with each plate, he minimizes the total number of plates required to reach the target sum `M`. Any other strategy (e.g., picking a smaller plate when a larger one is available) would either require the same number of plates (if the smaller plate was sufficient) or more plates (if the larger plate would have allowed him to reach `M` sooner).

Therefore, the optimal strategy is:
1.  Sort all plates in **descending order** based on the number of meatballs they contain.
2.  Iterate through the sorted plates, starting from the one with the most meatballs.
3.  Keep a running `current_sum` of meatballs collected and a `plates_count`.
4.  Add the meatballs from the current plate to `current_sum` and increment `plates_count`.
5.  Stop as soon as `current_sum` becomes greater than or equal to `M`. At this point, `plates_count` will be the minimum number of plates required.
6.  If we iterate through all `N` plates and `current_sum` is still less than `M`, it means it's impossible to collect `M` meatballs, so we output -1.

## Complexity Analysis

*   **Time Complexity**:
    *   Reading `N` and `M`: $O(1)$.
    *   Reading `N` plate values into a vector: $O(N)$.
    *   Sorting the `P` vector in descending order: `std::sort` takes $O(N \log N)$ time for `N` elements.
    *   Iterating through the sorted plates to find the sum: In the worst case, we might iterate through all `N` plates. This takes $O(N)$ time.
    *   The dominant operation is sorting. Therefore, the overall time complexity is $\mathcal{O}(N \log N)$.

*   **Space Complexity**:
    *   Storing the `N` plate values in a `std::vector<long long> P`: This requires $\mathcal{O}(N)$ space.
    *   Other variables (`N`, `M`, `current_sum`, `plates_count`, loop counter `i`) use constant space, $\mathcal{O}(1)$.
    *   Therefore, the overall space complexity is $\mathcal{O}(N)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes iostream, vector, algorithm, etc.

// Using namespace std as requested
using namespace std;

void solve() {
    int N;
    long long M; // M can be up to 10^18, so use long long
    cin >> N >> M;

    vector<long long> P(N); // P_i can be up to 10^18, so use long long
    for (int i = 0; i < N; ++i) {
        cin >> P[i];
    }

    // Sort plates in descending order.
    // std::sort with reverse iterators (rbegin(), rend()) sorts in descending order.
    sort(P.rbegin(), P.rend());

    long long current_sum = 0; // Sum of meatballs collected so far
    int plates_count = 0;      // Number of plates taken

    // Iterate through the sorted plates, picking the largest ones first
    for (int i = 0; i < N; ++i) {
        current_sum += P[i];
        plates_count++;
        if (current_sum >= M) {
            // We have collected enough meatballs, so this is the minimum number of plates
            break; 
        }
    }

    // Check if we successfully reached M meatballs
    if (current_sum >= M) {
        cout << plates_count << "\n";
    } else {
        // Even after taking all N plates, we couldn't reach M
        cout << -1 << "\n";
    }
}

int main() {
    // Fast I/O setup as requested
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Number of test cases
    cin >> T;
    while (T--) {
        solve(); // Solve each test case
    }

    return 0;
}
```