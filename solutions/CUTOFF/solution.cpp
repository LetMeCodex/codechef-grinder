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