# [Difficulty Rating Order (RATINGINPRAC)](https://www.codechef.com/problems/RATINGINPRAC)

- **Difficulty Rating**: 930
- **Solved in**: 1 attempt(s)

## Problem Summary
The objective is to determine whether a given sequence of $N$ difficulty ratings is sorted in non-decreasing order. Specifically, for an array $A$, we must check if $A[i] \le A[i+1]$ holds true for all valid indices $i$ from $0$ to $N-2$. If the condition holds for the entire array, output "Yes"; otherwise, output "No".

## Intuition & Mathematical Observation
A sequence is defined as non-decreasing if every element is less than or equal to the element that follows it. 
- We can iterate through the array from the first element to the second-to-last element.
- At each step $i$, we compare $A[i]$ with $A[i+1]$.
- If we encounter any instance where $A[i] > A[i+1]$, the non-decreasing property is violated, and we can immediately conclude the answer is "No".
- If the loop completes without finding such a violation, the sequence is non-decreasing, and the answer is "Yes".

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the number of elements in the array. We perform a single linear pass through the input.
- **Space Complexity**: $O(N)$ to store the input array. Note that this could be optimized to $O(1)$ by comparing elements on the fly as they are read, but $O(N)$ is well within the memory limits for this problem.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Difficulty Rating Order
 * The task is to check if an array of N integers is sorted in non-decreasing order.
 * A sequence is non-decreasing if for all i from 0 to N-2, arr[i] <= arr[i+1].
 * 
 * Time Complexity: O(N) per test case.
 * Space Complexity: O(N) to store the input array.
 */

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    bool is_non_decreasing = true;
    for (int i = 0; i < N - 1; ++i) {
        if (A[i] > A[i + 1]) {
            is_non_decreasing = false;
            break;
        }
    }

    if (is_non_decreasing) {
        cout << "Yes" << "\n";
    } else {
        cout << "No" << "\n";
    }
}

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    return 0;
}
```