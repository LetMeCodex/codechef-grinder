# [Alternating Array (ALTARR)](https://www.codechef.com/problems/ALTARR)
- **Difficulty Rating**: 787
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to find the minimum number of elements that need to be changed in a given array `A` of `N` integers such that the resulting array becomes "alternating" in terms of parity. An array is alternating in parity if any two adjacent elements have different parities (one is odd, the other is even). We need to output this minimum count.

## Intuition & Mathematical Observation

An array with alternating parities can only follow one of two possible patterns:

1.  **Pattern 1: Odd, Even, Odd, Even, ...**
    *   The element at index 0 must be Odd.
    *   The element at index 1 must be Even.
    *   The element at index 2 must be Odd.
    *   And so on. In general, for an element at index `i`:
        *   If `i` is even (`i % 2 == 0`), `A[i]` should be Odd (parity 1).
        *   If `i` is odd (`i % 2 == 1`), `A[i]` should be Even (parity 0).

2.  **Pattern 2: Even, Odd, Even, Odd, ...**
    *   The element at index 0 must be Even.
    *   The element at index 1 must be Odd.
    *   The element at index 2 must be Even.
    *   And so on. In general, for an element at index `i`:
        *   If `i` is even (`i % 2 == 0`), `A[i]` should be Even (parity 0).
        *   If `i` is odd (`i % 2 == 1`), `A[i]` should be Odd (parity 1).

Since these are the only two possible alternating parity patterns, the minimum number of changes required will be the minimum of the changes needed to achieve Pattern 1 and the changes needed to achieve Pattern 2.

The solution involves two main steps:
1.  **Calculate `cost1`**: Iterate through the array and count how many elements `A[i]` do not match the required parity for Pattern 1.
2.  **Calculate `cost2`**: Iterate through the array again and count how many elements `A[i]` do not match the required parity for Pattern 2.
3.  The final answer is `min(cost1, cost2)`.

To determine the parity of a number `X`, we use `X % 2`. If `X % 2 == 0`, it's even. If `X % 2 == 1` (or `-1` for negative numbers in some languages, but problem constraints usually imply positive integers or `0`), it's odd. For this problem, `A[i] % 2` will correctly give 0 for even and 1 for odd.

## Complexity Analysis

-   **Time Complexity**: $O(N)$ per test case.
    *   Reading the input array `A` takes $O(N)$ time.
    *   Calculating `cost1` involves a single loop that iterates `N` times. Each operation inside the loop (modulo, comparison, increment) is $O(1)$. Thus, this step takes $O(N)$ time.
    *   Calculating `cost2` similarly involves another single loop that iterates `N` times, also taking $O(N)$ time.
    *   Finding the minimum of `cost1` and `cost2` is $O(1)$.
    *   Therefore, for each test case, the total time complexity is $O(N)$.
    *   Given `T` test cases, the overall time complexity is $O(T \cdot N)$.

-   **Space Complexity**: $O(N)$ per test case.
    *   We use a `std::vector<int> A` of size `N` to store the input array, which requires $O(N)$ space.
    *   All other variables (`N`, `cost1`, `cost2`, loop counters, etc.) use a constant amount of space, $O(1)$.
    *   Thus, the total space complexity for each test case is $O(N)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes iostream, vector, algorithm, etc.

// Using namespace std; as requested by problem statement
using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // Calculate cost for pattern 1: Odd, Even, Odd, Even, ...
    // Target parities: 1, 0, 1, 0, ...
    // For index i:
    // If i is even (i % 2 == 0), A[i] should be Odd (parity 1).
    // If i is odd (i % 2 == 1), A[i] should be Even (parity 0).
    int cost1 = 0;
    for (int i = 0; i < N; ++i) {
        int current_parity = A[i] % 2;
        int required_parity_for_pattern1 = (i % 2 == 0) ? 1 : 0; 
        
        if (current_parity != required_parity_for_pattern1) {
            cost1++;
        }
    }

    // Calculate cost for pattern 2: Even, Odd, Even, Odd, ...
    // Target parities: 0, 1, 0, 1, ...
    // For index i:
    // If i is even (i % 2 == 0), A[i] should be Even (parity 0).
    // If i is odd (i % 2 == 1), A[i] should be Odd (parity 1).
    int cost2 = 0;
    for (int i = 0; i < N; ++i) {
        int current_parity = A[i] % 2;
        int required_parity_for_pattern2 = (i % 2 == 0) ? 0 : 1; 
        
        if (current_parity != required_parity_for_pattern2) {
            cost2++;
        }
    }

    // The minimum changes needed is the minimum of the two costs
    cout << min(cost1, cost2) << "\n";
}

int main() {
    // Fast I/O as requested by problem statement
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
```