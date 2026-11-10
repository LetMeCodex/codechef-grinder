#include <iostream>
#include <string>
#include <vector> // Not strictly needed, but good practice to include specific headers

void solve() {
    int N;
    int X;
    std::cin >> N >> X;
    std::string S;
    std::cin >> S;

    int current_swipes = 0; // Card starts with 0 swipes

    for (char op : S) {
        if (op == '1') {
            // Renewal: set swipes to X
            current_swipes = X;
        } else { // op == '0'
            // Swipe: requires at least 1 swipe
            if (current_swipes > 0) {
                current_swipes--;
            } else {
                // Not enough swipes to perform the operation
                std::cout << "NO\n";
                return; // Exit function early for this test case
            }
        }
    }

    // If the loop completes without returning "NO", the sequence is valid
    std::cout << "YES\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}