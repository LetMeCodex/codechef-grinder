# [The Gift (CS2023_GIFT)](https://www.codechef.com/problems/CS2023_GIFT)
- **Difficulty Rating**: 390
- **Solved in**: 1 attempt(s)

## Problem Summary
Om has $X$ rupees. He wants to buy a laptop that costs $N$ rupees. There is a Gymkhana fund with $M$ rupees. Om can use any amount from the Gymkhana fund. Determine if Om can afford the laptop.

## Intuition & Mathematical Observation
Om's total available money is the sum of his own money ($X$) and the money he can take from the Gymkhana fund. Since he can use the fund as much as he wants, the maximum amount he can gather is his own money plus the entire Gymkhana fund, which is $X + M$.

To be able to buy the laptop, the total amount of money Om can gather must be greater than or equal to the cost of the laptop ($N$). Therefore, the condition for Om to buy the laptop is:

$X + M \ge N$

If this condition holds true, Om can buy the laptop, and we should output "YES". Otherwise, he cannot, and we should output "NO".

## Complexity Analysis
- **Time Complexity**: $O(1)$
The solution involves a single comparison and a few arithmetic operations. These operations take constant time, regardless of the input values.

- **Space Complexity**: $O(1)$
The solution uses a fixed amount of memory to store the input variables ($X$, $N$, $M$) and perform calculations. This memory usage does not grow with the input size.

## Solution Code
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x, n, m;
    cin >> x >> n >> m;

    // Om has X rupees.
    // The laptop costs N rupees.
    // The Gymkhana fund has M rupees.
    // Om can use the fund as much as he wants.

    // The total amount Om can gather is his own money (X) plus
    // whatever he takes from the Gymkhana fund (up to M).
    // The maximum amount he can have is X + M.
    // If this maximum amount is greater than or equal to the laptop cost (N),
    // then he can buy the laptop.

    if (x + m >= n) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}
```