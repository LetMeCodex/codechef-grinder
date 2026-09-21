# Enough Space (ENSPACE)
- **Difficulty Rating**: 317
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to determine if a given storage capacity `n` is sufficient to store a certain number of items. We are given that there are `x` items that require 1 unit of space each, and `y` items that require 2 units of space each. We need to output "YES" if the total space required by these items is less than or equal to `n`, and "NO" otherwise.

## Intuition & Mathematical Observation
The core of the problem lies in calculating the total space required by all the items and then comparing it with the available storage capacity.

Each of the `x` items takes up 1 unit of space. So, the total space occupied by these items is `x * 1`.
Each of the `y` items takes up 2 units of space. So, the total space occupied by these items is `y * 2`.

The total space required for all items is the sum of the space required by both types of items: `(x * 1) + (y * 2)`.

We are given a storage capacity `n`. If the `total_space_required` is less than or equal to `n`, then there is enough space. Otherwise, there isn't.

Therefore, the condition to check is: `(x * 1) + (y * 2) <= n`.

A crucial point to consider is the potential for integer overflow. The problem statement doesn't explicitly mention the constraints on `x`, `y`, and `n`, but in competitive programming, it's good practice to anticipate large values. If `x` and `y` can be large, their product with 1 and 2 respectively, and their sum, could exceed the maximum value of a standard 32-bit integer. Using `long long` for the calculation of `total_size` is a safe approach to prevent this.

## Complexity Analysis
- **Time Complexity**: $O(1)$
The solution involves a fixed number of arithmetic operations (multiplication, addition, and comparison) and input/output operations. These operations take constant time, regardless of the input values. The loop runs `t` times, where `t` is the number of test cases. For each test case, the operations are constant time. Thus, the total time complexity is $O(t)$, but for a single test case, it's $O(1)$.

- **Space Complexity**: $O(1)$
The solution uses a fixed amount of memory to store variables like `t`, `n`, `x`, `y`, and `total_size`. This memory usage does not depend on the input size, making the space complexity constant.

## Solution Code
```cpp
#include <iostream>

int main() {
    // Optimize C++ standard streams for competitive programming
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; // Number of test cases
    std::cin >> t;
    while (t--) {
        int n; // Total storage capacity
        int x, y; // Number of items requiring 1 and 2 units of space respectively
        std::cin >> n >> x >> y;

        // Calculate the total space required.
        // Use long long to prevent potential integer overflow,
        // especially if x and y can be large.
        long long total_size = (long long)x * 1 + (long long)y * 2;

        // Check if the total required space is less than or equal to the available capacity.
        if (total_size <= n) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
    return 0;
}
```