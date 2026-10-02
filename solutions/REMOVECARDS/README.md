# [Card Removal (REMOVECARDS)](https://www.codechef.com/problems/REMOVECARDS)
- **Difficulty Rating**: 1039
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to find the minimum number of cards to remove from a given set of `N` cards such that all the remaining cards show the same number. The numbers on the cards (`A_i`) are integers between 1 and 10, inclusive.

## Intuition & Mathematical Observation

The core idea is to end up with a collection of cards where every card displays the identical number. To achieve this while minimizing the number of cards removed, we should aim to *maximize* the number of cards we *keep*.

Consider the numbers present on the cards. If we decide to keep only cards showing the number `X`, then all cards that do *not* show `X` must be removed. To maximize the number of cards kept, we should choose `X` to be the number that appears most frequently in the initial set of cards.

Let's say the number `Y` appears `K` times, and this `K` is the highest frequency among all numbers (1 through 10). If we choose to keep all cards showing `Y`, we will keep `K` cards. All other `N - K` cards (which show numbers other than `Y`) must be removed.

Since `K` is the maximum frequency, we cannot keep more than `K` cards of any single number. Therefore, keeping `K` cards and removing `N - K` cards is the optimal strategy, resulting in the minimum possible removals.

The algorithm is thus:
1. Count the frequency of each number (1-10) present in the input cards.
2. Find the maximum frequency among all these counts. Let this be `max_freq`.
3. The minimum number of cards to remove is `N - max_freq`.

**Example:**
Suppose `N = 5` and the cards are `[1, 2, 1, 3, 1]`.
- Frequencies:
    - Number 1: 3 times
    - Number 2: 1 time
    - Number 3: 1 time
- The maximum frequency (`max_freq`) is 3 (for the number 1).
- To minimize removals, we keep all three cards showing '1'.
- The number of cards to remove is `N - max_freq = 5 - 3 = 2`. (We remove the '2' and the '3').

## Complexity Analysis

-   **Time Complexity**: $O(N)$
    -   Reading `N` and `T` (number of test cases) takes $O(1)$ time.
    -   Initializing the `counts` vector (size 11) takes constant time, $O(1)$.
    -   The loop iterates `N` times to read each card. Inside the loop, operations like array access, increment, and comparison are all $O(1)$. Thus, processing all `N` cards takes $O(N)$ time.
    -   Finding the maximum frequency is done concurrently within the same loop, without additional iterations.
    -   Printing the result is $O(1)$.
    -   Since there are `T` test cases, the total time complexity is $O(T \cdot N)$. Given the constraints ($N \le 100$, $T \le 1000$), $T \cdot N \le 1000 \cdot 100 = 10^5$, which is well within typical time limits.

-   **Space Complexity**: $O(1)$
    -   The `counts` vector stores frequencies for numbers 1 through 10. Its size is fixed at 11 (to cover indices 0-10), regardless of `N`. This is constant space.
    -   All other variables (`N`, `A_i`, `max_freq`, `T`) also occupy constant space.
    -   Therefore, the total space complexity is $O(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h> 

// It's common practice in competitive programming to use the entire standard namespace
// for brevity, especially in single-file solutions.
using namespace std;

// Function to solve a single test case
void solve() {
    int N;
    cin >> N; // Read the number of cards
    
    // A_i values are constrained to be between 1 and 10.
    // We can use a fixed-size array (or std::vector) to store frequencies.
    // `counts[k]` will store the number of times `k` appears.
    // Size 11 is used to cover indices 0 through 10. We'll use indices 1-10.
    vector<int> counts(11, 0); 
    
    // `max_freq` will store the maximum frequency found among all card numbers.
    // Initialize to 0, as no cards have been processed yet.
    int max_freq = 0; 
    
    // Loop N times to read each card and update its frequency
    for (int i = 0; i < N; ++i) {
        int A_i;
        cin >> A_i; // Read the number on the current card
        
        // Increment the frequency for the number A_i
        counts[A_i]++; 
        
        // After updating the count for A_i, check if it's the new maximum frequency.
        // This way, `max_freq` always holds the highest frequency encountered so far.
        if (counts[A_i] > max_freq) {
            max_freq = counts[A_i];
        }
    }
    
    // The goal is to have all remaining cards show the same number.
    // To minimize moves, we should choose the number that appears most frequently
    // and keep all cards with that number. All other cards must be removed.
    // The number of cards to keep is `max_freq`.
    // The total number of cards is `N`.
    // So, the number of cards to remove (minimum moves) is `N - max_freq`.
    cout << N - max_freq << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // `ios_base::sync_with_stdio(false)` unties C++ streams from C standard streams.
    // `cin.tie(NULL)` prevents `cin` from flushing `cout` before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T; // Read the number of test cases
    while (T--) { // Loop through each test case
        solve(); // Call the solve function for the current test case
    }
    
    return 0; // Indicate successful execution
}
```