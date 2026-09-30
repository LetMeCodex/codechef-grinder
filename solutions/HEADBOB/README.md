# Tanu and Head-bob (HEADBOB)
- **Difficulty Rating**: 1065
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine if a person is "INDIAN", "NOT INDIAN", or "NOT SURE" based on a sequence of head gestures. The gestures are represented by characters: 'I' for nodding, 'N' for shaking, and 'Y' for a specific type of head movement.

The rules are:
1. If the sequence contains at least one 'I', the person is INDIAN.
2. If the sequence does not contain 'I' but contains at least one 'Y', the person is NOT INDIAN.
3. If the sequence contains neither 'I' nor 'Y' (meaning it only contains 'N's), the person is NOT SURE.

We are given `T` test cases, and for each test case, we receive an integer `N` (the length of the gesture sequence) and a string `s` representing the sequence of gestures.

## Intuition & Mathematical Observation

The problem statement directly provides the logic required to solve it. There isn't a complex mathematical observation needed here; it's more about careful interpretation of the rules.

The core idea is to check for the presence of specific characters in the input string `s`.

1.  **Priority of 'I'**: The presence of 'I' is the strongest indicator. If we find even a single 'I', we immediately know the person is INDIAN, and no further checks are necessary for that test case.

2.  **Fallback to 'Y'**: If we iterate through the entire string and do *not* find any 'I', we then consider the presence of 'Y'. If we find at least one 'Y' in this scenario (where 'I' is absent), the person is NOT INDIAN.

3.  **Default to 'N'**: If, after checking for both 'I' and 'Y', we find neither, it implies the string consists solely of 'N's. In this case, we cannot definitively classify the person, so the answer is NOT SURE.

This leads to a straightforward algorithm: iterate through the string, keeping track of whether an 'I' or a 'Y' has been encountered.

## Complexity Analysis

Let $N$ be the length of the gesture string for a single test case.

-   **Time Complexity**: $O(N)$
    For each test case, we iterate through the input string `s` of length $N$ exactly once to check for the presence of 'I' and 'Y'. The operations inside the loop (character comparison and flag updates) take constant time. Therefore, the time complexity for processing one test case is linear with respect to the length of the string. If there are $T$ test cases, the total time complexity is $O(T \cdot N_{max})$, where $N_{max}$ is the maximum length of the string across all test cases.

-   **Space Complexity**: $O(1)$
    We use a few boolean flags (`found_I`, `found_Y`) and integer variables (`N`, `T`) to store information. The amount of memory used does not depend on the input size $N$. Therefore, the space complexity is constant.

## Solution Code

```cpp
#include <iostream> // Required for input/output operations (cin, cout)
#include <string>   // Required for string manipulation
#include <vector>   // Not strictly needed for this problem, but often included with <bits/stdc++.h>
#include <algorithm> // Not strictly needed for this problem, but often included with <bits/stdc++.h>

// For competitive programming, it's common to include <bits/stdc++.h>
// which pulls in many standard library headers.
// #include <bits/stdc++.h> 

void solve() {
    int N;
    std::cin >> N; // Read the number of gestures
    std::string s;
    std::cin >> s; // Read the string of gestures

    bool found_I = false; // Flag to track if an 'I' gesture is found
    bool found_Y = false; // Flag to track if a 'Y' gesture is found

    // Iterate through each character in the gesture string
    for (char c : s) {
        if (c == 'I') {
            found_I = true; // Set flag if 'I' is found
        } else if (c == 'Y') {
            found_Y = true; // Set flag if 'Y' is found
        }
        // 'N' gestures do not change the flags, so no specific action is needed for 'N'.
    }

    // Apply the logic based on the flags
    if (found_I) {
        // If an 'I' gesture was found, the person must be INDIAN.
        std::cout << "INDIAN\n";
    } else if (found_Y) {
        // If no 'I' gesture was found, but a 'Y' gesture was found,
        // the person must be NOT INDIAN (foreigner).
        std::cout << "NOT INDIAN\n";
    } else {
        // If neither 'I' nor 'Y' gestures were found, it means only 'N' gestures were made.
        // In this case, we cannot be sure.
        std::cout << "NOT SURE\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
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