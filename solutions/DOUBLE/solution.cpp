#include <iostream> // Required for standard input/output operations (cin, cout)

int main() {
    // Optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) prevents std::cout from being flushed before each std::cin operation.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T; // Declare an integer variable T to store the number of test cases.
    std::cin >> T; // Read the number of test cases from standard input.

    // Loop T times, once for each test case.
    while (T--) {
        int N; // Declare an integer variable N to store the length of the palindrome.
        std::cin >> N; // Read the length N for the current test case.

        // The problem asks for the maximal possible number of characters in a "double string"
        // that can be obtained by removing and changing the order of symbols from a palindrome of length N.
        //
        // A "double string" must have an even length and its first half must be equal to its second half (e.g., "XX").
        // This implies that every character in a double string must appear an even number of times.
        //
        // We are given a palindrome of length N. The character counts in a palindrome have specific properties:
        // 1. If N is even: All characters in the palindrome appear an even number of times.
        //    Example: "abba" (N=4) has 'a':2, 'b':2.
        //    In this case, since all character counts are already even, we can use all N characters
        //    to form a double string. We can split the counts in half to form 'X' and then 'XX'.
        //    The maximal length is N.
        //
        // 2. If N is odd: Exactly one character in the palindrome appears an odd number of times.
        //    All other characters appear an even number of times.
        //    Example: "racecar" (N=7) has 'r':2, 'a':2, 'c':2, 'e':1.
        //    To form a double string, all characters must appear an even number of times.
        //    We must discard one occurrence of the character that appears an odd number of times.
        //    After discarding this one character, all remaining characters will have even counts,
        //    and the total length will be N-1. Since N is odd, N-1 is even, satisfying the
        //    length requirement for a double string. This is the maximal length possible
        //    because we only discard the minimum necessary (1 character).
        //
        // Therefore, the answer is N if N is even, and N-1 if N is odd.
        // This can be concisely written as N - (N % 2).

        if (N % 2 == 0) { // Check if N is even
            std::cout << N << "\n"; // If N is even, print N
        } else { // If N is odd
            std::cout << N - 1 << "\n"; // If N is odd, print N-1
        }
    }

    return 0; // Indicate successful execution.
}