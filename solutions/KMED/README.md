# [K Median (KMED)](https://www.codechef.com/problems/KMED)
- **Difficulty Rating**: 1110
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an array $A$ of $N$ integers and an integer $K$, we need to remove exactly $K$ elements from the array such that the median of the remaining $N-K$ elements is minimized. We need to output all possible values of this minimum median.

The median of a sorted array of length $M$ is the element at position $\lfloor \frac{M+1}{2} \rfloor$ (1-indexed).

## Intuition & Mathematical Observation

Let the original sorted array be $a_1, a_2, \dots, a_N$.
After removing $K$ elements, we are left with $N-K$ elements. Let this new array be $b_1, b_2, \dots, b_{N-K}$ in sorted order.
The median of this new array is $b_{\lfloor \frac{(N-K)+1}{2} \rfloor}$.
We want to minimize this median value.

Let $M = N-K$ be the number of elements remaining.
The median position is $P = \lfloor \frac{M+1}{2} \rfloor$.

Consider an element $a_i$ from the original sorted array. Can $a_i$ be the median of the remaining $N-K$ elements?
If $a_i$ is the median, it must be the $P$-th smallest element among the $N-K$ remaining elements.
This means that among the $N-K$ elements, there must be exactly $P-1$ elements smaller than $a_i$ and $M-P$ elements larger than $a_i$.

Let's analyze the conditions for $a_i$ to be a possible median.
The original sorted array has $i-1$ elements strictly smaller than $a_i$ (i.e., $a_1, \dots, a_{i-1}$) and $N-i$ elements strictly larger than $a_i$ (i.e., $a_{i+1}, \dots, a_N$).

For $a_i$ to be the median of the remaining $N-K$ elements:
1.  We need to select exactly $P-1$ elements from the $i-1$ elements smaller than $a_i$.
    This is possible only if we have at least $P-1$ elements smaller than $a_i$ available, i.e., $i-1 \ge P-1$, which simplifies to $i \ge P$.
    The number of smaller elements we *must* delete is $(i-1) - (P-1) = i-P$.
    The number of smaller elements we *can* delete is $i-1$.
    The number of smaller elements we *can* delete must be at least $i-P$.
    The total number of elements we can delete is $K$.
    The number of smaller elements we delete, $d_{small}$, must satisfy $0 \le d_{small} \le i-1$.
    To have $a_i$ as the median, we need to keep $P-1$ smaller elements. This means we must delete $(i-1) - (P-1) = i-P$ elements from the smaller group.
    So, $d_{small} = i-P$.
    This requires $i-P \ge 0 \implies i \ge P$.

2.  We need to select exactly $M-P$ elements from the $N-i$ elements larger than $a_i$.
    This is possible only if we have at least $M-P$ elements larger than $a_i$ available, i.e., $N-i \ge M-P$.
    $N-i \ge (N-K)-P$
    $N-i \ge N-K-P$
    $-i \ge -K-P$
    $i \le K+P$.
    The number of larger elements we *must* delete is $(N-i) - (M-P) = N-i - (N-K-P) = N-i-N+K+P = K-i+P$.
    So, $d_{large} = K-i+P$.
    This requires $d_{large} \ge 0 \implies K-i+P \ge 0 \implies i \le K+P$.

The total number of elements deleted is $d_{small} + d_{large}$.
$d_{small} = (i-1) - (P-1) = i-P$ (number of smaller elements we *must* delete to have $P-1$ remaining).
$d_{large} = (N-i) - (M-P) = (N-i) - (N-K-P) = K-i+P$ (number of larger elements we *must* delete to have $M-P$ remaining).

The total number of deletions must be exactly $K$:
$d_{small} + d_{large} = (i-P) + (K-i+P) = K$.
This equation is always satisfied, meaning if we can satisfy the conditions for $d_{small}$ and $d_{large}$ to be non-negative, then $a_i$ can be a median.

