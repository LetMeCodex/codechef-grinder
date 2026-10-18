# [Sticks (STICKS)](https://www.codechef.com/problems/STICKS)
- **Difficulty Rating**: 1261
- **Solved in**: 1 attempt(s)

## Problem Summary
Given $N$ sticks, each with a certain length, we need to form a rectangle. A rectangle requires four sides. We can use sticks of the same length to form two sides of the rectangle. If we have at least two sticks of length $L_1$ and at least two sticks of length $L_2$, we can form a rectangle with sides $L_1$ and $L_2$. The goal is to find the maximum possible area of such a rectangle. If it's impossible to form a rectangle, we should output -1.

## Intuition & Mathematical Observation

To form a rectangle, we need two pairs of sticks of equal length. Let these lengths be $L_1$ and $L_2$. The area of the rectangle formed would be $L_1 \times L_2$. To maximize the area, we should aim to use the longest possible sticks.

Consider the available stick lengths and their counts.
If we have $k$ sticks of length $L$, we can form $\lfloor k/2 \rfloor$ pairs of sticks of length $L$.

We are looking for two distinct lengths, say $L_a$ and $L_b$, such that we have at least two sticks of length $L_a$ and at least two sticks of length $L_b$. The area would be $L_a \times L_b$. To maximize this product, we should pick the two largest possible lengths for which we have at least two sticks.

Let's refine this. Suppose we have the following counts of sticks:
- Length $L_1$: $c_1$ sticks
- Length $L_2$: $c_2$ sticks
- Length $L_3$: $c_3$ sticks
... and so on, sorted in descending order of length.

From length $L_i$, we can contribute $\lfloor c_i/2 \rfloor$ pairs of sticks.
We need to select two lengths, say $L_a$ and $L_b$, such that the total number of pairs we can form from all available sticks allows us to pick one pair of length $L_a$ and one pair of length $L_b$.

A simpler approach is to identify all lengths for which we have at least two sticks.
If a length $L$ appears $k$ times:
- If $k \ge 2$, we can form one pair of length $L$.
- If $k \ge 4$, we can form two pairs of length $L$. This means we can use length $L$ as *both* sides of a square (which is a special type of rectangle).

So, we can iterate through the given stick lengths and count their frequencies. For each length $L$ with frequency $f$:
- If $f \ge 2$, we can use $L$ as one side of a rectangle.
- If $f \ge 4$, we can use $L$ as *both* sides of a rectangle (i.e., a square). This means we can add $L$ to our list of potential side lengths *twice*.

After collecting all possible side lengths (a length $L$ is added once if its count is $\ge 2$, and twice if its count is $\ge 4$), we will have a list of lengths that can form at least one side of a rectangle. To maximize the area, we should pick the two largest lengths from this list. If this list has fewer than two elements, it's impossible to form a rectangle.

Example:
Sticks: [1, 1, 2, 2, 3, 3, 3, 3, 4, 4]
Counts:
- 1: 2
- 2: 2
- 3: 4
- 4: 2

Possible side lengths:
- Length 1: count is 2 ($\ge 2$), so add 1 to potential sides.
- Length 2: count is 2 ($\ge 2$), so add 2 to potential sides.
- Length 3: count is 4 ($\ge 4$), so add 3 *twice* to potential sides.
- Length 4: count is 2 ($\ge 2$), so add 4 to potential sides.

Potential side lengths list: [1, 2, 3, 3, 4]
Sorted in descending order: [4, 3, 3, 2, 1]

We need two sides for a rectangle. The two largest available lengths are 4 and 3.
Maximum area = $4 \times 3 = 12$.

Example 2:
Sticks: [5, 5, 5, 5, 5, 5]
Counts:
- 5: 6

Possible side lengths:
- Length 5: count is 6 ($\ge 4$), so add 5 *twice* to potential sides.

Potential side lengths list: [5, 5]
Sorted in descending order: [5, 5]

We need two sides. The two largest available lengths are 5 and 5.
Maximum area = $5 \times 5 = 25$.

