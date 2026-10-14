# [Selling Coins (SELLCOIN)](https://www.codechef.com/problems/SELLCOIN)
- **Difficulty Rating**: 218
- **Solved in**: 2 attempt(s)

## Problem Summary

Chef has `A` silver coins and `B` gold coins. He has the option to trade 1 gold coin for 2 silver coins. Each silver coin can be sold for Rs. 1. The problem asks us to calculate the maximum total money Chef can earn by selling his coins.

## Intuition & Mathematical Observation

The goal is to maximize the total money earned. Since each silver coin sells for Rs. 1, maximizing the total number of silver coins will directly maximize the total money.

Chef starts with `A` silver coins. He also has `B` gold coins. The crucial information is that 1 gold coin can be traded for 2 silver coins. This means that each gold coin effectively has a value equivalent to 2 silver coins.

To maximize the total silver coins, Chef should convert all his gold coins into silver coins.
*   From `A` initial silver coins, he gets `A` rupees.
*   From `B` gold coins, by trading each for 2 silver coins, he will obtain `B * 2` additional silver coins. These `B * 2` silver coins will then sell for `B * 2` rupees.

Therefore, the total number of silver coins Chef will have is `A + (B * 2)`. Since each silver coin sells for Rs. 1, the total money earned will be exactly this sum.

## Complexity Analysis

-   **Time Complexity**: $O(1)$
    The solution involves a fixed number of arithmetic operations (one multiplication and one addition) and a fixed number of input/output operations. These operations take constant time, regardless of the values of `A` and `B`.

-   **Space Complexity**: $O(1)$
    The solution uses a few integer variables (`A`, `B`, `total_silver_coins`) to store the input and the result. The amount of memory used does not depend on the magnitude of the input values, making the space complexity constant.

## Solution Code

```cpp
#include <iostream> // Using iostream for basic input/output

// Use the standard namespace to avoid writing std:: repeatedly
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin from cout and disables synchronization with C's stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Declare integer variables 'A' and 'B' for silver and gold coins.
    int A, B;
    // Read the values of A and B from standard input.
    // Assuming a single test case as 't' is not explicitly mentioned in the problem statement.
    cin >> A >> B;

    // Calculate the total number of silver coins Chef can obtain.
    // Chef starts with 'A' silver coins.
    // Each 'B' gold coin can be traded for 2 silver coins,
    // so 'B' gold coins yield 'B * 2' silver coins.
    // Total silver coins = initial silver coins + silver coins from gold trades.
    int total_silver_coins = A + (B * 2);

    // Since each silver coin sells for Rs. 1, the total money earned
    // is simply the total number of silver coins.
    // Output the total money earned, followed by a newline.
    cout << total_silver_coins << "\n";

    return 0; // Indicate successful program execution.
}
```