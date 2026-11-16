# Nothing in Common (NOTINCOM)
- **Difficulty Rating**: 1386
- **Solved in**: 1 attempt(s)

## Problem Summary
Given two arrays, A and B, of sizes N and M respectively, where elements are integers between 1 and $10^6$. We need to find the minimum number of elements Alice (who owns array A) must discard so that no element in her remaining array is present in Berta's array (array B).

## Intuition & Mathematical Observation
The problem asks for the minimum number of elements Alice needs to discard. This is equivalent to finding the maximum number of elements Alice can *keep* such that none of them are present in Berta's array.

If an element from Alice's array `A` is also present in Berta's array `B`, then Alice *must* discard that element to satisfy the condition. If an element from `A` is *not* present in `B`, Alice can safely keep it.

Therefore, the minimum number of elements Alice needs to discard is exactly the count of elements that are common to both array A and array B.

To efficiently count these common elements, we can use a frequency map or a boolean array to mark the presence of elements from array B. Since the maximum value of elements is $10^6$, a boolean array of size $10^6 + 1$ is feasible and efficient.

The strategy is:
1. Read all elements of array B and mark their presence in a boolean array (e.g., `present_in_B`).
2. Iterate through array A. For each element in A, check if it is marked as present in `present_in_B`.
3. If an element from A is present in `present_in_B`, increment a counter for common elements.
4. The final count of common elements is the minimum number of elements Alice must discard.

A crucial detail for competitive programming problems with multiple test cases is to reset any global or static data structures used for marking presence. In this case, after processing each test case, we need to unmark the elements from B in the `present_in_B` array to ensure correctness for subsequent test cases.

## Complexity Analysis
- **Time Complexity**:
    - Reading N elements for array A: $O(N)$
    - Reading M elements for array B and marking their presence: $O(M)$
    - Iterating through array A and checking for common elements: $O(N)$
    - Resetting the `present_in_B` array for the next test case: $O(M)$ (in the worst case, all elements of B are distinct and need to be reset).
    - The total time complexity per test case is $O(N + M)$.
    - With T test cases, the overall time complexity is $O(T \times (N + M))$. Given the constraints ($N, M \le 10^5$, $T \le 100$), this is well within the time limits.

- **Space Complexity**:
    - `present_in_B` array: $O(\text{MAX\_VAL})$, where MAX\_VAL is $10^6$. This is a constant space requirement relative to N and M, but dependent on the maximum possible value of array elements.
    - `A` vector: $O(N)$
    - `B_values` vector: $O(M)$
    - The dominant space complexity is $O(N + M + \text{MAX\_VAL})$. Since MAX\_VAL is a constant, and N and M are bounded, this is acceptable. If N and M were much larger and MAX\_VAL smaller, the $O(N+M)$ would dominate. If MAX\_VAL was much larger, it would dominate. Here, MAX\_VAL is the largest factor.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes iostream, vector, etc.

// Using namespace std; as requested by the problem statement.
using namespace std;

// Max value for Ai, Bi is 10^6.
// We need indices from 1 to 10^6. So array size 10^6 + 1.
// Declared as static global to be zero-initialized once and reused across test cases.
const int MAX_VAL = 1000000;
static bool present_in_B[MAX_VAL + 1]; 

void solve() {
    int N, M;
    cin >> N >> M;

    // Alice's numbers. Storing them in a vector is fine given N <= 10^5.
    // Alternatively, they could be processed one by one without storing the whole vector.
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // Berta's numbers. We need to store them in a vector to:
    // 1. Mark their presence in 'present_in_B'.
    // 2. Efficiently unmark them after processing the current test case.
    vector<int> B_values(M);
    for (int i = 0; i < M; ++i) {
        cin >> B_values[i];
        present_in_B[B_values[i]] = true;
    }

    int common_count = 0;
    // Iterate through Alice's numbers and check if they are present in Berta's collection.
    for (int i = 0; i < N; ++i) {
        if (present_in_B[A[i]]) {
            common_count++;
        }
    }

    // Output the minimal amount of numbers Alice needs to throw away.
    cout << common_count << "\n";

    // Reset 'present_in_B' for the next test case.
    // Only the elements that were marked 'true' in this test case need to be reset.
    for (int i = 0; i < M; ++i) {
        present_in_B[B_values[i]] = false;
    }
}

int main() {
    // Fast I/O as requested.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases.
    while (T--) { // Loop through each test case.
        solve();
    }

    return 0;
}
```