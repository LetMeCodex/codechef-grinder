#include <bits/stdc++.h> // Includes common C++ headers

// Use the standard namespace to avoid prefixing std::
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) prevents std::cout from being flushed before each std::cin operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Variable to store the number of test cases
    cin >> T; // Read the number of test cases

    // Loop through each test case
    while (T--) {
        long long N; // N can be up to 10^9. Calculations involving N might exceed
                     // the capacity of a 32-bit integer, so long long is used.
        cin >> N; // Read the number of teams for the current test case

        long long result; // Variable to store the calculated maximum difference

        // The strategy to maximize the difference is:
        // 1. The winning team (Team A) wins all its games.
        //    Team A plays N-1 games, so P_A = 3 * (N-1) points.
        // 2. The second-placed team (Team B) should have the minimum possible score
        //    while still being the second-highest. This is achieved by distributing
        //    points as evenly as possible among the remaining N-1 teams (excluding Team A).
        //    All N-1 teams lost to Team A. These N-1 teams play a round-robin among themselves.
        //    Let K = N-1. Each of these K teams plays K-1 = N-2 games.
        //    The minimum possible maximum score for a team in a K-team round-robin
        //    is 3 * ceil((K-1)/2) = 3 * ceil((N-2)/2).

        if (N % 2 == 0) {
            // Case 1: N is even.
            // N-2 is even. So, ceil((N-2)/2) = (N-2)/2.
            // P_2 = 3 * (N-2)/2.
            // Difference = P_A - P_2 = 3*(N-1) - 3*(N-2)/2
            //            = (6*(N-1) - 3*(N-2)) / 2
            //            = (6N - 6 - 3N + 6) / 2
            //            = 3N / 2
            result = (3 * N) / 2;
        } else {
            // Case 2: N is odd.
            // N-2 is odd. So, ceil((N-2)/2) = (N-2+1)/2 = (N-1)/2.
            // P_2 = 3 * (N-1)/2.
            // Difference = P_A - P_2 = 3*(N-1) - 3*(N-1)/2
            //            = (6*(N-1) - 3*(N-1)) / 2
            //            = 3*(N-1) / 2
            result = (3 * (N - 1)) / 2;
        }
        
        // Output the result for the current test case, followed by a newline.
        cout << result << "\n";
    }

    return 0; // Indicate successful execution
}