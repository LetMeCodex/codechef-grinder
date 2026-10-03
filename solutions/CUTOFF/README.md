# [Passing Marks (CUTOFF)](https://www.codechef.com/problems/CUTOFF)
- **Difficulty Rating**: 855
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine the maximum possible integer passing mark `P` such that exactly `X` students pass. We are given `N` students' scores and the target number of passing students `X`. A student passes if their score is strictly greater than `P`.

## Intuition & Mathematical Observation

The core idea is to identify which students should pass and which should not, given the goal of maximizing `P` while ensuring exactly `X` students pass.

1.  **Identify the passing students**: To have exactly `X` students pass, and to maximize the passing mark `P`, it's intuitive that these `X` students must be the ones with the highest scores. If a student with a lower score passes, then all students with higher scores must also pass (since their scores would also be strictly greater than `P`). Therefore, to precisely control the count to `X`, we must select the `X` students with the highest scores.

2.  **Sort the scores**: To easily identify the highest scores, we should first sort all `N` student scores in ascending order. Let the sorted scores be `A[0], A[1], ..., A[N-1]`. After sorting, `A[0]` is the lowest score and `A[N-1]` is the highest.

3.  **Determine the critical scores**:
    *   The `X` students with the highest scores are `A[N-X], A[N-X+1], ..., A[N-1]`.
    *   The remaining `N-X` students with lower scores are `A[0], A[1], ..., A[N-X-1]`.

4.  **Formulate conditions for `P`**:
    *   **Condition 1: All `X` highest-scoring students must pass.**
        This means `A[N-X] > P`, `A[N-X+1] > P`, ..., `A[N-1] > P`.
        The most restrictive of these is `A[N-X] > P` (since `A[N-X]` is the minimum score among these `X` students).
        Since `P` must be an integer, `A[N-X] > P` implies `P <= A[N-X] - 1`.

    *   **Condition 2: All `N-X` lower-scoring students must *not* pass.**
        This condition applies only if `N-X > 0` (i.e., `X < N`).
        If `X < N`, these students must satisfy `A[0] <= P`, `A[1] <= P`, ..., `A[N-X-1] <= P`.
        The most restrictive of these is `A[N-X-1] <= P` (since `A[N-X-1]` is the maximum score among these `N-X` students).

5.  **Combine conditions and maximize `P`**:

    *   **Case A: `X < N`**
        We need to satisfy both conditions: `A[N-X-1] <= P` AND `P <= A[N-X] - 1`.
        Combining these, we get `A[N-X-1] <= P <= A[N-X] - 1`.
        To maximize `P`, we choose the largest possible integer value: `P = A[N-X] - 1`.
        (Note: Since scores are distinct, `A[N-X-1] < A[N-X]`, which means `A[N-X-1] <= A[N-X] - 1`, so a valid `P` always exists).

    *   **Case B: `X = N` (all students pass)**
        In this case, there are no lower-scoring students (`N-X = 0`), so Condition 2 does not apply.
        From Condition 1, we need `A[N-N] > P`, which simplifies to `A[0] > P`.
        This implies `P <= A[0] - 1`.
        To maximize `P`, we choose `P = A[0] - 1`.

6.  **Unified Solution**:
    Observe that the formula `A[N-X] - 1` works for both cases:
    *   If `X < N`, it's `A[N-X] - 1`.
    *   If `X = N`, then `N-X = 0`, so it becomes `A[0] - 1`.
    Thus, the maximum passing mark `P` is simply `A[N-X] - 1`.

## Complexity Analysis

*   **Time Complexity**:
    *   Reading `N` and `X`: $O(1)$
    *   Reading `N` scores into a vector: $O(N)$
    *   Sorting the vector `A`: $O(N \log N)$
    *   Accessing `A[N-X]` and printing: $O(1)$
    The dominant operation is sorting the scores. Since this is done for each of the `T` test cases, the total time complexity is $O(T \cdot N \log N)$.
    Therefore, the time complexity per test case is $\mathbf{O(N \log N)}$.

*   **Space Complexity**:
    *   Storing `N` scores in the `std::vector<int> A`: $O(N)$
    The space used is proportional to the number of students.
    Therefore, the space complexity per test case is $\mathbf{O(N)}$.

## Solution Code

```cpp
#include <iostream>
#include <vector>
#include <algorithm> // Required for std::sort

void solve() {
    int N, X;
    std::cin >> N >> X;
    std::vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> A[i];
    }

    // Sort the scores in ascending order.
    // After sorting, A[0] will be the smallest score, and A[N-1] will be the largest.
    std::sort(A.begin(), A.end());

    // The problem asks for the maximum passing mark P such that exactly X students pass.
    // A student passes if their score is strictly greater than P.
    //
    // Let the sorted scores be A[0], A[1], ..., A[N-1].
    //
    // For exactly X students to pass, these must be the X students with the highest scores.
    // These scores are A[N-X], A[N-X+1], ..., A[N-1].
    //
    // 1. All these X students must pass:
    //    The minimum score among these X students is A[N-X].
    //    For A[N-X] to pass, we must have A[N-X] > P.
    //    This implies P <= A[N-X] - 1.
    //
    // 2. The remaining N-X students must not pass:
    //    These students have scores A[0], A[1], ..., A[N-X-1].
    //    This condition applies only if N-X > 0 (i.e., X < N).
    //    If X < N, the maximum score among these N-X students is A[N-X-1].
    //    For A[N-X-1] not to pass, we must have A[N-X-1] <= P.
    //
    // Combining these two conditions for X < N:
    // We need A[N-X-1] <= P <= A[N-X] - 1.
    // Since all scores are distinct, A[N-X-1] < A[N-X], which means A[N-X-1] <= A[N-X] - 1.
    // To maximize P, we choose P = A[N-X] - 1.
    //
    // If X = N (all students pass):
    // Condition 2 does not apply. From Condition 1, we need A[N-N] > P, which is A[0] > P.
    // This implies P <= A[0] - 1.
    // To maximize P, we choose P = A[0] - 1.
    //
    // Both cases are covered by the formula A[N-X] - 1.
    // For X=N, N-X=0, so it becomes A[0]-1.

    std::cout << A[N - X] - 1 << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
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