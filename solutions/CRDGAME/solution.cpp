#include <iostream>
#include <string>
#include <algorithm>

// Function to calculate the sum of digits of a number
int sum_digits(int n) {
    int sum = 0;
    std::string s = std::to_string(n);
    for (char c : s) {
        sum += c - '0';
    }
    return sum;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        int chef_points = 0;
        int morty_points = 0;
        for (int i = 0; i < n; ++i) {
            int a, b;
            std::cin >> a >> b;
            int chef_power = sum_digits(a);
            int morty_power = sum_digits(b);
            if (chef_power > morty_power) {
                chef_points++;
            } else if (morty_power > chef_power) {
                morty_points++;
            } else {
                chef_points++;
                morty_points++;
            }
        }

        if (chef_points > morty_points) {
            std::cout << "0 " << chef_points << "\n";
        } else if (morty_points > chef_points) {
            std::cout << "1 " << morty_points << "\n";
        } else {
            std::cout << "2 " << chef_points << "\n";
        }
    }
    return 0;
}