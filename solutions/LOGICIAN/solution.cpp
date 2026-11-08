#include <iostream> // Required for input/output operations (std::cin, std::cout)
#include <string>   // Required for std::string

// Function to solve a single test case
void solve() {
    int N;
    std::cin >> N; // Read the number of logicians
    std::string S;
    std::cin >> S; // Read the binary string representing logicians' preferences

    // This boolean flag tracks whether, based on all information revealed so far,
    // it is still possible that *all* N logicians want beer.
    // Initially, before any logician has spoken, it's possible.
    bool can_still_be_all_yes = true;

    // Iterate through each logician from 1 to N (using 0-indexed 'i' for string S)
    for (int i = 0; i < N; ++i) {
        if (S[i] == '0') {
            // Logician (i+1) knows they themselves do not want beer.
            // If even one logician doesn't want beer, then it's impossible for "everyone" to want beer.
            // So, logician (i+1) is certain the answer to "Does everyone want a beer?" is "NO".
            std::cout << "NO\n";
            
            // Once a logician says "NO" because they don't want beer,
            // it's definitively established that not everyone wants beer.
            // This information is known to all subsequent logicians.
            can_still_be_all_yes = false;
        } else { // S[i] == '1' (Logician (i+1) wants beer)
            // Logician (i+1) knows they themselves want beer.
            // Now, they must consider the information gathered from previous logicians' replies.
            if (!can_still_be_all_yes) {
                // If 'can_still_be_all_yes' is false, it means some previous logician (j < i+1)
                // either explicitly replied "NO" (because S_j was '0'), or it was deduced
                // from their "IDK" replies that S_j must have been '0' (which is not the case here,
                // as "IDK" implies S_j='1'). The only way 'can_still_be_all_yes' becomes false
                // is if a previous logician said "NO".
                // In any case, it's already impossible for everyone to want beer.
                // So, logician (i+1) is certain the answer is "NO".
                std::cout << "NO\n";
                // The state 'can_still_be_all_yes' remains false.
            } else {
                // If 'can_still_be_all_yes' is true, it means:
                // 1. All previous logicians (j < i+1) who replied "IDK" must have wanted beer (S_j = '1').
                // 2. No previous logician has replied "NO".
                // Combined with S[i] == '1', logician (i+1) has deduced that S_1='1', S_2='1', ..., S_{i+1}='1'.

                if (i == N - 1) {
                    // This is the last logician.
                    // They have deduced that S_1='1', ..., S_N='1'.
                    // They are now certain that *everyone* wants beer.
                    std::cout << "YES\n";
                    // The state 'can_still_be_all_yes' remains true (as the condition was met).
                } else {
                    // This is not the last logician.
                    // They know S_1='1', ..., S_{i+1}='1'.
                    // However, they do not know the preferences of logicians (i+2) through N.
                    // It's still possible that all remaining logicians want beer (leading to "YES").
                    // It's also still possible that at least one of the remaining logicians does not want beer (leading to "NO").
                    // Since both outcomes are possible, logician (i+1) cannot be certain.
                    std::cout << "IDK\n";
                    // The state 'can_still_be_all_yes' remains true, as it's still possible for everyone to want beer.
                }
            }
        }
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) prevents std::cout from flushing before std::cin reads input.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T; // Read the number of test cases
    while (T--) {
        solve(); // Solve each test case
    }

    return 0; // Indicate successful execution
}