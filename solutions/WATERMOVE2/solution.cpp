#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        long long k;
        std::cin >> n >> k;
        std::vector<long long> a(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
        }

        // To maximize the maximum amount of water in any cup, we should
        // consolidate water into the cup that initially has the most water.
        // Each operation allows us to move water from one cup to another.
        // We need to perform exactly K operations.
        // The most effective strategy is to pick the cup with the largest
        // initial amount of water and move water from other cups into it.
        //
        // If K is large enough (K >= N-1), we can potentially move all water
        // into a single cup. However, we are limited by the number of operations.
        //
        // The problem states we must perform *exactly* K operations.
        //
        // Consider the cup with the maximum initial amount of water. Let this be M.
        // We can perform at most N-1 operations to consolidate water into one cup.
        // If K >= N-1, we can pick the cup with the maximum initial amount and
        // move water from all other N-1 cups into it. This would take N-1 operations.
        // If K > N-1, we can perform the N-1 consolidation operations, and then
        // we have K - (N-1) operations remaining. These remaining operations can
        // be used to move water from one cup to another, but since all water
        // is already in one cup (or distributed among a few), these operations
        // won't increase the maximum amount further if we've already consolidated
        // into the largest initial cup.
        //
        // However, the problem states we must perform *exactly* K operations.
        // If we have K operations and N-1 cups to consolidate, we can pick the
        // largest initial cup and move water from K other cups into it.
        // If K < N-1, we can pick the K cups with the largest initial amounts
        // (excluding the absolute largest) and move their water into the cup
        // with the absolute largest initial amount.
        //
        // The most straightforward way to maximize the largest cup is to pick
        // the cup that *initially* has the most water, and then move water
        // from other cups into it.
        //
        // Let's sort the array in descending order. The largest element is a[0].
        // We want to add water to a[0].
        // We have K operations. Each operation can take water from one cup and add it to another.
        // To maximize a[0], we should pick K other cups and move their water to a[0].
        // The best K cups to pick are the ones with the largest amounts among the remaining N-1 cups.
        //
        // So, sort A in descending order. The largest initial amount is A[0].
        // We can perform K operations. Each operation can take water from one of the other N-1 cups
        // and add it to A[0].
        // We should pick the K largest values from A[1], A[2], ..., A[N-1] and add them to A[0].
        //
        // If K is greater than or equal to N-1, we can move all water from all other N-1 cups
        // into the largest cup. The total sum will be the maximum.
        //
        // If K is less than N-1, we can pick the K largest amounts from the remaining N-1 cups
        // and add them to the largest initial cup.

        std::sort(a.rbegin(), a.rend()); // Sort in descending order

        long long max_val = a[0];

        // We can perform K operations. Each operation can take water from one of the
        // other N-1 cups and add it to the cup that initially had the most water (a[0]).
        // We should pick the K largest amounts from the remaining N-1 cups.
        // The number of cups we can take water from is limited by K and also by N-1.
        // So, we can take water from at most min(K, N-1) other cups.
        // Since we want to maximize the sum, we should pick the largest ones.
        // The sorted array `a` already has the largest amounts at the beginning.
        // So, we add the next min(K, N-1) amounts to a[0].

        long long operations_to_perform = std::min((long long)n - 1, k);

        for (int i = 0; i < operations_to_perform; ++i) {
            max_val += a[i + 1];
        }

        std::cout << max_val << "\n";
    }
    return 0;
}