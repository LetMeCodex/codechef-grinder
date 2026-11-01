# Chef and Pairing Slippers (CHEFSLP)
- **Difficulty Rating**: 930
- **Solved in**: 1 attempt(s)

## Problem Summary

Chef has a collection of $N$ slippers. He knows that $L$ of these slippers are left slippers, and the remaining $N-L$ are right slippers. Chef wants to form pairs of slippers, where each pair consists of one left slipper and one right slipper. He can sell each pair for $X$ rupees. The goal is to find the maximum amount of rupees Chef can earn by forming as many pairs as possible.

## Intuition & Mathematical Observation

The core of this problem lies in understanding how to maximize the number of pairs. A pair of slippers requires one left slipper and one right slipper. Therefore, the number of pairs Chef can form is limited by the minimum count of either left or right slippers available.

Let:
- $N$ be the total number of slippers.
- $L$ be the number of left slippers.
- $R$ be the number of right slippers.
- $X$ be the price Chef gets for each pair.

From the problem statement, we know that $R = N - L$.

The maximum number of pairs that can be formed is the minimum of the number of left slippers and the number of right slippers.
$$ \text{Maximum Pairs} = \min(L, R) $$
Substituting $R = N - L$:
$$ \text{Maximum Pairs} = \min(L, N - L) $$

Once we have the maximum number of pairs, the total amount of rupees Chef can earn is simply the maximum number of pairs multiplied by the price per pair ($X$).
$$ \text{Total Rupees} = \text{Maximum Pairs} \times X $$
$$ \text{Total Rupees} = \min(L, N - L) \times X $$

The problem involves multiple test cases, so we need to perform this calculation for each given set of $N$, $L$, and $X$.

## Complexity Analysis

- **Time Complexity**: $O(1)$ per test case.
    The solution involves a few arithmetic operations (subtraction, minimum, multiplication) and input/output operations. These operations take constant time. Since there are $T$ test cases, the total time complexity is $O(T)$. However, if we consider the complexity per test case, it is $O(1)$.

- **Space Complexity**: $O(1)$.
    The solution uses a fixed number of integer variables to store $N$, $L$, $X$, the number of right slippers, the maximum number of pairs, and the total rupees. The memory usage does not grow with the input size, making it constant.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes common headers like iostream and algorithm

// Using the standard namespace to avoid writing std:: repeatedly
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare an integer variable T for the number of test cases
    cin >> T; // Read the number of test cases

    // Loop T times, once for each test case
    while (T--) {
        int N, L, X; // Declare integer variables for N, L, and X
        cin >> N >> L >> X; // Read N, L, and X for the current test case

        // Calculate the number of right slippers.
        // Total slippers (N) - Left slippers (L) = Right slippers.
        int num_right_slippers = N - L;

        // The maximum number of pairs that can be formed is limited by the
        // minimum of available left slippers and available right slippers.
        int max_pairs = min(L, num_right_slippers);

        // Calculate the total amount of rupees Chef can get.
        // This is the maximum number of pairs multiplied by the price per pair (X).
        // The maximum possible value (500 * 1000 = 500,000) fits within an 'int'.
        int total_rupees = max_pairs * X;

        // Output the result for the current test case, followed by a newline.
        cout << total_rupees << "\n";
    }

    return 0; // Indicate successful program execution
}
```