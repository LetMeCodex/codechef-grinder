#include <cstdio> // Required for scanf, printf

// No need for 'using namespace std;' when using cstdio functions

void solve() {
    int X1, Y1, X2, Y2;
    // Use scanf for faster input
    scanf("%d %d %d %d", &X1, &Y1, &X2, &Y2);

    // Step 1: Check if the squares are of the same color.
    // Bishops always stay on squares of the same color.
    // If the starting and ending squares have different colors, it's impossible to reach.
    if ((X1 + Y1) % 2 != (X2 + Y2) % 2) {
        // Use printf for faster output
        printf("-1\n");
        return;
    }

    // Step 2: If they are of the same color, check for 1 move.
    // A bishop can reach any square on the same diagonal in 1 move.
    // There are two types of diagonals:
    // 1. Where x + y is constant.
    // 2. Where x - y is constant.
    if (X1 + Y1 == X2 + Y2 || X1 - Y1 == X2 - Y2) {
        printf("1\n");
        return;
    }

    // Step 3: If they are of the same color and not reachable in 1 move, they are reachable in 2 moves.
    // This is a known property for bishops on a standard chessboard.
    // An intermediate square always exists within the board boundaries (1 to 8).
    // The bishop can move from (X1, Y1) to an intermediate square (Xm, Ym) along one diagonal type,
    // and then from (Xm, Ym) to (X2, Y2) along the other diagonal type.
    printf("2\n");
}

int main() {
    // No need for ios_base::sync_with_stdio(false); cin.tie(NULL); with scanf/printf
    
    int T;
    scanf("%d", &T); // Read the number of test cases
    while (T--) { // Loop through each test case
        solve(); // Call the function to solve the current test case
    }

    return 0; // Indicate successful execution
}