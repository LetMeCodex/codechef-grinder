#include <iostream> // Required for standard input/output operations

void solve() {
    int X, Y; // X: total people, Y: infected people
    std::cin >> X >> Y; // Read X and Y for the current test case
    
    int N; // Minimum number of rooms
    
    if (Y == 0) {
        // Case 1: No infected people.
        // All X people are uninfected. They can be placed in X contiguous rooms.
        // Example: N N N N for X=4, Y=0.
        N = X;
    } else {
        // Case 2: There are infected people (Y > 0).
        // Infected people must be separated by at least one empty room.
        // The most compact arrangement for Y infected people is C _ C _ ... _ C.
        // This arrangement uses 2*Y - 1 rooms.
        // Rooms occupied by C: 1, 3, ..., 2*Y-1
        // Rooms occupied by _: 2, 4, ..., 2*Y-2 (these are adjacent to C, so no U can be here)
        // All 2*Y - 1 rooms in this block are effectively "blocked" for uninfected people.
        
        if (X == Y) {
            // Subcase 2a: All people are infected (no uninfected people).
            // The arrangement C _ C _ ... _ C is sufficient.
            // Example for X=3, Y=3: C _ C _ C (5 rooms).
            N = 2 * Y - 1;
        } else { // X > Y, meaning there are uninfected people (X - Y > 0).
            // Subcase 2b: There are uninfected people.
            // The last infected person (at room 2*Y-1 in the C _ C ... _ C block)
            // requires room 2*Y to be empty.
            // So, the infected block effectively needs to be C _ C _ ... _ C _
            // This uses 2*Y rooms.
            // After these 2*Y rooms, room 2*Y+1 is safe for an uninfected person.
            // We place the remaining (X - Y) uninfected people contiguously starting from room 2*Y+1.
            // Total rooms = (rooms for infected block with trailing empty room) + (rooms for uninfected)
            // N = 2*Y + (X - Y) = X + Y.
            // Example for X=5, Y=3: C _ C _ C _ U U (8 rooms).
            N = X + Y;
        }
    }
    
    std::cout << N << "\n"; // Output the minimum number of rooms
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) prevents std::cout from flushing before std::cin reads input.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int T; // Number of test cases
    std::cin >> T; // Read the number of test cases
    while (T--) { // Loop through each test case
        solve(); // Call the solve function for each test case
    }
    
    return 0; // Indicate successful execution
}