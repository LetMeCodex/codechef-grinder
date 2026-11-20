#include <iostream> // Required for std::cin, std::cout
#include <string>   // Required for std::string
#include <cmath>    // Required for std::abs

void solve() {
    int N; // Length of the match (number of seconds)
    int X, Y; // Bob's initial coordinates
    std::cin >> N >> X >> Y;
    std::string S; // Alice's sequence of moves
    std::cin >> S;

    // Alice's current position, starting at (0,0)
    int alice_x = 0;
    int alice_y = 0;

    bool bob_wins = false; // Flag to track if Bob can win

    // Iterate through each second of the match
    // 'k' represents the 0-indexed move in string S.
    // The (k+1)-th second is completed after Alice makes move S[k].
    for (int k = 0; k < N; ++k) {
        // Alice makes her move based on S[k]
        char move = S[k];
        if (move == 'R') {
            alice_x++;
        } else if (move == 'L') {
            alice_x--;
        } else if (move == 'U') {
            alice_y++;
        } else if (move == 'D') {
            alice_y--;
        }

        // After (k+1) seconds, Alice is at (alice_x, alice_y).
        // Bob started at (X, Y).
        // We need to check if Bob can reach (alice_x, alice_y) in exactly (k+1) seconds.

        // Calculate the Manhattan distance between Bob's starting position and Alice's current position
        int dist_x = std::abs(alice_x - X);
        int dist_y = std::abs(alice_y - Y);
        int manhattan_dist = dist_x + dist_y;
        
        int time_elapsed = k + 1; // The number of seconds that have passed

        // Bob can reach Alice's current position (alice_x, alice_y) from his starting position (X, Y)
        // in exactly 'time_elapsed' seconds if and only if:
        // 1. The Manhattan distance is less than or equal to the time elapsed.
        //    (Bob must have enough time to cover the minimum distance)
        // 2. The parity of the Manhattan distance is the same as the parity of the time elapsed.
        //    (If Bob has extra time (time_elapsed - manhattan_dist), this extra time must be an even number
        //    of steps, allowing him to move back and forth without changing his final position.)
        if (manhattan_dist <= time_elapsed && (manhattan_dist % 2 == time_elapsed % 2)) {
            bob_wins = true;
            break; // Bob can win, no need to check further seconds
        }
    }

    // Output the result for the current test case
    if (bob_wins) {
        std::cout << "Yes\n";
    } else {
        std::cout << "No\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) prevents std::cout from being flushed before each std::cin.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T; // Number of test cases
    std::cin >> T;
    while (T--) {
        solve(); // Solve each test case
    }

    return 0;
}