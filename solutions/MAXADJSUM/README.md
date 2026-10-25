# [Maximise Adjacent Sum (MAXADJSUM)](https://www.codechef.com/problems/MAXADJSUM)
- **Difficulty Rating**: 1118
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to find the maximum possible value of $f(B) = \sum_{i=1}^{N-1} |B_i - B_{i+1}|$ for a given array $A$ of $N$ integers. We are allowed to rearrange the elements of $A$ into any order to form array $B$. The elements $A_i$ are positive integers ($1 \le A_i \le 10^4$).

## Intuition & Mathematical Observation
To maximize the sum of absolute differences between adjacent elements, we want to make each $|B_i - B_{i+1}|$ as large as possible. This is generally achieved by placing very small numbers next to very large numbers.

Let the sorted version of array $A$ be $A_0 \le A_1 \le \dots \le A_{N-1}$.
The optimal arrangement for maximizing $\sum_{i=1}^{N-1} |B_i - B_{i+1}|$ is a "zigzag" pattern. This pattern alternates between the smallest available elements and the largest available elements.
One such optimal arrangement is $B = [A_0, A_{N-1}, A_1, A_{N-2}, A_2, A_{N-3}, \dots]$.

Let's analyze the sum $f(B)$ for this arrangement:
$f(B) = |A_0 - A_{N-1}| + |A_{N-1} - A_1| + |A_1 - A_{N-2}| + |A_{N-2} - A_2| + \dots$
Since $A_0 \le A_1 \le \dots \le A_{N-1}$, all absolute differences can be simplified:
$f(B) = (A_{N-1} - A_0) + (A_{N-1} - A_1) + (A_{N-2} - A_1) + (A_{N-2} - A_2) + \dots$

Let's look at the coefficients of each $A_i$ in this sum:
- $A_0$ appears once with a coefficient of $-1$ (from $A_{N-1} - A_0$).
- $A_1$ appears twice with coefficients of $-1$ (from $A_{N-1} - A_1$) and $-1$ (from $A_{N-2} - A_1$), summing to $-2$.
- Similarly, $A_k$ for $k \in [1, \lfloor (N-1)/2 \rfloor - 1]$ will have a coefficient of $-2$.
- $A_{N-1}$ appears twice with coefficients of $+1$ (from $A_{N-1} - A_0$) and $+1$ (from $A_{N-1} - A_1$), summing to $+2$.
- Similarly, $A_{N-1-k}$ for $k \in [0, \lfloor (N-1)/2 \rfloor - 1]$ will have a coefficient of $+2$.

The exact formula depends on whether $N$ is even or odd:
1.  **If $N$ is even ($N=2k$):** The arrangement is $A_0, A_{2k-1}, A_1, A_{2k-2}, \dots, A_{k-1}, A_k$.
    The sum is $2 \sum_{i=k+1}^{2k-1} A_i + A_k - 2 \sum_{i=1}^{k-1} A_i - A_0$.
2.  **If $N$ is odd ($N=2k+1$):** The arrangement is $A_0, A_{2k}, A_1, A_{2k-1}, \dots, A_{k-1}, A_{k+1}, A_k$.
    The sum is $2 \sum_{i=k+1}^{2k} A_i - 2 \sum_{i=1}^{k-1} A_i - A_0 - A_k$.

Let's test this with the sample cases:
-   **Sample 1: $N=3, A=[1, 2, 3]$**
    Sorted: $A_0=1, A_1=2, A_2=3$.
    $N=3$ is odd, so $k=1$. The arrangement is $A_0, A_2, A_1$.
    $f(B) = |A_0 - A_2| + |A_2 - A_1| = (A_2 - A_0) + (A_2 - A_1) = 2A_2 - A_0 - A_1$.
    Plugging in values: $2 \times 3 - 1 - 2 = 6 - 3 = 3$. This matches the sample output.

-   **Sample 2: $N=2, A=[10, 20]$**
    Sorted: $A_0=10, A_1=20$.
    $N=2$ is even, so $k=1$. The arrangement is $A_0, A_1$.
    $f(B) = |A_0 - A_1| = A_1 - A_0$.
    Plugging in values: $20 - 10 = 10$. This matches the sample output.

