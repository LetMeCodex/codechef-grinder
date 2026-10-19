# [Dark Light (DARLIG)](https://www.codechef.com/problems/DARLIG)
- **Difficulty Rating**: 994
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem describes a "Dark Light" torch with four distinct levels: 1, 2, 3, and 4.
- Levels 1, 2, and 3 correspond to the "On" state.
- Level 4 corresponds to the "Off" state.
Pressing a button changes the torch's level in a cyclic manner: $1 \to 2 \to 3 \to 4 \to 1 \to \dots$.

We are given two integers:
- `N`: The number of times the button is pressed.
- `K`: The initial state of the torch (0 for Off, 1 for On).

Our task is to determine the final state of the torch after `N` presses. The output should be "On", "Off", or "Ambiguous". An "Ambiguous" state occurs if, when the initial state is "On" (meaning it could be at Level 1, 2, or 3), these different possible starting levels lead to different final states (some "On", some "Off").

## Intuition & Mathematical Observation

The core of this problem lies in understanding the cyclic nature of the torch's levels. Since there are 4 levels and the progression is $1 \to 2 \to 3 \to 4 \to 1$, the state of the torch repeats every 4 presses. This means that the effect of `N` presses is equivalent to the effect of `N % 4` presses. Let `rem = N % 4`.

We need to consider two main cases based on the initial state `K`:

### Case 1: Initial state is Off (K = 0)
If the initial state is "Off", the torch *must* be at Level 4. We then track its state after `rem` presses:
- If `rem = 0` (i.e., `N` is a multiple of 4): Starting from Level 4, after `N` presses, the torch will return to Level 4. Level 4 is "Off".
- If `rem = 1`: Starting from Level 4, after 1 press, it goes to Level 1. Level 1 is "On".
- If `rem = 2`: Starting from Level 4, after 2 presses, it goes to Level 2. Level 2 is "On".
- If `rem = 3`: Starting from Level 4, after 3 presses, it goes to Level 3. Level 3 is "On".

**Conclusion for K = 0:**
- If `rem == 0`, the final state is "Off".
- Otherwise (`rem != 0`), the final state is "On".

### Case 2: Initial state is On (K = 1)
If the initial state is "On", the torch *could* be at Level 1, Level 2, or Level 3. We don't know which one. We must check if all these possibilities lead to the same final state.

- **Subcase 2.1: `rem = 0` (N is a multiple of 4)**
    - If starting at Level 1, after `N` presses, it returns to Level 1 ("On").
    - If starting at Level 2, after `N` presses, it returns to Level 2 ("On").
    - If starting at Level 3, after `N` presses, it returns to Level 3 ("On").
    Since all possible initial "On" levels lead to an "On" state, the final state is definitively "On".

- **Subcase 2.2: `rem = 1`**
    - If starting at Level 1, after 1 press, it goes to Level 2 ("On").
    - If starting at Level 2, after 1 press, it goes to Level 3 ("On").
    - If starting at Level 3, after 1 press, it goes to Level 4 ("Off").
    Since some paths lead to "On" and others to "Off", the final state is "Ambiguous".

- **Subcase 2.3: `rem = 2`**
    - If starting at Level 1, after 2 presses, it goes to Level 3 ("On").
    - If starting at Level 2, after 2 presses, it goes to Level 4 ("Off").
    - If starting at Level 3, after 2 presses, it goes to Level 1 ("On").
    Again, some paths lead to "On" and others to "Off", so the final state is "Ambiguous".

- **Subcase 2.4: `rem = 3`**
    - If starting at Level 1, after 3 presses, it goes to Level 4 ("Off").
    - If starting at Level 2, after 3 presses, it goes to Level 1 ("On").
    - If starting at Level 3, after 3 presses, it goes to Level 2 ("On").
    Once more, some paths lead to "On" and others to "Off", making the final state "Ambiguous".

**Conclusion for K = 1:**
- If `rem == 0`, the final state is "On".
- Otherwise (`rem != 0`), the final state is "Ambiguous".

This logic covers all possible scenarios and directly translates to the provided solution code.

## Complexity Analysis

-   **Time Complexity**: $O(T)$
    For each test case, the solution performs a constant number of operations: reading two integers, one modulo operation, a few comparisons, and printing a string. These operations do not depend on the magnitude of `N` or `K`. Since there are `T` test cases, the total time complexity is directly proportional to `T`. Given $T \le 10^5$, this is highly efficient.

-   **Space Complexity**: $O(1)$
    The solution uses a fixed amount of memory to store variables like `N`, `K`, `rem`, and `T`. This memory usage does not grow with the input values or the number of test cases. Therefore, the space complexity is constant.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries

// Use the standard namespace to avoid typing std:: repeatedly
using namespace std; 

// Function to solve a single test case
void solve() {
    int N; // N: number of changes, 0 <= N <= 10^9. Fits in a 32-bit signed int.
    int K; // K: initial state (0 for Off, 1 for On). Fits in int.
    
    // Read N and K for the current test case
    cin >> N >> K;

    // Calculate N modulo 4. This determines the position in the 4-level cycle.
    int rem = N % 4;

    // Case 1: Initial state is Off (K = 0)
    if (K == 0) {
        // If initial state is Off, the torch must be at Level 4.
        // The cycle is 4 -> 1 -> 2 -> 3 -> 4 -> ...
        // After N changes:
        // If N is a multiple of 4 (rem == 0), it returns to Level 4.
        // Level 4 corresponds to Off state.
        if (rem == 0) {
            cout << "Off\n";
        } 
        // If N is not a multiple of 4 (rem != 0), it will be at Level 1, 2, or 3.
        // (e.g., N=1: 4->1; N=2: 4->2; N=3: 4->3)
        // Levels 1, 2, 3 correspond to On state.
        else {
            cout << "On\n";
        }
    } 
    // Case 2: Initial state is On (K = 1)
    else { // K == 1
        // If initial state is On, the torch could be at Level 1, 2, or 3.
        // We need to check if all possible starting levels lead to the same final state.
        // The cycle is 1 -> 2 -> 3 -> 4 -> 1 -> ...
        // If N is a multiple of 4 (rem == 0):
        //   - From Level 1, N changes lead to Level 1 (On).
        //   - From Level 2, N changes lead to Level 2 (On).
        //   - From Level 3, N changes lead to Level 3 (On).
        // In this case, all possible initial levels lead to an On state.
        if (rem == 0) {
            cout << "On\n";
        } 
        // If N is not a multiple of 4 (rem != 0):
        //   - If rem = 1: initial 3 -> final 4 (Off)
        //   - If rem = 2: initial 2 -> final 4 (Off)
        //   - If rem = 3: initial 1 -> final 4 (Off)
        // In all these cases, at least one of the possible initial levels (1, 2, or 3)
        // will lead to Level 4 (Off), while others lead to On.
        // Thus, the final state cannot be determined.
        else {
            cout << "Ambiguous\n";
        }
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // T: number of test cases, 1 <= T <= 10^5
    cin >> T; // Read the number of test cases

    // Loop through each test case
    while (T--) {
        solve(); // Call the solve function for each test case
    }

    return 0; // Indicate successful execution
}
```