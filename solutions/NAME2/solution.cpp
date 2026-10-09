#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// Function to check if string A is a subsequence of string B
bool isSubsequence(const std::string& a, const std::string& b) {
    int i = 0, j = 0;
    while (i < a.length() && j < b.length()) {
        if (a[i] == b[j]) {
            i++;
        }
        j++;
    }
    return i == a.length();
}

int main() {
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    while (t--) {
        std::string m, w;
        std::cin >> m >> w;

        // The condition is M is a subsequence of W OR W is a subsequence of M.
        // If M is a subsequence of W, then |M| <= |W|.
        // If W is a subsequence of M, then |W| <= |M|.
        // Therefore, if |M| > |W|, we only need to check if W is a subsequence of M.
        // If |W| > |M|, we only need to check if M is a subsequence of W.
        // If |M| == |W|, we need to check both, but if one is a subsequence of the other
        // and lengths are equal, they must be identical.

        if (isSubsequence(m, w) || isSubsequence(w, m)) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
    return 0;
}