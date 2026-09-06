# [Chef and Instant Noodles (INSTNOODLE)](https://www.codechef.com/problems/INSTNOODLE)
- **Difficulty Rating**: 456
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to calculate the total number of customers Chef can serve given a certain number of stoves and a time limit. Chef has `X` stoves. Each stove can cook 1 packet of noodles per minute. Each customer orders exactly 1 packet of noodles. We need to find out how many customers Chef can serve in `Y` minutes.

## Intuition & Mathematical Observation

Let's break down the cooking capacity:
1.  **Per stove**: Each stove cooks 1 packet per minute.
2.  **Per stove in `Y` minutes**: In `Y` minutes, a single stove can cook `1 * Y = Y` packets.
3.  **Total with `X` stoves in `Y` minutes**: If one stove can cook `Y` packets in `Y` minutes, then `X` stoves working simultaneously can cook `X * Y` packets in `Y` minutes.
4.  **Customers served**: Since each customer orders 1 packet, the total number of packets cooked directly translates to the total number of customers served.

Therefore, the total number of customers Chef can serve is simply the product of the number of stoves (`X`) and the time in minutes (`Y`).

The constraints are `1 <= X, Y <= 1000`. The maximum possible product `X * Y` would be `1000 * 1000 = 1,000,000`. This value fits comfortably within a standard 32-bit signed integer (which typically goes up to ~2 * 10^9). However, using `long long` for `X` and `Y` (and their product) is a good practice in competitive programming to prevent potential overflow issues in similar problems with larger constraints, even if not strictly necessary here.

## Complexity Analysis

*   **Time Complexity**: $O(1)$
    The solution involves reading two integer inputs and performing a single multiplication operation, followed by printing the result. These are constant-time operations, irrespective of the magnitude of `X` and `Y` (within typical integer limits).

*   **Space Complexity**: $O(1)$
    The solution uses a fixed amount of memory to store a few variables (`X`, `Y`, and the output buffer). The memory usage does not scale with the input values.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes common headers like iostream

int main() {
    // Fast I/O setup: Unties cin from C-style I/O and unties cin from cout.
    // This can speed up input/output operations, which is crucial in competitive programming.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long X, Y; // Declare X and Y as long long to safely store the product,
                    // even though int would suffice for given constraints.

    // Read the number of stoves (X) and the time in minutes (Y).
    if (std::cin >> X >> Y) {
        // Calculate the total packets cooked (which equals customers served)
        // and print the result followed by a newline.
        std::cout << (X * Y) << "\n";
    }

    return 0; // Indicate successful execution.
}

```