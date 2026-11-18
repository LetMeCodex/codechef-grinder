# Leader of an Array (DSACPR49)
- **Difficulty Rating**: 950
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to find all "leaders" in a given array of integers. A leader is defined as an element that is strictly greater than all the elements to its right. The rightmost element of the array is always considered a leader. The output should be the leaders in the order they appear in the original array.

## Intuition & Mathematical Observation
The core of the problem lies in efficiently determining, for each element, if it's greater than all elements to its right. A naive approach would be to iterate through each element and then, for each element, iterate through all elements to its right. This would result in an $O(N^2)$ time complexity, which might be too slow for larger inputs.

A more efficient approach can be derived by observing the definition of a leader. An element $A[i]$ is a leader if $A[i] > A[j]$ for all $j > i$. This condition is equivalent to saying that $A[i]$ must be strictly greater than the maximum element among $A[i+1], A[i+2], \dots, A[N-1]$.

This observation suggests a right-to-left traversal of the array. We can maintain a variable that keeps track of the maximum element encountered so far from the right. Let's call this `current_max_from_right`.

When we iterate from right to left (from index $N-1$ down to $0$):
1. For the rightmost element ($A[N-1]$), there are no elements to its right. By definition, it's always a leader. We initialize `current_max_from_right` to a value smaller than any possible element (e.g., `INT_MIN` or `numeric_limits<int>::min()`) so that the rightmost element is guaranteed to be greater than it.
2. For any element $A[i]$ we are currently considering:
   - If $A[i]$ is strictly greater than `current_max_from_right`, it means $A[i]$ is greater than all elements to its right (because `current_max_from_right` holds the maximum of those elements). Therefore, $A[i]$ is a leader.
   - After checking if $A[i]$ is a leader, we must update `current_max_from_right` to be the maximum of its current value and $A[i]$. This is because $A[i]$ will be to the right of elements at indices $i-1, i-2, \dots, 0$, and thus it needs to be considered for their leader status.

Since we are iterating from right to left, the leaders will be identified in reverse order of their appearance in the original array. To satisfy the output requirement of printing leaders in their original relative order, we need to store the identified leaders in a temporary list and then reverse this list before printing.

## Complexity Analysis
- **Time Complexity**: $O(N)$
  - We iterate through the array once from right to left to identify the leaders. This takes $O(N)$ time.
  - We store the leaders in a `leaders` vector. In the worst case, all elements could be leaders, so this vector can grow up to size $N$.
  - Reversing the `leaders` vector takes $O(K)$ time, where $K$ is the number of leaders. Since $K \le N$, this is $O(N)$.
  - Printing the leaders takes $O(K)$ time, which is also $O(N)$.
  - Therefore, the total time complexity is dominated by the linear traversals, resulting in $O(N)$.

- **Space Complexity**: $O(N)$
  - We use a `std::vector<int> A` to store the input array, which takes $O(N)$ space.
  - We use a `std::vector<int> leaders` to store the identified leaders. In the worst case, all $N$ elements could be leaders, so this vector can take up to $O(N)$ space.
  - The `current_max_from_right` variable takes $O(1)$ space.
  - Thus, the total space complexity is $O(N)$.

## Solution Code
```cpp
#include <bits/stdc++.h> // Includes iostream, vector, algorithm, limits, etc.

// Use the standard namespace as requested.
using namespace std;

// The problem statement describes a single test case.
// The generic instruction "Handle multiple test cases (e.g. int t; cin >> t; while(t--))"
// is ignored because the problem statement itself does not specify 't' as input.
void solve() {
    int N;
    cin >> N; // Read the number of elements

    vector<int> A(N); // Declare a vector of size N
    for (int i = 0; i < N; ++i) {
        cin >> A[i]; // Read array elements
    }

    vector<int> leaders; // Vector to store leader elements
    
    // Initialize current_max_from_right with the smallest possible integer value.
    // This ensures that the rightmost element (A[N-1]) will always be greater than it,
    // making it a leader as per the problem definition.
    int current_max_from_right = numeric_limits<int>::min();

    // Iterate through the array from right to left
    for (int i = N - 1; i >= 0; --i) {
        // An element A[i] is a leader if it is strictly greater than
        // all elements to its right. This is equivalent to A[i] being
        // strictly greater than the maximum element to its right.
        // 'current_max_from_right' stores the maximum element encountered so far
        // from the right side of the array (i.e., max(A[i+1], ..., A[N-1])).
        if (A[i] > current_max_from_right) {
            leaders.push_back(A[i]); // If A[i] is a leader, add it to the list
        }
        // Update 'current_max_from_right' to be the maximum of its current value
        // and the current element A[i]. This prepares it for the next iteration (i-1).
        current_max_from_right = max(current_max_from_right, A[i]);
    }

    // The leaders were collected in reverse order of their appearance in the input array.
    // The problem requires printing them in their original relative order (left to right).
    reverse(leaders.begin(), leaders.end());

    // Print the leaders, separated by spaces
    for (size_t i = 0; i < leaders.size(); ++i) {
        cout << leaders[i] << (i == leaders.size() - 1 ? "" : " ");
    }
    cout << "\n"; // Print a newline character at the end
}

int main() {
    // Optimize C++ standard streams for faster input/output operations.
    // This is a common practice in competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Call the solve function for the single test case.
    solve();

    return 0; // Indicate successful execution
}
```