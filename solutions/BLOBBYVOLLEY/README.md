# [Blobby Volley Scores (BLOBBYVOLLEY)](https://www.codechef.com/problems/BLOBBYVOLLEY)
- **Difficulty Rating**: 962
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem describes a game of "Blobby Volley" played between two players, Alice ('A') and Bob ('B'). The rules are as follows:
1.  Alice always serves first.
2.  If the player currently serving wins the point, their score increases by 1, and they continue to serve for the next point.
3.  If the player currently receiving (the non-server) wins the point, their score does *not* increase. Instead, they become the new server for the next point.
We are given the total number of points played, `N`, and a string `S` of length `N` where each character ('A' or 'B') indicates who won that particular point. Our task is to calculate and output the final scores of Alice and Bob.

## Intuition & Mathematical Observation

The problem can be solved by directly simulating the game based on the given rules. We need to keep track of three main pieces of information throughout the game:
1.  Alice's current score.
2.  Bob's current score.
3.  Who is the current server.

We can initialize Alice's and Bob's scores to 0. According to the rules, Alice serves first, so we initialize the `current_server` to 'A'.

Then, we iterate through the string `S`, processing each point winner one by one:
-   For each point, let `winner` be the character from `S` indicating who won that point.
-   **Case 1: The `winner` is the `current_server`.**
    -   This means the server successfully defended their serve.
    -   The `current_server`'s score increases by 1.
    -   The `current_server` remains the same for the next point.
-   **Case 2: The `winner` is *not* the `current_server`.**
    -   This means the receiver won the point.
    -   The receiver's score does *not* increase.
    -   The receiver becomes the new `current_server` for the next point. We update `current_server` to `winner`.

After iterating through all points in `S`, the accumulated `alice_score` and `bob_score` will be the final scores. This approach directly translates the game rules into a step-by-step simulation. No complex mathematical observations are required beyond understanding and applying these rules sequentially.

## Complexity Analysis

Let `N` be the length of the input string `S` (the number of points played).
Let `T` be the number of test cases.

-   **Time Complexity**: $O(T \cdot N)$
    -   For each test case, we read the integer `N` and the string `S`. Reading the string takes $O(N)$ time.
    -   We then iterate through the string `S` exactly once using a `for` loop. This loop runs `N` times.
    -   Inside the loop, all operations (character comparison, integer increment, character assignment) are constant time operations, $O(1)$.
    -   Therefore, the total time complexity for one test case is dominated by reading the string and iterating through it, which is $O(N)$.
    -   Since there are `T` test cases, the overall time complexity is $O(T \cdot N)$.

-   **Space Complexity**: $O(N)$
    -   For each test case, we store the input string `S`, which requires $O(N)$ space.
    -   Variables like `n`, `alice_score`, `bob_score`, and `current_server` use a constant amount of memory, $O(1)$.
    -   Thus, the dominant factor for space complexity is storing the input string, making it $O(N)$ per test case.

## Solution Code

```cpp
#include <iostream>
#include <string>
#include <vector>

int main() {
    // Optimize C++ standard streams for faster input/output.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; // Number of test cases
    std::cin >> t;
    while (t--) { // Loop through each test case
        int n; // Number of points played
        std::cin >> n;
        std::string s; // String representing winners of each point
        std::cin >> s;

        int alice_score = 0; // Alice's current score
        int bob_score = 0;   // Bob's current score
        char current_server = 'A'; // Initially Alice is the server

        // Iterate through each point played
        for (char winner : s) {
            if (winner == current_server) {
                // Case 1: Server wins the point
                // Server's score increases
                if (current_server == 'A') {
                    alice_score++;
                } else {
                    bob_score++;
                }
                // Server remains the same for the next point
            } else {
                // Case 2: Receiver wins the point
                // Receiver's score does NOT increase
                // Receiver becomes the new server for the next point
                if (current_server == 'A') {
                    current_server = 'B'; // Alice was server, Bob won, so Bob becomes server
                } else {
                    current_server = 'A'; // Bob was server, Alice won, so Alice becomes server
                }
            }
        }
        // Output the final scores for Alice and Bob
        std::cout << alice_score << " " << bob_score << "\n";
    }
    return 0; // Indicate successful execution
}

```