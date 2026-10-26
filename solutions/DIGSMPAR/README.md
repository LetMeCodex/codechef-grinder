# [Digit Sum Parities (DIGSMPAR)](https://www.codechef.com/problems/DIGSMPAR)
- **Difficulty Rating**: 1077
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to find the smallest integer $X$ strictly greater than a given integer $N$ such that the parity of the sum of digits of $N$ is different from the parity of the sum of digits of $X$.
We are given $T$ test cases, and for each test case, an integer $N$ ($1 \le N \le 10^9$).

## Intuition & Mathematical Observation
The core of this problem lies in understanding how the sum of digits changes when an integer is incremented, and specifically, how its parity changes. Let $S(k)$ denote the sum of digits of an integer $k$. We are looking for the smallest $X > N$ such that $S(X) \pmod 2 \neq S(N) \pmod 2$.

Let's analyze the change in $S(k)$ when $k$ becomes $k+1$:

1.  **If the last digit of $k$ is not 9 (i.e., $k$ ends in $0, 1, \dots, 8$)**:
    For example, if $k=123$, then $k+1=124$.
    $S(k) = 1+2+3 = 6$.
    $S(k+1) = 1+2+4 = 7$.
    In this case, $S(k+1) = S(k) + 1$. This means $S(k+1) \pmod 2 \neq S(k) \pmod 2$. The parity of the digit sum flips.

2.  **If the last digit of $k$ is 9**:
    This case is more nuanced. When $k$ ends in one or more 9s, incrementing $k$ causes a "carry-over" operation.
    Let $k$ end in $p$ nines. For example, $k = \dots D99\dots9$ (where $D$ is a digit not equal to 9, and there are $p$ nines).
    Then $k+1 = \dots (D+1)00\dots0$ (with $p$ zeros).
    The sum of digits $S(k)$ includes $D + 9p$.
    The sum of digits $S(k+1)$ includes $(D+1)$. The $p$ nines are replaced by $p$ zeros, and the digit $D$ is effectively incremented to $D+1$.
    The change in sum of digits is $S(k+1) - S(k) = (S(\text{prefix before } D) + (D+1)) - (S(\text{prefix before } D) + D + 9p) = 1 - 9p$.
    The parity of this change is $(1 - 9p) \pmod 2$. Since $9p \pmod 2 = p \pmod 2$, the parity change is $(1 - p) \pmod 2$.

    -   If $p$ (number of trailing 9s) is **even** (e.g., $p=0$ (no trailing 9s, covered by case 1), $p=2$ (ends in `...X99`), $p=4$ (ends in `...X9999`)):
        The parity change is $(1 - \text{even}) \pmod 2 = 1 \pmod 2$. The parity of the digit sum flips.
        Example: $k=1299$ ($p=2$, even). $S(k)=21$ (odd). $k+1=1300$. $S(k+1)=4$ (even). Parity flips.

    -   If $p$ (number of trailing 9s) is **odd** (e.g., $p=1$ (ends in `...X9`), $p=3$ (ends in `...X999`)):
        The parity change is $(1 - \text{odd}) \pmod 2 = 0 \pmod 2$. The parity of the digit sum remains the same.
        Example: $k=129$ ($p=1$, odd). $S(k)=12$ (even). $k+1=130$. $S(k+1)=4$ (even). Parity stays the same.

**Conclusion from Observation**:
The parity of the digit sum $S(k)$ flips when $k$ is incremented to $k+1$, *unless* $k$ ends in an odd number of 9s.

Now, let's apply this to find $X$:
1.  We calculate $S(N) \pmod 2$.
2.  We check $X = N+1$:
    -   If $N$ does *not* end in an odd number of 9s (i.e., $N$ ends in $0, \dots, 8$ or an even number of 9s), then $S(N+1) \pmod 2 \neq S(N) \pmod 2$. In this case, $X=N+1$ is our answer.
    -   If $N$ *does* end in an odd number of 9s (e.g., $N=129$, $N=12999$), then $S(N+1) \pmod 2 = S(N) \pmod 2$. So $N+1$ is not the answer. We must check $X=N+2$.
        Consider $N+1$. If $N$ ends in an odd number of 9s, then $N+1$ will end in a $0$ (e.g., $129 \to 130$, $12999 \to 13000$). This means $N+1$ does not end in any 9s (i.e., $p=0$, which is an even number of 9s).
        Therefore, when we increment $N+1$ to $(N+1)+1 = N+2$, the parity of the digit sum *will* flip: $S(N+2) \pmod 2 \neq S(N+1) \pmod 2$.
        Since $S(N+1) \pmod 2 = S(N) \pmod 2$ (from the previous step), it follows that $S(N+2) \pmod 2 \neq S(N) \pmod 2$.
        Thus, if $N+1$ was not the answer, $X=N+2$ *must* be the answer.

This crucial observation simplifies the problem significantly: the smallest $X > N$ will always be either $N+1$ or $N+2$. This means we only need to check at most two numbers after $N$.

## Complexity Analysis
-   **Time Complexity**:
    -   The `getDigitSum` function iterates through the digits of a number. For a number $K$, this takes $O(\log_{10} K)$ time. Since $N \le 10^9$, $N$ has at most 10 digits. So, `getDigitSum` is effectively $O(1)$ (constant time) for practical purposes.
    -   For each test case, the `solve` function calls `getDigitSum` at most three times (once for $N$, then for $N+1$, and potentially for $N+2$).
    -   Therefore, the time complexity per test case is $O(\log_{10} N)$.
    -   With $T$ test cases, the total time complexity is $O(T \cdot \log_{10} N)$. Given $T=100$ and $N=10^9$, this is roughly $100 \times 10 = 1000$ operations, which is extremely efficient and well within typical time limits.

-   **Space Complexity**:
    -   The solution uses a few `long long` and `int` variables to store numbers and their digit sums/parities. No dynamic data structures or arrays are used whose size depends on $N$ or $T$.
    -   Thus, the space complexity is $O(1)$ (constant space).

## Solution Code
```cpp
#include <bits/stdc++.h> // Includes most standard libraries

// Use the standard namespace to avoid writing std:: repeatedly
using namespace std;

// Function to calculate the sum of digits of a number
// It takes a long long to handle numbers up to 10^9 and beyond safely.
long long getDigitSum(long long num) {
    long long sum = 0;
    // Loop until the number becomes 0
    while (num > 0) {
        // Add the last digit (num % 10) to the sum
        sum += num % 10;
        // Remove the last digit by integer division (num / 10)
        num /= 10;
    }
    return sum;
}

// Function to solve a single test case
void solve() {
    long long n;
    cin >> n; // Read the input integer N

    // Calculate the digit sum of N and its parity
    long long digitSumN = getDigitSum(n);
    int parityN = digitSumN % 2; // 0 for even, 1 for odd

    // Start checking integers strictly greater than N, beginning with N+1
    long long x = n + 1;
    while (true) { // This loop will run at most twice based on our observation
        // Calculate the digit sum of X and its parity
        long long digitSumX = getDigitSum(x);
        int parityX = digitSumX % 2;

        // Check if the parities are different
        if (parityX != parityN) {
            // If they are different, X is the smallest such integer
            cout << x << "\n"; // Print X followed by a newline
            return; // Exit the function for this test case
        }
        // If parities are the same, increment X and check the next number
        x++;
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t; // Read the number of test cases

    // Loop through each test case
    while (t--) {
        solve(); // Call the solve function for the current test case
    }

    return 0; // Indicate successful execution
}
```