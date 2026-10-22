# [Decoration Discount (DECDISC)](https://www.codechef.com/problems/DECDISC)

- **Difficulty Rating**: 781
- **Solved in**: 3 attempt(s)

## Problem Summary
You are given $N$ vases, each with a price $A_i$. You need to purchase exactly two distinct vases. If you choose two adjacent vases (i.e., index $i$ and $i+1$), the second vase in the pair is sold at half its price (integer division). If the vases are not adjacent, you pay the full price for both. The goal is to find the minimum total cost to purchase any two distinct vases.

## Intuition & Mathematical Observation
1. **The Discount Rule**: The discount only applies if the indices are adjacent ($|i - j| = 1$). In this case, the cost is $A_i + \lfloor A_{i+1} / 2 \rfloor$ or $A_{i+1} + \lfloor A_i / 2 \rfloor$.
2. **The Non-Discount Rule**: If the indices are not adjacent, the cost is simply $A_i + A_j$.
3. **Strategy**: 
   - Since $N$ is small (implied by the constraints of a 781-rated problem), we can iterate through all possible pairs $(i, j)$ where $i \neq j$.
   - For every pair, we calculate the cost based on whether they are adjacent or not.
   - We keep track of the minimum cost encountered during the iteration.
4. **Optimization**: While an $O(N^2)$ approach is sufficient for small $N$, one could also observe that the minimum cost will likely involve either the two smallest elements in the array (if they are not adjacent) or an adjacent pair where one element is small and the other is halved. Given the constraints, the brute-force approach is robust and easy to implement.

## Complexity Analysis
- **Time Complexity**: $O(N^2)$ per test case, where $N$ is the number of vases. Given the constraints typical for this difficulty level, this will comfortably pass within the time limit.
- **Space Complexity**: $O(N)$ to store the prices of the vases in a vector.

## Solution Code

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    // Optimize standard I/O operations
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T;
    while (T--) {
        int N;
        std::cin >> N;
        std::vector<int> A(N);
        for (int i = 0; i < N; ++i) {
            std::cin >> A[i];
        }

        long long min_cost = -1; 

        // Iterate through all possible pairs (i, j)
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (i == j) continue; // Must buy two DIFFERENT vases

                long long current_cost;
                // Check if the vases are adjacent
                if (std::abs(i - j) == 1) {
                    // Apply discount to the second vase in the pair
                    // The problem implies the second one chosen gets the discount
                    current_cost = (long long)A[i] + ((long long)A[j] / 2);
                } else {
                    // No discount applies
                    current_cost = (long long)A[i] + (long long)A[j];
                }

                // Update min_cost
                if (min_cost == -1 || current_cost < min_cost) {
                    min_cost = current_cost;
                }
            }
        }
        std::cout << min_cost << "\n";
    }
    return 0;
}
```