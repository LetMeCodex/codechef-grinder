#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int A, B, C, X;
    std::cin >> A >> B >> C >> X;
    if (X == A || X == B || X == C) {
        std::cout << "Yes\n";
    } else {
        std::cout << "No\n";
    }
    return 0;
}