# [Split N (SPLITN)](https://www.codechef.com/problems/SPLITN)
- **Difficulty Rating**: 1195
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to find the minimum number of operations required to break a given integer `N` into a sum of powers of 2. An operation consists of taking any number `X` and breaking it into two parts `Y` and `Z` such that `X = Y + Z`.

## Intuition & Mathematical Observation
Let's analyze the core operation: "take any number `X` and break it into two parts `Y` and `Z` such that `X = Y + Z`".
Crucially, each such operation takes one number (`X`) and replaces it with two numbers (`Y` and `Z`). This means that **each operation increases the total count of numbers we possess by exactly one**.

Our ultimate goal is to express `N` as a sum of powers of 2. The most fundamental and unique way to represent any positive integer `N` as a sum of distinct powers of 2 is through its binary representation. For example, if `N = 13`, its binary representation is `1101`, which translates to `13 = 2^3 + 2^2 + 2^0 = 8 + 4 + 1`. In this case, we need to obtain three distinct powers of 2: `8`, `4`, and `1`.

Let `k` be the number of set bits (1s) in the binary representation of `N`. This `k` represents the minimum number of distinct powers of 2 that sum up to `N`.
Initially, we start with a single number: `N`.
Our objective is to transform this single number `N` into `k` distinct numbers (the powers of 2 corresponding to its set bits).
Since each operation increases the count of numbers by one, to go from 1 number to `k` numbers, we must perform exactly `k - 1` operations.

Consider an example: `N = 7` (binary `111`).
- The number of set bits `k = 3`.
- We start with `{7}` (1 number).
- We want to end with `{4, 2, 1}` (3 numbers).
- Operations needed: `3 - 1 = 2`.
  - **Operation 1**: Break `7` into `4` and `3`. We now have `{4, 3}` (2 numbers).
  - **Operation 2**: Break `3` into `2` and `1`. We now have `{4, 2, 1}` (3 numbers).
  All numbers (`4`, `2`, `1`) are powers of 2. Total operations: 2.

This strategy is optimal for two key reasons:
1.  The binary representation provides the minimum number of *distinct* powers of 2 that sum to `N`. Using more numbers (e.g., `2+2` instead of `4`) would only increase the total count of numbers needed, thereby requiring more operations.
2.  Each operation inherently increases the count of numbers by exactly one. Therefore, to reach `k` numbers from an initial state of 1 number, `k-1` operations are the absolute minimum.

Thus, the minimum number of operations is simply `(number of set bits in N) - 1`.
In C++, the `__builtin_popcount(n)` function (a GCC extension) efficiently calculates the number of set bits in an integer `n`.

## Complexity Analysis
-   **Time Complexity**: For each test case, we perform a constant number of operations: reading `N`, calculating the number of set bits using `__builtin_popcount(N)`, and printing the result. The `__builtin_popcount` function typically takes time proportional to the number of bits in `N` (e.g., $O(\log N)$ or $O(1)$ for fixed-size integers like `int`, which is usually 32 bits). Given that `N` fits in an `int`, this is effectively a constant time operation. If there are `T` test cases, the total time complexity is $O(T)$.
-   **Space Complexity**: We only use a few integer variables to store `t`, `n`, and `set_bits`. This requires a constant amount of memory, so the space complexity is $O(1)$.

## Solution Code

```cpp
#include <iostream> // Required for standard input/output operations (cin, cout)

// Using namespace std; is common in competitive programming to avoid repeatedly typing std::
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t; // Read the number of test cases

    while (t--) { // Loop through each test case
        int n;
        cin >> n; // Read the integer N for the current test case

        // The problem asks for the minimum number of operations to break N into powers of 2.
        // Each operation takes one number X and breaks it into two parts Y and Z (X = Y + Z).
        // This means each operation increases the total count of numbers we have by one.
        //
        // We want to express N as a sum of powers of 2. The unique way to do this with distinct powers of 2
        // is given by N's binary representation. For example, if N = 13 (binary 1101),
        // it's 2^3 + 2^2 + 2^0 = 8 + 4 + 1.
        // Here, we need to obtain 3 distinct powers of 2 (8, 4, 1).
        //
        // Initially, we have 1 number (N).
        // We want to end up with 'k' numbers, where 'k' is the count of set bits in N's binary representation.
        // Since each operation increases the number of parts by 1, to go from 1 part to 'k' parts,
        // we need exactly 'k - 1' operations.
        //
        // __builtin_popcount(n) is a GCC extension that efficiently counts the number of set bits (1s)
        // in the binary representation of an integer 'n'.
        int set_bits = __builtin_popcount(n);

        // The minimum number of operations is (number of set bits) - 1.
        cout << set_bits - 1 << "\n";
    }

    return 0; // Indicate successful execution
}
```