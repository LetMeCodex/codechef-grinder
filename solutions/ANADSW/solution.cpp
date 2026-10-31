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

    if (N == 1) {
        // An array with one element is always sorted.
        std::cout << "YES\n";
    } else if (N == 2) {
        // For N=2, the only possible pair of indices is (0, 1).
        // The condition for swapping is j - i > 1.
        // For (0, 1), j - i = 1, which is not > 1.
        // So, no swaps are possible. The array can be sorted only if it's already sorted.
        if (A[0] <= A[1]) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    } else if (N == 3) {
        // For N=3, the only allowed swap is between A[0] and A[2] (j - i = 2 > 1).
        // The element A[1] (at index 1) is fixed and cannot be moved.
        // Therefore, for the array to be sortable, A[1] must already be the middle element
        // of the sorted version of the array.
        std::vector<int> B = A; // Create a copy to sort
        std::sort(B.begin(), B.end()); // Sort the copy
        if (A[1] == B[1]) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    } else {
        // For N >= 4, all indices are connected through allowed swaps.
        // 1. All odd indices (1, 3, 5, ...) can swap with each other (e.g., A[k] with A[k+2]).
        // 2. All even indices (2, 4, 6, ...) can swap with each other (e.g., A[k] with A[k+2]).
        // 3. For N >= 4, index 0 (odd in 0-indexed, 1 in 1-indexed) can swap with index 3 (even in 0-indexed, 4 in 1-indexed)
        //    because |3 - 0| = 3 > 1.
        // This connection between an odd-indexed position and an even-indexed position
        // links all positions into a single connected component.
        // In a connected component, any element can be moved to any position,
        // meaning any permutation (including the sorted one) is reachable.
        std::cout << "YES\n";
    }
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