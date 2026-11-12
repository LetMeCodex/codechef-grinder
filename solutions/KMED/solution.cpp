#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        int n, k;
        std::cin >> n >> k;
        std::vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
        }
        std::sort(a.begin(), a.end());

        int remaining_len = n - k;
        int median_pos = (remaining_len + 1) / 2; // 1-indexed position of median

        std::set<int> possible_medians;

        // Iterate through each element of the sorted array and consider it as a potential median.
        // If an element `a[i]` is to be the median of the remaining `n-k` elements,
        // it must be the `median_pos`-th smallest element among them.
        // This means there must be exactly `median_pos - 1` elements smaller than or equal to `a[i]`
        // and `remaining_len - median_pos` elements greater than or equal to `a[i]`
        // in the remaining `n-k` elements.

        for (int i = 0; i < n; ++i) {
            // Let's assume a[i] is the median of the remaining n-k elements.
            // For a[i] to be the median, it must be the median_pos-th smallest element.
            // This means we need to have exactly median_pos - 1 elements smaller than a[i]
            // and remaining_len - median_pos elements larger than a[i] in the final array.

            // Number of elements smaller than a[i] in the original sorted array is `i`.
            // Number of elements larger than a[i] in the original sorted array is `n - 1 - i`.

            // To make a[i] the median, we need to select `median_pos - 1` elements from the `i` elements
            // that are strictly smaller than a[i] to be in the remaining array.
            // We can select at most `i` elements smaller than a[i].
            // We must select at least `max(0, (median_pos - 1) - k)` elements smaller than a[i]
            // because we can delete at most `k` elements.
            // The number of elements smaller than a[i] that we *must* keep is `median_pos - 1`.
            // The number of elements smaller than a[i] that we *can* delete is `i - (median_pos - 1)`.
            // This number of deletable smaller elements must be less than or equal to `k`.
            // So, `i - (median_pos - 1) <= k` which means `i - median_pos + 1 <= k`.
            // This is equivalent to `i <= k + median_pos - 1`.

            // Similarly, we need to select `remaining_len - median_pos` elements from the `n - 1 - i` elements
            // that are strictly larger than a[i] to be in the remaining array.
            // We can select at most `n - 1 - i` elements larger than a[i].
            // We must select at least `max(0, (remaining_len - median_pos) - k)` elements larger than a[i].
            // The number of elements larger than a[i] that we *must* keep is `remaining_len - median_pos`.
            // The number of elements larger than a[i] that we *can* delete is `(n - 1 - i) - (remaining_len - median_pos)`.
            // This number of deletable larger elements must be less than or equal to `k`.
            // So, `(n - 1 - i) - (remaining_len - median_pos) <= k`
            // `n - 1 - i - (n - k - median_pos) <= k`
            // `n - 1 - i - n + k + median_pos <= k`
            // `-1 - i + median_pos <= 0`
            // `median_pos <= i + 1`
            // This is equivalent to `i >= median_pos - 1`.

            // Let's rephrase:
            // If a[i] is the median, then in the remaining n-k elements:
            // There are median_pos - 1 elements smaller than or equal to a[i].
            // There are remaining_len - median_pos elements larger than or equal to a[i].

            // Consider a[i] as the median.
            // Number of elements strictly smaller than a[i] in the original array is `i`.
            // Number of elements strictly larger than a[i] in the original array is `n - 1 - i`.

            // To make a[i] the median, we need to ensure that in the final n-k elements:
            // 1. At least `median_pos - 1` elements are strictly smaller than a[i].
            //    This means we can delete at most `i - (median_pos - 1)` elements from the `i` elements smaller than a[i].
            //    So, `i - (median_pos - 1) <= k` => `i - median_pos + 1 <= k` => `i <= k + median_pos - 1`.
            // 2. At least `remaining_len - median_pos` elements are strictly larger than a[i].
            //    This means we can delete at most `(n - 1 - i) - (remaining_len - median_pos)` elements from the `n - 1 - i` elements larger than a[i].
            //    So, `(n - 1 - i) - (remaining_len - median_pos) <= k`
            //    `n - 1 - i - (n - k - median_pos) <= k`
            //    `n - 1 - i - n + k + median_pos <= k`
            //    `-1 - i + median_pos <= 0`
            //    `median_pos <= i + 1` => `i >= median_pos - 1`.

            // So, for a[i] to be a possible median, we need to be able to select `median_pos - 1` elements
            // from the `i` elements smaller than `a[i]` and `remaining_len - median_pos` elements
            // from the `n - 1 - i` elements larger than `a[i]`, such that the total number of deleted elements is `k`.

            // The number of elements we *must* keep that are smaller than a[i] is `median_pos - 1`.
            // The number of elements we *must* keep that are larger than a[i] is `remaining_len - median_pos`.
            // The total number of elements we *must* keep (excluding a[i] itself) is `(median_pos - 1) + (remaining_len - median_pos) = remaining_len - 1`.
            // This is consistent because we keep `n-k` elements in total, and `a[i]` is one of them.

            // Number of elements smaller than a[i] available to keep: `i`.
            // Number of elements smaller than a[i] we need to keep: `median_pos - 1`.
            // Number of elements smaller than a[i] we can delete: `i - (median_pos - 1)`.
            // This must be <= k. So, `i - median_pos + 1 <= k`.

            // Number of elements larger than a[i] available to keep: `n - 1 - i`.
            // Number of elements larger than a[i] we need to keep: `remaining_len - median_pos`.
            // Number of elements larger than a[i] we can delete: `(n - 1 - i) - (remaining_len - median_pos)`.
            // This must be <= k. So, `(n - 1 - i) - (remaining_len - median_pos) <= k`.

            // Let's check the conditions for a[i] to be a median.
            // For a[i] to be the median of the remaining `remaining_len` elements:
            // There must be at least `median_pos - 1` elements smaller than or equal to `a[i]` in the remaining set.
            // There must be at least `remaining_len - median_pos + 1` elements greater than or equal to `a[i]` in the remaining set.

            // Consider `a[i]` as the median.
            // We need to select `median_pos - 1` elements from the `i` elements smaller than `a[i]`.
            // We need to select `remaining_len - median_pos` elements from the `n - 1 - i` elements larger than `a[i]`.
            // The total number of elements selected is `(median_pos - 1) + 1 + (remaining_len - median_pos) = remaining_len`.
            // The number of elements deleted is `k`.
            // The number of elements smaller than `a[i]` that we *can* delete is `i - (median_pos - 1)`. This must be <= `k`.
            // The number of elements larger than `a[i]` that we *can* delete is `(n - 1 - i) - (remaining_len - median_pos)`. This must be <= `k`.

            // Condition 1: We must be able to pick `median_pos - 1` elements from the `i` elements smaller than `a[i]`.
            // This is possible if `i >= median_pos - 1`.
            // Also, the number of elements we *can* delete from the smaller ones is `i - (median_pos - 1)`.
            // This must be less than or equal to `k`. So, `i - median_pos + 1 <= k`.

            // Condition 2: We must be able to pick `remaining_len - median_pos` elements from the `n - 1 - i` elements larger than `a[i]`.
            // This is possible if `n - 1 - i >= remaining_len - median_pos`.
            // `n - 1 - i >= (n - k) - median_pos`
            // `n - 1 - i >= n - k - median_pos`
            // `-1 - i >= -k - median_pos`
            // `k + median_pos - 1 >= i`
            // This is the same as the first condition.

            // Let's think about the number of elements we *must* delete from the smaller and larger groups.
            // Number of elements smaller than a[i] is `i`. We need to keep `median_pos - 1` of them.
            // So, we can delete at most `i - (median_pos - 1)` of them.
            // Number of elements larger than a[i] is `n - 1 - i`. We need to keep `remaining_len - median_pos` of them.
            // So, we can delete at most `(n - 1 - i) - (remaining_len - median_pos)` of them.

            // The total number of elements we *can* delete is `k`.
            // We need to check if there exists a way to delete `k` elements such that `a[i]` becomes the median.

            // For `a[i]` to be the median, we need to have `median_pos - 1` elements smaller than it and `remaining_len - median_pos` elements larger than it in the final array.
            // Number of elements smaller than `a[i]` in original array: `i`.
            // Number of elements larger than `a[i]` in original array: `n - 1 - i`.

            // We need to keep `median_pos - 1` elements from the `i` smaller elements.
            // We need to keep `remaining_len - median_pos` elements from the `n - 1 - i` larger elements.
            // The total number of elements we keep is `(median_pos - 1) + 1 + (remaining_len - median_pos) = remaining_len`.
            // The number of elements we delete is `k`.

            // The number of elements smaller than `a[i]` that we *must* delete is `i - (median_pos - 1)`.
            // This must be non-negative, so `i >= median_pos - 1`.
            // The number of elements larger than `a[i]` that we *must* delete is `(n - 1 - i) - (remaining_len - median_pos)`.
            // This must be non-negative, so `n - 1 - i >= remaining_len - median_pos`.

            // Let `num_smaller_to_keep = median_pos - 1`.
            // Let `num_larger_to_keep = remaining_len - median_pos`.

            // We have `i` elements smaller than `a[i]`. We need to keep `num_smaller_to_keep`.
            // This is possible if `i >= num_smaller_to_keep`.
            // The number of smaller elements we *can* delete is `i - num_smaller_to_keep`.

            // We have `n - 1 - i` elements larger than `a[i]`. We need to keep `num_larger_to_keep`.
            // This is possible if `n - 1 - i >= num_larger_to_keep`.
            // The number of larger elements we *can* delete is `(n - 1 - i) - num_larger_to_keep`.

            // The total number of elements we *can* delete is `(i - num_smaller_to_keep) + ((n - 1 - i) - num_larger_to_keep)`.
            // This sum must be equal to `k`.
            // `i - (median_pos - 1) + (n - 1 - i) - (remaining_len - median_pos) = k`
            // `i - median_pos + 1 + n - 1 - i - (n - k - median_pos) = k`
            // `n - median_pos - (n - k - median_pos) = k`
            // `n - median_pos - n + k + median_pos = k`
            // `k = k`. This equation is always true, which means this approach is not directly checking feasibility.

            // The correct condition is:
            // For `a[i]` to be the median, we need to be able to form a sub-array of size `n-k` where `a[i]` is the `median_pos`-th element.
            // This means we need to select `median_pos - 1` elements from the `i` elements smaller than `a[i]`.
            // And we need to select `remaining_len - median_pos` elements from the `n - 1 - i` elements larger than `a[i]`.
            // The total number of elements we select is `(median_pos - 1) + 1 + (remaining_len - median_pos) = remaining_len`.
            // The number of elements we *must* delete from the smaller group is `i - (median_pos - 1)`. This must be non-negative.
            // The number of elements we *must* delete from the larger group is `(n - 1 - i) - (remaining_len - median_pos)`. This must be non-negative.

            // The total number of elements we *can* delete is `k`.
            // We can delete at most `i` elements from the smaller group.
            // We can delete at most `n - 1 - i` elements from the larger group.
            // We can delete at most `k` elements in total.

            // For `a[i]` to be the median:
            // We need to keep `median_pos - 1` elements from the `i` elements smaller than `a[i]`.
            // This requires `i >= median_pos - 1`.
            // We need to keep `remaining_len - median_pos` elements from the `n - 1 - i` elements larger than `a[i]`.
            // This requires `n - 1 - i >= remaining_len - median_pos`.

            // The number of elements we *can* delete from the smaller group is `i`.
            // The number of elements we *can* delete from the larger group is `n - 1 - i`.
            // The total number of elements we *can* delete is `k`.

            // We need to be able to select `median_pos - 1` elements from the `i` smaller elements.
            // This is possible if `i >= median_pos - 1`.
            // The number of elements we *can* delete from the smaller group is `i`.
            // The number of elements we *can* delete from the larger group is `n - 1 - i`.

            // We need to select `median_pos - 1` elements from the `i` elements smaller than `a[i]`.
            // We need to select `remaining_len - median_pos` elements from the `n - 1 - i` elements larger than `a[i]`.
            // The total number of elements we *must* delete is `k`.

            // The number of elements smaller than `a[i]` that we *can* delete is `i`.
            // The number of elements larger than `a[i]` that we *can* delete is `n - 1 - i`.
            // We need to delete `k` elements in total.

            // For `a[i]` to be the median, we need to ensure that after deleting `k` elements:
            // 1. There are exactly `median_pos - 1` elements smaller than `a[i]` in the remaining array.
            //    This means we must delete `i - (median_pos - 1)` elements from the `i` smaller elements.
            //    This is only possible if `i >= median_pos - 1`.
            //    The number of elements we *can* delete from the smaller group is `i`.
            //    The number of elements we *can* delete from the larger group is `n - 1 - i`.

            // Let's consider the number of elements we *must* keep.
            // We must keep `median_pos - 1` elements smaller than `a[i]`.
            // We must keep `remaining_len - median_pos` elements larger than `a[i]`.
            // Total elements to keep (excluding `a[i]`) is `remaining_len - 1`.

            // Number of elements smaller than `a[i]` is `i`.
            // Number of elements larger than `a[i]` is `n - 1 - i`.

            // We need to select `median_pos - 1` elements from `i` smaller elements.
            // We need to select `remaining_len - median_pos` elements from `n - 1 - i` larger elements.
            // The total number of elements we *can* delete is `k`.

            // The number of elements we *can* delete from the smaller group is `i`.
            // The number of elements we *can* delete from the larger group is `n - 1 - i`.

            // For `a[i]` to be the median, we need to be able to select `median_pos - 1` elements from the `i` elements smaller than `a[i]`.
            // This is possible if `i >= median_pos - 1`.
            // We also need to be able to select `remaining_len - median_pos` elements from the `n - 1 - i` elements larger than `a[i]`.
            // This is possible if `n - 1 - i >= remaining_len - median_pos`.

            // The number of elements we *must* delete from the smaller group is `i - (median_pos - 1)`.
            // The number of elements we *must* delete from the larger group is `(n - 1 - i) - (remaining_len - median_pos)`.

            // The total number of elements we *can* delete is `k`.
            // We can delete at most `i` elements from the smaller group.
            // We can delete at most `n - 1 - i` elements from the larger group.

            // The number of elements we *can* delete from the smaller group is `i`.
            // The number of elements we *can* delete from the larger group is `n - 1 - i`.

            // For `a[i]` to be the median, we need to be able to delete `k` elements such that:
            // 1. We delete `d_small` elements from the `i` smaller elements, where `0 <= d_small <= i`.
            // 2. We delete `d_large` elements from the `n - 1 - i` larger elements, where `0 <= d_large <= n - 1 - i`.
            // 3. `d_small + d_large = k`.
            // 4. After deletion, `a[i]` is the `median_pos`-th smallest element.
            //    This means `i - d_small = median_pos - 1` (number of remaining smaller elements).
            //    And `(n - 1 - i) - d_large = remaining_len - median_pos` (number of remaining larger elements).

            // From `i - d_small = median_pos - 1`, we get `d_small = i - (median_pos - 1)`.
            // For this to be valid, we need `0 <= d_small <= i`.
            // `0 <= i - median_pos + 1` => `median_pos - 1 <= i`.
            // `i - median_pos + 1 <= i` => `-median_pos + 1 <= 0` => `1 <= median_pos`, which is always true.

            // From `(n - 1 - i) - d_large = remaining_len - median_pos`, we get `d_large = (n - 1 - i) - (remaining_len - median_pos)`.
            // For this to be valid, we need `0 <= d_large <= n - 1 - i`.
            // `0 <= (n - 1 - i) - (remaining_len - median_pos)`
            // `remaining_len - median_pos <= n - 1 - i`
            // `(n - k) - median_pos <= n - 1 - i`
            // `-k - median_pos <= -1 - i`
            // `k + median_pos >= 1 + i`
            // `i <= k + median_pos - 1`.

            // `(n - 1 - i) - (remaining_len - median_pos) <= n - 1 - i`
            // `-(remaining_len - median_pos) <= 0`
            // `remaining_len - median_pos >= 0`
            // `remaining_len >= median_pos`, which is always true since `median_pos = (remaining_len + 1) / 2`.

            // So, the conditions for `a[i]` to be a possible median are:
            // 1. `i >= median_pos - 1` (we must have enough smaller elements to pick `median_pos - 1`)
            // 2. `i <= k + median_pos - 1` (we must not delete too many smaller elements such that we can't form the required `median_pos - 1` smaller elements)
            //    This condition is derived from `d_large >= 0`.
            //    `d_large = (n - 1 - i) - (remaining_len - median_pos)`.
            //    We need `d_large <= n - 1 - i`, which is always true.
            //    We need `d_large >= 0`.
            //    `(n - 1 - i) - (remaining_len - median_pos) >= 0`
            //    `n - 1 - i >= remaining_len - median_pos`
            //    `n - 1 - i >= (n - k) - median_pos`
            //    `n - 1 - i >= n - k - median_pos`
            //    `-1 - i >= -k - median_pos`
            //    `k + median_pos - 1 >= i`
            //    `i <= k + median_pos - 1`.

            // So, the conditions are:
            // `median_pos - 1 <= i <= k + median_pos - 1`

            // Let's verify the number of elements we *can* delete.
            // We need to delete `d_small = i - (median_pos - 1)` from the smaller group.
            // We need to delete `d_large = (n - 1 - i) - (remaining_len - median_pos)` from the larger group.
            // The total number of deletions is `d_small + d_large`.
            // `(i - median_pos + 1) + (n - 1 - i - (n - k - median_pos))`
            // `i - median_pos + 1 + n - 1 - i - n + k + median_pos`
            // `k`.
            // This sum is always `k`.
            // So, if `d_small >= 0` and `d_large >= 0`, then `a[i]` is a possible median.

            // `d_small >= 0` => `i - (median_pos - 1) >= 0` => `i >= median_pos - 1`.
            // `d_large >= 0` => `(n - 1 - i) - (remaining_len - median_pos) >= 0`
            // `n - 1 - i >= remaining_len - median_pos`
            // `n - 1 - i >= (n - k) - median_pos`
            // `n - 1 - i >= n - k - median_pos`
            // `-1 - i >= -k - median_pos`
            // `k + median_pos - 1 >= i`
            // `i <= k + median_pos - 1`.

            // So, `a[i]` is a possible median if `median_pos - 1 <= i <= k + median_pos - 1`.

            int min_idx_for_median = median_pos - 1;
            int max_idx_for_median = k + median_pos - 1;

            if (i >= min_idx_for_median && i <= max_idx_for_median) {
                possible_medians.insert(a[i]);
            }
        }

        bool first = true;
        for (int med : possible_medians) {
            if (!first) {
                std::cout << " ";
            }
            std::cout << med;
            first = false;
        }
        std::cout << "\n";
    }
    return 0;
}