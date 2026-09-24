# Chef and Races (CHEFRACES)
- **Difficulty Rating**: 745
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef is participating in two races, Race X and Race Y. There are two other participants, Participant A and Participant B. We are given the race numbers Chef is participating in (X and Y) and the race numbers Participant A and Participant B are participating in. Chef wins a race if neither Participant A nor Participant B is participating in that race. The goal is to determine the total number of gold medals Chef can win.

## Intuition & Mathematical Observation
The core of the problem lies in understanding the condition for Chef to win a race. Chef wins a race if and only if *neither* of the other two participants (A and B) are in that specific race.

Let's consider Race X:
Chef wins Race X if Participant A is *not* in Race X AND Participant B is *not* in Race X.
Mathematically, this translates to: `X != A` AND `X != B`.

Similarly, for Race Y:
Chef wins Race Y if Participant A is *not* in Race Y AND Participant B is *not* in Race Y.
Mathematically, this translates to: `Y != A` AND `Y != B`.

We need to count the total number of races Chef wins. This means we can initialize a counter for gold medals to 0. Then, we check the condition for Race X. If Chef wins Race X, we increment the gold medal counter. After that, we check the condition for Race Y. If Chef wins Race Y, we increment the gold medal counter again. Finally, we output the total count.

The problem involves multiple test cases, so we need to read the number of test cases and then iterate through each one, applying the logic described above.

## Complexity Analysis
- **Time Complexity**: $O(1)$
  For each test case, we perform a fixed number of comparisons and arithmetic operations (reading four integers, two `if` conditions, and one increment per winning race). This is constant time, regardless of the input values. Since there are $T$ test cases, the total time complexity is $O(T \times 1) = O(T)$. However, if we consider the complexity per test case, it's $O(1)$.

- **Space Complexity**: $O(1)$
  We only use a few integer variables to store the input values and the gold medal count. The memory usage is constant and does not depend on the input size.

## Solution Code
```cpp
#include <bits/stdc++.h> // Required header for competitive programming

// Required namespace
using namespace std;

// Function to solve a single test case
void solve() {
    int X, Y, A, B;
    // Read the four integers for Chef's races (X, Y) and Rival's races (A, B)
    cin >> X >> Y >> A >> B;

    int gold_medals = 0; // Initialize counter for gold medals

    // Check if Chef can win race X
    // Chef wins race X if the arch-rival is not participating in race X
    // This means X must not be A AND X must not be B
    if (X != A && X != B) {
        gold_medals++; // If Chef can win, increment the medal count
    }

    // Check if Chef can win race Y
    // Chef wins race Y if the arch-rival is not participating in race Y
    // This means Y must not be A AND Y must not be B
    if (Y != A && Y != B) {
        gold_medals++; // If Chef can win, increment the medal count
    }

    // Print the total number of gold medals Chef can win for this test case
    cout << gold_medals << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    // Read the number of test cases
    cin >> T;
    // Loop through each test case
    while (T--) {
        solve(); // Call the solve function for the current test case
    }

    return 0; // Indicate successful execution
}
```