# Small GCD Sort (P3209)
- **Difficulty Rating**: 1039
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to sort a sequence of numbers from 1 to $N$ based on a specific criterion. For each number $i$ from 1 to $N$, we need to calculate its "value" as the greatest common divisor (GCD) of $i$ and $N$, i.e., $\text{gcd}(i, N)$. The sorting should be done in descending order of these GCD values. If two numbers have the same GCD value, they should be sorted in ascending order of their original numbers (IDs). We need to output the sorted sequence of original numbers (IDs).

## Intuition & Mathematical Observation

The core of the problem lies in understanding how the GCD of $i$ and $N$ behaves for $i$ ranging from 1 to $N$.

1.  **GCD Property**: The value $\text{gcd}(i, N)$ will always be a divisor of $N$. This is a fundamental property of the GCD.
2.  **Possible GCD Values**: Therefore, the possible values for $\text{gcd}(i, N)$ are limited to the divisors of $N$.
3.  **Sorting Criterion**: We need to sort based on $\text{gcd}(i, N)$ in descending order. If $\text{gcd}(i, N) = \text{gcd}(j, N)$, then we sort by $i$ in ascending order.

Let's consider an example: $N=6$.
The numbers are 1, 2, 3, 4, 5, 6.
Their GCDs with 6 are:
- $\text{gcd}(1, 6) = 1$
- $\text{gcd}(2, 6) = 2$
- $\text{gcd}(3, 6) = 3$
- $\text{gcd}(4, 6) = 2$
- $\text{gcd}(5, 6) = 1$
- $\text{gcd}(6, 6) = 6$

The GCD values are: 1, 2, 3, 2, 1, 6.
The divisors of 6 are 1, 2, 3, 6.

Now, let's group the numbers by their GCD values:
- GCD = 6: {6}
- GCD = 3: {3}
- GCD = 2: {2, 4}
- GCD = 1: {1, 5}

We need to sort these groups in descending order of GCD values.
- Group with GCD 6: {6}
- Group with GCD 3: {3}
- Group with GCD 2: {2, 4}. Within this group, sort by ID ascending: {2, 4}.
- Group with GCD 1: {1, 5}. Within this group, sort by ID ascending: {1, 5}.

Combining these sorted groups, we get the final sorted sequence of IDs: 6, 3, 2, 4, 1, 5.

The intuition is to:
1.  For each number $i$ from 1 to $N$, calculate its GCD with $N$.
2.  Store pairs of (GCD value, original ID).
3.  Sort these pairs. The primary sorting key is the GCD value in descending order. The secondary sorting key is the original ID in ascending order.
4.  Extract the original IDs from the sorted pairs.

The provided C++ solution implements this directly. It creates a `Player` struct to hold `id` and `score` (which is `gcd(id, n)`). It then defines a custom comparison operator for `Player` that sorts by `score` (GCD) in descending order and `id` in ascending order for ties. Finally, it sorts a vector of `Player` objects and prints their IDs.

## Complexity Analysis

-   **Time Complexity**:
    -   Calculating GCD for each number from 1 to $N$: There are $N$ numbers, and calculating `std::gcd(i, n)` takes approximately $O(\log(\min(i, n)))$ time. In the worst case, this is $O(\log N)$. So, this step takes $O(N \log N)$.
    -   Sorting the $N$ players: The `std::sort` algorithm on a vector of size $N$ takes $O(N \log N)$ time. The comparison operation within the sort takes constant time.
    -   Printing the result: This takes $O(N)$ time.
    -   Overall, the dominant factor is the sorting and GCD calculation, leading to a time complexity of $O(N \log N)$.

-   **Space Complexity**:
    -   We store $N$ `Player` objects in a `std::vector`. Each `Player` object stores two integers.
    -   Therefore, the space complexity is $O(N)$.

## Solution Code

```cpp
#include <iostream>
#include <vector>
#include <numeric> // For std::gcd
#include <algorithm> // For std::sort

// Custom GCD function (though std::gcd is preferred and available in C++17)
// int gcd(int a, int b) {
//     return std::gcd(a, b);
// }

struct Player {
    int id;
    int score; // Represents gcd(id, n)

    // Custom comparison operator for sorting
    // Sorts primarily by score (GCD) in descending order.
    // If scores are equal, sorts by id in ascending order.
    bool operator<(const Player& other) const {
        if (score != other.score) {
            return score > other.score; // Higher score comes first
        }
        return id < other.id; // Smaller ID comes first for same score
    }
};

int main() {
    // Optimize C++ standard streams for competitive programming
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; // Number of test cases
    std::cin >> t;
    while (t--) {
        int n; // The input number
        std::cin >> n;

        std::vector<Player> players;
        players.reserve(n); // Reserve space for efficiency

        // Create Player objects for each number from 1 to n
        // The 'score' is the gcd of the player's id and n.
        for (int i = 1; i <= n; ++i) {
            players.push_back({i, std::gcd(i, n)});
        }

        // Sort the players vector using the custom comparison operator
        std::sort(players.begin(), players.end());

        // Print the sorted player IDs
        for (int i = 0; i < n; ++i) {
            std::cout << players[i].id << (i == n - 1 ? "" : " ");
        }
        std::cout << "\n";
    }

    return 0;
}
```