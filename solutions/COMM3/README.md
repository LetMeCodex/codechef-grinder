# [Three Way Communications (COMM3)](https://www.codechef.com/problems/COMM3)
- **Difficulty Rating**: 1083
- **Solved in**: 3 attempt(s)

## Problem Summary
The problem asks us to determine if three individuals, Chef, Server, and Sous-Chef, can all communicate with each other, given their 2D coordinates and a maximum communication range $R$. Communication is possible between two individuals if the distance between them is less than or equal to $R$. All three can communicate if for any pair that *cannot* communicate directly, there exists a third individual who can communicate with *both* members of that pair.

## Intuition & Mathematical Observation

The core of the problem lies in understanding the condition for "all three can communicate". Let's denote the positions of Chef, Server, and Sous-Chef as $C$, $S$, and $SC$ respectively, and the communication range as $R$.

Two individuals can communicate if the Euclidean distance between them is $\le R$. We are interested in the squared distance to avoid using `sqrt` and potential floating-point precision issues. So, distance squared $\le R^2$.

The condition "all three can communicate" can be rephrased as:
For any pair of individuals, if they cannot communicate directly, there must be a third individual who can act as an intermediary, connecting them.

Let's consider the pairs:
1. Chef and Server
2. Chef and Sous-Chef
3. Server and Sous-Chef

If Chef and Server cannot communicate directly (i.e., `distSq(C, S) > R^2`), then for all three to communicate, Sous-Chef must be able to communicate with *both* Chef and Server (i.e., `distSq(SC, C) <= R^2` AND `distSq(SC, S) <= R^2`).

Similarly:
- If Chef and Sous-Chef cannot communicate directly, Server must be able to communicate with both Chef and Sous-Chef.
- If Server and Sous-Chef cannot communicate directly, Chef must be able to communicate with both Server and Sous-Chef.

However, there's a simpler way to frame this. If any one person can communicate with the other two directly, then all three can communicate.
- If Chef can reach Server AND Chef can reach Sous-Chef, then Chef acts as a bridge.
- If Server can reach Chef AND Server can reach Sous-Chef, then Server acts as a bridge.
- If Sous-Chef can reach Chef AND Sous-Chef can reach Server, then Sous-Chef acts as a bridge.

If any of these conditions are met, then all three can communicate. If none of these conditions are met, it implies that no single person can bridge the communication gap for the other two.

Let's verify this logic.
Suppose Chef can reach Server (`distSq(C, S) <= R^2`) and Chef can reach Sous-Chef (`distSq(C, SC) <= R^2`).
- If Server and Sous-Chef can also communicate (`distSq(S, SC) <= R^2`), then everyone can communicate with everyone directly.
- If Server and Sous-Chef *cannot* communicate (`distSq(S, SC) > R^2`), Chef can still communicate with both of them. So, Chef can relay messages. For example, if Server wants to talk to Sous-Chef, Server talks to Chef, and Chef talks to Sous-Chef. This satisfies the condition.

Therefore, the condition simplifies to checking if any of the three individuals can reach the other two within the range $R$.

The three conditions to check are:
1. `distSq(Chef, Server) <= R^2` AND `distSq(Chef, SousChef) <= R^2`
2. `distSq(Server, Chef) <= R^2` AND `distSq(Server, SousChef) <= R^2`
3. `distSq(SousChef, Chef) <= R^2` AND `distSq(SousChef, Server) <= R^2`

If any of these three compound conditions are true, the answer is "yes". Otherwise, it's "no".

The `distSq` function calculates the squared Euclidean distance between two points $(x_1, y_1)$ and $(x_2, y_2)$ as $(x_1 - x_2)^2 + (y_1 - y_2)^2$.

## Complexity Analysis
- **Time Complexity**: For each test case, we perform a constant number of distance calculations and comparisons. Each distance calculation involves a few arithmetic operations. Therefore, the time complexity per test case is $O(1)$. Since there are $T$ test cases, the total time complexity is $O(T)$.

- **Space Complexity**: We use a few variables to store the coordinates of the three individuals and the communication range. The space used is independent of the input size (other than the number of test cases). Therefore, the space complexity is $O(1)$.

## Solution Code
```cpp
#include <iostream>
#include <cmath>
#include <vector>

// Structure to represent a point in 2D space
struct Point {
    long long x, y;
};

// Function to calculate squared Euclidean distance between two points
// Using squared distance avoids floating-point arithmetic and potential precision issues.
long long distSq(Point p1, Point p2) {
    long long dx = p1.x - p2.x;
    long long dy = p1.y - p2.y;
    return dx * dx + dy * dy;
}

int main() {
    // Optimize C++ standard streams for competitive programming
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T; // Number of test cases
    std::cin >> T;
    while (T--) {
        long long R; // Maximum communication range
        std::cin >> R;

        Point chef, server, souschef;
        // Read coordinates for Chef
        std::cin >> chef.x >> chef.y;
        // Read coordinates for Server
        std::cin >> server.x >> server.y;
        // Read coordinates for Sous-Chef
        std::cin >> souschef.x >> souschef.y;

        // Calculate the squared communication range for efficient comparison
        long long rSq = R * R;

        // Determine if all three can communicate.
        // This is true if any one person can communicate with the other two directly.
        // If Chef can reach both Server and Sous-Chef, they can communicate.
        // If Server can reach both Chef and Sous-Chef, they can communicate.
        // If Sous-Chef can reach both Chef and Server, they can communicate.

        bool possible = false;

        // Check if Chef can communicate with both Server and Sous-Chef
        if (distSq(chef, server) <= rSq && distSq(chef, souschef) <= rSq) {
            possible = true;
        }
        // Check if Server can communicate with both Chef and Sous-Chef
        // We use 'else if' here because if the first condition is true,
        // we already know the answer is "yes" and don't need to check further.
        // However, the logic is sound even with separate 'if' statements,
        // as 'possible' will just be set to true multiple times.
        // For clarity and slight optimization, we can use separate 'if's or 'else if's.
        // The current implementation with separate 'if's is also correct.
        if (distSq(server, chef) <= rSq && distSq(server, souschef) <= rSq) {
            possible = true;
        }
        // Check if Sous-Chef can communicate with both Chef and Server
        if (distSq(souschef, chef) <= rSq && distSq(souschef, server) <= rSq) {
            possible = true;
        }

        // Output the result for the current test case
        if (possible) {
            std::cout << "yes\n";
        } else {
            std::cout << "no\n";
        }
    }
    return 0;
}
```