# [Invert And Equalize (INVEQ)](https://www.codechef.com/problems/INVEQ)
- **Difficulty Rating**: 1102
- **Solved in**: 2 attempt(s)

## Problem Summary

You are given a binary string $S$ of length $N$. You can perform the following operation:
Choose an index $i$ (1-indexed) and invert all characters $S[1], S[2], \ldots, S[i]$.
The goal is to find the minimum number of operations required to make all characters in $S$ equal (i.e., either all '0's or all '1's).

## Intuition & Mathematical Observation

Let's analyze the effect of the operation. An operation at index $i$ flips the characters $S[1], \ldots, S[i]$. We are interested in the minimum number of such operations.

A key observation in problems involving prefix operations is how they can be combined. If we apply an operation at index $b$ (flipping $S[1 \ldots b]$) and another operation at index $a-1$ (flipping $S[1 \ldots a-1]$), the net effect is:
- Characters $S[1 \ldots a-1]$ are flipped twice, resulting in no net change.
- Characters $S[a \ldots b]$ are flipped once.
- Characters $S[b+1 \ldots N]$ are not affected.

This means that by applying at most two prefix flip operations, we can effectively flip any arbitrary contiguous subsegment $S[a \ldots b]$ of the string.
- To flip $S[a \ldots b]$ where $a > 1$: Apply operations at $a-1$ and $b$.
- To flip $S[1 \ldots b]$: Apply an operation at $b$.

Therefore, the problem is equivalent to finding the minimum number of range flip operations to make the string monochromatic (all '0's or all '1's).

Consider the string $S$ as a sequence of alternating blocks of identical characters. For example, `001101` can be seen as blocks `00`, `11`, `0`, `1`.
Let's count the number of blocks of '0's (`count0_blocks`) and '1's (`count1_blocks`).
For `001101`:
- `00` is a '0' block.
- `11` is a '1' block.
- `0` is a '0' block.
- `1` is a '1' block.
So, `count0_blocks = 2` and `count1_blocks = 2`.

If we want to make the entire string all '0's, we need to flip all the '1' blocks. Each '1' block can be flipped using one range flip operation. The number of operations needed would be `count1_blocks`.
If we want to make the entire string all '1's, we need to flip all the '0' blocks. Each '0' block can be flipped using one range flip operation. The number of operations needed would be `count0_blocks`.

Since we want the *minimum* number of operations, we choose the target state (all '0's or all '1's) that requires fewer flips. This means the answer is `min(count0_blocks, count1_blocks)`.

Let's walk through an example: `S = 001101`
1. Initialize `count0_blocks = 0`, `count1_blocks = 0`.
2. First character `S[0]` is '0'. So, `count0_blocks = 1`.
3. Iterate from `i = 1` to `N-1`:
   - `S[1]` is '0'. `S[1] == S[0]`. No new block.
   - `S[2]` is '1'. `S[2] != S[1]`. New block starts with '1'. `count1_blocks = 1`.
   - `S[3]` is '1'. `S[3] == S[2]`. No new block.
   - `S[4]` is '0'. `S[4] != S[3]`. New block starts with '0'. `count0_blocks = 2`.
   - `S[5]` is '1'. `S[5] != S[4]`. New block starts with '1'. `count1_blocks = 2`.
4. Final counts: `count0_blocks = 2`, `count1_blocks = 2`.
5. The minimum operations is `min(2, 2) = 2`.

To achieve this for `001101` (target all '0's, 2 ops):
- Flip `S[3...4]` (the `11` block) to `00`.
- Flip `S[6...6]` (the `1` block) to `0`.
The string becomes `000000`. This takes 2 range flips.

This logic holds for all cases, including edge cases:
- `S = "0"`: `count0_blocks=1, count1_blocks=0`. `min(1,0)=0`. (Already all '0's)
- `S = "1"`: `count0_blocks=0, count1_blocks=1`. `min(0,1)=0`. (Already all '1's)
- `S = "01"`: `count0_blocks=1, count1_blocks=1`. `min(1,1)=1`. (Flip `S[2...2]` to make `00`, or `S[1...1]` to make `11`)

## Complexity Analysis

-   **Time Complexity**: $O(N)$
    -   Reading $N$ and the string $S$ takes $O(N)$ time.
    -   The loop iterates through the string once from $i=1$ to $N-1$ to count the blocks, which takes $O(N)$ time.
    -   Calculating `std::min` is $O(1)$.
    -   For $T$ test cases, the total time complexity is $O(T \cdot N)$.
-   **Space Complexity**: $O(N)$
    -   A character array `s_arr` of size $N+1$ is used to store the input string.
    -   A few integer variables (`n`, `count0_blocks`, `count1_blocks`, `i`, `t`) use $O(1)$ space.
    -   The total space complexity is dominated by the string storage, hence $O(N)$.

## Solution Code

```cpp
#include <cstdio>   // For scanf/printf
#include <algorithm> // Required for std::min

// Declare a global char array to avoid repeated memory allocation/deallocation
// Max N is 10^5, so 100005 characters + 1 for null terminator is sufficient.
char s_arr[100005]; 

void solve() {
    int n;
    // Use scanf for faster input
    scanf("%d", &n);
    scanf("%s", s_arr); // Read string into the char array

    // If N is 0, it's already equal (empty string), but constraints say N >= 1.
    // If N is 1, it's already equal. The logic below handles this correctly.
    // For example, if S="0", count0_blocks=1, count1_blocks=0. min(1,0)=0.
    // If S="1", count0_blocks=0, count1_blocks=1. min(0,1)=0.

    int count0_blocks = 0;
    int count1_blocks = 0;

    // The first character always starts a block.
    if (s_arr[0] == '0') {
        count0_blocks = 1;
    } else { // s_arr[0] == '1'
        count1_blocks = 1;
    }

    // Iterate from the second character to count subsequent blocks.
    // A new block starts whenever the current character is different from the previous one.
    for (int i = 1; i < n; ++i) {
        if (s_arr[i] != s_arr[i-1]) {
            // A new block starts
            if (s_arr[i] == '0') {
                count0_blocks++;
            } else { // s_arr[i] == '1'
                count1_blocks++;
            }
        }
    }

    // Use printf for faster output
    printf("%d\n", std::min(count0_blocks, count1_blocks));
}

int main() {
    // No need for std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    // when using scanf/printf. These are for C++ streams (cin/cout).

    int t;
    scanf("%d", &t); // Read the number of test cases
    while (t--) {
        solve(); // Solve each test case
    }

    return 0;
}
```