Example 3:
Sticks: [1, 2, 3, 4, 5]
Counts:
- 1: 1
- 2: 1
- 3: 1
- 4: 1
- 5: 1

Possible side lengths:
No length has a count $\ge 2$.
Potential side lengths list: []
Cannot form a rectangle. Output -1.

The strategy is:
1. Count the frequency of each stick length.
2. Create a list of potential side lengths. For each length $L$ with frequency $f$:
   - If $f \ge 2$, add $L$ to the list.
   - If $f \ge 4$, add $L$ to the list again.
3. Sort this list of potential side lengths in descending order.
4. If the list has fewer than 2 elements, output -1.
5. Otherwise, the maximum area is the product of the first two elements in the sorted list.

## Complexity Analysis

- **Time Complexity**:
    - Reading input and counting frequencies: We iterate through $N$ sticks. Using a `std::map` for counts, insertion/access takes $O(\log K)$ where $K$ is the number of distinct stick lengths. In the worst case, $K=N$. So, this step is $O(N \log N)$.
    - Populating the `sides` vector: We iterate through the map. The number of entries in the map is at most $N$. For each entry, we might add the length once or twice. This step is $O(K)$, which is at most $O(N)$.
    - Sorting the `sides` vector: Let $M$ be the number of elements in the `sides` vector. In the worst case, each distinct length appears 4 times, so $M$ can be up to $4 \times K$. Since $K \le N$, $M \le 4N$. Sorting takes $O(M \log M)$. Substituting $M \approx 4N$, this becomes $O(4N \log(4N)) = O(N \log N)$.
    - The dominant factor is the sorting and frequency counting.
    - Therefore, the overall time complexity is $O(N \log N)$.

- **Space Complexity**:
    - `std::map<int, int> counts`: Stores the frequency of distinct stick lengths. In the worst case, all $N$ sticks have different lengths, so the map can store up to $N$ entries. This is $O(N)$.
    - `std::vector<int> sides`: Stores the potential side lengths. In the worst case, if all $N$ sticks have the same length and $N$ is a multiple of 4, we could add this length up to $N/2$ times. If $N$ distinct lengths each have count 4, we could have $4N$ entries. However, the number of distinct lengths $K \le N$. If each of the $K$ distinct lengths has a count of at least 4, we add $2K$ elements to `sides`. If each of the $K$ distinct lengths has a count of at least 2 but less than 4, we add $K$ elements. The total number of elements in `sides` is at most $2 \times (\text{number of distinct lengths}) \le 2N$. So, this is $O(N)$.
    - Therefore, the overall space complexity is $O(N)$.

## Solution Code

```cpp
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

int main() {
    // Optimize C++ standard streams for competitive programming
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; // Number of test cases
    std::cin >> t;
    while (t--) {
        int n; // Number of sticks
        std::cin >> n;

        // Use a map to store the frequency of each stick length.
        // Key: stick length, Value: count of sticks with that length.
        std::map<int, int> counts;
        for (int i = 0; i < n; ++i) {
            int a; // Length of a stick
            std::cin >> a;
            counts[a]++; // Increment the count for this length
        }

        // This vector will store lengths that can be used as sides of a rectangle.
        // A length L is added once if its count is >= 2.
        // A length L is added twice if its count is >= 4 (allowing for a square).
        std::vector<int> sides;
        for (auto const& [length, count] : counts) {
            if (count >= 2) {
                sides.push_back(length); // Can form at least one pair
                if (count >= 4) {
                    sides.push_back(length); // Can form a second pair (for a square)
                }
            }
        }

        // To maximize the area, we need the two largest possible side lengths.
        // Sort the 'sides' vector in descending order.
        std::sort(sides.rbegin(), sides.rend());

        // If we have fewer than 2 potential side lengths, we cannot form a rectangle.
        if (sides.size() < 2) {
            std::cout << -1 << "\n";
        } else {
            // The maximum area is the product of the two largest side lengths.
            // Use long long to prevent potential integer overflow for large areas.
            long long max_area = (long long)sides[0] * sides[1];
            std::cout << max_area << "\n";
        }
    }
    return 0;
}
```