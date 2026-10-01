# [Lucky Clover (LUCLO)](https://www.codechef.com/problems/LUCLO)
- **Difficulty Rating**: 236
- **Solved in**: 1 attempt(s)

## Problem Summary

Chef finds a total of $N$ clovers. Among these $N$ clovers, it is guaranteed that exactly one of them is a four-leaf clover, and all the remaining clovers are three-leaf clovers. The task is to calculate and output the total number of leaves Chef has collected.

## Intuition & Mathematical Observation

The problem statement provides a clear breakdown of the types of clovers Chef finds:
1.  **One four-leaf clover**: This clover contributes exactly 4 leaves to the total count.
2.  **Remaining clovers are three-leaf clovers**: If Chef found $N$ clovers in total and one of them is a four-leaf clover, then the number of remaining clovers is $N - 1$. Each of these $N - 1$ clovers is a three-leaf clover, meaning each contributes 3 leaves.

Therefore, the total number of leaves can be calculated by summing the leaves from the four-leaf clover and the leaves from all the three-leaf clovers:

*   Leaves from the four-leaf clover: $1 \times 4 = 4$
*   Leaves from the three-leaf clovers: $(N - 1) \times 3$

Total leaves = $4 + (N - 1) \times 3$

This formula directly gives the required answer.

## Complexity Analysis

*   **Time Complexity**: $O(1)$
    The solution involves reading a single integer $N$, performing a constant number of arithmetic operations (subtraction, multiplication, addition), and printing a single integer. All these operations take a fixed amount of time, regardless of the value of $N$. Hence, the time complexity is constant.

*   **Space Complexity**: $O(1)$
    The solution uses a few integer variables (`N`, `total_leaves`) to store the input and the calculated result. The memory usage does not grow with the input size $N$. Therefore, the space complexity is constant.

## Solution Code

```cpp
#include <bits/stdc++.h> // Required header for competitive programming, includes many standard libraries.

using namespace std; // Required to use standard library components without the std:: prefix.

int main() {
    // Optimize C++ standard streams for faster input/output operations.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; // Declare an integer variable N to store the number of clovers Chef found.
    cin >> N; // Read the integer N from standard input.

    // Calculate the total number of leaves.
    // According to the problem statement:
    // - Exactly one clover is a four-leaf clover, contributing 4 leaves.
    // - The remaining (N - 1) clovers are three-leaf clovers, each contributing 3 leaves.
    //
    // So, the total number of leaves is:
    // (Leaves from the four-leaf clover) + (Leaves from the three-leaf clovers)
    // = 4 + (N - 1) * 3
    int total_leaves = 4 + (N - 1) * 3;

    // Print the calculated total number of leaves to standard output.
    // A newline character "\n" is added at the end, as is standard practice in competitive programming.
    cout << total_leaves << "\n";

    return 0; // Indicate that the program executed successfully.
}
```