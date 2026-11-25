#include <iostream> // Required for standard input/output operations (cin, cout)

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin/cout from C's stdio and prevents flushing cout before cin.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T; // Declare an integer variable T to store the number of test cases.
    std::cin >> T; // Read the value of T from standard input.

    // Loop T times, once for each test case.
    while (T--) {
        int X1, Y1, X2, Y2; // Declare integer variables for the coordinates.
        // Read the starting coordinates (X1, Y1) and ending coordinates (X2, Y2).
        std::cin >> X1 >> Y1 >> X2 >> Y2;

        // A knight's move always changes the color of the square it is on.
        // The color of a square (x, y) can be determined by the parity of (x + y).
        // If (x + y) is even, it's one color. If (x + y) is odd, it's the other color.

        // After an even number of moves (like 100), the knight must end up on a square
        // of the same color as its starting square.
        // This means the parity of (X1 + Y1) must be the same as the parity of (X2 + Y2).

        // Check if the parities match.
        // (X1 + Y1) % 2 gives 0 if the sum is even, and 1 if the sum is odd.
        if ((X1 + Y1) % 2 == (X2 + Y2) % 2) {
            // If the parities match, the squares are of the same color.
            // On an 8x8 board, any two squares of the same color are reachable by a knight.
            // The maximum number of moves required between any two squares is 6.
            // Since 100 is an even number, and the minimum moves M will also be even
            // (because start and end squares have the same color), we can always reach
            // the target in exactly 100 moves. We can "waste" (100 - M) moves by
            // repeatedly moving back and forth between the target square and one of its
            // adjacent squares (in terms of knight moves). Since (100 - M) is even,
            // this strategy works. Every square on an 8x8 board has at least two
            // valid knight moves, so moving away and back is always possible.
            std::cout << "YES\n";
        } else {
            // If the parities do not match, the squares are of different colors.
            // It's impossible to reach a square of a different color in an even number of moves.
            std::cout << "NO\n";
        }
    }

    return 0; // Indicate successful program execution.
}