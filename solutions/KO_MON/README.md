# [Monster Monster (KO_MON)](https://www.codechef.com/problems/KO_MON)
- **Difficulty Rating**: 1184
- **Solved in**: 1 attempt(s)

## Problem Summary

We are given `N` monsters, each with an initial health `H_i`. We have an attack stat `A`. We can defeat exactly one monster per day. On day `k` (1-indexed), a monster's health increases by `(k-1) * X`. To defeat a monster on day `k`, its effective health on that day, `H_i + (k-1) * X`, must be less than or equal to our attack `A`. Our goal is to find the minimum possible attack `A` that allows us to defeat all `N` monsters.

## Intuition & Mathematical Observation

1.  **Monotonicity and Binary Search**: The problem asks for the *minimum* `A`. Notice that if a certain attack `A` is sufficient to defeat all monsters, then any attack `A' > A` will also be sufficient. This monotonic property allows us to use binary search on the possible values of `A`.

    *   **Lower Bound for `A`**: The minimum possible `A` must be at least the maximum initial health among all monsters (`max(H_i)`), because even on day 1 (when `k-1=0`), we need to be able to defeat the strongest monster.
    *   **Upper Bound for `A`**: A safe upper bound can be estimated. In the worst case, we might kill the strongest monster on day `N`. Its health would be `max(H_i) + (N-1)*X`. Given `N=2*10^5`, `H_i=10^9`, `X=10^9`, this can be approximately `10^9 + (2*10^5 - 1) * 10^9 \approx 2 * 10^{14}`. A value like `2 * 10^{14} + 7` is a sufficiently large upper bound.

