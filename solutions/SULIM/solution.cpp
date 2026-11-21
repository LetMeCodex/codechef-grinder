#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

struct Snack {
    int tastiness;
    int sugar;
};

bool compareSnacks(const Snack& a, const Snack& b) {
    return a.sugar < b.sugar;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<Snack> snacks(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> snacks[i].tastiness;
        }
        for (int i = 0; i < n; ++i) {
            std::cin >> snacks[i].sugar;
        }

        std::sort(snacks.begin(), snacks.end(), compareSnacks);

        long long max_satisfaction = 0;
        long long current_tastiness_sum = 0;

        // Iterate through all possible values of L.
        // The optimal L must be one of the B_i values or 0.
        // If L is not one of B_i, we can always increase L to the smallest B_i > L
        // without changing the set of edible snacks, and potentially increase satisfaction.
        // If L is greater than all B_i, we can decrease L to the largest B_i
        // without changing the set of edible snacks, and potentially increase satisfaction.
        // So, we only need to consider L values that are equal to some B_i, or L=0.
        // Since snacks are sorted by sugar, we can iterate through them.

        // Consider L=0 (no snacks eaten)
        max_satisfaction = 0;
        current_tastiness_sum = 0;

        for (int i = 0; i < n; ++i) {
            // For a chosen L, we eat all snacks j such that B_j <= L.
            // We want to maximize (sum of A_j for B_j <= L) - L.
            // Let's iterate through possible L values.
            // The possible values for L that change the set of edible snacks are the B_i values.
            // If we choose L = snacks[i].sugar, then all snacks with sugar <= snacks[i].sugar are candidates.
            // We should only eat snacks with positive tastiness among these candidates.

            // When we consider snacks[i].sugar as L, we add snacks[i] to our potential sum.
            // If snacks[i].tastiness is positive, we add it to current_tastiness_sum.
            // If snacks[i].tastiness is negative, we don't add it to current_tastiness_sum
            // because we can choose not to eat it even if B_i <= L.
            if (snacks[i].tastiness > 0) {
                current_tastiness_sum += snacks[i].tastiness;
            }
            
            // The current L is snacks[i].sugar.
            // The sum of tastiness of snacks we *could* eat is current_tastiness_sum.
            // The satisfaction for this L is current_tastiness_sum - L.
            max_satisfaction = std::max(max_satisfaction, current_tastiness_sum - snacks[i].sugar);
        }
        
        std::cout << max_satisfaction << "\n";
    }
    return 0;
}