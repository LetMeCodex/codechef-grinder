#include <iostream> // Required for input/output operations

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T; // Variable to store the number of test cases
    std::cin >> T; // Read the number of test cases

    // Loop through each test case
    while (T--) {
        int X, Y; // Variables to store the number of 1's and 2's
        std::cin >> X >> Y; // Read X and Y for the current test case

        long long total_score; // Use long long for score to be safe, though int is sufficient for given constraints

        // Case 1: We have enough '2's to pair with all '1's such that no (1,1,1) triplets are formed.
        // Each '2' can effectively "cover" up to two '1's in a (2,1,1) triplet.
        // If X <= 2*Y, it means we have enough '2's to ensure all '1's are part of a triplet
        // that contains at least one '2'. Thus, all (X+Y)/3 triplets will contribute 2 to the score.
        if (X <= 2 * Y) {
            total_score = 2LL * (X + Y) / 3;
        }
        // Case 2: We have too many '1's relative to '2's.
        // We use all 'Y' twos to cover 2*Y ones (by forming Y triplets of type (2,1,1)).
        // This leaves X - 2*Y ones that cannot be paired with any '2'.
        // These remaining (X - 2*Y) ones must be grouped into (1,1,1) triplets.
        // The number of such (1,1,1) triplets is (X - 2*Y) / 3.
        // These (X - 2*Y) / 3 triplets will contribute 1 each to the score.
        // The remaining triplets will contribute 2 each to the score.
        // The simplified formula for this case is (X + 4*Y) / 3.
        else { // X > 2 * Y
            total_score = (X + 4LL * Y) / 3;
        }
        
        // Output the maximum possible score for the current test case, followed by a newline
        std::cout << total_score << "\n";
    }

    return 0; // Indicate successful execution
}