The conditions are:
-   We must be able to select $P-1$ elements from the $i-1$ elements smaller than $a_i$. This means we can delete at most $(i-1) - (P-1) = i-P$ elements from the smaller group. The number of elements we *can* delete from the smaller group is $i-1$. So we need to delete $i-P$ elements from the smaller group. This is possible if $i-P \ge 0$, which means $i \ge P$.
-   We must be able to select $M-P$ elements from the $N-i$ elements larger than $a_i$. This means we can delete at most $(N-i) - (M-P) = K-i+P$ elements from the larger group. The number of elements we *can* delete from the larger group is $N-i$. So we need to delete $K-i+P$ elements from the larger group. This is possible if $K-i+P \ge 0$, which means $i \le K+P$.

So, an element $a_i$ (using 0-based indexing for the sorted array $a$) can be the median of the remaining $N-K$ elements if and only if:
Let $M = N-K$ be the number of remaining elements.
Let $P = \lfloor \frac{M+1}{2} \rfloor$ be the 1-indexed median position.
The 0-indexed median position is $P_{0based} = P-1$.

For $a_i$ (0-indexed) to be the median:
-   Number of elements smaller than $a_i$ in the original array is $i$.
-   Number of elements larger than $a_i$ in the original array is $N-1-i$.

We need to keep $P_{0based}$ elements smaller than $a_i$ and $M-1-P_{0based}$ elements larger than $a_i$.
Total elements to keep (excluding $a_i$) is $(P_{0based}) + (M-1-P_{0based}) = M-1$.

Number of smaller elements to keep: $P_{0based}$.
Number of smaller elements available: $i$.
This is possible if $i \ge P_{0based}$.
Number of smaller elements we *can* delete: $i$.
Number of smaller elements we *must* delete: $i - P_{0based}$.

Number of larger elements to keep: $M-1-P_{0based}$.
Number of larger elements available: $N-1-i$.
This is possible if $N-1-i \ge M-1-P_{0based}$.
$N-1-i \ge (N-K)-1 - (P-1)$
$N-1-i \ge N-K-1-P+1$
$N-1-i \ge N-K-P$
$-1-i \ge -K-P$
$K+P-1 \ge i$
$i \le K+P-1$.

Number of larger elements we *can* delete: $N-1-i$.
Number of larger elements we *must* delete: $(N-1-i) - (M-1-P_{0based}) = (N-1-i) - (N-K-1-P+1) = N-1-i - (N-K-P) = N-1-i-N+K+P = K-i+P-1$.

The total number of elements to delete is $K$.
The number of smaller elements we *can* delete is $i$.
The number of larger elements we *can* delete is $N-1-i$.

For $a_i$ to be a possible median, we need to be able to delete $K$ elements such that $a_i$ becomes the $P_{0based}$-th element.
This means we need to delete $i - P_{0based}$ elements from the smaller group and $(N-1-i) - (M-1-P_{0based})$ elements from the larger group.
The total number of deletions is $(i - P_{0based}) + ((N-1-i) - (M-1-P_{0based})) = i - P_{0based} + N-1-i - (N-K-1-P+1) = i - P_{0based} + N-1-i - (N-K-P) = i - P_{0based} + N-1-i - N+K+P = K - P_{0based} + P = K$.

The conditions for $a_i$ (0-indexed) to be a possible median are:
1.  We must have enough smaller elements to keep $P_{0based}$ of them: $i \ge P_{0based}$.
2.  We must have enough larger elements to keep $M-1-P_{0based}$ of them: $N-1-i \ge M-1-P_{0based}$.
    $N-1-i \ge (N-K)-1 - (P-1)$
    $N-1-i \ge N-K-1-P+1$
    $N-1-i \ge N-K-P$
    $-1-i \ge -K-P$
    $K+P-1 \ge i$
    $i \le K+P-1$.

So, for a 0-indexed element $a_i$ in the sorted array, it can be a median if:
$P_{0based} \le i \le K + P_{0based}$

