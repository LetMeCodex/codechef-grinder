#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        long long l, k;
        std::cin >> l >> k;

        // We want to minimize sum(|A_{i+1} - A_i|) where A_i are positive integers
        // and sum(A_i) = L.
        // To minimize the absolute differences, we want the lengths A_i to be as close
        // to each other as possible.
        // The ideal scenario would be to have all A_i equal to L/K.
        // Since A_i must be positive integers, we can distribute L into K parts.
        // Let L = q*K + r, where q = L/K (integer division) and r = L%K.
        // We can have r parts of length q+1 and K-r parts of length q.
        // The sum of lengths will be r*(q+1) + (K-r)*q = r*q + r + K*q - r*q = K*q + r = L.
        // All parts will be positive integers because K <= L, so q = L/K >= 1.
        //
        // The sequence of lengths would look like:
        // [q+1, q+1, ..., q+1 (r times), q, q, ..., q (K-r times)]
        // or any permutation of these.
        //
        // To minimize the sum of absolute differences, we should arrange the parts
        // such that the differences are minimized. The best arrangement is to group
        // the larger parts together and the smaller parts together.
        // For example: [q+1, ..., q+1, q, ..., q] or [q, ..., q, q+1, ..., q+1].
        //
        // Consider the sequence: [q+1, q+1, ..., q+1 (r times), q, q, ..., q (K-r times)]
        // The differences are:
        // |(q+1) - (q+1)| = 0 for the first r-1 pairs.
        // |q - (q+1)| = 1 for the pair between the last q+1 and the first q.
        // |q - q| = 0 for the remaining K-r-1 pairs.
        //
        // The total sum of differences is 0 * (r-1) + 1 + 0 * (K-r-1) = 1, if r > 0.
        // If r = 0, then all parts are of length q, and the sequence is [q, q, ..., q].
        // The differences are all |q - q| = 0.
        //
        // So, if L is perfectly divisible by K (r=0), the minimum sum is 0.
        // If L is not perfectly divisible by K (r>0), the minimum sum is 1.
        //
        // This holds true as long as K >= 2. The problem statement guarantees K >= 2.
        // Also, A_i must be positive integers. Since K <= L, L/K >= 1, so q >= 1.
        // Thus, q and q+1 are always positive integers.

        if (l % k == 0) {
            std::cout << 0 << "\n";
        } else {
            std::cout << 1 << "\n";
        }
    }
    return 0;
}