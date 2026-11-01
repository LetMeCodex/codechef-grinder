# [Valid Minimum (VALIDMIN)](https://www.codechef.com/problems/VALIDMIN)
- **Difficulty Rating**: 1132
- **Solved in**: 2 attempt(s)

## Problem Summary

The problem asks us to determine if three given positive integers `x, y, z` can be the minimums of pairs from a triplet of positive integers `A, B, C`. Specifically, we need to check if there exist positive integers `A, B, C` such that:
1. `x = min(A, B)`
2. `y = min(B, C)`
3. `z = min(C, A)`

If such `A, B, C` exist, we should print "YES"; otherwise, print "NO".

## Intuition & Mathematical Observation

Let's analyze the conditions `x = min(A, B)`, `y = min(B, C)`, `z = min(C, A)`.

From these definitions, we can deduce lower bounds for `A, B, C`:
- `A >= x` (from `min(A, B) = x`)
- `A >= z` (from `min(C, A) = z`)
  Therefore, `A >= max(x, z)`.
- `B >= x` (from `min(A, B) = x`)
- `B >= y` (from `min(B, C) = y`)
  Therefore, `B >= max(x, y)`.
- `C >= y` (from `min(B, C) = y`)
- `C >= z` (from `min(C, A) = z`)
  Therefore, `C >= max(y, z)`.

Now, let's consider the relationship between `x, y, z` themselves.
Suppose a valid triplet `(A, B, C)` exists.
Consider the smallest value among `A, B, C`. Let `min(A, B, C) = K`.

**Case 1: `K = A`**
If `A` is the smallest, then `A <= B` and `A <= C`.
- `x = min(A, B) = A` (since `A <= B`)
- `z = min(C, A) = A` (since `A <= C`)
So, `x = z = A`.
Now consider `y = min(B, C)`. Since `A <= B` and `A <= C`, it must be that `A <= min(B, C)`.
Thus, `x = z <= y`.
In this case, two of the given minimums (`x` and `z`) are equal, and this common value is less than or equal to the third minimum (`y`).

**Case 2: `K = B`**
If `B` is the smallest, then `B <= A` and `B <= C`.
- `x = min(A, B) = B` (since `B <= A`)
- `y = min(B, C) = B` (since `B <= C`)
So, `x = y = B`.
Now consider `z = min(C, A)`. Since `B <= A` and `B <= C`, it must be that `B <= min(C, A)`.
Thus, `x = y <= z`.
Again, two minimums (`x` and `y`) are equal, and this common value is less than or equal to the third (`z`).

**Case 3: `K = C`**
If `C` is the smallest, then `C <= A` and `C <= B`.
- `y = min(B, C) = C` (since `C <= B`)
- `z = min(C, A) = C` (since `C <= A`)
So, `y = z = C`.
Now consider `x = min(A, B)`. Since `C <= A` and `C <= B`, it must be that `C <= min(A, B)`.
Thus, `y = z <= x`.
Once more, two minimums (`y` and `z`) are equal, and this common value is less than or equal to the third (`x`).

From these three cases, we can conclude that if a valid triplet `(A, B, C)` exists, then among `x, y, z`, two of the values must be equal, and this common value must be less than or equal to the third value. This is equivalent to saying that if we sort `x, y, z` in non-decreasing order as `m1 <= m2 <= m3`, then `m1` must be equal to `m2`.

**Is this condition sufficient?**
Let's assume the condition holds. Without loss of generality, let's assume `x = y` and `x <= z`. (The other two cases are symmetric by relabeling `x, y, z`).
We need to find `A, B, C` such that:
`min(A, B) = x`
`min(B, C) = x` (since `y=x`)
`min(C, A) = z`

Let's try to construct `A, B, C` using the lower bounds we derived, aiming for the smallest possible values:
- `A >= max(x, z)`
- `B >= max(x, x)` which simplifies to `B >= x`
- `C >= max(x, z)`

Since we assumed `x <= z`, `max(x, z)` is simply `z`.
So, we have:
- `A >= z`
- `B >= x`
- `C >= z`

Let's try setting `A, B, C` to these minimum possible values:
`A = z`
`B = x`
`C = z`

Now, let's check if these `A, B, C` satisfy the original conditions:
1. `min(A, B) = min(z, x)`. Since `x <= z`, this evaluates to `x`. (Matches `x`)
2. `min(B, C) = min(x, z)`. Since `x <= z`, this evaluates to `x`. (Matches `y`, because `y=x`)
3. `min(C, A) = min(z, z)`. This evaluates to `z`. (Matches `z`)

All conditions are satisfied! Since `x, y, z` are positive integers, the constructed `A, B, C` will also be positive integers.
Thus, the condition is also sufficient.

The problem boils down to checking if any two of the three given numbers are equal, and if that equal value is less than or equal to the third number.

The code implements this logic directly:
`if ((x == y && x <= z) || (y == z && y <= x) || (x == z && x <= y))`

## Complexity Analysis

-   **Time Complexity**: For each test case, the solution reads three integers and performs a constant number of comparisons and logical operations. This takes $O(1)$ time per test case. If there are $T$ test cases, the total time complexity is $O(T)$.

-   **Space Complexity**: The solution uses a few integer variables (`x, y, z, t`) to store input and loop counters. This requires a constant amount of memory, $O(1)$, regardless of the input values.

## Solution Code

```cpp
#include <iostream> // Required for standard input/output operations (cin, cout)

void solve() {
    int x, y, z;
    // Read the three given minimum values
    std::cin >> x >> y >> z;

    // The logic checks if the set of given minimums {x, y, z} is of the form {K, K, L} where K <= L.
    // This is equivalent to checking if, after sorting the three values, the two smallest are equal.
    //
    // For example:
    // - If x=y=z (e.g., 5 5 5), then (5==5 && 5<=5) is true. A valid tuple is (5, 5, 5).
    // - If x=y < z (e.g., 2 2 4), then (2==2 && 2<=4) is true. A valid tuple is (4, 2, 4).
    // - If y=z < x (e.g., 5 3 3), then (3==3 && 3<=5) is true. A valid tuple is (5, 5, 3).
    // - If x=z < y (e.g., 3 5 3), then (3==3 && 3<=5) is true. A valid tuple is (5, 3, 5).
    //
    // If all three are distinct (e.g., 2 3 4), none of these conditions will be met, and it's impossible.
    // If two are equal but the third is smaller (e.g., x=3, y=5, z=5), this is also impossible
    // (as min(B,C)=5, min(C,A)=5 implies A,B,C >= 5, which means min(A,B) must be >= 5,
    // contradicting min(A,B)=3).
    //
    // The conditions correctly cover all valid scenarios and reject all impossible ones.
    if ((x == y && x <= z) || 
        (y == z && y <= x) || 
        (x == z && x <= y)) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming and ensures I/O is not a bottleneck.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    // Read the number of test cases
    std::cin >> t;
    // Loop through each test case
    while (t--) {
        solve();
    }

    return 0;
}
```