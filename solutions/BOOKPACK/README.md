# [Packing Books (BOOKPACK)](https://www.codechef.com/problems/BOOKPACK)
- **Difficulty Rating**: 775
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to calculate the minimum total number of boxes required to pack books. We are given three integers:
*   $X$: The number of shelves.
*   $Y$: The number of books on each shelf.
*   $Z$: The maximum number of books a single box can hold.

A crucial constraint is that books from different shelves cannot be placed in the same box. We need to find the overall minimum number of boxes needed to pack all books from all shelves.

## Intuition & Mathematical Observation

The key to solving this problem lies in understanding the constraint: "books from different shelves cannot be placed in the same box." This immediately simplifies the problem significantly. It means that the packing process for each of the $X$ shelves is entirely independent. We cannot optimize by sharing boxes across shelves. Therefore, the total minimum number of boxes will simply be the number of shelves ($X$) multiplied by the minimum number of boxes required for a *single* shelf.

Now, let's focus on determining the minimum number of boxes for a single shelf.
A single shelf contains $Y$ books. Each box can hold a maximum of $Z$ books. To minimize the number of boxes, we should fill each box to its maximum capacity $Z$. This is a classic ceiling division problem: we need $\lceil \frac{Y}{Z} \rceil$ boxes.

In integer arithmetic, the ceiling division $\lceil \frac{A}{B} \rceil$ can be efficiently calculated using the formula: $(A + B - 1) / B$.
Let's verify this formula with a few examples:
*   **Example 1**: If $Y=9$ books and $Z=9$ books/box.
    *   Mathematically: $\lceil \frac{9}{9} \rceil = 1$ box.
    *   Using formula: $(9 + 9 - 1) / 9 = 17 / 9 = 1$ (integer division). Correct.
*   **Example 2**: If $Y=9$ books and $Z=7$ books/box.
    *   Mathematically: $\lceil \frac{9}{7} \rceil = 2$ boxes (one box with 7 books, another with 2 books).
    *   Using formula: $(9 + 7 - 1) / 7 = 15 / 7 = 2$ (integer division). Correct.
*   **Example 3**: If $Y=3$ books and $Z=2$ books/box.
    *   Mathematically: $\lceil \frac{3}{2} \rceil = 2$ boxes (one box with 2 books, another with 1 book).
    *   Using formula: $(3 + 2 - 1) / 2 = 4 / 2 = 2$ (integer division). Correct.

So, the minimum number of boxes required for one shelf is `(Y + Z - 1) / Z`.
Since there are $X$ such shelves, and their packing is independent, the total minimum number of boxes will be $X \times \left( \frac{Y + Z - 1}{Z} \right)$.

The maximum values for $X, Y, Z$ are 1000.
The maximum number of boxes per shelf would occur when $Y=1000$ and $Z=1$, which is $(1000 + 1 - 1) / 1 = 1000$.
The maximum total number of boxes would then be $X \times (\text{boxes per shelf}) = 1000 \times 1000 = 1,000,000$. This value fits comfortably within a standard 32-bit integer type (`int`). However, using `long long` for the final product is a good practice in competitive programming to prevent potential overflow, especially if constraints were slightly larger.

## Complexity Analysis

*   **Time Complexity**: $O(T)$
    For each test case, the solution involves reading three integers ($X, Y, Z$) and performing a constant number of basic arithmetic operations (addition, subtraction, division, multiplication). These operations take constant time. Since there are $T$ test cases, the total time complexity is directly proportional to the number of test cases, hence $O(T)$.

*   **Space Complexity**: $O(1)$
    The solution uses a fixed number of variables to store $X, Y, Z$, `boxes_per_shelf`, and `total_boxes`. The amount of memory used does not depend on the input values or their magnitude. Therefore, the space complexity is constant, $O(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Required include for competitive programming, includes most standard libraries

using namespace std; // Required to use standard library components without the std:: prefix

void solve() {
    int X, Y, Z;
    cin >> X >> Y >> Z; // Read the three integers X, Y, Z for the current test case

    // Calculate the minimum number of boxes needed for a single shelf.
    // Each shelf has Y books. Each box can hold at most Z books.
    // To minimize boxes, we fill each box to its maximum capacity Z.
    // This is equivalent to calculating ceil(Y / Z).
    // In integer arithmetic, ceil(A / B) can be efficiently calculated as (A + B - 1) / B.
    // For example:
    // If Y=9, Z=9: (9 + 9 - 1) / 9 = 17 / 9 = 1 box.
    // If Y=9, Z=7: (9 + 7 - 1) / 7 = 15 / 7 = 2 boxes (one with 7, one with 2).
    // If Y=3, Z=2: (3 + 2 - 1) / 2 = 4 / 2 = 2 boxes (one with 2, one with 1).
    int boxes_per_shelf = (Y + Z - 1) / Z;

    // The problem states that books from different shelves cannot be placed in the same box.
    // This means that the packing for each of the X shelves is independent.
    // Therefore, the total minimum number of boxes is simply the number of shelves (X)
    // multiplied by the minimum number of boxes required for a single shelf (boxes_per_shelf).

    // The maximum possible value for X, Y, Z is 1000.
    // Maximum boxes_per_shelf = (1000 + 1 - 1) / 1 = 1000 (when Y=1000, Z=1).
    // Maximum total_boxes = X * boxes_per_shelf = 1000 * 1000 = 1,000,000.
    // This value fits comfortably within a standard 32-bit integer type (int).
    // However, it's a good practice in competitive programming to use 'long long' for results
    // of multiplications to prevent potential overflow, especially if constraints were slightly larger.
    long long total_boxes = (long long)X * boxes_per_shelf;

    cout << total_boxes << "\n"; // Output the result followed by a newline
}

int main() {
    // Optimize C++ standard streams for faster input/output operations.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) { // Loop T times, decrementing T in each iteration
        solve(); // Call the solve function for each test case
    }

    return 0; // Indicate successful execution
}
```