#include <iostream> // For std::cin, std::cout
#include <string>   // For std::string
#include <vector>   // Not strictly needed for this solution, but often useful
#include <algorithm> // Not strictly needed for this solution, but often useful (e.g., std::reverse)

void solve() {
    int N;
    std::cin >> N;
    std::string A;
    std::cin >> A;

    // Check if string A consists of all 'z's.
    // If A is "zz...z" (N times), then no string S of length N can be lexicographically
    // larger than A, because "zz...z" is the lexicographically largest possible string
    // of length N using lowercase English letters.
    // In this case, S > A is impossible, and thus reverse(S) > A is also impossible.
    // So, if A is all 'z's, no solution exists.
    bool all_z = true;
    for (char c : A) {
        if (c != 'z') {
            all_z = false;
            break; // Found a character not 'z', so A is not all 'z's.
        }
    }

    if (all_z) {
        std::cout << -1 << "\n";
    } else {
        // If A is not all 'z's, we can construct a valid string S.
        // The simplest valid string is one consisting of N 'z's.
        // Let S = "zz...z" (N times).
        //
        // Condition 1: S must be lexicographically larger than A.
        // Since A is not all 'z's, there must be at least one character in A that is not 'z'.
        // Let k be the first index (0-indexed) such that A[k] != 'z'.
        // This means A[0...k-1] are all 'z's.
        // For our constructed string S, S[j] = 'z' for all j from 0 to N-1.
        // So, for j < k, S[j] = 'z' and A[j] = 'z', meaning S[j] == A[j].
        // At index k, S[k] = 'z' and A[k] is some character less than 'z'.
        // Therefore, S[k] > A[k].
        // By the definition of lexicographical comparison, S is lexicographically larger than A.
        //
        // Condition 2: reverse(S) must be lexicographically larger than A.
        // If S consists of N 'z's, then reverse(S) is also "zz...z" (N times).
        // So, reverse(S) == S.
        // Since we already proved S > A, it directly follows that reverse(S) > A.
        //
        // Both conditions are satisfied.
        for (int i = 0; i < N; ++i) {
            std::cout << 'z';
        }
        std::cout << "\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T; // Read the number of test cases
    while (T--) {
        solve(); // Solve each test case
    }

    return 0;
}