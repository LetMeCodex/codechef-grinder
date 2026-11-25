# [Make Them Equal (MTE)](https://www.codechef.com/problems/MTE)
- **Difficulty Rating**: 1348
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to find the minimum number of operations required to make all elements in an array have the same parity. We are given an array $A$ of $N$ integers. In one operation, we can choose any two elements $A_i$ and $A_j$ from the array, remove them, and insert their sum $(A_i + A_j)$ back into the array. This reduces the array size by one. We continue until only one element remains, or until all elements have the same parity. The goal is to reach a state where all elements have the same parity using the minimum number of operations.

## Intuition & Mathematical Observation

Let's analyze how the parity of numbers changes with the given operation:
1.  **Odd + Odd = Even**: If we sum two odd numbers, the result is an even number.
2.  **Odd + Even = Odd**: If we sum an odd and an even number, the result is an odd number.
3.  **Even + Even = Even**: If we sum two even numbers, the result is an even number.

Let's track the counts of odd and even numbers in the array: `count_odd` and `count_even`.

*   **Operation 1 (Odd + Odd -> Even):**
    *   `count_odd` decreases by 2.
    *   `count_even` increases by 1 (the new sum is even).
*   **Operation 2 (Odd + Even -> Odd):**
    *   `count_odd` remains unchanged (one odd is removed, one odd is added).
    *   `count_even` decreases by 1.
*   **Operation 3 (Even + Even -> Even):**
    *   `count_odd` remains unchanged.
    *   `count_even` decreases by 1.

**Key Observation: The parity of `count_odd` is an invariant.**

Notice that in all three operations:
*   If `count_odd` changes, it decreases by 2 (from `odd + odd`). `count_odd - 2` has the same parity as `count_odd`.
*   If `count_odd` does not change (from `odd + even` or `even + even`), its parity also remains the same.

Therefore, if `count_odd` is initially odd, it will always remain odd. If `count_odd` is initially even, it will always remain even. This is a crucial insight.

Our goal is to make all elements have the same parity. This means we want to reach a state where either:
*   All numbers are even (`count_odd = 0`).
*   All numbers are odd (`count_even = 0`).

Let's consider the cases based on the initial counts:

**Case 1: All elements already have the same parity.**
If `count_odd == 0` (all numbers are even) or `count_even == 0` (all numbers are odd) initially, then 0 operations are needed.

**Case 2: `count_odd` is initially odd.**
*   Since the parity of `count_odd` is an invariant, and `count_odd` is initially odd, it can never become 0 (because 0 is an even number).
*   This means we can never make all elements even.
*   Therefore, our only option is to make all elements odd. This requires reaching a state where `count_even = 0`.
*   To eliminate even numbers, we must use the operation `odd + even -> odd`. Each such operation reduces `count_even` by 1.
*   We need to perform `count_even` operations to eliminate all even numbers.
*   This is always possible because `count_odd` is odd, meaning `count_odd >= 1`, so there's always at least one odd number available to pair with an even number.
*   **Result for this case: `count_even` operations.**

**Case 3: `count_odd` is initially even.**
*   Since the parity of `count_odd` is an invariant, and `count_odd` is initially even, it *can* potentially become 0 (all even).
*   We can also potentially make all elements odd (`count_even = 0`).
*   We need to find the minimum operations for these two possibilities:
    *   **Option A: Make all elements even (target `count_odd = 0`).**
        *   To eliminate odd numbers, we must use the operation `odd + odd -> even`.
        *   Each such operation reduces `count_odd` by 2.
        *   Since `count_odd` is even, we need `count_odd / 2` operations to eliminate all odd numbers.
    *   **Option B: Make all elements odd (target `count_even = 0`).**
        *   To eliminate even numbers, we must use the operation `odd + even -> odd`.
        *   Each such operation reduces `count_even` by 1.
        *   We need `count_even` operations to eliminate all even numbers.
*   **Result for this case: `min(count_odd / 2, count_even)` operations.**

The solution involves first counting the initial `count_odd` and `count_even`, and then applying the logic derived from these cases.

## Complexity Analysis

*   **Time Complexity**: $O(N)$ per test case. We iterate through the input array once to count the number of odd and even elements. All subsequent calculations are constant time operations. If there are $T$ test cases, the total time complexity is $O(T \cdot N)$.
*   **Space Complexity**: $O(1)$. We only use a few integer variables to store `n`, `count_odd`, `count_even`, and the current element `a`. This is constant auxiliary space.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries

// Use the standard namespace to avoid prefixing std::
using namespace std;

// Function to solve a single test case
void solve() {
    int n;
    cin >> n; // Read the size of the array

    int count_odd = 0;  // Counter for odd numbers
    int count_even = 0; // Counter for even numbers

    // Iterate through the array elements to count parities
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a; // Read an element
        if (a % 2 == 0) {
            count_even++; // Increment even count if element is even
        } else {
            count_odd++;  // Increment odd count if element is odd
        }
    }

    // If all elements are already of the same parity, 0 operations are needed.
    // This means either there are no odd numbers (all even) or no even numbers (all odd).
    if (count_odd == 0 || count_even == 0) {
        cout << 0 << "\n";
    } else {
        // The parity of the count of odd numbers (count_odd) is an invariant.
        // This means if count_odd is initially odd, it will always remain odd.
        // If count_odd is initially even, it will always remain even.

        // Case 1: Initial count_odd is odd.
        // Since count_odd must always be odd, we can never reach a state where count_odd = 0 (which is an even number).
        // Therefore, we cannot make all elements even.
        // We must make all elements odd. This means we need to eliminate all even numbers.
        // The only operation that reduces the count of even numbers is (even + odd -> odd).
        // Each such operation reduces count_even by 1.
        // We need to perform 'count_even' such operations to eliminate all even numbers.
        // This is always possible because count_odd is odd, meaning count_odd >= 1, so there's always an odd number to pair with an even number.
        if (count_odd % 2 == 1) { // count_odd is odd
            cout << count_even << "\n";
        } 
        // Case 2: Initial count_odd is even.
        // Since count_odd must always be even, we can potentially reach count_odd = 0 (all even).
        // We can also potentially reach count_even = 0 (all odd).
        // We need to find the minimum operations for these two possibilities.
        else { // count_odd is even
            // Option A: Make all elements even (target count_odd = 0).
            // To do this, we pair up odd numbers: (odd + odd -> even).
            // Each such operation reduces count_odd by 2.
            // Since count_odd is even, we can form count_odd / 2 pairs.
            // This takes count_odd / 2 operations.
            int ops_to_all_even = count_odd / 2;

            // Option B: Make all elements odd (target count_even = 0).
            // To do this, we pair up even and odd numbers: (even + odd -> odd).
            // Each such operation reduces count_even by 1.
            // We need to perform 'count_even' such operations to eliminate all even numbers.
            int ops_to_all_odd = count_even;
            
            // The minimum operations is the smaller of these two options.
            cout << min(ops_to_all_even, ops_to_all_odd) << "\n";
        }
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cout from flushing before cin reads input.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t; // Read the number of test cases
    while (t--) {
        solve(); // Solve each test case
    }

    return 0;
}
```