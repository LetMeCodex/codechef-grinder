#include <iostream>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        double a, x, b, y;
        std::cin >> a >> x >> b >> y;
        
        double alice_speed = a / x;
        double bob_speed = b / y;
        
        // Using a small epsilon for floating-point comparisons
        double epsilon = 1e-9; 
        
        if (alice_speed > bob_speed + epsilon) {
            std::cout << "Alice\n";
        } else if (bob_speed > alice_speed + epsilon) {
            std::cout << "Bob\n";
        } else {
            std::cout << "Equal\n";
        }
    }
    return 0;
}