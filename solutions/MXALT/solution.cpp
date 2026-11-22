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