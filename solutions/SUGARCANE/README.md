# [Sugarcane Juice Business (SUGARCANE)](https://www.codechef.com/problems/SUGARCANE)
- **Difficulty Rating**: 563
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to calculate the total profit earned by a sugarcane juice business. We are given the number of glasses of juice (`N`) sold. Each glass of juice is sold for 50 coins. There are three types of expenses associated with each glass:
1.  20% of the selling price for sugarcane.
2.  20% of the selling price for salt and mint.
3.  30% of the selling price for shop rent.

We need to output the total profit for `N` glasses for each test case.

## Intuition & Mathematical Observation

The core of this problem is to determine the profit earned per glass of sugarcane juice. Once we have the profit per glass, we can simply multiply it by the total number of glasses sold (`N`) to get the total profit.

Let's break down the costs and profit per glass:

1.  **Selling Price per glass**: 50 coins.

2.  **Expenses per glass**:
    *   **Sugarcane**: 20% of 50 coins = $0.20 \times 50 = 10$ coins.
    *   **Salt and Mint**: 20% of 50 coins = $0.20 \times 50 = 10$ coins.
    *   **Shop Rent**: 30% of 50 coins = $0.30 \times 50 = 15$ coins.

3.  **Total Expenses per glass**: Summing up all individual expenses:
    $10 \text{ (sugarcane)} + 10 \text{ (salt/mint)} + 15 \text{ (rent)} = 35$ coins.

4.  **Profit per glass**: This is the selling price minus the total expenses per glass:
    $50 \text{ (selling price)} - 35 \text{ (total expenses)} = 15$ coins.

Alternatively, we can calculate the total expense percentage first:
Total expense percentage = 20% (sugarcane) + 20% (salt/mint) + 30% (rent) = 70%.
This means 70% of the selling price goes towards expenses.
Therefore, the profit percentage is 100% (selling price) - 70% (expenses) = 30%.
Profit per glass = 30% of 50 coins = $0.30 \times 50 = 15$ coins.

Finally, for `N` glasses, the **Total Profit** will be:
Total Profit = Profit per glass $\times$ Number of glasses = $15 \times N$.

The solution directly implements this formula.

## Complexity Analysis

-   **Time Complexity**: $O(T)$
    *   The program reads `T` test cases.
    *   For each test case, it performs a constant number of operations: reading an integer `N`, performing one multiplication (`15 * N`), and printing an integer. These operations take constant time, $O(1)$.
    *   Since these $O(1)$ operations are repeated `T` times, the total time complexity is $O(T)$.

-   **Space Complexity**: $O(1)$
    *   The program uses a few integer variables (`T`, `N`, `profit`) to store input and calculated values. The memory required for these variables is constant and does not depend on the input size (`N` or `T`).
    *   Therefore, the space complexity is $O(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes most standard libraries

using namespace std; // Use the standard namespace

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases

    while (T--) { // Loop T times, decrementing T in each iteration
        int N;
        cin >> N; // Read the number of glasses sold for the current test case

        // Calculate the profit based on the derived formula:
        // Total income per glass = 50 coins.
        // Total expenses percentage = 20% (sugarcane) + 20% (salt/mint) + 30% (rent) = 70% of total income.
        // Profit percentage = 100% (total income) - 70% (total expenses) = 30% of total income.
        // Profit per glass = 30% of 50 coins = 0.30 * 50 = 15 coins.
        // Total profit for N glasses = 15 * N.
        int profit = 15 * N;

        cout << profit << "\n"; // Output the calculated profit followed by a newline
    }

    return 0; // Indicate successful execution
}
```