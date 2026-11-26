#include <iostream> // Required for standard input/output operations

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming to prevent Time Limit Exceeded (TLE)
    // on problems with large numbers of test cases or large inputs.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T; // Declare an integer variable 'T' to store the number of test cases.
    std::cin >> T; // Read the number of test cases from standard input.

    // Loop through each test case. The loop continues as long as T is greater than 0,
    // and T is decremented in each iteration.
    while (T--) {
        long long X, Y; // Declare two long long variables 'X' and 'Y'
                        // to store the initial number of biscuits and cakes.
                        // 'long long' is used because X and Y can be up to 10^9.
        std::cin >> X >> Y; // Read the values of X and Y for the current test case.

        // The winner is determined by the parity of X.
        // If X is odd, Alice wins.
        // If X is even, Bob wins.
        // This is proven by induction as explained in the problem analysis.
        //
        // If X is odd, Alice can always make Move 1 (eat one biscuit).
        // This changes X to X-1, which is an even number.
        // By induction, a state with an even number of biscuits is a P-position (previous player wins).
        // So, Alice moves to a P-position, meaning she wins.
        //
        // If X is even, any move Alice makes will result in a state where the number of biscuits X' is odd:
        // - Move 1: (X-1, Y) -> X-1 is odd.
        // - Move 2: (X-1, Y-1) -> X-1 is odd.
        // - Move 3: (X+1, Y-1) -> X+1 is odd.
        // By induction, a state with an odd number of biscuits is an N-position (next player wins).
        // Since all of Alice's moves lead to N-positions, the current state (X, Y) is a P-position.
        // Thus, Bob wins.
        // This logic holds even for edge cases like X=0 or Y=0.

        if (X % 2 == 1) { // Check if X is odd (remainder is 1 when divided by 2).
            std::cout << "Alice\n"; // If X is odd, Alice wins. Print "Alice".
        } else { // If X is not odd, it must be even.
            std::cout << "Bob\n"; // If X is even, Bob wins. Print "Bob".
        }
    }

    return 0; // Indicate that the program executed successfully.
}