#include <iostream> // Required for standard input/output operations (cin, cout)

int main() {
    // Optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) prevents cin from flushing cout before each input operation.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T; // Variable to store the number of test cases
    std::cin >> T; // Read the number of test cases

    // Loop through each test case
    while (T--) {
        long long N, M; // N: number of nominated members, M: total number of voters
                        // Using long long for N and M as they can be up to 10^9
        std::cin >> N >> M; // Read N and M for the current test case

        // Problem: Find the minimum number of votes Om requires to ensure a strict majority win.
        // A strict majority win means Om must have strictly more votes than any other nominee.
        // Let V_Om be the number of votes Om receives.
        // Let V_i be the votes for any other nominee i.
        // We need V_Om > V_i for all other nominees i.

        // To "ensure" this, we must consider the worst-case scenario for Om.
        // The worst-case scenario is when the other nominees try to maximize
        // the votes of one of their members to challenge Om.
        
        // If Om gets V_Om votes, then M - V_Om votes are remaining to be distributed
        // among the N-1 other nominees.
        
        // Since N >= 2 (as per constraints), there is at least one other nominee (N-1 >= 1).
        // In the worst case, all M - V_Om remaining votes could be given to a single
        // one of the other N-1 nominees.
        // Let's call this maximum possible votes for an opponent V_opponent_max.
        // V_opponent_max = M - V_Om.

        // For Om to ensure a strict majority win, Om's votes must be strictly greater
        // than V_opponent_max.
        // So, we need:
        // V_Om > M - V_Om

        // Now, solve for V_Om:
        // 2 * V_Om > M
        // V_Om > M / 2

        // Since V_Om must be an integer (number of votes), the smallest integer
        // that satisfies V_Om > M / 2 is floor(M / 2) + 1.
        // In C++ integer division, M / 2 automatically computes floor(M / 2) for positive M.
        long long required_votes = M / 2 + 1;

        // Output the result for the current test case, followed by a newline.
        std::cout << required_votes << "\n";
    }

    return 0; // Indicate successful execution
}