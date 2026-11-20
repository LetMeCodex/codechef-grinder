#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<long long> a(n);
        std::vector<long long> d(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            std::cin >> d[i];
        }

        long long max_safe_defense = -1;

        for (int i = 0; i < n; ++i) {
            // Soldier i can be attacked by soldier (i-1) mod n and soldier (i+1) mod n.
            // The indices need to be handled carefully for circularity.
            // Soldier to the left of i is (i-1+n)%n
            // Soldier to the right of i is (i+1)%n

            long long left_attacker_attack = a[(i - 1 + n) % n];
            long long right_attacker_attack = a[(i + 1) % n];

            // The maximum possible attack power on soldier i is the sum of attacks from
            // the soldier to their left and the soldier to their right.
            long long max_attack_on_i = left_attacker_attack + right_attacker_attack;

            // Soldier i survives if their defense is strictly greater than the attack power.
            // Chef wants to pick a soldier that is GUARANTEED to survive, regardless of
            // other soldiers' choices.
            // This means that even if BOTH neighbors attack soldier i, soldier i must survive.
            // So, we check if d[i] > max_attack_on_i.

            if (d[i] > max_attack_on_i) {
                // This soldier is guaranteed to survive.
                // We want to find the maximum defense value among all such guaranteed survivors.
                max_safe_defense = std::max(max_safe_defense, d[i]);
            }
        }
        std::cout << max_safe_defense << "\n";
    }
    return 0;
}