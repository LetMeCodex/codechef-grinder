# [Subset Sum 3 (SUBSUM3)](https://www.codechef.com/problems/SUBSUM3)
- **Difficulty Rating**: 990
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine if it's possible to select a non-empty subsequence from a given array $A$ of $N$ integers such that the sum of the elements in the subsequence is divisible by 3. We need to output "Yes" if such a subsequence exists, and "No" otherwise.

## Intuition & Mathematical Observation

The key to solving this problem lies in understanding modular arithmetic, specifically modulo 3. A sum $S$ is divisible by 3 if and only if $S \pmod 3 = 0$. The remainder of a sum modulo 3 is equal to the sum of the remainders modulo 3:
$(A_{i_1} + A_{i_2} + \dots + A_{i_k}) \pmod 3 = (A_{i_1} \pmod 3 + A_{i_2} \pmod 3 + \dots + A_{i_k} \pmod 3) \pmod 3$.

This means we only care about the remainders of the numbers in the array when divided by 3. Each number $A_i$ can have a remainder of 0, 1, or 2. Let's count how many numbers fall into each category:
- `counts[0]`: Number of elements $A_i$ such that $A_i \pmod 3 = 0$.
- `counts[1]`: Number of elements $A_i$ such that $A_i \pmod 3 = 1$.
- `counts[2]`: Number of elements $A_i$ such that $A_i \pmod 3 = 2$.

Now, we need to find if we can pick a non-empty subsequence whose sum modulo 3 is 0. We should look for the simplest combinations of elements that satisfy this condition:

1.  **An element itself is divisible by 3:**
    If there is any number $A_i$ such that $A_i \pmod 3 = 0$ (i.e., `counts[0] > 0`), we can simply pick that single number as our subsequence. Its sum is $A_i$, which is divisible by 3. This is the most straightforward case.

2.  **Combine an element with remainder 1 and an element with remainder 2:**
    If we pick one element $A_i$ with $A_i \pmod 3 = 1$ and one element $A_j$ with $A_j \pmod 3 = 2$, their sum $A_i + A_j$ will have a remainder of $(1 + 2) \pmod 3 = 3 \pmod 3 = 0$.
    This is possible if we have at least one number with remainder 1 (`counts[1] > 0`) AND at least one number with remainder 2 (`counts[2] > 0`).

3.  **Combine three elements with remainder 1:**
    If we pick three elements $A_i, A_j, A_k$ all with $A_x \pmod 3 = 1$, their sum $A_i + A_j + A_k$ will have a remainder of $(1 + 1 + 1) \pmod 3 = 3 \pmod 3 = 0$.
    This is possible if we have at least three numbers with remainder 1 (`counts[1] >= 3`).

4.  **Combine three elements with remainder 2:**
    If we pick three elements $A_i, A_j, A_k$ all with $A_x \pmod 3 = 2$, their sum $A_i + A_j + A_k$ will have a remainder of $(2 + 2 + 2) \pmod 3 = 6 \pmod 3 = 0$.
    This is possible if we have at least three numbers with remainder 2 (`counts[2] >= 3`).

These four conditions cover all minimal ways to form a sum divisible by 3 using 1, 2, or 3 elements. If none of these conditions are met, it's impossible to form such a subsequence. For example, if `counts[0]` is 0, and we only have numbers with remainder 1 (less than 3 of them), or only numbers with remainder 2 (less than 3 of them), or a mix of 1s and 2s but not both (e.g., only one 1 and no 2s), then no combination will yield a sum divisible by 3.

The solution iterates through the input array once to populate these counts and then checks these four conditions.

## Complexity Analysis

-   **Time Complexity**:
    -   Reading `N` and initializing the `counts` vector takes $O(1)$ time.
    -   The loop to read `N` elements and update their respective counts based on `A_i % 3` runs $N$ times. Each operation inside the loop (reading, modulo, incrementing) is $O(1)$. Thus, this loop takes $O(N)$ time.
    -   Checking the four `if-else if` conditions is a constant number of operations, taking $O(1)$ time.
    -   Printing the result is $O(1)$.
    -   Since there are `T` test cases, the total time complexity is $O(T \cdot N)$. Given $N \le 10^5$ and $T \le 10$, this is approximately $10 \cdot 10^5 = 10^6$ operations, which is efficient enough.
    Therefore, the time complexity is $\mathcal{O}(N)$ per test case.

-   **Space Complexity**:
    -   The `counts` vector stores 3 integers, regardless of the input size `N`. This requires $O(1)$ space.
    -   All other variables (`N`, `A_i`, `found`, `T`) also consume $O(1)$ space.
    Therefore, the space complexity is $\mathcal{O}(1)$ per test case.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes iostream, vector, etc. as requested

// Using namespace std; as requested
using namespace std;

void solve() {
    int N;
    cin >> N;
    
    // counts[0]: count of numbers A_i such that A_i % 3 == 0
    // counts[1]: count of numbers A_i such that A_i % 3 == 1
    // counts[2]: count of numbers A_i such that A_i % 3 == 2
    vector<int> counts(3, 0); 
    
    for (int i = 0; i < N; ++i) {
        int A_i;
        cin >> A_i;
        counts[A_i % 3]++;
    }
    
    bool found = false;
    
    // Condition 1: An element itself is divisible by 3.
    // If there's any number A_i such that A_i % 3 == 0, we can pick just that number.
    // This forms a non-empty subsequence with sum divisible by 3.
    if (counts[0] > 0) {
        found = true;
    }
    // Condition 2: Combine an element with remainder 1 and an element with remainder 2.
    // Their sum will be (1 + 2) % 3 = 0.
    // This forms a non-empty subsequence with sum divisible by 3.
    else if (counts[1] > 0 && counts[2] > 0) {
        found = true;
    }
    // Condition 3: Combine three elements with remainder 1.
    // Their sum will be (1 + 1 + 1) % 3 = 3, which is 0 % 3.
    // This forms a non-empty subsequence with sum divisible by 3.
    else if (counts[1] >= 3) {
        found = true;
    }
    // Condition 4: Combine three elements with remainder 2.
    // Their sum will be (2 + 2 + 2) % 3 = 6, which is 0 % 3.
    // This forms a non-empty subsequence with sum divisible by 3.
    else if (counts[2] >= 3) {
        found = true;
    }
    
    if (found) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}

int main() {
    // Fast I/O as requested
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