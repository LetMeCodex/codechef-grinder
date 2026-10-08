# [Christmas Cake (CRCK)](https://www.codechef.com/problems/CRCK)
- **Difficulty Rating**: 217
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem states that Chef bakes a practice cake every day from December 1st to December 24th. We are given the current day of December, denoted by $X$. We need to calculate the number of practice cakes Chef will bake starting from today ($X$-th of December) up to and including December 24th.

## Intuition & Mathematical Observation
The core of the problem is to count the number of days in a given range. The range of days Chef bakes practice cakes is from December 1st to December 24th. We are given that today is the $X$-th of December. We need to find the number of days from day $X$ to day 24, inclusive.

Let's consider a few examples:
- If today is December 1st ($X=1$), Chef bakes cakes on days 1, 2, ..., 24. The total number of cakes is 24.
- If today is December 20th ($X=20$), Chef bakes cakes on days 20, 21, 22, 23, 24. The total number of cakes is 5.
- If today is December 24th ($X=24$), Chef bakes a cake on day 24. The total number of cakes is 1.

The number of integers in a range $[a, b]$ (inclusive) is given by the formula $b - a + 1$.
In our case, the range of days is from $X$ to 24. So, $a = X$ and $b = 24$.
Therefore, the number of cakes Chef will bake starting from today is $24 - X + 1$.

## Complexity Analysis
- **Time Complexity**: $O(1)$
The solution involves a single arithmetic operation to calculate the number of cakes. This operation takes constant time, regardless of the input value of $X$.

- **Space Complexity**: $O(1)$
The solution uses a fixed amount of memory to store the input variable $X$ and the result. This amount of memory does not grow with the input size.

## Solution Code
```cpp
#include <iostream>

int main() {
    // Optimize C++ standard streams for competitive programming.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C stdio.
    // std::cin.tie(NULL) unties cin from cout, allowing cin to operate independently.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int x; // Variable to store the current day of December.
    std::cin >> x;

    // Christmas is on December 25th.
    // Chef bakes one practice cake every day from December 1st to December 24th.
    // Today is the X-th of December.
    // We need to find how many practice cakes Chef will bake starting from today.
    // This means we need to count the number of days from X to 24, inclusive.
    // The number of days in a range [a, b] inclusive is b - a + 1.
    // Here, a = X and b = 24.
    int cakes_to_bake = 24 - x + 1;

    // Output the calculated number of cakes.
    std::cout << cakes_to_bake << "\n";

    return 0; // Indicate successful execution.
}
```