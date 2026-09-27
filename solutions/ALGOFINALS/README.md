# [Algomaniac Finals (ALGOFINALS)](https://www.codechef.com/problems/ALGOFINALS)
- **Difficulty Rating**: 279
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem states that the Algomaniac finals are held on March 17th. Shreyan is available on a specific day, represented by an integer `X`. We need to determine if Shreyan can attend the finals, which means checking if his available day `X` is the same as the finals day.

## Intuition & Mathematical Observation
The core of this problem is a simple comparison. The Algomaniac finals are fixed on a specific date, which is March 17th. Shreyan's availability is given as an integer `X`. To determine if Shreyan can attend, we just need to check if the value of `X` is equal to 17.

Mathematically, this can be expressed as:
If $X = 17$, then Shreyan can attend.
If $X \neq 17$, then Shreyan cannot attend.

This is a direct conditional check.

## Complexity Analysis
- **Time Complexity**: $O(1)$
The solution involves reading a single integer and performing a single comparison. These operations take constant time, regardless of the input value of `X`.

- **Space Complexity**: $O(1)$
The solution uses a fixed amount of memory to store the input variable `X` and for standard input/output operations. This memory usage does not grow with the input size.

## Solution Code
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
    // Optimize C++ standard streams for competitive programming.
    // This unties cin from cout and prevents synchronization with C's stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int X; // Declare an integer variable to store the day Shreyan can go.
    cin >> X; // Read the input value for X.

    // The Algomaniac finals are held on March 17.
    // We need to check if Shreyan's available day (X) is the same as the finals day.
    if (X == 17) {
        // If X is 17, Shreyan can attend the finals.
        cout << "YAY\n";
    } else {
        // Otherwise, Shreyan cannot attend the finals.
        cout << "NO\n";
    }

    return 0; // Indicate successful program execution.
}
```