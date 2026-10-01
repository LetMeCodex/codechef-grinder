# Paper Cutting (CUTPAPER)
- **Difficulty Rating**: 800
- **Solved in**: 1 attempt(s)

## Problem Summary
Given a square piece of chart paper with side length $N$, we want to cut it into smaller squares of side length $K$. We need to find the maximum number of $K \times K$ squares that can be obtained from the $N \times N$ chart paper.

## Intuition & Mathematical Observation
Imagine the $N \times N$ chart paper as a grid. We want to fit as many $K \times K$ squares as possible within this grid.

Consider one dimension of the chart paper, which has length $N$. If we want to cut squares of side length $K$ along this dimension, we can fit $\lfloor \frac{N}{K} \rfloor$ segments of length $K$. For example, if $N=10$ and $K=3$, we can fit $10/3 = 3$ segments of length 3 along one side, with a remainder of 1 unit.

Since the chart paper is a square, both its width and height are $N$. Therefore, along the width, we can fit $\lfloor \frac{N}{K} \rfloor$ squares of side $K$. Similarly, along the height, we can also fit $\lfloor \frac{N}{K} \rfloor$ squares of side $K$.

The total number of $K \times K$ squares that can be cut from the $N \times N$ paper is the product of the number of squares that fit along the width and the number of squares that fit along the height. This is because we can form a grid of these smaller squares.

So, the total number of $K \times K$ squares is $\lfloor \frac{N}{K} \rfloor \times \lfloor \frac{N}{K} \rfloor$.

In integer arithmetic, the division operator `/` in C++ (and many other languages) performs floor division for positive numbers. Thus, `N / K` directly gives us $\lfloor \frac{N}{K} \rfloor$.

Therefore, the total number of squares is simply `(N / K) * (N / K)`.

## Complexity Analysis
- **Time Complexity**: $O(1)$
  The solution involves a few arithmetic operations (division and multiplication) and reading input. These operations take constant time, regardless of the input values of $N$ and $K$. The loop runs $T$ times, where $T$ is the number of test cases. So, for each test case, the time complexity is $O(1)$. The total time complexity for $T$ test cases is $O(T)$. However, if we consider the complexity per test case, it's $O(1)$.

- **Space Complexity**: $O(1)$
  The solution uses a fixed number of variables to store the input values ($T, N, K$) and intermediate results (`num_squares_per_side`, `total_squares`). The amount of memory used does not grow with the input size, hence it's constant space.

## Solution Code
```cpp
#include <bits/stdc++.h> // Required header for competitive programming

using namespace std; // Required namespace

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases

    while (T--) { // Loop T times, processing each test case
        int N, K;
        cin >> N >> K; // Read the side length of the chart paper (N) and the cutout squares (K)

        // Calculate how many K-length segments can fit along one side of length N.
        // Integer division automatically truncates, giving floor(N/K).
        int num_squares_per_side = N / K;

        // The total number of KxK squares is the product of the number of squares
        // that can fit along the width and the number that can fit along the height.
        int total_squares = num_squares_per_side * num_squares_per_side;

        cout << total_squares << "\n"; // Output the result for the current test case, followed by a newline
    }

    return 0; // Indicate successful execution
}
```