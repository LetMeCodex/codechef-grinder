#include <iostream> // For std::cin, std::cout, std::ios_base, std::endl (or "\n")
#include <string>   // For std::string
// No need for <vector> or <algorithm> with the changes below

void solve() {
    int N, M;
    std::cin >> N >> M;
    std::string S;
    std::cin >> S;
    std::string L;
    std::cin >> L;

    // Use a raw boolean array for maximum efficiency and to avoid any potential
    // (though unlikely for 26 elements) overheads of std::vector<bool> specialization.
    // Initialize all elements to false.
    bool is_left_hand[26] = {false}; 
    for (char c : L) {
        is_left_hand[c - 'a'] = true;
    }

    // Constraints state N >= 1, so S will never be empty.
    // Initialize max_consecutive and current_consecutive based on the first character.
    int max_consecutive = 1;
    int current_consecutive = 1;
    
    // Determine the hand for the first character in S.
    bool prev_hand_is_left = is_left_hand[S[0] - 'a'];

    // Iterate through the string S starting from the second character.
    for (int i = 1; i < N; ++i) {
        char current_char = S[i];
        bool current_char_is_left = is_left_hand[current_char - 'a'];

        if (current_char_is_left == prev_hand_is_left) {
            // The current character is typed by the same hand as the previous one.
            // Continue the streak.
            current_consecutive++;
        } else {
            // The current character is typed by a different hand.
            // The streak is broken. Update max_consecutive with the length of the just-finished streak.
            if (current_consecutive > max_consecutive) {
                max_consecutive = current_consecutive;
            }
            
            // Start a new streak with the current character.
            current_consecutive = 1;
            // Update the hand for the previous character to the current character's hand.
            prev_hand_is_left = current_char_is_left;
        }
    }

    // After the loop, the last streak's length needs to be compared with max_consecutive
    // because it might be the longest streak and wouldn't have been updated inside the loop
    // if it continued until the end of the string.
    if (current_consecutive > max_consecutive) {
        max_consecutive = current_consecutive;
    }

    std::cout << max_consecutive << "\n"; // Use "\n" instead of std::endl for potentially faster output
}

int main() {
    // Enable fast I/O for competitive programming.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T; // Read the number of test cases.
    while (T--) {
        solve(); // Solve each test case.
    }

    return 0;
}