#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int W, H;
    std::cin >> W >> H;
    
    int chef_weight = 60;
    int chef_height = 130;
    
    if (chef_weight <= W && chef_height >= H) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }
    
    return 0;
}