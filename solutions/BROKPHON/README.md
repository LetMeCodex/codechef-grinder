# Broken Telephone (BROKPHON)
- **Difficulty Rating**: 1204
- **Solved in**: 1 attempt(s)

## Problem Summary
In a line of $N$ players, the first player receives an initial message. Each subsequent player receives a message from the player before them. If a player receives a message that is different from the message they whisper to the next player, then either the player misheard or they whispered incorrectly. We are given the sequence of messages received by each player and need to find the minimum number of players who could be faulty.

## Intuition & Mathematical Observation
The core of the problem lies in identifying discrepancies between consecutive messages. Let $A_i$ be the message received by the $i$-th player.

Consider two adjacent players, player $i$ and player $i+1$.
- Player $i$ receives message $A_i$.
- Player $i+1$ receives message $A_{i+1}$.

If $A_i = A_{i+1}$, it means that the message passed from player $i$ to player $i+1$ was consistent. This doesn't necessarily mean player $i$ is not faulty (they could have misheard and then whispered the correct message they received), but it doesn't *prove* they are faulty based on this pair alone.

However, if $A_i \neq A_{i+1}$, a problem has occurred between player $i$ and player $i+1$. This discrepancy implies that *at least one* of the following must be true:
1. Player $i$ misheard the message from player $i-1$ (if $i>0$) and received $A_i$, but then whispered a different message to player $i+1$.
2. Player $i$ received the correct message $A_i$ from player $i-1$, but player $i+1$ misheard $A_i$ and received $A_{i+1}$ instead.

In simpler terms, if the message received by player $i$ ($A_i$) is different from the message received by player $i+1$ ($A_{i+1}$), then either player $i$ is faulty (whispered incorrectly) or player $i+1$ is faulty (misheard).

The problem asks for the *minimum* number of players who *could* be faulty. If $A_i \neq A_{i+1}$, we know that *at least one* of player $i$ or player $i+1$ is faulty. To minimize the count, we should assume that *both* players involved in a discrepancy are potentially faulty. If a player is involved in multiple discrepancies, we only count them once.

Therefore, the strategy is to iterate through all adjacent pairs of players. If the messages they received are different ($A_i \neq A_{i+1}$), we mark both player $i$ and player $i+1$ as potentially faulty. We use a boolean array or a set to keep track of unique faulty players. The final count of unique faulty players is our answer.

## Complexity Analysis
- **Time Complexity**: $O(N)$
  The code iterates through the input array `A` once to check for discrepancies between adjacent elements. Reading the input takes $O(N)$ time. The loop runs $N-1$ times. Therefore, the total time complexity is dominated by these operations and is $O(N)$.

- **Space Complexity**: $O(N)$
  We use a `std::vector<int> A` to store the messages, which takes $O(N)$ space. We also use a `std::vector<bool> is_faulty` to keep track of faulty players, which also takes $O(N)$ space. Thus, the total space complexity is $O(N)$.

## Solution Code
```cpp
#include <iostream> // Required for std::cin, std::cout
#include <vector>   // Required for std::vector

// Function to solve a single test case
void solve() {
    int N;
    std::cin >> N; // Read the number of players

    // Create a vector to store the messages received by each person.
    // A[i] corresponds to the message received by player (i+1).
    // Messages can be up to 10^9, so 'int' is sufficient (typically 32-bit, max ~2*10^9).
    std::vector<int> A(N); 
    for (int i = 0; i < N; ++i) {
        std::cin >> A[i];
    }

    // Create a boolean vector to keep track of players who are potentially faulty.
    // is_faulty[i] will be true if player (i+1) is potentially faulty.
    // Initialize all to false.
    std::vector<bool> is_faulty(N, false);
    int faulty_players_count = 0; // Counter for the total number of unique faulty players

    // Iterate through adjacent pairs of messages.
    // A[i] is the message received by player (i+1).
    // A[i+1] is the message received by player (i+2).
    // The loop runs from i = 0 to N-2, covering all pairs (A[0],A[1]) through (A[N-2],A[N-1]).
    for (int i = 0; i < N - 1; ++i) {
        // If the message received by player (i+1) is different from
        // the message received by player (i+2), a discrepancy occurred.
        if (A[i] != A[i+1]) {
            // This discrepancy means either:
            // 1. Player (i+1) (0-indexed 'i') whispered wrongly.
            // 2. Player (i+2) (0-indexed 'i+1') misheard.
            // In either case, both players are potentially faulty.

            // Mark player (i+1) as faulty if not already marked.
            if (!is_faulty[i]) {
                is_faulty[i] = true;
                faulty_players_count++;
            }
            // Mark player (i+2) as faulty if not already marked.
            if (!is_faulty[i+1]) {
                is_faulty[i+1] = true;
                faulty_players_count++;
            }
        }
    }

    // Output the total count of unique players that could be faulty.
    std::cout << faulty_players_count << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) prevents std::cout from flushing before std::cin reads input.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T; // Read the number of test cases
    while (T--) {
        solve(); // Call the solve function for each test case
    }

    return 0; // Indicate successful execution
}
```