#include <iostream> // Required for input/output operations

int main() {
    // Optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) prevents std::cout from flushing before std::cin reads input.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T; // Variable to store the number of test cases
    std::cin >> T; // Read the number of test cases

    // Loop through each test case
    while (T--) {
        int N; // Variable to store the size of the chessboard
        std::cin >> N; // Read the value of N for the current test case

        // Determine the minimum moves based on N's parity.
        // The logic is as follows:
        // 1. Every move changes the y-coordinate. To start at y=1 and end at y=1,
        //    the total number of moves must be even.
        // 2. To change x from 1 to N, a net change of N-1 in x is required.
        //    Each move can change x by at most 1. So, at least N-1 moves are needed.
        //
        // If N is odd:
        //   N-1 is even. We need an even number of moves.
        //   We can make N-1 moves, each increasing x by 1 and changing y.
        //   Example for N=3: (1,1) -> (2,2) -> (3,1). This takes 2 moves (N-1).
        //   Since N-1 moves are made, and N-1 is even, the y-coordinate parity
        //   flips an even number of times, ending up with the same parity as start (odd).
        //   So, N-1 moves are sufficient and minimal.
        //
        // If N is even:
        //   N-1 is odd. If we make N-1 moves, the y-coordinate parity will flip
        //   an odd number of times, ending up with the opposite parity as start (even).
        //   To reach y=1 (odd), we need one more move to flip the y-parity again.
        //   This extra move can be a vertical move (x, y+/-1) which doesn't change x.
        //   Example for N=2: (1,1) -> (2,2) (1 move, y is even).
        //   Then (2,2) -> (2,1) (1 more move, y is odd). Total 2 moves (N).
        //   So, N moves are sufficient and minimal.
        //
        // This logic is consistent with the sample cases and general path construction.
        if (N % 2 == 0) {
            std::cout << N << "\n";
        } else {
            std::cout << N - 1 << "\n";
        }
    }

    return 0; // Indicate successful execution
}