# [Nearest Court (NEARESTCOURT)](https://www.codechef.com/problems/NEARESTCOURT)
- **Difficulty Rating**: 819
- **Solved in**: 1 attempt(s)

## Problem Summary

Chef and Chefina are located at integer positions $X$ and $Y$ respectively on a 1D number line. They want to choose an integer position $Z$ for a new court. The objective is to minimize the maximum distance either Chef or Chefina has to travel to reach the court. In other words, they want to find an integer $Z$ that minimizes $\max(|X-Z|, |Y-Z|)$. We need to output this minimum possible maximum distance.

The constraints are $1 \le X, Y \le 1000$ and $X \neq Y$.

## Intuition & Mathematical Observation

The problem asks us to find an integer $Z$ that minimizes $\max(|X-Z|, |Y-Z|)$. This is a classic minimax problem on a 1D line.

Consider the segment between $X$ and $Y$. Let's assume without loss of generality that $X < Y$.
1. If we choose $Z < X$: Then $|X-Z| = X-Z$ and $|Y-Z| = Y-Z$. Since $Y-Z > X-Z$, $\max(|X-Z|, |Y-Z|) = Y-Z$. This value increases as $Z$ moves further left.
2. If we choose $Z > Y$: Then $|X-Z| = Z-X$ and $|Y-Z| = Z-Y$. Since $Z-X > Z-Y$, $\max(|X-Z|, |Y-Z|) = Z-X$. This value increases as $Z$ moves further right.
3. If we choose $X \le Z \le Y$: Then $|X-Z| = Z-X$ and $|Y-Z| = Y-Z$. We want to minimize $\max(Z-X, Y-Z)$.
   The sum of these two distances is $(Z-X) + (Y-Z) = Y-X$. This sum is constant for any $Z$ between $X$ and $Y$.
   To minimize the maximum of two numbers whose sum is constant, we should make the two numbers as equal as possible.
   This occurs when $Z-X \approx Y-Z$, which means $Z \approx (X+Y)/2$.

The point that perfectly balances the distances is the midpoint of $X$ and $Y$, which is $(X+Y)/2$. At this midpoint, both Chef and Chefina would travel a distance of $|X - (X+Y)/2| = |(X-Y)/2| = |Y - (X+Y)/2| = |(Y-X)/2|$. This distance is $|X-Y|/2$.

Since $Z$ must be an integer, we cannot always pick the exact midpoint if $(X+Y)/2$ is not an integer. We must choose an integer $Z$ closest to the midpoint.
If we choose an integer $Z$ closest to $(X+Y)/2$, the maximum distance will be $\lceil |X-Y|/2 \rceil$.

Let's verify with examples:
- If $X=2, Y=6$: $|X-Y|=4$. Midpoint is $(2+6)/2 = 4$.
  If $Z=4$, Chef travels $|2-4|=2$, Chefina travels $|6-4|=2$. Max distance is $2$.
  $\lceil 4/2 \rceil = 2$. Matches.
- If $X=2, Y=5$: $|X-Y|=3$. Midpoint is $(2+5)/2 = 3.5$.
  If $Z=3$, Chef travels $|2-3|=1$, Chefina travels $|5-3|=2$. Max distance is $2$.
  If $Z=4$, Chef travels $|2-4|=2$, Chefina travels $|5-4|=1$. Max distance is $2$.
  $\lceil 3/2 \rceil = \lceil 1.5 \rceil = 2$. Matches.

So, the minimum maximum distance is indeed $\lceil |X-Y|/2 \rceil$.

To calculate $\lceil A/B \rceil$ for positive integers $A, B$ using integer division, the formula is $(A + B - 1) / B$.
In our case, $A = |X-Y|$ and $B = 2$.
Thus, the result is $(|X-Y| + 2 - 1) / 2$, which simplifies to $(|X-Y| + 1) / 2$.
The constraints $X \neq Y$ ensure that $|X-Y| \ge 1$, so this formula is always valid for positive numerators.

## Complexity Analysis

-   **Time Complexity**: $O(T)$
    For each test case, we perform a constant number of operations: reading two integers, calculating an absolute difference, an addition, a division, and printing the result. These operations take constant time. Since there are $T$ test cases, the total time complexity is proportional to $T$.

-   **Space Complexity**: $O(1)$
    The solution uses a fixed number of integer variables (`T`, `X`, `Y`, `diff`, `result`) regardless of the input values of $X$ and $Y$. The memory usage does not scale with the input size, hence the space complexity is constant.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes iostream, cmath, etc.

// According to problem instructions, use 'using namespace std;'
using namespace std;

int main() {
    // Fast I/O as per problem instructions
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Number of test cases
    cin >> T; // Read the number of test cases
    while (T--) { // Loop through each test case
        int X, Y; // Positions of Chef and Chefina
        cin >> X >> Y; // Read X and Y for the current test case

        // The problem asks to find an integer court position Z that minimizes
        // the maximum distance travelled by either Chef or Chefina.
        // This is equivalent to minimizing max(|X-Z|, |Y-Z|).
        //
        // The optimal court Z is the integer point closest to the midpoint of X and Y.
        // The minimum value of max(|X-Z|, |Y-Z|) will be ceil(|X-Y| / 2).
        //
        // For positive integers A and B, ceil(A/B) can be calculated using
        // integer division as (A + B - 1) / B.
        // In this problem, A = |X-Y| and B = 2.
        // So, the formula becomes (|X-Y| + 2 - 1) / 2, which simplifies to (|X-Y| + 1) / 2.
        //
        // Constraints: 1 <= X, Y <= 1000 and X != Y.
        // This guarantees that |X-Y| is always at least 1, so the formula is valid.

        int diff = abs(X - Y); // Calculate the absolute difference between X and Y
        int result = (diff + 1) / 2; // Apply the formula to get ceil(diff / 2)

        cout << result << "\n"; // Output the calculated minimum maximum distance
    }

    return 0; // Indicate successful execution
}
```