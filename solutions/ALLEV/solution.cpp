#include <iostream>
#include <vector>
#include <numeric> // Not strictly needed, but useful for sum operations

void solve() {
    int N;
    std::cin >> N;
    std::vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> A[i];
    }

    bool possible = false;

    // Iterate through all possible number of elements 'k' that could remain on the blackboard.
    // 'k' ranges from 1 to N.
    // If 'k' elements remain, it means we performed N-k operations.
    // The resulting array would be [A[0], A[1], ..., A[k-2], sum(A[k-1]...A[N-1])]
    // (using 0-indexed array A)
    for (int k = 1; k <= N; ++k) {
        bool prefix_all_even = true;
        // Check if A[0]...A[k-2] are all even.
        // This loop runs for j from 0 to k-2.
        // If k=1, this loop doesn't run, which means prefix_all_even remains true (vacuously true).
        for (int j = 0; j < k - 1; ++j) {
            if (A[j] % 2 != 0) { // If A[j] is odd
                prefix_all_even = false;
                break;
            }
        }

        if (prefix_all_even) {
            // If the prefix elements are all even (or k=1), check the sum of the remaining suffix.
            long long suffix_sum = 0; // Use long long for sum to be safe, though int is fine for given constraints
            for (int j = k - 1; j < N; ++j) {
                suffix_sum += A[j];
            }

            if (suffix_sum % 2 == 0) { // If the suffix sum is even
                possible = true;
                break; // Found a way to make all numbers even, no need to check further k
            }
        }
    }

    if (possible) {
        std::cout << "Yes\n";
    } else {
        std::cout << "No\n";
    }
}

int main() {
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}