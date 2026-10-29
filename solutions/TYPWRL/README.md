# [Typing World (TYPWRL)](https://www.codechef.com/problems/TYPWRL)
- **Difficulty Rating**: 807
- **Solved in**: 2 attempt(s)

## Problem Summary

The problem asks us to find the maximum number of consecutive characters in a given string `S` that are typed by the same hand. We are provided with the length of `S` (denoted by `N`), and a string `L` of length `M` which contains all the lowercase English letters that are typed by the left hand. All other lowercase English letters are typed by the right hand.

For example, if `S = "apple"` and `L = "aeiou"`, then 'a' is left, 'p' is right, 'l' is right, 'e' is left.
- 'a' (L)
- 'p' (R) - different from 'a'
- 'p' (R) - same as previous 'p'
- 'l' (R) - same as previous 'p'
- 'e' (L) - different from previous 'l'

The sequence of hands would be L, R, R, R, L.
The consecutive streaks are:
- 'a': 1 (L)
- 'p', 'p', 'l': 3 (R)
- 'e': 1 (L)
The maximum consecutive streak is 3.

## Intuition & Mathematical Observation

1.  **Hand Mapping**: The first crucial step is to efficiently determine which hand types each character. Since there are only 26 lowercase English letters, a simple boolean array of size 26 (e.g., `bool is_left_hand[26]`) is perfect. We can initialize all entries to `false` (meaning right hand by default) and then iterate through the string `L`, setting `is_left_hand[c - 'a'] = true` for each character `c` in `L`. This allows for $O(1)$ lookup for any character's hand.

2.  **Consecutive Streak Tracking**: We need to iterate through the input string `S` and keep track of the current streak of characters typed by the same hand.
    *   We'll maintain two variables: `max_consecutive` (to store the overall maximum found so far) and `current_consecutive` (to store the length of the current streak).
    *   We also need to remember the hand that typed the *previous* character to compare it with the *current* character's hand. Let's call this `prev_hand_is_left`.

3.  **Iteration Logic**:
    *   Initialize `max_consecutive = 1` and `current_consecutive = 1` because `N >= 1`, so there will always be at least one character, forming a streak of at least 1.
    *   Determine `prev_hand_is_left` based on `S[0]`.
    *   Start iterating `S` from the second character (`i = 1` to `N-1`).
    *   For each `S[i]`:
        *   Determine `current_char_is_left` using our `is_left_hand` array.
        *   **If `current_char_is_left == prev_hand_is_left`**: The streak continues. Increment `current_consecutive`.
        *   **If `current_char_is_left != prev_hand_is_left`**: The streak is broken.
            *   Update `max_consecutive = std::max(max_consecutive, current_consecutive)`.
            *   Start a new streak: `current_consecutive = 1`.
            *   Update `prev_hand_is_left = current_char_is_left` for the next comparison.

4.  **Final Check**: After the loop finishes, `current_consecutive` will hold the length of the very last streak in `S`. This streak might be the longest, but it wouldn't have been compared and updated into `max_consecutive` inside the loop (because the loop ended). Therefore, a final comparison `max_consecutive = std::max(max_consecutive, current_consecutive)` is necessary after the loop.

## Complexity Analysis

-   **Time Complexity**:
    *   Reading inputs `N`, `M`, `S`, `L`: This takes $O(N + M)$ time.
    *   Populating the `is_left_hand` array: We iterate through the string `L` once. For each character, we perform a constant time operation (array assignment). This takes $O(M)$ time.
    *   Iterating through string `S` to find the maximum consecutive streak: We iterate through `S` once (from the second character to the end). For each character, we perform constant time operations (array lookup, comparison, increment/assignment). This takes $O(N)$ time.
    *   **Total Time Complexity**: $O(N + M)$ per test case.

-   **Space Complexity**:
    *   Storing input strings `S` and `L`: This requires $O(N + M)$ space.
    *   Storing the `is_left_hand` array: This is a boolean array of fixed size 26. This is considered $O(1)$ constant space, as its size does not depend on the input `N` or `M`.
    *   Other variables (`N`, `M`, `max_consecutive`, `current_consecutive`, `prev_hand_is_left`, etc.): These take $O(1)$ space.
    *   **Total Space Complexity**: $O(N + M)$.

## Solution Code

```cpp
#include <iostream> // For std::cin, std::cout, std::ios_base, std::endl (or "\n")
#include <string>   // For std::string
// No need for <vector> or <algorithm> with the changes below

void solve() {
    int N, M;
    std::cin >> N >> M;
    std::string S;
    std::cin >> S;
    std::string L;
    std::cin >> L;

    // Use a raw boolean array for maximum efficiency and to avoid any potential
    // (though unlikely for 26 elements) overheads of std::vector<bool> specialization.
    // Initialize all elements to false.
    bool is_left_hand[26] = {false}; 
    for (char c : L) {
        is_left_hand[c - 'a'] = true;
    }

    // Constraints state N >= 1, so S will never be empty.
    // Initialize max_consecutive and current_consecutive based on the first character.
    int max_consecutive = 1;
    int current_consecutive = 1;
    
    // Determine the hand for the first character in S.
    bool prev_hand_is_left = is_left_hand[S[0] - 'a'];

    // Iterate through the string S starting from the second character.
    for (int i = 1; i < N; ++i) {
        char current_char = S[i];
        bool current_char_is_left = is_left_hand[current_char - 'a'];

        if (current_char_is_left == prev_hand_is_left) {
            // The current character is typed by the same hand as the previous one.
            // Continue the streak.
            current_consecutive++;
        } else {
            // The current character is typed by a different hand.
            // The streak is broken. Update max_consecutive with the length of the just-finished streak.
            if (current_consecutive > max_consecutive) {
                max_consecutive = current_consecutive;
            }
            
            // Start a new streak with the current character.
            current_consecutive = 1;
            // Update the hand for the previous character to the current character's hand.
            prev_hand_is_left = current_char_is_left;
        }
    }

    // After the loop, the last streak's length needs to be compared with max_consecutive
    // because it might be the longest streak and wouldn't have been updated inside the loop
    // if it continued until the end of the string.
    if (current_consecutive > max_consecutive) {
        max_consecutive = current_consecutive;
    }

    std::cout << max_consecutive << "\n"; // Use "\n" instead of std::endl for potentially faster output
}

int main() {
    // Enable fast I/O for competitive programming.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T; // Read the number of test cases.
    while (T--) {
        solve(); // Solve each test case.
    }

    return 0;
}
```