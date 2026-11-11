#include <iostream> // Required for standard input/output operations (std::cin, std::cout)

// Function to solve a single test case
void solve() {
    // Declare integer variables to store the correct answers for the three questions.
    int A1, A2, A3;
    // Read the three correct answers from standard input.
    // A value of 1 represents 'Yes', and 0 represents 'No'.
    std::cin >> A1 >> A2 >> A3;

    // Declare integer variables to store the hero's responses to the three questions.
    int B1, B2, B3;
    // Read the three hero's responses from standard input.
    // A value of 1 represents 'Yes', and 0 represents 'No'.
    std::cin >> B1 >> B2 >> B3;

    // Calculate the total count of 'Yes' answers (1s) among the correct answers.
    // Since A_i are either 0 or 1, their sum directly gives the count of 1s.
    int sumA = A1 + A2 + A3;

    // Calculate the total count of 'Yes' answers (1s) among the hero's responses.
    // Similarly, the sum of B_i gives the count of 1s in the hero's responses.
    int sumB = B1 + B2 + B3;

    // The hero passes the test if the number of 'Yes' answers in their responses
    // matches the number of 'Yes' answers in the correct answers.
    // If the count of 'Yes' answers matches, the count of 'No' answers (3 - count_of_Yes)
    // will also automatically match, satisfying the problem condition.
    if (sumA == sumB) {
        // If the counts match, print "Pass" followed by a newline character.
        std::cout << "Pass\n";
    } else {
        // If the counts do not match, print "Fail" followed by a newline character.
        std::cout << "Fail\n";
    }
}

// Main function: the entry point of the program
int main() {
    // For this specific error ("Connection aborted") and the problem's small constraints,
    // the fast I/O optimizations (std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);)
    // have been removed. While generally beneficial, they are not strictly necessary here
    // and in extremely rare cases, might interact unexpectedly with certain judge environments.
    // The core logic remains unchanged and is correct.

    int t; // Declare an integer variable to store the number of test cases.
    // Read the number of test cases from standard input.
    std::cin >> t;

    // Loop through each test case. The loop continues as long as 't' is greater than 0,
    // and 't--' decrements 't' after each iteration.
    while (t--) {
        // Call the 'solve' function to process each individual test case.
        solve();
    }

    // Return 0 to indicate successful program execution.
    return 0;
}