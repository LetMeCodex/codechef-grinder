# [Akash and Missing Class (CHFCLASS)](https://www.codechef.com/problems/CHFCLASS)
- **Difficulty Rating**: 931
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to calculate the number of Saturdays in a month that has `N` days. We are given that the month always starts on a Monday. We need to do this for several test cases.

## Intuition & Mathematical Observation

The key information is that the month starts on a Monday. A standard week consists of 7 days: Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday.

Let's list the days and their corresponding day numbers, starting from Monday as day 1:
1. Monday
2. Tuesday
3. Wednesday
4. Thursday
5. Friday
6. Saturday
7. Sunday

From this, we can see that the first Saturday occurs on day 6. Subsequent Saturdays will occur 7 days after the previous one. So, Saturdays fall on days 6, 13, 20, 27, and so on. These are days of the form `7k - 1` or `7k + 6` for `k >= 1` (if we consider `k` as the week number).

Let's analyze the number of Saturdays based on `N` days:

1.  **Full Weeks**: Every complete 7-day cycle (a full week) will contain exactly one Saturday. The number of full weeks in `N` days is `N / 7` (using integer division). So, `N / 7` Saturdays are guaranteed from these full weeks.

2.  **Remaining Days**: After accounting for full weeks, there are `N % 7` days remaining. These remaining days start from Monday. We need to check if any of these remaining days include a Saturday.
    *   If `N % 7` is 0, 1, 2, 3, 4, or 5: The remaining days (Monday up to Friday) do not include a Saturday. So, no additional Saturdays are counted.
    *   If `N % 7` is 6: The remaining days are Monday, Tuesday, Wednesday, Thursday, Friday, Saturday. This includes one additional Saturday.

Combining these observations:
*   If `N % 7 == 6`, the total number of Saturdays is `(N / 7) + 1`.
*   Otherwise (if `N % 7` is anything from 0 to 5), the total number of Saturdays is `N / 7`.

This logic can be concisely expressed using a single formula: `(N + 1) / 7` (integer division). Let's verify this:

Let `N = 7q + r`, where `q = N / 7` (integer division) and `r = N % 7`.

*   **Case 1: `r < 6` (i.e., `r` is 0, 1, 2, 3, 4, 5)**
    The formula becomes `(7q + r + 1) / 7`.
    Since `1 <= r + 1 <= 6`, `(r + 1) / 7` will evaluate to `0` in integer division.
    So, `(7q + r + 1) / 7 = q + 0 = q`. This matches `N / 7`.

*   **Case 2: `r = 6`**
    The formula becomes `(7q + 6 + 1) / 7 = (7q + 7) / 7`.
    This simplifies to `q + 1`. This matches `(N / 7) + 1`.

The formula `(N + 1) / 7` correctly covers both scenarios and provides an elegant solution.

**Examples:**
*   `N = 5` (Mon, Tue, Wed, Thu, Fri): `(5 + 1) / 7 = 6 / 7 = 0` Saturdays. Correct.
*   `N = 6` (Mon, Tue, Wed, Thu, Fri, Sat): `(6 + 1) / 7 = 7 / 7 = 1` Saturday. Correct.
*   `N = 7` (Mon ... Sun): `(7 + 1) / 7 = 8 / 7 = 1` Saturday. Correct.
*   `N = 13` (Mon ... Sat of 2nd week): `(13 + 1) / 7 = 14 / 7 = 2` Saturdays. Correct.

## Complexity Analysis

*   **Time Complexity**: For each test case, we perform a constant number of arithmetic operations (reading `N`, adding 1, dividing by 7, and printing the result). If there are `T` test cases, the total time complexity will be $O(T)$.
*   **Space Complexity**: We only use a few integer variables to store `T`, `N`, and the calculated number of Saturdays. This requires a constant amount of memory, so the space complexity is $O(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Include all standard libraries

// Use the standard namespace
using namespace std;

int main() {
    // Enable fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) {
        int N;
        cin >> N; // Read the number of days in the month

        // Calculate the number of Saturdays.
        // A week has 7 days, starting Monday. Saturday is the 6th day.
        // The formula (N + 1) / 7 correctly calculates the number of Saturdays.
        //
        // Let N = 7q + r, where q = N/7 (integer division) and r = N%7.
        //
        // If r < 6 (i.e., r is 0, 1, 2, 3, 4, 5):
        //   The N days contain 'q' full weeks, each with one Saturday.
        //   The remaining 'r' days (starting from Monday) do not include a Saturday.
        //   So, the total Saturdays should be 'q'.
        //   Formula: (N + 1) / 7 = (7q + r + 1) / 7 = q + (r + 1) / 7.
        //   Since 1 <= r + 1 <= 6, (r + 1) / 7 evaluates to 0 in integer division.
        //   Result: q + 0 = q. This is correct.
        //
        // If r = 6:
        //   The N days contain 'q' full weeks, plus 6 additional days (Monday to Saturday).
        //   This means there are 'q' Saturdays from the full weeks, and one more Saturday from the remaining 6 days.
        //   So, the total Saturdays should be 'q + 1'.
        //   Formula: (N + 1) / 7 = (7q + 6 + 1) / 7 = (7q + 7) / 7 = q + 1.
        //   Result: q + 1. This is correct.
        
        int Saturdays = (N + 1) / 7;
        
        cout << Saturdays << "\n"; // Output the result for the current test case
    }

    return 0;
}
```