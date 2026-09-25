# [Chef and Remissness (REMISS)](https://www.codechef.com/problems/REMISS)
- **Difficulty Rating**: 928
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef has two guards, G1 and G2. Chef enters his house `X` times. Guard 1 counts `A` entries, and Guard 2 counts `B` entries. The problem states a crucial condition: "At least one of them remains awake and counts who enters." This implies that every time Chef enters, at least one guard records the entry. We need to find the minimum and maximum possible values for `X`, the total number of times Chef entered the house.

## Intuition & Mathematical Observation

Let `X` be the total number of times Chef entered the house.
Let `A` be the count reported by Guard 1.
Let `B` be the count reported by Guard 2.

The core constraint is: "At least one of them remains awake and counts who enters." This means every entry Chef makes is recorded by at least one guard.

### Minimum Possible Entries (`min_X`)

To find the minimum possible value for `X`, we want to maximize the overlap between the entries counted by Guard 1 and Guard 2.

1.  **From Guard 1's perspective**: Guard 1 counted `A` entries. This means Chef *must* have entered at least `A` times. So, `X >= A`.
2.  **From Guard 2's perspective**: Guard 2 counted `B` entries. This means Chef *must* have entered at least `B` times. So, `X >= B`.

Combining these two, `X` must be at least the maximum of `A` and `B`. That is, `X >= max(A, B)`.

Can `X` actually be `max(A, B)`? Yes.
Consider an example: `A = 5` and `B = 3`. `max(A, B) = 5`.
If Chef enters 5 times, and Guard 1 counts all 5 entries. Guard 2 could have been awake for 3 of those 5 entries (and asleep for the other 2 entries that Guard 1 saw). In this scenario, Guard 1 reports 5, Guard 2 reports 3, and Chef entered 5 times. This satisfies all conditions, including "at least one guard is awake" for each entry.
Thus, the minimum number of entries is `min_X = max(A, B)`.

### Maximum Possible Entries (`max_X`)

To find the maximum possible value for `X`, we want to minimize the overlap between the entries counted by Guard 1 and Guard 2. In other words, we want to maximize the number of *unique* entries.

The constraint "At least one guard is always awake and counts who enters" means that for every entry, either Guard 1 sees it, or Guard 2 sees it, or both see it.

To maximize `X`, we assume that the entries counted by Guard 1 are completely distinct from the entries counted by Guard 2.
1.  **Guard 1's entries**: There are `A` entries that Guard 1 counted. For these `A` entries, Guard 1 was awake. Guard 2 could have been asleep for all of them.
2.  **Guard 2's entries**: There are `B` entries that Guard 2 counted. For these `B` entries, Guard 2 was awake. Guard 1 could have been asleep for all of them.

If these two sets of entries are entirely separate, then the total number of unique entries `X` would simply be the sum of the counts from both guards.
For example, if `A = 5` and `B = 3`.
Chef enters 5 times, and only Guard 1 sees these 5 entries (Guard 2 is asleep).
Chef then enters 3 *different* times, and only Guard 2 sees these 3 entries (Guard 1 is asleep).
The total number of entries `X` would be `5 + 3 = 8`. This scenario is valid because for every entry, at least one guard (the one who counted it) was awake.
Thus, the maximum number of entries is `max_X = A + B`.

## Complexity Analysis
-   **Time Complexity**: The solution processes `t` test cases. For each test case, it performs a constant number of operations: reading two integers, calculating `max(a, b)`, calculating `a + b`, and printing two integers. All these operations take $O(1)$ time. Therefore, the total time complexity is $O(t)$.
-   **Space Complexity**: The solution uses a few variables (`t`, `a`, `b`, `min_entries`, `max_entries`) to store input and intermediate results. The memory usage for these variables is constant and does not depend on the input values (other than the fixed size of integer types). Therefore, the space complexity is $O(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; // Number of test cases
    cin >> t;
    while (t--) {
        long long a, b; // Counts from Guard 1 and Guard 2
        cin >> a >> b;

        // Minimum entries:
        // At least one guard is always awake.
        // If Chef entered X times, guard 1 counted A times and guard 2 counted B times.
        // The total number of entries must be at least the maximum of the two counts,
        // because the guard who counted more must have seen all those entries.
        // Example: If G1 counted 5 and G2 counted 3, Chef must have entered at least 5 times.
        // It's possible G1 saw all 5, and G2 saw 3 of those same 5 entries.
        long long min_entries = max(a, b);

        // Maximum entries:
        // The guards never fall asleep at the same time.
        // This means that for any entry, at least one guard counted it.
        // The maximum number of entries occurs when there is no overlap in the entries
        // counted by the two guards. In this scenario, the total number of entries
        // is simply the sum of the counts from both guards.
        // Example: If G1 counted 5 and G2 counted 3, and these were 5 distinct entries
        // seen only by G1, and 3 distinct entries seen only by G2.
        // Total entries = 5 + 3 = 8.
        long long max_entries = a + b;

        cout << min_entries << " " << max_entries << "\n";
    }
    return 0;
}
```