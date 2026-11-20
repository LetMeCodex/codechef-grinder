# [Food Resources (FOODRES)](https://www.codechef.com/problems/FOODRES)
- **Difficulty Rating**: 1235
- **Solved in**: 1 attempt(s)

## Problem Summary

You are given `N` types of food, and `M` people. For each food type `i`, you have `A[i]` units. Each person consumes 1 unit of food per day. If a food type `i` is used to feed people for `D` days, it can sustain `A[i] / D` people (integer division) for those `D` days. The goal is to find the maximum number of days `D` for which it's possible to feed all `M` people using the available food resources.

## Intuition & Mathematical Observation

The core of this problem lies in a monotonic property that allows us to use binary search.

1.  **Monotonicity**: Consider a function `check(D)` which returns `true` if it's possible to feed `M` people for `D` days, and `false` otherwise.
    *   If `M` people can be fed for `D` days, it means the total number of people that can be sustained for `D` days (sum of `A[i] / D` for all `i`) is greater than or equal to `M`.
    *   Now, if we consider `D' < D` days, then for each food type `i`, `A[i] / D'` will be greater than or equal to `A[i] / D` (since `D'` is a smaller divisor).
    *   Therefore, the total number of people that can be sustained for `D'` days will be greater than or equal to the total for `D` days.
    *   This implies that if `check(D)` is `true`, then `check(D')` for any `D' < D` must also be `true`. This monotonic property (the `check` function is `true` for smaller `D` and `false` for larger `D`) is ideal for binary search. We are looking for the largest `D` for which `check(D)` is `true`.

2.  **`check(D)` Function Implementation**: To implement `check(D)`:
    *   Initialize `total_fed_people = 0`.
    *   For each food type `A[i]`:
        *   Calculate how many people this food type can feed for `D` days: `A[i] / D`.
        *   Add this to `total_fed_people`.
        *   (Optimization) If `total_fed_people` already reaches `M`, we can immediately return `true` as we've found enough food.
    *   After iterating through all food types, return `true` if `total_fed_people >= M`, otherwise return `false`.

3.  **Binary Search Range**:
    *   **Lower Bound (`low`)**: The minimum possible number of days is 0. However, our binary search will typically start from `1`. If `check(1)` is false, our `ans` variable (initialized to 0) will correctly represent 0 days. So, `low = 1` is appropriate.
    *   **Upper Bound (`high`)**: What's the maximum possible number of days? If we have `A[i]` units of food, and `M=1` person, that person can be fed for at most `A[i]` days using that food type. The maximum value of `A[i]` is `10^4`. So, `10^4` is a reasonable upper bound. Setting `high = 10001` (or `max(A_i) + 1`) is a safe choice to cover all possibilities.

The binary search will then iteratively narrow down the range `[low, high]`. If `check(mid)` is true, it means `mid` days are possible, so we store `mid` as a potential answer and try for more days (`low = mid + 1`). If `check(mid)` is false, `mid` days are not possible, so we need to reduce the number of days (`high = mid - 1`).

## Complexity Analysis

-   **Time Complexity**: The binary search performs `log(high - low)` iterations. In this problem, `high` is approximately `10^4`. So, `log(10^4)` is roughly `14` (since `2^13 = 8192`, `2^14 = 16384`). Inside each iteration, the `check` function iterates through all `N` food types. `N` can be up to `10^5`.
    Therefore, the total time complexity is $O(N \cdot \log(\max(A_i)))$.
    Given `N = 10^5` and `log(10^4) \approx 14`, this results in approximately `10^5 * 14 = 1.4 \times 10^6` operations, which is well within typical time limits.

-   **Space Complexity**: We store the input array `A` of size `N`. No other significant data structures are used that scale with `N` or `M`.
    Therefore, the space complexity is $O(N)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Required header

// Required namespace
using namespace std;

// Function to check if it's possible to sustain M people for D days
bool check(long long D, int M, const vector<int>& A) {
    // D will always be >= 1 due to binary search range [1, high].
    // If D were 0, it means 0 days, which is always possible (no food needed).
    // Our binary search range [1, MAX_DAYS] and ans=0 handles this:
    // if check(1) is false, ans remains 0, which is the correct output for 0 days.
    
    long long total_fed_people = 0;
    for (int units : A) {
        total_fed_people += units / D; // Integer division automatically floors
        // Optimization: if we already have enough people, we can stop early
        if (total_fed_people >= M) {
            return true;
        }
    }
    return total_fed_people >= M;
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; // Number of food types
    int M; // Number of people
    cin >> N >> M;

    vector<int> A(N); // Units of each food type
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    long long low = 1;
    // Max possible days is max(A_i). Since max(A_i) is 10^4,
    // high can be set to 10000. Using 10001 is also fine, as it covers 10000.
    long long high = 10001; 
    long long ans = 0; // Stores the maximum D for which check(D) is true

    while (low <= high) {
        long long mid = low + (high - low) / 2;
        
        if (check(mid, M, A)) {
            ans = mid;       // It's possible for 'mid' days, so this is a potential answer.
            low = mid + 1;   // Try to achieve more days.
        } else {
            high = mid - 1;  // Not possible for 'mid' days, need to reduce days.
        }
    }

    cout << ans << "\n";

    return 0;
}
```