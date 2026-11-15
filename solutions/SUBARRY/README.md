# [Interesting Subarray (SUBARRY)](https://www.codechef.com/problems/SUBARRY)
- **Difficulty Rating**: 1375
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to find the minimum and maximum "interesting value" among all possible non-empty subarrays of a given array $A$. An "interesting value" for a subarray is defined as the product of its minimum and maximum elements.

For each test case, we are given an integer $N$ (the size of the array) followed by $N$ integers representing the elements of array $A$. We need to output two space-separated integers: the overall minimum interesting value and the overall maximum interesting value.

**Constraints:**
*   $1 \le T \le 1000$ (number of test cases)
*   $1 \le N \le 10^5$ (array size)
*   $-10^9 \le A_i \le 10^9$ (element values)
*   Sum of $N$ over all test cases $\le 10^5$.

## Intuition & Mathematical Observation

Let's denote the given array as $A$. For any non-empty subarray $S$ of $A$, let $min(S)$ be its minimum element and $max(S)$ be its maximum element. The "interesting value" for $S$ is $min(S) \times max(S)$. We need to find the global minimum and maximum of these interesting values across all possible subarrays.

The key insight lies in understanding which elements can contribute to the extreme (minimum or maximum) interesting values. Let $A_{min}$ be the global minimum element in the entire array $A$, and $A_{max}$ be the global maximum element in the entire array $A$.

Consider any subarray $S$. Its minimum element $min(S)$ must be greater than or equal to $A_{min}$ (i.e., $A_{min} \le min(S)$), and its maximum element $max(S)$ must be less than or equal to $A_{max}$ (i.e., $max(S) \le A_{max}$).

The product $min(S) \times max(S)$ can be positive, negative, or zero, depending on the signs of $min(S)$ and $max(S)$.

Let's analyze the candidates for the overall minimum and maximum interesting values:

