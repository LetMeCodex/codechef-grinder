# [Independence Day 101 (INDEPENDENCE)](https://www.codechef.com/problems/INDEPENDENCE)
- **Difficulty Rating**: 771
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine if it's possible to arrange a given number of colored strips of three different colors (say, Red, Green, Blue) such that no two adjacent strips have the same color. We are provided with the counts of strips for each of the three colors.

## Intuition & Mathematical Observation

Let the counts of the three colors be $A$, $B$, and $C$. To solve this problem, we need to find a condition under which such an arrangement is possible.

The key insight lies in considering the color with the maximum number of strips. Let this count be `max_count`. The sum of the counts of the other two colors will be `sum_others`.

To ensure no two strips of the `max_count` color are adjacent, they must be separated by strips of the other two colors. Imagine we have `max_count` strips of color 'M' (representing the most frequent color) and `sum_others` strips of other colors 'O'.

Consider placing all `sum_others` strips first. These `sum_others` strips create `sum_others + 1` possible "slots" where we can place the 'M' strips without them being adjacent to each other.
For example, if we have 3 'O' strips: `_ O _ O _ O _`
There are 4 slots (marked by `_`) where we can place 'M' strips.
In general, `s` 'O' strips create `s+1` slots.

Therefore, if the number of 'M' strips (`max_count`) exceeds the number of available slots (`sum_others + 1`), it's impossible to arrange them without two 'M' strips being adjacent.
Conversely, if `max_count <= sum_others + 1`, it is always possible to arrange the strips. We can achieve this by greedily placing an 'M' strip, then an 'O' strip (from either of the two less frequent colors), and repeating this process. Any remaining 'O' strips can be appended or inserted without violating the condition, as they are not the most frequent color.

So, the condition for a "YES" answer is:
`max_count <= sum_others + 1`

Let's illustrate with examples:
*   **Example 1**: Counts are (7, 3, 3).
    *   `max_count = 7` (from the color with 7 strips).
    *   `sum_others = 3 + 3 = 6`.
    *   Check condition: `7 <= 6 + 1` (which is `7 <= 7`). This is true. So, "YES".
    *   A possible arrangement: `A B A C A B A C A B A` (where A is the most frequent color).

*   **Example 2**: Counts are (8, 3, 3).
    *   `max_count = 8` (from the color with 8 strips).
    *   `sum_others = 3 + 3 = 6`.
    *   Check condition: `8 <= 6 + 1` (which is `8 <= 7`). This is false. So, "NO".
    *   Even if we try to intersperse: `A B A C A B A C A B A`. We've used 7 'A's and all 6 'B's and 'C's. We still have one 'A' left. No matter where we place it, it will be adjacent to another 'A'.

The solution involves:
1.  Reading the three counts.
2.  Sorting them to easily identify `max_count` (the largest) and `sum_others` (the sum of the two smallest).
3.  Applying the derived condition.

## Complexity Analysis

*   **Time Complexity**:
    The solution processes each test case independently. For each test case:
    1.  Reading three `long long` integers takes $O(1)$ time.
    2.  Storing them in a `std::vector` of size 3 takes $O(1)$ time.
    3.  Sorting a vector of 3 elements using `std::sort` takes $O(1)$ time (as it's a constant number of elements, the operations are fixed).
    4.  Performing arithmetic operations and comparisons takes $O(1)$ time.
    5.  Printing the result takes $O(1)$ time.
    Since each test case is processed in constant time, and there are $T$ test cases, the total time complexity is $O(T)$.

*   **Space Complexity**:
    For each test case, we use a few variables (`a`, `b`, `c`, `t`, `max_count`, `sum_others`) and a `std::vector` of size 3 (`counts`). All these consume a constant amount of memory regardless of the input values (within `long long` limits).
    Therefore, the space complexity is $O(1)$.

## Solution Code

```cpp
#include <iostream>
#include <algorithm> // Required for std::sort
#include <vector>    // Required for std::vector

int main() {
    // Optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams,
    // which can speed up I/O operations.
    // std::cin.tie(NULL) prevents std::cout from flushing before std::cin reads input,
    // further optimizing I/O in competitive programming contexts.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; // Number of test cases
    std::cin >> t;
    while (t--) {
        long long a, b, c; // Counts of the three colored strips
        std::cin >> a >> b >> c;

        // Store counts in a vector to easily sort them
        std::vector<long long> counts = {a, b, c};
        std::sort(counts.begin(), counts.end());

        // After sorting, counts[0] is the smallest, counts[1] is the middle, counts[2] is the largest.
        long long max_count = counts[2]; // The count of the most frequent color
        long long sum_others = counts[0] + counts[1]; // The sum of counts of the other two colors

        // The condition for being able to arrange the strips such that no two
        // adjacent strips have the same color is that the count of the most
        // frequent color must not be more than the sum of the counts of the
        // other two colors plus one.
        // This is because the 'sum_others' strips can create 'sum_others + 1'
        // possible positions where the 'max_count' strips can be placed
        // without being adjacent. If 'max_count' exceeds this, it's impossible.
        if (max_count <= sum_others + 1) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
    return 0;
}

```