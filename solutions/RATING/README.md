# [The Rating Dilemma (RATING)](https://www.codechef.com/problems/RATING)
- **Difficulty Rating**: 909
- **Solved in**: 2 attempt(s)

## Problem Summary

Given an integer $S$, we need to find two integers $X$ and $Y$ such that $X + Y = S$, $X > 0$, and $Y < 0$. Our goal is to maximize the product $X \times Y$.

## Intuition & Mathematical Observation

We are given the constraint $X + Y = S$, which means $Y = S - X$.
We are also given the constraints $X > 0$ and $Y < 0$.
Since $X$ and $Y$ must be integers, these constraints translate to $X \ge 1$ and $Y \le -1$.

Let's substitute $Y = S - X$ into the constraint $Y \le -1$:
$S - X \le -1$
Adding $X$ to both sides:
$S \le X - 1$
Adding $1$ to both sides:
$S + 1 \le X$

So, we have two conditions for $X$:
1. $X \ge 1$
2. $X \ge S + 1$

Combining these, the valid range for $X$ is $X \ge \max(1, S + 1)$.

Now, we want to maximize the product $P = X \times Y$. Substituting $Y = S - X$, we get:
$P(X) = X \times (S - X)$
$P(X) = SX - X^2$

This is a quadratic function of $X$, opening downwards (due to the $-X^2$ term). The maximum value of a downward-opening parabola $ax^2 + bx + c$ occurs at $x = -b / (2a)$.
In our case, $a = -1$ and $b = S$. So, the vertex of the parabola is at $X = -S / (2 \times -1) = S / 2$.

However, $X$ must be an integer and must satisfy $X \ge \max(1, S + 1)$. The vertex $S/2$ might not be an integer, and it might not satisfy the constraints.

Since the parabola $P(X) = SX - X^2$ opens downwards, its maximum value over a given interval will occur at the boundary of that interval if the vertex is outside the interval. In our case, the valid values of $X$ are $X \ge \max(1, S+1)$. This is an unbounded interval from the right.

Let's re-examine the function $P(X) = SX - X^2$.
The derivative with respect to $X$ is $P'(X) = S - 2X$.
Setting $P'(X) = 0$ gives $S - 2X = 0$, so $X = S/2$.

If $S/2$ is an integer and satisfies the constraints $X \ge 1$ and $Y \le -1$, then $X=S/2$ would give the maximum product.
However, the problem statement implies that $S$ can be any integer.

Let's consider the constraints on $X$ and $Y$ more carefully.
$X \ge 1$
$Y \le -1$
$X + Y = S$

If $S$ is positive, say $S=5$:
$X \ge 1$
$Y \le -1$
$X+Y=5$
Possible pairs $(X, Y)$: $(6, -1), (7, -2), (8, -3), \dots$
Products: $6 \times -1 = -6$, $7 \times -2 = -14$, $8 \times -3 = -24$.
The product is decreasing as $X$ increases.
The smallest valid $X$ is $S+1$ (since $X \ge S+1$ and $X \ge 1$).
If $S=5$, then $X \ge 6$. The smallest valid $X$ is $6$.
When $X=6$, $Y = 5 - 6 = -1$. Product is $6 \times -1 = -6$.
This matches $-(S+1) = -(5+1) = -6$.

If $S$ is negative, say $S=-5$:
$X \ge 1$
$Y \le -1$
$X+Y=-5$
Possible pairs $(X, Y)$: $(1, -6), (2, -7), (3, -8), \dots$
Products: $1 \times -6 = -6$, $2 \times -7 = -14$, $3 \times -8 = -24$.
The product is decreasing as $X$ increases.
The smallest valid $X$ is $1$ (since $X \ge 1$ and $X \ge S+1 = -5+1 = -4$).
When $X=1$, $Y = -5 - 1 = -6$. Product is $1 \times -6 = -6$.
This matches $-(S+1) = -(-5+1) = -(-4) = 4$. This is incorrect.

