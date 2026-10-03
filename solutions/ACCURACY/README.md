# [High Accuracy (ACCURACY)](https://www.codechef.com/problems/ACCURACY)
- **Difficulty Rating**: 580
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to find the minimum number of incorrect answers a student can have, given that their total score is $X$. The scoring system is as follows: +3 for a correct answer, -1 for an incorrect answer, and 0 for an unattempted question. There are a total of 100 questions.

## Intuition & Mathematical Observation

Let $c$ be the number of correct answers, $i$ be the number of incorrect answers, and $u$ be the number of unattempted questions.
We are given the following constraints:
1.  The total number of questions is 100: $c + i + u = 100$
2.  The total score is $X$: $3c - 1i + 0u = X$, which simplifies to $3c - i = X$.
3.  The number of questions must be non-negative integers: $c \ge 0$, $i \ge 0$, $u \ge 0$.

Our goal is to minimize $i$.

From the score equation, $3c - i = X$, we can express $c$ in terms of $i$ and $X$:
$3c = X + i$
$c = \frac{X + i}{3}$

For $c$ to be a valid number of correct answers, it must be a non-negative integer.
-   **Non-negativity of $c$**: Since $X \ge 0$ (given in constraints) and we are looking for $i \ge 0$, $X+i$ will always be non-negative. Thus, $c \ge 0$ is automatically satisfied.
-   **Integer $c$**: For $c$ to be an integer, $(X + i)$ must be divisible by 3. This means $(X + i) \pmod 3 = 0$.

Now, let's consider the constraint on the total number of questions: $c + i + u = 100$.
Since $u \ge 0$, we must have $c + i \le 100$.

Substitute the expression for $c$ into this inequality:
$\frac{X + i}{3} + i \le 100$

To solve for $i$, we can multiply by 3:
$(X + i) + 3i \le 300$
$X + 4i \le 300$
$4i \le 300 - X$
$i \le \frac{300 - X}{4}$

So, we need to find the minimum non-negative integer $i$ that satisfies two conditions:
1.  $(X + i) \pmod 3 = 0$ (to ensure $c$ is an integer)
2.  $c + i \le 100$, which we derived as $i \le \frac{300 - X}{4}$.

We are looking for the *minimum* such $i$. We can iterate through possible values of $i$ starting from 0 and check if these conditions are met. The first value of $i$ that satisfies both conditions will be our answer.

The loop for $i$ can start from 0. What is the upper bound for $i$? Since $i$ is the number of incorrect answers out of 100 questions, $i$ cannot exceed 100. The derived inequality $i \le \frac{300 - X}{4}$ also provides an upper bound. For $X=0$, $i \le 75$. For $X=100$, $i \le 50$. In general, $i$ will be less than or equal to 100.

Therefore, we can iterate $i$ from 0 upwards. For each $i$, we check if $(X + i)$ is divisible by 3. If it is, we calculate $c = (X+i)/3$. Then we check if $c + i \le 100$. The first $i$ that satisfies these conditions is the minimum number of incorrect answers.

Let's trace with an example: $X = 10$.
We need to find minimum $i \ge 0$ such that:
1. $(10 + i) \pmod 3 = 0$
2. $i \le \frac{300 - 10}{4} = \frac{290}{4} = 72.5$

Let's try $i=0$: $(10+0) \pmod 3 = 10 \pmod 3 = 1 \ne 0$. Condition 1 fails.
Let's try $i=1$: $(10+1) \pmod 3 = 11 \pmod 3 = 2 \ne 0$. Condition 1 fails.
Let's try $i=2$: $(10+2) \pmod 3 = 12 \pmod 3 = 0$. Condition 1 passes.
Now check condition 2 for $i=2$: $2 \le 72.5$. Condition 2 passes.
So, the minimum $i$ is 2.
If $i=2$, then $c = (10+2)/3 = 12/3 = 4$.
Check total questions: $c+i = 4+2 = 6$. $u = 100 - 6 = 94$.
Score: $3*4 - 1*2 = 12 - 2 = 10$. This matches $X$.
So, for $X=10$, the minimum incorrect answers is 2.

The code implements this exact logic by iterating $i$ from 0 and checking the divisibility condition. The `c + i <= 100` check is implicitly handled because if `c + i > 100`, then `u` would be negative, which is not allowed. The loop breaks as soon as the first valid `i` is found, guaranteeing it's the minimum.

## Complexity Analysis

-   **Time Complexity**: $O(1)$ per test case.
    The loop iterates at most 100 times (from $i=0$ to $i=100$). Inside the loop, operations are constant time (modulo, division, addition, comparison). Since the number of iterations is bounded by a constant (100), the time complexity per test case is constant.
-   **Space Complexity**: $O(1)$ per test case.
    We only use a few integer variables to store the input and intermediate calculations. The space used does not depend on the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int x;
        cin >> x;

        // We need to find the minimum non-negative integer 'i' (incorrect answers)
        // such that there exists a non-negative integer 'c' (correct answers)
        // and a non-negative integer 'u' (unattempted questions) satisfying:
        // 1. c + i + u = 100
        // 2. 3*c - i = x

        // From equation (2), we can express 'c' in terms of 'x' and 'i':
        // 3*c = x + i
        // c = (x + i) / 3

        // For 'c' to be a valid number of correct answers, it must be a non-negative integer.
        // Since x >= 0 and we are looking for i >= 0, x + i will always be non-negative.
        // For 'c' to be an integer, (x + i) must be divisible by 3.
        // So, (x + i) % 3 == 0.

        // From equation (1), since u >= 0, we must have c + i <= 100.
        // Substituting c = (x + i) / 3:
        // (x + i) / 3 + i <= 100
        // x + i + 3*i <= 300
        // x + 4*i <= 300
        // 4*i <= 300 - x
        // i <= (300 - x) / 4

        // We need to find the smallest non-negative integer 'i' that satisfies:
        // 1. (x + i) % 3 == 0
        // 2. c + i <= 100 (where c = (x + i) / 3)

        // We can iterate through possible values of 'i' starting from 0.
        // The maximum possible value for 'i' is 100 (since there are only 100 questions).
        int min_incorrect = 0;
        for (int i = 0; i <= 100; ++i) {
            // Check if (x + i) is divisible by 3. If so, we can find an integer 'c'.
            if ((x + i) % 3 == 0) {
                int c = (x + i) / 3;
                // Check if the total number of questions attempted (correct + incorrect)
                // does not exceed 100. This ensures 'u' is non-negative.
                if (c + i <= 100) {
                    min_incorrect = i;
                    break; // Found the minimum 'i', so we can stop.
                }
            }
        }
        cout << min_incorrect << "\n";
    }
    return 0;
}
```