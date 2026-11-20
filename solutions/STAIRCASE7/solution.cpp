#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

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

        // A staircase array has the property A_i - A_{i-1} = 1 for 2 <= i <= |A|.
        // This means A_i = A_1 + (i-1) for 1-indexed array.
        // Or A[i] = A[0] + i for 0-indexed array.
        // So, A[i] - i should be constant for all i.
        // Let's consider the value A[i] - i.
        // If the array is a staircase, then A[i] = A[0] + i.
        // So, A[i] - i = A[0]. This value should be constant.
        // We want to make A[i] - i constant for all i.
        // This is equivalent to finding the most frequent value of A[i] - i.
        // If we choose a target value `k` for A[i] - i, then for each element A[i],
        // if A[i] - i != k, we need to change A[i] to satisfy A[i] - i = k.
        // The new A[i] would be k + i.
        // The number of edits for a chosen `k` would be the count of elements where A[i] - i != k.
        // This is N - (count of elements where A[i] - i == k).
        // To minimize edits, we need to maximize the count of elements where A[i] - i == k.
        // This means we should choose `k` to be the most frequent value of A[i] - i.

        std::map<int, int> diff_counts;
        for (int i = 0; i < n; ++i) {
            diff_counts[a[i] - i]++;
        }

        int max_freq = 0;
        if (n > 0) {
            for (auto const& [diff, count] : diff_counts) {
                if (count > max_freq) {
                    max_freq = count;
                }
            }
        }
        
        // The minimum number of edits is N - max_freq.
        // If N=0, max_freq would be 0, so N-max_freq = 0.
        // But problem constraints say N >= 2.
        std::cout << n - max_freq << "\n";
    }
    return 0;
}