#include <bits/stdc++.h> // Includes all standard libraries

// Use the standard namespace to avoid prefixing std::
using namespace std;

void solve() {
    long long W, L; // W and L can be up to 10^9. long long is used to safely store these values.
                    // For parity checks, 'int' would also be sufficient as 10^9 fits in int.
    cin >> W >> L;

    // A tile (w_i, h_i) is valid if its perimeter 2*(w_i + h_i) is not divisible by 4.
    // This condition simplifies to (w_i + h_i) being an odd number.
    // For (w_i + h_i) to be odd, w_i and h_i must have different parities (one even, one odd).
    // If w_i and h_i have different parities, then their product w_i * h_i (the area of the tile)
    // is always an even number (e.g., even * odd = even).

    // The total area of the floor W * L must be covered by these tiles.
    // Since each individual tile must have an even area, the sum of their areas (W * L) must also be even.
    // If W * L is odd, it's impossible to tile the floor with such tiles.
    // W * L is odd if and only if both W and L are odd.
    // Therefore, if both W and L are odd, the answer is NO.

    // If W * L is even, then at least one of W or L must be an even number.
    // In this scenario, a tiling is always possible:
    // Case 1: W is even (and L can be either odd or even).
    //   If L is odd: We can use a single tile of dimensions W x L.
    //     Its width W (even) and height L (odd) have different parities, making it a valid tile.
    //     So, a single W x L tile can cover the floor.
    //   If L is even: We can tile the W x L floor with W tiles, each of dimensions 1 x L.
    //     For each 1 x L tile: its width is 1 (odd) and its height is L (even).
    //     Since 1 and L have different parities, each 1 x L tile is valid.
    //     Placing W such tiles side-by-side perfectly covers the W x L floor.
    // Case 2: L is even (and W is odd). This is symmetric to Case 1.
    //   We can use a single W x L tile (W odd, L even) or L tiles of W x 1 dimensions.

    // In summary, if at least one of W or L is even, it's possible to tile the floor.
    // This condition is checked by (W % 2 == 0 || L % 2 == 0).
    if (W % 2 == 0 || L % 2 == 0) {
        cout << "YES\n";
    } else {
        // Both W and L are odd
        cout << "NO\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common competitive programming optimization.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Variable to store the number of test cases
    cin >> T; // Read the number of test cases
    while (T--) { // Loop T times, decrementing T in each iteration
        solve(); // Call the solve function for each test case
    }

    return 0; // Indicate successful execution
}