# Two Numbers (TWONMS)
- **Difficulty Rating**: 1320
- **Solved in**: 1 attempt(s)

## Problem Summary
Given three positive integers $A$, $B$, and $N$. Alice and Bob take turns multiplying their current number by 2. Alice starts. Alice's number is initially $A$, and Bob's number is initially $B$. They take $N$ turns in total. Alice takes turns 1, 3, 5, ... and Bob takes turns 2, 4, 6, .... After $N$ turns, we need to find the ratio of the larger number to the smaller number.

## Intuition & Mathematical Observation

Let $A_i$ and $B_i$ be the numbers Alice and Bob have after $i$ turns.
Initially, $A_0 = A$ and $B_0 = B$.

Alice's turns are 1, 3, 5, ...
Bob's turns are 2, 4, 6, ...

If $N$ is the total number of turns:

**Case 1: $N$ is even.**
Alice takes turns 1, 3, ..., $N-1$. There are $N/2$ turns for Alice.
Bob takes turns 2, 4, ..., $N$. There are $N/2$ turns for Bob.
After $N$ turns, Alice's number will be $A \times 2^{N/2}$ and Bob's number will be $B \times 2^{N/2}$.
The ratio will be $\frac{\max(A \times 2^{N/2}, B \times 2^{N/2})}{\min(A \times 2^{N/2}, B \times 2^{N/2})} = \frac{2^{N/2} \times \max(A, B)}{2^{N/2} \times \min(A, B)} = \frac{\max(A, B)}{\min(A, B)}$.

**Case 2: $N$ is odd.**
Alice takes turns 1, 3, ..., $N$. There are $(N+1)/2$ turns for Alice.
Bob takes turns 2, 4, ..., $N-1$. There are $(N-1)/2$ turns for Bob.
After $N$ turns, Alice's number will be $A \times 2^{(N+1)/2}$ and Bob's number will be $B \times 2^{(N-1)/2}$.
The ratio will be $\frac{\max(A \times 2^{(N+1)/2}, B \times 2^{(N-1)/2})}{\min(A \times 2^{(N+1)/2}, B \times 2^{(N-1)/2})}$.

Let's analyze the exponents:
$(N+1)/2 = (N-1)/2 + 1$.
So, Alice's number is $A \times 2^{(N-1)/2} \times 2^1$.
Bob's number is $B \times 2^{(N-1)/2}$.

The ratio becomes $\frac{\max(A \times 2^{(N-1)/2} \times 2, B \times 2^{(N-1)/2})}{\min(A \times 2^{(N-1)/2} \times 2, B \times 2^{(N-1)/2})}$.
We can factor out $2^{(N-1)/2}$ from both the numerator and denominator:
$\frac{2^{(N-1)/2} \times \max(A \times 2, B)}{\min(A \times 2, B) \times 2^{(N-1)/2}} = \frac{\max(A \times 2, B)}{\min(A \times 2, B)}$.

**Unified Observation:**
We can see that if $N$ is odd, Alice effectively gets one extra multiplication by 2 compared to Bob. This means we can consider Alice's initial number as $A \times 2$ and Bob's as $B$ for the purpose of calculating the final ratio, and then the number of turns becomes effectively $N-1$ (which is even).
If $N$ is even, both get $N/2$ multiplications by 2, and the ratio is $\frac{\max(A, B)}{\min(A, B)}$.

Combining these:
- If $N$ is odd, we compare $2A$ and $B$. The ratio is $\frac{\max(2A, B)}{\min(2A, B)}$.
- If $N$ is even, we compare $A$ and $B$. The ratio is $\frac{\max(A, B)}{\min(A, B)}$.

This can be simplified:
If $N$ is odd, we effectively modify $A$ to $A \times 2$. Then we calculate $\frac{\max(\text{modified } A, B)}{\min(\text{modified } A, B)}$.
If $N$ is even, we don't modify $A$. Then we calculate $\frac{\max(A, B)}{\min(A, B)}$.

The code implements this by checking if $N$ is odd. If it is, $A$ is multiplied by 2. Then, it calculates the ratio of the maximum to the minimum of the (potentially modified) $A$ and $B$.

## Complexity Analysis

- **Time Complexity**: $O(1)$
    The solution involves a few arithmetic operations (modulo, multiplication, comparison, division) and reading input. These operations take constant time. The loop for test cases runs $T$ times, but the work inside the loop is constant. Thus, the total time complexity is $O(T)$, or $O(1)$ per test case.

- **Space Complexity**: $O(1)$
    The solution uses a fixed number of variables ($A, B, N, T$, and `result`) regardless of the input size. Therefore, the space complexity is constant.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes iostream, algorithm, etc.

// Using namespace std; as requested by problem instructions
using namespace std;

void solve() {
    long long A, B, N;
    // Read A, B, N for the current test case
    cin >> A >> B >> N;

    // Check if N is odd or even to determine the effective multipliers
    if (N % 2 == 1) {
        // If N is odd, Alice gets one more turn than Bob.
        // This means Alice's number is effectively multiplied by an extra 2
        // compared to Bob's number, before common factors of 2 are considered.
        // So, we effectively compare (A * 2) with B.
        A *= 2; 
    }
    
    // After the potential adjustment to A (if N was odd),
    // both numbers (A and B) have been effectively multiplied by the same
    // power of 2. This common power of 2 will cancel out when we take
    // the ratio max(C, D) / min(C, D).
    // Therefore, we just need to calculate max(current_A, B) / min(current_A, B).
    // Note: A now holds the potentially modified value (A or 2*A).
    long long result = max(A, B) / min(A, B);
    
    // Output the result followed by a newline
    cout << result << "\n";
}

int main() {
    // Optimize C++ standard streams for competitive programming.
    // This unties cin from cout and prevents synchronization with C's stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    // Read the number of test cases
    cin >> T;
    // Loop through each test case
    while (T--) {
        solve();
    }

    return 0;
}
```