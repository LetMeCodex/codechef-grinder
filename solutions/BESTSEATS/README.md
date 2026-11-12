# [Best Seats (BESTSEATS)](https://www.codechef.com/problems/BESTSEATS)
- **Difficulty Rating**: 848
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to find the minimum possible sum of costs of two *adjacent* seats in a row. We are given `N` seats, and for each seat `i`, its cost `A[i]` is provided. We need to process `T` independent test cases. The number of seats `N` is guaranteed to be at least 2.

## Intuition & Mathematical Observation

The core constraint of the problem is that the two chosen seats must be *adjacent*. This simplifies the problem significantly. If we select a seat at index `i`, its only adjacent seat to the right is at index `i+1`. Similarly, its only adjacent seat to the left is at index `i-1`.

To find the minimum sum, we simply need to iterate through all possible pairs of adjacent seats and calculate their sum. We keep track of the smallest sum encountered so far.

Consider a row of seats `A[0], A[1], A[2], ..., A[N-1]`. The possible pairs of adjacent seats are:
*   `(A[0], A[1])`
*   `(A[1], A[2])`
*   `...`
*   `(A[N-2], A[N-1])`

We can initialize our minimum sum with the cost of the first pair `A[0] + A[1]`. Then, we iterate from `i = 1` up to `N-2`, calculating `A[i] + A[i+1]` for each `i`, and updating our minimum sum if the current pair's sum is smaller.

There are no complex mathematical observations or data structures required; a simple linear scan is sufficient.

## Complexity Analysis

*   **Time Complexity**:
    *   For each test case:
        *   Reading `N`: $O(1)$
        *   Reading `N` seat costs into a vector: $O(N)$
        *   Iterating through `N-1` pairs to find the minimum sum: $O(N)$
    *   Therefore, for a single test case, the time complexity is $O(N)$.
    *   Since there are `T` test cases, the total time complexity is $O(T \cdot N)$.
    *   Given $N \le 100$ and $T \le 100$, $T \cdot N \le 100 \cdot 100 = 10^4$, which is very efficient and well within typical time limits.

*   **Space Complexity**:
    *   For each test case:
        *   Storing `N` seat costs in a vector `A`: $O(N)$
    *   The space used is primarily for storing the input array for the current test case.
    *   Therefore, the space complexity is $O(N)$.
    *   Given $N \le 100$, this is a very small amount of memory.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes most standard libraries

// Using namespace std; is common in competitive programming to avoid typing std:: repeatedly
using namespace std;

// Function to solve a single test case
void solve() {
    int N;
    cin >> N; // Read the number of seats in the row

    // Create a vector to store the costs of the seats.
    // N is small (up to 100), so a vector is efficient enough.
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i]; // Read the cost of each seat
    }

    // Initialize min_cost with the cost of the first possible pair of adjacent seats.
    // Since N is guaranteed to be at least 2, seats A[0] and A[1] always exist.
    int min_cost = A[0] + A[1];

    // Iterate through all other possible pairs of adjacent seats.
    // A pair consists of seats at index i and i+1.
    // The loop starts from i = 1 because the pair (A[0], A[1]) has already been considered.
    // It goes up to N-2 (inclusive), meaning the last pair considered will be (A[N-2], A[N-1]).
    for (int i = 1; i < N - 1; ++i) {
        int current_cost = A[i] + A[i+1]; // Calculate the cost of the current adjacent pair
        // Update min_cost if the current pair's cost is lower than the minimum found so far.
        min_cost = min(min_cost, current_cost);
    }

    // Output the minimum cost found for this test case, followed by a newline.
    cout << min_cost << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases

    // Loop through each test case
    while (T--) {
        solve(); // Call the solve function for the current test case
    }

    return 0; // Indicate successful execution
}
```