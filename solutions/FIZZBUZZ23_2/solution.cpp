#include <iostream>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        long long n, x, d;
        std::cin >> n >> x >> d;
        // Total family members are 5 (Alice + 4 others)
        long long family_members = 5;
        // Total buns required per day by the family
        long long daily_consumption = family_members * x;

        // Calculate how many full days the buns can last
        // If daily_consumption is 0 (which is not possible given constraints X>=1),
        // this would be infinite, but constraints prevent this.
        // If n < daily_consumption, buns last 0 full days.
        long long days_from_buns = n / daily_consumption;

        // The total survival days are the days the buns last plus the additional days
        // they can survive after food runs out.
        // However, the number of days the buns last cannot exceed the additional survival days D.
        // The problem states "After the food supply runs out, the family can survive for a further D days."
        // This implies that if the buns last for 'k' days, they survive for 'k' days.
        // If 'k' days is less than or equal to 'D', they survive for 'k' days.
        // If 'k' days is more than 'D', they survive for 'k' days.
        // The crucial part is "If there aren't enough buns to feed the whole family, nobody will eat anything."
        // This means if at any point they need 'daily_consumption' buns and have less than that,
        // they stop eating from the buns.
        // The number of days they can *eat* from the buns is `days_from_buns`.
        // After these `days_from_buns`, they can survive for an additional `D` days.
        // So, the total survival days are `days_from_buns + D`.

        // Let's re-read the sample explanation carefully:
        // Test case 1: 50 2 10
        // Daily consumption = 5 * 2 = 10.
        // Days buns last = 50 / 10 = 5 days.
        // Total survival = 5 (from buns) + 10 (additional) = 15 days. This matches.

        // Test case 2: 120 5 15
        // Daily consumption = 5 * 5 = 25.
        // Days buns last = 120 / 25 = 4 days.
        // After 4 days, buns remaining = 120 - (4 * 25) = 120 - 100 = 20 buns.
        // On day 5, they need 25 buns, but only 20 are left.
        // "If there aren't enough buns to feed the whole family, nobody will eat anything."
        // This means they cannot complete day 5 using buns. So, they survive for 4 full days using buns.
        // After these 4 days, they can survive for an additional D=15 days.
        // Total survival = 4 (from buns) + 15 (additional) = 19 days. This matches.

        // The logic seems to be:
        // 1. Calculate how many full days the buns can sustain the family. This is `N / daily_consumption`.
        // 2. Add the additional survival days `D` to this number.

        long long total_survival_days = days_from_buns + d;
        
        std::cout << total_survival_days << "\n";
    }
    return 0;
}