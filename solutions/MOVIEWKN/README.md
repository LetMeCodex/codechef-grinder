# [Movie Weekend (MOVIEWKN)](https://www.codechef.com/problems/MOVIEWKN)
- **Difficulty Rating**: 1175
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to select the "best" movie from a list of `N` available movies. For each movie `i`, we are given its length `L_i` and its rating `R_i`. The criteria for determining the best movie are hierarchical:

1.  **Primary Criterion**: Maximize the product `L_i * R_i`.
2.  **Secondary Criterion (Tie-breaker)**: If multiple movies have the same maximum `L_i * R_i` product, choose the one with the maximum `R_i`.
3.  **Tertiary Criterion (Tie-breaker)**: If multiple movies still tie on both the primary and secondary criteria, choose the one with the smallest 1-based index.

We need to output the 1-based index of the chosen movie.

## Intuition & Mathematical Observation

The problem defines a clear set of priority rules for selecting the best movie. We need to iterate through all movies, keeping track of the "best" movie found so far according to these rules.

Let's maintain three variables to store information about the current best movie:
*   `max_product`: Stores the maximum `L * R` product encountered so far. Initialize it to `0`. Since `L_i` and `R_i` are positive, all products will be positive.
*   `max_rating_for_max_product`: Stores the rating `R` of the movie that achieved the `max_product`. This is essential for applying the secondary tie-breaking rule. Initialize it to `0`.
*   `best_index`: Stores the 1-based index of the movie currently considered "best". Initialize it to `-1` (or `1` if we assume at least one movie).

We can iterate through the movies from `i = 0` to `N-1` (using 0-based indexing for arrays). For each movie `i`:

1.  Calculate `current_product = L[i] * R[i]`.
2.  **Apply Primary Criterion**:
    *   If `current_product > max_product`: This movie is strictly better than the current best based on the primary rule. We update all our tracking variables:
        *   `max_product = current_product`
        *   `max_rating_for_max_product = R[i]`
        *   `best_index = i + 1` (converting to 1-based index).
3.  **Apply Secondary Criterion (if primary is a tie)**:
    *   Else if `current_product == max_product`: This means we have a tie on the primary criterion. Now, we apply the secondary rule: choose the one with the maximum `R`.
    *   If `R[i] > max_rating_for_max_product`: This movie is better than the current best based on the secondary rule. We update:
        *   `max_rating_for_max_product = R[i]`
        *   `best_index = i + 1`.
4.  **Apply Tertiary Criterion (if both primary and secondary are ties)**:
    *   Else if `R[i] == max_rating_for_max_product`: This implies `current_product == max_product` AND `R[i] == max_rating_for_max_product`. We have a tie on both primary and secondary criteria. The problem states to choose the one with the *smallest index*.
    *   Since we are iterating through the movies from `i = 0` upwards, `best_index` will naturally retain the smallest index among such ties. If we encounter a movie `j` later (`j > i`) that has the same `L*R` and `R` values as a previously chosen movie `i`, `best_index` will already hold `i+1`, which is smaller than `j+1`. Therefore, no explicit action is needed in this specific `else if` block; the `best_index` will correctly preserve the minimum index.

This iterative approach correctly applies all three rules to find the desired movie.

**Important Note on Data Types**: The problem constraints state `1 <= L_i, R_i <= 1000`. This means the maximum product `L_i * R_i` will be `1000 * 1000 = 10^6`. An `int` data type (which typically holds values up to `2 * 10^9`) is sufficient to store `L_i`, `R_i`, `current_product`, and `max_product` without overflow.

## Complexity Analysis

*   **Time Complexity**:
    *   Reading `N`: $O(1)$
    *   Reading `N` lengths into vector `L`: $O(N)$
    *   Reading `N` ratings into vector `R`: $O(N)$
    *   The main loop iterates `N` times. Inside the loop, we perform a constant number of operations (multiplication, comparisons, assignments). This part takes $O(N)$ time.
    *   Printing the result: $O(1)$
    *   Therefore, the total time complexity for a single test case is $O(N) + O(N) + O(N) = O(N)$.
    *   Given `T` test cases, the total time complexity is $O(T \cdot N)$. With `N` up to $10^5$ and `T` up to $10$, this is approximately $10 \cdot 10^5 = 10^6$ operations, which is well within typical time limits.

*   **Space Complexity**:
    *   The `L` vector stores `N` integers, requiring $O(N)$ space.
    *   The `R` vector stores `N` integers, requiring $O(N)$ space.
    *   Other variables (`n`, `max_product`, `max_rating_for_max_product`, `best_index`, `current_product`) use $O(1)$ additional space.
    *   Thus, the total space complexity is $O(N) + O(N) + O(1) = O(N)$.
    *   With `N` up to $10^5$, storing two vectors of $10^5$ integers (approx. $2 \cdot 10^5 \cdot 4$ bytes = $800$ KB) is well within typical memory limits (usually 256 MB).

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries
using namespace std; // Uses the standard namespace

void solve() {
    int n;
    cin >> n; // Read the number of movies

    vector<int> L(n);
    for (int i = 0; i < n; ++i) {
        cin >> L[i]; // Read movie lengths
    }

    vector<int> R(n);
    for (int i = 0; i < n; ++i) {
        cin >> R[i]; // Read movie ratings
    }

    int max_product = 0; // Stores the maximum L*R product found so far
    int max_rating_for_max_product = 0; // Stores the rating R for the movie with max_product (used for tie-breaking)
    int best_index = -1; // Stores the 1-based index of the best movie

    for (int i = 0; i < n; ++i) {
        int current_product = L[i] * R[i]; // Calculate L*R for the current movie

        if (current_product > max_product) {
            // This movie is strictly better by the primary criterion (L*R)
            max_product = current_product;
            max_rating_for_max_product = R[i];
            best_index = i + 1; // Store 1-based index
        } else if (current_product == max_product) {
            // Tie on primary criterion, check secondary criterion (max R)
            if (R[i] > max_rating_for_max_product) {
                // This movie is better by the secondary criterion (higher R)
                max_rating_for_max_product = R[i];
                best_index = i + 1; // Store 1-based index
            }
            // If R[i] == max_rating_for_max_product, it's a tie on both primary and secondary.
            // In this case, we need the minimal index. Since we iterate from i=0 upwards,
            // 'best_index' will naturally retain the smallest index among such ties.
            // So, no action is needed here.
        }
    }

    cout << best_index << "\n"; // Output the 1-based index of the chosen movie
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t; // Read the number of test cases
    while (t--) {
        solve(); // Solve each test case
    }

    return 0;
}
```