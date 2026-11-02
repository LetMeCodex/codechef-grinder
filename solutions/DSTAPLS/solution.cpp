#include <iostream>

int main() {
    // Optimize C++ standard streams for faster input/output.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T; // Read the number of test cases.
    while (T--) {
        long long N, K;
        std::cin >> N >> K; // Read N and K for each test case.

        // Candidate 1: Distributes N apples evenly among K boxes.
        // Each box will end up with N/K apples.
        // This is a uniform distribution: [N/K, N/K, ..., N/K] (K times).

        // Candidate 2: Performs N/K operations. In each operation, puts K apples
        // into a box that currently has the minimum number of apples.
        // Let Q be the total number of operations, Q = N/K.
        // Candidate 2 effectively distributes Q "chunks" of K apples among K boxes.
        // To keep the distribution as balanced as possible, Candidate 2 will ensure:
        // - (Q % K) boxes receive (Q / K + 1) chunks, meaning (Q / K + 1) * K apples.
        // - (K - Q % K) boxes receive (Q / K) chunks, meaning (Q / K) * K apples.

        // The distributions are different if Candidate 2's distribution is not uniform.
        // Candidate 2's distribution is uniform if and only if Q % K == 0.
        // If Q % K == 0:
        //   All boxes for Candidate 2 will have (Q / K) * K = Q apples.
        //   Since Q = N/K, this means all boxes have N/K apples, which is identical to Candidate 1's distribution.
        //   In this case, the distributions are the same.
        // If Q % K != 0:
        //   Candidate 2's distribution will involve at least two different apple counts
        //   ((Q / K + 1) * K and (Q / K) * K). This is a non-uniform distribution.
        //   Since Candidate 1 always produces a uniform distribution, these two distributions will be different.
        //   In this case, the distributions are different.

        long long Q = N / K; // Calculate the number of K-apple chunks.

        if (Q % K == 0) {
            std::cout << "NO\n"; // Distributions are the same.
        } else {
            std::cout << "YES\n"; // Distributions can be different.
        }
    }
    return 0;
}