# [Long Queue (LONGQUEUE)](https://www.codechef.com/problems/LONGQUEUE)
- **Difficulty Rating**: 719
- **Solved in**: 1 attempt(s)

## Problem Summary
There are $N$ people in a queue, each with a certain amount of wealth. The people are arranged from front to back. Sushil is the $N$-th person in the queue. A person can bully the person directly in front of them if their wealth is at least twice the wealth of the person in front. If Sushil bullies someone, he moves to their position, and the bullied person is removed from the queue. This process continues until Sushil can no longer bully the person in front of him. We need to find Sushil's final position in the queue.

## Intuition & Mathematical Observation
The problem describes a sequential bullying process. Sushil starts at the very end of the queue (position $N$). He can only bully the person directly in front of him. The condition for bullying is that Sushil's wealth must be at least twice the wealth of the person in front. If he bullies, he takes that person's spot, and the bullied person is removed. This means Sushil effectively moves one position forward.

The key observation is that Sushil's wealth remains constant throughout this process. The only thing that changes is his position. He will continue to bully the person in front of him as long as his wealth is sufficient. The moment he encounters a person in front whose wealth is *not* less than half of Sushil's wealth, he stops bullying.

Therefore, we can simulate this process by starting from the person directly in front of Sushil and moving towards the front of the queue. For each person, we check if Sushil can bully them. If he can, his position effectively moves forward by one. If he cannot, the process stops, and his current position is his final position.

Let Sushil's wealth be $W_S$. If the person in front of him has wealth $W_P$, Sushil can bully if $W_S \ge 2 \times W_P$, which is equivalent to $W_P \le W_S / 2$. To avoid floating-point arithmetic and potential precision issues, it's safer to use the integer arithmetic equivalent: $W_P \times 2 \le W_S$.

We can iterate from the person at index $N-2$ (the person directly in front of Sushil, who is at index $N-1$) down to index $0$ (the first person in the original queue). We maintain Sushil's current position, initially $N$. If Sushil can bully the person at index $i$, we decrement his position by 1. If he cannot, we break the loop.

## Complexity Analysis
- **Time Complexity**: $O(N)$
  The code iterates through the queue at most once, from the person in front of Sushil backwards to the beginning of the queue. In the worst case, Sushil might bully everyone in front of him, requiring $N-1$ checks. Thus, the time complexity is linear with respect to the number of people in the queue.

- **Space Complexity**: $O(N)$
  We use a `std::vector` of size $N$ to store the wealth of each person. This dominates the space usage.

## Solution Code
```cpp
#include <bits/stdc++.h> // Required header for competitive programming

// Required namespace usage
using namespace std;

void solve() {
    int n;
    cin >> n; // Read the number of people in the queue
    vector<int> a(n); // Create a vector to store wealths
    for (int i = 0; i < n; ++i) {
        cin >> a[i]; // Read wealths into the vector
    }

    // Sushil is the N-th person, so his wealth is at index N-1 (0-indexed)
    int sushil_wealth = a[n - 1];
    // Sushil's initial position is N (1-indexed)
    int sushil_position = n;

    // Iterate from the person directly in front of Sushil backwards.
    // The person directly in front is at index n-2 (0-indexed).
    // We go down to index 0 (the first person in the original queue).
    for (int i = n - 2; i >= 0; --i) {
        int person_in_front_wealth = a[i];
        
        // Check if Sushil can bully this person.
        // Condition: person_in_front_wealth <= sushil_wealth / 2.
        // Using person_in_front_wealth * 2 <= sushil_wealth for robust integer arithmetic.
        if (person_in_front_wealth * 2 <= sushil_wealth) {
            // Sushil bullies this person, so his position moves forward by 1.
            sushil_position--;
        } else {
            // Sushil cannot bully this person, so the process stops.
            break;
        }
    }

    // Output Sushil's final position.
    cout << sushil_position << "\n";
}

int main() {
    // Enable fast I/O for competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t; // Read the number of test cases.
    while (t--) {
        solve(); // Solve each test case.
    }

    return 0;
}
```