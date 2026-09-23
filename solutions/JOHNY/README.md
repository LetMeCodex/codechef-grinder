# [Uncle Johny (JOHNY)](https://www.codechef.com/problems/JOHNY)
- **Difficulty Rating**: 1093
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine the new 1-indexed position of a specific song, "Uncle Johny's song," after all songs are sorted by their lengths in increasing order. We are given:
1.  `N`: The total number of songs.
2.  An array `A` of `N` integers, where `A[i]` represents the length of the `(i+1)`-th song.
3.  `K`: The initial 1-indexed position of Uncle Johny's song.

We need to output the 1-indexed position of Uncle Johny's song in the sorted list.

## Intuition & Mathematical Observation

The core idea revolves around identifying Uncle Johny's song by its unique length and then finding its rank after sorting all songs.

1.  **Identify Uncle Johny's Song Length**: The problem provides the initial 1-indexed position `K` of Uncle Johny's song. Since arrays are 0-indexed in C++, the length of Uncle Johny's song can be found at `A[K-1]`. This length is the crucial piece of information we need to track. Let's store this value.

2.  **Sort All Songs**: The problem states that songs are sorted by their lengths in increasing order. This immediately suggests applying a sorting algorithm to the entire array `A` of song lengths. After sorting, the relative order of songs changes, but the specific length of Uncle Johny's song remains constant.

3.  **Find New Position**: Once the array `A` is sorted, we need to find where our stored `johny_length` now resides.
    *   Since the array is sorted, we can efficiently find the position using a binary search algorithm. `std::lower_bound` is a perfect fit for this. It returns an iterator to the first element in the range `[first, last)` that is not less than `value`. In this problem, assuming all song lengths are distinct (a common competitive programming assumption unless specified otherwise), `lower_bound` will point directly to the element matching `johny_length`.
    *   The `std::distance` function can then be used to calculate the 0-indexed position of this iterator from the beginning of the vector.

4.  **Convert to 1-indexed**: The problem requires the output to be a 1-indexed position. Therefore, we simply add 1 to the 0-indexed position obtained in the previous step.

**Key Insight**: The initial position `K` is only used to determine the *length* of Uncle Johny's song. Once that length is known, the initial position becomes irrelevant for finding its *new* position after sorting. The song's identity for sorting purposes is its length.

## Complexity Analysis

Let `N` be the number of songs.

*   **Time Complexity**:
    *   Reading `N` song lengths into a vector: $O(N)$.
    *   Finding `johny_length` by accessing `A[K-1]`: $O(1)$.
    *   Sorting the vector `A` using `std::sort`: $O(N \log N)$. This is the dominant operation.
    *   Finding the new position using `std::lower_bound` on a sorted vector: $O(\log N)$.
    *   Calculating distance and printing: $O(1)$.
    *   Since there are `T` test cases, the total time complexity would be $O(T \cdot N \log N)$.

    Therefore, the **Time Complexity** is $O(N \log N)$ per test case.

*   **Space Complexity**:
    *   Storing the `N` song lengths in `std::vector<int> A`: $O(N)$ space.
    *   `std::sort` typically uses $O(\log N)$ auxiliary space for its recursive calls (e.g., for Introsort) or $O(N)$ for merge sort in some implementations. However, the primary space usage is for the input vector itself.

    Therefore, the **Space Complexity** is $O(N)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes iostream, vector, algorithm, iterator, etc.

// Using namespace std as requested by problem instructions
using namespace std;

void solve() {
    int N;
    cin >> N; // Read the number of songs

    vector<int> A(N); // Declare a vector to store song lengths
    for (int i = 0; i < N; ++i) {
        cin >> A[i]; // Read song lengths into the vector
    }

    int K;
    cin >> K; // Read the initial 1-indexed position of "Uncle Johny"

    // K is 1-indexed, so A[K-1] is the length of "Uncle Johny"
    int johny_length = A[K - 1];

    // Sort the array of song lengths in increasing order
    sort(A.begin(), A.end());

    // Find the position of johny_length in the sorted array.
    // Since all lengths are unique, std::lower_bound will return an iterator
    // pointing directly to the element with johny_length.
    auto it = lower_bound(A.begin(), A.end(), johny_length);

    // The 0-indexed position is the distance from the beginning of the vector
    int position_0_indexed = distance(A.begin(), it);

    // Convert to 1-indexed position and print the result
    cout << position_0_indexed + 1 << "\n";
}

int main() {
    // Enable fast I/O as requested by problem instructions
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) {
        solve(); // Solve each test case
    }

    return 0;
}
```