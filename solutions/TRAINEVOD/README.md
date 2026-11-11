# Train Even or Odd (TRAINEVOD)
- **Difficulty Rating**: 608
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to consider a sequence of $N$ train departures, where each departure has a certain number of passengers. We are given $N$ integers, $a_1, a_2, \dots, a_N$, representing the number of passengers for each departure. The departures are indexed from 1 to $N$. We need to choose a strategy to maximize the total number of passengers. The strategy involves selecting either all departures on odd-numbered days or all departures on even-numbered days. We can only choose one of these two options.

## Intuition & Mathematical Observation

The problem statement clearly defines two distinct choices:
1. **Choose odd-numbered days**: This means we collect passengers from departures $a_1, a_3, a_5, \dots$.
2. **Choose even-numbered days**: This means we collect passengers from departures $a_2, a_4, a_6, \dots$.

We are asked to maximize the total number of passengers. Since we can only pick *one* of these two strategies, the optimal strategy is simply to calculate the total passengers for each strategy and then choose the one that yields a higher sum.

Let $S_{odd}$ be the sum of passengers on odd-numbered days, and $S_{even}$ be the sum of passengers on even-numbered days.
$S_{odd} = a_1 + a_3 + a_5 + \dots$
$S_{even} = a_2 + a_4 + a_6 + \dots$

The maximum number of passengers we can get is $\max(S_{odd}, S_{even})$.

The indices in the problem are 1-based. When iterating through the input array (which is typically 0-indexed in programming), we need to be careful about the day number. If we use a 0-indexed loop variable `i` from $0$ to $N-1$, the corresponding day number is `i + 1`.
- For odd-numbered days (1, 3, 5, ...), the 0-indexed positions are 0, 2, 4, ... This corresponds to `(i + 1) % 2 != 0` or `i % 2 == 0`.
- For even-numbered days (2, 4, 6, ...), the 0-indexed positions are 1, 3, 5, ... This corresponds to `(i + 1) % 2 == 0` or `i % 2 != 0`.

The provided solution uses `(i + 1) % 2 != 0` for odd days, which correctly identifies indices 0, 2, 4, ... (corresponding to days 1, 3, 5, ...).

## Complexity Analysis

- **Time Complexity**: $O(N)$
  The code iterates through the input array of size $N$ exactly once to calculate the sums of passengers for odd and even days. The operations inside the loop (addition and modulo) take constant time. Therefore, the total time complexity is linear with respect to the number of departures, $N$.

- **Space Complexity**: $O(N)$
  The code uses a `std::vector<int> a(n)` to store the $N$ passenger counts. This vector requires $O(N)$ space. If we were allowed to process the input numbers one by one without storing them all, the space complexity could be reduced to $O(1)$. However, given the typical constraints and the straightforward nature of the problem, storing the array is a common and acceptable approach.

## Solution Code

```cpp
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

int main() {
    // Optimize C++ standard streams for competitive programming
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; // Number of test cases
    std::cin >> t;
    while (t--) {
        int n; // Number of train departures
        std::cin >> n;
        
        // Vector to store passenger counts for each departure.
        // Although we only need sums, storing the array is simple.
        std::vector<int> a(n); 
        
        long long sum_odd_days = 0; // Accumulator for passengers on odd-numbered days
        long long sum_even_days = 0; // Accumulator for passengers on even-numbered days
        
        // Loop through each departure
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i]; // Read the number of passengers for the current departure
            
            // Check if the current day (1-indexed) is odd or even.
            // The loop index 'i' is 0-indexed. So, day number is 'i + 1'.
            if ((i + 1) % 2 != 0) { 
                // If (i + 1) is odd (e.g., 1, 3, 5, ...), add passengers to sum_odd_days.
                // This corresponds to 0-indexed positions 0, 2, 4, ...
                sum_odd_days += a[i];
            } else { 
                // If (i + 1) is even (e.g., 2, 4, 6, ...), add passengers to sum_even_days.
                // This corresponds to 0-indexed positions 1, 3, 5, ...
                sum_even_days += a[i];
            }
        }
        
        // The problem asks to maximize the total passengers by choosing either
        // all odd-day departures or all even-day departures.
        // We output the maximum of the two calculated sums.
        std::cout << std::max(sum_odd_days, sum_even_days) << "\n";
    }
    return 0;
}
```