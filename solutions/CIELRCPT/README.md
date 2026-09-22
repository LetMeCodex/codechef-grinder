# [Ciel and Receipt (CIELRCPT)](https://www.codechef.com/problems/CIELRCPT)
- **Difficulty Rating**: 936
- **Solved in**: 1 attempt(s)

## Problem Summary
Ciel wants to buy a receipt of price $P$. The restaurant offers a special deal where they have menus with prices that are powers of 2, from $2^0$ to $2^{11}$ (i.e., 1, 2, 4, 8, ..., 2048). Ciel wants to find the minimum number of menus she needs to buy to achieve the exact price $P$.

## Intuition & Mathematical Observation
The problem asks us to represent a given integer $P$ as a sum of powers of 2, using the minimum number of terms. This is a classic problem that can be solved using a greedy approach.

Consider the binary representation of the number $P$. Any positive integer can be uniquely represented as a sum of distinct powers of 2. For example, if $P = 13$, its binary representation is $1101_2$, which means $13 = 1 \cdot 2^3 + 1 \cdot 2^2 + 0 \cdot 2^1 + 1 \cdot 2^0 = 8 + 4 + 1$. In this case, we would need 3 menus.

However, the problem statement implies that we can use multiple menus of the same price. For instance, if we need to make a sum of 6, we could use one menu of price 4 and one menu of price 2 (2 menus total). Alternatively, we could use three menus of price 2 (3 menus total). The goal is to minimize the total number of menus.

The key insight here is that to minimize the number of menus, we should always try to use the largest possible menu price that is less than or equal to the remaining amount. This is because any larger power of 2 can be represented by multiple smaller powers of 2, but using the largest power of 2 directly will always be more efficient if it fits.

Let's illustrate with an example: $P = 23$.
The available menu prices are: 1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048.

1.  **Start with the largest price**: The largest price less than or equal to 23 is 16.
    *   We use one menu of price 16.
    *   Remaining amount: $23 - 16 = 7$.
    *   Number of menus: 1.

2.  **Consider the next largest price**: The largest price less than or equal to 7 is 4.
    *   We use one menu of price 4.
    *   Remaining amount: $7 - 4 = 3$.
    *   Number of menus: $1 + 1 = 2$.

3.  **Consider the next largest price**: The largest price less than or equal to 3 is 2.
    *   We use one menu of price 2.
    *   Remaining amount: $3 - 2 = 1$.
    *   Number of menus: $2 + 1 = 3$.

4.  **Consider the next largest price**: The largest price less than or equal to 1 is 1.
    *   We use one menu of price 1.
    *   Remaining amount: $1 - 1 = 0$.
    *   Number of menus: $3 + 1 = 4$.

The total number of menus is 4.

This greedy strategy works because the prices are powers of 2. If we have an amount $X$ and the largest power of 2 less than or equal to $X$ is $2^k$, then $X = 2^k + (X - 2^k)$. The term $(X - 2^k)$ will always be less than $2^k$. By picking the largest possible power of 2, we are essentially performing a greedy decomposition similar to how binary representations are formed, but allowing for multiple uses of the same power.

The maximum price is $2^{11} = 2048$. The maximum possible value for $P$ is not explicitly stated but given the context of competitive programming problems, it's usually within standard integer limits. The provided solution uses prices up to 2048, which is sufficient for typical constraints.

The greedy approach can be implemented by iterating through the available menu prices in descending order. For each price, we determine how many menus of that price can be used without exceeding the remaining amount, add that count to our total, and update the remaining amount.

## Complexity Analysis

-   **Time Complexity**: $O(\log P)$ or more precisely $O(K)$, where $K$ is the number of available menu prices. Since the menu prices are fixed powers of 2 up to $2^{11}$, there are a constant number of prices (12 prices). Therefore, the time complexity for each test case is $O(1)$ because the loop runs a fixed number of times (12 iterations). If $P$ could be arbitrarily large and we had to generate powers of 2, it would be $O(\log P)$.

-   **Space Complexity**: $O(1)$. We are using a fixed-size array to store the prices and a few variables to keep track of the count and remaining price. The space used does not depend on the input size $P$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes iostream, vector, algorithm, etc.

// Use the standard namespace
using namespace std;

void solve() {
    int p;
    cin >> p; // Read the price p for the current test case
    
    int count = 0; // Initialize count of menus
    
    // Menu prices are 2^0 to 2^11.
    // For a greedy approach, it's best to iterate from largest to smallest price.
    // The prices are: 2048, 1024, 512, 256, 128, 64, 32, 16, 8, 4, 2, 1
    int prices[] = {2048, 1024, 512, 256, 128, 64, 32, 16, 8, 4, 2, 1};
    
    // Iterate through the prices in descending order
    for (int price : prices) {
        // Add as many items of the current price as possible
        // Integer division p / price gives the maximum number of menus of this price
        // that can be used without exceeding the remaining amount p.
        count += p / price;
        
        // Update p with the remaining amount after using as many menus of 'price' as possible.
        // The modulo operator p % price gives the remainder.
        p %= price;
        
        // If p becomes 0, we have found the exact sum, so we can stop early.
        // This is an optimization, not strictly necessary given the small constraints
        // on the number of menu prices.
        if (p == 0) {
            break;
        }
    }
    
    cout << count << "\n"; // Print the minimum number of menus
}

int main() {
    // Optimize C++ standard streams for competitive programming.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams,
    // which can speed up I/O operations.
    // std::cin.tie(NULL) prevents cin from flushing cout before each input operation,
    // further optimizing I/O.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t; // Read the number of test cases
    while (t--) { // Loop through each test case
        solve(); // Call the solve function for each test case
    }

    return 0; // Indicate successful execution
}
```