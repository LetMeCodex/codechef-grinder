# [Ticket Fine (TCKTFINE)](https://www.codechef.com/problems/TCKTFINE)

- **Difficulty Rating**: 373
- **Solved in**: 1 attempt(s)

## Problem Summary
In this problem, we are given the total number of passengers ($P$) on a train and the number of passengers who have a valid ticket ($Q$). If a passenger does not have a ticket, they must pay a fine of $X$ rupees. We need to calculate the total amount of fine collected by the ticket collector.

## Intuition & Mathematical Observation
The problem asks for the total fine collected. We can break this down into two simple steps:
1. **Identify the number of offenders**: Since $P$ is the total number of passengers and $Q$ is the number of passengers with tickets, the number of passengers without tickets is simply $P - Q$.
2. **Calculate the total fine**: Since each passenger without a ticket pays $X$ rupees, the total fine is the product of the number of offenders and the fine amount per person.

**Formula:**
$$\text{Total Fine} = (P - Q) \times X$$

Given the constraints ($X, P, Q \le 10$), the calculation is straightforward and will not result in integer overflow.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we are performing a constant number of arithmetic operations. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * - X: Fine per passenger without a ticket.
 * - P: Total number of passengers.
 * - Q: Total number of tickets.
 * - Passengers without tickets = P - Q.
 * - Total fine = (P - Q) * X.
 * 
 * Constraints:
 * - T <= 10, X <= 10, Q <= P <= 10.
 * - The result will fit in a standard integer, but using long long is safe practice.
 * - Time complexity per test case: O(1).
 * - Space complexity: O(1).
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long x, p, q;
        cin >> x >> p >> q;
        
        // Calculate number of passengers without tickets
        long long passengers_without_ticket = p - q;
        
        // Calculate total fine
        long long total_fine = passengers_without_ticket * x;
        
        // Output the result
        cout << total_fine << "\n";
    }

    return 0;
}
```