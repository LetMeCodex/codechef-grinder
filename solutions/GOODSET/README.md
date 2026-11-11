# [A Good Set (GOODSET)](https://www.codechef.com/problems/GOODSET)
- **Difficulty Rating**: 1231
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an integer $n$, we need to construct a set $S$ of $n$ distinct positive integers, where each integer in $S$ is between 1 and 500 (inclusive). The set $S$ must satisfy the "good set" condition: there should be no three distinct elements $a, b, c \in S$ such that $a + b = c$.

## Intuition & Mathematical Observation

The core of the problem lies in satisfying the "good set" condition: $a + b \neq c$ for any distinct $a, b, c \in S$. This condition suggests that the elements in our set should be "far apart" from each other, or at least large enough such that the sum of any two elements is greater than any other element in the set.

Let's consider the constraints:
1.  $n$ distinct integers.
2.  Each integer $x$ in $S$ must satisfy $1 \le x \le 500$.
3.  For any distinct $a, b, c \in S$, $a + b \neq c$.

To ensure $a + b \neq c$, we can try to make the smallest possible sum of two elements ($a+b$) larger than the largest possible element ($c$).

Let $S = \{s_1, s_2, \dots, s_n\}$ where $s_1 < s_2 < \dots < s_n$.
The smallest possible sum of two distinct elements from $S$ is $s_1 + s_2$.
The largest possible element in $S$ is $s_n$.

If we can ensure that $s_1 + s_2 > s_n$, then for any distinct $a, b \in S$, their sum $a+b$ will be at least $s_1 + s_2$. Since $s_n$ is the largest element, and $a+b > s_n$, it's impossible for $a+b$ to be equal to any element $c \in S$.

Now, let's try to construct such a set. We need $n$ distinct integers between 1 and 500.
A simple strategy is to pick a sequence of consecutive integers.
Let's try to pick integers starting from a sufficiently large number.

Suppose we pick the set $S = \{k, k+1, k+2, \dots, k+n-1\}$ for some starting value $k$.
The smallest two elements are $k$ and $k+1$. Their sum is $k + (k+1) = 2k+1$.
The largest element is $k+n-1$.
For the condition $s_1 + s_2 > s_n$ to hold, we need $2k+1 > k+n-1$.
This simplifies to $k > n-2$.

So, if we choose $k$ such that $k > n-2$, this strategy might work.
However, we also need to satisfy the range constraint $1 \le x \le 500$.
The largest element in our set would be $k+n-1$. We need $k+n-1 \le 500$.

Let's consider the maximum possible value of $n$, which is 100.
If $n=100$, we need $k > 100-2 = 98$. So $k$ could be 99.
If $k=99$ and $n=100$, the set would be $\{99, 100, \dots, 99+100-1\} = \{99, 100, \dots, 198\}$.
The smallest sum is $99+100 = 199$. The largest element is 198.
Here, $199 > 198$, so the condition $s_1+s_2 > s_n$ holds.
All elements are between 1 and 500. This works.

However, the problem statement implies that we can pick *any* $n$ distinct integers. We don't have to pick consecutive ones. This gives us more flexibility.

Let's re-examine the condition $a+b > c$.
If we pick elements that are all greater than 250, then the sum of any two elements will be greater than 500.
Let $S = \{s_1, s_2, \dots, s_n\}$ where $s_i > 250$ for all $i$.
The smallest possible sum of two distinct elements is $s_1 + s_2$. Since $s_1 \ge 251$ and $s_2 \ge 252$ (assuming they are distinct and ordered), their sum is at least $251 + 252 = 503$.
The largest possible element $c$ in $S$ must be $\le 500$.
Since $a+b \ge 503$ and $c \le 500$, it's impossible for $a+b = c$.

This observation leads to a very simple construction:
Choose $n$ distinct integers starting from 251.
Let $S = \{251, 252, \dots, 250+n\}$.

Let's verify this construction:
1.  **Distinctness**: The numbers $251, 252, \dots, 250+n$ are clearly distinct.
2.  **Range constraint (1 to 500)**:
    *   The smallest element is 251, which is $\ge 1$.
    *   The largest element is $250+n$. Since the maximum value of $n$ is 100, the largest element is at most $250+100 = 350$.
    *   $350 \le 500$.
    *   Thus, all elements are distinct and lie between 1 and 500.
3.  **"Good set" condition ($a+b \neq c$)**:
    *   Let $a, b$ be two distinct elements from $S$. The minimum possible sum $a+b$ occurs when $a$ and $b$ are the two smallest elements in $S$, which are 251 and 252.
    *   So, $a+b \ge 251 + 252 = 503$.
    *   Now, consider any element $c \in S$. The maximum possible value for $c$ is $250+n$. Since $n \le 100$, the maximum value for $c$ is $250+100 = 350$.
    *   So, $c \le 350$.
    *   Since $a+b \ge 503$ and $c \le 350$, it is impossible for $a+b = c$.
    *   Therefore, the set $S$ is a good set.

This construction is simple, correct, and satisfies all conditions.

The code implements this strategy by iterating from 0 to $n-1$ and printing $251+i$.

## Complexity Analysis

-   **Time Complexity**: $O(n)$
    The `solve()` function iterates $n$ times to print the elements. Since $n$ is at most 100, this is very efficient. The main loop runs $t$ times, where $t$ is the number of test cases. So, the total time complexity is $O(t \cdot n)$. Given the constraints on $t$ and $n$, this is well within limits.

-   **Space Complexity**: $O(1)$
    The solution uses a constant amount of extra space to store variables like `n`, `t`, and loop counters. It does not store the set itself in any data structure that grows with $n$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes iostream, vector, etc.

// Using namespace std; is common in competitive programming
using namespace std;

void solve() {
    int n;
    cin >> n;

    // Strategy: Output n distinct integers starting from 251.
    // Let S be the set {251, 252, ..., 250 + n}.
    //
    // 1. Distinctness: All elements 251, 252, ..., 250+n are clearly distinct.
    //
    // 2. Range constraint (1 to 500):
    //    The smallest element is 251, which is >= 1.
    //    The largest element is 250 + n. Since n <= 100, the maximum value is 250 + 100 = 350.
    //    350 is <= 500.
    //    Thus, all elements are distinct and lie between 1 and 500.
    //
    // 3. "Good set" condition (no distinct a, b, c in S such that a + b = c):
    //    Let a, b be two distinct elements from S.
    //    The smallest possible sum a + b occurs when a and b are the two smallest elements in S,
    //    which are 251 and 252.
    //    So, a + b >= 251 + 252 = 503.
    //
    //    Now, consider any element c in S.
    //    The largest possible element c in S is 250 + n.
    //    Since n <= 100, the maximum value for c is 250 + 100 = 350.
    //    So, c <= 350.
    //
    //    Since a + b >= 503 and c <= 350, it is impossible for a + b = c.
    //    Therefore, the set S is a good set.
    for (int i = 0; i < n; ++i) {
        cout << 251 + i << (i == n - 1 ? "" : " ");
    }
    cout << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
```