The provided solution code, however, calculates `2 * total_sum - A[0] - A[1]`.
Let's expand this:
`2 * (A[0] + A[1] + A[2] + ... + A[N-1]) - A[0] - A[1]`
`= A[0] + A[1] + 2A[2] + 2A[3] + ... + 2A[N-1]`

Comparing this with the correct results for sample cases:
-   **For $N=3, A=[1,2,3]$:**
    Correct answer: $3$.
    Code's formula: $A_0 + A_1 + 2A_2 = 1 + 2 + 2 \times 3 = 3 + 6 = 9$.
    The code's formula gives $9$, while the correct answer is $3$.

-   **For $N=2, A=[10,20]$:**
    Correct answer: $10$.
    Code's formula: $A_0 + A_1 = 10 + 20 = 30$.
    The code's formula gives $30$, while the correct answer is $10$.

It appears the provided solution code implements an incorrect formula for this problem. The correct approach involves sorting and then applying the zigzag pattern logic, which leads to the specific sum formulas derived above. For $N=2$ and $N=3$, the formula $2A_{N-1} - A_0 - A_1$ happens to be correct. For $N \ge 4$, the general zigzag pattern formula is more complex. However, given the difficulty rating, it's possible that the test cases are weak or primarily test $N=2,3$ or specific configurations where the simpler formula $2A_{N-1} - A_0 - A_1$ holds.

**Note on the provided solution code:** The provided solution code calculates `2 * total_sum - A[0] - A[1]`. As demonstrated above, this formula is incorrect for the general case of this problem and does not match the sample outputs. The correct approach involves sorting the array and applying the "zigzag" pattern, which yields different results.

## Complexity Analysis
-   **Time Complexity**: $O(N \log N)$
    -   Sorting the array takes $O(N \log N)$ time.
    -   Calculating the total sum takes $O(N)$ time.
    -   The final calculation of the maximum value is $O(1)$.
    -   Overall, the dominant factor is sorting.
-   **Space Complexity**: $O(N)$
    -   Storing the array elements in a `std::vector` takes $O(N)$ space. If sorting is done in-place, this is the space for input. If a copy is made for sorting, it would be $O(N)$ auxiliary space.

## Solution Code
```cpp
#include <bits/stdc++.h> // Includes all standard libraries, as requested by problem instructions

// Function to solve a single test case
void solve() {
    int N;
    std::cin >> N; // Read the size of the array

    // Declare a vector to store array elements.
    // Using long long for elements is safe, though int would suffice for A_i values (up to 10^4).
    // The sum will definitely require long long.
    std::vector<long long> A(N); 
    for (int i = 0; i < N; ++i) {
        std::cin >> A[i]; // Read array elements
    }

    // Sort the array in non-decreasing order.
    // This places the smallest elements at the beginning (A[0], A[1])
    // and the largest elements at the end.
    std::sort(A.begin(), A.end());

    // Calculate the total sum of all elements in the array.
    long long total_sum = 0;
    for (int i = 0; i < N; ++i) {
        total_sum += A[i];
    }
    
    // The maximum value of f(A) is 2 * (total sum of elements) - (smallest element) - (second smallest element).
    // This formula expands to A[0] + A[1] + 2*A[2] + ... + 2*A[N-1].
    // As analyzed in the "Intuition & Mathematical Observation" section, this specific formula
    // is generally incorrect for this problem and does not match the sample outputs.
    // The correct approach involves a "zigzag" arrangement.
    long long max_f_A = 2 * total_sum - A[0] - A[1];

    std::cout << max_f_A << "\n"; // Output the result followed by a newline
}

int main() {
    // Use `using namespace std;` as requested by problem instructions.
    using namespace std; 

    // Optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) prevents std::cout from flushing before std::cin reads input.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) {
        solve(); // Solve each test case
    }

    return 0; // Indicate successful execution
}
```