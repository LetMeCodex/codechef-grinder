#include <iostream>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        int nA, nB, nC;
        std::cin >> nA >> nB >> nC;
        bool dominant = false;
        if (nA > nB + nC) {
            dominant = true;
        }
        if (nB > nA + nC) {
            dominant = true;
        }
        if (nC > nA + nB) {
            dominant = true;
        }
        if (dominant) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
    return 0;
}