Let's re-evaluate the condition $X \ge \max(1, S+1)$.

Case 1: $S+1 \ge 1$, which means $S \ge 0$.
In this case, $X \ge S+1$.
The function $P(X) = SX - X^2$ has its vertex at $X = S/2$.
If $S \ge 0$, then $S/2 \le S$.
Since $X \ge S+1$, the vertex $S/2$ is to the left of the valid range for $X$.
The parabola opens downwards, so on the interval $[S+1, \infty)$, the function $P(X)$ is decreasing.
Therefore, the maximum product is achieved at the smallest possible value of $X$, which is $X = S+1$.
If $X = S+1$, then $Y = S - (S+1) = -1$.
The product is $(S+1) \times (-1) = -(S+1)$.

Case 2: $S+1 < 1$, which means $S < 0$.
In this case, $X \ge 1$.
The vertex of the parabola is at $X = S/2$. Since $S < 0$, $S/2 < 0$.
The valid range for $X$ is $[1, \infty)$.
The vertex $S/2$ is to the left of the valid range for $X$.
The parabola opens downwards, so on the interval $[1, \infty)$, the function $P(X)$ is decreasing.
Therefore, the maximum product is achieved at the smallest possible value of $X$, which is $X = 1$.
If $X = 1$, then $Y = S - 1$.
The product is $1 \times (S-1) = S-1$.

Let's check the formula $-(S+1)$ for $S < 0$.
If $S = -5$:
Case 1 formula gives $-(S+1) = -(-5+1) = -(-4) = 4$.
Case 2 formula gives $S-1 = -5-1 = -6$.
The actual maximum product we found was $-6$. So, the formula $S-1$ is correct for $S < 0$.

Let's re-examine the problem statement and constraints.
$X > 0 \implies X \ge 1$
$Y < 0 \implies Y \le -1$
$X + Y = S$

We want to maximize $X \times Y$.
Let's consider the expression $X \times Y = X \times (S-X)$.
We need to find the minimum valid $X$ that satisfies the constraints.

If $S=0$:
$X \ge 1$, $Y \le -1$, $X+Y=0 \implies Y=-X$.
So, $X \ge 1$ and $-X \le -1 \implies X \ge 1$.
The smallest valid $X$ is $1$.
If $X=1$, $Y=-1$. Product is $1 \times -1 = -1$.
Formula $-(S+1) = -(0+1) = -1$. This works.

If $S=1$:
$X \ge 1$, $Y \le -1$, $X+Y=1 \implies Y=1-X$.
So, $X \ge 1$ and $1-X \le -1 \implies 2 \le X$.
The smallest valid $X$ is $2$.
If $X=2$, $Y=1-2=-1$. Product is $2 \times -1 = -2$.
Formula $-(S+1) = -(1+1) = -2$. This works.

If $S=-1$:
$X \ge 1$, $Y \le -1$, $X+Y=-1 \implies Y=-1-X$.
So, $X \ge 1$ and $-1-X \le -1 \implies -X \le 0 \implies X \ge 0$.
Combined with $X \ge 1$, the smallest valid $X$ is $1$.
If $X=1$, $Y=-1-1=-2$. Product is $1 \times -2 = -2$.
Formula $-(S+1) = -(-1+1) = 0$. This is incorrect.
Formula $S-1 = -1-1 = -2$. This works.

It seems my initial reasoning about $X \ge S+1$ was correct, but the interpretation of the vertex and the interval was slightly off.

Let's go back to $P(X) = SX - X^2$.
We need to find the maximum of this function subject to:
1. $X \ge 1$
2. $Y \le -1 \implies S - X \le -1 \implies X \ge S + 1$

So, we need to maximize $P(X)$ for $X \in [\max(1, S+1), \infty)$.

The function $P(X)$ is a downward-opening parabola with its vertex at $X = S/2$.

