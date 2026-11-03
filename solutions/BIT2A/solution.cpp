#include <iostream>
#include <vector>
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

        std::vector<int> b(n);
        for (int i = 0; i < n; ++i) {
            // Since the list A is sorted, all elements strictly greater than A[i]
            // will appear after the last occurrence of A[i].
            // We can find the first element strictly greater than A[i] using std::upper_bound.
            // The number of elements strictly greater than A[i] will be the total number of elements
            // minus the index of the first element strictly greater than A[i].
            auto it = std::upper_bound(a.begin(), a.end(), a[i]);
            b[i] = std::distance(it, a.end());
        }

        for (int i = 0; i < n; ++i) {
            std::cout << b[i] << (i == n - 1 ? "" : " ");
        }
        std::cout << "\n";
    }
    return 0;
}