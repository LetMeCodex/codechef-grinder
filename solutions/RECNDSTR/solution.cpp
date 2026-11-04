#include <iostream>
#include <string>
#include <vector>
#include <numeric>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        std::string s;
        std::cin >> s;
        int n = s.length();

        if (n == 1) {
            std::cout << "YES\n";
            continue;
        }

        // The condition L(V) = S and R(V) = S implies that V = R(S) and V = L(S).
        // Thus, we need R(S) == L(S).
        // R(S) = S.back() + S.substr(0, n-1)
        // L(S) = S.substr(1) + S.front()
        //
        // For R(S) == L(S), we need:
        // S[n-1]S[0]S[1]...S[n-2] == S[1]S[2]...S[n-1]S[0]
        //
        // This implies:
        // S[n-1] == S[1]
        // S[0]   == S[2]
        // S[1]   == S[3]
        // ...
        // S[n-2] == S[0]
        //
        // In general, for any index i, the character at index i in L(S) must match
        // the character at index i in R(S).
        //
        // L(S) has character S[(i+1) % n] at index i.
        // R(S) has character S[(i-1) % n] at index i.
        //
        // So we need S[(i+1) % n] == S[(i-1) % n] for all i from 0 to n-1.
        // Let j = (i-1) % n. Then i = (j+1) % n.
        // The condition becomes S[(j+2) % n] == S[j] for all j from 0 to n-1.
        // This means characters at indices j, j+2, j+4, ... (modulo n) must be the same.
        // This implies the string must be of the form c1 c2 c1 c2 ... or c1 c1 c1 c1 ...

        bool possible = true;
        for (int i = 0; i < n; ++i) {
            // Check if S[i] is equal to S[(i+2) % n]
            // This is equivalent to checking if S[i] == S[i+2] for i < n-2,
            // S[n-2] == S[0], and S[n-1] == S[1].
            // The modulo arithmetic handles all cases correctly.
            if (s[i] != s[(i + 2) % n]) {
                possible = false;
                break;
            }
        }

        if (possible) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
    return 0;
}