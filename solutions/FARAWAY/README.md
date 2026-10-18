# [Far Away (FARAWAY)](https://www.codechef.com/problems/FARAWAY)
- **Difficulty Rating**: 1090
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an array $A$ of $N$ integers and an integer $M$. We need to choose an array $B$ of $N$ integers such that each element $B_i$ is between $1$ and $M$ (inclusive). The goal is to maximize the sum of absolute differences between corresponding elements of $A$ and $B$, i.e., maximize $\sum_{i=1}^{N} |A_i - B_i|$.

## Intuition & Mathematical Observation
For each element $A_i$ in the given array, we want to choose a corresponding element $B_i$ from the range $[1, M]$ such that the absolute difference $|A_i - B_i|$ is maximized.

Consider a single element $A_i$. We want to find $B_i \in [1, M]$ that maximizes $|A_i - B_i|$.
The possible values for $B_i$ are $1, 2, \dots, M$.
The function $|A_i - x|$ is a V-shaped function with its minimum at $x = A_i$. The further $x$ is from $A_i$, the larger $|A_i - x|$ becomes.
Therefore, to maximize $|A_i - B_i|$, $B_i$ should be chosen as far as possible from $A_i$ within the allowed range $[1, M]$. The two extreme values in the range are $1$ and $M$.

So, for a given $A_i$, the maximum possible value of $|A_i - B_i|$ is achieved when $B_i$ is either $1$ or $M$.
The maximum difference will be $\max(|A_i - 1|, |A_i - M|)$.

Let's analyze this:
- If $A_i$ is closer to $1$, then $M$ will be further away. The maximum difference will be $|A_i - M| = M - A_i$ (since $A_i \le M$).
- If $A_i$ is closer to $M$, then $1$ will be further away. The maximum difference will be $|A_i - 1| = A_i - 1$ (since $A_i \ge 1$).

This can be simplified. The distance from $A_i$ to $1$ is $A_i - 1$. The distance from $A_i$ to $M$ is $M - A_i$.
The maximum possible difference for $A_i$ is thus $\max(A_i - 1, M - A_i)$.

Since we want to maximize the *sum* of absolute differences, and the choice of $B_i$ for each $A_i$ is independent of the choices for other elements, we can maximize each term $|A_i - B_i|$ individually.
Therefore, the total maximum sum is the sum of these individual maximum differences:
$$ \sum_{i=1}^{N} \max(A_i - 1, M - A_i) $$

The problem statement guarantees that $A_i$ will be between $1$ and $M$. This simplifies the calculation of absolute differences. For example, $|A_i - 1|$ is always $A_i - 1$ and $|A_i - M|$ is always $M - A_i$.

## Complexity Analysis
- **Time Complexity**: $O(N)$
  The code iterates through the input array $A$ once. For each element, it performs a constant number of operations (reading the element, calculating the maximum of two values, and adding to the total). Thus, the time complexity is linear with respect to the number of elements $N$.

- **Space Complexity**: $O(N)$
  The code uses a `std::vector<long long> a(n)` to store the input array $A$. This vector requires $O(N)$ space. If we were allowed to process the input elements as they are read without storing the entire array, the space complexity could be reduced to $O(1)$. However, the provided solution stores the array.

## Solution Code
```cpp
#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>
#include <algorithm>

int main() {
    // Optimize C++ standard streams for competitive programming
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; // Number of test cases
    std::cin >> t;
    while (t--) {
        int n; // Number of elements in array A
        long long m; // Upper bound for elements in array B
        std::cin >> n >> m;

        std::vector<long long> a(n); // Array A
        long long total_distance = 0; // Variable to store the sum of maximum distances

        for (int i = 0; i < n; ++i) {
            std::cin >> a[i]; // Read element A_i

            // To maximize |A_i - B_i|, B_i should be chosen as far as possible from A_i
            // within the range [1, M]. The extreme points are 1 and M.
            // The maximum distance for A_i is achieved by picking B_i = 1 or B_i = M.
            // The distance to 1 is |A_i - 1| = A_i - 1 (since A_i >= 1).
            // The distance to M is |A_i - M| = M - A_i (since A_i <= M).
            // We take the maximum of these two distances.
            total_distance += std::max(a[i] - 1, m - a[i]);
        }
        std::cout << total_distance << "\n"; // Output the total maximum distance
    }
    return 0;
}
```