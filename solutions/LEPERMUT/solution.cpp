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

        // A permutation is "good" if the number of inversions equals the number of local inversions.
        // An inversion is a pair (i, j) such that i < j and A[i] > A[j].
        // A local inversion is an index i such that A[i] > A[i+1].
        //
        // Consider an inversion (i, j) where A[i] > A[j].
        // If j = i + 1, then this inversion is also a local inversion.
        // If j > i + 1, then this inversion is NOT a local inversion.
        //
        // For the number of inversions to equal the number of local inversions,
        // every inversion must be a local inversion.
        // This means that for any pair (i, j) with i < j and A[i] > A[j],
        // it must be the case that j = i + 1.
        //
        // In other words, if A[i] > A[j] for some i < j, then it must be that j = i + 1.
        // This implies that if A[i] > A[j] for i < j, then A[i] must be greater than A[i+1], A[i+2], ..., A[j].
        //
        // Let's rephrase: if there is an inversion (i, j) where j > i + 1,
        // then the permutation is NOT good.
        //
        // This means that for any element A[i], all elements A[j] with j > i + 1
        // must be smaller than A[i].
        //
        // Equivalently, for any element A[i], all elements A[j] with j < i - 1
        // must be larger than A[i].
        //
        // Consider an element A[i]. If A[i] is greater than some element A[j] where j > i + 1,
        // then this is an inversion (i, j) which is not a local inversion.
        //
        // So, a permutation is good if and only if for every i,
        // A[i] is NOT greater than any A[j] where j > i + 1.
        //
        // This condition is equivalent to saying that for every i,
        // A[i] must be less than or equal to all elements A[j] where j > i + 1.
        //
        // Let's consider the elements from left to right.
        // For A[0], we need A[0] <= A[2], A[0] <= A[3], ..., A[0] <= A[n-1].
        // For A[1], we need A[1] <= A[3], A[1] <= A[4], ..., A[1] <= A[n-1].
        // ...
        // For A[i], we need A[i] <= A[i+2], A[i] <= A[i+3], ..., A[i] <= A[n-1].
        //
        // This is equivalent to checking if for every i, A[i] is less than or equal to the minimum
        // of the elements A[i+2], A[i+3], ..., A[n-1].
        //
        // However, a simpler observation is:
        // If A[i] > A[j] for some j > i + 1, then this is an inversion that is not a local inversion.
        // This means the number of inversions will be strictly greater than the number of local inversions.
        //
        // So, the condition for a "good" permutation is that there are NO inversions (i, j)
        // where j > i + 1.
        //
        // This means for every i, A[i] must be less than or equal to all A[j] where j > i + 1.
        //
        // Let's check this condition directly.
        // For each element A[i], we need to check if it's greater than any element A[j] where j >= i + 2.
        // If we find such a pair, the permutation is not good.
        // If we iterate through all i and don't find such a pair, the permutation is good.

        bool is_good = true;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 2; j < n; ++j) {
                if (a[i] > a[j]) {
                    is_good = false;
                    break;
                }
            }
            if (!is_good) {
                break;
            }
        }

        if (is_good) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
    return 0;
}