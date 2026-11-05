#include <bits/stdc++.h> // Includes all standard libraries

// Use standard namespace to avoid writing std::
using namespace std;

// Function to solve a single test case
void solve() {
    int N, K; // Declare N and K
    cin >> N >> K; // Read N and K from input

    // The core logic is based on a property of permutations:
    // It is impossible for a permutation of N elements to have exactly N-1 fixed points.
    //
    // Proof:
    // Assume there are N-1 fixed points. Let these be P_i = i for all i except one index, say 'x'.
    // So, P_j = j for all j != x.
    // Since P is a permutation, the set of values {P_1, P_2, ..., P_N} must be {1, 2, ..., N}.
    // The values {P_j | j != x} are {j | j != x}.
    // This means the value 'x' is not used by any P_j where j != x.
    // The only remaining position is 'x', and the only remaining value is 'x'.
    // Therefore, it must be that P_x = x.
    // This contradicts our assumption that 'x' is not a fixed point (P_x != x).
    // Hence, a permutation cannot have exactly N-1 fixed points.
    //
    // For all other values of K (0 to N, excluding N-1), such a permutation exists:
    // 1. If K = N:
    //    The identity permutation P = [1, 2, ..., N] has N fixed points.
    //    Example: N=3, K=3 -> P=[1,2,3]
    // 2. If K < N-1 (i.e., K <= N-2):
    //    We can construct such a permutation.
    //    Fix the first K elements: P_i = i for i = 1, ..., K.
    //    For the remaining N-K elements (indices K+1, ..., N and values K+1, ..., N),
    //    we need to arrange them such that none are fixed points. This is a derangement problem.
    //    Let M = N-K be the number of elements to derange.
    //    Since K <= N-2, it implies M = N-K >= N-(N-2) = 2.
    //    Derangements exist for any number of elements M >= 2.
    //    For example, a cyclic shift can create a derangement:
    //    P_{K+1} = K+2, P_{K+2} = K+3, ..., P_{N-1} = N, P_N = K+1.
    //    This arrangement ensures that none of the elements from K+1 to N are fixed points.
    //    Thus, such a permutation exists.
    //    Example: N=3, K=0 -> P=[2,3,1] (derangement of 3 elements)
    //    Example: N=3, K=1 -> P=[1,3,2] (fix 1, derange 2 and 3)
    //
    // Based on this, the condition is simply: if K is N-1, output "No", otherwise output "Yes".
    if (K == N - 1) {
        cout << "No\n"; // Output "No" if K is N-1
    } else {
        cout << "Yes\n"; // Output "Yes" for all other K values
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common competitive programming optimization.
    ios_base::sync_with_stdio(false); // Untie C++ streams from C standard streams
    cin.tie(NULL); // Untie cin from cout

    int T; // Declare T for the number of test cases
    cin >> T; // Read the number of test cases
    while (T--) { // Loop T times, decrementing T each iteration
        solve(); // Call the solve function for each test case
    }

    return 0; // Indicate successful execution
}