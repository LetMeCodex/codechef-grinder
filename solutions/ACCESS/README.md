# [Access Control (ACCESS)](https://www.codechef.com/problems/ACCESS)
- **Difficulty Rating**: 1096
- **Solved in**: 2 attempt(s)

## Problem Summary
The problem asks us to determine if a sequence of operations on a card is valid. The card starts with 0 swipes. There are two types of operations:
1.  **'1'**: This operation renews the card, setting the number of available swipes to $X$.
2.  **'0'**: This operation represents a swipe. It can only be performed if the card has at least 1 swipe available. If performed, it decrements the number of available swipes by 1.

We are given the number of operations $N$, the renewal swipe count $X$, and a string $S$ representing the sequence of operations. We need to output "YES" if the entire sequence of operations can be performed successfully, and "NO" otherwise.

## Intuition & Mathematical Observation

The core of the problem lies in tracking the number of available swipes on the card. The card starts with 0 swipes.

*   When an operation '1' occurs, the number of swipes is reset to $X$. This is a straightforward update.
*   When an operation '0' occurs, we need to check if there's at least one swipe available.
    *   If `current_swipes > 0`, we can perform the swipe, and the number of swipes decreases by 1.
    *   If `current_swipes == 0`, we cannot perform the swipe, and the entire sequence becomes invalid.

The problem can be modeled as simulating the process. We maintain a variable, say `current_swipes`, initialized to 0. We iterate through the given string $S$. For each character:
*   If it's '1', we update `current_swipes = X`.
*   If it's '0', we check if `current_swipes > 0`. If it is, we decrement `current_swipes`. If `current_swipes` is 0, we immediately know the sequence is invalid and can stop processing, outputting "NO".

If we successfully process all operations in the string $S$ without encountering a situation where a '0' operation is attempted with 0 swipes, then the sequence is valid, and we output "YES".

There isn't a complex mathematical formula needed here; it's a direct simulation of the state changes. The key observation is that the state (number of swipes) only depends on the previous state and the current operation.

## Complexity Analysis

*   **Time Complexity**: $O(N)$
    The solution iterates through the input string $S$ of length $N$ exactly once. Inside the loop, operations (comparison, assignment, decrement) take constant time. Therefore, the total time complexity is directly proportional to the length of the string $N$.

*   **Space Complexity**: $O(1)$
    The solution uses a few variables to store $N$, $X$, the current number of swipes, and the input string $S$. The space required for these variables is constant and does not grow with the input size $N$. The input string $S$ itself takes $O(N)$ space, but this is considered input space, not auxiliary space used by the algorithm. The auxiliary space complexity is $O(1)$.

## Solution Code

```cpp
#include <iostream>
#include <string>
#include <vector> // Not strictly needed, but good practice to include specific headers

void solve() {
    int N; // Number of operations
    int X; // Renewal swipe count
    std::cin >> N >> X;
    std::string S; // Sequence of operations
    std::cin >> S;

    int current_swipes = 0; // Card starts with 0 swipes

    // Iterate through each operation in the sequence
    for (char op : S) {
        if (op == '1') {
            // Operation '1': Renewal. Set current swipes to X.
            current_swipes = X;
        } else { // op == '0'
            // Operation '0': Swipe. Requires at least 1 swipe.
            if (current_swipes > 0) {
                // If swipes are available, decrement the count.
                current_swipes--;
            } else {
                // If no swipes are available, the sequence is invalid.
                // Print "NO" and return immediately for this test case.
                std::cout << "NO\n";
                return;
            }
        }
    }

    // If the loop completes without returning "NO", it means all operations were valid.
    // Print "YES".
    std::cout << "YES\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C stdio.
    // std::cin.tie(NULL) unties cin from cout, meaning cin operations won't flush cout.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T; // Number of test cases
    std::cin >> T;
    while (T--) {
        solve(); // Solve each test case
    }

    return 0;
}
```