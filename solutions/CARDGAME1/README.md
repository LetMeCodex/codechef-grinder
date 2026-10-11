# [Card Game (CARDGAME1)](https://www.codechef.com/problems/CARDGAME1)
- **Difficulty Rating**: 671
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem describes a card game where a deck contains cards numbered from 1 to $N$. A card $X$ is chosen and removed from the deck. We then need to choose another card from the remaining deck such that the sum of the chosen card and the removed card $X$ is an even number. The task is to find out how many such cards can be chosen.

## Intuition & Mathematical Observation

The core of this problem lies in understanding the properties of even and odd numbers when added together.
Let `chosen_card` be the card we pick from the remaining deck, and `X` be the card that was removed. We want `(chosen_card + X)` to be an even number.

The rules for addition of parities are:
*   Even + Even = Even
*   Odd + Odd = Even
*   Even + Odd = Odd
*   Odd + Even = Odd

From these rules, for `(chosen_card + X)` to be even, `chosen_card` and `X` must have the **same parity**.

This leads to two distinct cases:

**Case 1: $X$ is an even number.**
If $X$ is even, then for `(chosen_card + X)` to be even, `chosen_card` must also be an even number.
We need to count how many even cards are available in the deck (from 1 to $N$), *excluding* the card $X$ which has already been removed.

*   **Total even cards in the range [1, N]:** The count of even numbers in the range [1, N] is given by $N / 2$ (using integer division). For example, if $N=5$, evens are {2, 4}, count = $5/2 = 2$. If $N=6$, evens are {2, 4, 6}, count = $6/2 = 3$.
*   Since $X$ is an even card and it has been removed, the number of available even cards decreases by 1.
*   Therefore, the number of possible `chosen_card`s is $(N / 2) - 1$.

**Case 2: $X$ is an odd number.**
If $X$ is odd, then for `(chosen_card + X)` to be even, `chosen_card` must also be an odd number.
We need to count how many odd cards are available in the deck (from 1 to $N$), *excluding* the card $X$ which has already been removed.

*   **Total odd cards in the range [1, N]:** The count of odd numbers in the range [1, N] is given by $(N + 1) / 2$ (using integer division). For example, if $N=5$, odds are {1, 3, 5}, count = $(5+1)/2 = 3$. If $N=6$, odds are {1, 3, 5}, count = $(6+1)/2 = 3$.
*   Since $X$ is an odd card and it has been removed, the number of available odd cards decreases by 1.
*   Therefore, the number of possible `chosen_card`s is $((N + 1) / 2) - 1$.

The solution directly implements these two cases by checking the parity of $X$.

## Complexity Analysis

*   **Time Complexity**: The `solve()` function involves a few arithmetic operations (division, addition, subtraction) and a conditional check (`if-else`). All these operations take constant time, $O(1)$. The `main()` function iterates `T` times, calling `solve()` for each test case. Thus, the total time complexity is $O(T)$.

*   **Space Complexity**: The solution uses a fixed number of integer variables (`N`, `X`, `result`, `T`). The memory usage does not scale with the input size. Therefore, the space complexity is $O(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes most standard libraries

// It's common in competitive programming to use the entire std namespace
using namespace std;

void solve() {
    int N, X;
    cin >> N >> X; // Read N and X

    int result;
    if (X % 2 == 0) { // If X is an even number
        // For the sum (chosen_card + X) to be even, chosen_card must also be even.
        // We need to count the number of even cards remaining in the deck.
        // Total even cards in the range [1, N] is N / 2 (integer division).
        // Since X is an even card and it's removed, the count of available even cards decreases by 1.
        result = (N / 2) - 1;
    } else { // If X is an odd number
        // For the sum (chosen_card + X) to be even, chosen_card must also be odd.
        // We need to count the number of odd cards remaining in the deck.
        // Total odd cards in the range [1, N] is (N + 1) / 2 (integer division).
        // Since X is an odd card and it's removed, the count of available odd cards decreases by 1.
        result = ((N + 1) / 2) - 1;
    }
    cout << result << "\n"; // Output the result followed by a newline
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) { // Loop T times
        solve(); // Call the solve function for each test case
    }

    return 0; // Indicate successful execution
}
```