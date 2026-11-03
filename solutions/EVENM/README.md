# [Even Matrix (EVENM)](https://www.codechef.com/problems/EVENM)
- **Difficulty Rating**: 1376
- **Solved in**: 2 attempt(s)

## Problem Summary

The problem asks us to construct an $N \times N$ matrix. Each cell $(i, j)$ (1-indexed) must contain a unique integer from $1$ to $N^2$. The main condition is that for any two adjacent cells (sharing a side), the sum of their values must be even.

**Note on Problem Statement Interpretation**: The problem statement "for any two adjacent cells (sharing a side), the sum of their values must be even" implies that adjacent cells must have the *same parity* (e.g., both odd or both even). However, this condition makes the problem impossible for $N > 1$ because we need to use both odd and even numbers from $1$ to $N^2$, and if all cells had the same parity, it would require all numbers $1 \dots N^2$ to have the same parity. The provided solution code, which is a common pattern for such problems, implements a different logic: it ensures that adjacent cells have *different parities*. This is a standard "chessboard pattern" problem. We will proceed with explaining the solution based on the assumption that the problem *intended* to ask for adjacent cells to have **different parities**.

## Intuition & Mathematical Observation

Assuming the problem intends for adjacent cells to have **different parities** (i.e., one odd and one even), we can use a classic chessboard coloring pattern.

Consider a cell $(i, j)$ in the matrix (using 0-indexed coordinates for convenience, as in the code). We can classify cells based on the parity of the sum of their coordinates, $i+j$:
- If $i+j$ is even, we can call it a "white" square.
- If $i+j$ is odd, we can call it a "black" square.

A key property of this chessboard pattern is that any two adjacent cells (sharing a side) always have different "colors".
- If cell $(i, j)$ has an even sum $i+j$, its neighbors $(i, j \pm 1)$ and $(i \pm 1, j)$ will all have an odd sum of coordinates.
- Conversely, if cell $(i, j)$ has an odd sum $i+j$, its neighbors will all have an even sum of coordinates.

To ensure that adjacent cells have values with different parities, we can assign values based on this chessboard pattern:
1. All cells where $i+j$ is even will be assigned odd numbers.
2. All cells where $i+j$ is odd will be assigned even numbers.

This strategy guarantees that any two adjacent cells will consist of one cell assigned an odd value and another assigned an even value, thus satisfying the "different parities" condition.

We need to fill the matrix with unique integers from $1$ to $N^2$. The numbers $1, \dots, N^2$ contain $\lceil N^2/2 \rceil$ odd numbers and $\lfloor N^2/2 \rfloor$ even numbers.
Similarly, in an $N \times N$ matrix:
- The number of cells where $i+j$ is even is $\lceil N^2/2 \rceil$.
- The number of cells where $i+j$ is odd is $\lfloor N^2/2 \rfloor$.
Since these counts match, we have exactly enough odd numbers for the "even sum of indices" cells and enough even numbers for the "odd sum of indices" cells.

The algorithm would be:
1. Initialize `odd_val = 1` and `even_val = 2`.
2. Iterate through the matrix from $i=0$ to $N-1$ and $j=0$ to $N-1$.
3. For each cell $(i, j)$:
   - If $(i+j) \pmod 2 == 0$ (sum of indices is even), assign `matrix[i][j] = odd_val`, then increment `odd_val` by 2.
   - Else (sum of indices is odd), assign `matrix[i][j] = even_val`, then increment `even_val` by 2.
4. Print the constructed matrix.

**Example for N=3:**
Initial `odd_val = 1`, `even_val = 2`.

| (i,j) | i+j | Parity of i+j | Value assigned | `odd_val` | `even_val` |
|-------|-----|---------------|----------------|-----------|------------|
| (0,0) | 0   | Even          | 1              | 3         | 2          |
| (0,1) | 1   | Odd           | 2              | 3         | 4          |
| (0,2) | 2   | Even          | 3              | 5         | 4          |
| (1,0) | 1   | Odd           | 4              | 5         | 6          |
| (1,1) | 2   | Even          | 5              | 7         | 6          |
| (1,2) | 3   | Odd           | 6              | 7         | 8          |
| (2,0) | 2   | Even          | 7              | 9         | 8          |
| (2,1) | 3   | Odd           | 8              | 9         | 10         |
| (2,2) | 4   | Even          | 9              | 11        | 10         |

Resulting matrix for $N=3$:
```
1 2 3
4 5 6
7 8 9
```
Checking adjacent cells (e.g., (0,0) and (0,1)): values are 1 (odd) and 2 (even). They have different parities. This holds for all adjacent pairs.

## Complexity Analysis
- **Time Complexity**: The solution involves iterating through the $N \times N$ matrix twice: once to fill it with values and once to print it. Each cell operation (assignment or print) takes constant time. Therefore, the total time complexity is $O(N^2)$ for each test case.
- **Space Complexity**: An $N \times N$ matrix is used to store the values before printing. This requires $O(N^2)$ space.

## Solution Code

```cpp
#include <iostream>
#include <vector>
#include <numeric> // Not strictly needed for this solution, but often useful.

int main() {
    // Optimize C++ standard streams for faster input/output.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T; // Number of test cases
    std::cin >> T;
    while (T--) {
        int N; // Size of the matrix
        std::cin >> N;

        // Create an N x N matrix to store the results
        std::vector<std::vector<int>> matrix(N, std::vector<int>(N));

        // Initialize counters for odd and even numbers
        int odd_val = 1;
        int even_val = 2;

        // Fill the matrix based on the chessboard pattern
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                // Using 0-based indexing for matrix access.
                // The problem's logic (as implemented by this solution)
                // assigns values based on the parity of (row_idx + col_idx).
                // If (i + j) is even, it corresponds to one "color" on a chessboard.
                // If (i + j) is odd, it corresponds to the other "color".
                // By assigning odd numbers to one color and even numbers to the other,
                // we ensure adjacent cells have different parities.
                if ((i + j) % 2 == 0) { // Cells where sum of 0-indexed coordinates is even
                    matrix[i][j] = odd_val;
                    odd_val += 2; // Move to the next odd number
                } else { // Cells where sum of 0-indexed coordinates is odd
                    matrix[i][j] = even_val;
                    even_val += 2; // Move to the next even number
                }
            }
        }

        // Print the constructed matrix
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                std::cout << matrix[i][j] << (j == N - 1 ? "" : " "); // Print space after each number except the last
            }
            std::cout << "\n"; // Newline after each row
        }
    }
    return 0;
}

```