# [Another Card Game Problem (CRDGAME3)](https://www.codechef.com/problems/CRDGAME3)
- **Difficulty Rating**: 1230
- **Solved in**: 1 attempt(s)

## Problem Summary

Chef and Rick are playing a card game. Both start with 0 power. To increase their power, they draw cards, each having a single digit from 1 to 9. The digit on the drawn card is *added* to their current power. Chef wants to reach a final power $P_C$, and Rick wants to reach $P_R$. The player who uses the minimum number of cards to reach their target power wins. If both players use the same minimum number of cards, Rick wins. We need to determine the winner and the number of cards they used.

## Intuition & Mathematical Observation

The core of this problem is to find the minimum number of cards required to reach a target power $P$. Since each card contributes a digit from 1 to 9, to minimize the number of cards, we should maximize the value contributed by each card. The maximum value a single card can contribute is 9.

Therefore, to reach a target power $P$:
1.  We should ideally draw as many '9' cards as possible.
2.  If $P$ is a multiple of 9 (e.g., 9, 18, 27), we can reach $P$ by drawing $P/9$ cards, each with a value of 9.
3.  If $P$ is not a multiple of 9 (e.g., 10, 17, 19), we will draw some number of '9' cards, and then one final card with a value less than 9 to reach the exact target. For example, to reach 10: draw a '9' (power 9), then draw a '1' (power 9+1=10). This takes 2 cards.
4.  In general, the minimum number of cards required to reach power $P$ is $\lceil P/9 \rceil$ (P divided by 9, rounded up to the nearest integer).

**Mathematical Calculation of Ceiling Division:**
For positive integers $A$ and $B$, the ceiling division $\lceil A/B \rceil$ can be calculated using integer division as $(A + B - 1) / B$.
In our case, $A = P$ and $B = 9$. So, the minimum number of cards is $(P + 9 - 1) / 9 = (P + 8) / 9$.

Once we calculate the minimum cards for Chef (`digits_C`) and Rick (`digits_R`):
*   If `digits_C < digits_R`, Chef wins. Output `0 digits_C`.
*   If `digits_R < digits_C`, Rick wins. Output `1 digits_R`.
*   If `digits_C == digits_R`, Rick wins (as per problem statement). Output `1 digits_R`.

## Complexity Analysis

*   **Time Complexity**: $O(T)$
    *   For each test case, we perform a constant number of operations: reading two integers, two calls to `calculate_min_digits` (which involves constant arithmetic operations), a few comparisons, and printing the result.
    *   Since there are $T$ test cases, the total time complexity is directly proportional to $T$. Given $T \le 10^5$, this is highly efficient.

*   **Space Complexity**: $O(1)$
    *   The program uses a fixed number of integer variables to store `T`, `P_C`, `P_R`, `digits_C`, and `digits_R`.
    *   No dynamic data structures or arrays are used that would scale with input size. Thus, the memory usage remains constant regardless of the input values.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes iostream and many other useful headers
using namespace std;     // Allows direct use of cin, cout, etc.

// Function to calculate the minimum number of digits required for a given power P
int calculate_min_digits(int P) {
    // To minimize digits, each digit should be as large as possible (9).
    // The minimum number of digits is ceil(P / 9).
    // Using integer division, ceil(A / B) for positive A, B is (A + B - 1) / B.
    // Here, A = P, B = 9. So, (P + 9 - 1) / 9 = (P + 8) / 9.
    return (P + 8) / 9;
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Number of test cases
    cin >> T; // Read the number of test cases

    while (T--) { // Loop through each test case
        int P_C, P_R; // Final powers for Chef and Rick
        cin >> P_C >> P_R; // Read Chef's and Rick's final powers

        // Calculate the minimum digits required for Chef and Rick
        int digits_C = calculate_min_digits(P_C);
        int digits_R = calculate_min_digits(P_R);

        // Determine the winner based on the number of digits
        if (digits_C < digits_R) {
            // Chef needs fewer digits, so Chef wins.
            // Output 0 (for Chef) and Chef's digit count.
            cout << 0 << " " << digits_C << "\n";
        } else if (digits_R < digits_C) {
            // Rick needs fewer digits, so Rick wins.
            // Output 1 (for Rick) and Rick's digit count.
            cout << 1 << " " << digits_R << "\n";
        } else {
            // Both need the same number of digits. Rick cheats and wins.
            // Output 1 (for Rick) and the common digit count.
            cout << 1 << " " << digits_R << "\n";
        }
    }

    return 0; // Indicate successful execution
}
```