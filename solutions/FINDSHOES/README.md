# Finding Shoes (FINDSHOES)
- **Difficulty Rating**: 646
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef wants to buy shoes for $N$ friends. Each friend needs one left shoe and one right shoe. Chef already has $M$ left shoes. He needs to buy the minimum number of additional shoes to ensure each of his $N$ friends gets a pair of shoes.

## Intuition & Mathematical Observation
The problem asks for the minimum number of *additional* shoes Chef needs to buy.

1.  **Right Shoes**: Chef starts with 0 right shoes. Since he needs to provide a pair for each of his $N$ friends, he will always need to buy $N$ right shoes.

2.  **Left Shoes**: Chef needs $N$ left shoes in total for his $N$ friends. He already possesses $M$ left shoes.
    *   If $M \ge N$, Chef has enough (or more than enough) left shoes. He doesn't need to buy any additional left shoes.
    *   If $M < N$, Chef needs $N - M$ more left shoes.

3.  **Total Additional Shoes**: The total minimum number of additional shoes to buy is the sum of the additional left shoes needed and the right shoes needed.

    Let $L_{buy}$ be the number of left shoes to buy and $R_{buy}$ be the number of right shoes to buy.
    $R_{buy} = N$ (since Chef starts with 0 right shoes).
    $L_{buy} = \max(0, N - M)$ (Chef buys left shoes only if he has fewer than $N$).

    Total additional shoes = $L_{buy} + R_{buy} = \max(0, N - M) + N$.

## Complexity Analysis
- **Time Complexity**: $O(1)$
    The solution involves a fixed number of arithmetic operations and comparisons for each test case. The input reading and output printing are also constant time per test case. Since the number of test cases $T$ is read first, and the operations inside the loop are constant, the overall time complexity is dominated by reading the input, which is $O(T)$. However, for a single test case, the operations are $O(1)$.

- **Space Complexity**: $O(1)$
    The solution uses a fixed number of integer variables ($T, N, M, left\_shoes\_to\_buy, right\_shoes\_to\_buy, total\_extra\_shoes$) regardless of the input size. Therefore, the space complexity is constant.

## Solution Code
```cpp
#include <bits/stdc++.h> // Includes iostream for input/output and algorithm for max()
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare an integer variable T for the number of test cases.
    cin >> T; // Read the number of test cases from standard input.

    // Loop T times, once for each test case.
    while (T--) {
        int N, M; // Declare integer variables N and M for each test case.
        cin >> N >> M; // Read N (number of friends) and M (left shoes Chef has).

        // Calculate the number of left shoes Chef needs to buy.
        // If M < N, Chef needs N - M more left shoes.
        // If M >= N, Chef has enough left shoes, so he needs to buy 0 more.
        int left_shoes_to_buy = max(0, N - M);

        // Chef always needs to buy N right shoes, as he starts with none.
        int right_shoes_to_buy = N;

        // The total minimum number of extra shoes to buy is the sum of
        // left shoes to buy and right shoes to buy.
        int total_extra_shoes = left_shoes_to_buy + right_shoes_to_buy;

        // Output the result for the current test case, followed by a newline.
        cout << total_extra_shoes << "\n";
    }

    return 0; // Indicate successful program execution.
}
```