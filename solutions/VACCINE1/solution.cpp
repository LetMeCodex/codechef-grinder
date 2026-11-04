#include <iostream>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int d1, v1, d2, v2, p;
    std::cin >> d1 >> v1 >> d2 >> v2 >> p;

    long long current_vaccines = 0;
    int day = 0;

    while (current_vaccines < p) {
        day++;
        if (day >= d1) {
            current_vaccines += v1;
        }
        if (day >= d2) {
            current_vaccines += v2;
        }
    }

    std::cout << day << std::endl;

    return 0;
}