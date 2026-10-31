#include <iostream>

int main() {
    // Optimize C++ standard streams for faster input/output.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t; // Read the number of test cases.
    while (t--) {
        long long a, b; // Use long long for A and B, as per problem constraints (up to 10^6, int is fine, but long long is safer and harmless).
        std::cin >> a >> b; // Read A and B for the current test case.

        // Condition 1: Both A and B are odd.
        // In this case, A+B is even. For an even length palindrome, both character counts must be even.
        // Since A and B are both odd, it's impossible to form any palindrome.
        bool both_odd = (a % 2 != 0) && (b % 2 != 0);

        // Condition 2: A is 1 and B is even.
        // The total length A+B is odd. The middle character must be '0' (since A is odd).
        // The prefix P needs (A-1)/2 zeros and B/2 ones.
        // If A=1, then (A-1)/2 = 0. So P needs 0 zeros and B/2 ones.
        // This means P must be '1' repeated B/2 times. Only one such P exists.
        // Thus, only one palindrome can be formed.
        bool a_is_one_b_is_even = (a == 1) && (b % 2 == 0);

        // Condition 3: B is 1 and A is even.
        // Similar to Condition 2, but roles of A and B are swapped.
        // The total length A+B is odd. The middle character must be '1' (since B is odd).
        // The prefix P needs A/2 zeros and (B-1)/2 ones.
        // If B=1, then (B-1)/2 = 0. So P needs A/2 zeros and 0 ones.
        // This means P must be '0' repeated A/2 times. Only one such P exists.
        // Thus, only one palindrome can be formed.
        bool b_is_one_a_is_even = (b == 1) && (a % 2 == 0);

        // If any of these conditions are true, we cannot construct two different palindromes.
        if (both_odd || a_is_one_b_is_even || b_is_one_a_is_even) {
            std::cout << "No\n";
        } else {
            // In all other cases, it's possible to construct two different palindromes.
            // This includes:
            // - A and B are both even (A, B >= 2).
            // - A is even (A >= 2), B is odd (B >= 3).
            // - A is odd (A >= 3), B is even (B >= 2).
            std::cout << "Yes\n";
        }
    }
    return 0;
}