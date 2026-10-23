#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    int cost_tv = 1000;
    int cost_toys = n * 200;

    if (cost_toys < cost_tv) {
        std::cout << cost_toys << "\n";
    } else {
        std::cout << cost_tv << "\n";
    }

    return 0;
}