Where:
$M = N-K$
$P = \lfloor \frac{M+1}{2} \rfloor$ (1-indexed median position)
$P_{0based} = P-1$ (0-indexed median position)

Let's re-calculate $P_{0based}$ carefully.
$M = N-K$.
Median position (1-indexed) is $\lceil M/2 \rceil$.
If $M$ is odd, $M=2q+1$, median is at $q+1$. $\lfloor \frac{(2q+1)+1}{2} \rfloor = \lfloor \frac{2q+2}{2} \rfloor = q+1$.
If $M$ is even, $M=2q$, median is at $q$. $\lfloor \frac{2q+1}{2} \rfloor = \lfloor q+0.5 \rfloor = q$.
So $P = \lfloor \frac{M+1}{2} \rfloor$ is correct for 1-indexed median.
$P_{0based} = P-1 = \lfloor \frac{M+1}{2} \rfloor - 1$.

Let's use the example: $N=5, K=2$. $M=3$. $P = \lfloor \frac{3+1}{2} \rfloor = 2$. $P_{0based} = 1$.
The conditions for $a_i$ (0-indexed) to be a median are:
$1 \le i \le 2 + 1$
$1 \le i \le 3$.
So $a_1, a_2, a_3$ are possible medians.

Let's verify this.
Array: $a_0, a_1, a_2, a_3, a_4$. $N=5, K=2$. $M=3$. Median position is 2nd element.
If $a_1$ is median:
We need 1 element smaller than $a_1$ and 1 element larger than $a_1$.
Original smaller than $a_1$: $a_0$ (1 element).
Original larger than $a_1$: $a_2, a_3, a_4$ (3 elements).
To make $a_1$ median, we need to keep 1 smaller and 1 larger.
We must delete $1-1=0$ from smaller.
We must delete $3-1=2$ from larger.
Total deletions = $0+2=2=K$. This is possible. So $a_1$ is a possible median.

If $a_2$ is median:
We need 1 element smaller than $a_2$ and 1 element larger than $a_2$.
Original smaller than $a_2$: $a_0, a_1$ (2 elements).
Original larger than $a_2$: $a_3, a_4$ (2 elements).
To make $a_2$ median, we need to keep 1 smaller and 1 larger.
We must delete $2-1=1$ from smaller.
We must delete $2-1=1$ from larger.
Total deletions = $1+1=2=K$. This is possible. So $a_2$ is a possible median.

If $a_3$ is median:
We need 1 element smaller than $a_3$ and 1 element larger than $a_3$.
Original smaller than $a_3$: $a_0, a_1, a_2$ (3 elements).
Original larger than $a_3$: $a_4$ (1 element).
To make $a_3$ median, we need to keep 1 smaller and 1 larger.
We must delete $3-1=2$ from smaller.
We must delete $1-1=0$ from larger.
Total deletions = $2+0=2=K$. This is possible. So $a_3$ is a possible median.

The indices $i$ for which $a_i$ can be a median are $P_{0based}, P_{0based}+1, \dots, K+P_{0based}$.
The number of such indices is $(K+P_{0based}) - P_{0based} + 1 = K+1$.
This means there are $K+1$ possible values for the median.

Let's re-check the median position calculation.
The problem statement says "median of the remaining $N-K$ elements".
If $N-K$ is odd, say $2m+1$, the median is the $(m+1)$-th element.
If $N-K$ is even, say $2m$, the median is the $m$-th element.
This is equivalent to the $\lfloor \frac{(N-K)+1}{2} \rfloor$-th element (1-indexed).
Let $M = N-K$. Median position $P = \lfloor \frac{M+1}{2} \rfloor$.

Let's use the problem's definition of median:
If $N-K$ is odd, say $2m+1$, median is $(m+1)$-th element.
If $N-K$ is even, say $2m$, median is $m$-th element.

This is equivalent to the $\lceil \frac{N-K}{2} \rceil$-th element (1-indexed).
Let's verify:
If $N-K=5$, median is $\lceil 5/2 \rceil = 3$rd element.
If $N-K=4$, median is $\lceil 4/2 \rceil = 2$nd element.

