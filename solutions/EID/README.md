# [Chef and Eid (EID)](https://www.codechef.com/problems/EID)
- **Difficulty Rating**: 1135
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to find the minimum possible absolute difference between any two distinct coin values given $N$ coins. We are given $N$ integer values, representing the values of the coins. We need to output the smallest non-negative difference that can be formed by picking any two different coins.

## Intuition & Mathematical Observation
A naive approach would be to calculate the absolute difference between every possible pair of coins and then find the minimum among these differences. If there are $N$ coins, there are $N \times (N-1) / 2$ pairs, leading to an $O(N^2)$ time complexity. Given $N$ can be up to $10^5$, an $O(N^2)$ solution would be too slow ($10^{10}$ operations).

The key insight lies in the property of sorted arrays. Consider a set of numbers $v_0, v_1, \dots, v_{N-1}$. If we sort these numbers in non-decreasing order, say $v_{(0)} \le v_{(1)} \le \dots \le v_{(N-1)}$, then the minimum absolute difference between any two numbers in the set must occur between *adjacent* elements in the sorted sequence.

**Why?**
Let's take any three numbers $a, b, c$ from the set such that $a \le b \le c$.
The difference between the smallest and largest is $c - a$.
This difference can be expressed as $(c - b) + (b - a)$.
Since $a \le b \le c$, both $(c - b)$ and $(b - a)$ are non-negative.
This implies that $c - a \ge c - b$ and $c - a \ge b - a$.
In other words, the difference between two non-adjacent elements ($c$ and $a$) is always greater than or equal to the difference between some adjacent elements ($c$ and $b$, or $b$ and $a$) in the sorted sequence.
Therefore, to find the minimum difference, we only need to check the differences between $v_{(i+1)}$ and $v_{(i)}$ for all $i$ from $0$ to $N-2$.

**Algorithm:**
1. Read the $N$ coin values into a data structure (e.g., a `std::vector`).
2. Sort the coin values in non-decreasing order.
3. Initialize a variable `min_diff` to a very large value (e.g., `INT_MAX`).
4. Iterate through the sorted array from the first element up to the second-to-last element (i.e., from index $0$ to $N-2$).
5. In each iteration, calculate the difference between the current element and the next element: `diff = v[i+1] - v[i]`. Since the array is sorted, this difference will always be non-negative.
6. Update `min_diff = std::min(min_diff, diff)`.
7. **Optimization**: If `min_diff` ever becomes $0$, we can immediately stop and print $0$. This is because a difference of $0$ is the smallest possible non-negative difference, and it occurs when there are at least two coins with the same value.

## Complexity Analysis
- **Time Complexity**:
    - Reading $N$ coin values: $O(N)$
    - Sorting the `std::vector` of $N$ elements: $O(N \log N)$ (using `std::sort`).
    - Iterating through the sorted array to find the minimum difference: $O(N)$
    - The dominant factor is the sorting step.
    - Therefore, the overall time complexity is $O(N \log N)$.

- **Space Complexity**:
    - Storing $N$ coin values in a `std::vector`: $O(N)$
    - `std::sort` typically uses $O(\log N)$ auxiliary space for its recursion stack (e.g., for introsort), or $O(N)$ in the worst case for some implementations or if it falls back to merge sort.
    - The primary space usage is for storing the input array.
    - Therefore, the overall space complexity is $O(N)$.

## Solution Code
```cpp
#include <bits/stdc++.h> // Includes iostream, vector, algorithm, climits etc.

// Function to solve a single test case
void solve() {
    int N;
    std::cin >> N; // Read the number of coins

    std::vector<int> v(N); // Create a vector to store coin values
    for (int i = 0; i < N; ++i) {
        std::cin >> v[i]; // Read each coin value
    }

    // Sort the coin values in non-decreasing order.
    // This is the crucial step for O(N log N) efficiency.
    std::sort(v.begin(), v.end());

    // Initialize min_diff with a very large value.
    // Since v_i are up to 10^6, the maximum possible difference is 10^6 - 1.
    // INT_MAX (from <climits>) is a safe upper bound.
    int min_diff = INT_MAX; 

    // Iterate through the sorted array and calculate differences between adjacent elements.
    // The minimum difference between any two elements will always be found between adjacent elements
    // in a sorted array.
    for (int i = 0; i < N - 1; ++i) {
        // Calculate the difference between the current coin and the next coin.
        // Since the array is sorted, v[i+1] >= v[i], so v[i+1] - v[i] is already non-negative.
        int diff = v[i+1] - v[i];
        
        // Update min_diff if the current difference is smaller.
        if (diff < min_diff) {
            min_diff = diff;
        }
        
        // Optimization: If min_diff becomes 0, we can't get a smaller non-negative difference.
        // So, we can break early.
        if (min_diff == 0) {
            break;
        }
    }

    // Print the minimum possible difference.
    std::cout << min_diff << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) prevents std::cout from flushing before std::cin reads input.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T; // Read the number of test cases
    while (T--) {
        solve(); // Solve each test case
    }

    return 0; // Indicate successful execution
}
```