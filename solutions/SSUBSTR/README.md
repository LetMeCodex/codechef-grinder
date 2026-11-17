Here's a clean, high-quality solution writeup for the CodeChef problem Sorted Substrings (SSUBSTR) in GitHub-Flavored Markdown.

---

# [Sorted Substrings (SSUBSTR)](https://www.codechef.com/problems/SSUBSTR)
- **Difficulty Rating**: 1310
- **Solved in**: 2 attempt(s)

## Problem Summary

The problem asks for the minimum number of operations required to sort a given binary string $S$ of length $N$. A binary string is considered sorted if all '0's appear before all '1's (e.g., "000", "111", "0011"). An operation consists of choosing any substring $S[L \dots R]$ and reversing it.

## Intuition & Mathematical Observation

The goal is to transform the given binary string $S$ into a sorted form, which means it should look like `0...01...1`.

Let's identify the characteristics of a sorted string:
1. It contains only '0's (e.g., "000").
2. It contains only '1's (e.g., "111").
3. It contains some '0's followed by some '1's (e.g., "0011", "01").
Crucially, a sorted string *never* has a '1' appearing before a '0' (i.e., it does not contain "10" as a substring).

We can find the "unsortedness" of the string by identifying the first '1' that appears before a '0'.
Let `first_one_idx` be the index of the first occurrence of '1' in the string.
Let `last_zero_idx` be the index of the last occurrence of '0' in the string.

**Case 1: The string is already sorted.**
This happens in a few scenarios, all of which require 0 operations:
*   If `first_one_idx == -1`: The string contains no '1's (e.g., "000"). It's sorted.
*   If `last_zero_idx == -1`: The string contains no '0's (e.g., "111"). It's sorted.
*   If `first_one_idx > last_zero_idx`: All '0's appear before all '1's (e.g., "0011", "000", "111"). The first '1' is to the right of the last '0'. It's sorted.

**Case 2: The string is unsorted.**
This occurs if and only if `first_one_idx < last_zero_idx`. This condition implies that there is at least one '1' that appears before at least one '0'. For example, in "01011", `first_one_idx = 1` and `last_zero_idx = 2`.

When `first_one_idx < last_zero_idx`, we know we need at least one operation. Consider the substring $P = S[\text{first\_one\_idx} \dots \text{last\_zero\_idx}]$.
This substring $P$ *must* start with '1' (at `first_one_idx`) and end with '0' (at `last_zero_idx`).
Example: `S = 00101011`
`first_one_idx = 2` (S[2] is '1')
`last_zero_idx = 5` (S[5] is '0')
The problematic segment $P = S[2 \dots 5]$ is `1010`.

If we perform one operation by reversing the entire segment $P = S[\text{first\_one\_idx} \dots \text{last\_zero\_idx}]$:
*   The '1' at `first_one_idx` moves to `last_zero_idx`.
*   The '0' at `last_zero_idx` moves to `first_one_idx`.
This single operation effectively fixes the outermost `1...0` inversion. This is why we always need at least 1 operation if the string is unsorted.

Now, let's consider what happens to the characters *inside* this segment $P$.
Any `01` pattern within $P$ (e.g., `...01...`) will be reversed into a `10` pattern (e.g., `...10...`).
For example, in `P = 1010`:
The pair `S[3]S[4]` is `01`.
After reversing `P` (`1010` becomes `0101`), the string becomes `00010111`.
In this new string, the characters that were originally at `S[3]S[4]` (the `01` pair) are now at `S[3]S[4]` but in reversed order, forming `10`.
This newly formed `10` pattern (or any `10` pattern that was already present and remained `10` after reversal) represents an "inner" inversion that still needs to be resolved. Each such `10` pattern will require an *additional* operation to fix.

Therefore, the minimum number of operations is:
1 (for the initial reversal of $S[\text{first\_one\_idx} \dots \text{last\_zero\_idx}]$)
+ (number of `01` patterns within $S[\text{first\_one\_idx} \dots \text{last\_zero\_idx}]$)

Let's re-verify with `S = 00101011`:
`first_one_idx = 2`, `last_zero_idx = 5`. Segment $P = `1010`.
Count `01` patterns within $P$:
*   `S[2]S[3]` is `10` (not `01`)
*   `S[3]S[4]` is `01` (count = 1)
*   `S[4]S[5]` is `10` (not `01`)
Total `01` patterns = 1.
Minimum operations = $1 + 1 = 2$.

