# [Selling Donuts (DONUTSELL)](https://www.codechef.com/problems/DONUTSELL)
- **Difficulty Rating**: 754
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem describes a scenario where there are `N` different types of donuts, and for each type, we are given the initial number of available donuts. Then, `M` customers arrive sequentially. Each customer wants a donut of a specific type. If the desired donut type is available (i.e., its count is greater than zero), the customer buys one, and the count for that donut type decreases by one. If the desired donut type is not available, the customer becomes sad. The task is to calculate and output the total number of sad customers. This process needs to be repeated for `T` test cases.

## Intuition & Mathematical Observation

This problem is a straightforward simulation task. There are no complex mathematical observations or advanced algorithms required. The core idea is to directly model the process described:

1.  **Store Donut Counts**: We need an efficient way to keep track of the number of available donuts for each of the `N` types. A `std::vector<int>` or a simple array is perfect for this. Since donut types are 1-indexed (from 1 to `N`), using a vector of size `N+1` allows us to directly use the donut type as an index, simplifying access.
2.  **Process Customers Sequentially**: The problem explicitly states that customers arrive one by one. This means we must handle their requests in the exact order they are given.
3.  **Check Availability and Update**: For each customer:
    *   Read the type of donut they want.
    *   Check the current count of that donut type in our storage.
    *   If the count is greater than zero, decrement the count (customer buys one).
    *   If the count is zero, increment a counter for sad customers (customer becomes sad).
4.  **Output Result**: After processing all `M` customers, the final value of the sad customer counter is the answer for that test case.

The constraints (`N`, `M` up to $10^5$) suggest that an $O(N+M)$ solution per test case would be efficient enough, which a direct simulation using a vector achieves.

## Complexity Analysis

*   **Time Complexity**:
    *   Reading `N` and `M`: $O(1)$.
    *   Initializing and reading `N` donut counts into the `donut_counts` vector: $O(N)$.
    *   Processing `M` customers: The loop runs `M` times. Inside the loop, reading the customer's desired donut type, accessing an element in the `donut_counts` vector, performing a comparison, and incrementing/decrementing are all constant time operations, $O(1)$. Therefore, this part takes $O(M)$.
    *   Total time complexity for one test case: $O(N + M)$.
    *   Since there are `T` test cases, the overall time complexity is $O(T \cdot (N + M))$.

*   **Space Complexity**:
    *   The `donut_counts` vector stores `N` integer values. This requires $O(N)$ space.
    *   Other variables like `N`, `M`, `B_i`, `sad_customers`, and `T` consume a constant amount of space, $O(1)$.
    *   Total space complexity: $O(N)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries, as requested by the problem statement.

using namespace std; // Uses the standard namespace, as requested.

void solve() {
    int N, M;
    cin >> N >> M;

    // donut_counts stores the number of available donuts for each type.
    // We use a vector of size N+1 to easily handle 1-based indexing for donut types (1 to N).
    vector<int> donut_counts(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> donut_counts[i];
    }

    int sad_customers = 0; // Counter for customers who become sad.

    // Process each of the M customers sequentially.
    for (int i = 0; i < M; ++i) {
        int B_i; // The type of donut the current customer wants.
        cin >> B_i;

        // Check if there are any donuts of the desired type available.
        if (donut_counts[B_i] > 0) {
            // If available, the customer buys one, so decrement the count for that type.
            donut_counts[B_i]--;
        } else {
            // If not available, the customer becomes sad. Increment the sad_customers counter.
            sad_customers++;
        }
    }

    // Output the total number of sad customers for the current test case.
    cout << sad_customers << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Number of test cases.
    cin >> T; // Read the number of test cases.
    while (T--) { // Loop T times, once for each test case.
        solve(); // Call the solve function to handle each test case.
    }

    return 0; // Indicate successful execution.
}
```