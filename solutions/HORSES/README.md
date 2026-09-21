# [Racing Horses (HORSES)](https://www.codechef.com/problems/HORSES)
- **Difficulty Rating**: 1231
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to find the minimum possible difference between the skill levels of any two horses from a given set of `N` horses. We are provided with `N` skill levels, $S_1, S_2, \dots, S_N$. We need to output the smallest value of $|S_i - S_j|$ for any $i \neq j$. This process needs to be repeated for `T` test cases.

## Intuition & Mathematical Observation

A naive approach would be to consider every possible pair of horses, calculate the absolute difference in their skill levels, and keep track of the minimum difference found. This would involve checking $N \times (N-1) / 2$ pairs, leading to an $O(N^2)$ time complexity. Given that `N` can be up to $10^5$, an $O(N^2)$ solution would be too slow ($10^{10}$ operations).

The key observation for problems involving finding the minimum difference between any two elements in a set is that **if the set of numbers is sorted, the minimum difference between any two elements must occur between adjacent elements.**

Let's prove this:
Suppose we have a sorted array of skill levels: $S_1 \le S_2 \le \dots \le S_N$.
Consider any two non-adjacent elements $S_i$ and $S_k$ such that $i < k-1$. This implies there is at least one element $S_j$ between them, i.e., $i < j < k$.
Since the array is sorted, we have $S_i \le S_j \le S_k$.
The difference between $S_i$ and $S_k$ is $S_k - S_i$.
We can express this difference as the sum of two adjacent differences: $(S_k - S_j) + (S_j - S_i)$.
Since $S_k - S_j \ge 0$ and $S_j - S_i \ge 0$ (because the array is sorted), it follows that:
$S_k - S_i \ge S_k - S_j$
$S_k - S_i \ge S_j - S_i$
This means the difference between any two non-adjacent elements ($S_i, S_k$) is always greater than or equal to the difference between at least one of the adjacent pairs that lie between them ($S_j, S_k$) or ($S_i, S_j$). Therefore, the minimum possible difference *must* be found between adjacent elements in the sorted array.

Based on this observation, the optimal strategy is:
1. Read all `N` skill levels into an array or vector.
2. Sort the array of skill levels in ascending order.
3. Initialize a variable `min_diff` to a very large value (e.g., `INT_MAX`).
4. Iterate through the sorted array from the first element up to the second-to-last element. For each element `S[i]`, calculate the difference with its adjacent element `S[i+1]`.
5. Update `min_diff` with the minimum of its current value and the newly calculated difference `S[i+1] - S[i]`.
6. After iterating through all adjacent pairs, `min_diff` will hold the smallest difference. Output this value.

## Complexity Analysis

-   **Time Complexity**:
    *   Reading `N` skill levels: $O(N)$
    *   Sorting the `N` skill levels: $O(N \log N)$ (using `std::sort`, which is typically an IntroSort implementation).
    *   Iterating through the sorted array to find the minimum adjacent difference: $O(N)$
    *   For each test case, the dominant operation is sorting. Thus, the time complexity per test case is $O(N \log N)$.
    *   Since there are `T` test cases, the overall time complexity is $O(T \cdot N \log N)$.

-   **Space Complexity**:
    *   Storing `N` skill levels in a `std::vector`: $O(N)$
    *   `std::sort` typically uses $O(\log N)$ auxiliary space for its recursive calls (e.g., for QuickSort part) or $O(1)$ for in-place algorithms like HeapSort. In competitive programming contexts, $O(N)$ is a safe upper bound for the space used by `std::sort` if it needs to create temporary copies or use auxiliary arrays.
    *   Therefore, the total space complexity is $O(N)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes iostream, vector, algorithm, climits etc.

using namespace std; // Use standard namespace for convenience

// Function to solve a single test case
void solve() {
    int N;
    cin >> N; // Read the number of horses

    // Create a vector to store the skill levels of the horses
    vector<int> S(N);
    for (int i = 0; i < N; ++i) {
        cin >> S[i]; // Read each horse's skill
    }

    // Sort the skill levels in ascending order.
    // This is the key step for an efficient solution.
    // After sorting, the minimum difference between any two skills
    // must be found between adjacent elements.
    sort(S.begin(), S.end());

    // Initialize min_diff with a very large value.
    // INT_MAX is the maximum value an 'int' can hold, ensuring any valid
    // difference will be smaller.
    int min_diff = INT_MAX;

    // Iterate through the sorted array and find the minimum difference
    // between adjacent elements.
    // We only need to go up to N-1 because we access S[i+1].
    for (int i = 0; i < N - 1; ++i) {
        // Calculate the difference between the current element and the next.
        // Since the array is sorted, S[i+1] will always be >= S[i],
        // so the difference S[i+1] - S[i] is non-negative.
        min_diff = min(min_diff, S[i+1] - S[i]);
    }

    // Output the minimum difference found for the current test case.
    cout << min_diff << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output operations.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cout from flushing before cin reads input.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases

    // Loop through each test case
    while (T--) {
        solve(); // Call the solve function for the current test case
    }

    return 0; // Indicate successful program execution
}
```