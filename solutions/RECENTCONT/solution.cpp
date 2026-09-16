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
        int start38_count = 0;
        int ltime108_count = 0;
        for (int i = 0; i < n; ++i) {
            std::string contest_code;
            std::cin >> contest_code;
            if (contest_code == "START38") {
                start38_count++;
            } else {
                ltime108_count++;
            }
        }
        std::cout << start38_count << " " << ltime108_count << "\n";
    }
    return 0;
}