Case A: $S/2 \le \max(1, S+1)$.
This means the vertex is to the left of or at the start of our valid interval for $X$.
Since the parabola opens downwards, the function will be decreasing over the interval $[\max(1, S+1), \infty)$.
Therefore, the maximum value will be at the smallest possible $X$, which is $X = \max(1, S+1)$.

Let's analyze when $S/2 \le \max(1, S+1)$:
Subcase A1: $S+1 \ge 1$ (i.e., $S \ge 0$). Then $\max(1, S+1) = S+1$.
We need $S/2 \le S+1$.
$S \le 2S + 2$
$-S \le 2$
$S \ge -2$.
Since we are in the case $S \ge 0$, this condition $S \ge -2$ is always true.
So, for $S \ge 0$, the vertex $S/2$ is always less than or equal to $S+1$.
The smallest valid $X$ is $S+1$.
If $X = S+1$, then $Y = S - (S+1) = -1$.
The product is $(S+1) \times (-1) = -(S+1)$.

Subcase A2: $S+1 < 1$ (i.e., $S < 0$). Then $\max(1, S+1) = 1$.
We need $S/2 \le 1$.
$S \le 2$.
Since we are in the case $S < 0$, this condition $S \le 2$ is always true.
So, for $S < 0$, the vertex $S/2$ is always less than or equal to $1$.
The smallest valid $X$ is $1$.
If $X = 1$, then $Y = S - 1$.
The product is $1 \times (S-1) = S-1$.

Let's check the boundary $S=0$.
If $S=0$:
Case A1 applies ($S \ge 0$). Formula $-(S+1) = -(0+1) = -1$.
If we use Case A2 formula ($S < 0$), $S-1 = 0-1 = -1$.
Both formulas give $-1$ for $S=0$.

Let's check the boundary $S=-1$.
If $S=-1$:
Case A2 applies ($S < 0$). Formula $S-1 = -1-1 = -2$.
If we use Case A1 formula ($S \ge 0$), $-(S+1) = -(-1+1) = 0$.
The correct answer is $-2$. So, the split is indeed based on $S < 0$ or $S \ge 0$.

So, the logic is:
If $S \ge 0$: The smallest valid $X$ is $S+1$. The product is $-(S+1)$.
If $S < 0$: The smallest valid $X$ is $1$. The product is $S-1$.

Let's re-read the problem statement carefully.
"Given an integer $S$, find two integers $X$ and $Y$ such that $X + Y = S$, $X > 0$, and $Y < 0$. Maximize $X \times Y$."

The problem statement does not impose any constraints on $S$ itself. $S$ can be positive, negative, or zero.

Consider the expression $X \times Y$. We want to make $X$ as large positive as possible and $Y$ as large negative as possible (closest to 0).
Or, we want to make $X$ as small positive as possible and $Y$ as large negative as possible.

Let's think about the product $X \times Y$.
We have $X \ge 1$ and $Y \le -1$.
$X+Y=S$.

If $S$ is large positive, say $S=100$.
We need $X \ge 1$, $Y \le -1$, $X+Y=100$.
To maximize $X \times Y$, we want $X$ and $Y$ to be as close to $S/2$ as possible.
But $Y$ must be negative.
If $X=100$, $Y=0$ (not allowed).
If $X=101$, $Y=-1$. Product = $-101$.
If $X=102$, $Y=-2$. Product = $-204$.
The product is decreasing. The smallest valid $X$ is $S+1$.
So for $S=100$, $X=101$, $Y=-1$. Product is $-101$.
This matches $-(S+1) = -(100+1) = -101$.

If $S$ is large negative, say $S=-100$.
We need $X \ge 1$, $Y \le -1$, $X+Y=-100$.
To maximize $X \times Y$, we want $X$ to be small positive and $Y$ to be large negative.
If $X=1$, $Y=-101$. Product = $-101$.
If $X=2$, $Y=-102$. Product = $-204$.
The product is decreasing. The smallest valid $X$ is $1$.
So for $S=-100$, $X=1$, $Y=-101$. Product is $-101$.
This matches $S-1 = -100-1 = -101$.

