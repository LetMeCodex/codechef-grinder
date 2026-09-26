# [How much Scholarship (ZCOSCH)](https://www.codechef.com/problems/ZCOSCH)
- **Difficulty Rating**: 1012
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to calculate the scholarship percentage a student receives based on their rank `R` in an examination. The scholarship rules are as follows:
*   If the rank `R` is between 1 and 50 (inclusive), the student receives a 100% scholarship.
*   If the rank `R` is between 51 and 100 (inclusive), the student receives a 50% scholarship.
*   If the rank `R` is greater than 100, the student receives a 0% scholarship.

We need to read the rank `R` as input and print the corresponding scholarship percentage.

## Intuition & Mathematical Observation

This problem is a straightforward application of conditional logic. There are no complex mathematical formulas or advanced algorithms involved. The core idea is to check which of the given rank ranges the input `R` falls into and then print the corresponding scholarship percentage.

We can achieve this using a series of `if-else if-else` statements:
1.  First, we check if `R` is in the range `[1, 50]`. If it is, the scholarship is 100%.
2.  If `R` is not in the first range, we then check if it's in the range `[51, 100]`. If it is, the scholarship is 50%.
3.  If `R` does not satisfy either of the above conditions, it must be greater than 100 (as per the problem's implied constraints for ranks), in which case the scholarship is 0%.

This approach directly translates the problem's rules into code, ensuring that each rank `R` is correctly categorized into one of the three scholarship tiers.

## Complexity Analysis

-   **Time Complexity**: $O(1)$
    *   The program performs a fixed number of operations regardless of the input rank `R`. It reads one integer, performs at most two comparisons (`if` and `else if`), and prints one integer. All these operations take constant time. Therefore, the time complexity is constant.

-   **Space Complexity**: $O(1)$
    *   The program uses a constant amount of extra space. It only declares a single integer variable `R` to store the input. This space requirement does not grow with the value of the input `R`.

## Solution Code

```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
    // Enable fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int R; // Declare an integer variable to store the rank
    cin >> R; // Read the rank from standard input

    // Apply the scholarship rules based on the rank R
    if (R >= 1 && R <= 50) {
        // Ranks from 1 to 50 get 100% scholarship
        cout << 100 << "\n";
    } else if (R >= 51 && R <= 100) {
        // Ranks from 51 to 100 get 50% scholarship
        cout << 50 << "\n";
    } else {
        // Ranks greater than 100 get 0% scholarship
        cout << 0 << "\n";
    }

    return 0; // Indicate successful program termination
}
```