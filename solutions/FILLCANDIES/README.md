# [Fill Candies (FILLCANDIES)](https://www.codechef.com/problems/FILLCANDIES)
- **Difficulty Rating**: 681
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to calculate the minimum number of bags required to store a given number of candies. We are provided with:
1.  `N`: The total number of candies we have.
2.  `K`: The number of pockets in each bag.
3.  `M`: The maximum number of candies that can be stored in a single pocket.

We need to find the smallest integer number of bags that can accommodate all `N` candies. This needs to be done for multiple test cases.

## Intuition & Mathematical Observation

1.  **Capacity of a single bag**: Each bag has `K` pockets, and each pocket can hold `M` candies. Therefore, a single bag can hold a total of `K * M` candies. Let's call this `capacity_per_bag`.

2.  **Total candies to store**: We have `N` candies that need to be stored.

3.  **Minimum bags required**: To find the minimum number of bags, we need to divide the total candies (`N`) by the capacity of one bag (`capacity_per_bag`). Since we must store *all* `N` candies, if `N` is not perfectly divisible by `capacity_per_bag`, we will need an additional bag for any remaining candies. This is a classic "ceiling division" scenario.

4.  **Ceiling Division**: For positive integers `A` and `B`, the ceiling of `A/B` (i.e., `ceil(A/B)`) can be calculated using integer arithmetic as `(A + B - 1) / B`.
    *   For example, if `N = 10` candies and `capacity_per_bag = 3`:
        ` (10 + 3 - 1) / 3 = 12 / 3 = 4`. We need 4 bags (3 bags for 9 candies, 1 more for the last candy).
    *   If `N = 9` candies and `capacity_per_bag = 3`:
        ` (9 + 3 - 1) / 3 = 11 / 3 = 3`. We need 3 bags.

Applying this formula, `min_bags = (N + capacity_per_bag - 1) / capacity_per_bag`.

## Complexity Analysis

-   **Time Complexity**: $O(T)$
    For each test case, the solution performs a fixed number of arithmetic operations (multiplication, addition, division). These operations take constant time. Since there are `T` test cases, the total time complexity is directly proportional to `T`.

-   **Space Complexity**: $O(1)$
    The solution uses a few integer variables (`T`, `N`, `K`, `M`, `capacity_per_bag`, `min_bags`) to store input and intermediate results. The amount of memory used does not depend on the magnitude of `N`, `K`, or `M`, but rather on the fixed number of variables. Thus, the space complexity is constant.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes most standard libraries, as requested

// Using namespace std; is common in competitive programming
// and explicitly requested by the problem instructions.
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a standard practice in competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases

    while (T--) { // Loop T times, decrementing T each iteration
        int N, K, M;
        cin >> N >> K >> M; // Read N, K, M for the current test case

        // Calculate the total capacity of candies a single bag can hold.
        // A bag has K pockets, and each pocket can hold M candies.
        // So, one bag can hold K * M candies.
        int capacity_per_bag = K * M;

        // To find the minimum number of bags, we need to divide the total
        // number of candies (N) by the capacity of one bag (capacity_per_bag).
        // Since we must put *every* candy, if there are any remaining candies
        // after filling whole bags, we need an additional bag for them.
        // This is equivalent to performing a ceiling division.
        // The formula for ceiling division (ceil(A/B)) using integer arithmetic
        // for positive A and B is (A + B - 1) / B.
        int min_bags = (N + capacity_per_bag - 1) / capacity_per_bag;

        // Print the calculated minimum number of bags, followed by a newline.
        cout << min_bags << "\n";
    }

    return 0; // Indicate successful execution
}
```