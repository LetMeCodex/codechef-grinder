# Maximum Ones (MXON)
- **Difficulty Rating**: 943
- **Solved in**: 1 attempt(s)

## Problem Summary
Given a binary string $S$ of length $N$ and an integer $K$, we can perform an operation: if there is a '1' at index $i+1$, we can change the character at index $i$ to '1'. This operation can be performed at most $K$ times. The goal is to maximize the number of '1's in the string after performing at most $K$ operations.

## Intuition & Mathematical Observation
The core of the problem lies in understanding how the operations propagate. A '1' at index $i+1$ can convert a '0' at index $i$ to a '1'. This newly formed '1' at index $i$ can then be used to convert a '0' at index $i-1$ to a '1', and so on. This suggests a chain reaction.

To maximize the total number of '1's, we should prioritize converting '0's that are "closer" to existing '1's, as they can be converted with fewer or no additional '1's to their right. Consider the effect of a '1' at index $j$. It can convert $S[j-1]$ to '1', then $S[j-2]$ to '1', and so on, all the way down to $S[0]$.

If we have multiple '1's, say at indices $j_1$ and $j_2$ ($j_1 < j_2$), the '1' at $j_2$ can convert $S[j_2-1], S[j_2-2], \dots, S[0]$. The '1' at $j_1$ can convert $S[j_1-1], S[j_1-2], \dots, S[0]$. The key observation is that the '1' at $j_2$ can potentially convert more '0's to its left than the '1' at $j_1$.

This leads to a greedy strategy: to maximize the number of '1's, we should try to extend the "reach" of the rightmost '1' as far to the left as possible. Why the rightmost '1'? Because it has the potential to convert all characters to its left. If we have a '1' at index $i+1$, it can convert $S[i]$ to '1'. If $S[i]$ becomes '1', it can then be used to convert $S[i-1]$ to '1', and so on. This suggests iterating from right to left.

Let's consider the string from right to left. Suppose the rightmost '1' is at index `last_one_idx`.
1. We first count all the initial '1's in the string.
2. If there are no '1's initially, we can never create any '1's, so the answer is 0.
3. If there are '1's, we start from the character immediately to the left of the rightmost '1' (i.e., at index `last_one_idx - 1`).
4. If we have operations ($K > 0$) and the current character $S[i]$ is '0', we can convert it to '1' using the '1' at $S[i+1]$ (which is either an original '1' or was just converted in a previous step). This costs one operation ($K--$) and increases our count of '1's.
5. We continue this process, moving leftwards (decreasing $i$). Each time we convert a '0' to a '1', we increment the total count of '1's and decrement $K$.
6. We stop when we run out of operations ($K=0$) or when we reach the beginning of the string ($i < 0$).

This greedy approach works because converting a '0' at index $i$ to a '1' using $S[i+1]$ is always beneficial. It costs one operation and increases the total count of '1's. Furthermore, this newly created '1' at index $i$ can then be used to help convert $S[i-1]$, potentially creating a longer contiguous block of '1's from right to left. By processing from right to left, we ensure that the '1' at $S[i+1]$ is already in its final state (either an original '1' or one that was converted) when we consider $S[i]$.

For example, if $S = "00100"$ and $K=2$:
- Initial '1's: 1. `last_one_idx = 2`.
- Consider $i = 1$: $S[1] = '0'$. We have $K=2$. Convert $S[1]$ to '1'. `current_ones` becomes 2. $K$ becomes 1. String conceptually becomes "01100".
- Consider $i = 0$: $S[0] = '0'$. We have $K=1$. Convert $S[0]$ to '1'. `current_ones` becomes 3. $K$ becomes 0. String conceptually becomes "11100".
- $K$ is now 0, so we stop. The maximum number of '1's is 3.

## Complexity Analysis
- **Time Complexity**: $O(N)$
  - We iterate through the string once to find the initial count of '1's and the `last_one_idx`. This takes $O(N)$ time.
  - We then iterate from `last_one_idx - 1` down to 0. In the worst case, this loop also runs up to $N$ times.
  - Therefore, the total time complexity is $O(N) + O(N) = O(N)$.

- **Space Complexity**: $O(N)$
  - We store the input string $S$, which takes $O(N)$ space.
  - The variables `N`, `K`, `current_ones`, and `last_one_idx` take constant space, $O(1)$.
  - Thus, the dominant space usage is the string itself, leading to $O(N)$ space complexity. If the input string is considered part of the input and not counted towards auxiliary space, then the auxiliary space complexity is $O(1)$.

## Solution Code
```cpp
#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // Not strictly needed, but good practice for competitive programming

void solve() {
    int N, K;
    std::cin >> N >> K;
    std::string S;
    std::cin >> S;

    int current_ones = 0;
    int last_one_idx = -1;

    // Count initial ones and find the rightmost '1'
    for (int i = 0; i < N; ++i) {
        if (S[i] == '1') {
            current_ones++;
            last_one_idx = i;
        }
    }

    // If there are no '1's initially, no '0' can ever become '1'.
    // The count of '1's remains 0.
    if (last_one_idx == -1) {
        std::cout << 0 << "\n";
        return;
    }

    // Apply operations greedily from right to left, starting from the position
    // just to the left of the rightmost '1'.
    // The logic is that a '1' at S[i+1] can turn S[i] into '1'.
    // If S[i] becomes '1', it can then be used to turn S[i-1] into '1', and so on.
    // By iterating from right to left, we ensure that S[i+1] is already in its
    // final (or current '1') state when we consider S[i].
    for (int i = last_one_idx - 1; i >= 0; --i) {
        if (K == 0) {
            break; // No more operations left
        }
        
        // If S[i] is '0', we can turn it into '1' using S[i+1] (which is either
        // an original '1' or was just turned into '1' in the previous iteration).
        if (S[i] == '0') {
            current_ones++; // Increment the count of '1's
            K--;            // Use one operation
            // Conceptually, S[i] is now '1'. This allows S[i-1] to potentially become '1'.
            // The loop naturally handles this by moving to i-1.
        }
        // If S[i] is already '1', we don't need to do anything for this position.
    }

    std::cout << current_ones << "\n";
}

int main() {
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
```