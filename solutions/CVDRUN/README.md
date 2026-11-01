# [Covid Run (CVDRUN)](https://www.codechef.com/problems/CVDRUN)
- **Difficulty Rating**: -1
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem describes a scenario where there are $N$ cities arranged in a circle, numbered from 0 to $N-1$. We start at city $X$ and can jump $K$ cities forward at a time. We want to determine if it's possible to reach city $Y$ starting from city $X$ by making a sequence of these jumps. The jumps are modulo $N$, meaning if we are at city $c$ and jump $K$ cities forward, we land in city $(c + K) \pmod N$.

## Intuition & Mathematical Observation

Let's analyze the cities we can reach starting from city $X$.
The first jump takes us to city $(X + K) \pmod N$.
The second jump takes us to city $(X + K + K) \pmod N = (X + 2K) \pmod N$.
The third jump takes us to city $(X + 2K + K) \pmod N = (X + 3K) \pmod N$.
In general, after $i$ jumps, we will be at city $(X + i \cdot K) \pmod N$.

We want to know if there exists a non-negative integer $i$ such that:
$Y \equiv (X + i \cdot K) \pmod N$

Rearranging this equation, we get:
$Y - X \equiv i \cdot K \pmod N$

This is a linear congruence equation of the form $a \equiv b \cdot x \pmod m$, where $a = Y - X$, $b = K$, and $m = N$.
A linear congruence $ax \equiv b \pmod m$ has a solution for $x$ if and only if $\gcd(a, m)$ divides $b$.
In our case, the equation is $i \cdot K \equiv Y - X \pmod N$.
This equation has a solution for $i$ if and only if $\gcd(K, N)$ divides $(Y - X)$.

However, there's a more direct way to think about this. The set of cities reachable from $X$ by jumps of $K$ are of the form $(X + i \cdot K) \pmod N$.
Let $g = \gcd(K, N)$.
We can rewrite $K$ as $g \cdot k'$ and $N$ as $g \cdot n'$, where $\gcd(k', n') = 1$.
Then, the reachable cities are $(X + i \cdot g \cdot k') \pmod{g \cdot n'}$.

Consider the remainders when cities are divided by $g$.
If we are at city $c$, and we jump $K$ cities, we go to $(c + K) \pmod N$.
The remainder of $(c + K)$ when divided by $g$ is $(c + K) \pmod g$.
Since $K$ is a multiple of $g$, $K \pmod g = 0$.
Therefore, $(c + K) \pmod g = (c \pmod g + K \pmod g) \pmod g = (c \pmod g + 0) \pmod g = c \pmod g$.

This means that every jump preserves the remainder of the city number when divided by $\gcd(K, N)$.
So, if we start at city $X$, all reachable cities will have the same remainder as $X$ when divided by $\gcd(K, N)$.
Therefore, city $Y$ is reachable from city $X$ if and only if $Y \pmod{\gcd(K, N)} = X \pmod{\gcd(K, N)}$.

Let's verify this with the linear congruence.
$Y - X \equiv i \cdot K \pmod N$
This implies that $Y - X$ must be a multiple of $\gcd(K, N)$.
If $Y - X$ is a multiple of $\gcd(K, N)$, then $Y - X \equiv 0 \pmod{\gcd(K, N)}$.
This means $Y \equiv X \pmod{\gcd(K, N)}$.
Conversely, if $Y \equiv X \pmod{\gcd(K, N)}$, then $Y - X$ is a multiple of $\gcd(K, N)$.
Since $K$ is also a multiple of $\gcd(K, N)$, we can write $K = g \cdot k'$ and $N = g \cdot n'$ where $g = \gcd(K, N)$.
The condition $Y - X \equiv i \cdot K \pmod N$ is equivalent to saying that $Y - X = i \cdot K + j \cdot N$ for some integer $j$.
This is a linear Diophantine equation. It has integer solutions for $i$ and $j$ if and only if $\gcd(K, N)$ divides $Y - X$.

So, the condition for reachability is simply that $X$ and $Y$ must have the same remainder when divided by $\gcd(K, N)$.

## Complexity Analysis

- **Time Complexity**: $O(\log(\min(K, N)))$
    The dominant operation is calculating the greatest common divisor (GCD) of $K$ and $N$. The Euclidean algorithm for GCD has a time complexity that is logarithmic with respect to the smaller of the two numbers. All other operations (reading input, modulo, comparison, printing) are constant time.

- **Space Complexity**: $O(1)$
    The solution uses a fixed amount of extra space for variables ($N, K, X, Y$, `common_divisor`, `T`), regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes iostream, numeric, etc.

// Using namespace std; as requested
using namespace std;

// Function to solve a single test case
void solve() {
    int N, K, X, Y;
    cin >> N >> K >> X >> Y;

    // Calculate gcd(K, N)
    // std::gcd is available in C++17 and is in <numeric> or <bits/stdc++.h>
    // The set of cities reachable from X by jumps of K is
    // { (X + i * common_divisor) % N | i >= 0 }.
    // So, Y is reachable if and only if Y has the same remainder as X
    // when divided by common_divisor.
    int common_divisor = std::gcd(K, N);

    // Check if X and Y have the same remainder modulo common_divisor.
    if (X % common_divisor == Y % common_divisor) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
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