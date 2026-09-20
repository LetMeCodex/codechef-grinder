# [Running Comparison (RUNCOMPARE)](https://www.codechef.com/problems/RUNCOMPARE)
- **Difficulty Rating**: 899
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine the number of "happy days" for Alice and Bob. We are given the number of days, `N`, and for each day `i`, the distance Alice ran (`A[i]`) and the distance Bob ran (`B[i]`).

The conditions for happiness are:
1.  **Alice is happy** on day `i` if Bob's distance (`B[i]`) is **not strictly more than twice** Alice's distance (`A[i]`).
2.  **Bob is happy** on day `i` if Alice's distance (`A[i]`) is **not strictly more than twice** Bob's distance (`B[i]`).

A day is considered a "happy day" if **both** Alice and Bob are happy on that particular day. We need to output the total count of such happy days.

## Intuition & Mathematical Observation

The core of this problem lies in correctly interpreting the phrase "not strictly more than twice".

Let's break it down:
*   "Twice X" means `2 * X`.
*   "Strictly more than twice X" means `> 2 * X`.
*   "Not strictly more than twice X" is the negation of `> 2 * X`, which means `NOT (> 2 * X)`. This simplifies to `<= 2 * X`.

Applying this to the happiness conditions:
1.  **Alice's happiness condition**: Bob's distance (`B[i]`) is not strictly more than twice Alice's distance (`A[i]`).
    Mathematically, this translates to: `B[i] <= 2 * A[i]`.

2.  **Bob's happiness condition**: Alice's distance (`A[i]`) is not strictly more than twice Bob's distance (`B[i]`).
    Mathematically, this translates to: `A[i] <= 2 * B[i]`.

For a day `i` to be a "happy day", both conditions must be true simultaneously. So, on day `i`, it's a happy day if `(B[i] <= 2 * A[i])` AND `(A[i] <= 2 * B[i])`.

The solution approach is straightforward:
1.  Read the number of days, `N`.
2.  Read all `N` distances for Alice into a vector (or array), `A`.
3.  Read all `N` distances for Bob into a vector (or array), `B`.
4.  Initialize a counter, `happy_days_count`, to 0.
5.  Iterate from `i = 0` to `N-1` (representing each day):
    *   Check if `B[i] <= 2 * A[i]`.
    *   Check if `A[i] <= 2 * B[i]`.
    *   If both conditions are true, increment `happy_days_count`.
6.  After iterating through all days, print the final `happy_days_count`.

This problem is a direct application of conditional logic and array traversal. No complex algorithms or data structures are required.

## Complexity Analysis

*   **Time Complexity**:
    *   Reading `N`: $O(1)$
    *   Reading `N` elements for vector `A`: $O(N)$
    *   Reading `N` elements for vector `B`: $O(N)$
    *   The main loop iterates `N` times. Inside the loop, we perform constant-time comparisons and an increment. Thus, the loop takes $O(N)$ time.
    *   Overall, for a single test case, the time complexity is $O(1) + O(N) + O(N) + O(N) = O(N)$.
    *   Given `T` test cases, the total time complexity is $O(T \cdot N)$.

*   **Space Complexity**:
    *   Vector `A` stores `N` integers: $O(N)$
    *   Vector `B` stores `N` integers: $O(N)$
    *   Other variables (`N`, `happy_days_count`, loop counter `i`) use $O(1)$ space.
    *   Therefore, the total space complexity is $O(N) + O(N) + O(1) = O(N)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes iostream, vector, etc.

// It's common practice in competitive programming to use the entire std namespace
// for brevity in single-file solutions.
using namespace std;

// Function to solve a single test case
void solve() {
    int N;
    cin >> N; // Read the number of days

    // Vectors to store distances for Alice and Bob
    vector<int> A(N);
    vector<int> B(N);

    // Read Alice's distances
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    // Read Bob's distances
    for (int i = 0; i < N; ++i) {
        cin >> B[i];
    }

    int happy_days_count = 0; // Initialize counter for days both are happy

    // Iterate through each day to check happiness conditions
    for (int i = 0; i < N; ++i) {
        // Alice is happy if Bob's distance is NOT strictly more than twice her distance.
        // This means B[i] <= 2 * A[i]
        bool alice_happy = (B[i] <= 2 * A[i]);
        
        // Bob is happy if Alice's distance is NOT strictly more than twice his distance.
        // This means A[i] <= 2 * B[i]
        bool bob_happy = (A[i] <= 2 * B[i]);

        // If both are happy on this day, increment the counter
        if (alice_happy && bob_happy) {
            happy_days_count++;
        }
    }

    // Output the total count of days where both were happy
    cout << happy_days_count << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin from cout and disables synchronization with C's stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) { // Loop through each test case
        solve(); // Call the solve function for the current test case
    }

    return 0; // Indicate successful execution
}
```