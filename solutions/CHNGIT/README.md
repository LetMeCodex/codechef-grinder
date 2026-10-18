# [Change It (CHNGIT)](https://www.codechef.com/problems/CHNGIT)
- **Difficulty Rating**: 1061
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to find the minimum number of operations required to make all elements in an array equal. An operation consists of changing any element to any other value. We are given an array of $N$ integers, where each integer $A_i$ is between 1 and 100.

## Intuition & Mathematical Observation

The goal is to make all elements in the array identical. This means the final array will consist of $N$ copies of some value, let's call it $X$. Each operation allows us to change one element to any desired value. We want to minimize the total number of operations.

Consider the following:
1.  **Target Value**: We need to choose a target value $X$ that all elements will eventually become.
2.  **Minimizing Operations**: To minimize operations, we should try to change as few elements as possible. This implies that our chosen target value $X$ should be one that already appears most frequently in the original array.
3.  **Example**: Suppose the array is `[1, 2, 3, 2, 2]` ($N=5$).
    *   If we decide to make all elements `1`: We have one `1`. We need to change the `2`, `3`, `2`, `2` (4 elements) to `1`. This takes 4 operations.
    *   If we decide to make all elements `2`: We have three `2`s. We need to change the `1`, `3` (2 elements) to `2`. This takes 2 operations.
    *   If we decide to make all elements `3`: We have one `3`. We need to change the `1`, `2`, `2`, `2` (4 elements) to `3`. This takes 4 operations.

From the example, it's clear that choosing `2` as the target value results in the minimum operations (2 operations). Notice that `2` is the most frequent element in the original array (it appears 3 times).

**Generalizing this observation**:
If we choose the most frequent element in the array as our target value $X$, then all elements that are *already equal* to $X$ do not require any operation. Only the elements that are *not equal* to $X$ need to be changed.

Let `max_freq` be the maximum frequency of any element in the array. This means there are `max_freq` elements that are already equal to our chosen target value $X$. The remaining $N - \text{max\_freq}$ elements are different from $X$. Each of these $N - \text{max\_freq}$ elements requires exactly one operation to change it to $X$.

Therefore, the minimum number of operations is $N - \text{max\_freq}$.

To implement this, we can use a frequency array (or hash map) to count the occurrences of each number. Since the numbers are constrained to be between 1 and 100, a simple array of size 101 is perfect for this.

## Complexity Analysis

*   **Time Complexity**:
    *   Reading $N$: $O(1)$.
    *   Initializing the frequency `counts` vector: $O(101)$, which simplifies to $O(1)$ as 101 is a constant.
    *   Looping through the $N$ input elements to read them and update their frequencies: This loop runs $N$ times. Inside the loop, reading an integer and incrementing a count in the vector are $O(1)$ operations. So, this part takes $O(N)$ time.
    *   Looping through the `counts` vector (from index 1 to 100) to find the `max_freq`: This loop runs 100 times. Each comparison is $O(1)$. So, this part takes $O(100)$, which simplifies to $O(1)$ as 100 is a constant.
    *   Printing the result: $O(1)$.
    *   For each test case, the total time complexity is $O(N)$.
    *   Given $T$ test cases, the overall time complexity is $O(T \cdot N)$. With $N \le 100$ and $T \le 100$, the maximum operations would be around $100 \times 100 = 10^4$, which is very efficient.

*   **Space Complexity**:
    *   The `counts` vector stores frequencies for values 1 to 100. Its size is 101. This is a constant amount of memory, so its space complexity is $O(101)$, which simplifies to $O(1)$.
    *   Other variables (`N`, `val`, `max_freq`, `T`) also consume $O(1)$ space.
    *   Therefore, the total space complexity is $O(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes iostream, vector, algorithm etc.

using namespace std; // Required by problem statement

void solve() {
    int N;
    cin >> N;
    
    // Use a vector as a frequency array.
    // A_i values are between 1 and 100, so an array of size 101 (indices 0-100) is suitable.
    // Initialize all counts to 0.
    vector<int> counts(101, 0); 
    
    for (int i = 0; i < N; ++i) {
        int val;
        cin >> val;
        counts[val]++; // Increment frequency for the current value
    }
    
    int max_freq = 0;
    // Iterate through possible values (1 to 100) to find the maximum frequency.
    // Since N >= 1, there will always be at least one element, so max_freq will be at least 1.
    for (int i = 1; i <= 100; ++i) {
        if (counts[i] > max_freq) {
            max_freq = counts[i];
        }
    }
    
    // The minimum number of moves is N - (maximum frequency of any element).
    // This is because N - max_freq elements are not equal to the most frequent value,
    // and each of them needs at least one move.
    cout << N - max_freq << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T; // Number of test cases
    cin >> T;
    while (T--) { // Loop through each test case
        solve();
    }
    
    return 0;
}
```