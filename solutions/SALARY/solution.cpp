#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

void solve() {
    int N;
    std::cin >> N;
    
    if (N == 1) {
        int W_val;
        std::cin >> W_val;
        std::cout << 0 << "\n";
        return;
    }

    long long sum_W = 0; 
    int max_W = 0;
    int min_W = 10001; // W_i <= 10000, so 10001 is a safe initial max for min_W

    std::vector<int> W(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> W[i];
        sum_W += W[i];
        if (W[i] > max_W) {
            max_W = W[i];
        }
        if (W[i] < min_W) {
            min_W = W[i];
        }
    }

    // Constraints on the target salary X:
    // 1. X >= max_W (salaries can only increase)
    // 2. X >= sum_W - (N-1) * min_W (derived from k_j >= 0)
    // 3. X = S mod (N-1) (for K to be an integer)

    long long lower_bound_X = std::max((long long)max_W, sum_W - (long long)(N - 1) * min_W);
    
    long long target_remainder = sum_W % (N - 1);
    long long current_lower_bound_remainder = lower_bound_X % (N - 1);

    // Calculate the minimum amount to add to lower_bound_X to satisfy the remainder condition.
    // This formula handles cases where target_remainder < current_lower_bound_remainder
    // by effectively adding (N-1) to the difference before taking modulo.
    long long diff_to_add = (target_remainder - current_lower_bound_remainder + (N - 1)) % (N - 1);
    
    // The minimum possible target salary X
    long long final_X = lower_bound_X + diff_to_add;
    
    // Calculate the minimum number of operations K
    // K = (N*X - S) / (N-1)
    long long min_operations = (N * final_X - sum_W) / (N - 1);

    std::cout << min_operations << "\n";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}