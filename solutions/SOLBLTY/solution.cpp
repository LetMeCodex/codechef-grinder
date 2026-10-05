#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        int x, a, b;
        std::cin >> x >> a >> b;
        // The initial temperature is X degrees, and the solubility is A g/100mL.
        // For every unit rise in temperature, solubility increases by B g/100mL.
        // The maximum temperature Chef can reach is 100 degrees.
        // The amount of water is 1 liter, which is 1000 mL.

        // Calculate the temperature difference from the initial temperature to the maximum temperature.
        int temp_diff = 100 - x;

        // Calculate the increase in solubility due to the temperature rise.
        int solubility_increase = temp_diff * b;

        // Calculate the maximum solubility at 100 degrees.
        // The solubility is given in g/100mL.
        int max_solubility_per_100ml = a + solubility_increase;

        // Since we have 1 liter of water (1000 mL), which is 10 times 100 mL,
        // the total amount of sugar that can be dissolved is 10 times the solubility per 100 mL.
        long long max_sugar_dissolved = (long long)max_solubility_per_100ml * 10;

        std::cout << max_sugar_dissolved << "\n";
    }
    return 0;
}