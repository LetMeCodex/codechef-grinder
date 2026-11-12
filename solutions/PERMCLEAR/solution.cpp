#include <iostream>
#include <vector>
#include <unordered_set>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
        }
        int k;
        std::cin >> k;
        std::unordered_set<int> disliked_numbers;
        for (int i = 0; i < k; ++i) {
            int b_val;
            std::cin >> b_val;
            disliked_numbers.insert(b_val);
        }

        std::vector<int> result;
        for (int x : a) {
            if (disliked_numbers.find(x) == disliked_numbers.end()) {
                result.push_back(x);
            }
        }

        for (size_t i = 0; i < result.size(); ++i) {
            std::cout << result[i] << (i == result.size() - 1 ? "" : " ");
        }
        std::cout << "\n";
    }
    return 0;
}