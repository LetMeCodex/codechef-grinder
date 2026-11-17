#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>

using namespace std;

int solve() {
    int n;
    cin >> n;
    vector<int> c(n);
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }

    if (n == 1) {
        return c[0];
    }
    if (n == 2) {
        return max(c[0], c[1]);
    }
    if (n == 3) {
        sort(c.begin(), c.end());
        // Option 1: Put c[2] on burner 1, c[1] on burner 2.
        // When c[1] finishes, put c[0] on burner 2.
        // Time = max(c[2], c[1] + c[0])
        // Option 2: Put c[0] and c[1] on burners. When one finishes, put c[2] on it.
        // Time = max(c[0], c[1], c[2]) if c[0]+c[1] >= c[2]
        // Time = max(c[0], c[1]) + c[2] if c[0]+c[1] < c[2]
        // This is equivalent to max(c[0]+c[1], c[2]) if we consider the total time on one burner.
        // The actual minimum time is achieved by distributing tasks.
        // The optimal strategy for N=3 is to put the two largest dishes on separate burners,
        // and then the smallest dish can be placed on the burner that finishes earlier.
        // Let the sorted costs be c0, c1, c2.
        // Burner 1: c2
        // Burner 2: c1
        // When c1 finishes at time c1, put c0 on burner 2.
        // Total time = max(c2, c1 + c0)
        return max(c[2], c[0] + c[1]);
    }

    // For N=4, we can iterate through all possible assignments of dishes to burners.
    // Since N is small (up to 4), we can use bit manipulation or recursion to explore assignments.
    // A dish can be assigned to burner 1 or burner 2.
    // We can represent an assignment as a bitmask of length N, where the i-th bit
    // indicates which burner dish i is assigned to (0 for burner 1, 1 for burner 2).
    // However, this doesn't account for the order.
    // A better approach is to partition the N dishes into two sets, one for each burner.
    // The total time will be the maximum of the sum of costs in each set.
    // We need to find a partition that minimizes this maximum sum.

    int min_max_sum = -1;

    // Iterate through all possible subsets of dishes for burner 1.
    // The remaining dishes go to burner 2.
    // There are 2^N subsets. For N=4, 2^4 = 16 subsets.
    // We only need to consider subsets up to N/2 because the partition {A, B} is the same as {B, A}.
    // So we iterate from 0 to 2^(N-1) - 1.
    for (int i = 0; i < (1 << (n - 1)); ++i) {
        long long sum1 = 0;
        long long sum2 = 0;

        // Dish 0 is always assigned to burner 1 to avoid duplicate partitions.
        sum1 += c[0];

        for (int j = 1; j < n; ++j) {
            if ((i >> (j - 1)) & 1) { // If the j-th bit is set, assign dish j to burner 2
                sum2 += c[j];
            } else { // Otherwise, assign dish j to burner 1
                sum1 += c[j];
            }
        }
        
        int current_max_sum = max(sum1, sum2);
        if (min_max_sum == -1 || current_max_sum < min_max_sum) {
            min_max_sum = current_max_sum;
        }
    }

    return min_max_sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        cout << solve() << "\n";
    }

    return 0;
}