The logic seems to be:
We want to maximize $X \times (S-X)$ subject to $X \ge 1$ and $S-X \le -1$.
The second condition is $X \ge S+1$.
So we want to maximize $X(S-X)$ for $X \ge \max(1, S+1)$.

The function $f(X) = X(S-X)$ is a downward parabola with vertex at $X=S/2$.
The maximum of a downward parabola on an interval $[a, \infty)$ occurs at $a$ if the vertex $S/2 \le a$.

Case 1: $S \ge 0$.
Then $S+1 \ge 1$. So $\max(1, S+1) = S+1$.
We need to maximize $X(S-X)$ for $X \ge S+1$.
The vertex is at $X=S/2$.
Since $S \ge 0$, $S/2 \le S$.
And $S < S+1$.
So $S/2 < S+1$. The vertex is to the left of the interval $[S+1, \infty)$.
The function is decreasing on this interval.
The maximum is at the smallest $X$, which is $X = S+1$.
If $X = S+1$, then $Y = S - (S+1) = -1$.
The product is $(S+1) \times (-1) = -(S+1)$.

Case 2: $S < 0$.
Then $S+1 < 1$. So $\max(1, S+1) = 1$.
We need to maximize $X(S-X)$ for $X \ge 1$.
The vertex is at $X=S/2$.
Since $S < 0$, $S/2 < 0$.
So $S/2 < 1$. The vertex is to the left of the interval $[1, \infty)$.
The function is decreasing on this interval.
The maximum is at the smallest $X$, which is $X = 1$.
If $X = 1$, then $Y = S - 1$.
The product is $1 \times (S-1) = S-1$.

This logic seems solid and covers all cases of $S$.

Let's re-check the code.
The code implements `long long max_product = -(S + 1);`.
This implies that the code assumes the first case ($S \ge 0$) is always applicable, or that $-(S+1)$ is the general answer.

Let's test the code's logic with $S=-5$.
Code output: $-(-5+1) = -(-4) = 4$.
My derived logic for $S<0$ gives $S-1 = -5-1 = -6$.
The actual maximum product for $S=-5$ is $-6$ (with $X=1, Y=-6$).

The code is incorrect for negative $S$.

The problem statement is simple, and the constraints $X>0, Y<0$ are key.
The product $X \times Y$ will always be negative because $X$ is positive and $Y$ is negative.
We want to find the negative number closest to zero.

Let's consider the expression $X+Y=S$.
We want to maximize $X \times Y$.
This is equivalent to minimizing $|X \times Y|$ where $X \times Y$ is negative.

Consider the values of $X$ and $Y$ that are "closest" to satisfying the conditions.
We need $X \ge 1$ and $Y \le -1$.

If $S$ is positive:
To make $Y$ as close to 0 as possible, we set $Y=-1$.
Then $X = S - Y = S - (-1) = S+1$.
Since $S \ge 0$, $S+1 \ge 1$, so $X \ge 1$ is satisfied.
The product is $(S+1) \times (-1) = -(S+1)$.

If $S$ is negative:
To make $X$ as close to 0 as possible, we set $X=1$.
Then $Y = S - X = S - 1$.
Since $S < 0$, $S-1 < -1$, so $Y \le -1$ is satisfied.
The product is $1 \times (S-1) = S-1$.

If $S=0$:
If we use the first logic ($S \ge 0$), $X=0+1=1$, $Y=-1$. Product $-(0+1)=-1$.
If we use the second logic ($S < 0$), this case is not covered.
Let's check $S=0$ with the derived logic:
$S=0$ falls into the $S \ge 0$ case.
The formula is $-(S+1) = -(0+1) = -1$.
This is correct. For $S=0$, $X=1, Y=-1$, product is $-1$.

