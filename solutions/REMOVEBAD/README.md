# [Remove Bad elements (REMOVEBAD)](https://www.codechef.com/problems/REMOVEBAD)
- **Difficulty Rating**: 1100
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to find the minimum number of operations required to make all elements in an array equal. An operation consists of removing any single element from the array. We are given an array $A$ of $N$ integers.

## Intuition & Mathematical Observation

To minimize the number of operations (removals), we need to maximize the number of elements we *keep*.
If we want all remaining elements in the array to be equal, it means they must all have the same value. For example, if we decide to keep only elements with value $X$, then all other elements (those not equal to $X$) must be removed.

Consider an array `[1, 2, 2, 3, 2]`.
*   If we decide to keep only `1`s: We keep one `1`, and remove `2, 2, 3, 2`. This requires 4 removals.
*   If we decide to keep only `2`s: We keep `2, 2, 2`, and remove `1, 3`. This requires 2 removals.
*   If we decide to keep only `3`s: We keep one `3`, and remove `1, 2, 2, 2`. This requires 4 removals.

From these examples, it's clear that the optimal strategy is to choose the element that appears *most frequently* in the original array. By keeping all occurrences of this most frequent element and removing everything else, we maximize the number of elements kept, thereby minimizing the number of removals.

Let $N$ be the total number of elements in the array.
Let $max\_freq$ be the maximum frequency of any element in the array.
The number of elements we choose to keep is $max\_freq$.
The number of elements we must remove is $N - max\_freq$.

Thus, the minimum number of operations is $N - max\_freq$.

To implement this, we can use a frequency map (or an array if the values are within a reasonable range) to count the occurrences of each element and find the maximum frequency.

## Complexity Analysis

Let $N$ be the number of elements in the array.
The problem constraints state that $1 \le A_i \le N$. This is a crucial detail, as it allows us to use a frequency array instead of a hash map, which can be slightly faster and simpler.

*   **Time Complexity**: $O(N)$
    1.  Reading $N$: $O(1)$.
    2.  Initializing the `freq` vector of size $N+1$: $O(N)$.
    3.  Iterating through the $N$ elements of the input array:
        *   For each element, we read its value, increment its count in the `freq` array, and potentially update `max_freq`. All these operations (`cin`, array access, increment, comparison, assignment) take $O(1)$ time.
        *   Since this loop runs $N$ times, this step takes $O(N)$ time.
    4.  Calculating and printing the result $N - max\_freq$: $O(1)$.
    Therefore, the dominant part is the single pass through the array and the initialization of the frequency array, both taking $O(N)$ time. The total time complexity for one test case is $O(N)$.
    Given that the sum of $N$ over all test cases does not exceed $2 \cdot 10^5$, the total time complexity across all test cases will be $O(\sum N)$, which is efficient enough.

*   **Space Complexity**: $O(N)$
    1.  The `freq` vector stores the counts for elements from $1$ to $N$. Its size is $N+1$.
    2.  Other variables (`N`, `val`, `max_freq`) consume $O(1)$ space.
    Therefore, the total space complexity for one test case is $O(N)$. This is acceptable given $N \le 2 \cdot 10^5$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes iostream, vector, algorithm, etc.
using namespace std;     // Use standard namespace for brevity

void solve() {
    int N;
    cin >> N; // Read the length of the array

    // Create a frequency array. Since A_i can be up to N (1 <= A_i <= N),
    // a vector of size N+1 is sufficient to store counts for values from 1 to N.
    // Initialize all counts to 0.
    vector<int> freq(N + 1, 0); 
    
    int max_freq = 0; // Variable to store the maximum frequency found so far

    // Iterate N times to read all elements of the array
    for (int i = 0; i < N; ++i) {
        int val;
        cin >> val; // Read an element A_i

        // Increment the frequency count for the current value
        freq[val]++;

        // Update max_freq if the current value's frequency is higher
        if (freq[val] > max_freq) {
            max_freq = freq[val];
        }
    }
    
    // The minimum number of operations required is N (total elements)
    // minus the count of the most frequent element (which we choose to keep).
    cout << N - max_freq << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is crucial for competitive programming problems with large I/O.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases

    // Loop through each test case
    while (T--) {
        solve(); // Call the solve function for each test case
    }

    return 0; // Indicate successful execution
}
```