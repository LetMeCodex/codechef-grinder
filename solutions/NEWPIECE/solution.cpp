#include <bits/stdc++.h> // Required header as per critical instructions

// Function to solve a single test case
void solve() {
    int A, B, P, Q;
    std::cin >> A >> B >> P >> Q;

    // Case 1: If the starting cell is the same as the destination cell,
    // 0 moves are required.
    if (A == P && B == Q) {
        std::cout << 0 << "\n";
        return;
    }

    // Determine the color of the starting cell (A, B)
    // A cell (i, j) is white if i+j is even, black if i+j is odd.
    // We can use (sum % 2) to represent the color.
    // For example, 0 for white, 1 for black.
    int color_AB = (A + B) % 2;

    // Determine the color of the destination cell (P, Q)
    int color_PQ = (P + Q) % 2;

    // Case 2: If the starting cell and destination cell have different colors,
    // the new piece can move directly from (A, B) to (P, Q) in 1 step,
    // because the rule states it can move to any cell of a different color.
    if (color_AB != color_PQ) {
        std::cout << 1 << "\n";
    } 
    // Case 3: If the starting cell and destination cell have the same color,
    // and they are not the same cell (handled by the first if-condition),
    // the piece cannot move directly in 1 step.
    // It must make an intermediate move.
    // From (A, B) (color C1), it moves to any cell (X, Y) of a different color (C2).
    // From (X, Y) (color C2), it can then move to (P, Q) (color C1),
    // because C1 is different from C2.
    // Since an 8x8 board always has cells of both colors, such an intermediate
    // cell (X, Y) always exists. For example, if (A,B) is white, it can move
    // to (1,2) (black). From (1,2), it can move to (P,Q) (white).
    // Thus, 2 moves are always sufficient and necessary in this case.
    else { // color_AB == color_PQ
        std::cout << 2 << "\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T; // Number of test cases
    std::cin >> T;
    while (T--) {
        solve(); // Call the solve function for each test case
    }

    return 0;
}