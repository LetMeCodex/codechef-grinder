# [Laddu (LADDU)](https://www.codechef.com/problems/LADDU)
- **Difficulty Rating**: 1241
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem requires us to calculate the total "Laddus" (a virtual currency) accumulated by a user based on a series of activities. After summing up all Laddus, we need to determine how many free Amazon vouchers the user can redeem. The redemption rate for vouchers depends on the user's origin:
- If the user is of "INDIAN" origin, 200 Laddus are required to redeem one voucher per month.
- If the user is of "FOREIGNER" origin, 400 Laddus are required to redeem one voucher per month.

The Laddus awarded for different activities are:
1.  `CONTEST_WON`: 300 Laddus + a bonus. The bonus is calculated as `max(0, 20 - rank)`, where `rank` is the user's rank in the contest.
2.  `TOP_CONTRIBUTOR`: 300 Laddus.
3.  `BUG_FOUND`: `severity` Laddus, where `severity` is an integer value provided with the activity.
4.  `CONTEST_HOSTED`: 50 Laddus.

For each test case, the final output should be the total Laddus earned divided by the respective monthly redemption limit, representing the number of months for which the user can redeem vouchers.

## Intuition & Mathematical Observation
The problem is a straightforward simulation task. We need to process each activity one by one and accumulate the Laddus earned according to the given rules.

1.  **Accumulation**: We'll maintain a variable, `total_laddus`, initialized to zero. For each activity read from the input, we'll determine its type and add the corresponding Laddus to `total_laddus`.
2.  **Data Type for Laddus**: The number of activities can be up to 1000, and each activity can award a significant amount of Laddus (e.g., 300 + bonus, or a high severity bug). In the worst case, `total_laddus` could exceed the maximum value of a standard `int` (typically $2 \times 10^9$). To prevent integer overflow, `total_laddus` should be declared as a `long long`.
3.  **Conditional Logic**:
    *   We use `if-else if` statements to check the `activity_type` string and apply the correct Laddu calculation.
    *   For `CONTEST_WON`, the bonus calculation `max(0, 20 - rank)` ensures that the bonus is never negative.
    *   The `redemption_limit` is determined by comparing the `origin` string ("INDIAN" or "FOREIGNER"). This can be handled with a simple ternary operator or an `if-else` statement.
4.  **Final Calculation**: After processing all activities, the total number of months for which vouchers can be redeemed is simply `total_laddus / redemption_limit`. Since the problem asks for the number of months, integer division is appropriate, as partial months are not considered.

No complex algorithms, data structures, or advanced mathematical concepts are required; the solution is a direct implementation of the problem's rules.

## Complexity Analysis
-   **Time Complexity**:
    Let $T$ be the number of test cases and $N$ be the number of activities for a given test case.
    1.  The program has an outer loop that runs $T$ times (for each test case).
    2.  Inside each test case, we first read `activities_count` and `origin`, which takes constant time.
    3.  Then, a loop iterates $N$ times, once for each activity.
    4.  Within this inner loop, reading `activity_type` (a string) and potentially an integer (`rank` or `severity`) takes constant time, as the maximum length of these strings and the range of integers are small and bounded.
    5.  String comparisons and arithmetic operations are also constant time.
    Therefore, for each test case, the time complexity is $O(N)$.
    The total time complexity across all test cases is $O(T \times N)$.
    Given the constraints ($T \le 100$, $N \le 1000$), the maximum number of operations would be approximately $100 \times 1000 = 10^5$, which is very efficient and well within typical time limits for competitive programming problems.

-   **Space Complexity**:
    The program uses a fixed number of variables: `t`, `activities_count`, `origin`, `total_laddus`, `redemption_limit`, `activity_type`, `rank`, and `severity`. The memory occupied by these variables is constant, regardless of the input size (beyond the fixed maximum length of strings like `origin` and `activity_type`).
    Thus, the space complexity is $O(1)$ (constant space).

## Solution Code
```cpp
#include <iostream> // For input/output operations (cin, cout)
#include <string>   // For using std::string
#include <vector>   // Not strictly needed for this solution, but often included
#include <algorithm> // For std::max

using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t; // Read the number of test cases
    while (t--) { // Loop through each test case
        int activities_count;
        string origin;
        cin >> activities_count >> origin; // Read the number of activities and user's origin

        long long total_laddus = 0; // Initialize total Laddus. Use long long to prevent overflow.
        
        // Determine the monthly redemption limit based on the user's origin
        int redemption_limit = (origin == "INDIAN") ? 200 : 400;

        // Process each activity to accumulate Laddus
        for (int i = 0; i < activities_count; ++i) {
            string activity_type;
            cin >> activity_type; // Read the type of the current activity

            if (activity_type == "CONTEST_WON") {
                int rank;
                cin >> rank; // Read the rank achieved in the contest
                // Calculate bonus: max(0, 20 - rank). Bonus is 0 if rank is 20 or worse.
                long long bonus = max(0, 20 - rank);
                total_laddus += 300 + bonus; // Add base Laddus and bonus
            } else if (activity_type == "TOP_CONTRIBUTOR") {
                total_laddus += 300; // Add fixed Laddus for being a top contributor
            } else if (activity_type == "BUG_FOUND") {
                int severity;
                cin >> severity; // Read the severity of the bug found
                total_laddus += severity; // Add Laddus equal to the bug's severity
            } else if (activity_type == "CONTEST_HOSTED") {
                total_laddus += 50; // Add fixed Laddus for hosting a contest
            }
        }

        // Output the number of months for which vouchers can be redeemed.
        // This is total_laddus divided by the monthly redemption limit (integer division).
        cout << total_laddus / redemption_limit << "\n";
    }

    return 0; // Indicate successful execution
}
```