2.  **The `can(A)` Function (Greedy Strategy)**: The core of the binary search is a function `can(A)` that checks if a given attack `A` is sufficient to defeat all `N` monsters. To make `A` sufficient, we need to assign each monster to a day such that its effective health on that day does not exceed `A`. To minimize the required `A` (or to maximize our chances of `A` being sufficient), we should try to kill the monsters that become "hardest" to kill as early as possible.

    *   A monster with higher initial `H_i` is generally harder to kill.
    *   Killing a monster on a later day `k` means its health increases by a larger `(k-1)*X` factor, making it harder to kill.
    *   Therefore, the optimal strategy for the `can(A)` function is to sort the monsters by their initial health `H_i` in **decreasing order**.
    *   Then, we greedily assign the strongest monster (`H_0` after sorting) to day 1, the second strongest (`H_1`) to day 2, and so on, until the weakest monster (`H_{N-1}`) is assigned to day `N`.

    Let's formalize the check for `H_i` (the `i`-th monster in the *sorted decreasing* list, 0-indexed) assigned to day `i+1`:
    The condition is `H_i + ( (i+1) - 1 ) * X <= A`, which simplifies to `H_i + i * X <= A`.
    This can be rewritten as `i * X <= A - H_i`, or `i <= (A - H_i) / X`.
    Let `max_day_multiplier = (A - H_i) / X`. This represents the maximum `(k-1)` value for which monster `H_i` can be killed with attack `A`.
    For `A` to be sufficient, for each monster `H_i` (0-indexed in the sorted list), its `max_day_multiplier` must be at least `i` (since it's assigned to day `i+1`, which corresponds to a multiplier of `i`). If `max_day_multiplier < i` for any monster, then `A` is not sufficient.

    The `can(A)` function proceeds as follows:
    1.  Sort the monster HPs `H` in decreasing order.
    2.  For each monster `H[i]` (where `i` is its 0-indexed position in the sorted list):
        a.  Calculate `max_day_multiplier = (A - H[i]) / X`.
        b.  If `A < H[i]`, it means `A - H[i]` is negative. In this case, `max_day_multiplier` would be negative or zero, which is definitely less than `i` (for `i >= 0`). So, `A` is insufficient. This also handles cases where `A - H[i]` might be negative, preventing incorrect integer division behavior.
        c.  If `max_day_multiplier < i`, then `A` is insufficient.
    3.  If all monsters satisfy the condition, `A` is sufficient.

## Complexity Analysis

*   **Time Complexity**:
    *   **Sorting**: `std::sort(H.rbegin(), H.rend())` takes $O(N \log N)$ time.
    *   **`can` function**: This function iterates through the `N` monsters once. Each operation inside the loop is constant time. Thus, `can(A)` takes $O(N)$ time.
    *   **Binary Search**: The binary search performs $O(\log(\text{max_A_value}))$ iterations. The maximum value for `A` is approximately $2 \cdot 10^{14}$. $\log_2(2 \cdot 10^{14}) \approx 48$.
    *   **Total Time**: The overall time complexity is dominated by the initial sort and the binary search calls to `can(A)`. This results in $O(N \log N + N \cdot \log(\text{max_A_value}))$. Since `log(max_A_value)` (around 48) is typically larger than `log N` (for $N=2 \cdot 10^5$, $\log_2 N \approx 18$), the term $N \cdot \log(\text{max_A_value})$ is dominant.
    *   Therefore, the time complexity is $O(N \log(\text{max_A_value}))$.

*   **Space Complexity**:
    *   The `std::vector<long long> H(N)` stores the monster HPs, requiring $O(N)$ space.
    *   All other variables use constant space.
    *   Thus, the total space complexity is $O(N)$.

## Solution Code

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

// Function to check if a given attack stat A is sufficient
// H_sorted_desc: vector of monster HPs sorted in decreasing order
bool can(long long A, int N, long long X, const std::vector<long long>& H_sorted_desc) {
    for (int i = 0; i < N; ++i) {
        long long current_H = H_sorted_desc[i];
        
        // If A is less than current_H, this monster cannot be killed even on day 1.
        // This also handles cases where A - current_H would be negative,
        // preventing incorrect floor division behavior for negative numbers.
        if (A < current_H) {
            return false;
        }
        
        // Calculate the maximum (0-indexed) day multiplier (k-1)
        // such that H_i + (k-1)*X <= A
        // (k-1)*X <= A - H_i
        // k-1 <= (A - H_i) / X
        // Integer division in C++ for non-negative numbers correctly computes floor.
        long long max_day_multiplier = (A - current_H) / X;
        
        // The i-th monster (0-indexed) in the sorted list is assigned to be killed on day (i+1).
        // For this to be possible, the maximum allowed day multiplier for this monster
        // must be at least 'i' (since day 'i+1' corresponds to multiplier 'i').
        // If max_day_multiplier < i, it means this monster cannot be killed on day (i+1)
        // or any later day, which is required by its position in the sorted list.
        if (max_day_multiplier < i) {
            return false;
        }
    }
    return true;
}

void solve() {
    int N;
    long long X;
    std::cin >> N >> X;
    std::vector<long long> H(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> H[i];
    }

    // Sort HPs in decreasing order.
    // This is crucial for the `can` function's greedy assignment logic.
    // H_sorted_desc[i] will be the (i+1)-th monster to be killed.
    std::sort(H.rbegin(), H.rend()); // Sorts in reverse (decreasing) order

    // Initialize binary search range for A
    long long low = H[0]; // Minimum possible A is the largest initial HP
    // A safe upper bound for A.
    // Max H_i + (N-1)*X. Max H_i = 10^9, Max N = 2*10^5, Max X = 10^9.
    // 10^9 + (2*10^5 - 1) * 10^9 approx 2 * 10^14.
    long long high = 200000000000000LL + 7; // A bit more than 2 * 10^14 for safety
    long long ans = high; // Initialize answer with a value that is definitely possible (or higher)

    // Binary search for the minimum A
    while (low <= high) {
        long long mid = low + (high - low) / 2; // Prevent overflow for (low+high)
        if (can(mid, N, X, H)) {
            ans = mid;         // mid is a possible answer, try for a smaller one
            high = mid - 1;
        } else {
            low = mid + 1;     // mid is too small, need a larger A
        }
    }
    std::cout << ans << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T; // Read the number of test cases
    while (T--) {
        solve(); // Solve each test case
    }
    return 0;
}

```