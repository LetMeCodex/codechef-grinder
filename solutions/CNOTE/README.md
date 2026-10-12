# [Chef and Notebooks (CNOTE)](https://www.codechef.com/problems/CNOTE)
- **Difficulty Rating**: 1255
- **Solved in**: 1 attempt(s)

## Problem Summary

Chef wants to write a poetry book of `X` pages. He has already written `Y` pages. He needs to buy a new notebook to complete his book. He has a budget of `K` rupees. There are `N` notebooks available in a shop. Each notebook `i` has `Pi` pages and costs `Ci` rupees.

Chef is considered "LuckyChef" if he can find *at least one* notebook in the shop that satisfies two conditions:
1.  It provides enough pages to complete his book (i.e., `Pi` must be greater than or equal to the remaining pages needed).
2.  Its price `Ci` does not exceed his budget `K`.

If no such notebook exists, Chef is "UnluckyChef". We need to output "LuckyChef" or "UnluckyChef" for each test case.

## Intuition & Mathematical Observation

1.  **Pages Required**: The first step is to determine how many additional pages Chef needs. If he needs `X` total pages and already has `Y` pages, he needs `X - Y` more pages. It's important to note that if `Y` is already greater than or equal to `X`, he doesn't need any *additional* pages. In this scenario, `X - Y` would be non-positive. We can express the minimum pages required from a new notebook as `max(0, X - Y)`. Let's call this `pages_needed`.

2.  **Notebook Selection Criteria**: For a notebook to be suitable, it must meet two conditions simultaneously:
    *   `Pi >= pages_needed` (It provides enough pages).
    *   `Ci <= K` (Its price is within budget).

3.  **Iterative Search**: We need to examine all `N` notebooks available in the shop. We can use a boolean flag, say `found_suitable_notebook`, initialized to `false`. We iterate through each notebook. If we find any notebook that satisfies both criteria mentioned above, we set `found_suitable_notebook` to `true`.

4.  **Final Decision**: After checking all `N` notebooks, if `found_suitable_notebook` is `true`, it means Chef can complete his book, so we print "LuckyChef". Otherwise, if the flag remains `false`, no suitable notebook was found, and we print "UnluckyChef".

The problem essentially asks for an existence check: "Does there exist *any* notebook that satisfies both conditions?"

## Complexity Analysis

-   **Time Complexity**:
    The solution involves iterating through `T` test cases. For each test case, we read `N` pairs of `Pi` and `Ci` values.
    -   Reading `T`: $O(1)$
    -   Looping `T` times:
        -   Reading `X, Y, K, N`: $O(1)$
        -   Calculating `pages_needed`: $O(1)$
        -   Looping `N` times (for each notebook):
            -   Reading `Pi, Ci`: $O(1)$
            -   Performing comparisons: $O(1)$
        -   Printing the result: $O(1)$
    Therefore, the total time complexity is dominated by the nested loops, resulting in $O(T \cdot N)$. Given typical constraints (e.g., $T \le 100$, $N \le 1000$), $100 \cdot 1000 = 10^5$ operations per test file is well within standard time limits.

-   **Space Complexity**:
    The solution uses a fixed number of integer variables (`T, X, Y, K, N, pages_needed, Pi, Ci`) and a boolean flag (`found_suitable_notebook`). These variables consume a constant amount of memory regardless of the input size `N` or `T`.
    Therefore, the space complexity is $O(1)$ (excluding the space required for input/output buffers, which is typically not counted in algorithm space complexity).

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes common C++ headers, as requested by the problem statement

// Using namespace std; is common in competitive programming and requested by the problem statement
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is crucial for competitive programming problems with large I/O.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases

    while (T--) { // Loop through each test case
        int X, Y, K, N;
        cin >> X >> Y >> K >> N; // Read poetry length, current pages, budget, and number of notebooks

        // Calculate the minimum number of additional pages Chef needs from a new notebook.
        // If Chef already has enough pages (Y >= X), he needs 0 additional pages.
        // Otherwise, he needs X - Y pages.
        int pages_needed = max(0, X - Y);

        bool found_suitable_notebook = false; // Flag to track if a suitable notebook is found

        // Iterate through all N notebooks available in the shop
        for (int i = 0; i < N; ++i) {
            int Pi, Ci;
            cin >> Pi >> Ci; // Read pages (Pi) and price (Ci) of the current notebook

            // Check if the current notebook meets both criteria:
            // 1. Its price (Ci) does not exceed Chef's budget (K).
            // 2. It provides enough pages (Pi) to cover the 'pages_needed'.
            if (Ci <= K && Pi >= pages_needed) {
                found_suitable_notebook = true; // Mark that a suitable notebook has been found
                // We don't break here because we still need to consume the remaining input
                // for this test case to ensure correct parsing for subsequent test cases.
                // The loop will continue, but 'found_suitable_notebook' will remain true.
            }
        }

        // After checking all notebooks, print the result based on the flag
        if (found_suitable_notebook) {
            cout << "LuckyChef\n";
        } else {
            cout << "UnluckyChef\n";
        }
    }

    return 0; // Indicate successful execution
}
```