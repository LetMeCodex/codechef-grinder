# Split and Maximize (SPLITMAX)
- **Difficulty Rating**: 1313
- **Solved in**: 1 attempt(s)

## Problem Summary

Given an array $C$ of $N$ positive integers, we can perform an operation: choose an element $x$ from the array and replace it with two positive integers $a$ and $b$ such that $a+b=x$. This operation can be performed any number of times. The goal is to maximize the value of $f(A) = (\sum_{i} A_i)^2 - \sum_{i} A_i^2$, where $A$ is the final array after performing the operations. We need to find the maximum possible value of $f(A)$ modulo $998244353$.

## Intuition & Mathematical Observation

Let the initial array be $C = [C_1, C_2, \dots, C_N]$.
When we replace an element $x$ with $a$ and $b$ such that $a+b=x$, the sum of elements in the array changes from $\dots + x + \dots$ to $\dots + a + b + \dots$. Since $a+b=x$, the total sum of elements in the array remains invariant throughout the operations. Let $S$ be the initial sum of elements in $C$. Then, for any final array $A$, the sum of its elements will also be $S$.

Now let's analyze the function $f(A) = (\sum_{i} A_i)^2 - \sum_{i} A_i^2$.
Since $\sum_{i} A_i = S$ for any final array $A$, the function becomes $f(A) = S^2 - \sum_{i} A_i^2$.
To maximize $f(A)$, we need to minimize $\sum_{i} A_i^2$.

Consider an element $x$. If we replace it with $a$ and $b$ ($a+b=x$), how does the sum of squares change?
The original contribution to the sum of squares was $x^2$.
The new contribution is $a^2 + b^2$.
We know that $(a+b)^2 = a^2 + 2ab + b^2$.
So, $x^2 = a^2 + 2ab + b^2$.
This implies $a^2 + b^2 = x^2 - 2ab$.
Since $a$ and $b$ are positive integers, $ab \ge 1$. Thus, $2ab \ge 2$.
Therefore, $a^2 + b^2 \le x^2 - 2$.
This means that splitting an element $x$ into two positive integers $a$ and $b$ always decreases the sum of squares (or keeps it the same if $x=1$ and we split it into $1$ and $0$, but the problem states positive integers, so this is not allowed. If $x=2$, we can split into $1,1$. $2^2=4$, $1^2+1^2=2$. The sum of squares decreases).

To minimize the sum of squares $\sum_{i} A_i^2$, we should split the elements as much as possible. The smallest positive integer is $1$. If we can split every element $C_i$ into $C_i$ ones, we would achieve the minimum possible sum of squares.
For example, if $C_i = 5$, we can split it into $1, 1, 1, 1, 1$. The sum of squares contribution changes from $5^2 = 25$ to $1^2+1^2+1^2+1^2+1^2 = 5$.

If we can split every element $C_i$ into $C_i$ ones, the final array $A$ will consist of $S = \sum_{i=1}^N C_i$ ones.
In this case, the sum of elements is $\sum A_i = S$.
The sum of squares of elements is $\sum A_i^2 = \sum_{j=1}^S 1^2 = S \times 1 = S$.

Therefore, the maximum value of $f(A)$ is $S^2 - S$.

We need to compute $(S^2 - S) \pmod{998244353}$.
Let $MOD = 998244353$.
The calculation is:
1. Calculate $S = \sum_{i=1}^N C_i$.
2. Calculate $S \pmod{MOD}$. Let this be $S_{mod}$.
3. Calculate $(S_{mod} \times S_{mod}) \pmod{MOD}$. Let this be $S_{squared\_mod}$.
4. Calculate $(S_{squared\_mod} - S_{mod} + MOD) \pmod{MOD}$. The addition of $MOD$ before the final modulo ensures that the result is non-negative if $S_{squared\_mod} < S_{mod}$.

The constraints are $N \le 2 \times 10^5$ and $C_i \le 10^9$.
The total sum $S$ can be up to $2 \times 10^5 \times 10^9 = 2 \times 10^{14}$. This requires `long long` in C++.
The modulo is $998244353$, which fits within a `long long`.

## Complexity Analysis

- **Time Complexity**: $O(N)$
    - We iterate through the array once to read the elements and calculate their sum. This takes $O(N)$ time.
    - The subsequent calculations for the result involve a few arithmetic operations, which take constant time $O(1)$.
    - Thus, the total time complexity is dominated by the input reading and summation, resulting in $O(N)$ per test case.

- **Space Complexity**: $O(1)$
    - We only use a few variables to store the total sum, intermediate results, and the modulo. The space used does not depend on the input size $N$.
    - Thus, the space complexity is $O(1)$ per test case.

## Solution Code

```cpp
#include <iostream> // Required for standard input/output operations (cin, cout)

// Define the modulo constant. It's a prime number commonly used in competitive programming.
const long long MOD = 998244353;

// Function to solve a single test case
void solve() {
    int N;
    std::cin >> N; // Read the size of the array C

    long long total_sum = 0; // Initialize a long long variable to store the sum of elements.
                             // Using long long is crucial because C_i can be up to 10^9 and N up to 2*10^5,
                             // so total_sum can be up to 2*10^5 * 10^9 = 2*10^14, which exceeds int's capacity.

    // Loop through N elements to read them and calculate their sum
    for (int i = 0; i < N; ++i) {
        long long C_i; // Each element C_i can be up to 10^9, so use long long for safety.
        std::cin >> C_i;
        total_sum += C_i; // Add the current element to the total sum
    }

    // The maximum value of f(C) is obtained when all elements in the array are 1s.
    // The sum of elements (total_sum) remains invariant under the given operations.
    // If the final array consists of only 1s, its size will be equal to the initial total_sum.
    // Let S_final be the total_sum. The final array will be [1, 1, ..., 1] (S_final times).
    // For this array:
    // - The sum of elements is S_final.
    // - The sum of squares of elements is S_final * 1^2 = S_final.
    // The function f(A) is defined as (sum of elements)^2 - (sum of squares of elements).
    // So, the maximum value of f(C) is S_final^2 - S_final.

    // Now, calculate (total_sum^2 - total_sum) modulo MOD.
    // First, take total_sum modulo MOD to keep intermediate values within manageable range.
    long long S_mod = total_sum % MOD;

    // Calculate S_mod * S_mod, then take modulo.
    long long S_squared_mod = (S_mod * S_mod) % MOD;

    // Calculate (S_squared_mod - S_mod) modulo MOD.
    // We add MOD before subtracting S_mod to ensure the result of the subtraction is non-negative
    // before applying the final modulo operation. This handles cases where S_squared_mod < S_mod.
    long long result = (S_squared_mod - S_mod + MOD) % MOD;

    std::cout << result << "\n"; // Output the final result
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) prevents std::cout from flushing before std::cin reads input.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T; // Read the number of test cases
    while (T--) { // Loop through each test case
        solve(); // Call the solve function for the current test case
    }

    return 0; // Indicate successful execution
}
```