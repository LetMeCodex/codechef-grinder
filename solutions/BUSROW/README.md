# [Bus Rows (BUSROW)](https://www.codechef.com/problems/BUSROW)
- **Difficulty Rating**: 727
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem describes a bus with `N` rows, and each row has `M` seats. The seats are numbered sequentially starting from 1. Seats `1` to `M` are in row 1, seats `M+1` to `2M` are in row 2, and so on. You are assigned a specific seat `X`.

You can board the bus from two ends:
1.  **From the front**: You start at row 1 and walk towards your assigned row. If your seat is in row `R`, you walk through rows `1, 2, ..., R`. The number of rows walked is `R`.
2.  **From the back**: You start at row `N` and walk towards your assigned row. If your seat is in row `R`, you walk through rows `N, N-1, ..., R`. The number of rows walked is `N - R + 1`.

The task is to determine the minimum number of rows you need to walk through to reach your seat `X`.

## Intuition & Mathematical Observation

The core of this problem is to first identify which row your seat `X` is located in, and then calculate the distance from both ends to that row.

1.  **Determine the target row for seat `X`**:
    *   Seats `1` to `M` are in row 1.
    *   Seats `M+1` to `2M` are in row 2.
    *   In general, seats `(k-1)M + 1` to `kM` are in row `k`.
    *   To find the row `k` for a given seat `X`, we can use integer division. If `X` is 1-indexed, we can convert it to 0-indexed by `X-1`. Then, `(X-1) / M` gives us the 0-indexed row number. Adding 1 converts it back to 1-indexed.
    *   So, `target_row = (X - 1) / M + 1`.
        *   Example: `X=1, M=5` -> `(1-1)/5 + 1 = 0 + 1 = 1`.
        *   Example: `X=5, M=5` -> `(5-1)/5 + 1 = 0 + 1 = 1`.
        *   Example: `X=6, M=5` -> `(6-1)/5 + 1 = 1 + 1 = 2`.

2.  **Calculate rows walked from the front**:
    *   If your seat is in `target_row`, and you board from the front (row 1), you pass through rows `1, 2, ..., target_row`.
    *   The number of rows walked is simply `target_row`.

3.  **Calculate rows walked from the back**:
    *   If your seat is in `target_row`, and you board from the back (row `N`), you pass through rows `N, N-1, ..., target_row`.
    *   The number of rows walked can be calculated as `N - target_row + 1`.
        *   Example: `N=10, target_row=10` -> `10 - 10 + 1 = 1` (only row 10).
        *   Example: `N=10, target_row=1` -> `10 - 1 + 1 = 10` (rows 10 down to 1).
        *   Example: `N=10, target_row=5` -> `10 - 5 + 1 = 6` (rows 10, 9, 8, 7, 6, 5).

4.  **Find the minimum**:
    *   The final answer is the minimum of the rows walked from the front and the rows walked from the back: `min(rows_from_front, rows_from_back)`.

## Complexity Analysis

-   **Time Complexity**: $O(T)$
    *   For each test case, we perform a few constant-time arithmetic operations (division, addition, subtraction) and a `min` operation. These operations take constant time, $O(1)$.
    *   Since there are `T` test cases, the total time complexity is proportional to the number of test cases, $O(T)$.

-   **Space Complexity**: $O(1)$
    *   We only use a fixed number of integer variables (`T`, `N`, `M`, `X`, `target_row`, `rows_from_front`, `rows_from_back`, `min_rows_walked`) to store input and intermediate results.
    *   The memory usage does not depend on the magnitude of `N`, `M`, or `X`. Thus, the space complexity is constant.

## Solution Code

```cpp
#include <iostream> // Required for cin, cout
#include <algorithm> // Required for std::min

// It's common in competitive programming to include <bits/stdc++.h>
// which includes most standard libraries. For this specific problem,
// iostream and algorithm are sufficient.

// Using namespace std; is also common in competitive programming
// to avoid typing std:: repeatedly.
using namespace std;

int main() {
    // Fast I/O setup to speed up input and output operations.
    // This is generally good practice in competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Variable to store the number of test cases
    cin >> T; // Read the number of test cases

    // Loop through each test case
    while (T--) {
        int N, M, X; // N: number of rows, M: seats per row, X: your seat number
        cin >> N >> M >> X; // Read N, M, and X for the current test case

        // Step 1: Determine the row number where seat X is located.
        // The formula (X - 1) / M + 1 correctly calculates the 1-indexed row.
        int target_row = (X - 1) / M + 1;

        // Step 2: Calculate the number of rows walked if boarding from the front.
        // To reach target_row from the front, you walk through rows 1, 2, ..., target_row.
        // The count is simply target_row.
        int rows_from_front = target_row;

        // Step 3: Calculate the number of rows walked if boarding from the back.
        // To reach target_row from the back (starting after row N),
        // you walk through rows N, N-1, ..., target_row.
        // The count is N - target_row + 1.
        int rows_from_back = N - target_row + 1;

        // Step 4: Find the minimum of the two options.
        // std::min is used to get the smaller of the two values.
        int min_rows_walked = min(rows_from_front, rows_from_back);

        // Output the minimum number of rows walked for the current test case,
        // followed by a newline character.
        cout << min_rows_walked << "\n";
    }

    return 0; // Indicate successful program execution
}
```