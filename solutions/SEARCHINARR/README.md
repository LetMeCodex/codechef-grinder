# Search an element in an array (SEARCHINARR)
- **Difficulty Rating**: 600
- **Solved in**: 2 attempt(s)

## Problem Summary

The problem asks us to determine if a given integer `X` exists within an array `A` of size `N`. We need to output "YES" if `X` is found in `A`, and "NO" otherwise.

## Intuition & Mathematical Observation

The core of this problem is a fundamental search operation. We are given a collection of numbers (the array `A`) and a target number (`X`). We need to check if the target number is present in the collection.

The most straightforward approach is to examine each element of the array one by one and compare it with the target element `X`. If we find an element that matches `X`, we know `X` is present, and we can stop searching. If we go through the entire array without finding a match, then `X` is not present.

Mathematically, this is equivalent to checking if `X` belongs to the set of elements in `A`. For a finite set $A = \{a_1, a_2, \dots, a_N\}$, we want to determine if $X \in A$. This is true if and only if there exists an index $i$ (where $1 \le i \le N$) such that $a_i = X$.

## Complexity Analysis

- **Time Complexity**: $O(N)$
    The solution iterates through the array `A` once. In the worst case, the target element `X` might be the last element in the array, or it might not be present at all. In either scenario, we will examine all `N` elements of the array. Therefore, the time complexity is directly proportional to the size of the array, which is $O(N)$.

- **Space Complexity**: $O(1)$
    The solution uses a constant amount of extra space. We only need a few variables to store the loop counter (`i`), the array size (`N`), and the target element (`X`). The input array `A` itself takes $O(N)$ space, but this is considered input space and not extra space used by the algorithm. Therefore, the auxiliary space complexity is $O(1)$.

## Solution Code

```cpp
#include <vector> // Required for std::vector
#include <string> // Required for std::string
// #include <iostream> // Not strictly needed in solve function, but good practice for general C++
// #include <bits/stdc++.h> // Can be used instead of specific headers, common in competitive programming

// Using namespace std; is common in competitive programming to avoid writing std::
// If not used, you'd need to prefix std:: before vector, string, etc.
using namespace std;

// Function to search for an element X in an array A
// N: size of the array
// X: element to be searched
// A: the input array
// Returns "YES" if X is found, "NO" otherwise
string solve(int N, int X, const vector<int>& A) {
    // Iterate through the array A
    for (int i = 0; i < N; ++i) {
        // If the current element A[i] is equal to X, we found it
        if (A[i] == X) {
            return "YES"; // Return "YES" immediately
        }
    }
    // If the loop finishes without finding X, it means X is not in the array
    return "NO"; // Return "NO"
}
```