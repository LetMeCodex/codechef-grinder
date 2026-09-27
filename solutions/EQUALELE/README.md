# [Equal Elements (EQUALELE)](https://www.codechef.com/problems/EQUALELE)
- **Difficulty Rating**: 1123
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to find the minimum number of operations required to make all elements in an array $A$ of size $N$ equal. An operation consists of changing the value of any one element in the array.

## Intuition & Mathematical Observation

Let's say we want to make all $N$ elements of the array equal to some value $X$.
If there are $k$ elements in the original array that are already equal to $X$, then we need to change the values of the remaining $N - k$ elements to $X$.
To minimize the number of operations, we need to minimize $N - k$. This is equivalent to maximizing $k$.

Therefore, the optimal strategy is to choose the target value $X$ to be the element that appears most frequently in the original array. If the maximum frequency of any element in the array is `max_freq`, then we already have `max_freq` elements equal to our target value. The minimum number of operations required will then be $N - \text{max\_freq}$.

For example, if $N=5$ and the array is $[1, 2, 2, 3, 2]$:
*   Frequency of 1: 1
*   Frequency of 2: 3
*   Frequency of 3: 1
The maximum frequency is 3 (for the element 2).
So, we choose 2 as our target value. We already have three 2s. We need to change the 1 and the 3 to 2. This requires $5 - 3 = 2$ operations.

## Complexity Analysis

*   **Time Complexity**:
    For each test case:
    1.  Reading $N$ elements and updating their frequencies in the `freq` array, and simultaneously tracking `max_freq`: This loop runs $N$ times, with each operation (array access, increment, comparison) taking $O(1)$ time. So, this part is $O(N)$.
    2.  Storing elements in `elements_in_current_test_case` also takes $O(N)$ time.
    3.  Resetting frequencies for the elements encountered in the current test case: This loop iterates through `elements_in_current_test_case`, which contains $N$ elements. Each reset takes $O(1)$ time. So, this part is $O(N)$.
    Therefore, for a single test case, the time complexity is $O(N)$.
    Since there are $T$ test cases, the total time complexity over all test cases is $O(\sum N)$, where $\sum N$ is the sum of $N$ over all test cases. Given $N \le 2 \cdot 10^5$ and $T \le 10$, $\sum N$ can be up to $2 \cdot 10^6$, which is efficient enough.

*   **Space Complexity**:
    1.  `freq` array: This is a global array of size `MAX_VAL` (200005). This size is constant with respect to $N$ for a single test case, but chosen based on the maximum possible value of $A_i$ (which can be up to $N_{max}$). So, it contributes $O(MAX\_VAL)$ to space.
    2.  `elements_in_current_test_case` vector: This vector stores all $N$ elements of the current test case to facilitate resetting frequencies. It contributes $O(N)$ to space.
    Overall, the space complexity is $O(MAX\_VAL + N_{max\_current})$. Since `MAX_VAL` is determined by the maximum possible $N$, we can simplify this to $O(N_{max\_overall})$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries

// Use the standard namespace as requested
using namespace std;

// Using a global frequency array to avoid reallocating large memory for each test case.
// MAX_VAL is chosen based on the maximum possible value of N (2 * 10^5)
// since A_i can be up to N. So, indices up to 200000 are needed.
const int MAX_VAL = 200005; 
int freq[MAX_VAL]; // Stores frequencies of elements. Global arrays are initialized to 0 by default.

void solve() {
    int N;
    cin >> N;

    int max_freq = 0;
    // We need to store the elements encountered in the current test case
    // to efficiently reset their frequencies for the next test case.
    vector<int> elements_in_current_test_case;
    elements_in_current_test_case.reserve(N); // Pre-allocate memory for efficiency

    for (int i = 0; i < N; ++i) {
        int A_i;
        cin >> A_i;
        freq[A_i]++; // Increment frequency for A_i
        max_freq = max(max_freq, freq[A_i]); // Update max_freq with the current maximum frequency
        elements_in_current_test_case.push_back(A_i); // Store A_i to clear its freq later
    }

    // The minimum operations needed is N - (maximum frequency).
    // This is because we want to make all N elements equal to the most frequent element.
    // If 'max_freq' elements are already equal to that value, we need to change N - max_freq elements.
    cout << N - max_freq << "\n";

    // Reset frequencies for the elements encountered in this test case.
    // This is crucial for correctness in subsequent test cases and maintains O(sum of N) complexity.
    for (int val : elements_in_current_test_case) {
        freq[val] = 0;
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
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