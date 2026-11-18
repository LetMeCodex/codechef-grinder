# [Train Partner (ANKTRAIN)](https://www.codechef.com/problems/ANKTRAIN)
- **Difficulty Rating**: 1187
- **Solved in**: 2 attempt(s)

## Problem Summary
The problem asks us to find the train berth number and type of the partner berth for a given berth number $N$. The berths are arranged in a specific pattern within each coach. The pattern repeats every 8 berths.

## Intuition & Mathematical Observation

The core of this problem lies in understanding the pattern of berth pairings. Let's analyze the berth numbers and their partners:

- **Berths 1, 2, 3**: These are Lower Berth (LB), Middle Berth (MB), and Upper Berth (UB) respectively. Their partners are berths 4, 5, and 6, which are also LB, MB, and UB.
    - Berth 1 (LB) partners with Berth 4 (LB).
    - Berth 2 (MB) partners with Berth 5 (MB).
    - Berth 3 (UB) partners with Berth 6 (UB).
    Notice that the partner berth number is $N+3$ for $N=1, 2, 3$.

- **Berths 4, 5, 6**: These are LB, MB, and UB respectively. Their partners are berths 1, 2, and 3.
    - Berth 4 (LB) partners with Berth 1 (LB).
    - Berth 5 (MB) partners with Berth 2 (MB).
    - Berth 6 (UB) partners with Berth 3 (UB).
    Notice that the partner berth number is $N-3$ for $N=4, 5, 6$.

- **Berths 7, 8**: These are Side Lower (SL) and Side Upper (SU) berths.
    - Berth 7 (SL) partners with Berth 8 (SU).
    - Berth 8 (SU) partners with Berth 7 (SL).
    Notice that the partner berth number is $N+1$ for $N=7$, and $N-1$ for $N=8$.

This pattern repeats every 8 berths. This suggests that the modulo 8 of the berth number $N$ will be crucial in determining its partner.

Let's examine the remainders when $N$ is divided by 8:

- If $N \pmod 8 = 1$: This corresponds to berths like 1, 9, 17, etc. These are LB berths. Their partners are berths 4, 12, 20, etc., which are also LB berths. The partner number is $N+3$.
- If $N \pmod 8 = 2$: This corresponds to berths like 2, 10, 18, etc. These are MB berths. Their partners are berths 5, 13, 21, etc., which are also MB berths. The partner number is $N+3$.
- If $N \pmod 8 = 3$: This corresponds to berths like 3, 11, 19, etc. These are UB berths. Their partners are berths 6, 14, 22, etc., which are also UB berths. The partner number is $N+3$.

- If $N \pmod 8 = 4$: This corresponds to berths like 4, 12, 20, etc. These are LB berths. Their partners are berths 1, 9, 17, etc., which are also LB berths. The partner number is $N-3$.
- If $N \pmod 8 = 5$: This corresponds to berths like 5, 13, 21, etc. These are MB berths. Their partners are berths 2, 10, 18, etc., which are also MB berths. The partner number is $N-3$.
- If $N \pmod 8 = 6$: This corresponds to berths like 6, 14, 22, etc. These are UB berths. Their partners are berths 3, 11, 19, etc., which are also UB berths. The partner number is $N-3$.

- If $N \pmod 8 = 7$: This corresponds to berths like 7, 15, 23, etc. These are SL berths. Their partners are berths 8, 16, 24, etc., which are SU berths. The partner number is $N+1$.

- If $N \pmod 8 = 0$: This corresponds to berths like 8, 16, 24, etc. These are SU berths. Their partners are berths 7, 15, 23, etc., which are SL berths. The partner number is $N-1$.

We can summarize this logic using `if-else if` statements based on `N % 8`.

## Complexity Analysis

- **Time Complexity**: $O(1)$
    The solution involves a few arithmetic operations and comparisons. The time taken does not depend on the input value of $N$, making it constant time.

- **Space Complexity**: $O(1)$
    The solution uses a fixed amount of memory to store variables, regardless of the input size.

## Solution Code

```cpp
#include <iostream> // For input/output operations
#include <string>   // For std::string

// It's generally good practice in competitive programming to avoid 'using namespace std;'
// to prevent potential name collisions, especially in larger projects or when including many headers.
// Instead, qualify standard library elements with 'std::'.

void solve() {
    long long N; // N can be up to 500, so 'int' would suffice, but 'long long' is harmless and safer for larger constraints.
    std::cin >> N;

    long long partner_berth_number;
    std::string partner_berth_type;

    // Calculate N modulo 8.
    // For N = 1, 2, ..., 7, N % 8 will be 1, 2, ..., 7 respectively.
    // For N = 8, 16, 24, ..., N % 8 will be 0.
    long long mod_N = N % 8;

    if (mod_N == 1) { // Current berth is 1LB (e.g., 1, 9, 17...)
        partner_berth_number = N + 3;
        partner_berth_type = "LB";
    } else if (mod_N == 2) { // Current berth is 2MB (e.g., 2, 10, 18...)
        partner_berth_number = N + 3;
        partner_berth_type = "MB";
    } else if (mod_N == 3) { // Current berth is 3UB (e.g., 3, 11, 19...)
        partner_berth_number = N + 3;
        partner_berth_type = "UB";
    } else if (mod_N == 4) { // Current berth is 4LB (e.g., 4, 12, 20...)
        partner_berth_number = N - 3;
        partner_berth_type = "LB";
    } else if (mod_N == 5) { // Current berth is 5MB (e.g., 5, 13, 21...)
        partner_berth_number = N - 3;
        partner_berth_type = "MB";
    } else if (mod_N == 6) { // Current berth is 6UB (e.g., 6, 14, 22...)
        partner_berth_number = N - 3;
        partner_berth_type = "UB";
    } else if (mod_N == 7) { // Current berth is 7SL (e.g., 7, 15, 23...)
        partner_berth_number = N + 1;
        partner_berth_type = "SU"; // Partner of 7SL is 8SU
    } else { // mod_N == 0, meaning N is a multiple of 8 (e.g., 8, 16, 24...)
             // Current berth is 8SU
        partner_berth_number = N - 1;
        partner_berth_type = "SL"; // Partner of 8SU is 7SL
    }

    std::cout << partner_berth_number << partner_berth_type << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin from cout and disables synchronization with C's stdio.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t; // Read the number of test cases
    while (t--) {  // Loop through each test case
        solve();
    }
    return 0;
}
```