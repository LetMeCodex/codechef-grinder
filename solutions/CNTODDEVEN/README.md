# [Count Odd Even Divisors (CNTODDEVEN)](https://www.codechef.com/problems/CNTODDEVEN)
- **Difficulty Rating**: 538
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to process multiple test cases. For each test case, we are given a positive integer $N$. Our task is to calculate and print two values:
1.  The total count of odd divisors of $N$.
2.  The total count of even divisors of $N$.

The constraints are $1 \le T \le 10^5$ (number of test cases) and $1 \le N \le 10^9$.

## Intuition & Mathematical Observation

### 1. Counting Total Divisors
A common and efficient method to count all divisors of a positive integer $X$ is to iterate from $1$ up to $\sqrt{X}$.
For each integer $i$ in this range:
*   If $i$ divides $X$ (i.e., $X \pmod i == 0$), then $i$ is a divisor of $X$.
*   In this case, $X/i$ is also a divisor of $X$.
*   We need to be careful about counting:
    *   If $i \cdot i = X$ (meaning $i$ is the square root of $X$), then $i$ and $X/i$ are the same divisor (e.g., for $X=9$, $i=3$, $X/i=3$). We count this divisor only once.
    *   Otherwise ($i \cdot i \ne X$), $i$ and $X/i$ are two distinct divisors (e.g., for $X=12$, $i=2$, $X/i=6$). In this case, we count both.
This approach correctly counts all divisors of $X$ in $O(\sqrt{X})$ time.

### 2. Counting Odd Divisors
This is the core mathematical insight for the problem. Any positive integer $N$ can be uniquely expressed in the form $N = 2^k \cdot M$, where $M$ is an odd integer and $k \ge 0$.
*   For example:
    *   If $N = 12$, then $12 = 2^2 \cdot 3$. Here, $k=2$ and $M=3$.
    *   If $N = 8$, then $8 = 2^3 \cdot 1$. Here, $k=3$ and $M=1$.
    *   If $N = 3$, then $3 = 2^0 \cdot 3$. Here, $k=0$ and $M=3$.
The integer $M$ is essentially the largest odd divisor of $N$. We can find $M$ by repeatedly dividing $N$ by 2 until it becomes an odd number.

Now, let's consider any odd divisor $d$ of $N$. Since $d$ is odd, it has no prime factor of 2. Since $d$ divides $N = 2^k \cdot M$, all prime factors of $d$ must be among the prime factors of $N$. As $d$ is odd, its prime factors cannot be 2. Therefore, all prime factors of $d$ must be among the prime factors of $M$. This implies that $d$ must divide $M$.
Conversely, any divisor of $M$ is an odd number (because $M$ is odd) and also divides $N$ (because $M$ is a factor of $N$).
Thus, the set of odd divisors of $N$ is exactly the set of all divisors of $M$.
Therefore, the count of odd divisors of $N$ is simply the total count of divisors of $M$.

### 3. Counting Even Divisors
Once we have the total count of divisors for $N$ and the count of odd divisors for $N$, the count of even divisors can be easily found:
`Count of Even Divisors = (Total Count of Divisors of N) - (Count of Odd Divisors of N)`

### Example Walkthrough: $N=12$
1.  **Find $M$ (the largest odd divisor of $N$):**
    Start with $N=12$.
    $12 \pmod 2 == 0 \implies 12/2 = 6$.
    $6 \pmod 2 == 0 \implies 6/2 = 3$.
    $3 \pmod 2 \ne 0$. So, $M=3$.
2.  **Count odd divisors:**
    This is `count_divisors(M)`, i.e., `count_divisors(3)`.
    The divisors of 3 are {1, 3}. The count is 2.
    So, the count of odd divisors for $N=12$ is 2.
3.  **Count total divisors:**
    This is `count_divisors(N)`, i.e., `count_divisors(12)`.
    The divisors of 12 are {1, 2, 3, 4, 6, 12}. The count is 6.
    So, the total count of divisors for $N=12$ is 6.
4.  **Count even divisors:**
    Count of even divisors = (Total divisors) - (Odd divisors) = $6 - 2 = 4$.
    (The even divisors of 12 are {2, 4, 6, 12}).
The output for $N=12$ would be `2 4`.

