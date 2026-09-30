# [Greedy puppy (GDOG)](https://www.codechef.com/problems/GDOG)
- **Difficulty Rating**: 1306
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to find the maximum number of coins a greedy puppy, Tuzik, can get. Tuzik has $N$ coins and wants to divide them among himself and $P$ friends. The rule is that if $P$ friends are called, the $N$ coins are divided as evenly as possible, and Tuzik gets the remainder. We need to find the maximum remainder Tuzik can achieve by choosing the number of friends $P$ to call, where $P$ can be any integer from 1 to $K$ (inclusive).

## Intuition & Mathematical Observation
Tuzik wants to maximize the number of coins he gets. When $N$ coins are divided among $P$ friends (meaning $P+1$ people in total, including Tuzik), the number of coins each person gets is $\lfloor \frac{N}{P+1} \rfloor$, and the remainder is $N \pmod{P+1}$. However, the problem statement says "if $P$ friends are called", and the division is among these $P$ friends and Tuzik. This implies that the total number of people among whom the coins are divided is $P$. So, if $P$ friends are called, the coins are divided among $P$ people, and Tuzik gets the remainder. This means the number of coins Tuzik gets is $N \pmod P$.

Tuzik can choose to call any number of friends $P$ from 1 to $K$. Therefore, Tuzik will iterate through all possible values of $P$ from 1 to $K$ and calculate the remainder $N \pmod P$. He will then choose the value of $P$ that yields the largest remainder.

Let's consider an example: $N=10, K=4$.
- If $P=1$: $10 \pmod 1 = 0$. Tuzik gets 0 coins.
- If $P=2$: $10 \pmod 2 = 0$. Tuzik gets 0 coins.
- If $P=3$: $10 \pmod 3 = 1$. Tuzik gets 1 coin.
- If $P=4$: $10 \pmod 4 = 2$. Tuzik gets 2 coins.

The maximum number of coins Tuzik can get is 2.

The core of the problem is to find $\max_{1 \le P \le K} (N \pmod P)$.

## Complexity Analysis
- **Time Complexity**: The solution iterates through all possible values of $P$ from 1 to $K$. For each value of $P$, it performs a modulo operation and a comparison. Therefore, the time complexity for each test case is $O(K)$. Since there are $T$ test cases, the total time complexity is $O(T \cdot K)$.

- **Space Complexity**: The solution uses a few integer variables to store $N$, $K$, the current remainder, and the maximum remainder. This space usage is constant and does not depend on the input size $N$ or $K$. Therefore, the space complexity is $O(1)$ per test case.

## Solution Code
```cpp
#include <bits/stdc++.h> // Includes most standard libraries, including iostream and algorithm

// Use the standard namespace to avoid prefixing std::
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k; // Read N and K for the current test case

    int max_coins_for_tuzik = 0; // Initialize the maximum coins Tuzik can get

    // Iterate through all possible numbers of people Tuzik can call
    // P ranges from 1 to K, inclusive.
    for (int p = 1; p <= k; ++p) {
        // Calculate the number of coins Tuzik gets if P people are called
        // This is simply the remainder when N is divided by P.
        int current_coins = n % p;
        
        // Update max_coins_for_tuzik if the current remainder is greater
        max_coins_for_tuzik = max(max_coins_for_tuzik, current_coins);
    }

    // Output the maximum coins Tuzik can get, followed by a newline
    cout << max_coins_for_tuzik << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin from cout and prevents synchronization with C's stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t; // Read the number of test cases

    // Loop through each test case
    while (t--) {
        solve(); // Call the solve function for each test case
    }

    return 0; // Indicate successful execution
}
```