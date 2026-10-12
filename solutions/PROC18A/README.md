# The Great Run (PROC18A)
- **Difficulty Rating**: 1097
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to find the maximum number of girls Vishal can impress. Vishal can choose any contiguous stretch of $K$ kilometers on a track of length $N$ kilometers. For each kilometer, we are given the number of girls present. Vishal wants to maximize the total number of girls in his chosen $K$-kilometer stretch.

## Intuition & Mathematical Observation
The core of this problem is to find the maximum sum of a contiguous sub-array of a fixed size $K$ within a larger array of size $N$. This is a classic "sliding window" problem.

We can iterate through all possible contiguous stretches of $K$ kilometers. A stretch of $K$ kilometers can start at kilometer 0, kilometer 1, ..., up to kilometer $N-K$.

A naive approach would be to iterate through each possible starting point $i$ (from $0$ to $N-K$) and then sum up the girls from kilometer $i$ to $i+K-1$. This would involve a nested loop, leading to a time complexity of $O(N \cdot K)$. Given the constraints, this might be too slow if $N$ and $K$ are large.

A more efficient approach is the **sliding window technique**.
1.  **Initialize the first window**: Calculate the sum of girls for the first $K$ kilometers (from index 0 to $K-1$). This will be our initial maximum.
2.  **Slide the window**: For each subsequent kilometer, we can efficiently update the sum of the current window. When the window slides one kilometer to the right:
    *   The girl count from the kilometer that is no longer in the window (the leftmost kilometer of the previous window) is subtracted.
    *   The girl count from the new kilometer that enters the window (the rightmost kilometer of the current window) is added.
3.  **Track the maximum**: At each step of sliding the window, we compare the current window's sum with the maximum sum found so far and update the maximum if necessary.

Let $a_i$ be the number of girls in the $i$-th kilometer.
The first window sum is $S_0 = a_0 + a_1 + \dots + a_{K-1}$.
The second window sum is $S_1 = a_1 + a_2 + \dots + a_K$.
Notice that $S_1 = S_0 - a_0 + a_K$.
In general, if the current window sum is $S_{i-1}$ (representing kilometers $i-1$ to $i-1+K-1$), the next window sum $S_i$ (representing kilometers $i$ to $i+K-1$) can be calculated as:
$S_i = S_{i-1} - a_{i-1} + a_{i+K-1}$.

This sliding window approach allows us to calculate the sum for each window in $O(1)$ time after the initial window sum is computed.

## Complexity Analysis
- **Time Complexity**: $O(N)$
    - We first iterate through the first $K$ elements to calculate the initial window sum. This takes $O(K)$ time.
    - Then, we iterate from the $K$-th element to the $(N-1)$-th element (a total of $N-K$ elements). In each iteration, we perform constant time operations (subtraction, addition, comparison). This takes $O(N-K)$ time.
    - The total time complexity is $O(K + (N-K)) = O(N)$.

- **Space Complexity**: $O(N)$
    - We use a vector `a` of size $N$ to store the number of girls for each kilometer. This requires $O(N)$ space.
    - The variables `t`, `n`, `k`, `current_window_sum`, and `max_girls_impressed` use $O(1)$ space.
    - Therefore, the dominant space complexity is $O(N)$ due to the input array storage. If we were allowed to read input on the fly without storing the entire array, the space complexity could be reduced to $O(1)$ by processing elements as they are read. However, given the standard competitive programming setup, storing the array is typical.

## Solution Code
```cpp
#include <bits/stdc++.h> // Includes most standard libraries, common in competitive programming
using namespace std;     // Allows using standard library elements without the std:: prefix

int main() {
    // Optimize C++ standard streams for competitive programming.
    // Unties cin from cout and prevents synchronization with C's stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t; // Read the number of testcases

    while (t--) { // Loop through each testcase
        int n, k;
        cin >> n >> k; // Read N (total track length) and K (max speed stretch length)

        vector<int> a(n); // Declare a vector of size N to store girl counts per kilometre
        for (int i = 0; i < n; ++i) {
            cin >> a[i]; // Read the number of girls for each kilometre
        }

        int current_window_sum = 0;
        // Calculate the sum of girls in the first K kilometres (initial window)
        // This covers the window from index 0 to K-1
        for (int i = 0; i < k; ++i) {
            current_window_sum += a[i];
        }

        int max_girls_impressed = current_window_sum; // Initialize max_girls_impressed with the first window's sum

        // Slide the window across the track
        // The loop starts from 'i = k'. In each iteration:
        // 'a[i]' is the new element entering the window (rightmost element of the new window).
        // 'a[i - k]' is the element leaving the window (leftmost element of the previous window).
        for (int i = k; i < n; ++i) {
            // Update the current window sum:
            // Subtract the element that is leaving the window (a[i-k])
            // Add the element that is entering the window (a[i])
            current_window_sum = current_window_sum - a[i - k] + a[i];
            
            // Update the maximum sum found so far if the current window sum is greater
            max_girls_impressed = max(max_girls_impressed, current_window_sum);
        }

        // Print the maximum number of girls Vishal can impress for the current testcase
        // Follows the output format: one integer per line.
        cout << max_girls_impressed << "\n";
    }

    return 0; // Indicate successful execution
}
```