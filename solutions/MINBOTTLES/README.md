# [Minimum Bottles (MINBOTTLES)](https://www.codechef.com/problems/MINBOTTLES)
- **Difficulty Rating**: 656
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to calculate the minimum number of bottles required to store a given amount of water. We are given $N$ bottles, each with a capacity of $X$ liters. We are also given the amount of water present in each of the $N$ bottles. We need to find the smallest number of bottles, each of capacity $X$, that can hold all the water from the given $N$ bottles.

## Intuition & Mathematical Observation
The core idea is to determine the total amount of water we need to store. Since we want to use the minimum number of bottles, we should fill each bottle to its maximum capacity ($X$ liters) as much as possible.

1.  **Calculate Total Water:** The first step is to sum up the amount of water present in all the $N$ given bottles. Let this total amount be `total_water`.

2.  **Determine Minimum Bottles:** Once we have the `total_water`, we need to find out how many bottles of capacity $X$ are needed to hold this amount. If `total_water` is perfectly divisible by $X$, then `total_water / X` bottles will suffice. However, if there's a remainder, it means we need an additional bottle to store the remaining water, even if it's not completely full. This is a classic ceiling division problem.

    For positive integers $A$ (total water) and $B$ (bottle capacity), the minimum number of bottles required is $\lceil \frac{A}{B} \rceil$.
    In integer arithmetic, ceiling division can be computed efficiently using the formula:
    $\lceil \frac{A}{B} \rceil = (A + B - 1) / B$

    Therefore, the minimum number of bottles will be `(total_water + X - 1) / X`.

## Complexity Analysis
- **Time Complexity**: $O(N)$
    The solution iterates through the $N$ bottles once to sum up the total water. The subsequent calculation for the minimum number of bottles is a constant time operation. Thus, the dominant factor is reading the $N$ inputs, making the time complexity $O(N)$ per test case.

- **Space Complexity**: $O(1)$
    The solution uses a few variables (`N`, `X`, `total_water`, `A_i`, `min_bottles`, `T`) to store the input values and intermediate results. The amount of memory used does not depend on the input size $N$. Therefore, the space complexity is constant, $O(1)$ per test case.

## Solution Code

```cpp
#include <iostream> // Required for standard input/output operations (cin, cout)

void solve() {
    int N; // Number of bottles
    int X; // Capacity of each bottle in liters
    std::cin >> N >> X;

    long long total_water = 0; // Variable to store the sum of water from all bottles.
                               // Using long long to be safe, although 'int' would suffice
                               // given the problem constraints (max total_water = 100 * 1000 = 100,000).

    // Read the amount of water in each bottle and sum it up.
    for (int i = 0; i < N; ++i) {
        int A_i; // Water in the i-th bottle
        std::cin >> A_i;
        total_water += A_i;
    }

    // To find the minimum number of bottles, we need to divide the total water
    // by the capacity of a single bottle and round up to the nearest integer.
    // This is known as ceiling division.
    // For positive integers 'a' and 'b', ceil(a / b) can be calculated using
    // integer division as (a + b - 1) / b.
    long long min_bottles = (total_water + X - 1) / X;

    // Output the result for the current test case, followed by a newline.
    std::cout << min_bottles << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) prevents cin from flushing cout before each input operation.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T; // Number of test cases
    std::cin >> T; // Read the number of test cases

    // Loop through each test case
    while (T--) {
        solve(); // Call the solve function for each test case
    }

    return 0; // Indicate successful execution
}
```