#include <iostream>
#include <algorithm> // Required for std::min

int main() {
    // Optimize C++ standard streams for faster input/output.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; // Number of test cases for the entire problem
    std::cin >> t;
    while (t--) {
        int maxT_int, maxN_int, sumN_int;
        std::cin >> maxT_int >> maxN_int >> sumN_int;

        // Convert input values to long long to prevent potential overflow
        // during intermediate calculations (e.g., maxN * maxN) and for the final sum.
        long long maxT = maxT_int;
        long long maxN = maxN_int;
        long long sumN = sumN_int;

        // Step 1: Determine the number of test cases that can be assigned the maximum N value (maxN).
        // This is limited by the total allowed test cases (maxT) and the total sum budget (sumN).
        // sumN / maxN gives how many times maxN can fit into sumN.
        long long num_full_maxN = std::min(maxT, sumN / maxN);

        // Step 2: Calculate the total iterations from these 'num_full_maxN' test cases.
        // Each contributes maxN * maxN iterations.
        long long total_iterations = num_full_maxN * maxN * maxN;

        // Step 3: Calculate the sum of N values used by these 'num_full_maxN' test cases.
        long long sum_used_for_full_maxN = num_full_maxN * maxN;

        // Step 4: Calculate the remaining sum budget.
        long long remaining_sum_budget = sumN - sum_used_for_full_maxN;

        // Step 5: Calculate the remaining number of test case slots available.
        long long remaining_T_slots = maxT - num_full_maxN;

        // Step 6: If there are remaining test case slots AND a remaining sum budget,
        // assign the entire remaining sum budget to one more test case.
        // This maximizes the square for the remaining sum.
        // As proven in the thought process, if remaining_T_slots > 0, then
        // remaining_sum_budget will be <= maxN, making it a valid N value.
        if (remaining_T_slots > 0 && remaining_sum_budget > 0) {
            total_iterations += remaining_sum_budget * remaining_sum_budget;
        }

        // Output the maximum total iterations for the current test case.
        std::cout << total_iterations << "\n";
    }

    return 0;
}