The problem statement says: "The median of a sorted array of length $M$ is the element at position $\lfloor \frac{M+1}{2} \rfloor$ (1-indexed)."
This is the standard definition for odd length. For even length, it's usually the average of the two middle elements, or one of them.
Let's stick to the problem's definition: $P = \lfloor \frac{N-K+1}{2} \rfloor$.

Let $M = N-K$.
Median position (1-indexed) $P = \lfloor \frac{M+1}{2} \rfloor$.
0-indexed median position $P_{0based} = P-1$.

For $a_i$ (0-indexed) to be the median:
We need to keep $P_{0based}$ elements smaller than $a_i$.
We need to keep $M-1-P_{0based}$ elements larger than $a_i$.

Number of smaller elements available: $i$.
Number of larger elements available: $N-1-i$.

Conditions:
1.  Number of smaller elements to keep $\le$ Number of smaller elements available:
    $P_{0based} \le i$.
2.  Number of larger elements to keep $\le$ Number of larger elements available:
    $M-1-P_{0based} \le N-1-i$.
    $(N-K)-1 - (P-1) \le N-1-i$
    $N-K-1-P+1 \le N-1-i$
    $N-K-P \le N-1-i$
    $-K-P \le -1-i$
    $K+P \ge 1+i$
    $i \le K+P-1$.

So, the 0-indexed elements $a_i$ that can be the median are those where $i$ satisfies:
$P_{0based} \le i \le K + P_{0based}$

Where:
$M = N-K$
$P = \lfloor \frac{M+1}{2} \rfloor$
$P_{0based} = P-1$

Let's re-check the example $N=5, K=2$.
$M = 5-2 = 3$.
$P = \lfloor \frac{3+1}{2} \rfloor = 2$.
$P_{0based} = 2-1 = 1$.
The indices $i$ are $1 \le i \le 2 + 1$, so $1 \le i \le 3$.
The possible medians are $a_1, a_2, a_3$. This matches our manual check.

The range of indices for possible medians is $[P_{0based}, K+P_{0based}]$.
The number of possible medians is $(K+P_{0based}) - P_{0based} + 1 = K+1$.

The algorithm is:
1. Read $N$ and $K$.
2. Read the array $A$ and sort it.
3. Calculate $M = N-K$.
4. Calculate $P = \lfloor \frac{M+1}{2} \rfloor$.
5. Calculate $P_{0based} = P-1$.
6. The indices $i$ for which $a_i$ can be a median are from $P_{0based}$ to $K+P_{0based}$ (inclusive).
7. Collect all $a_i$ for $i$ in this range.
8. Print the collected values in sorted order (which they already are).

Example 1:
N=5, K=2
Array: 1 2 3 4 5
Sorted: 1 2 3 4 5
M = 5-2 = 3
P = floor((3+1)/2) = 2
P_0based = 2-1 = 1
Indices for median: [1, 2+1] = [1, 3]
Possible medians are a[1], a[2], a[3], which are 2, 3, 4.

Example 2:
N=6, K=3
Array: 10 20 30 40 50 60
Sorted: 10 20 30 40 50 60
M = 6-3 = 3
P = floor((3+1)/2) = 2
P_0based = 2-1 = 1
Indices for median: [1, 3+1] = [1, 4]
Possible medians are a[1], a[2], a[3], a[4], which are 20, 30, 40, 50.

The code implements this logic.
`remaining_len = n - k;` corresponds to $M$.
`median_pos = (remaining_len + 1) / 2;` corresponds to $P$.
`median_pos` is 1-indexed.
The loop iterates through `i` from 0 to `n-1`.
The condition `i >= median_pos - 1 && i <= k + median_pos - 1` corresponds to $P_{0based} \le i \le K + P_{0based}$.
`median_pos - 1` is $P_{0based}$.
`k + median_pos - 1` is $K + P_{0based}$.

The code seems correct.

