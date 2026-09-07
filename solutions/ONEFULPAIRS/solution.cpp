#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    long long a, b;
    std::cin >> a >> b;
    if (a + b + (a * b) == 111) {
        std::cout << "Yes\n";
    } else {
        std::cout << "No\n";
    }
    return 0;
}