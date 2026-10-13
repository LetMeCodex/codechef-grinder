# [Moderate Temperatures (MODTEMP)](https://www.codechef.com/problems/MODTEMP)
- **Difficulty Rating**: 597
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to count the number of "liked" days based on their temperatures. We are given a list of `N` temperatures, one for each day. A day is considered "liked" if its temperature is strictly greater than the minimum temperature recorded across all `N` days AND strictly less than the maximum temperature recorded across all `N` days. In simpler terms, a day is liked if its temperature is neither the absolute minimum nor the absolute maximum temperature observed.

## Intuition & Mathematical Observation

The core idea to solve this problem is straightforward:
1.  **Identify Extremes**: To determine which temperatures are "neither minimum nor maximum," we first need to find the overall minimum and maximum temperatures present in the given list of `N` days.
2.  **Iterate and Count**: Once we have the global minimum (`min_temp`) and maximum (`max_temp`), we can iterate through the list of temperatures again. For each day's temperature `A[i]`, we check if it is different from `min_temp` AND different from `max_temp`.
3.  **Increment Counter**: If both conditions are true (i.e., `A[i] != min_temp` and `A[i] != max_temp`), then that day is "liked," and we increment a counter.
4.  **Output**: Finally, the total count of "liked" days is the answer.

**Example:**
Let temperatures be `[10, 20, 5, 30, 20]`.
1.  **Identify Extremes**:
    *   Minimum temperature (`min_temp`) = 5
    *   Maximum temperature (`max_temp`) = 30
2.  **Iterate and Count**:
    *   Day 1: `A[0] = 10`. `10 != 5` and `10 != 30`. Liked. Count = 1.
    *   Day 2: `A[1] = 20`. `20 != 5` and `20 != 30`. Liked. Count = 2.
    *   Day 3: `A[2] = 5`. `5 == min_temp`. Not liked. Count = 2.
    *   Day 4: `A[3] = 30`. `30 == max_temp`. Not liked. Count = 2.
    *   Day 5: `A[4] = 20`. `20 != 5` and `20 != 30`. Liked. Count = 3.
3.  **Output**: 3

This approach correctly handles cases where all temperatures are the same (e.g., `[5, 5, 5]`, `min_temp=5`, `max_temp=5`, liked days = 0) or where only two distinct temperatures exist (e.g., `[10, 20, 10]`, `min_temp=10`, `max_temp=20`, liked days = 0).

## Complexity Analysis

*   **Time Complexity**: $O(N)$
    *   Reading `N` integers into a vector takes $O(N)$ time.
    *   Finding the minimum element using `std::min_element` takes $O(N)$ time.
    *   Finding the maximum element using `std::max_element` takes $O(N)$ time.
    *   Iterating through the vector once to count liked days takes $O(N)$ time.
    *   The total time complexity for a single test case is $O(N) + O(N) + O(N) + O(N) = O(N)$.
    *   Since there are `T` test cases, the overall time complexity is $O(T \cdot N)$.

*   **Space Complexity**: $O(N)$
    *   We use a `std::vector<int> A` to store the `N` temperatures, which requires $O(N)$ space.
    *   All other variables (`N`, `min_temp`, `max_temp`, `liked_days_count`, loop counter) use a constant amount of space, $O(1)$.
    *   Therefore, the total space complexity is $O(N)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries, including iostream, vector, algorithm

using namespace std; // As requested by the problem statement

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // Find the minimum and maximum temperatures among all N days.
    // std::min_element and std::max_element return iterators to the elements.
    // Dereference them to get the actual values.
    int min_temp = *min_element(A.begin(), A.end());
    int max_temp = *max_element(A.begin(), A.end());

    int liked_days_count = 0;
    // Iterate through the temperatures to count days that are neither the minimum nor the maximum.
    for (int i = 0; i < N; ++i) {
        if (A[i] != min_temp && A[i] != max_temp) {
            liked_days_count++;
        }
    }
    cout << liked_days_count << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common competitive programming optimization.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Number of test cases
    cin >> T;
    while (T--) { // Loop T times for each test case
        solve();
    }

    return 0;
}
```