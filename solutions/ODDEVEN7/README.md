# Odd Even (ODDEVEN7)
- **Difficulty Rating**: 877
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an array of $N$ integers, we want to find the maximum size of a sub-sequence such that the elements alternate between odd and even. That is, if the sub-sequence is $a_1, a_2, \dots, a_k$, then $a_i$ and $a_{i+1}$ must have different parity for all $1 \le i < k$.

## Intuition & Mathematical Observation
The core idea behind forming an alternating sub-sequence is to pair up odd and even numbers. To maximize the length of such a sub-sequence, we should try to use as many numbers as possible.

Consider the counts of odd and even numbers in the given array. Let `count_odd` be the number of odd integers and `count_even` be the number of even integers.

1.  **Perfect Alternation**: If we have `count_odd` odd numbers and `count_even` even numbers, we can form an alternating sequence by picking numbers one by one. For example, if we have 3 odd numbers (O) and 3 even numbers (E), we can form `O E O E O E` or `E O E O E O`. The maximum length we can achieve in this scenario is limited by the minimum of the two counts. Specifically, we can form `min(count_odd, count_even)` pairs of (odd, even) or (even, odd). Each pair contributes 2 elements to the alternating sequence. So, the initial maximum length is $2 \times \min(\text{count\_odd, count\_even})$.

2.  **Unequal Counts**: What happens if `count_odd` is not equal to `count_even`? Suppose `count_odd > count_even`. We can form `count_even` pairs of (odd, even) or (even, odd), using up all `count_even` even numbers and `count_even` odd numbers. This gives us a sequence of length $2 \times \text{count\_even}$. We are left with `count_odd - count_even` odd numbers. Since we have already used all even numbers, we cannot extend the alternating sequence by adding another even number. However, we can add one more odd number to the end of our current alternating sequence. For example, if we had `O E O E` and we have one more `O` left, we can form `O E O E O`. This adds one more element to our sequence. The same logic applies if `count_even > count_odd`.

Therefore, if the counts are unequal, we can add one extra element from the parity that has more occurrences. This means if `count_odd != count_even`, we can add 1 to the length obtained from pairing.

Combining these observations, the maximum size of the alternating sub-sequence is:
-   $2 \times \min(\text{count\_odd, count\_even})$ if `count_odd == count_even`.
-   $2 \times \min(\text{count\_odd, count\_even}) + 1$ if `count_odd != count_even`.

This can be concisely expressed as $2 \times \min(\text{count\_odd, count\_even}) + (\text{count\_odd} \neq \text{count\_even} ? 1 : 0)$.

## Complexity Analysis
-   **Time Complexity**: $O(N)$
    The code iterates through the input array once to count the number of odd and even elements. This takes $O(N)$ time, where $N$ is the number of elements in the array. The subsequent calculations are constant time. Therefore, the overall time complexity per test case is $O(N)$. If there are $T$ test cases, the total time complexity is $O(T \times N)$.

-   **Space Complexity**: $O(1)$
    The solution uses a few integer variables (`count_odd`, `count_even`, `result`, `N`, `T`, `A_i`) to store counts and intermediate values. The amount of memory used does not depend on the input size $N$. Thus, the space complexity is $O(1)$ per test case.

## Solution Code
```cpp
#include <bits/stdc++.h> // Includes all standard libraries, as requested

// Function to solve a single test case
void solve() {
    int N;
    std::cin >> N; // Read the size of the array

    int count_odd = 0;
    int count_even = 0;

    // Iterate through the array elements and count odd/even numbers
    for (int i = 0; i < N; ++i) {
        int A_i;
        std::cin >> A_i; // Read each element
        if (A_i % 2 == 0) {
            count_even++;
        } else {
            count_odd++;
        }
    }

    // Calculate the maximum size of a subset that can form a good array.
    // We can always pair up min(count_odd, count_even) odd numbers with
    // min(count_odd, count_even) even numbers to form an alternating sequence.
    // This gives 2 * min(count_odd, count_even) elements.
    int result = 2 * std::min(count_odd, count_even);

    // If the total counts of odd and even numbers are not equal, it means one parity
    // has more elements than the other. We can pick one additional element from the
    // more frequent parity to extend the alternating sequence by 1. This maintains
    // the |odd_count - even_count| <= 1 property.
    if (count_odd != count_even) {
        result += 1;
    }

    std::cout << result << "\n"; // Output the maximum size
}

int main() {
    // Optimize C++ standard streams for competitive programming
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T; // Read the number of test cases
    while (T--) {
        solve(); // Solve each test case
    }

    return 0;
}
```