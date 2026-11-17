# [Transfusion Chain (TRANCHAIN)](https://www.codechef.com/problems/TRANCHAIN)
- **Difficulty Rating**: 1214
- **Solved in**: 2 attempt(s)

## Problem Summary

The problem asks us to find the maximum possible length of a "transfusion chain" given `N` people, each with one of four blood types: A, B, O, or AB. A transfusion chain is a sequence of people $P_1 \to P_2 \to \dots \to P_k$ such that $P_i$ can donate blood to $P_{i+1}$. Each person can be part of the chain at most once. We need to output the maximum possible value of $k$.

The standard ABO blood type compatibility rules are:
*   **O**: Can donate to A, B, AB, O (Universal Donor)
*   **A**: Can donate to A, AB
*   **B**: Can donate to B, AB
*   **AB**: Can donate to AB (Universal Recipient within ABO system)

## Intuition & Mathematical Observation

To maximize the length of a single transfusion chain, we need to arrange as many people as possible in a compatible sequence. Let's analyze the donation capabilities of each blood type:

1.  **Type O (Universal Donors)**: People with type O blood can donate to anyone (A, B, AB, O). This makes them extremely flexible. They can form a chain among themselves, and then donate to any other blood type. Therefore, all `count_O` individuals can be included in the chain.

2.  **Type AB (Universal Recipients)**: People with type AB blood can receive from anyone (A, B, O, AB). However, they can *only* donate to other AB types. This means that if an AB type person is part of the chain, they can receive blood from any preceding person, but can only pass it on to another AB type. Effectively, all `count_AB` individuals can be appended at the end of any chain, forming a sub-chain among themselves.

3.  **Type A and Type B**: This is where the crucial observation lies.
    *   Type A can donate to A and AB.
    *   Type B can donate to B and AB.
    The key incompatibility is that **Type A cannot donate to Type B, and Type B cannot donate to Type A**.

    Consider forming a single, continuous chain.
    *   All `count_O` people can be placed at the beginning or middle of the chain, as they can donate to anyone.
    *   All `count_AB` people can be placed at the end of the chain, as they can receive from anyone and only donate to other ABs.

    The challenge is how to incorporate Type A and Type B individuals. Since A cannot donate to B and vice-versa, we cannot have a sequence like `... -> A -> B -> ...` or `... -> B -> A -> ...` in our single chain. This implies that we must choose *either* to include all Type A individuals *or* all Type B individuals to extend the chain from the O types towards the AB types. We cannot include both groups in a way that allows them to directly donate to each other within the same chain.

    For example, a chain could be:
    `O -> O -> ... -> O -> A -> A -> ... -> A -> AB -> AB -> ... -> AB`
    OR
    `O -> O -> ... -> O -> B -> B -> ... -> B -> AB -> AB -> ... -> AB`

    To maximize the chain length, we should pick the larger group between Type A and Type B. If we have `count_A` people of type A and `count_B` people of type B, we can include `max(count_A, count_B)` people from these two groups.

Combining these observations, the maximum chain length will be the sum of:
*   All Type O people (`count_O`)
*   The maximum of Type A or Type B people (`max(count_A, count_B)`)
*   All Type AB people (`count_AB`)

Thus, the formula for the maximum chain length is:
`count_O + max(count_A, count_B) + count_AB`

## Complexity Analysis

*   **Time Complexity**:
    *   The program iterates `N` times to read the blood types and update their respective counts. Inside the loop, `std::cin >> blood_type_arr` reads a string of maximum length 2, and `strcmp` performs a comparison on strings of maximum length 2. Both operations take constant time, $O(1)$. Therefore, the loop runs in $O(N)$ time.
    *   After the loop, calculating `std::max` and performing additions takes $O(1)$ time.
    *   Since there are `T` test cases, the total time complexity is $O(T \cdot N)$.
*   **Space Complexity**:
    *   We use a few integer variables (`count_A`, `count_B`, `count_O`, `count_AB`, `n`, `t`, `i`) and a fixed-size character array `blood_type_arr[3]` (to store "A", "B", "O", or "AB" plus null terminator). All these variables occupy a constant amount of memory, regardless of the input size `N`.
    *   Therefore, the space complexity is $O(1)$.

## Solution Code

```cpp
#include <iostream>
#include <algorithm> // Required for std::max
#include <cstring>   // Required for strcmp

void solve() {
    int n;
    std::cin >> n;
    int count_A = 0;
    int count_B = 0;
    int count_O = 0;
    int count_AB = 0;

    // Use char array for faster string input and comparison
    char blood_type_arr[3]; // Max "AB" + null terminator

    for (int i = 0; i < n; ++i) {
        std::cin >> blood_type_arr; // Reads into char array
        if (strcmp(blood_type_arr, "A") == 0) {
            count_A++;
        } else if (strcmp(blood_type_arr, "B") == 0) {
            count_B++;
        } else if (strcmp(blood_type_arr, "O") == 0) {
            count_O++;
        } else if (strcmp(blood_type_arr, "AB") == 0) {
            count_AB++;
        }
    }

    // The maximum number of people in a chain is formed by:
    // 1. All 'O' type people (universal donors).
    // 2. The maximum of 'A' people or 'B' people, as 'A' and 'B' cannot donate to each other
    //    and thus cannot be in the same direct donation path in a single chain.
    // 3. All 'AB' type people (universal recipients, but can only donate to 'AB').
    int max_chain_length = count_O + std::max(count_A, count_B) + count_AB;
    
    std::cout << max_chain_length << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t; // Read the number of test cases.
    while (t--) {
        solve(); // Solve each test case.
    }

    return 0;
}
```