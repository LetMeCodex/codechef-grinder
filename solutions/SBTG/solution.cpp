#include <iostream>
#include <vector>
#include <algorithm> // For std::sort, std::lower_bound, std::min
#include <functional> // For std::greater<int>
#include <iterator>   // For std::distance

void solve() {
    int N, X, K;
    std::cin >> N >> X >> K;
    std::vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> A[i];
    }

    // Sort A in descending order.
    // This allows us to easily "sabotage" the K strongest opponents
    // by considering elements from index k onwards in the sorted array.
    std::sort(A.begin(), A.end(), std::greater<int>());

    int min_rank = N + 1; // Initialize with the worst possible rank (all N opponents have higher score + 1)

    // Iterate through all possible number of sabotage operations, from 0 to K.
    for (int k = 0; k <= K; ++k) {
        // Calculate Chef's score after k operations.
        // X can go up to 10000 + 500*100 = 60000, which fits comfortably in an int.
        int current_X = X + k * 100; 
        
        // current_R will store the count of participants with score > current_X.
        int current_R = 0;
        
        // The first k participants (A[0]...A[k-1] in the sorted array) are considered sabotaged.
        // Their scores are effectively 0 and won't be greater than current_X.
        // We only need to consider participants from index k to N-1.
        
        // std::lower_bound with std::greater<int>() comparator finds the first element
        // in the range [A.begin() + k, A.end()) that is less than or equal to current_X.
        // All elements before this iterator in the specified range are strictly greater than current_X.
        auto it = std::lower_bound(A.begin() + k, A.end(), current_X, std::greater<int>());
        
        // The number of such elements is the distance from the start of the considered range to 'it'.
        current_R = std::distance(A.begin() + k, it);
        
        // Update the minimum rank found so far.
        min_rank = std::min(min_rank, current_R + 1);
    }
    std::cout << min_rank << "\n";
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