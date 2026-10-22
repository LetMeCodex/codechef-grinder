# [Clothing Store (XLSL)](https://www.codechef.com/problems/XLSL)

- **Difficulty Rating**: 947
- **Solved in**: 3 attempt(s)

## Problem Summary

The problem asks us to maximize the number of happy customers in a clothing store. We are given the counts of available shirts in three sizes: Small (S), Large (L), and Extra Large (XL). We are also given the counts of people who desire shirts of these three sizes.

The rules for wearing shirts are:
1. A person who wants a Small (S) shirt can wear an S, L, or XL shirt.
2. A person who wants a Large (L) shirt can wear an L or XL shirt.
3. A person who wants an Extra Large (XL) shirt can only wear an XL shirt.

Our goal is to find the maximum total number of people who can be satisfied.

## Intuition & Mathematical Observation

This problem can be solved using a greedy approach. The core idea is to prioritize satisfying people with shirts that have the least flexibility, or by using shirts that are least flexible for their exact match.

Let's analyze the flexibility of shirts and the restrictiveness of people's needs:

**Shirt Flexibility (from least to most flexible):**
*   **Small (S) shirts:** Can only fit S-sized people. (Least flexible)
*   **Large (L) shirts:** Can fit L-sized or S-sized people.
*   **Extra Large (XL) shirts:** Can fit XL-sized, L-sized, or S-sized people. (Most flexible)

**People's Needs (from most to least restrictive):**
*   **XL-sized people:** Can *only* wear XL shirts. (Most restrictive)
*   **L-sized people:** Can wear L or XL shirts.
*   **S-sized people:** Can wear S, L, or XL shirts. (Least restrictive)

Based on these observations, an optimal greedy strategy emerges:

1.  **Satisfy Exact Matches First:**
    *   **XL people with XL shirts:** People who want XL shirts *must* get an XL shirt. So, we should satisfy as many XL people as possible using available XL shirts first. This is the most restrictive demand.
    *   **L people with L shirts:** People who want L shirts can take an L or XL shirt. If we use an L shirt for an L person, we save a more flexible XL shirt for potentially an XL person (if any remain) or another L person, or even an S person. This is generally optimal because L shirts are less flexible than XL shirts.
    *   **S people with S shirts:** People who want S shirts can take S, L, or XL shirts. S shirts are the least flexible and can *only* fit S people. Therefore, using S shirts for S people is always optimal as it doesn't prevent any other person from being satisfied.

    This first step ensures that shirts are used for their exact size preference where possible, prioritizing less flexible shirts and more restrictive people.

2.  **Satisfy Remaining People with Conversions (Larger to Smaller):**
    After exact matches, we might have remaining shirts (L and XL) and remaining people (S and L). Now, we use the more flexible shirts to satisfy the remaining people who need smaller sizes. The order of these conversions also matters:
    *   **XL shirts for L people:** Use any remaining XL shirts to satisfy L-sized people who still need shirts. This is better than using them for S-sized people because L-sized people are more restrictive than S-sized people (L people cannot wear S shirts, but S people can wear L shirts).
    *   **XL shirts for S people:** After satisfying all possible XL and L people with XL shirts, any remaining XL shirts can only be used for S-sized people.
    *   **L shirts for S people:** Finally, use any remaining L shirts to satisfy S-sized people. At this point, all L-people who could be satisfied by L shirts (or XL shirts) have been.

This greedy strategy works because it always makes the locally optimal choice that leads to a globally optimal solution. By using less flexible shirts for their exact match first, and then using more flexible shirts for the largest possible remaining size, we ensure that no person is left unsatisfied unnecessarily.

## Complexity Analysis

*   **Time Complexity**: The solution involves a fixed number of `std::min` operations and basic arithmetic operations per test case. These operations take constant time. Since the number of operations is constant and does not depend on the input values (other than the number of test cases), the time complexity for each test case is $O(1)$. If there are $T$ test cases, the total time complexity is $O(T)$.

*   **Space Complexity**: The solution uses a fixed number of variables (`x, y, z, a, b, c, happy_people`) to store shirt counts, people counts, and the total happy people. This amount of memory does not depend on the input values. Therefore, the space complexity is $O(1)$ (constant space) per test case.

## Solution Code

```cpp
#include <iostream>
#include <algorithm> // Required for std::min

void solve() {
    long long x, y, z, a, b, c;
    // Read the six integers for the current test case
    std::cin >> x >> y >> z >> a >> b >> c;

    long long happy_people = 0;

    // Strategy:
    // 1. Satisfy direct matches first.
    // 2. Then, use conversions from larger shirts to smaller ones.
    //    Prioritize using more flexible shirts (XL, then L) for remaining needs,
    //    and for conversions, prioritize larger target sizes (L before S).

    // Step 1: Satisfy people with shirts of their exact desired size.

    // Satisfy 'A' people (who want Small) with 'X' Small shirts.
    // S shirts can only fit S people, so use them here first.
    long long s_match = std::min(x, a);
    happy_people += s_match;
    x -= s_match; // Remaining Small shirts
    a -= s_match; // Remaining people who want Small

    // Satisfy 'B' people (who want Large) with 'Y' Large shirts.
    // L shirts can fit L or S. Using them for L people here is optimal
    // as it saves more flexible XL shirts for XL/L/S people.
    long long l_match = std::min(y, b);
    happy_people += l_match;
    y -= l_match; // Remaining Large shirts
    b -= l_match; // Remaining people who want Large

    // Satisfy 'C' people (who want Extra Large) with 'Z' Extra Large shirts.
    // XL people can ONLY wear XL shirts, so this is critical.
    long long xl_match = std::min(z, c);
    happy_people += xl_match;
    z -= xl_match; // Remaining Extra Large shirts
    c -= xl_match; // Remaining people who want Extra Large (should be 0 here)

    // Step 2: Use conversions to satisfy remaining people.
    // At this point:
    // - 'a' people want Small.
    // - 'b' people want Large.
    // - 'c' people want Extra Large (should be 0).
    // - 'x' Small shirts remain (can only fit 'a' people).
    // - 'y' Large shirts remain (can fit 'a' people).
    // - 'z' Extra Large shirts remain (can fit 'a' or 'b' people).

    // Convert remaining XL shirts to L for remaining 'B' people.
    // Prioritize L people over S people for XL shirts, as L people are more restrictive.
    long long xl_to_l = std::min(z, b);
    happy_people += xl_to_l;
    z -= xl_to_l; // XL shirts used for L
    b -= xl_to_l; // Remaining people who want Large

    // Convert remaining XL shirts to S for remaining 'A' people.
    // After satisfying L people, any remaining XL shirts go to S people.
    long long xl_to_s = std::min(z, a);
    happy_people += xl_to_s;
    z -= xl_to_s; // XL shirts used for S
    a -= xl_to_s; // Remaining people who want Small

    // Convert remaining L shirts to S for remaining 'A' people.
    // After satisfying L people with L/XL shirts, any remaining L shirts go to S people.
    long long l_to_s = std::min(y, a);
    happy_people += l_to_s;
    y -= l_to_s; // L shirts used for S
    a -= l_to_s; // Remaining people who want Small

    // Output the maximum number of happy people for this test case.
    std::cout << happy_people << "\n"; // Use '\n' for faster output than std::endl
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is crucial for problems with many test cases or large I/O.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t; // Read the number of test cases
    while (t--) {
        solve(); // Process each test case
    }

    return 0;
}
```