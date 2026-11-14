#include <iostream>
#include <string>
#include <vector>
#include <numeric> // Not strictly needed, a loop is used for counting

void solve() {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;

    int count0 = 0;
    for (char c : s) {
        if (c == '0') {
            count0++;
        }
    }

    // The core logic:
    // If N is odd, we can always form a palindrome.
    // If N is even, we can form a palindrome only if the count of 0s (and 1s) is even.
    // The operation preserves the parity of the count of 0s.
    // So, if N is even and count0 is odd, it's impossible. Otherwise, it's possible.
    if (n % 2 == 1) {
        std::cout << "YES\n";
    } else { // N is even
        if (count0 % 2 == 0) { // count0 is even
            std::cout << "YES\n";
        } else { // count0 is odd
            std::cout << "NO\n";
        }
    }
}

int main() {
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}