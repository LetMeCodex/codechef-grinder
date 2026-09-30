#include <iostream>
#include <vector>
#include <numeric> // Not strictly needed, but often included in competitive programming templates

// Function to check if a valid array A (in terms of parities a) exists
// for a given B and an initial guess for a_1.
// As derived, the existence of a solution does not depend on the choice of a1_initial_guess.
// So, we only need to call this function once with either 0 or 1 for a1_initial_guess.
bool check_solution_existence(int N, const std::vector<int>& B, int a1_initial_guess) {
    // 'a' will store the parities of elements of A.
    // a[0] corresponds to A_1 % 2, a[1] to A_2 % 2, ..., a[N-1] to A_N % 2.
    std::vector<int> a(N);
    a[0] = a1_initial_guess; // Set the initial parity for A_1

    // Use the given conditions B_i = (A_i + A_{i+1}) % 2 to determine
    // a_2, a_3, ..., a_N sequentially.
    // In 0-indexed terms: a[i+1] = (B[i] - a[i] + 2) % 2 for i from 0 to N-2.
    for (int i = 0; i < N - 1; ++i) {
        // From a[i] + a[i+1] = B[i] (mod 2), we get a[i+1] = B[i] - a[i] (mod 2).
        // Adding 2 before modulo ensures the result is always non-negative (0 or 1).
        a[i+1] = (B[i] - a[i] + 2) % 2;
    }

    // After determining a[0] through a[N-1], we must check the final condition:
    // B_N = (A_N + A_1) % 2.
    // In 0-indexed terms: B[N-1] = (a[N-1] + a[0]) % 2.
    return (a[N-1] + a[0]) % 2 == B[N-1];
}

void solve() {
    int N;
    std::cin >> N;
    std::vector<int> B(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> B[i];
    }

    // As proven, the existence of a valid array A does not depend on the initial choice
    // of A_1's parity. So, we can just try a_1 = 0. If it works, a solution exists.
    // If it doesn't work, no solution exists (trying a_1 = 1 would also fail).
    if (check_solution_existence(N, B, 0)) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T; // Read the number of test cases
    while (T--) {
        solve(); // Solve each test case
    }

    return 0;
}