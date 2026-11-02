#include <bits/stdc++.h> // Includes iostream, vector, string, etc.

// Using namespace std; is common in competitive programming for brevity.
using namespace std;

void solve() {
    int K;
    cin >> K;

    // Create an 8x8 chessboard.
    // Initialize all cells to 'X' (obstacles).
    vector<string> board(8, string(8, 'X'));

    // Place the king at the top-left corner (0,0).
    board[0][0] = 'O';

    // We need K total reachable cells. Since one is 'O',
    // we need to mark K-1 additional cells as empty ('.').
    int cells_to_fill = K - 1;

    // Iterate through the board in row-major order.
    // Mark cells as '.' until K cells are accounted for.
    for (int r = 0; r < 8; ++r) {
        for (int c = 0; c < 8; ++c) {
            // If we have already marked K cells (1 'O' + K-1 '.'), stop.
            if (cells_to_fill == 0) {
                break;
            }

            // Skip the king's initial position, as it's already 'O'.
            if (r == 0 && c == 0) {
                continue;
            }

            // Mark the current cell as empty (reachable).
            board[r][c] = '.';
            cells_to_fill--;
        }
        // If we have already marked K cells, break from the outer loop too.
        if (cells_to_fill == 0) {
            break;
        }
    }

    // Print the resulting chessboard.
    for (int r = 0; r < 8; ++r) {
        cout << board[r] << "\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases.
    while (T--) {
        solve(); // Solve each test case.
    }

    return 0;
}