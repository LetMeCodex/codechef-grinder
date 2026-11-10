# Group Assignment (GRPASSN)
- **Difficulty Rating**: 1092
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to determine if it's possible to assign $N$ people into groups such that everyone is in a group and each person's preferred group size is satisfied. We are given $N$ integers, where the $i$-th integer $P_i$ represents the preferred group size of the $i$-th person. A person is satisfied if they are placed in a group whose size is exactly equal to their preferred group size.

## Intuition & Mathematical Observation
The core constraint is that every person must be assigned to a group, and this group must match their preferred size. This implies that if a certain group size $S$ is preferred by $k$ people, then these $k$ people must be able to form one or more groups of size $S$. The only way to do this is if the total number of people who prefer group size $S$ is perfectly divisible by $S$.

Let's consider a specific preferred group size $S$. Suppose $k$ people have $S$ as their preferred group size. For these $k$ people to be satisfied, they must be partitioned into groups of size $S$. This is only possible if $k$ is a multiple of $S$. If $k$ is not a multiple of $S$, then it's impossible to form groups of size $S$ using exactly these $k$ people, and thus at least one of them will not be satisfied.

Therefore, the condition for a valid assignment to exist is that for *every* possible preferred group size $S$ (from 2 to $N$), the number of people who prefer group size $S$ must be divisible by $S$. If this condition holds true for all $S$, then we can form groups of size $S$ for all people who prefer it. Since the problem statement implies that people only care about their *own* preferred group size and not about forming groups with others who have different preferences, we can consider each preferred group size independently.

The input gives us $N$ preferred group sizes $P_1, P_2, \dots, P_N$. We need to count how many people prefer each possible group size. A frequency map or an array can be used for this. Let `counts[S]` be the number of people who prefer group size $S$. Then, for the assignment to be possible, `counts[S]` must be divisible by $S$ for all $S$ from 2 to $N$.

## Complexity Analysis
- **Time Complexity**: $O(N)$
    - We read $N$ preferred group sizes, which takes $O(N)$ time.
    - We iterate through the `counts` array from index 2 to $N$. This loop runs $N-1$ times. Inside the loop, we perform a constant number of operations (modulo and comparison).
    - Therefore, the total time complexity is dominated by reading the input and iterating through the counts, resulting in $O(N)$.

- **Space Complexity**: $O(N)$
    - We use a `vector<int> counts` of size $N+1$ to store the frequency of each preferred group size. This requires $O(N)$ space.
    - Other variables use constant space.
    - Thus, the total space complexity is $O(N)$.

## Solution Code
```cpp
#include <bits/stdc++.h> // Includes iostream, vector, etc.

// Using namespace std; as per problem instruction
using namespace std;

void solve() {
    int N;
    cin >> N;
    
    // Use a frequency array to store counts of preferred group sizes.
    // P_i values are from 2 to N. So, an array of size N+1 is sufficient.
    // Index i will store the count of people who prefer group size i.
    vector<int> counts(N + 1, 0);
    
    for (int i = 0; i < N; ++i) {
        int P_i;
        cin >> P_i;
        // Increment the count for the preferred group size P_i.
        // P_i is guaranteed to be between 2 and N.
        counts[P_i]++;
    }
    
    bool possible = true;
    // Iterate through all possible preferred group sizes from 2 to N.
    // P_i is guaranteed to be >= 2.
    for (int S = 2; S <= N; ++S) {
        // If there are people who prefer group size S:
        if (counts[S] > 0) {
            // The number of people who prefer group size S must be a multiple of S.
            // If not, it's impossible to form groups of size S using all of them.
            if (counts[S] % S != 0) {
                possible = false;
                break; // No need to check further, it's already impossible.
            }
        }
    }
    
    if (possible) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    // Fast I/O as per problem instruction
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    
    return 0;
}
```