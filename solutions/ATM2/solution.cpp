#include <iostream>
#include <vector>
#include <string>
#include <numeric>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        long long k;
        std::cin >> n >> k;
        std::vector<long long> a(n);
        std::string result = "";
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
            if (k >= a[i]) {
                k -= a[i];
                result += '1';
            } else {
                result += '0';
            }
        }
        std::cout << result << "\n";
    }
    return 0;
}