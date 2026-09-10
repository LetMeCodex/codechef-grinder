# [IPL Ticket Rush (IPLTRSH)](https://www.codechef.com/problems/IPLTRSH)

- **Difficulty Rating**: 273
- **Solved in**: 1 attempt(s)

## Problem Summary
There are $N$ students who want to book tickets for an IPL match, but there are only $M$ tickets available. We need to determine how many students will be unable to book a ticket.

## Intuition & Mathematical Observation
The problem asks for the number of students left without a ticket. 
- If the number of students ($N$) is less than or equal to the number of tickets ($M$), every student gets a ticket, meaning $0$ students are left out.
- If the number of students ($N$) is greater than the number of tickets ($M$), then $M$ students will successfully book their tickets, and the remaining $N - M$ students will be left without one.

Mathematically, the answer is $\max(0, N - M)$.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. Each test case performs a constant time arithmetic operation.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and output.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long n, m;
        cin >> n >> m;

        // If the number of students (n) is greater than the number of tickets (m),
        // then n - m students won't be able to book tickets.
        // Otherwise, if n <= m, all students can get tickets, so 0 students won't get tickets.
        if (n > m) {
            cout << n - m << "\n";
        } else {
            cout << 0 << "\n";
        }
    }

    return 0;
}
```