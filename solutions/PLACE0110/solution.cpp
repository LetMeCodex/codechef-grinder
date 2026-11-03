#include <iostream>
#include <algorithm> // Required for std::max

void solve() {
    int X, Y;
    std::cin >> X >> Y;

    int result;
    if (X == Y) {
        // If X equals Y, we can perfectly alternate "01" and "10" strings.
        // For example, "01", "10", "01", "10", ...
        // All junctions between strings will be "01"+"10" or "10"+"01",
        // which do not add any extra flips.
        // The total flips will only be the internal flips of each string.
        // Each "01" has 1 flip, each "10" has 1 flip.
        // So, total flips = X + Y.
        result = X + Y;
    } else {
        // If X is not equal to Y, one type of string is more numerous.
        // Let's say X > Y. We can form an alternating sequence using all Y "10"s
        // and Y+1 "01"s (e.g., "01", "10", "01", ..., "01").
        // This part has (Y+1) + Y = 2Y+1 strings, and all 2Y junctions are between
        // different types, adding 0 flips. The internal flips are 2Y+1.
        // We are left with X - (Y+1) "01" strings. These must be appended to the end
        // of the sequence, which is a "01". So we get "01"+"01" junctions.
        // Each such junction adds 1 flip. There are X - (Y+1) such junctions.
        // Total flips = (2Y+1) + (X - (Y+1)) = 2Y+1 + X - Y - 1 = X + Y.
        // This is the total number of flips from internal flips (X+Y) plus the
        // additional flips (X-Y-1).
        // So, total flips = (X+Y) + (X-Y-1) = 2X-1.
        // Symmetrically, if Y > X, the total flips = 2Y-1.
        // In general, this is 2 * max(X, Y) - 1.
        result = 2 * std::max(X, Y) - 1;
    }

    std::cout << result << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t; // Read the number of test cases
    while (t--) {
        solve(); // Solve each test case
    }

    return 0;
}