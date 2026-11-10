# Easy Math (RPD)
- **Difficulty Rating**: 1133
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to find the maximum sum of digits among all possible products of pairs of distinct elements from a given sequence of integers. We are given a sequence of $N$ integers, and we need to consider all pairs $(A_i, A_j)$ where $i \neq j$, calculate their product $A_i \times A_j$, and then find the sum of digits of this product. Our goal is to report the maximum such sum of digits encountered.

## Intuition & Mathematical Observation

The core of the problem lies in calculating the product of pairs and then summing their digits. The constraints on the input numbers ($A_i \le 10^4$) are important. The maximum possible product of two numbers would be $10^4 \times 10^4 = 10^8$. A standard 32-bit integer type (like `int` in C++) can comfortably store values up to approximately $2 \times 10^9$, so overflow is not a concern for the product calculation.

The sum of digits of a number is a straightforward operation. For a number $X$, we can repeatedly take the number modulo 10 to get the last digit and add it to a running sum, then divide the number by 10 to remove the last digit, until the number becomes 0.

Since we need to find the *maximum* sum of digits, we must iterate through all possible pairs of distinct elements. If the sequence has $N$ elements, there are $N \times (N-1) / 2$ unique pairs of distinct indices $(i, j)$ where $i < j$. For each such pair, we compute the product and its sum of digits, and keep track of the maximum sum found so far.

The problem statement explicitly mentions `using namespace std;`. While generally discouraged in larger projects for clarity and to avoid name collisions, it's often used in competitive programming for brevity. The provided solution adheres to this.

The `sum_digits` function is a helper function that takes an integer and returns the sum of its digits. It handles positive integers correctly. Since the input numbers are positive and their products will also be positive, this function is suitable.

The `solve` function reads the input sequence $A$ of size $N$. It then uses nested loops to iterate through all unique pairs of indices $(i, j)$ where $i < j$. For each pair, it calculates the product $A[i] \times A[j]$, calls `sum_digits` to get the sum of digits of the product, and updates `max_digit_sum` if the current sum is greater.

The `main` function handles multiple test cases. It includes standard competitive programming optimizations for I/O: `ios_base::sync_with_stdio(false);` and `cin.tie(NULL);`. This is crucial for performance in problems with large input sizes or many test cases.

## Complexity Analysis

- **Time Complexity**:
The dominant part of the algorithm is the nested loop that iterates through all pairs of elements. If there are $N$ elements in the sequence, the outer loop runs $N$ times, and the inner loop runs approximately $N$ times for each iteration of the outer loop. Specifically, for $i=0$, $j$ runs from $1$ to $N-1$ ($N-1$ iterations). For $i=1$, $j$ runs from $2$ to $N-1$ ($N-2$ iterations), and so on. The total number of pairs considered is $N(N-1)/2$, which is $O(N^2)$.
Inside the inner loop, we perform a multiplication and a call to `sum_digits`. The `sum_digits` function takes time proportional to the number of digits in the product. The maximum product is $10^8$, which has 9 digits. So, `sum_digits` takes $O(\log(\text{max_product}))$ time, which is a small constant in this context (effectively $O(1)$ for practical purposes given the constraints).
Therefore, the overall time complexity is dominated by the nested loops, resulting in $O(N^2)$.

- **Space Complexity**:
The solution uses a vector `A` to store the $N$ input integers. This requires $O(N)$ space.
The `sum_digits` function uses a few integer variables, which take $O(1)$ space.
The `solve` function uses a few integer variables (`N`, `max_digit_sum`, `product`, `current_digit_sum`), which also take $O(1)$ space.
The `main` function uses an integer `T` and a loop counter, taking $O(1)$ space.
Thus, the overall space complexity is $O(N)$ due to the storage of the input array.

## Solution Code

```cpp
#include <bits/stdc++.h> 

using namespace std; // Explicitly requested by problem instructions

// Function to calculate the sum of digits of a number
// Assumes n is non-negative. For this problem, products are always positive.
int sum_digits(int n) {
    int sum = 0;
    // The smallest product is 1*1 = 1, so n will always be > 0.
    while (n > 0) {
        sum += n % 10; // Add the last digit to the sum
        n /= 10;       // Remove the last digit
    }
    return sum;
}

void solve() {
    int N;
    cin >> N; // Read N, the number of elements in the sequence
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i]; // Read elements into vector A
    }

    int max_digit_sum = 0; // Initialize the maximum sum of digits found

    // Iterate through all unique pairs of indices (i, j) such that i < j
    // This ensures we pick two *different* elements from the sequence.
    // The values A[i] and A[j] can be the same, as long as their indices are different.
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            // Calculate the product of the two elements
            // A_i <= 10^4, so product <= 10^4 * 10^4 = 10^8.
            // An 'int' type in C++ is typically 32-bit, capable of storing values up to ~2*10^9,
            // so 10^8 fits comfortably without overflow.
            int product = A[i] * A[j];
            
            // Calculate the sum of digits of the product
            int current_digit_sum = sum_digits(product);
            
            // Update the maximum sum of digits found so far
            if (current_digit_sum > max_digit_sum) {
                max_digit_sum = current_digit_sum;
            }
        }
    }
    cout << max_digit_sum << "\n"; // Print the result for the current test case
}

int main() {
    // Optimize C++ standard streams for faster input/output operations.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) prevents std::cout from flushing before std::cin reads input.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) { // Loop T times for each test case
        solve(); // Solve a single test case
    }

    return 0;
}
```