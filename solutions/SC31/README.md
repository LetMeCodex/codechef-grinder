# [Weapon Value (SC31)](https://www.codechef.com/problems/SC31)
- **Difficulty Rating**: 1204
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem describes a tournament with `N` participants. Each participant possesses a set of weapons, which is represented by a 10-digit binary string. A '1' at the `i`-th position (0-indexed) indicates the participant has weapon type `i+1`, and '0' means they don't. The winner of the tournament is determined by combining all participants' weapon sets according to a specific rule: the winner possesses a weapon type `X` if and only if an **odd** number of participants possess weapon type `X`. The task is to find the total number of distinct weapon types the winner possesses.

## Intuition & Mathematical Observation
The core of this problem lies in the condition: "a weapon type `X` is part of the winner's set if an **odd** number of participants possess weapon type `X`." This specific property is a direct application of the **XOR (exclusive OR)** bitwise operation.

Let's consider a single weapon type (e.g., weapon type 1) and how its presence is determined for the winner:
*   **XOR Property**:
    *   `0 XOR 0 = 0`
    *   `0 XOR 1 = 1`
    *   `1 XOR 0 = 1`
    *   `1 XOR 1 = 0`

*   **Applying to the problem**:
    If we XOR a bit representing the presence (1) or absence (0) of a specific weapon type across all participants:
    *   If an **even** number of participants have weapon type `X`, the cumulative XOR for that weapon type will be `0`. For example, `1 XOR 1 = 0`, `1 XOR 1 XOR 1 XOR 1 = 0`.
    *   If an **odd** number of participants have weapon type `X`, the cumulative XOR for that weapon type will be `1`. For example, `1 = 1`, `1 XOR 1 XOR 1 = 1`.

This perfectly matches the problem's requirement: a weapon is present in the winner's set if an odd number of participants have it.

Given that there are only 10 distinct weapon types, we can efficiently represent each participant's weapon set using a **bitmask**. A 10-bit integer can represent all 10 weapon types, where the `j`-th bit (0-indexed) corresponds to weapon type `j+1`. If the `j`-th bit is set (1), the participant has weapon `j+1`; otherwise, they don't.

The algorithm then becomes:
1.  Initialize a `final_weapon_mask` to `0`. This mask will accumulate the XOR sum of all participants' weapon sets.
2.  For each participant:
    a.  Read their 10-digit binary string `S`.
    b.  Convert this string `S` into a `current_participant_mask`. This is done by iterating through the string: if `S[j]` is '1', set the `j`-th bit in `current_participant_mask` using the bitwise OR operation (`|= (1 << j)`).
    c.  XOR the `current_participant_mask` with the `final_weapon_mask`: `final_weapon_mask ^= current_participant_mask`. This step effectively combines the current participant's weapons into the running total according to the symmetric difference rule.
3.  After processing all `N` participants, the `final_weapon_mask` will hold the combined weapon set of the tournament winner.
4.  The final answer is the number of set bits (1s) in `final_weapon_mask`. This can be efficiently counted using the `__builtin_popcount()` function (a GCC extension), which returns the number of set bits in an integer.

## Complexity Analysis
Let `T` be the number of test cases and `N` be the number of participants in a single test case. The length of the weapon string is fixed at 10.

*   **Time Complexity**:
    *   The `main` function iterates `T` times, calling `solve()` for each test case.
    *   Inside `solve()`:
        *   Reading `N` takes $O(1)$ time.
        *   There's a loop that runs `N` times (once for each participant).
            *   Inside this loop, reading the 10-character string `S` takes $O(10)$ time.
            *   Converting `S` to `current_participant_mask` involves iterating through the 10 characters, taking $O(10)$ time.
            *   The XOR operation (`final_weapon_mask ^= current_participant_mask`) takes $O(1)$ time.
        *   Finally, `__builtin_popcount(final_weapon_mask)` takes $O(1)$ time for a fixed-size integer (like a 32-bit or 64-bit integer, as 10 bits is very small).
    *   Therefore, for each test case, the total time complexity is $O(N \times (10 + 10 + 1)) = O(N \times 21) = O(N)$.
    *   The overall time complexity for `T` test cases is $O(T \times N)$.
    *   Given constraints ($T \le 100$, $N \le 100$), the maximum operations would be approximately $100 \times 100 = 10^4$, which is very efficient and well within typical time limits.

*   **Space Complexity**:
    *   Variables like `N`, `final_weapon_mask`, `current_participant_mask`, `max_weapons`, `T` all occupy constant space, $O(1)$.
    *   The string `S` for reading participant weapons occupies $O(10)$ space, which is also constant.
    *   Thus, the space complexity per test case is $O(1)$.

## Solution Code
```cpp
#include <bits/stdc++.h> // Includes common standard libraries like iostream, string, etc.

// Using namespace std; is common in competitive programming to avoid typing std::
using namespace std;

// Function to solve a single test case
void solve() {
    int N;
    cin >> N; // Read the number of participants

    // Initialize a bitmask to represent the final weapon set.
    // Each bit (0 to 9) corresponds to a weapon type (1 to 10).
    // A bit is '1' if the weapon type is present, '0' otherwise.
    // We use XOR to combine weapon sets, as explained in the problem analysis.
    int final_weapon_mask = 0;

    // Iterate through each participant
    for (int i = 0; i < N; ++i) {
        string S;
        cin >> S; // Read the weapon string for the current participant

        // Convert the current participant's weapon string into a bitmask.
        int current_participant_mask = 0;
        for (int j = 0; j < 10; ++j) {
            if (S[j] == '1') {
                // If the j-th character is '1', it means the participant has
                // weapon type (j+1). Set the j-th bit in their mask.
                current_participant_mask |= (1 << j);
            }
        }

        // XOR the current participant's weapon mask with the running total.
        // This effectively combines their weapons into the final set according
        // to the symmetric difference rule.
        final_weapon_mask ^= current_participant_mask;
    }

    // After processing all participants, final_weapon_mask holds the
    // combined weapon set of the tournament winner.
    // We need to count the number of set bits (1s) in this mask.
    // __builtin_popcount is a GCC extension that efficiently counts set bits in an integer.
    int max_weapons = __builtin_popcount(final_weapon_mask);
    
    // Print the result for the current test case, followed by a newline.
    cout << max_weapons << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is crucial for competitive programming problems with large I/O.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) {
        solve(); // Call the solve function for each test case
    }

    return 0; // Indicate successful execution
}
```