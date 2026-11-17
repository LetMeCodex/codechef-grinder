Here's a clean, high-quality solution writeup in GitHub-Flavored Markdown for the CodeChef problem ANOTSTR.

---

# [Another String (ANOTSTR)](https://www.codechef.com/problems/ANOTSTR)
- **Difficulty Rating**: 1140
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks whether a binary string `A` can be transformed into another binary string `B` of the same length `N` using a specific operation. The operation involves choosing two distinct indices `i` and `j` (`i \neq j`), then performing two steps:
1. Swap the characters `A[i]` and `A[j]`.
2. Flip both `A[i]` and `A[j]` (i.e., `0` becomes `1`, and `1` becomes `0`).

The constraint given is `N >= 3`.

## Intuition & Mathematical Observation

Let's analyze the effect of the operation on the total number of '1's in the string. Let `val_i` and `val_j` be the original values of `A[i]` and `A[j]` respectively.
The operation transforms `A[i]` to `1 - val_j` and `A[j]` to `1 - val_i`.

We consider the four possible pairs for `(val_i, val_j)`:

1.  **Case (0, 0)**:
    *   `A[i]` becomes `1 - 0 = 1`.
    *   `A[j]` becomes `1 - 0 = 1`.
    *   Two '0's become two '1's. The total count of '1's increases by 2.
    *   Parity of '1's count: `count + 2` has the same parity as `count`.

2.  **Case (0, 1)**:
    *   `A[i]` becomes `1 - 1 = 0`.
    *   `A[j]` becomes `1 - 0 = 1`.
    *   A '0' and a '1' remain a '0' and a '1'. The total count of '1's remains unchanged (0).
    *   Parity of '1's count: `count + 0` has the same parity as `count`.

3.  **Case (1, 0)**:
    *   `A[i]` becomes `1 - 0 = 1`.
    *   `A[j]` becomes `1 - 1 = 0`.
    *   A '1' and a '0' remain a '1' and a '0'. The total count of '1's remains unchanged (0).
    *   Parity of '1's count: `count + 0` has the same parity as `count`.

4.  **Case (1, 1)**:
    *   `A[i]` becomes `1 - 1 = 0`.
    *   `A[j]` becomes `1 - 1 = 0`.
    *   Two '1's become two '0's. The total count of '1's decreases by 2.
    *   Parity of '1's count: `count - 2` has the same parity as `count`.

**Key Observation:** In all possible scenarios, the parity of the total number of '1's in the string remains invariant. This means that if string `A` can be transformed into string `B`, then the number of '1's in `A` (`countA`) and the number of '1's in `B` (`countB`) must have the same parity.

**Is this condition sufficient?**
The problem states `N >= 3`. This is a crucial detail.
If `N=1` or `N=2`, the condition might not be sufficient. For example, if `N=2`, `A="01"`, `B="10"`. `countA=1`, `countB=1`. Parity matches. However, applying the operation on `(0,1)` for `A="01"` results in `A[0]` becoming `1-A[1]=1-1=0` and `A[1]` becoming `1-A[0]=1-0=1`. So `A` remains `01`. We cannot transform `A` to `B`.

However, with `N >= 3`, we have more flexibility.
The operations allow us to:
*   Change `00` to `11` (increase count by 2).
*   Change `11` to `00` (decrease count by 2).
*   The `01` or `10` pairs remain `01` or `10` respectively. This means the operation on a pair of different characters does not change the string.

The ability to change the count of '1's by `+2` or `-2` means we can reach any target count `countB` from `countA` as long as `countA` and `countB` have the same parity.
Once `countA` matches `countB`, we need to be able to rearrange the '0's and '1's to match string `B`.
Consider the case where `A[i] = 0` and `A[j] = 1`. We want to effectively swap them to `A[i] = 1` and `A[j] = 0`. Since `N >= 3`, we can always pick a third index `k` distinct from `i` and `j`.
Let's demonstrate how to swap `A[i]=0` and `A[j]=1` using `A[k]=X`:
1.  **Operate on `(i, k)`**: `(A[i], A[k]) = (0, X)` becomes `(1-X, 1)`.
    String state: `... (1-X)_i ... 1_j ... 1_k ...`
2.  **Operate on `(j, k)`**: `(A[j], A[k]) = (1, 1)` (using current values) becomes `(0, 0)`.
    String state: `... (1-X)_i ... 0_j ... 0_k ...`
3.  **Operate on `(i, k)`**: `(A[i], A[k]) = (1-X, 0)` (using current values) becomes `(1, 1-X)`.
    String state: `... 1_i ... 0_j ... (1-X)_k ...`

After these three operations, `A[i]` and `A[j]` have effectively swapped their values (`0` and `1`), and `A[k]` has been restored to its original value `X`. Each step preserves the parity of the total count of '1's.

Since we can both adjust the total count of '1's (by `+2` or `-2`) and rearrange '0's and '1's arbitrarily (by effectively swapping any two positions), the condition that `countA` and `countB` have the same parity is sufficient when `N >= 3`.

Therefore, the solution is to count the number of '1's in `A` and `B`, and if their parities match, output "YES"; otherwise, output "NO".

## Complexity Analysis

Let `N` be the length of the strings.

*   **Time Complexity**: $O(N)$
    *   Reading `N`, `A`, and `B` takes $O(N)$ time.
    *   Iterating through string `A` to count '1's takes $O(N)$ time.
    *   Iterating through string `B` to count '1's takes $O(N)$ time.
    *   The comparison and printing take $O(1)$ time.
    *   Since there are `T` test cases, the total time complexity is $O(T \cdot N)$.

*   **Space Complexity**: $O(N)$
    *   Storing strings `A` and `B` requires $O(N)$ space.
    *   A few integer variables for counts and loop iterators require $O(1)$ space.
    *   The total space complexity is $O(N)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes common headers like iostream, string, etc.
using namespace std;

void solve() {
    int N;
    cin >> N;
    string A, B;
    cin >> A >> B;

    // Count the number of '1's in string A
    int countA = 0;
    for (char c : A) {
        if (c == '1') {
            countA++;
        }
    }

    // Count the number of '1's in string B
    int countB = 0;
    for (char c : B) {
        if (c == '1') {
            countB++;
        }
    }

    // If the parity of '1's counts is the same, transformation is possible
    if (countA % 2 == countB % 2) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Number of test cases
    cin >> T;
    while (T--) {
        solve(); // Solve each test case
    }
    return 0;
}

```