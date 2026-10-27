#include <iostream> // For std::cin, std::cout
#include <vector>   // For std::vector
#include <numeric>  // For std::accumulate (though not strictly used, sum is manual)
#include <algorithm> // For std::sort, std::min
#include <functional> // For std::greater

// Function to solve a single test case
void solve() {
    int N, M;
    std::cin >> N >> M;

    // Use int for A and B elements as their values (up to 10^6) fit in int.
    // Sums can exceed int max, so sumA and sumB must be long long.
    std::vector<int> A(N);
    std::vector<int> B(M);
    long long sumA = 0;
    long long sumB = 0;

    // Read A packs and calculate initial sumA
    for (int i = 0; i < N; ++i) {
        std::cin >> A[i];
        sumA += A[i];
    }

    // Read B packs and calculate initial sumB
    for (int i = 0; i < M; ++i) {
        std::cin >> B[i];
        sumB += B[i];
    }

    // Sort A in ascending order to easily pick the smallest packs
    std::sort(A.begin(), A.end());
    // Sort B in descending order to easily pick the largest packs
    std::sort(B.begin(), B.end(), std::greater<int>());

    int swaps = 0;
    
    // If John Jackson already has strictly more votes, no swaps needed.
    if (sumA > sumB) {
        std::cout << 0 << "\n";
        return;
    }

    // Iterate through possible swaps. We can perform at most min(N, M) swaps
    // because each swap uses one pack from A and one from B.
    int limit = std::min(N, M); 

    for (int i = 0; i < limit; ++i) {
        // The greedy strategy: swap the smallest pack from A (A[i])
        // with the largest pack from B (B[i]).
        // This swap is beneficial only if A[i] < B[i].
        if (A[i] < B[i]) {
            // Update sums after swapping A[i] and B[i]
            // A[i] moves from John's side to Jack's side (sumA decreases by A[i], sumB increases by A[i])
            // B[i] moves from Jack's side to John's side (sumA increases by B[i], sumB decreases by B[i])
            // Net effect on sumA: -A[i] + B[i]
            // Net effect on sumB: -B[i] + A[i]
            sumA = sumA - A[i] + B[i];
            sumB = sumB - B[i] + A[i];
            swaps++;

            // Check if John Jackson wins after this swap
            if (sumA > sumB) {
                std::cout << swaps << "\n";
                return;
            }
        } else {
            // If A[i] >= B[i], then swapping A[i] with B[i] would not increase
            // John's votes more than it decreases Jack's (or would be detrimental).
            // Since A is sorted ascending and B descending, any subsequent A[j] (j > i)
            // will be >= A[i], and any subsequent B[j] (j > i) will be <= B[i].
            // Thus, A[j] >= B[j] will hold for all j > i.
            // No further beneficial swaps are possible.
            break;
        }
    }

    // If the loop finishes and John Jackson still doesn't have strictly more votes,
    // it's impossible to make him win.
    std::cout << -1 << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t; // Read the number of test cases
    while (t--) {
        solve(); // Solve each test case
    }
    return 0;
}