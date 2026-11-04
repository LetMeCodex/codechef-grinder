# [Max Binary (MAX_BIN)](https://www.codechef.com/problems/MAX_BIN)
- **Difficulty Rating**: 1143
- **Solved in**: 2 attempt(s)

## Problem Summary
Given a binary string $S$ of length $N$ and an integer $K$, we can perform at most $K$ operations. An operation consists of either changing a '0' to a '1' or appending a '0' to the end of the string. The goal is to maximize the decimal value represented by the binary string after performing at most $K$ operations.

## Intuition & Mathematical Observation

To maximize the decimal value of a binary string, we want to make the most significant bits (leftmost bits) as large as possible. A '1' at a more significant position contributes much more to the decimal value than a '1' at a less significant position.

Consider the operations:
1.  **Changing '0' to '1'**: This operation directly increases the value of a specific bit position. To maximize the overall value, it's always best to change a '0' to a '1' at the most significant position possible.
2.  **Appending '0'**: Appending a '0' to the end of a binary string of length $L$ effectively multiplies its decimal value by 2. This is because each bit's positional value doubles. For example, "101" (decimal 5) becomes "1010" (decimal 10). This operation is most effective when the string already represents a large value.

Combining these observations, the optimal strategy emerges:

*   **Prioritize the Most Significant Bit (MSB)**: If the first character of the string $S$ is '0' and we have operations ($K > 0$) available, we should use one operation to change this '0' to a '1'. This is the single most impactful change we can make to increase the decimal value.
*   **Maximize by Appending**: After ensuring the MSB is '1' (if possible and beneficial), any remaining operations ($K$) should be used to append '0's to the end of the string. Appending '0's is the most efficient way to increase the magnitude of the number when the leading bits are already optimized. Each appended '0' doubles the current value, which is a significant increase.

Let's trace an example: $N=3, K=2, S="010"$.
1.  The first character is '0' and $K=2 > 0$. Change $S[0]$ to '1'. $S$ becomes "110", $K$ becomes 1.
2.  We have $K=1$ operation left. Append a '0' to $S$. $S$ becomes "1100".
The final string is "1100", which represents decimal 12.

Another example: $N=3, K=1, S="101"$.
1.  The first character is '1'. No change needed for the MSB. $K$ remains 1.
2.  We have $K=1$ operation left. Append a '0' to $S$. $S$ becomes "1010".
The final string is "1010", which represents decimal 10.

This strategy ensures that we make the most significant bits as large as possible first, and then leverage the remaining operations to exponentially increase the value by appending zeros.

## Complexity Analysis

*   **Time Complexity**: $O(N + K)$
    *   Reading the input string $S$ takes $O(N)$ time.
    *   Checking and potentially modifying the first character takes $O(1)$ time.
    *   Appending $K$ zeros to the string takes $O(K)$ time. The `std::string::append(count, char)` operation is efficient.
    *   Printing the string takes $O(N+K)$ time (the final length of the string).
    *   Therefore, the dominant factor is $O(N+K)$.

*   **Space Complexity**: $O(N + K)$
    *   We store the input string $S$, which has length $N$.
    *   After appending $K$ zeros, the string can grow up to length $N+K$.
    *   Thus, the space complexity is $O(N+K)$ to store the modified string.

## Solution Code

```cpp
#include <iostream> // Required for std::cin, std::cout
#include <string>   // Required for std::string
// <vector> and <algorithm> are not strictly needed for this problem,
// but are often included in competitive programming templates.

void solve() {
    int n, k;
    std::cin >> n >> k; // Read N and K
    std::string s;
    std::cin >> s; // Read the binary string S

    // Step 1: If the first character is '0' and we have operations left (K > 0),
    // change it to '1'. This makes the most significant bit '1', which is
    // the most impactful change for maximizing the decimal value.
    if (s[0] == '0' && k > 0) {
        s[0] = '1'; // Change '0' to '1'
        k--;        // One operation used
    }

    // Step 2: Use any remaining K operations to append '0's to the end of the string.
    // Appending '0's effectively multiplies the current decimal value by 2 for each '0' added.
    // This is the most efficient way to increase the value after the first bit is '1'.
    // Using s.append(count, char) is generally more efficient for appending multiple
    // characters than repeated push_back, as it can perform a single memory allocation.
    if (k > 0) { // Only append if there are operations left
        s.append(k, '0');
    }

    std::cout << s << "\n"; // Output the modified string
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is crucial for competitive programming problems with large I/O.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t; // Read the number of test cases
    while (t--) {
        solve(); // Solve each test case
    }

    return 0; // Indicate successful execution
}
```