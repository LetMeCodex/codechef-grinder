# [Equal Card Game (EQCARDGAME)](https://www.codechef.com/problems/EQCARDGAME)
- **Difficulty Rating**: 1058
- **Solved in**: 1 attempt(s)

## Problem Summary

Alice has a deck of 52 cards. There are `K` people playing a game, including Alice. Alice wants to distribute the cards equally among all `K` people. To do this, she might need to discard some cards. The task is to find the minimum number of cards Alice must discard so that the remaining cards can be distributed equally among `K` people.

## Intuition & Mathematical Observation

Alice starts with 52 cards. She wants to distribute a certain number of cards, let's say `N_remaining`, equally among `K` people. This means `N_remaining` must be perfectly divisible by `K`. In other words, `N_remaining % K` must be equal to 0.

To minimize the number of discarded cards, Alice should aim to keep as many cards as possible. This means `N_remaining` should be the largest possible multiple of `K` that is less than or equal to 52.

Consider the total number of cards, 52. When we divide 52 by `K`, we get a quotient and a remainder:
`52 = (quotient * K) + remainder`

The `remainder` (`52 % K`) represents the number of cards that are "left over" after distributing as many full sets of `K` cards as possible. If Alice discards exactly these `remainder` cards, then the number of remaining cards will be `52 - remainder`, which is `quotient * K`. This quantity is perfectly divisible by `K`.

Since we want to discard the *minimum* number of cards, discarding exactly the `remainder` cards achieves this. Any fewer discards would mean the total number of cards is still not a multiple of `K` (unless the remainder was already 0).

Therefore, the minimum number of cards Alice must discard is simply `52 % K`.

**Example:**
*   If `K = 4`: `52 % 4 = 0`. Alice discards 0 cards. Each person gets `52 / 4 = 13` cards.
*   If `K = 5`: `52 % 5 = 2`. Alice discards 2 cards. `52 - 2 = 50` cards remain. Each person gets `50 / 5 = 10` cards.
*   If `K = 10`: `52 % 10 = 2`. Alice discards 2 cards. `52 - 2 = 50` cards remain. Each person gets `50 / 10 = 5` cards.

## Complexity Analysis

-   **Time Complexity**: $O(1)$ per test case. The `solve()` function performs a constant number of operations (reading an integer, one modulo operation, and printing an integer). Since there are `T` test cases, the total time complexity is $O(T)$.
-   **Space Complexity**: $O(1)$ per test case. The solution uses a constant amount of extra space for variables like `K`, `total_cards`, and `discarded_cards`, regardless of the input value of `K`.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries, as requested

using namespace std; // Uses the standard namespace, as requested

void solve() {
    int K;
    cin >> K; // Read the number of people playing
    
    const int total_cards = 52; // Alice starts with 52 cards
    
    // The minimum number of cards to discard is the remainder when total_cards is divided by K.
    // This remainder represents the 'excess' cards that cannot be distributed equally.
    int discarded_cards = total_cards % K;
    
    cout << discarded_cards << "\n"; // Output the result followed by a newline
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) { // Loop T times for each test case
        solve(); // Call the solve function for each test case
    }

    return 0; // Indicate successful execution
}
```