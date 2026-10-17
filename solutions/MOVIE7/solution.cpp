#include <iostream>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        long long n, m, a, b, c;
        std::cin >> n >> m >> a >> b >> c;
        
        long long min_cost = -1;
        
        // Strategy 1: Buy all tickets and popcorn individually
        long long cost1 = n * a + m * b;
        min_cost = cost1;
        
        // Strategy 2: Maximize combo packs
        // We can buy at most min(N, M) combo packs.
        // The remaining items will be bought individually.
        
        // Option 2a: Buy min(N, M) combo packs, then remaining tickets
        long long num_combos_2a = std::min(n, m);
        long long remaining_tickets_2a = n - num_combos_2a;
        long long remaining_popcorn_2a = m - num_combos_2a;
        long long cost2a = num_combos_2a * c + remaining_tickets_2a * a + remaining_popcorn_2a * b;
        if (min_cost == -1 || cost2a < min_cost) {
            min_cost = cost2a;
        }
        
        // Option 2b: Buy min(N, M) combo packs, then remaining popcorn
        // This is covered by the logic above, as remaining_popcorn_2a will be 0 if m <= n.
        // If n <= m, then remaining_tickets_2a will be 0.
        // So, cost2a correctly handles buying remaining items of either type.

        // The problem statement guarantees max(A, B) < C <= A + B.
        // This means buying a combo is always better than buying the more expensive item individually
        // and then the cheaper item individually if we were to buy them separately.
        // For example, if A > B, then C < A + B.
        // If we buy a combo (cost C) and a ticket (cost A), total is C + A.
        // If we buy two tickets and one popcorn, total is 2A + B.
        // If we buy one ticket and two popcorns, total is A + 2B.
        
        // The optimal strategy is to use as many combo packs as possible,
        // up to the minimum of N and M, because each combo pack saves
        // (A + B) - C compared to buying them separately.
        // Since C > max(A, B), it means C is strictly greater than the cost of
        // either A or B individually.
        // The condition C <= A + B ensures that buying a combo is not more
        // expensive than buying both items separately.
        
        // Let's re-evaluate the strategy.
        // We need N tickets and M popcorns.
        // We can form k combo packs, where 0 <= k <= min(N, M).
        // The cost for k combo packs is k * C.
        // We are left with N-k tickets and M-k popcorns.
        // The cost for remaining items is (N-k)*A + (M-k)*B.
        // Total cost for k combos: k*C + (N-k)*A + (M-k)*B
        // = k*C + N*A - k*A + M*B - k*B
        // = N*A + M*B + k*(C - A - B)
        
        // Since C <= A + B, the term (C - A - B) is less than or equal to 0.
        // To minimize the total cost, we want to maximize k if (C - A - B) is negative,
        // or minimize k if (C - A - B) is positive.
        // Since C <= A + B, (C - A - B) <= 0.
        // So, to minimize the cost, we should maximize k.
        // The maximum possible value for k is min(N, M).
        
        // Therefore, the optimal strategy is to buy min(N, M) combo packs
        // and then buy the remaining items individually.
        
        long long num_combos = std::min(n, m);
        long long remaining_tickets = n - num_combos;
        long long remaining_popcorn = m - num_combos;
        
        long long final_cost = num_combos * c + remaining_tickets * a + remaining_popcorn * b;
        
        std::cout << final_cost << "\n";
    }
    return 0;
}