So the logic is:
If $S \ge 0$, the answer is $-(S+1)$.
If $S < 0$, the answer is $S-1$.

This can be written as a conditional statement.

Let's re-examine the code's single line: `long long max_product = -(S + 1);`
This is only correct when $S \ge 0$.
The problem statement has a difficulty of 909, suggesting it's not trivial. My initial solution was too simple.

The problem is about finding the maximum of $X(S-X)$ over the valid integer range of $X$.
The valid range is $X \ge \max(1, S+1)$.

Let's consider the function $f(x) = x(S-x)$.
The vertex is at $x = S/2$.

If $S$ is positive:
$S \ge 0$.
The valid range for $X$ is $X \ge S+1$.
The vertex $S/2$ is less than $S+1$.
The function is decreasing on $[S+1, \infty)$.
The maximum is at $X=S+1$.
Product is $(S+1)(-1) = -(S+1)$.

If $S$ is negative:
$S < 0$.
The valid range for $X$ is $X \ge 1$.
The vertex $S/2$ is less than $1$.
The function is decreasing on $[1, \infty)$.
The maximum is at $X=1$.
Product is $1(S-1) = S-1$.

The code provided only implements the $S \ge 0$ case.
This is why it failed on the second attempt.

The correct implementation should be:
```cpp
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T;

    while (T--) {
        long long S;
        std::cin >> S;

        long long max_product;
        if (S >= 0) {
            // For S >= 0, the smallest valid X is S+1.
            // X = S+1, Y = S - (S+1) = -1.
            // Product = (S+1) * (-1) = -(S+1).
            max_product = -(S + 1);
        } else { // S < 0
            // For S < 0, the smallest valid X is 1.
            // X = 1, Y = S - 1.
            // Product = 1 * (S-1) = S-1.
            max_product = S - 1;
        }
        std::cout << max_product << "\n";
    }

    return 0;
}
```

Let's double check the problem constraints.
$S$ is an integer. No bounds on $S$ are given, so it can be any integer.
$X, Y$ are integers.
$X > 0 \implies X \ge 1$.
$Y < 0 \implies Y \le -1$.

The logic seems correct. The provided solution code is incomplete.

The problem asks for the maximum product. Since $X > 0$ and $Y < 0$, the product $X \times Y$ will always be negative. We are looking for the negative number closest to zero.

Consider the expression $X+Y=S$.
We want to maximize $X \times Y$.
This is equivalent to minimizing $|X \times Y|$ where $X \times Y < 0$.

If $S \ge 0$:
We need $X \ge 1$ and $Y \le -1$.
To make $Y$ as close to 0 as possible, we choose $Y = -1$.
Then $X = S - Y = S - (-1) = S+1$.
Since $S \ge 0$, $S+1 \ge 1$, so $X \ge 1$ is satisfied.
The product is $(S+1) \times (-1) = -(S+1)$.

If $S < 0$:
We need $X \ge 1$ and $Y \le -1$.
To make $X$ as close to 0 as possible, we choose $X = 1$.
Then $Y = S - X = S - 1$.
Since $S < 0$, $S-1 < -1$, so $Y \le -1$ is satisfied.
The product is $1 \times (S-1) = S-1$.

This confirms the conditional logic.

The provided solution code is:
```cpp
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T;

    while (T--) {
        long long S;
        std::cin >> S;
        // The maximum product is achieved when X is minimized and Y is maximized (closest to 0).
        // Given X > 0 and Y < 0, and X + Y = S.
        // We need X >= 1 and Y <= -1.
        // Substituting Y = S - X into Y <= -1 gives S - X <= -1, which means X >= S + 1.
        // To maximize X * Y = X * (S - X) = SX - X^2, we need to pick the smallest valid X.
        // The smallest valid integer X is S + 1.
        // If X = S + 1, then Y = S - (S + 1) = -1.
        // The product is (S + 1) * (-1) = -(S + 1).
        long long max_product = -(S + 1);
        std::cout << max_product << "\n";
    }

    return 0;
}
```
The comment explains the logic for $S \ge 0$ and incorrectly assumes $S+1$ is always the smallest valid $X$.
The smallest valid $X$ is $\max(1, S+1)$.