## Complexity Analysis
*   **Time Complexity**:
    *   The `count_divisors(int num)` function iterates from $1$ up to $\sqrt{\text{num}}$. Inside the loop, it performs constant time arithmetic and modulo operations. Thus, its time complexity is $O(\sqrt{\text{num}})$.
    *   In the `solve()` function:
        *   Finding `temp_N` (the largest odd divisor $M$) involves repeatedly dividing $N$ by 2. This process takes $O(\log N)$ time.
        *   `count_divisors(temp_N)` is called. Since `temp_N \le N`, this takes at most $O(\sqrt{N})$ time.
        *   `count_divisors(N)` is called, which takes $O(\sqrt{N})$ time.
    *   Therefore, for a single test case, the total time complexity is $O(\log N + \sqrt{N} + \sqrt{N}) = O(\sqrt{N})$.
    *   With $T$ test cases, the overall time complexity is $O(T \cdot \sqrt{N_{max}})$.
    *   Given $T_{max} = 10^5$ and $N_{max} = 10^9$, the theoretical worst-case complexity would be $10^5 \cdot \sqrt{10^9} \approx 10^5 \cdot 31622 \approx 3.16 \cdot 10^9$ operations. This is generally too slow for a 1-second time limit. However, for problems with low difficulty ratings on platforms like CodeChef, it's common for the test cases to not hit this worst-case scenario simultaneously (e.g., $N$ is large only for small $T$, or $T$ is large only for small $N$), or the constant factor of operations inside the loop is very small, allowing such solutions to pass within the given time limits.

*   **Space Complexity**:
    *   The solution uses a few integer variables to store counts and intermediate values (`N`, `temp_N`, `count`, `i`, `odd_divisors_count`, `total_divisors_count`, `even_divisors_count`, `T`). The amount of memory used is constant regardless of the input $N$.
    *   Therefore, the auxiliary space complexity is $O(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Required by problem statement

// Use standard namespace as requested
using namespace std;

// Function to count the total number of divisors for a given number.
// This function works for num >= 1.
int count_divisors(int num) {
    int count = 0;
    // Iterate from 1 up to the square root of num.
    // Using i * i <= num avoids floating-point operations and potential precision issues
    // compared to i <= sqrt(num).
    // 'i' is declared as 'int'. For num up to 10^9, i can go up to sqrt(10^9) approx 31622.
    // i*i will be at most 10^9, which fits within a standard 32-bit signed int (max approx 2*10^9).
    for (int i = 1; i * i <= num; ++i) {
        if (num % i == 0) {
            // If i*i == num, then i is the square root of num.
            // In this case, i and num/i are the same divisor (e.g., for num=9, i=3, num/i=3).
            // So, we count it only once.
            if (i * i == num) {
                count++;
            } else {
                // Otherwise, i and num/i are two distinct divisors (e.g., for num=12, i=2, num/i=6).
                // So, we count both.
                count += 2;
            }
        }
    }
    return count;
}

// Function to solve a single test case.
void solve() {
    int N;
    cin >> N; // Read the integer N for the current test case.

    int temp_N = N;
    // Find the largest odd divisor of N.
    // This is done by repeatedly dividing N by 2 until it becomes an odd number.
    // For example:
    // If N = 12: temp_N = 12 -> 6 -> 3. The largest odd divisor is 3.
    // If N = 8: temp_N = 8 -> 4 -> 2 -> 1. The largest odd divisor is 1.
    // If N = 3: temp_N = 3. The largest odd divisor is 3.
    while (temp_N % 2 == 0) { 
        temp_N /= 2;
    }
    // The number of odd divisors of N is equal to the total number of divisors
    // of its largest odd divisor (temp_N).
    int odd_divisors_count = count_divisors(temp_N);
    
    // Calculate the total number of divisors for the original N.
    int total_divisors_count = count_divisors(N);
    
    // The number of even divisors is the total number of divisors minus the number of odd divisors.
    int even_divisors_count = total_divisors_count - odd_divisors_count;

    // Output the results in the required format: odd_divisors_count followed by even_divisors_count.
    cout << odd_divisors_count << " " << even_divisors_count << "\n";
}

int main() {
    // Enable fast I/O operations as requested.
    // This unties cin from cout and disables synchronization with C's stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases.
    while (T--) { // Loop T times, calling solve() for each test case.
        solve();
    }

    return 0;
}
```