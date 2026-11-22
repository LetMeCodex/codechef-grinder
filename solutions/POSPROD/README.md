# [Positive Products (POSPROD)](https://www.codechef.com/problems/POSPROD)
- **Difficulty Rating**: 1178
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an array of $N$ integers, we need to find the number of pairs of indices $(i, j)$ such that $1 \le i < j \le N$ and the product $A_i \times A_j$ is positive.

## Intuition & Mathematical Observation
The product of two numbers $A_i$ and $A_j$ is positive if and only if:
1. Both $A_i$ and $A_j$ are positive.
2. Both $A_i$ and $A_j$ are negative.

The problem statement implies that we are looking for pairs $(i, j)$ where $i < j$. This means we are counting unordered pairs of distinct elements.

Let's count the number of positive integers and negative integers in the given array.
Suppose there are `positive_count` positive numbers and `negative_count` negative numbers.

- **Pairs of positive numbers**: Any pair of two distinct positive numbers will result in a positive product. The number of ways to choose 2 distinct positive numbers from `positive_count` positive numbers is given by the combination formula: $C(\text{positive\_count}, 2) = \frac{\text{positive\_count} \times (\text{positive\_count} - 1)}{2}$.

- **Pairs of negative numbers**: Similarly, any pair of two distinct negative numbers will result in a positive product (negative $\times$ negative = positive). The number of ways to choose 2 distinct negative numbers from `negative_count` negative numbers is given by: $C(\text{negative\_count}, 2) = \frac{\text{negative\_count} \times (\text{negative\_count} - 1)}{2}$.

- **Pairs involving zero**: If one of the numbers is zero, the product will be zero, which is not positive. Therefore, we don't need to consider pairs involving zeros.

The total number of pairs $(i, j)$ with $i < j$ such that $A_i \times A_j > 0$ is the sum of the number of pairs of positive numbers and the number of pairs of negative numbers.

Total positive products = $C(\text{positive\_count}, 2) + C(\text{negative\_count}, 2)$
Total positive products = $\frac{\text{positive\_count} \times (\text{positive\_count} - 1)}{2} + \frac{\text{negative\_count} \times (\text{negative\_count} - 1)}{2}$

The solution involves iterating through the array once to count the number of positive and negative elements. Then, we apply the combination formula to calculate the total number of pairs.

## Complexity Analysis
- **Time Complexity**: $O(N)$
  The code iterates through the input array of size $N$ exactly once to count the positive and negative numbers. The calculation of the number of pairs takes constant time. Therefore, the overall time complexity is linear with respect to the input size $N$.

- **Space Complexity**: $O(1)$
  The code uses a few variables (`t`, `n`, `positive_count`, `negative_count`, `a`, `pairs`) to store counts and intermediate results. The amount of memory used does not depend on the input size $N$. Thus, the space complexity is constant.

## Solution Code
```cpp
#include <iostream>
#include <vector>
#include <numeric>

int main() {
    // Optimize C++ standard streams for faster input/output.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; // Number of test cases
    std::cin >> t;
    while (t--) {
        int n; // Size of the array
        std::cin >> n;

        long long positive_count = 0; // Counter for positive numbers
        long long negative_count = 0; // Counter for negative numbers

        // Iterate through the array to count positive and negative numbers
        for (int i = 0; i < n; ++i) {
            int a; // Current element of the array
            std::cin >> a;
            if (a > 0) {
                positive_count++;
            } else if (a < 0) {
                negative_count++;
            }
            // Numbers equal to 0 do not contribute to positive products,
            // so they are ignored.
        }

        // Calculate the number of pairs of positive numbers.
        // This is the number of ways to choose 2 distinct positive numbers: C(positive_count, 2).
        // Formula: k * (k - 1) / 2
        long long positive_pairs = (positive_count * (positive_count - 1)) / 2;

        // Calculate the number of pairs of negative numbers.
        // This is the number of ways to choose 2 distinct negative numbers: C(negative_count, 2).
        // Formula: k * (k - 1) / 2
        long long negative_pairs = (negative_count * (negative_count - 1)) / 2;

        // The total number of pairs with a positive product is the sum of
        // pairs of positive numbers and pairs of negative numbers.
        long long total_positive_products = positive_pairs + negative_pairs;

        std::cout << total_positive_products << "\n";
    }
    return 0;
}
```