1.  **To maximize $min(S) \times max(S)$**:
    *   If $min(S)$ and $max(S)$ are both positive, we want them to be as large as possible. The largest possible value for both $min(S)$ and $max(S)$ is $A_{max}$. This product $A_{max} \times A_{max}$ can be achieved by a subarray containing only $A_{max}$ (e.g., `[A_max]`).
    *   If $min(S)$ and $max(S)$ are both negative, we want them to be as negative as possible (largest absolute values) to get a large positive product. The most negative possible value for $min(S)$ is $A_{min}$, and for $max(S)$ (if it's also negative) it would be $A_{min}$ as well. This product $A_{min} \times A_{min}$ can be achieved by a subarray containing only $A_{min}$ (e.g., `[A_min]`).
    *   If $min(S)$ is negative and $max(S)$ is positive, their product $min(S) \times max(S)$ will be negative. A negative product cannot be the overall maximum interesting value unless all other products are also negative (which only happens if all array elements are negative, in which case the first two points cover it).
    *   Therefore, the overall maximum interesting value must be $\max(A_{min} \times A_{min}, A_{max} \times A_{max})$.

2.  **To minimize $min(S) \times max(S)$**:
    *   If $min(S)$ and $max(S)$ are both positive, their product is positive. The smallest positive product would be $A_{min} \times A_{min}$ (if $A_{min}$ is positive) or $A_{min} \times A_{max}$ (if $A_{min}$ is positive and $A_{max}$ is also positive).
    *   If $min(S)$ and $max(S)$ are both negative, their product is positive. The smallest positive product would be $A_{max} \times A_{max}$ (if $A_{max}$ is negative) or $A_{min} \times A_{max}$ (if $A_{min}$ is negative and $A_{max}$ is also negative).
    *   If $min(S)$ is negative and $max(S)$ is positive, their product $min(S) \times max(S)$ will be negative. To make this product as small (most negative) as possible, we want $min(S)$ to be as negative as possible (i.e., $A_{min}$) and $max(S)$ to be as positive as possible (i.e., $A_{max}$). This product $A_{min} \times A_{max}$ can be achieved by a subarray that contains both $A_{min}$ and $A_{max}$ (e.g., the entire array $A$ itself).
    *   Therefore, the overall minimum interesting value must be $\min(A_{min} \times A_{min}, A_{max} \times A_{max}, A_{min} \times A_{max})$.

Combining these observations, the overall minimum and maximum interesting values will always be found among these three products:
1.  $P_1 = A_{min} \times A_{min}$ (achieved by subarray `[A_min]`)
2.  $P_2 = A_{max} \times A_{max}$ (achieved by subarray `[A_max]`)
3.  $P_3 = A_{min} \times A_{max}$ (achieved by a subarray containing both $A_{min}$ and $A_{max}$, e.g., the entire array $A$)

Thus, the strategy is:
1.  Iterate through the input array to find its global minimum element ($A_{min}$) and global maximum element ($A_{max}$).
2.  Calculate the three candidate products: $P_1 = A_{min} \times A_{min}$, $P_2 = A_{max} \times A_{max}$, and $P_3 = A_{min} \times A_{max}$.
3.  The minimum interesting value is $\min(P_1, P_2, P_3)$.
4.  The maximum interesting value is $\max(P_1, P_2, P_3)$.

**Data Type Consideration:**
The elements $A_i$ can be up to $10^9$ or down to $-10^9$. Their product can be as large as $(10^9)^2 = 10^{18}$. A standard `int` in C++ typically handles values up to $2 \times 10^9$, which is insufficient. Therefore, `long long` must be used for storing the products and for `min_val`/`max_val` to prevent overflow.

## Complexity Analysis

*   **Time Complexity**:
    *   We iterate through the array once to find the global minimum (`min_val`) and global maximum (`max_val`). This takes $O(N)$ time.
    *   Calculating the three products and finding their minimum and maximum takes constant time, $O(1)$.
    *   For each test case, the time complexity is $O(N)$.
    *   Given that the sum of $N$ over all test cases is $\le 10^5$, the total time complexity across all test cases is $O(\sum N)$, which is highly efficient.

*   **Space Complexity**:
    *   We only store a few variables (`N`, `min_val`, `max_val`, `current_A_i`, and the three product variables). We do not store the entire array.
    *   Therefore, the space complexity is $O(1)$ (constant space).

## Solution Code

```cpp
#include <iostream> // For std::cin, std::cout
#include <vector>   // Not strictly needed if processing on the fly, but good for general competitive programming
#include <algorithm> // For std::min, std::max
#include <limits>    // For std::numeric_limits (LLONG_MAX, LLONG_MIN)

// Using namespace std; is requested by problem statement
using namespace std;

void solve() {
    int N;
    cin >> N;
    
    // Initialize min_val and max_val with extreme values to correctly find
    // the actual minimum and maximum elements in the array.
    // A_i can be up to 10^9, so long long is used for min_val/max_val to be safe,
    // though int would technically suffice for storing A_i values themselves.
    // The products definitely need long long.
    long long min_val = numeric_limits<long long>::max();
    long long max_val = numeric_limits<long long>::min();
    
    for (int i = 0; i < N; ++i) {
        long long current_A_i; // Use long long for current_A_i to be consistent and safe, though int is fine for A_i itself.
        cin >> current_A_i;
        min_val = min(min_val, current_A_i);
        max_val = max(max_val, current_A_i);
    }
    
    // The minimum and maximum interesting values will always be achieved by
    // one of these three products:
    // 1. min_val * min_val (from a subarray containing only the global minimum element)
    // 2. max_val * max_val (from a subarray containing only the global maximum element)
    // 3. min_val * max_val (from a subarray containing both global min and max, e.g., the entire array)
    
    long long prod1 = min_val * min_val;
    long long prod2 = max_val * max_val;
    long long prod3 = min_val * max_val;
    
    // Calculate the overall minimum interesting value
    long long min_interesting_value = min({prod1, prod2, prod3});
    
    // Calculate the overall maximum interesting value
    long long max_interesting_value = max({prod1, prod2, prod3});
    
    cout << min_interesting_value << " " << max_interesting_value << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    
    return 0;
}
```