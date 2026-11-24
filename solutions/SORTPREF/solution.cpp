#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
        }

        long long total_cost = 0;
        int current_max_sorted = 0; // Represents the largest element that is already in its correct sorted position

        // Iterate from right to left to find elements that are not in their sorted positions
        // The sorted array should be [1, 2, ..., n]
        // We are looking for the first element from the right that is NOT in its correct place.
        // For example, if the array is [2, 3, 1, 4, 5], n=5.
        // The sorted array should be [1, 2, 3, 4, 5].
        // We check from right:
        // a[4] = 5. Correct position for 5 is index 4 (0-indexed). It's correct. current_max_sorted = 5.
        // a[3] = 4. Correct position for 4 is index 3. It's correct. current_max_sorted = 4.
        // a[2] = 1. Correct position for 1 is index 0. It's NOT correct.
        // This means the prefix A[1...3] (or A[0...2] in 0-indexed) needs to be sorted.
        // The cost to sort prefix A[1...i] is A_i.
        // In this example, we need to sort A[1...3] (elements 2, 3, 1). The index i is 3.
        // The cost is A_3 = 1.
        // After sorting A[1...3], the array becomes [1, 2, 3, 4, 5].

        // The logic is to find the largest `k` such that `A[N-k+1]` is `N-k+1`.
        // If `A[N]` is `N`, then the suffix of length 1 is sorted.
        // If `A[N-1]` is `N-1` and `A[N]` is `N`, then the suffix of length 2 is sorted.
        // We want to find the longest sorted suffix.
        // Let's say the longest sorted suffix has length `L`. This means `A[N-L+1...N]` is `[N-L+1, ..., N]`.
        // The elements `A[1...N-L]` are not in their final sorted positions.
        // We need to sort the prefix `A[1...N-L]`. The cost of this operation is `A[N-L]`.
        // After this sort, the entire array `A[1...N]` will be sorted.

        // Let's rephrase: we want to find the largest `k` such that `A[i] == i+1` for all `i` from `k` to `n-1`.
        // This means the suffix `A[k...n-1]` is already sorted and contains the elements `k+1, k+2, ..., n`.
        // If such a `k` exists, then the prefix `A[0...k-1]` needs to be sorted.
        // The operation to sort `A[0...i]` costs `A[i]`.
        // To sort the entire array, we need to sort the prefix `A[0...k-1]`.
        // The most efficient way to sort this prefix is to apply the operation at index `k-1`.
        // The cost will be `A[k-1]` (the value at that index *before* sorting).

        int first_unsorted_idx = n; // Index from the right that is not in its sorted place
        for (int i = n - 1; i >= 0; --i) {
            if (a[i] == i + 1) {
                // This element is in its correct sorted position
                // If we are looking for the element `n`, and `a[n-1] == n`, then the suffix of length 1 is sorted.
                // If we are looking for the element `n-1`, and `a[n-2] == n-1`, and `a[n-1] == n`, then suffix of length 2 is sorted.
                // So, we are looking for the largest `k` such that `a[i] == i+1` for `i` from `k` to `n-1`.
                // This means `a[n-1] == n`, `a[n-2] == n-1`, ..., `a[k] == k+1`.
                // The loop finds the first index `i` from the right where `a[i] != i+1`.
                // All elements from `i+1` to `n-1` are in their correct sorted positions.
                // The prefix that needs sorting is `A[0...i]`.
                // The operation to sort `A[0...i]` costs `A[i]`.
                // So, `first_unsorted_idx` will be `i`.
            } else {
                // Found the first element from the right that is NOT in its sorted position.
                // This element is `a[i]`, and it should be `i+1`.
                // The prefix `A[0...i]` needs to be sorted.
                // The operation to sort `A[0...i]` costs `A[i]`.
                first_unsorted_idx = i;
                break;
            }
        }

        // If first_unsorted_idx is n, it means the entire array was already sorted.
        if (first_unsorted_idx == n) {
            total_cost = 0;
        } else {
            // The prefix A[0...first_unsorted_idx] needs to be sorted.
            // The operation to sort A[0...k] costs A[k].
            // To sort the prefix A[0...first_unsorted_idx], we should apply the operation at index `first_unsorted_idx`.
            // The cost is the value of A[first_unsorted_idx] *before* sorting.
            total_cost = a[first_unsorted_idx];
        }

        std::cout << total_cost << "\n";
    }
    return 0;
}