## Complexity Analysis
- **Time Complexity**:
    - Reading input: $O(N)$
    - Sorting the array: $O(N \log N)$
    - Calculating median position and iterating through possible medians: $O(N)$ in the worst case (if all elements are possible medians).
    - Inserting into a `std::set`: $O(\log S)$ where $S$ is the number of unique medians. In the worst case, $S=N$. So, $O(N \log N)$.
    - Printing the output: $O(N)$ in the worst case.
    The dominant factor is sorting, so the overall time complexity is $O(N \log N)$.

- **Space Complexity**:
    - Storing the input array: $O(N)$.
    - Storing possible medians in a `std::set`: $O(N)$ in the worst case.
    The overall space complexity is $O(N)$.

## Solution Code
```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>

int main() {
    // Optimize C++ standard streams for competitive programming
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t; // Read the number of test cases
    while (t--) {
        int n, k;
        std::cin >> n >> k; // Read array size N and number of elements to remove K

        std::vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i]; // Read array elements
        }

        // Sort the array to easily determine medians and count elements
        std::sort(a.begin(), a.end());

        // Calculate the number of elements remaining after removal
        int remaining_len = n - k;

        // Calculate the 1-indexed position of the median in the remaining array.
        // According to the problem statement: median is at floor((M+1)/2) for an array of size M.
        int median_pos_1_indexed = (remaining_len + 1) / 2;

        // We are interested in the 0-indexed position for array access.
        int median_pos_0_indexed = median_pos_1_indexed - 1;

        // A set to store unique possible median values.
        std::set<int> possible_medians;

        // Iterate through each element of the sorted array to check if it can be a median.
        // For an element a[i] (0-indexed) to be the median of the remaining `remaining_len` elements:
        // 1. It must be the `median_pos_0_indexed`-th smallest element among the remaining `remaining_len` elements.
        // 2. This means there must be exactly `median_pos_0_indexed` elements smaller than a[i]
        //    and `remaining_len - 1 - median_pos_0_indexed` elements larger than a[i] in the final array.
        //
        // Let's analyze the conditions based on the original sorted array `a`:
        // Number of elements strictly smaller than `a[i]` in the original array is `i`.
        // Number of elements strictly larger than `a[i]` in the original array is `n - 1 - i`.
        //
        // To make `a[i]` the median, we need to select `median_pos_0_indexed` elements from the `i` elements smaller than `a[i]`.
        // This is possible if `i >= median_pos_0_indexed`.
        //
        // We also need to select `remaining_len - 1 - median_pos_0_indexed` elements from the `n - 1 - i` elements larger than `a[i]`.
        // This is possible if `n - 1 - i >= remaining_len - 1 - median_pos_0_indexed`.
        // Substituting `remaining_len = n - k` and `median_pos_0_indexed = P-1` where `P = (M+1)/2`:
        // `n - 1 - i >= (n - k) - 1 - (P - 1)`
        // `n - 1 - i >= n - k - 1 - P + 1`
        // `n - 1 - i >= n - k - P`
        // `-1 - i >= -k - P`
        // `k + P - 1 >= i`
        // `i <= k + P - 1`
        //
        // So, an element `a[i]` (0-indexed) can be a median if its index `i` satisfies:
        // `median_pos_0_indexed <= i <= k + median_pos_0_indexed`

        int min_idx_for_median = median_pos_0_indexed;
        int max_idx_for_median = k + median_pos_0_indexed;

        for (int i = 0; i < n; ++i) {
            // Check if the current element's index falls within the valid range for a median.
            if (i >= min_idx_for_median && i <= max_idx_for_median) {
                possible_medians.insert(a[i]); // Add the element to the set of possible medians
            }
        }

        // Print the unique possible medians in sorted order.
        bool first = true;
        for (int med : possible_medians) {
            if (!first) {
                std::cout << " "; // Print space between numbers
            }
            std::cout << med;
            first = false;
        }
        std::cout << "\n"; // Newline after each test case output
    }
    return 0;
}
```