#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<long long> a(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
        }
        std::sort(a.begin(), a.end());

        // We can delete at most two elements.
        // The goal is to minimize max(A) - min(A).
        // After sorting, the minimum element is a[0] and the maximum is a[n-1].
        // To minimize the range, we should try to remove elements that are
        // either very small or very large.

        // Case 1: Delete 0 elements.
        // Range is a[n-1] - a[0].

        // Case 2: Delete 1 element.
        // If we delete a[0], the range is a[n-1] - a[1].
        // If we delete a[n-1], the range is a[n-2] - a[0].
        // We want the minimum of these two.

        // Case 3: Delete 2 elements.
        // There are three main scenarios for deleting two elements to minimize range:
        // a) Delete the two smallest elements: a[0] and a[1]. The remaining range is a[n-1] - a[2].
        // b) Delete the two largest elements: a[n-1] and a[n-2]. The remaining range is a[n-3] - a[0].
        // c) Delete one smallest and one largest element: a[0] and a[n-1]. The remaining range is a[n-2] - a[1].

        // We need to find the minimum among all these possibilities.
        // Since N >= 3, all indices used (0, 1, 2, n-3, n-2, n-1) are valid.

        long long min_range = LLONG_MAX;

        // Option 1: Delete 0 elements
        min_range = std::min(min_range, a[n - 1] - a[0]);

        // Option 2: Delete 1 element
        // Delete smallest
        min_range = std::min(min_range, a[n - 1] - a[1]);
        // Delete largest
        min_range = std::min(min_range, a[n - 2] - a[0]);

        // Option 3: Delete 2 elements
        // Delete two smallest
        min_range = std::min(min_range, a[n - 1] - a[2]);
        // Delete two largest
        min_range = std::min(min_range, a[n - 3] - a[0]);
        // Delete one smallest and one largest
        min_range = std::min(min_range, a[n - 2] - a[1]);

        std::cout << min_range << "\n";
    }
    return 0;
}