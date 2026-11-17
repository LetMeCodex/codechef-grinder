# [Rhythmic Door (RHYDOOR)](https://www.codechef.com/problems/RHYDOOR)
- **Difficulty Rating**: 687
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to count how many times a door opens given a sequence of button presses. The door opens every time a specific button is pressed three consecutive times. After the door opens, the counter for consecutive presses resets to zero. We are given the total number of button presses and the sequence of presses as a string of 'A's and 'B's.

## Intuition & Mathematical Observation

The core of the problem lies in tracking consecutive identical button presses. We need to iterate through the sequence of button presses and maintain a count of how many times the *current* button has been pressed consecutively.

Let's consider an example: `AAABBAAA`.

1.  **A**: First 'A'. Streak of 'A' is 1.
2.  **A**: Second 'A'. Streak of 'A' is 2.
3.  **A**: Third 'A'. Streak of 'A' is 3. The door opens! Reset streak to 0.
4.  **B**: First 'B'. Streak of 'B' is 1.
5.  **B**: Second 'B'. Streak of 'B' is 2.
6.  **A**: Button changed. Start new streak with 'A'. Streak of 'A' is 1.
7.  **A**: Second 'A'. Streak of 'A' is 2.
8.  **A**: Third 'A'. Streak of 'A' is 3. The door opens! Reset streak to 0.

The door opened 2 times.

The key observation is that we only care about the *current* consecutive streak. When the button changes, the previous streak is irrelevant, and we start a new streak with the new button. When a streak reaches a length of 3, we increment our door open count and *immediately* reset the streak counter. This reset is crucial because even if the *next* press is the same button, it's the start of a *new* streak of length 1.

We can implement this by:
1.  Initializing a `door_open_count` to 0.
2.  Keeping track of the `current_button` being pressed consecutively and its `current_streak_length`.
3.  Iterating through the input string `S`.
4.  For each character `press` in `S`:
    *   If `press` is the same as `current_button`, increment `current_streak_length`.
    *   If `press` is different from `current_button` (or if it's the very first press), update `current_button` to `press` and reset `current_streak_length` to 1.
    *   If `current_streak_length` becomes 3, increment `door_open_count` and reset `current_streak_length` to 0.

The initial state of `current_button` should be something that won't match 'A' or 'B' to ensure the first press correctly starts a new streak. A space character or any character other than 'A' or 'B' works.

## Complexity Analysis

-   **Time Complexity**: $O(N)$
    The solution iterates through the input string `S` of length `N` exactly once. All operations inside the loop (comparisons, increments, assignments) take constant time. Therefore, the time complexity is linear with respect to the number of button presses.

-   **Space Complexity**: $O(1)$
    The solution uses a few variables to store the `door_open_count`, `current_button`, and `current_streak_length`. The amount of memory used by these variables is constant and does not depend on the input size `N`. The input string `S` itself takes $O(N)$ space, but this is considered input space, not auxiliary space used by the algorithm. If we consider the input string as part of the space complexity, it would be $O(N)$. However, typically, auxiliary space is what's analyzed, which is $O(1)$ here.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes iostream, string, vector, algorithm, etc.

// As per problem instructions, using namespace std; is allowed.
using namespace std;

// Function to solve a single test case
void solve() {
    int N;
    cin >> N; // Read the number of button presses
    string S;
    cin >> S; // Read the sequence of button presses

    int door_open_count = 0;
    char current_button = ' '; // Stores the button character of the current streak.
                               // Initialized to a character not 'A' or 'B' to ensure the first
                               // press correctly starts a new streak.
    int current_streak_length = 0; // Stores the length of the current consecutive streak.

    // Iterate through each button press in the sequence
    for (int i = 0; i < N; ++i) {
        char press = S[i]; // Get the current button press

        // Check if the current press continues the existing streak
        if (press == current_button) {
            current_streak_length++; // Increment streak length
        } else {
            // If the button changed, or this is the very first press (current_button was ' ')
            // a new streak begins with the current button.
            current_button = press;
            current_streak_length = 1; // Start a new streak of length 1
        }

        // Check if the streak has reached 3 consecutive presses
        if (current_streak_length == 3) {
            door_open_count++; // Increment the count of times the door opened
            
            // The lock immediately resets its counter to zero.
            // This means the current streak is "consumed" to open the door.
            // Any subsequent presses, even if they are the same button,
            // will start a fresh count. Setting current_streak_length to 0
            // achieves this: the next iteration, if 'press' is still 'current_button',
            // will increment it from 0 to 1, effectively starting a new streak.
            current_streak_length = 0; 
        }
    }

    // Print the total number of times the door opened for this test case
    cout << door_open_count << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common competitive programming optimization.
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