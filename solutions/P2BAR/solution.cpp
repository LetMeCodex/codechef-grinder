#include <iostream>
#include <string>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::string s;
        std::cin >> s;

        int count = 0;
        bool silence_seen = false;

        for (int i = 0; i < n; ++i) {
            if (s[i] == '0') {
                silence_seen = true;
            } else if (s[i] == '1') {
                if (silence_seen) {
                    count++;
                }
            }
        }
        std::cout << count << "\n";
    }
    return 0;
}