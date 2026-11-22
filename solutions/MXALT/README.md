# [Maximum Alternating Sum (MXALT)](https://www.codechef.com/problems/MXALT)
- **Difficulty Rating**: 1111
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to find the maximum possible value of an alternating sum $A_1 - A_2 + A_3 - A_4 + \dots + (-1)^{N-1}A_N$. We are given $N$ integers, and we have the freedom to arrange them in any order to form the sequence $A_1, A_2, \dots, A_N$.

## Intuition & Mathematical Observation
Let the alternating sum be $S$. We can rewrite the sum by grouping terms with positive and negative coefficients:
$S = (A_1 + A_3 + A_5 + \dots) - (A_2 + A_4 + A_6 + \dots)$

To maximize this sum $S$, we need to achieve two goals simultaneously:
1. **Maximize the sum of terms with a positive coefficient** (i.e., $A_1, A_3, A_5, \dots$).
2. **Minimize the sum of terms with a negative coefficient** (i.e., $A_2, A_4, A_6, \dots$).

This leads to a greedy strategy:
- To maximize the positive part, we should assign the **largest available numbers** from the input array to the positions that have a positive coefficient.
- To minimize the negative part (which means maximizing the value being subtracted), we should assign the **smallest available numbers** from the input array to the positions that have a negative coefficient.

Let's count how many terms receive a positive sign and how many receive a negative sign:
- The terms $A_i$ where $i$ is odd ($1, 3, 5, \dots$) get a positive sign. There are $\lceil N/2 \rceil$ such terms.
- The terms $A_i$ where $i$ is even ($2, 4, 6, \dots$) get a negative sign. There are $\lfloor N/2 \rfloor$ such terms.

So, the optimal strategy is:
1. Sort the given $N$ integers in ascending order. Let the sorted array be $A'$.
2. Take the $\lceil N/2 \rceil$ largest numbers from $A'$ and add them to our `max_alternating_sum`. These will be the elements from index $\lfloor N/2 \rfloor$ up to $N-1$ in the sorted array ($A'_{\lfloor N/2 \rfloor}, A'_{\lfloor N/2 \rfloor + 1}, \dots, A'_{N-1}$).
3. Take the $\lfloor N/2 \rfloor$ smallest numbers from $A'$ and subtract them from our `max_alternating_sum`. These will be the elements from index $0$ up to $\lfloor N/2 \rfloor - 1$ in the sorted array ($A'_0, A'_1, \dots, A'_{\lfloor N/2 \rfloor - 1}$).

For example, if $N=5$ and the input array is $[1, 5, 2, 8, 3]$:
1. Sorted array $A'$ becomes $[1, 2, 3, 5, 8]$.
2. Number of terms to be subtracted (negative coefficients): $\lfloor 5/2 \rfloor = 2$. These are the smallest two numbers: $1, 2$.
3. Number of terms to be added (positive coefficients): $\lceil 5/2 \rceil = 3$. These are the largest three numbers: $3, 5, 8$.
The maximum alternating sum would be $(3+5+8) - (1+2) = 16 - 3 = 13$.

The solution code implements this by first sorting the array and then iterating through the first `N/2` elements to subtract them, and the remaining `N - N/2` elements to add them.

## Complexity Analysis
- **Time Complexity**:
    - Reading $N$ integers into a vector takes $O(N)$ time.
    - Sorting the vector using `std::sort` takes $O(N \log N)$ time.
    - Iterating through the sorted vector to calculate the sum takes $O(N)$ time.
    - The dominant factor is sorting, so the overall time complexity is $O(N \log N)$.

- **Space Complexity**:
    - Storing the input integers in a `std::vector` takes $O(N)$ space.
    - `std::sort` typically uses $O(\log N)$ auxiliary space for its recursion stack (e.g., Introsort) or $O(N)$ for temporary storage in some implementations (e.g., Merge Sort fallback). In competitive programming, $O(N)$ is a safe upper bound for the auxiliary space of `std::sort` in the worst case.
    - Therefore, the overall space complexity is $O(N)$.

## Solution Code
```cpp
#include <iostream>
#include <vector>
#include <algorithm> // Required for std::sort

void solve() {
    int N;
    std::cin >> N;
    std::vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> A[i];
    }

    // Sort the array in ascending order.
    // This allows us to easily identify the smallest and largest elements.
    std::sort(A.begin(), A.end());

    long long max_alternating_sum = 0;

    // The alternating sum is A_1 - A_2 + A_3 - A_4 + ...
    // To maximize this sum, we want to:
    // 1. Assign the largest elements to positions with a +1 coefficient (odd indices).
    // 2. Assign the smallest elements to positions with a -1 coefficient (even indices).

    // After sorting, the first N/2 elements (A[0] to A[N/2 - 1]) are the smallest.
    // These should be assigned to positions with a -1 coefficient.
    // The remaining elements (A[N/2] to A[N-1]) are the largest.
    // These should be assigned to positions with a +1 coefficient.

    // Number of elements to be subtracted (smallest ones)
    int num_neg_terms = N / 2; 
    
    // Sum the smallest 'num_neg_terms' elements with a negative sign
    for (int i = 0; i < num_neg_terms; ++i) {
        max_alternating_sum -= A[i];
    }

    // Sum the remaining (N - num_neg_terms) elements with a positive sign
    // These are the largest elements, from index 'num_neg_terms' up to 'N-1'.
    for (int i = num_neg_terms; i < N; ++i) {
        max_alternating_sum += A[i];
    }

    std::cout << max_alternating_sum << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
```