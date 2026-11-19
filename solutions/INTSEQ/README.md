# [An Interesting Sequence (INTSEQ)](https://www.codechef.com/problems/INTSEQ)
- **Difficulty Rating**: 1393
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to find the maximum possible length $N$ of an "interesting sequence" for a given integer $K$. An interesting sequence $A_1, A_2, \dots, A_N$ is defined such that $A_i = K / 2^i$ for all $1 \le i \le N$, and all $A_i$ must be integers.

## Intuition & Mathematical Observation
For $A_i = K / 2^i$ to be an integer, it implies that $K$ must be perfectly divisible by $2^i$.
If $K$ is divisible by $2^i$, it must also be divisible by all smaller powers of 2, i.e., $2^{i-1}, 2^{i-2}, \dots, 2^1$.
Therefore, the condition that all $A_1, A_2, \dots, A_N$ are integers simplifies to finding the largest $N$ such that $K$ is divisible by $2^N$.

This is equivalent to finding the exponent of 2 in the prime factorization of $K$. In simpler terms, we need to count how many times $K$ can be successively divided by 2 until it becomes an odd number.

Let's take an example:
If $K = 12$:
- $A_1 = 12 / 2^1 = 12 / 2 = 6$ (integer)
- $A_2 = 12 / 2^2 = 12 / 4 = 3$ (integer)
- $A_3 = 12 / 2^3 = 12 / 8 = 1.5$ (not an integer)
So, the maximum length $N$ is 2.

Our algorithm would work as follows:
1. Initialize a `count` variable to 0.
2. While $K$ is even (i.e., $K \pmod 2 == 0$):
   a. Divide $K$ by 2 ($K = K / 2$).
   b. Increment `count`.
3. The final value of `count` is the maximum length $N$.

If $K$ is initially odd (e.g., $K=7$), the loop condition ($K \pmod 2 == 0$) will be false immediately, and `count` will remain 0. This is correct because $A_1 = 7/2 = 3.5$ is not an integer, so an interesting sequence of length 1 cannot be formed.

## Complexity Analysis
- **Time Complexity**: The `while` loop repeatedly divides `K` by 2 until `K` becomes odd. The number of divisions is equal to the number of factors of 2 in `K`, which is $\log_2 K$. Since $K$ can be up to $10^9$, $\log_2 10^9 \approx 30$. This means the loop runs at most about 30 times for each test case. Thus, the time complexity per test case is $O(\log K)$. For $T$ test cases, the total time complexity is $O(T \log K)$.
- **Space Complexity**: The solution uses a few integer variables (`T`, `K`, `count`) to store input and intermediate results. These variables occupy a constant amount of memory regardless of the input value of $K$. Therefore, the space complexity is $O(1)$.

## Solution Code
```cpp
#include <bits/stdc++.h> // Includes iostream and other standard libraries

// It's generally good practice to avoid 'using namespace std;' in headers or large projects,
// but for competitive programming, it's common and accepted for brevity.
using namespace std; 

int main() {
    // Fast I/O setup to speed up input and output operations.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Variable to store the number of test cases.
    cin >> T; // Read the number of test cases.

    // Loop through each test case.
    while (T--) {
        int K; // Variable to store the input integer K for the current test case.
               // K up to 10^9 fits comfortably within a standard 32-bit signed int.
        cin >> K; // Read the value of K.

        int count = 0; // This variable will store the maximum length of the interesting sequence.
                       // It effectively counts the number of times K can be divided by 2.

        // The core logic: find the largest N such that K is divisible by 2^N.
        // This is done by repeatedly dividing K by 2 as long as K is even.
        // Each successful division increments the count.
        //
        // If K is initially odd (e.g., K=1, K=3, K=5), the loop condition (K % 2 == 0)
        // will be false from the start. 'count' will remain 0, which is correct
        // because an odd K cannot form an interesting sequence of length 1 (A_1 = K/2 would not be an integer).
        //
        // The condition K > 0 is technically redundant given the problem constraint 1 <= K,
        // as K will become 1 (an odd number) before it becomes 0. However, it does no harm.
        while (K > 0 && K % 2 == 0) {
            K /= 2;        // Divide K by 2.
            count++;       // Increment the count for each power of 2 found.
        }
        
        // Print the calculated maximum length for the current test case, followed by a newline.
        cout << count << "\n";
    }

    return 0; // Indicate successful execution.
}
```