Let's trace this:
1. `S = 00101011`. Reverse `S[2...5]` (`1010` -> `0101`).
   `S` becomes `00010111`. (1 operation)
2. Now, `first_one_idx = 3`, `last_zero_idx = 4`. Segment $P' = `10`.
   Count `01` patterns within $P'$: None.
   Minimum operations for this step = $1 + 0 = 1$.
   Reverse `S[3...4]` (`10` -> `01`).
   `S` becomes `00001111`. (1 operation)
The string is now sorted. Total operations = $1 + 1 = 2$. This matches our formula.

This logic holds because each `01` pattern within the problematic segment effectively "flips" to a `10` pattern after the first reversal, requiring another operation to sort it.

## Complexity Analysis

*   **Time Complexity**: $O(N)$
    *   Finding `first_one_idx` involves iterating through the string once, taking $O(N)$ time.
    *   Finding `last_zero_idx` involves iterating through the string once (in reverse), taking $O(N)$ time.
    *   Counting `01` patterns involves iterating through a substring of length at most $N$, taking $O(N)$ time.
    *   Since these operations are sequential, the total time complexity for a single test case is $O(N)$.
    *   Given $T$ test cases, the total time complexity is $O(T \cdot N)$.

*   **Space Complexity**: $O(N)$
    *   Storing the input string $S$ requires $O(N)$ space.
    *   A few integer variables are used (`n`, `first_one_idx`, `last_zero_idx`, `count_01_patterns`, loop counter `i`), which take $O(1)$ additional space.
    *   Therefore, the total space complexity is $O(N)$.

## Solution Code

```cpp
#include <iostream> // Required for std::cin, std::cout
#include <string>   // Required for std::string
#include <vector>   // Not strictly needed for this problem, but often useful
#include <algorithm> // Not strictly needed for this problem, but often useful (e.g. std::min, std::max)

// Function to solve a single test case
void solve() {
    int n;
    std::cin >> n; // Read the length of the string
    std::string s;
    std::cin >> s; // Read the binary string

    // Find the index of the first '1' in the string
    int first_one_idx = -1;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') {
            first_one_idx = i;
            break; // Found the first '1', no need to search further
        }
    }

    // Find the index of the last '0' in the string
    int last_zero_idx = -1;
    for (int i = n - 1; i >= 0; --i) {
        if (s[i] == '0') {
            last_zero_idx = i;
            break; // Found the last '0', no need to search further
        }
    }

    // Case 1: The string is already sorted.
    // This occurs if:
    // a) There are no '1's (string is "00...0"). `first_one_idx` will be -1.
    // b) There are no '0's (string is "11...1"). `last_zero_idx` will be -1.
    // c) All '0's appear before all '1's. This means the first '1' appears after the last '0'.
    //    So, `first_one_idx > last_zero_idx`.
    // In any of these scenarios, 0 operations are needed.
    if (first_one_idx == -1 || last_zero_idx == -1 || first_one_idx > last_zero_idx) {
        std::cout << 0 << "\n";
        return; // Move to the next test case
    }

    // Case 2: The string is unsorted. We need at least 1 operation.
    // At this point, we know `first_one_idx < last_zero_idx`.
    // This means there is at least one '1' that appears before at least one '0'.
    // The "problematic" segment of the string is `S[first_one_idx ... last_zero_idx]`.
    // This segment starts with a '1' and ends with a '0'.

    // We need to count the number of '01' patterns within the problematic segment.
    // Each '01' pattern signifies an additional "inversion" that needs to be resolved.
    // The first operation resolves the outermost '1...0' inversion.
    // Each subsequent '01' pattern requires an additional operation.
    int count_01_patterns = 0;
    // Iterate through the problematic segment S[first_one_idx ... last_zero_idx-1]
    // to check for any '01' substring.
    // The loop goes up to `last_zero_idx - 1` because we are checking `s[i]` and `s[i+1]`.
    for (int i = first_one_idx; i < last_zero_idx; ++i) {
        if (s[i] == '0' && s[i+1] == '1') {
            count_01_patterns++;
        }
    }

    // The minimum number of operations is 1 (for the initial '1...0' inversion)
    // plus the number of '01' patterns found within that '1...0' segment.
    std::cout << 1 + count_01_patterns << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common competitive programming optimization.
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