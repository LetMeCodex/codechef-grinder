#include <iostream> // Required for standard input/output operations (cin, cout)
#include <cmath>    // Required for std::abs

void solve() {
    int A, B, C, M;
    std::cin >> A >> B >> C >> M;

    // The problem asks if it's possible for at least two players to end up with the same score.
    // Let the initial scores be A, B, C and M be the number of additional matches.
    // In each match, one point is awarded to a winner.
    // Let xA, xB, xC be the points won by Alice, Bob, and Cameron respectively.
    // We must have xA, xB, xC >= 0 and xA + xB + xC = M.
    // The final scores will be A' = A + xA, B' = B + xB, C' = C + xC.

    // Consider if it's possible for Alice and Bob to have the same final score (A' = B').
    // A + xA = B + xB  =>  xB - xA = A - B.
    // The maximum value xB - xA can take is M (if Bob wins all M matches, Alice wins 0).
    // The minimum value xB - xA can take is -M (if Alice wins all M matches, Bob wins 0).
    // So, for A' = B' to be possible, the difference A - B must be within the range [-M, M].
    // This is equivalent to |A - B| <= M.
    // If |A - B| <= M, we can always find non-negative xA, xB, xC that sum to M and make A' = B'.
    // (e.g., if A >= B, set xA=0, xB=A-B, xC=M-(A-B); if B > A, set xA=B-A, xB=0, xC=M-(B-A)).

    // The same logic applies to any pair of players:
    // - A' = B' is possible if and only if |A - B| <= M.
    // - B' = C' is possible if and only if |B - C| <= M.
    // - A' = C' is possible if and only if |A - C| <= M.

    // We need to output "YES" if any of these conditions are met, and "NO" otherwise.
    if (std::abs(A - B) <= M || std::abs(B - C) <= M || std::abs(A - C) <= M) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; // Number of test cases
    std::cin >> t;
    while (t--) {
        solve(); // Call the solve function for each test case
    }

    return 0;
}