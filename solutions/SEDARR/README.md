# Sed Sequences (SEDARR)
- **Difficulty Rating**: -1
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks for the minimum number of operations to make the sum of an array of $N$ integers divisible by $K$. An operation consists of choosing an element $A_i$ and replacing it with any positive integer $A_i'$.

## Intuition & Mathematical Observation

The core of this problem lies in understanding the properties of divisibility and how changing a single element affects the sum.

Let the initial sum of the array be $S = \sum_{i=1}^{N} A_i$.
We want to reach a state where the new sum $S'$ is divisible by $K$, i.e., $S' \equiv 0 \pmod{K}$.

**Case 1: The initial sum $S$ is already divisible by $K$.**
If $S \pmod{K} == 0$, then the sum is already divisible by $K$. In this scenario, we don't need to perform any operations. The minimum number of operations is 0.

**Case 2: The initial sum $S$ is not divisible by $K$.**
If $S \pmod{K} \neq 0$, we need to perform at least one operation. The question is whether one operation is always sufficient.

Consider performing one operation: we choose an element $A_j$ and replace it with a new positive integer $A_j'$. The new sum will be $S' = S - A_j + A_j'$.
We want to find if there exists a positive integer $A_j'$ such that $S' \equiv 0 \pmod{K}$.
This is equivalent to $(S - A_j + A_j') \equiv 0 \pmod{K}$.

Let $R = S \pmod{K}$. Since $S$ is not divisible by $K$, $R \neq 0$.
We are looking for $A_j'$ such that $(S - A_j + A_j') \equiv 0 \pmod{K}$.
This can be rewritten as $A_j' \equiv (A_j - S) \pmod{K}$.
Or, $A_j' \equiv (A_j - (S \pmod{K})) \pmod{K}$.
$A_j' \equiv (A_j - R) \pmod{K}$.

We need to find a positive integer $A_j'$ that satisfies this congruence.
Let's consider the value $A_j - R$.
If we choose $A_j' = A_j - R$, this might be zero or negative, which is not allowed.
However, we can always find a positive integer $A_j'$ by adding multiples of $K$.
Specifically, we can set $A_j' = (A_j - R) + m \cdot K$ for some integer $m$.
We need $A_j' > 0$.

Let's analyze the required change. We need to change the sum by an amount $\Delta = S' - S = A_j' - A_j$.
We want $S + \Delta \equiv 0 \pmod{K}$.
This means $\Delta \equiv -S \pmod{K}$.
So, $\Delta \equiv -(S \pmod{K}) \pmod{K}$.
Let $R = S \pmod{K}$. Then $\Delta \equiv -R \pmod{K}$.
This means $\Delta$ can be $-R$ or $-R + K$ or $-R + 2K$, etc., or $-R - K$ or $-R - 2K$, etc.

We are changing $A_j$ to $A_j'$, so $\Delta = A_j' - A_j$.
We need $A_j' - A_j \equiv -R \pmod{K}$.
This means $A_j' \equiv A_j - R \pmod{K}$.

We can always find a positive integer $A_j'$ to satisfy this.
For example, let's pick any element $A_j$. We want to find $A_j'$ such that $(S - A_j + A_j') \pmod{K} = 0$.
This means $A_j' \pmod{K} = (A_j - S) \pmod{K}$.
Let $target\_rem = (A_j - S) \pmod{K}$. If $target\_rem < 0$, we can add $K$ to make it non-negative.
So, $target\_rem = (A_j - S \% K + K) \% K$.
We need to find a positive integer $A_j'$ such that $A_j' \pmod{K} = target\_rem$.
We can always choose $A_j' = target\_rem$ if $target\_rem > 0$.
If $target\_rem = 0$, we can choose $A_j' = K$ (since $K$ is positive).
In general, we can choose $A_j' = target\_rem$ if $target\_rem \neq 0$, and $A_j' = K$ if $target\_rem = 0$.
This ensures $A_j'$ is a positive integer.
Therefore, if the sum is not divisible by $K$, we can always make it divisible by changing just one element. The minimum number of operations is 1.

**Conclusion:**
The minimum number of operations is 0 if the initial sum is divisible by $K$, and 1 otherwise.

## Complexity Analysis
- **Time Complexity**: $O(N)$
    - We iterate through the array once to calculate the sum.
    - The operations for checking divisibility and printing the result are $O(1)$.
    - Since there are $T$ test cases, the total time complexity is $O(T \cdot N)$.

- **Space Complexity**: $O(1)$
    - We only use a few variables to store the sum and loop counters, which is constant extra space.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries

// Using namespace std for brevity as requested
using namespace std;

void solve() {
    int N;
    int K; // K up to 10^5, int is sufficient.
    cin >> N >> K;

    long long current_sum = 0; // Max sum is 100 * 10^5 = 10^7. Fits in int, but long long is safer practice.
    for (int i = 0; i < N; ++i) {
        int A_i; // A_i up to 10^5, int is sufficient.
        cin >> A_i;
        current_sum += A_i;
    }

    // If the current sum is already divisible by K, 0 operations are needed.
    if (current_sum % K == 0) {
        cout << 0 << "\n";
    } else {
        // If the current sum is not divisible by K, we can always make it divisible
        // by changing just one element.
        // For example, pick any A_j. We want (current_sum - A_j + A_j') % K == 0.
        // We can always find a positive integer A_j' to satisfy this.
        // Thus, 1 operation is always sufficient if the sum is not already divisible.
        cout << 1 << "\n";
    }
}

int main() {
    // Fast I/O setup as requested
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) { // Loop through each test case
        solve();
    }

    return 0;
}
```