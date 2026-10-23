#include <bits/stdc++.h> // Includes iostream, algorithm, etc.

// Using namespace std; is requested
using namespace std;

int main() {
    // Fast I/O as requested
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) {
        long long N, X, Y; // N, X, Y can be up to 10^6. Using long long for safety.
        cin >> N >> X >> Y; // Read board size N, Queen's position (X, Y)

        long long attacked_cells = 0;

        // Calculate horizontal attacks
        // Cells to the left of the Queen (row X, columns 1 to Y-1)
        attacked_cells += (Y - 1);
        // Cells to the right of the Queen (row X, columns Y+1 to N)
        attacked_cells += (N - Y);

        // Calculate vertical attacks
        // Cells above the Queen (rows 1 to X-1, column Y)
        attacked_cells += (X - 1);
        // Cells below the Queen (rows X+1 to N, column Y)
        attacked_cells += (N - X);

        // Calculate diagonal attacks

        // Top-left diagonal: cells (X-k, Y-k)
        // Limited by distance to row 1 (X-1) and column 1 (Y-1)
        attacked_cells += min(X - 1, Y - 1);

        // Top-right diagonal: cells (X-k, Y+k)
        // Limited by distance to row 1 (X-1) and column N (N-Y)
        attacked_cells += min(X - 1, N - Y);

        // Bottom-left diagonal: cells (X+k, Y-k)
        // Limited by distance to row N (N-X) and column 1 (Y-1)
        attacked_cells += min(N - X, Y - 1);

        // Bottom-right diagonal: cells (X+k, Y+k)
        // Limited by distance to row N (N-X) and column N (N-Y)
        attacked_cells += min(N - X, N - Y);

        // Output the total number of attacked cells for the current test case
        cout << attacked_cells << "\n";
    }
    return 0;
}