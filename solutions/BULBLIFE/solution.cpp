#include <bits/stdc++.h> // Includes common libraries like iostream, algorithm, etc.

void solve() {
    int N; // Number of test bulbs
    int X; // Minimum average lifetime claimed
    std::cin >> N >> X;

    long long sum_A = 0; // Use long long for the sum to prevent potential overflow,
                         // although for these constraints, int would also suffice.
    for (int i = 0; i < N - 1; ++i) {
        int A_i; // Lifetime of one of the N-1 bulbs
        std::cin >> A_i;
        sum_A += A_i;
    }

    // Calculate the minimum total sum required for all N bulbs to meet the average X.
    // This is N * X.
    long long required_total_sum = (long long)N * X; 

    // Calculate the minimum lifetime Y for the remaining bulb.
    // Y must be at least (required_total_sum - sum_A).
    long long min_Y_candidate = required_total_sum - sum_A;
    
    // The lifetime Y must also be non-negative.
    // So, the final minimum non-negative lifetime for Y is max(0, min_Y_candidate).
    std::cout << std::max(0LL, min_Y_candidate) << "\n"; 
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T; // Number of test cases
    std::cin >> T;
    while (T--) {
        solve(); // Call the solve function for each test case
    }

    return 0;
}