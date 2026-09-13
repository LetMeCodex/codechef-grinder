# [Six Friends (SIXFRIENDS)](https://www.codechef.com/problems/SIXFRIENDS)
- **Difficulty Rating**: 382
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to find the minimum cost to accommodate six friends. We are given two options for booking rooms:
1.  **Double Room**: Accommodates exactly two people and costs `X` rupees.
2.  **Triple Room**: Accommodates exactly three people and costs `Y` rupees.

The problem statement explicitly states that we can *either* book three double rooms *or* two triple rooms to accommodate all six friends. We need to determine the minimum total cost between these two scenarios.

## Intuition & Mathematical Observation

The problem simplifies to comparing the total cost of two distinct accommodation strategies:

1.  **Strategy 1: Using only Double Rooms**
    *   Each double room accommodates 2 people.
    *   To accommodate 6 people, we need $6 \div 2 = 3$ double rooms.
    *   If each double room costs `X` rupees, the total cost for this strategy will be $3 \times X$.

2.  **Strategy 2: Using only Triple Rooms**
    *   Each triple room accommodates 3 people.
    *   To accommodate 6 people, we need $6 \div 3 = 2$ triple rooms.
    *   If each triple room costs `Y` rupees, the total cost for this strategy will be $2 \times Y$.

Since we are asked for the *minimum* amount of money Chef needs to spend, we simply need to calculate the total cost for each strategy and then choose the smaller of the two values.

**Mathematical Formula:**
Minimum Cost = $\min(3 \times X, 2 \times Y)$

This approach directly addresses the problem constraints and options provided.

## Complexity Analysis

*   **Time Complexity**: $O(T)$
    *   For each test case, the solution performs a constant number of operations: reading two integers, two multiplications, one comparison (`std::min`), and printing one integer.
    *   Let $C$ be this constant number of operations per test case. If there are $T$ test cases, the total time complexity will be $T \times C$, which simplifies to $O(T)$.

*   **Space Complexity**: $O(1)$
    *   The solution uses a fixed number of variables (`t`, `x`, `y`, `cost_double_rooms`, `cost_triple_rooms`, `min_cost`) regardless of the input values or the number of test cases.
    *   Therefore, the space required is constant, leading to an $O(1)$ space complexity.

## Solution Code

```cpp
#include <iostream> // Required for input/output operations (std::cin, std::cout)
#include <algorithm> // Required for std::min function

int main() {
    // Optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) prevents std::cout from being flushed before each std::cin operation.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; // Declare an integer variable 't' to store the number of test cases.
    std::cin >> t; // Read the number of test cases from standard input.

    while (t--) { // Loop 't' times, decrementing 't' in each iteration.
        long long x, y; // Declare two long long variables 'x' and 'y' for room costs.
                        // Using long long to handle potentially large costs, though int might suffice for this problem's constraints.
        std::cin >> x >> y; // Read the costs of a double room (x) and a triple room (y).

        // Calculate the total cost if three double rooms are booked.
        // Each double room accommodates 2 people, so 3 rooms accommodate 6 people.
        long long cost_double_rooms = 3 * x;

        // Calculate the total cost if two triple rooms are booked.
        // Each triple room accommodates 3 people, so 2 rooms accommodate 6 people.
        long long cost_triple_rooms = 2 * y;

        // Determine the minimum cost between the two options.
        long long min_cost = std::min(cost_double_rooms, cost_triple_rooms);

        // Print the minimum cost followed by a newline character.
        std::cout << min_cost << "\n";
    }

    return 0; // Indicate successful program execution.
}

```