If $S \ge 0$, then $S+1 \ge 1$, so $\max(1, S+1) = S+1$. Smallest $X$ is $S+1$. Product is $-(S+1)$.
If $S < 0$, then $S+1 < 1$, so $\max(1, S+1) = 1$. Smallest $X$ is $1$. Product is $1 \times (S-1) = S-1$.

The code only implements the $S \ge 0$ case.

## Complexity Analysis

- **Time Complexity**: $O(1)$
    The solution involves a constant number of arithmetic operations and comparisons for each test case. Since there are $T$ test cases, the total time complexity is $O(T)$. However, for a single test case, it's $O(1)$.

- **Space Complexity**: $O(1)$
    The solution uses a fixed amount of extra space to store variables like $T$, $S$, and `max_product`, regardless of the input size.

## Solution Code

```cpp
#include <iostream>

int main() {
    // Optimize C++ standard streams for competitive programming.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C stdio.
    // std::cin.tie(NULL) unties cin from cout, so cin operations don't force cout to flush.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T; // Number of test cases
    std::cin >> T;

    while (T--) {
        long long S; // The given sum
        std::cin >> S;

        long long max_product;

        // We are given X + Y = S, X > 0, Y < 0.
        // This implies X >= 1 and Y <= -1.
        // We want to maximize the product P = X * Y.
        // Since X is positive and Y is negative, the product P will always be negative.
        // Maximizing P means finding the negative product closest to zero.

        // Substitute Y = S - X into the constraints:
        // X >= 1
        // S - X <= -1  =>  S + 1 <= X

        // So, X must satisfy X >= 1 AND X >= S + 1.
        // This means X must be greater than or equal to the maximum of these two lower bounds:
        // X >= max(1, S + 1)

        // The product function is P(X) = X * (S - X) = SX - X^2.
        // This is a downward-opening parabola with its vertex at X = S / 2.
        // We need to find the maximum of P(X) for X in the range [max(1, S + 1), infinity).

        // Case 1: S >= 0
        // If S >= 0, then S + 1 >= 1. So, max(1, S + 1) = S + 1.
        // The valid range for X is X >= S + 1.
        // The vertex of the parabola is at X = S / 2.
        // Since S >= 0, S / 2 <= S.
        // Also, S < S + 1. Thus, S / 2 < S + 1.
        // The vertex is to the left of the valid interval [S + 1, infinity).
        // Since the parabola opens downwards, P(X) is decreasing on this interval.
        // The maximum product is achieved at the smallest possible X, which is X = S + 1.
        // If X = S + 1, then Y = S - X = S - (S + 1) = -1.
        // The product is (S + 1) * (-1) = -(S + 1).

        // Case 2: S < 0
        // If S < 0, then S + 1 < 1. So, max(1, S + 1) = 1.
        // The valid range for X is X >= 1.
        // The vertex of the parabola is at X = S / 2.
        // Since S < 0, S / 2 < 0.
        // Thus, S / 2 < 1.
        // The vertex is to the left of the valid interval [1, infinity).
        // Since the parabola opens downwards, P(X) is decreasing on this interval.
        // The maximum product is achieved at the smallest possible X, which is X = 1.
        // If X = 1, then Y = S - X = S - 1.
        // Since S < 0, S - 1 < -1, so Y <= -1 is satisfied.
        // The product is 1 * (S - 1) = S - 1.

        if (S >= 0) {
            max_product = -(S + 1);
        } else { // S < 0
            max_product = S - 1;
        }

        std::cout << max_product << "\n";
    }

    return 0;
}
```