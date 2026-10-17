#include <iostream>
#include <string>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        int n, a, b;
        std::cin >> n >> a >> b;
        std::string s;
        std::cin >> s;
        
        long long inter_district_count = 0;
        long long inter_state_count = 0;
        
        for (char c : s) {
            if (c == '0') {
                inter_district_count++;
            } else {
                inter_state_count++;
            }
        }
        
        long long total_time = (inter_district_count * a) + (inter_state_count * b);
        std::cout << total_time << "\n";
    }
    return 0;
}