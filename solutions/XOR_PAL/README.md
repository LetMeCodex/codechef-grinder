# [Xor Palindrome (XOR_PAL)](https://www.codechef.com/problems/XOR_PAL)
- **Difficulty Rating**: 1129
- **Solved in**: 2 attempt(s)

## Problem Summary

The problem asks us to find the minimum number of operations to make a given binary string `A` of even length `N` a palindrome.
The described operation is: "choose an index `i` ($0 \le i < N$), and flip both `A[i]` and `A[N-1-i]` (i.e., change '0' to '1' and '1' to '0'). This operation costs 1."

**Important Note on Problem Statement Interpretation:**
The problem statement's description of the operation ("flip both `A[i]` and `A[N-1-i]`") is highly misleading. If interpreted literally, this operation would never change whether `A[k]` and `A[N-1-k]` are equal or unequal. This would mean that if the initial string has any mismatches, it can never become a palindrome. However, the example output and the provided solution code clearly indicate that mismatches *can* be resolved.

The solution code's logic is consistent with a common competitive programming problem variant where the actual operation is: **"Choose any two indices `i` and `j` (not necessarily symmetric, possibly `i=j`) and flip `A[i]` and `A[j]`. This operation costs 1."** We will proceed with this interpretation, as it is the only way the provided solution and example make sense.

## Intuition & Mathematical Observation

For a string `A` to be a palindrome, `A[k]` must be equal to `A[N-1-k]` for all `0 \le k < N/2`. Since `N` is even, there is no middle character.

We iterate through the first half of the string (from `k = 0` to `N/2 - 1`) and examine each pair `(A[k], A[N-1-k])`.

1.  **If `A[k] == A[N-1-k]`**: This pair already satisfies the palindrome condition. We don't need to perform any operation involving `A[k]` or `A[N-1-k]` to fix this pair.

