#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        int xa, xb, Xa, Xb;
        std::cin >> xa >> xb >> Xa >> Xb;
        int num_a = Xa / xa;
        int num_b = Xb / xb;
        std::cout << num_a + num_b << "\n";
    }
    return 0;
}