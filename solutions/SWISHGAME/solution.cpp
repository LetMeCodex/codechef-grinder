#include <iostream>
#include <string>
#include <algorithm> // For std::count, though a manual loop is also fine

void solve() {
    int M, K;
    std::cin >> M >> K;
    std::string S;
    std::cin >> S;

    int swishes_M = 0;
    // Count the total number of 'S' (swishes) in the string S
    for (char c : S) {
        if (c == 'S') {
            swishes_M++;
        }
    }

    // Case 1: Toofan has already achieved K swishes or more.
    // If swishes_M >= K, Toofan has won. The game must have ended
    // because all N rings were finished. If there were rings left (M < N),
    // the game would continue even after winning until all N rings are played.
    // So, if the game ended after M moves, it means M = N.
    if (swishes_M >= K) {
        std::cout << M << "\n";
    } else {
        // Case 2: Toofan has less than K swishes (swishes_M < K).
        // The game must have ended because it became impossible to win,
        // or because all N rings were finished (and he still hadn't won).
        //
        // Let N be the total number of rings.
        // The game ended after M moves.
        //
        // If M < N, the game ended because it became impossible to win:
        // swishes_M + (N - M) < K
        // This implies N < M + K - swishes_M.
        // The maximum integer N satisfying this is M + K - swishes_M - 1.
        //
        // If M = N, the game ended because all rings were finished.
        // In this scenario, swishes_M + (N - M) = swishes_M. Since swishes_M < K,
        // the impossibility condition (swishes_M < K) is also met.
        // This case occurs when swishes_M = K-1, and the formula
        // M + K - swishes_M - 1 simplifies to M + K - (K-1) - 1 = M.
        //
        // The problem guarantees a unique N. This means the derived value
        // N = M + K - swishes_M - 1 must be the correct answer, and it
        // implicitly satisfies all conditions (e.g., game not ending prematurely).
        std::cout << M + K - swishes_M - 1 << "\n";
    }
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