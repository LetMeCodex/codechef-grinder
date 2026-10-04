# Yoga Day (YOGADAY)
- **Difficulty Rating**: 264
- **Solved in**: 2 attempt(s)

## Problem Summary
The problem asks us to calculate the number of full Surya Namaskar rounds that can be completed given a total number of yoga poses performed. It is stated that a single Surya Namaskar consists of 12 yoga poses.

## Intuition & Mathematical Observation
The core of the problem lies in understanding the relationship between the total number of poses performed and the number of poses in one Surya Namaskar.

If one Surya Namaskar requires 12 poses, and we are given a total of $N$ poses, we want to find out how many times 12 "fits" into $N$. This is a classic division problem.

For example:
- If $N = 12$, we can complete 1 full round ($12 / 12 = 1$).
- If $N = 23$, we can complete 1 full round ($23 / 12 = 1$ with a remainder of 11). We can't complete a second round because we don't have enough poses.
- If $N = 24$, we can complete 2 full rounds ($24 / 12 = 2$).

The number of completed rounds is precisely the integer part of the division of the total number of poses ($N$) by the number of poses per round (12). In integer arithmetic, this is achieved by simple integer division.

Therefore, the formula to calculate the number of completed Surya Namaskar rounds is $N / 12$.

## Complexity Analysis
- **Time Complexity**: $O(1)$
    The solution involves a single integer division operation, which takes constant time regardless of the input size.

- **Space Complexity**: $O(1)$
    The solution uses a fixed amount of memory to store the input variable $N$ and the result. This amount does not grow with the input size.

## Solution Code
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    // Optimize C++ standard streams for competitive programming.
    // Disables synchronization with C's stdio and unties cin from cout.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Declare an integer variable 'n' to store the total number of yoga poses.
    int n;

    // Read the total number of yoga poses from standard input.
    cin >> n;

    // Each Surya Namaskar consists of 12 yoga poses.
    // To find the number of completed rounds, we need to find
    // how many times 12 fits completely into N.
    // This is equivalent to integer division of N by 12.
    // The result of integer division automatically truncates any fractional part,
    // giving us the number of full rounds.
    cout << n / 12 << "\n";

    // Return 0 to indicate successful execution.
    return 0;
}
```