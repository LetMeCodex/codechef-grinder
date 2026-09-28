# [Presents for Cheffina (PRESENTS)](https://www.codechef.com/problems/PRESENTS)
- **Difficulty Rating**: 757
- **Solved in**: 1 attempt(s)

## Problem Summary

Cheffina wants to buy `N` gifts. There's a special offer: "buy 4 gifts and get 1 gift free". Each gift that is not free costs 1 coin. The task is to determine the minimum number of coins Cheffina needs to spend to acquire `N` gifts.

## Intuition & Mathematical Observation

The core of the problem lies in understanding the "buy 4 get 1 free" offer. This means that for every set of 5 gifts Cheffina acquires, she only has to pay for 4 of them, and the 5th one is free.

Let's analyze this pattern:
- If Cheffina wants 1 gift, she pays 1 coin.
- If Cheffina wants 2 gifts, she pays 2 coins.
- If Cheffina wants 3 gifts, she pays 3 coins.
- If Cheffina wants 4 gifts, she pays 4 coins.
- If Cheffina wants 5 gifts, she can buy 4 and get 1 free. So, she pays 4 coins.

Notice that for every 5 gifts, 1 gift is free. This implies that the number of free gifts Cheffina receives is directly proportional to the total number of gifts `N` she wants, specifically `N / 5` (using integer division).

For example:
- If `N = 10`, she can form `10 / 5 = 2` groups of 5 gifts. Each group gives 1 free gift, so she gets `2` free gifts in total.
- If `N = 12`, she can form `12 / 5 = 2` groups of 5 gifts. She gets `2` free gifts. The remaining 2 gifts are paid for normally.

So, the total number of gifts she needs to pay for is the total number of gifts `N` minus the number of free gifts she receives.
Number of paid gifts = `N - (N / 5)`

Since each paid gift costs 1 coin, the total coins needed will be equal to the number of paid gifts.

Therefore, the minimum coins required is `N - (N / 5)`.

## Complexity Analysis

-   **Time Complexity**: $O(1)$
    The `solve()` function performs a fixed number of operations: reading an integer, one integer division, one subtraction, and printing an integer. These operations take constant time. The `main()` function calls `solve()` `T` times. Thus, the total time complexity is $O(T \times 1) = O(T)$. Since $T$ is typically small in competitive programming and the operations per test case are constant, we can consider the per-test-case complexity as $O(1)$.

-   **Space Complexity**: $O(1)$
    The solution uses a few integer variables (`N`, `coins_needed`, `T`) to store input and intermediate results. The memory usage for these variables is constant and does not depend on the input size `N` or the number of test cases `T`.

## Solution Code

```cpp
#include <bits/stdc++.h> // Required by problem statement to include most standard libraries
using namespace std;     // Required by problem statement to use standard namespace

void solve() {
    int N; // Declare N to store the number of gifts
    cin >> N; // Read the number of gifts for the current test case

    // Calculate the minimum number of coins required.
    // For every 5 gifts, Chef gets 1 free.
    // So, the number of free gifts is N / 5 (integer division).
    // The number of gifts Chef actually pays for is N - (number of free gifts).
    // Since each paid gift costs 1 coin, this is the total coins needed.
    int coins_needed = N - (N / 5);
    
    cout << coins_needed << "\n"; // Output the result followed by a newline
}

int main() {
    // Optimize C++ standard streams for competitive programming.
    // This unties cin/cout from the C standard streams and disables synchronization
    // with C stdio, making I/O operations faster.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare T to store the number of test cases
    cin >> T; // Read the number of test cases
    while (T--) { // Loop T times, decrementing T in each iteration
        solve(); // Call the solve function for each test case
    }

    return 0; // Indicate successful execution
}
```