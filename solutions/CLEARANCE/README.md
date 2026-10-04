# [Clearance Sale (CLEARANCE)](https://www.codechef.com/problems/CLEARANCE)
- **Difficulty Rating**: 392
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef is at a clearance sale where for every 2 t-shirts he buys, he gets a third one for free. Given the number of t-shirts Chef paid for, `X`, determine the total number of t-shirts he receives.

## Intuition & Mathematical Observation
The problem states a clear rule: "for every 2 t-shirts he buys, he gets a third one for free". This implies a ratio of paid t-shirts to free t-shirts.

If Chef pays for 2 t-shirts, he gets 1 free.
If Chef pays for 4 t-shirts, he gets 2 free.
If Chef pays for 6 t-shirts, he gets 3 free.

We can observe a pattern here: the number of free t-shirts is exactly half the number of t-shirts Chef paid for.

Let `X` be the number of t-shirts Chef paid for.
The number of pairs of t-shirts Chef paid for is `X / 2`.
Since each pair of paid t-shirts grants one free t-shirt, the number of free t-shirts is also `X / 2`.

The total number of t-shirts Chef receives is the sum of the t-shirts he paid for and the free t-shirts he received.
Total t-shirts = (T-shirts paid for) + (Free t-shirts)
Total t-shirts = `X` + `X / 2`

The problem statement guarantees that `X` is an even integer, so `X / 2` will always result in an integer, and there's no need to worry about fractional t-shirts.

## Complexity Analysis
- **Time Complexity**: $O(1)$
The solution involves a fixed number of arithmetic operations (one division and one addition) and input/output operations. These operations take constant time, regardless of the input value of `X`.

- **Space Complexity**: $O(1)$
The solution uses a few integer variables (`X`, `free_tshirts`, `total_tshirts`) to store the input and intermediate results. The amount of memory used is constant and does not depend on the input size.

## Solution Code
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
    // Optimize C++ standard streams for competitive programming.
    // This unties cin/cout from the C standard streams and disables synchronization
    // with C's stdio, leading to faster input/output operations.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Declare an integer variable X to store the number of t-shirts Chef paid for.
    // The problem guarantees X is an even integer between 2 and 100.
    int X;

    // Read the value of X from standard input.
    cin >> X;

    // According to the problem statement, for every 2 t-shirts bought,
    // Chef receives a third one for free.
    // This means for every pair of t-shirts Chef paid for, he gets one free.
    // The number of pairs Chef paid for is X / 2.
    // Therefore, the number of free t-shirts Chef receives is X / 2.
    int free_tshirts = X / 2;

    // The total number of t-shirts Chef gets is the sum of t-shirts paid for
    // and the free t-shirts received.
    int total_tshirts = X + free_tshirts;

    // Output the total number of t-shirts Chef received, followed by a newline character.
    cout << total_tshirts << "\n";

    return 0; // Indicate successful execution of the program.
}
```