#include <iostream>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        long long a, b, x;
        std::cin >> a >> b >> x;
        long long rect_area = a * b;
        long long square_area = x * x;

        if (square_area >= rect_area) {
            std::cout << 0 << "\n";
        } else {
            // We need to reduce the rectangle's area to be <= square_area.
            // Each change costs 1. We can change A or B to any positive integer.
            // To minimize cost, we want to make the largest possible reduction with each change.
            // The goal is to make a * b <= x*x.
            //
            // Option 1: Change A.
            // We want to find the minimum positive integer A' such that A' * b <= x*x.
            // This means A' <= (x*x) / b. The smallest possible A' is 1.
            // If we change A to A', the cost is 1 (if A' != A).
            //
            // Option 2: Change B.
            // We want to find the minimum positive integer B' such that a * B' <= x*x.
            // This means B' <= (x*x) / a. The smallest possible B' is 1.
            // If we change B to B', the cost is 1 (if B' != B).
            //
            // Option 3: Change both A and B.
            // We want to find minimum positive integers A' and B' such that A' * B' <= x*x.
            // The minimum possible area is 1*1 = 1.
            // If we change both A and B, the cost is 2.
            //
            // Since we want the minimum cost, we check if 1 move is sufficient.
            //
            // Can we achieve the goal with 1 move?
            //
            // Case 1: Change A to A'. We need A' * b <= x*x.
            // The smallest possible A' is 1. If 1 * b <= x*x, and A was not 1, cost is 1.
            // More generally, we need to find if there exists a positive integer A' such that A' * b <= x*x.
            // The smallest possible value for A' is 1. If 1 * b <= x*x, we can potentially change A to 1.
            // If A was already 1, this doesn't help.
            //
            // Let's rephrase: we need to reduce the product a*b.
            // The target area is at most square_area.
            //
            // If we change A to A', we need A' * b <= square_area.
            // The smallest possible A' is 1. If 1 * b <= square_area, we can change A to 1.
            // If A was not 1, this costs 1 move.
            //
            // If we change B to B', we need a * B' <= square_area.
            // The smallest possible B' is 1. If a * 1 <= square_area, we can change B to 1.
            // If B was not 1, this costs 1 move.
            //
            // So, if we can make the area <= square_area by changing just one dimension to 1,
            // and that dimension was not already 1, the cost is 1.
            //
            // Consider the target area `target_area = square_area`.
            // We need to find minimum cost to make `new_a * new_b <= target_area`.
            //
            // Cost 0: `a * b <= target_area`. Already handled.
            //
            // Cost 1:
            // Option 1a: Change A to A'. We need A' * b <= target_area.
            // The smallest possible A' is 1. If 1 * b <= target_area, we can change A to 1.
            // If A was not 1, cost is 1.
            //
            // Option 1b: Change B to B'. We need a * B' <= target_area.
            // The smallest possible B' is 1. If a * 1 <= target_area, we can change B to 1.
            // If B was not 1, cost is 1.
            //
            // So, if `b <= target_area` (meaning we can change A to 1) OR `a <= target_area` (meaning we can change B to 1),
            // and we haven't already achieved the goal with cost 0, then the cost is 1.
            //
            // Example 1: A=2, B=3, X=2. rect_area=6, square_area=4.
            // square_area < rect_area.
            // Can we do it in 1 move?
            // Change A to A': need A' * 3 <= 4. Smallest A' is 1. 1 * 3 = 3 <= 4. Yes.
            // Since A=2 was not 1, cost is 1. (Change A to 1, area becomes 1*3=3. Or change B to 2, area becomes 2*2=4).
            // The explanation says change B to 2.
            // If we change B to B', we need 2 * B' <= 4. Smallest B' is 1. 2 * 1 = 2 <= 4. Yes.
            // Since B=3 was not 1, cost is 1. (Change B to 1, area becomes 2*1=2).
            //
            // The problem states "change any single dimension of a red object to any positive integer".
            // This means we can pick a new value for A or B.
            //
            // To make `a * b <= x*x` with minimum cost:
            //
            // Cost 0: `a * b <= x*x`.
            //
            // Cost 1:
            // We can change A to A' such that A' * b <= x*x.
            // The smallest possible A' is 1. If 1 * b <= x*x, we can achieve the goal by changing A to 1.
            // This costs 1 move.
            //
            // OR
            //
            // We can change B to B' such that a * B' <= x*x.
            // The smallest possible B' is 1. If a * 1 <= x*x, we can achieve the goal by changing B to 1.
            // This costs 1 move.
            //
            // So, if `b <= x*x` OR `a <= x*x`, we can achieve the goal with 1 move.
            //
            // Example 1: A=2, B=3, X=2. rect_area=6, square_area=4.
            // square_area < rect_area.
            // Is `b <= square_area`? 3 <= 4. Yes. So cost is 1.
            // Is `a <= square_area`? 2 <= 4. Yes. So cost is 1.
            // Minimum cost is 1.
            //
            // Example 3: A=8, B=8, X=2. rect_area=64, square_area=4.
            // square_area < rect_area.
            // Is `b <= square_area`? 8 <= 4. No.
            // Is `a <= square_area`? 8 <= 4. No.
            // So 1 move is not enough to make one dimension 1 and satisfy the condition.
            //
            // What if we change A to A' and B to B'? Cost is 2.
            // We need A' * B' <= x*x.
            // The minimum possible product A' * B' is 1 * 1 = 1.
            // Since x*x is always at least 1 (X >= 1), we can always achieve A' * B' <= x*x with 2 moves
            // by setting A'=1 and B'=1.
            // This costs 2 moves.
            //
            // So, if cost 0 is not possible, and cost 1 is not possible, then cost must be 2.
            //
            // Cost 1 is possible if:
            // We can change A to A' such that A' * b <= x*x.
            // The smallest possible A' is 1. So if 1 * b <= x*x, we can change A to 1. Cost 1.
            // OR
            // We can change B to B' such that a * B' <= x*x.
            // The smallest possible B' is 1. So if a * 1 <= x*x, we can change B to 1. Cost 1.
            //
            // So, if `b <= x*x` OR `a <= x*x`, the cost is 1.
            //
            // Let's re-verify the logic.
            // We need `new_a * new_b <= x*x`.
            //
            // If `a * b <= x*x`, cost is 0.
            //
            // If `a * b > x*x`:
            //
            // Can we achieve it with 1 move?
            //
            // Option 1: Change A to A'. We need `A' * b <= x*x`.
            // To minimize cost, we want to find if there exists *any* positive integer A' that satisfies this.
            // The smallest possible value for A' is 1.
            // If `1 * b <= x*x`, then we can change A to 1. This costs 1 move.
            //
            // Option 2: Change B to B'. We need `a * B' <= x*x`.
            // The smallest possible value for B' is 1.
            // If `a * 1 <= x*x`, then we can change B to 1. This costs 1 move.
            //
            // So, if `b <= x*x` OR `a <= x*x`, we can achieve the goal with 1 move.
            //
            // If neither of these conditions is met, it means:
            // `b > x*x` AND `a > x*x`.
            //
            // In this scenario, changing A to 1 is not enough (since 1*b > x*x).
            // And changing B to 1 is not enough (since a*1 > x*x).
            //
            // Can we achieve it with 2 moves?
            // Yes, by changing A to 1 and B to 1. The new area is 1 * 1 = 1.
            // Since X >= 1, x*x >= 1. So 1 <= x*x is always true.
            // This costs 2 moves.
            //
            // Therefore, the logic is:
            // If `a * b <= x*x`, cost is 0.
            // Else if `a <= x*x` OR `b <= x*x`, cost is 1.
            // Else, cost is 2.
            //
            // Let's test this logic with the sample cases.
            //
            // Test case 1: A=2, B=3, X=2.
            // a*b = 6, x*x = 4.
            // 6 > 4. Not cost 0.
            // Is a <= x*x? 2 <= 4. Yes.
            // Is b <= x*x? 3 <= 4. Yes.
            // Since at least one is true, cost is 1. Correct.
            //
            // Test case 2: A=4, B=3, X=4.
            // a*b = 12, x*x = 16.
            // 12 <= 16. Cost is 0. Correct.
            //
            // Test case 3: A=8, B=8, X=2.
            // a*b = 64, x*x = 4.
            // 64 > 4. Not cost 0.
            // Is a <= x*x? 8 <= 4. No.
            // Is b <= x*x? 8 <= 4. No.
            // Neither is true. Cost is 2. Correct.
            //
            // The logic seems sound.
            // The constraints A, B, X <= 10 mean `a*b` and `x*x` will not overflow `long long`.
            // `10*10 = 100`. `10*10 = 100`.
            // `long long` is overkill for these constraints but good practice.

            if (a <= square_area || b <= square_area) {
                std::cout << 1 << "\n";
            } else {
                std::cout << 2 << "\n";
            }
        }
    }
    return 0;
}