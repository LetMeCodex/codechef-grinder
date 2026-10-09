# [Count the Holidays (SUNDAY)](https://www.codechef.com/problems/SUNDAY)
- **Difficulty Rating**: 907
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to calculate the total number of unique holidays in a month that has exactly 30 days. We are given that Day 1 of this month is a Monday. The holidays include:
1.  All Saturdays.
2.  All Sundays.
3.  `N` specific festival days, whose dates are provided.

We need to output the total count of unique days that are holidays.

## Intuition & Mathematical Observation

The core idea is to keep track of which days are holidays to avoid double-counting. Since we are interested in unique days, a boolean array (or `std::vector<bool>` in C++) is an ideal data structure for this.

1.  **Representing Days**: The month has 30 days. We can use a boolean vector `is_holiday` of size 31 (to allow 1-based indexing for days 1 to 30). Initialize all entries to `false`.
2.  **Marking Weekends**:
    *   Day 1 is a Monday.
    *   We can determine the day of the week for any `day` using modular arithmetic. If we map Monday to 0, Tuesday to 1, ..., Sunday to 6, then the day of the week index for `day` is `(day - 1) % 7`.
    *   Saturdays correspond to index 5, and Sundays correspond to index 6.
    *   We iterate from `day = 1` to `30`. For each day, calculate its day of the week. If it's a Saturday or Sunday, mark `is_holiday[day] = true`.
3.  **Marking Festival Days**:
    *   Read the `N` festival days. For each `festival_day`, mark `is_holiday[festival_day] = true`. If a festival day happens to fall on a Saturday or Sunday, it will already be marked `true`, and marking it again has no effect, correctly ensuring unique counting.
4.  **Counting Total Holidays**:
    *   Finally, iterate from `day = 1` to `30` through the `is_holiday` vector. Count how many entries are `true`. This count will be our answer.

This approach ensures that each unique holiday (whether a weekend, a festival, or both) is counted exactly once.

## Complexity Analysis

Let `N` be the number of festival days and `T` be the number of test cases.

-   **Time Complexity**:
    *   Initializing the `is_holiday` vector of size 31 takes $O(1)$ time.
    *   The loop to mark all Saturdays and Sundays iterates 30 times. This takes $O(1)$ time.
    *   The loop to read `N` festival days and mark them takes $O(N)$ time.
    *   The loop to count the total unique holidays iterates 30 times. This takes $O(1)$ time.
    *   Therefore, for a single test case, the total time complexity is $O(1 + 1 + N + 1) = O(N)$.
    *   Since there are `T` test cases, the overall time complexity is $O(T \cdot N)$.
    *   Given constraints ($T \le 100$, $N \le 30$), the maximum operations would be around $100 \times 30 = 3000$, which is very efficient.

-   **Space Complexity**:
    *   The `is_holiday` vector stores 31 boolean values. This requires $O(1)$ space (as its size is constant and independent of `N`).
    *   All other variables use constant space.
    *   Therefore, the total space complexity is $O(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries

// Using namespace std; as requested by problem instructions
using namespace std;

void solve() {
    int N;
    cin >> N;

    // Use a boolean vector to mark holidays.
    // Size 31 to use 1-based indexing for days 1 to 30.
    vector<bool> is_holiday(31, false);

    // Mark all Saturdays and Sundays as holidays.
    // Day 1 is Monday.
    // The day of the week can be determined by (day - 1) % 7.
    // 0: Monday
    // 1: Tuesday
    // 2: Wednesday
    // 3: Thursday
    // 4: Friday
    // 5: Saturday
    // 6: Sunday
    for (int day = 1; day <= 30; ++day) {
        int day_of_week_idx = (day - 1) % 7;
        if (day_of_week_idx == 5 || day_of_week_idx == 6) { // 5 is Saturday, 6 is Sunday
            is_holiday[day] = true;
        }
    }

    // Mark festival days as holidays.
    for (int i = 0; i < N; ++i) {
        int festival_day;
        cin >> festival_day;
        is_holiday[festival_day] = true;
    }

    // Count total unique holidays.
    int total_holidays = 0;
    for (int day = 1; day <= 30; ++day) {
        if (is_holiday[day]) {
            total_holidays++;
        }
    }

    cout << total_holidays << "\n";
}

int main() {
    // Fast I/O as requested
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
```