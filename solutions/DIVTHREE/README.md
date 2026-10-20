# Chef and Division 3 (DIVTHREE)

- **Difficulty Rating**: -1
- **Solved in**: 1 attempt(s)

## Problem Summary

Chef wants to host a programming contest. To host a contest, Chef needs to solve at least $K$ problems. Chef has $N$ problems available, with the $i$-th problem having $A_i$ points. Chef can host at most one contest per day, and has a total of $D$ days to host contests. The goal is to find the maximum number of contests Chef can host.

## Intuition & Mathematical Observation

The core constraint is that each contest requires at least $K$ problems to be solved. Chef has a total pool of problems with a sum of points equal to $\sum_{i=1}^{N} A_i$.

Let $S = \sum_{i=1}^{N} A_i$ be the total points from all available problems.
If Chef wants to host a contest, they need to select a subset of problems whose total points are at least $K$. However, the problem statement implies that Chef can use *any* of the available problems to satisfy the $K$ requirement for a contest. This means we should consider the total sum of points available.

The maximum number of contests Chef can host based *solely on the total points available* is the total points divided by the minimum requirement per contest:
$\lfloor \frac{S}{K} \rfloor$.

Additionally, Chef has a limited number of days, $D$. Since Chef can host at most one contest per day, the maximum number of contests Chef can host is also limited by the number of days available: $D$.

Therefore, the maximum number of contests Chef can host is the minimum of these two limiting factors:
$\min \left( \lfloor \frac{S}{K} \rfloor, D \right)$.

If the total points $S$ is less than $K$, then Chef cannot even host a single contest, and $\lfloor \frac{S}{K} \rfloor$ will correctly evaluate to 0.

## Complexity Analysis

- **Time Complexity**: $O(N)$
    - The code iterates through $N$ problems to read their points and sum them up. This takes $O(N)$ time.
    - The rest of the operations (reading $K, D$, calculating the minimum) are constant time, $O(1)$.
    - Since there are $T$ test cases, the total time complexity is $O(T \cdot N)$.

- **Space Complexity**: $O(1)$
    - The solution uses a few variables to store $N, K, D$, the sum of problems, and the result. The amount of memory used does not depend on the input size $N$ or $T$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes iostream, numeric, algorithm, etc.

// Using namespace std; as requested by the problem statement.
using namespace std; 

void solve() {
    // N can fit in int, but K and D require long long due to their maximum values (10^9).
    // Reading N as long long is harmless and consistent.
    long long N, K, D; 
    cin >> N >> K >> D;
    
    long long total_problems = 0;
    // Iterate N times to read A_i and sum them up.
    for (int i = 0; i < N; ++i) {
        long long A_i; // A_i can fit in int, but reading into long long is safer for summation to total_problems.
        cin >> A_i;
        total_problems += A_i;
    }
    
    // Calculate the maximum number of contests Chef can host based on the total problems available.
    // Integer division automatically handles cases where total_problems < K, resulting in 0 contests.
    long long contests_from_problems = total_problems / K;
    
    // Chef cannot host more than one contest in a day.
    // So, over D days, Chef can host at most D contests.
    long long contests_from_days = D; 
    
    // The final answer is limited by whichever factor (problems or days) is more restrictive.
    long long result = min(contests_from_problems, contests_from_days);
    
    cout << result << "\n";
}

int main() {
    // Enable fast I/O for competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T; // Number of test cases.
    cin >> T;
    while (T--) { // Loop through each test case.
        solve();
    }
    
    return 0;
}
```