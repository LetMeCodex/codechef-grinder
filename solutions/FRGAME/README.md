# [Game between friends (FRGAME)](https://www.codechef.com/problems/FRGAME)
- **Difficulty Rating**: 991
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem describes a game played by two main players, Nitin and Sobhagya, who start with a certain number of coins. Two other friends, Ritik and Satyarth, then intervene by giving coins to one of the main players.

Here's a breakdown of the game rules:
1.  **Initial State**: Nitin starts with `A` coins, and Sobhagya starts with `B` coins.
2.  **Ritik's Turn**: Ritik gives `C` coins. The recipient is determined by who is *not currently winning*.
    *   If Sobhagya has strictly more coins than Nitin (`B > A`), Nitin is considered "not winning" and receives `C` coins.
    *   Otherwise (if Nitin has more or equal coins, `A >= B`), Sobhagya is considered "not winning" and receives `C` coins.
3.  **Satyarth's Turn**: After Ritik's turn and the coin counts are updated, Satyarth gives `D` coins. The recipient is again determined by who is *not currently winning* based on the *current* (updated) coin counts.
    *   If Sobhagya has strictly more coins than Nitin (`B > A`), Nitin receives `D` coins.
    *   Otherwise (`A >= B`), Sobhagya receives `D` coins.
4.  **Final Winner**: After both Ritik and Satyarth have given their coins, the player with more coins wins. If both players have an equal number of coins, Nitin is declared the winner. The output should be 'N' for Nitin or 'S' for Sobhagya.

## Intuition & Mathematical Observation

The problem is a straightforward simulation. There are no complex algorithms, data structures, or deep mathematical insights required. The core idea is to follow the rules precisely step-by-step:

1.  **Direct Simulation**: We need to maintain the coin counts for Nitin (`A`) and Sobhagya (`B`) and update them according to the rules.
2.  **Sequential Updates**: Ritik's action modifies `A` or `B`. Satyarth's decision is then based on these *newly updated* values of `A` and `B`. It's crucial not to use the initial `A` and `B` for Satyarth's turn.
3.  **"Not Winning" Condition**: The condition for determining who receives coins (`B > A` for Sobhagya winning, `A >= B` for Nitin winning/tied) is consistent throughout the game. This also implicitly handles the tie-breaking rule for who receives coins.
4.  **Final Winner Condition**: The final winner is determined by comparing the final coin counts using the same logic: if `B > A`, Sobhagya wins; otherwise (`A >= B`), Nitin wins.

By simply implementing these conditional updates and comparisons, we can arrive at the correct winner for each test case.

## Complexity Analysis

-   **Time Complexity**: For each test case, the solution performs a fixed number of operations: reading four integers, two `if-else` statements involving comparisons and additions, and one final `if-else` statement for output. This means the processing time for a single test case is constant, $O(1)$. Since there are `T` test cases, the total time complexity will be $O(T)$.

-   **Space Complexity**: The solution uses a fixed number of integer variables (`A`, `B`, `C`, `D`, `T`) to store input values and intermediate coin counts. The memory usage does not depend on the magnitude of the input values or any other variable factor. Therefore, the space complexity is $O(1)$.

## Solution Code

```cpp
#include <iostream> // Required for standard input/output operations (cin, cout)

// Function to solve a single test case
void solve() {
    int A, B, C, D;
    // Read the initial number of coins for Nitin (A) and Sobhagya (B),
    // and the coins Ritik (C) and Satyarth (D) will give.
    std::cin >> A >> B >> C >> D;

    // --- Ritik's turn ---
    // Determine who is currently winning based on A and B.
    // Sobhagya wins if B > A. Nitin wins if A >= B.
    // Ritik gives C coins to the player who is NOT winning.
    if (B > A) {
        // Sobhagya is winning, so Nitin is not winning.
        // Nitin receives C coins.
        A += C;
    } else {
        // Nitin is winning (A >= B), so Sobhagya is not winning.
        // Sobhagya receives C coins.
        B += C;
    }

    // --- Satyarth's turn ---
    // Determine who is currently winning based on the UPDATED A and B.
    // Satyarth gives D coins to the player who is NOT winning.
    if (B > A) {
        // Sobhagya is currently winning, so Nitin is not winning.
        // Nitin receives D coins.
        A += D;
    } else {
        // Nitin is currently winning (A >= B), so Sobhagya is not winning.
        // Sobhagya receives D coins.
        B += D;
    }

    // --- Determine the final winner ---
    // After both Ritik and Satyarth have given their coins,
    // check the final coin counts.
    if (B > A) {
        // Sobhagya has more coins, so Sobhagya is the final winner.
        std::cout << "S\n";
    } else {
        // Nitin has more or equal coins, so Nitin is the final winner.
        std::cout << "N\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) prevents cin from flushing cout before each input operation.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    // Read the number of test cases.
    std::cin >> T;
    // Loop through each test case.
    while (T--) {
        solve(); // Call the solve function for each test case.
    }

    return 0; // Indicate successful execution.
}
```