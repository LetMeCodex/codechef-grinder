# [Malvika is peculiar about color of balloons (CHN09)](https://www.codechef.com/problems/CHN09)
- **Difficulty Rating**: 988
- **Solved in**: 1 attempt(s)

## Problem Summary
Malvika has a string of balloons, where each balloon is either amber ('a') or brass ('b'). She wants to make all balloons the same color. She can flip the color of a balloon from 'a' to 'b' or 'b' to 'a'. The goal is to find the minimum number of flips required to make all balloons the same color.

## Intuition & Mathematical Observation
The problem asks for the minimum number of flips to make all balloons either 'a' or 'b'. There are only two possible target states: all balloons are 'a', or all balloons are 'b'.

Let's consider the two target states:

1.  **Target: All balloons are 'a'.**
    To achieve this, we need to flip every balloon that is currently 'b' to 'a'. The number of flips required is exactly the count of 'b' balloons in the original string.

2.  **Target: All balloons are 'b'.**
    To achieve this, we need to flip every balloon that is currently 'a' to 'b'. The number of flips required is exactly the count of 'a' balloons in the original string.

Since we want the *minimum* number of flips, we should choose the target state that requires fewer operations. Therefore, the minimum number of flips is the smaller of the count of 'a' balloons and the count of 'b' balloons.

Let $N_a$ be the number of 'a' balloons and $N_b$ be the number of 'b' balloons.
The minimum number of flips is $\min(N_a, N_b)$.

## Complexity Analysis
- **Time Complexity**: $O(L)$, where $L$ is the length of the input string $s$. We iterate through the string once to count the occurrences of 'a' and 'b'. The operations inside the loop (comparison and increment) take constant time.
- **Space Complexity**: $O(1)$. We only use a few integer variables (`count_a`, `count_b`, `t`) to store counts and loop indices, which is constant space regardless of the input string length.

## Solution Code
```cpp
#include <bits/stdc++.h> // Includes iostream, string, algorithm, etc.

using namespace std; // Use standard namespace

void solve() {
    string s;
    cin >> s; // Read the string of balloon colors

    int count_a = 0; // Counter for 'a' (amber) balloons
    int count_b = 0; // Counter for 'b' (brass) balloons

    // Iterate through the string to count 'a's and 'b's
    for (char c : s) {
        if (c == 'a') {
            count_a++;
        } else { // The problem statement guarantees characters are either 'a' or 'b'
            count_b++;
        }
    }

    // The minimum number of flips is the smaller of the two counts.
    // If we want all 'a', we flip 'b's. If we want all 'b', we flip 'a's.
    // We choose the option that requires fewer flips.
    cout << min(count_a, count_b) << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
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