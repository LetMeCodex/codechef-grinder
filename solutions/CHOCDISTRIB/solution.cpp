#include <iostream>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;

        // Minimum number of children:
        // To minimize the number of children, we want to give as many chocolates
        // as possible to a single child. Since children never ask for more than 2,
        // the most efficient way to distribute is to give 2 chocolates to as many
        // children as possible, and then 1 chocolate to the last child if N is odd.
        // However, the problem states "Some of them even asked for 2 chocolates".
        // This implies that we can give 2 chocolates to a child.
        // The absolute minimum number of children occurs when we give 2 chocolates
        // to as many children as possible. If N is even, we can give N/2 children 2 chocolates each.
        // If N is odd, we can give (N-1)/2 children 2 chocolates each, and 1 child 1 chocolate.
        // In both cases, the minimum number of children is ceil(N/2).
        // This can be calculated as (N + 1) / 2 using integer division.
        int min_children = (n + 1) / 2;

        // Maximum number of children:
        // To maximize the number of children, we want to give as few chocolates
        // as possible to each child. Since children never ask for more than 2,
        // the minimum number of chocolates a child can receive is 1.
        // Therefore, to maximize the number of children, we give 1 chocolate to
        // each child. This means we can have at most N children, each receiving 1 chocolate.
        int max_children = n;

        std::cout << min_children << " " << max_children << "\n";
    }
    return 0;
}