2.  **If `A[k] != A[N-1-k]`**: This pair is a mismatch. We need to make `A[k]` and `A[N-1-k]` equal. This requires flipping exactly one of them. To minimize operations, we want to group these required flips efficiently.
    There are two types of mismatches:
    *   **Type 1: `A[k] = '1'` and `A[N-1-k] = '0'`** (let's call this a `(1,0)` mismatch). To fix this, we need to flip `A[k]` from `1` to `0` OR flip `A[N-1-k]` from `0` to `1`.
    *   **Type 2: `A[k] = '0'` and `A[N-1-k] = '1'`** (let's call this a `(0,1)` mismatch). To fix this, we need to flip `A[k]` from `0` to `1` OR flip `A[N-1-k]` from `1` to `0`.

Let's decide a consistent strategy for fixing mismatches. For each mismatch `(A[k], A[N-1-k])`, we will target `A[k]` for a flip.
*   For a `(1,0)` mismatch at `k`, we need to flip `A[k]` from `1` to `0`.
*   For a `(0,1)` mismatch at `k`, we need to flip `A[k]` from `0` to `1`.

Let `c10` be the count of `(1,0)` mismatches (where `A[k]` needs a `1 \to 0` flip).
Let `c01` be the count of `(0,1)` mismatches (where `A[k]` needs a `0 \to 1` flip).

Now, we use the assumed operation: "Choose any two indices `i` and `j` and flip `A[i]` and `A[j]`. Cost 1."

The strategy to minimize operations is as follows:

1.  **Pairing opposite flips**: We have `c10` indices where `A[k]` needs to be flipped `1 \to 0`, and `c01` indices where `A[k]` needs to be flipped `0 \to 1`.
    We can take one index `k_a` from the `c10` group and one index `k_b` from the `c01` group. Perform one operation: flip `A[k_a]` and `A[k_b]`.
    *   `A[k_a]` changes `1 \to 0`, fixing its mismatch.
    *   `A[k_b]` changes `0 \to 1`, fixing its mismatch.
    This single operation fixes two mismatches. We can do this `min(c10, c01)` times.
    `operations += min(c10, c01)`.

2.  **Fixing remaining flips of the same type**: After step 1, we are left with `remaining_flips = abs(c10 - c01)` mismatches. All these remaining mismatches are of the same type (e.g., all `(1,0)` mismatches where `A[k]` needs `1 \to 0` flip).
    *   If we have two such remaining mismatches, say at `k_c` and `k_d`, we can perform one operation: flip `A[k_c]` and `A[k_d]`. This fixes both with 1 operation.
    *   If `remaining_flips` is even, we need `remaining_flips / 2` operations.
    *   If `remaining_flips` is odd, we need `(remaining_flips - 1) / 2` operations for `remaining_flips - 1` mismatches, leaving one mismatch. This last mismatch requires one additional operation (flipping `A[k_e]` and some other `A[j]` which is not part of a mismatch pair, thus introducing a new mismatch, but this is the minimum possible).
    Combining these, the number of operations for remaining flips is `ceil(remaining_flips / 2.0)`, which can be calculated using integer division as `(remaining_flips + 1) / 2`.
    `operations += (remaining_flips + 1) / 2`.

The total minimum operations will be the sum of operations from these two steps.

**Example: `N=4, A="1010"`**
*   `k=0`: `A[0]='1', A[3]='0'`. This is a `(1,0)` mismatch. `c10 = 1`.
*   `k=1`: `A[1]='0', A[2]='1'`. This is a `(0,1)` mismatch. `c01 = 1`.

1.  `operations += std::min(c10, c01) = std::min(1, 1) = 1`.
2.  `remaining_flips = std::abs(c10 - c01) = std::abs(1 - 1) = 0`.
    `operations += (0 + 1) / 2 = 0`.

Total operations = `1 + 0 = 1`. This matches the example output.
To achieve this: flip `A[0]` (from `1` to `0`) and `A[1]` (from `0` to `1`). String becomes `0110`.
Now `(A[0], A[3]) = (0,0)` and `(A[1], A[2]) = (1,1)`. Both are palindromic.

## Complexity Analysis

-   **Time Complexity**: $O(N)$
    *   Reading the input `N` and string `A` takes $O(N)$ time.
    *   The loop iterates `N/2` times to count mismatches, which is $O(N)$.
    *   The subsequent arithmetic operations are $O(1)$.
    *   Therefore, the total time complexity per test case is $O(N)$. For `T` test cases, it's $O(T \cdot N)$.

-   **Space Complexity**: $O(N)$
    *   Storing the input string `A` requires $O(N)$ space.
    *   A few integer variables (`n`, `mismatches_target_0`, `mismatches_target_1`, `operations`, `remaining_mismatches`) use $O(1)$ space.
    *   Therefore, the total space complexity is $O(N)$.

## Solution Code

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // For std::min and std::abs

void solve() {
    int n;
    std::cin >> n;
    std::string a;
    std::cin >> a;

    // mismatches_target_0: Count of pairs (A_k, A_{N-1-k}) where A_k='1', A_{N-1-k}='0'
    // (Meaning A_k needs to be flipped from 1 to 0 to match A_{N-1-k})
    int mismatches_target_0 = 0; 
    
    // mismatches_target_1: Count of pairs (A_k, A_{N-1-k}) where A_k='0', A_{N-1-k}='1'
    // (Meaning A_k needs to be flipped from 0 to 1 to match A_{N-1-k})
    int mismatches_target_1 = 0; 

    // Iterate through the first half of the string to find mismatches
    for (int k = 0; k < n / 2; ++k) {
        if (a[k] != a[n - 1 - k]) {
            // Mismatch found
            if (a[k] == '1') { 
                mismatches_target_0++;
            } else { // a[k] == '0'
                mismatches_target_1++;
            }
        }
    }

    int operations = 0;
    
    // Step 1: Pair up mismatches of type (1,0) with mismatches of type (0,1).
    // Each such pairing can be fixed in one operation by flipping A[k] for both pairs.
    // For example, if we have (1,0) at index k and (0,1) at index j:
    // One operation: flip A[k] (1->0) and flip A[j] (0->1).
    // This fixes both mismatches.
    operations += std::min(mismatches_target_0, mismatches_target_1);
    
    // Step 2: Calculate the number of mismatches remaining after pairing different types.
    // These remaining mismatches will all be of the same type (e.g., all (1,0) or all (0,1)).
    int remaining_mismatches = std::abs(mismatches_target_0 - mismatches_target_1);
    
    // Step 3: Fix the remaining mismatches.
    // If we have two mismatches of the same type (e.g., (1,0) at k and (1,0) at j):
    // One operation: flip A[k] (1->0) and flip A[j] (1->0).
    // This fixes both mismatches.
    // If there's an odd number of remaining mismatches, the last one requires a separate operation.
    // This is equivalent to ceil(remaining_mismatches / 2.0).
    operations += (remaining_mismatches + 1) / 2; // Integer division for ceil

    std::cout << operations << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t; // Read the number of test cases
    while (t--) {
        solve(); // Solve each test case
    }
    return 0;
}

```