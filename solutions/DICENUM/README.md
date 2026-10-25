# [Dice Number (DICENUM)](https://www.codechef.com/problems/DICENUM)
- **Difficulty Rating**: 994
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem describes a game played by Alice and Bob. Each player rolls three standard six-sided dice. After rolling, each player must arrange their three dice rolls to form the largest possible 3-digit number. The player who forms the larger number wins. If both players form the same number, it's a tie. We need to determine the winner (Alice, Bob, or Tie) for several test cases.

## Intuition & Mathematical Observation

The core of this problem lies in understanding how to form the largest possible 3-digit number from three given digits.

1.  **Forming the Largest Number**: To construct the largest 3-digit number from three distinct digits (say `d1, d2, d3`), we should place the largest digit in the hundreds place, the second largest in the tens place, and the smallest digit in the units place. For example, if the rolls are `1, 5, 2`, the largest number is `521`. This principle holds even if the digits are not distinct (e.g., `3, 3, 5` would form `533`).
    This means we need to sort the three dice rolls in *descending* order. If the sorted rolls are `r1, r2, r3` (where `r1 >= r2 >= r3`), the number formed will be `r1 * 100 + r2 * 10 + r3`.

2.  **Comparison**: Once both Alice and Bob have formed their respective largest 3-digit numbers using this method, we simply compare these two numbers:
    *   If Alice's number is greater than Bob's number, Alice wins.
    *   If Bob's number is greater than Alice's number, Bob wins.
    *   If their numbers are equal, it's a tie.

**Algorithm Steps:**
1.  For Alice:
    a. Read her three dice rolls.
    b. Sort these three rolls in descending order.
    c. Calculate her score: `(first_sorted_roll * 100) + (second_sorted_roll * 10) + (third_sorted_roll)`.
2.  Repeat steps 1a-1c for Bob to get his score.
3.  Compare Alice's score and Bob's score and print the appropriate winner ("Alice", "Bob", or "Tie").

## Complexity Analysis

Let $T$ be the number of test cases.
For each test case:
*   **Reading Input**: We read 3 integers for Alice and 3 integers for Bob. This is a constant number of operations, $O(1)$.
*   **Sorting**: We sort 3 integers for Alice and 3 integers for Bob. Sorting a fixed small number of elements (like 3) takes constant time, $O(1)$. In general, sorting $N$ elements takes $O(N \log N)$, but for $N=3$, it's effectively $O(1)$.
*   **Calculating Score**: This involves a few multiplications and additions, which is $O(1)$.
*   **Comparison**: Comparing two integers is $O(1)$.

Therefore, for a single test case, the operations are all constant time.

-   **Time Complexity**: $O(T)$
    Since each test case takes constant time, the total time complexity is proportional to the number of test cases.
-   **Space Complexity**: $O(1)$
    We use a fixed-size vector (or array) of 3 integers for Alice's rolls and another for Bob's rolls, along with a few integer variables. The memory usage does not grow with the input size (as the number of rolls per player is fixed at 3).

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes most standard libraries like iostream, vector, algorithm

// Using namespace std; is common in competitive programming to avoid std:: prefix
using namespace std;

// Function to solve a single test case
void solve() {
    // Declare vectors to store Alice's and Bob's dice rolls
    vector<int> alice_rolls(3);
    vector<int> bob_rolls(3);

    // Read Alice's three dice rolls
    cin >> alice_rolls[0] >> alice_rolls[1] >> alice_rolls[2];
    // Read Bob's three dice rolls
    cin >> bob_rolls[0] >> bob_rolls[1] >> bob_rolls[2];

    // Sort Alice's rolls in descending order to form the largest possible number.
    // rbegin() and rend() provide reverse iterators, which makes std::sort
    // arrange elements from largest to smallest.
    sort(alice_rolls.rbegin(), alice_rolls.rend());
    // Calculate Alice's score: The largest digit goes to the hundreds place,
    // the second largest to the tens place, and the smallest to the units place.
    int alice_score = alice_rolls[0] * 100 + alice_rolls[1] * 10 + alice_rolls[2];

    // Sort Bob's rolls in descending order using the same logic.
    sort(bob_rolls.rbegin(), bob_rolls.rend());
    // Calculate Bob's score.
    int bob_score = bob_rolls[0] * 100 + bob_rolls[1] * 10 + bob_rolls[2];

    // Compare the calculated scores to determine the winner or a tie.
    if (alice_score > bob_score) {
        cout << "Alice\n"; // Alice wins if her score is higher
    } else if (bob_score > alice_score) {
        cout << "Bob\n";   // Bob wins if his score is higher
    } else {
        cout << "Tie\n";   // It's a tie if scores are equal
    }
}

int main() {
    // Optimize C++ standard streams for competitive programming.
    // ios_base::sync_with_stdio(false) disables synchronization with C's stdio library,
    // which can speed up I/O operations.
    // cin.tie(NULL) unties cin from cout, meaning cin will not flush cout before reading input,
    // further speeding up I/O.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t; // Read the number of test cases
    while (t--) { // Loop through each test case
        solve(); // Call the solve function for the current test case
    }

    return 0; // Indicate successful execution
}
```