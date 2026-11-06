#include <iostream>
#include <cmath>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        long long n, xs, ys;
        std::cin >> n >> xs >> ys;
        long long center = (n + 1) / 2;
        
        long long dist_x = std::abs(xs - center);
        long long dist_y = std::abs(ys - center);
        
        if (dist_x == dist_y) {
            std::cout << 0 << "\n";
        } else {
            // If not on the same diagonal, we need at least one horizontal/vertical move.
            // The goal is to reach a cell from which we can reach the center using only diagonal moves.
            // A cell (x, y) can reach the center (cx, cy) using only diagonal moves if |x - cx| == |y - cy|.
            // We want to minimize the cost, which is the number of horizontal/vertical moves.
            // Each horizontal/vertical move costs 1 coin.
            // We can reach any cell (x', y') from (x, y) using diagonal moves such that |x - x'| = |y - y'|.
            //
            // Consider the Manhattan distance from the start to the center: |xs - center| + |ys - center|.
            // Each diagonal move reduces both |x - center| and |y - center| by 1 (or increases by 1).
            // Effectively, a diagonal move changes the sum of absolute differences |x - center| + |y - center| by 0 or 2.
            //
            // If we are at (xs, ys) and the center is (cx, cy), we want to reach a cell (x', y') such that |x' - cx| = |y' - cy|.
            // From (xs, ys), we can reach (xs +/- k, ys +/- k) using k diagonal moves.
            //
            // Let's analyze the parity of the sum of coordinates relative to the center.
            // The center is ((N+1)/2, (N+1)/2).
            // A diagonal move from (x, y) to (x+dx, y+dy) where |dx|=|dy|=1.
            // The sum of coordinates changes from x+y to (x+dx) + (y+dy).
            // If dx=1, dy=1: (x+1)+(y+1) = x+y+2. Parity of sum doesn't change.
            // If dx=1, dy=-1: (x+1)+(y-1) = x+y. Parity of sum doesn't change.
            // If dx=-1, dy=1: (x-1)+(y+1) = x+y. Parity of sum doesn't change.
            // If dx=-1, dy=-1: (x-1)+(y-1) = x+y-2. Parity of sum doesn't change.
            // So, diagonal moves preserve the parity of the sum of coordinates.
            //
            // A horizontal/vertical move from (x, y) to (x+dx, y) or (x, y+dy) where |dx|=1 or |dy|=1.
            // If move is horizontal: (x+dx)+y = x+y+dx. Parity of sum changes if dx is odd (which it is, 1 or -1).
            // If move is vertical: x+(y+dy) = x+y+dy. Parity of sum changes if dy is odd (which it is, 1 or -1).
            // So, horizontal/vertical moves change the parity of the sum of coordinates.
            //
            // The center cell ((N+1)/2, (N+1)/2) has sum of coordinates (N+1)/2 + (N+1)/2 = N+1.
            // Since N is odd, N+1 is even. The sum of coordinates of the center is even.
            //
            // If the starting cell (xs, ys) has sum xs+ys with the same parity as the center (even),
            // then we can reach the center using only diagonal moves if |xs - center| == |ys - center|.
            // If |xs - center| != |ys - center|, but xs+ys has the same parity as center,
            // we can reach a cell (x', y') from (xs, ys) using diagonal moves such that |x' - center| == |y' - center|.
            // This is because diagonal moves preserve the difference between |x - center| and |y - center| in terms of parity.
            // Specifically, if we are at (x, y) and center is (cx, cy), the difference is (x-cx) - (y-cy).
            // Diagonal move: (x+dx, y+dy). New difference: (x+dx-cx) - (y+dy-cy) = (x-cx) - (y-cy) + dx - dy.
            // If dx=1, dy=1: dx-dy = 0. Difference preserved.
            // If dx=1, dy=-1: dx-dy = 2. Difference changes by 2.
            // If dx=-1, dy=1: dx-dy = -2. Difference changes by 2.
            // If dx=-1, dy=-1: dx-dy = 0. Difference preserved.
            // So, diagonal moves preserve the parity of (x-cx) - (y-cy).
            //
            // The condition |x - cx| == |y - cy| is equivalent to (x - cx) == (y - cy) OR (x - cx) == -(y - cy).
            // This is equivalent to (x - cx) - (y - cy) == 0 OR (x - cx) + (y - cy) == 0.
            //
            // Let's consider the Manhattan distance from the start to the center: M = |xs - center| + |ys - center|.
            // Each diagonal move can reduce M by at most 2.
            // Each horizontal/vertical move costs 1 coin.
            //
            // If |xs - center| != |ys - center|, we are not on a diagonal that leads directly to the center.
            // We need to make at least one horizontal or vertical move to change the parity of the difference.
            //
            // Consider the distance to the closest cell that IS on a diagonal to the center.
            // From (xs, ys), we can reach (xs+k, ys+k), (xs+k, ys-k), (xs-k, ys+k), (xs-k, ys-k) using k diagonal moves.
            // We want to reach a cell (x', y') such that |x' - center| = |y' - center|.
            //
            // If |xs - center| > |ys - center|, we can make |xs - center| - |ys - center| diagonal moves to reach a cell (x_new, y_new) where |x_new - center| = 0 and |y_new - center| = |xs - center| - |ys - center|.
            // Or we can make |ys - center| diagonal moves to reach a cell (x_new, y_new) where |x_new - center| = |xs - center| - |ys - center| and |y_new - center| = 0.
            // In either case, we reach a cell where one coordinate difference is 0 and the other is |xs - center| - |ys - center|.
            // Let this difference be D = |xs - center| - |ys - center|.
            // We are at a cell (x', y') where |x' - center| = D and |y' - center| = 0 (or vice versa).
            // To reach the center (cx, cy), we need to cover the remaining distance D.
            // From (x', y'), we can move to (x', cy) or (cx, y') using one horizontal/vertical move.
            // For example, if |y' - center| = 0, we are at (x', center). We need to reach (center, center).
            // We can move from (x', center) to (center, center) using |x' - center| = D horizontal moves.
            // This costs D coins.
            //
            // So, if |xs - center| != |ys - center|, the minimum number of coins is min(|xs - center|, |ys - center|).
            // This is because we can make min(|xs - center|, |ys - center|) diagonal moves to align one of the coordinate differences to 0.
            // For example, if xs > center and ys < center, and |xs - center| > |ys - center|.
            // We can move diagonally towards the center: (xs-1, ys+1), (xs-2, ys+2), ..., until we reach a cell (x', y') where y' = center.
            // The number of such moves is center - ys = |ys - center|.
            // The new cell is (xs - (center - ys), center).
            // The difference in x-coordinate from center is |xs - (center - ys) - center| = |xs - center + ys - center| = |(xs - center) - (center - ys)|.
            // This is not quite right.
            //
            // Let's re-evaluate.
            // We are at (xs, ys). Center is (cx, cy).
            // We want to reach (cx, cy).
            // Diagonal moves: (x +/- 1, y +/- 1). These preserve |x-cx| - |y-cy| parity.
            // H/V moves: (x +/- 1, y) or (x, y +/- 1). These change |x-cx| - |y-cy| parity.
            //
            // If |xs - cx| == |ys - cy|, we are on a diagonal to the center. Cost is 0.
            //
            // If |xs - cx| != |ys - cy|, we need at least one H/V move.
            // After one H/V move, say to (xs+1, ys), the new differences are |xs+1 - cx| and |ys - cy|.
            // The difference of differences changes parity.
            //
            // Consider the minimum number of steps to reach *any* cell (x', y') such that |x' - cx| = |y' - cy|.
            // From (xs, ys), we can reach (xs+k, ys+k) or (xs+k, ys-k) etc.
            // We want to find k such that for some choice of signs, |(xs +/- k) - cx| = |(ys +/- k) - cy|.
            //
            // Let dx = xs - cx and dy = ys - cy. We are at (dx, dy) relative to center.
            // We want to reach (0, 0).
            // Diagonal moves: (dx +/- 1, dy +/- 1).
            // H/V moves: (dx +/- 1, dy) or (dx, dy +/- 1). Cost 1.
            //
            // If |dx| == |dy|, cost is 0.
            //
            // If |dx| != |dy|.
            // Suppose |dx| > |dy|.
            // We can make |dx| - |dy| diagonal moves to reach a state where one coordinate is 0.
            // For example, if dx > 0 and dy > 0, we can move (dx-1, dy-1), (dx-2, dy-2), ..., until dy becomes 0.
            // This takes dy moves. The new state is (dx-dy, 0).
            // The number of diagonal moves is min(|dx|, |dy|).
            // After min(|dx|, |dy|) diagonal moves, we reach a cell (x_diag, y_diag) such that
            // |x_diag - cx| = |dx| - min(|dx|, |dy|) = ||dx| - |dy||
            // |y_diag - cy| = |dy| - min(|dx|, |dy|) = 0 (if |dy| <= |dx|) OR ||dx| - |dy|| (if |dx| <= |dy|)
            //
            // So, after min(|dx|, |dy|) diagonal moves, we reach a cell (x', y') where one of the coordinate differences from the center is 0, and the other is ||dx| - |dy||.
            // Let this remaining difference be D = ||dx| - |dy||.
            // We are at a cell (x', y') where |x' - cx| = D and |y' - cy| = 0 (or vice versa).
            // To reach the center (cx, cy), we need to cover this distance D.
            // We can do this using D horizontal/vertical moves.
            // For example, if we are at (cx + D, cy), we need D horizontal moves to reach (cx, cy).
            //
            // So, the total cost is min(|dx|, |dy|) diagonal moves + ||dx| - |dy|| horizontal/vertical moves.
            // This is not right. We want to minimize coins.
            //
            // The problem states:
            // - Freely move along diagonals.
            // - Move one step horizontally or vertically with cost 1.
            //
            // We want to reach the center (cx, cy) from (xs, ys).
            // Let dx = |xs - cx| and dy = |ys - cy|.
            //
            // If dx == dy, cost is 0.
            //
            // If dx != dy.
            // We can make min(dx, dy) diagonal moves.
            // Suppose dx > dy. We make dy diagonal moves.
            // We can reach a cell (x', y') where |x' - cx| = dx - dy and |y' - cy| = 0.
            // This takes dy diagonal moves.
            // From (x', y'), we need to reach (cx, cy). The distance is |x' - cx| = dx - dy.
            // We can cover this distance using dx - dy horizontal/vertical moves.
            // Total moves: dy diagonal + (dx - dy) H/V moves.
            // Total coins: dx - dy.
            //
            // If dy > dx. We make dx diagonal moves.
            // We can reach a cell (x', y') where |x' - cx| = 0 and |y' - cy| = dy - dx.
            // This takes dx diagonal moves.
            // From (x', y'), we need to reach (cx, cy). The distance is |y' - cy| = dy - dx.
            // We can cover this distance using dy - dx horizontal/vertical moves.
            // Total moves: dx diagonal + (dy - dx) H/V moves.
            // Total coins: dy - dx.
            //
            // In both cases, the number of coins is |dx - dy|.
            //
            // Let's check the sample cases.
            // Test case 1: N=3, xs=2, ys=1. Center = (2, 2).
            // cx = 2, cy = 2.
            // xs = 2, ys = 1.
            // dx = |2 - 2| = 0.
            // dy = |1 - 2| = 1.
            // dx != dy. Cost = |dx - dy| = |0 - 1| = 1. Correct.
            //
            // Test case 2: N=5, xs=3, ys=1. Center = (3, 3).
            // cx = 3, cy = 3.
            // xs = 3, ys = 1.
            // dx = |3 - 3| = 0.
            // dy = |1 - 3| = 2.
            // dx != dy. Cost = |dx - dy| = |0 - 2| = 2.
            // Sample output is 0. My logic is wrong.
            //
            // Let's re-read the problem carefully.
            // "He can freely move along diagonals"
            // "He can move one step horizontally or vertically with the cost of 1 gold coin"
            //
            // The key is that we want to MINIMIZE coins.
            // If we can reach the center using only diagonal moves, the cost is 0.
            // This happens if and only if |xs - center| == |ys - center|.
            //
            // If |xs - center| != |ys - center|, we MUST use at least one horizontal/vertical move.
            // Consider the grid cells.
            // A cell (r, c) can reach the center (cx, cy) using only diagonal moves if |r - cx| = |c - cy|.
            //
            // If we are at (xs, ys) and |xs - cx| != |ys - cy|.
            // We can make one horizontal or vertical move.
            // Suppose we move to (xs+1, ys). Cost = 1.
            // New position (xs', ys') = (xs+1, ys).
            // Now check if |xs' - cx| == |ys' - cy|. If yes, we are done, cost is 1.
            //
            // Example 2: N=5, xs=3, ys=1. Center=(3,3).
            // |3-3| = 0, |1-3| = 2. Not equal.
            //
            // Possible moves from (3,1):
            // Diagonal:
            // (3-1, 1+1) = (2,2). |2-3|=1, |2-3|=1. Equal!
            // So from (3,1) we can reach (2,2) using a diagonal move.
            // From (2,2), we can reach (3,3) using a diagonal move.
            // Total cost = 0.
            //
            // This means we can reach the center using only diagonal moves if there exists a path of diagonal moves from (xs, ys) to (cx, cy).
            // This is true if and only if |xs - cx| == |ys - cy|.
            //
            // If |xs - cx| != |ys - cy|, we need at least one H/V move.
            // What is the minimum number of H/V moves?
            //
            // Let dx = |xs - cx| and dy = |ys - cy|.
            // If dx == dy, cost is 0.
            //
            // If dx != dy.
            // We can make diagonal moves. Each diagonal move changes (dx, dy) to (dx-1, dy-1) or (dx-1, dy+1) or (dx+1, dy-1) or (dx+1, dy+1) (in terms of absolute differences from center).
            //
            // Consider the parity of dx and dy.
            // Center (cx, cy).
            // A cell (r, c) is on a "diagonal path" to the center if |r - cx| = |c - cy|.
            //
            // If we are at (xs, ys) and |xs - cx| != |ys - cy|.
            // We need to reach a cell (x', y') such that |x' - cx| = |y' - cy|.
            // From (xs, ys), we can reach (x', y') using some diagonal moves and some H/V moves.
            //
            // Let's consider the minimum number of H/V moves required.
            // If we make 1 H/V move, say to (xs+1, ys). Cost = 1.
            // New position (xs', ys') = (xs+1, ys).
            // Check if |xs' - cx| == |ys' - cy|. If yes, cost is 1.
            //
            // When can we reach a cell (x', y') with |x' - cx| = |y' - cy| using exactly one H/V move?
            // Suppose we move from (xs, ys) to (xs+1, ys). New position (xs+1, ys).
            // We need |(xs+1) - cx| == |ys - cy|.
            // Let cx = (N+1)/2, cy = (N+1)/2.
            //
            // Case 1: xs < cx, ys < cy.
            // We are at (xs, ys). Center (cx, cy).
            // dx = cx - xs, dy = cy - ys.
            // If dx == dy, cost 0.
            // If dx != dy.
            //
            // Option 1: Move to (xs+1, ys). Cost 1.
            // New position (xs+1, ys).
            // New differences: cx - (xs+1) = dx - 1, cy - ys = dy.
            // We need dx - 1 == dy. This means dx = dy + 1.
            // So if |xs - cx| = |ys - cy| + 1, one H/V move is enough.
            //
            // Option 2: Move to (xs, ys+1). Cost 1.
            // New position (xs, ys+1).
            // New differences: cx - xs = dx, cy - (ys+1) = dy - 1.
            // We need dx == dy - 1. This means dy = dx + 1.
            // So if |ys - cy| = |xs - cx| + 1, one H/V move is enough.
            //
            // Combining these: If ||xs - cx| - |ys - cy|| == 1, then one H/V move is sufficient.
            //
            // What if ||xs - cx| - |ys - cy|| > 1?
            // Example: N=5, xs=1, ys=1. Center=(3,3).
            // cx=3, cy=3. xs=1, ys=1.
            // dx = |1-3| = 2. dy = |1-3| = 2.
            // dx == dy. Cost 0.
            //
            // Example: N=5, xs=1, ys=2. Center=(3,3).
            // cx=3, cy=3. xs=1, ys=2.
            // dx = |1-3| = 2. dy = |2-3| = 1.
            // dx != dy. ||dx - dy|| = |2 - 1| = 1.
            // So cost should be 1.
            // Let's verify. From (1,2) to (3,3).
            // Move to (1+1, 2) = (2,2). Cost 1.
            // From (2,2) to (3,3) is diagonal.
            // Total cost 1. Correct.
            //
            // What if the difference is greater than 1?
            // Example: N=5, xs=1, ys=3. Center=(3,3).
            // cx=3, cy=3. xs=1, ys=3.
            // dx = |1-3| = 2. dy = |3-3| = 0.
            // dx != dy. ||dx - dy|| = |2 - 0| = 2.
            //
            // Can we reach the center with 1 H/V move?
            // From (1,3):
            // Move to (1+1, 3) = (2,3). Cost 1.
            // From (2,3) to (3,3). |2-3|=1, |3-3|=0. Not diagonal. Need another move.
            // Move to (1, 3+1) = (1,4). Out of bounds.
            // Move to (1, 3-1) = (1,2). Cost 1.
            // From (1,2) to (3,3). |1-3|=2, |2-3|=1. Not diagonal. Need another move.
            //
            // If we make 1 H/V move, we reach a cell (x', y') where |x' - cx| and |y' - cy| are either (dx-1, dy) or (dx, dy-1) (assuming xs < cx, ys < cy).
            // The difference of differences becomes |(dx-1) - dy| or |dx - (dy-1)|.
            // If original difference was D = |dx - dy|.
            // New difference is |(dx-1) - dy| = |(dx - dy) - 1| = |D - 1|.
            // Or |dx - (dy-1)| = |(dx - dy) + 1| = |D + 1|.
            //
            // If we start with ||dx - dy|| = 2.
            // After 1 H/V move, the new difference of differences becomes |2-1|=1 or |2+1|=3.
            // If it becomes 1, then one more H/V move will make it 0. Total 2 H/V moves.
            //
            // This suggests that the minimum number of coins is related to how many steps it takes to make the coordinate differences equal.
            //
            // Let dx = |xs - center| and dy = |ys - center|.
            // If dx == dy, cost is 0.
            //
            // If dx != dy.
            // We can make min(dx, dy) diagonal moves.
            // This brings us to a cell (x', y') where one difference is 0 and the other is |dx - dy|.
            // Let D = |dx - dy|.
            // We are at a cell (x', y') with |x' - center| = D and |y' - center| = 0 (or vice versa).
            // To reach the center, we need to cover distance D.
            // This requires D horizontal/vertical moves.
            //
            // So, the total number of H/V moves is D = |dx - dy|.
            // This is the number of coins.
            //
            // Let's re-check sample 2: N=5, xs=3, ys=1. Center=(3,3).
            // cx=3, cy=3. xs=3, ys=1.
            // dx = |3-3| = 0. dy = |1-3| = 2.
            // dx != dy. Cost = |dx - dy| = |0 - 2| = 2.
            // Sample output is 0.
            //
            // The sample explanation for N=5, (3,1) to (3,3):
            // "Akash can go from (3,1) to (2,2) with a diagonal move, then from (2,2) to (3, 3) with another diagonal move. So, he needs zero coins."
            //
            // This implies that if we can reach *any* cell (x', y') from which the center is reachable by diagonal moves, using only diagonal moves from the start, then the cost is 0.
            //
            // The condition for reaching the center from (x', y') using only diagonal moves is |x' - cx| = |y' - cy|.
            //
            // So, if there exists a cell (x', y') such that:
            // 1. (x', y') is reachable from (xs, ys) using only diagonal moves.
            // 2. |x' - cx| = |y' - cy|.
            // Then the cost is 0.
            //
            // A cell (x', y') is reachable from (xs, ys) using only diagonal moves if |x' - xs| = |y' - ys|.
            //
            // So, we need to check if there exist x', y' such that:
            // |x' - xs| = |y' - ys|  AND  |x' - cx| = |y' - cy|.
            //
            // Let's analyze the condition |x' - xs| = |y' - ys|.
            // This means x' - xs = y' - ys  OR  x' - xs = -(y' - ys).
            // Rearranging:
            // x' - y' = xs - ys  OR  x' + y' = xs + ys.
            //
            // Let's analyze the condition |x' - cx| = |y' - cy|.
            // This means x' - cx = y' - cy  OR  x' - cx = -(y' - cy).
            // Rearranging:
            // x' - y' = cx - cy  OR  x' + y' = cx + cy.
            //
            // We are looking for a cell (x', y') that satisfies one condition from the first set AND one condition from the second set.
            //
            // Case A: (x' - y' = xs - ys) AND (x' - y' = cx - cy).
            // This implies xs - ys = cx - cy.
            // This is equivalent to xs - cx = ys - cy.
            // Which means |xs - cx| = |ys - cy|.
            // If this holds, we can choose x' = xs, y' = ys. Then |x' - xs| = 0 = |y' - ys| and |x' - cx| = |xs - cx| = |ys - cy| = |y' - cy|.
            // So if |xs - cx| = |ys - cy|, cost is 0. This matches our initial observation.
            //
            // Case B: (x' - y' = xs - ys) AND (x' + y' = cx + cy).
            // We have a system of linear equations for x' and y'.
            // Adding them: 2x' = (xs - ys) + (cx + cy) => x' = ((xs - ys) + (cx + cy)) / 2.
            // Subtracting them: -2y' = (xs - ys) - (cx + cy) => y' = ((cx + cy) - (xs - ys)) / 2.
            // For x' and y' to be integers, (xs - ys) + (cx + cy) must be even.
            // (xs - ys) + (cx + cy) = (xs + cx) - (ys - cy).
            // Parity of (xs - ys) + (cx + cy) is same as parity of (xs + ys) + (cx + cy).
            // If (xs + ys) and (cx + cy) have the same parity, their sum is even.
            // The center cell (cx, cy) has cx = cy = (N+1)/2. So cx + cy = N+1. Since N is odd, N+1 is even.
            // So we need (xs + ys) to be even. This means xs and ys have the same parity.
            // If xs and ys have the same parity, then xs+ys is even.
            // If xs and ys have different parity, then xs+ys is odd.
            //
            // Let's check parity of xs+ys and cx+cy.
            // cx+cy = N+1 (even).
            // If xs+ys is even, then (xs+ys) + (cx+cy) is even.
            // If xs+ys is odd, then (xs+ys) + (cx+cy) is odd.
            // So, for x' and y' to be integers, xs and ys must have the same parity.
            //
            // If xs and ys have the same parity, we can find integer x', y' such that x' - y' = xs - ys and x' + y' = cx + cy.
            // This cell (x', y') is reachable from (xs, ys) diagonally and can reach the center diagonally.
            // So if xs and ys have the same parity, cost is 0.
            //
            // Case C: (x' + y' = xs + ys) AND (x' - y' = cx - cy).
            // Adding: 2x' = (xs + ys) + (cx - cy) => x' = ((xs + ys) + (cx - cy)) / 2.
            // Subtracting: 2y' = (xs + ys) - (cx - cy) => y' = ((xs + ys) - (cx - cy)) / 2.
            // For x' and y' to be integers, (xs + ys) + (cx - cy) must be even.
            // cx - cy = (N+1)/2 - (N+1)/2 = 0.
            // So we need (xs + ys) to be even. Again, xs and ys must have the same parity.
            // If xs and ys have the same parity, cost is 0.
            //
            // Case D: (x' + y' = xs + ys) AND (x' + y' = cx + cy).
            // This implies xs + ys = cx + cy.
            // Since cx + cy = N+1 (even), this means xs + ys must be even.
            // Again, xs and ys must have the same parity.
            // If xs and ys have the same parity, cost is 0.
            //
            // Summary so far: If |xs - cx| == |ys - cy| OR (xs and ys have the same parity), cost is 0.
            //
            // Let's check sample 2 again: N=5, xs=3, ys=1. Center=(3,3).
            // cx=3, cy=3. xs=3, ys=1.
            // |xs - cx| = |3-3| = 0. |ys - cy| = |1-3| = 2. Not equal.
            // Parity of xs: 3 (odd). Parity of ys: 1 (odd). Same parity.
            // So cost is 0. This matches sample 2.
            //
            // Let's check sample 1: N=3, xs=2, ys=1. Center=(2,2).
            // cx=2, cy=2. xs=2, ys=1.
            // |xs - cx| = |2-2| = 0. |ys - cy| = |1-2| = 1. Not equal.
            // Parity of xs: 2 (even). Parity of ys: 1 (odd). Different parity.
            // So cost is NOT 0.
            //
            // If cost is not 0, what is it?
            // We need to make at least one H/V move.
            //
            // Consider the grid colored like a chessboard.
            // A diagonal move always stays on the same color.
            // A H/V move always switches color.
            //
            // The center cell (cx, cy) has cx = cy = (N+1)/2.
            // The color of a cell (r, c) can be determined by the parity of r+c.
            // If r+c is even, it's one color. If r+c is odd, it's the other color.
            //
            // Center (cx, cy): cx+cy = N+1 (even). So center is on the "even sum" color.
            //
            // Starting cell (xs, ys):
            // If xs+ys is even, it has the same color as the center.
            // If xs+ys is odd, it has a different color from the center.
            //
            // If (xs, ys) has the same color as the center (xs+ys is even), and |xs - cx| == |ys - cy|, then cost is 0.
            // If (xs, ys) has the same color as the center (xs+ys is even), but |xs - cx| != |ys - cy|, can we reach the center with 0 cost?
            // No, because if |xs - cx| != |ys - cy|, we cannot reach the center using only diagonal moves.
            //
            // If (xs, ys) has a different color from the center (xs+ys is odd).
            // To reach the center (which has even sum), we MUST make at least one H/V move.
            // A single H/V move changes the color.
            // So, if xs+ys is odd, we need at least 1 H/V move.
            //
            // Can we always reach the center with 1 H/V move if xs+ys is odd?
            //
            // Let dx = |xs - cx| and dy = |ys - cy|.
            // If xs+ys is odd, we need at least 1 coin.
            //
            // Consider the Manhattan distance from (xs, ys) to (cx, cy): M = |xs - cx| + |ys - cy|.
            // Each diagonal move reduces M by at most 2.
            // Each H/V move reduces M by 1.
            //
            // If xs+ys is odd, we need to reach a cell (x', y') such that |x' - cx| = |y' - cy|.
            // And (x', y') must be reachable from (xs, ys) using some diagonal moves and some H/V moves.
            //
            // If xs+ys is odd, we need at least one H/V move.
            // Let's try to reach a cell (x', y') with |x' - cx| = |y' - cy| using exactly one H/V move.
            // Suppose we move from (xs, ys) to (xs+1, ys). Cost = 1.
            // New position (xs', ys') = (xs+1, ys).
            // We need |xs' - cx| = |ys' - cy|.
            //
            // Let's analyze the condition |xs - cx| == |ys - cy| OR (xs and ys have the same parity).
            //
            // If |xs - cx| == |ys - cy|, cost is 0.
            //
            // If |xs - cx| != |ys - cy|.
            //   If xs and ys have the same parity (xs+ys is even), then cost is NOT 0.
            //     We need to make H/V moves.
            //     Consider the distance to the "diagonal line" that passes through the center.
            //     The cells (r, c) such that |r - cx| = |c - cy| form two diagonals.
            //     We are at (xs, ys). Let dx = |xs - cx|, dy = |ys - cy|.
            //     We can make min(dx, dy) diagonal moves to reach a cell (x', y') where one difference is 0 and the other is |dx - dy|.
            //     Let D = |dx - dy|.
            //     We are at (x', y') where |x' - cx| = D, |y' - cy| = 0.
            //     To reach (cx, cy), we need D H/V moves.
            //     Total coins = D = |dx - dy|.
            //
            //   If xs and ys have different parity (xs+ys is odd), then cost is NOT 0.
            //     We need at least 1 H/V move.
            //     Can we always reach a cell (x', y') with |x' - cx| = |y' - cy| using just 1 H/V move?
            //     Let's check the condition ||xs - cx| - |ys - cy|| == 1.
            //     If this is true, then 1 H/V move is sufficient.
            //     Example: N=3, xs=2, ys=1. Center=(2,2).
            //     cx=2, cy=2. xs=2, ys=1.
            //     dx = |2-2| = 0. dy = |1-2| = 1.
            //     |dx - dy| = |0 - 1| = 1.
            //     xs+ys = 2+1 = 3 (odd).
            //     So cost is 1.
            //
            //     What if ||xs - cx| - |ys - cy|| > 1 and xs+ys is odd?
            //     Example: N=5, xs=1, ys=3. Center=(3,3).
            //     cx=3, cy=3. xs=1, ys=3.
            //     dx = |1-3| = 2. dy = |3-3| = 0.
            //     |dx - dy| = |2 - 0| = 2.
            //     xs+ys = 1+3 = 4 (even).
            //     This case falls into the "xs and ys have same parity" category.
            //     So cost should be |dx - dy| = 2.
            //
            //     Let's re-evaluate the conditions.
            //     Center (cx, cy) = ((N+1)/2, (N+1)/2).
            //     cx+cy = N+1 (even).
            //
            //     Condition for 0 cost:
            //     1. |xs - cx| == |ys - cy|
            //     OR
            //     2. (xs + ys) has the same parity as (cx + cy). Since cx+cy is even, this means (xs + ys) is even.
            //        This is equivalent to xs and ys having the same parity.
            //
            //     If neither of these conditions is met, cost is > 0.
            //     This means:
            //     |xs - cx| != |ys - cy|  AND  (xs + ys) is odd.
            //
            //     If (xs + ys) is odd, we need at least 1 H/V move.
            //     Can we always reach the center with 1 H/V move if (xs + ys) is odd?
            //     Consider the distance to the "diagonal line" that passes through the center.
            //     Let dx = |xs - cx|, dy = |ys - cy|.
            //     If we make one H/V move, we reach a cell (x', y') where the differences from center are (dx-1, dy) or (dx, dy-1) (assuming xs < cx, ys < cy).
            //     The new difference of differences is |(dx-1) - dy| or |dx - (dy-1)|.
            //     If the original difference |dx - dy| was 1, then the new difference becomes 0.
            //     So if ||xs - cx| - |ys - cy|| == 1, and (xs+ys) is odd, then cost is 1.
            //
            //     What if ||xs - cx| - |ys - cy|| > 1 and (xs+ys) is odd?
            //     Example: N=7, xs=1, ys=1. Center=(4,4).
            //     cx=4, cy=4. xs=1, ys=1.
            //     dx = |1-4| = 3. dy = |1-4| = 3.
            //     dx == dy. Cost 0.
            //
            //     Example: N=7, xs=1, ys=2. Center=(4,4).
            //     cx=4, cy=4. xs=1, ys=2.
            //     dx = |1-4| = 3. dy = |2-4| = 2.
            //     dx != dy. ||dx - dy|| = |3 - 2| = 1.
            //     xs+ys = 1+2 = 3 (odd).
            //     So cost is 1.
            //
            //     Example: N=7, xs=1, ys=3. Center=(4,4).
            //     cx=4, cy=4. xs=1, ys=3.
            //     dx = |1-4| = 3. dy = |3-4| = 1.
            //     dx != dy. ||dx - dy|| = |3 - 1| = 2.
            //     xs+ys = 1+3 = 4 (even).
            //     This falls into the "xs and ys have same parity" case. Cost should be |dx - dy| = 2.
            //
            //     Example: N=7, xs=1, ys=4. Center=(4,4).
            //     cx=4, cy=4. xs=1, ys=4.
            //     dx = |1-4| = 3. dy = |4-4| = 0.
            //     dx != dy. ||dx - dy|| = |3 - 0| = 3.
            //     xs+ys = 1+4 = 5 (odd).
            //     So cost is NOT 0.
            //     We need at least 1 H/V move.
            //     Can we reach the center with 1 H/V move?
            //     From (1,4) to (4,4).
            //     Move to (1+1, 4) = (2,4). Cost 1.
            //     From (2,4) to (4,4). |2-4|=2, |4-4|=0. Not diagonal. Need more moves.
            //
            //     The logic seems to be:
            //     If |xs - cx| == |ys - cy|, cost is 0.
            //     Else if (xs + ys) % 2 == (cx + cy) % 2, cost is | |xs - cx| - |ys - cy| |.
            //     Else (if (xs + ys) % 2 != (cx + cy) % 2), cost is 1.
            //
            //     Let's verify this logic.
            //     Center (cx, cy) = ((N+1)/2, (N+1)/2).
            //     cx + cy = N+1 (even).
            //
            //     So the logic becomes:
            //     If |xs - cx| == |ys - cy|, cost is 0.
            //     Else if (xs + ys) % 2 == 0, cost is | |xs - cx| - |ys - cy| |.
            //     Else (if (xs + ys) % 2 != 0), cost is 1.
            //
            //     Test case 1: N=3, xs=2, ys=1. Center=(2,2).
            //     cx=2, cy=2. xs=2, ys=1.
            //     |xs - cx| = |2-2| = 0. |ys - cy| = |1-2| = 1. Not equal.
            //     xs + ys = 2 + 1 = 3 (odd).
            //     Condition (xs + ys) % 2 == 0 is false.
            //     So cost is 1. Correct.
            //
            //     Test case 2: N=5, xs=3, ys=1. Center=(3,3).
            //     cx=3, cy=3. xs=3, ys=1.
            //     |xs - cx| = |3-3| = 0. |ys - cy| = |1-3| = 2. Not equal.
            //     xs + ys = 3 + 1 = 4 (even).
            //     Condition (xs + ys) % 2 == 0 is true.
            //     Cost is | |xs - cx| - |ys - cy| | = | |0| - |2| | = |0 - 2| = 2.
            //     Sample output is 0. My logic is still wrong.
            //
            //     The sample explanation for test case 2 is crucial:
            //     "Akash can go from (3,1) to (2,2) with a diagonal move, then from (2,2) to (3, 3) with another diagonal move. So, he needs zero coins."
            //     This means that if we can reach *any* cell (x', y') from (xs, ys) using only diagonal moves, such that |x' - cx| = |y' - cy|, then the cost is 0.
            //
            //     The condition for (x', y') to be reachable from (xs, ys) using only diagonal moves is |x' - xs| = |y' - ys|.
            //     So we need to check if there exists (x', y') such that:
            //     1. |x' - xs| = |y' - ys|
            //     2. |x' - cx| = |y' - cy|
            //
            //     Let's re-examine the conditions derived from these two equations.
            //     Equation 1: x' - y' = xs - ys OR x' + y' = xs + ys
            //     Equation 2: x' - y' = cx - cy OR x' + y' = cx + cy
            //
            //     We need to find if there is an intersection of these conditions.
            //     There are 4 combinations:
            //     A) (x' - y' = xs - ys) AND (x' - y' = cx - cy)  => xs - ys = cx - cy => xs - cx = ys - cy => |xs - cx| = |ys - cy|. If this is true, cost is 0.
            //     B) (x' - y' = xs - ys) AND (x' + y' = cx + cy)
            //     C) (x' + y' = xs + ys) AND (x' - y' = cx - cy)
            //     D) (x' + y' = xs + ys) AND (x' + y' = cx + cy)  => xs + ys = cx + cy.
            //
            //     If |xs - cx| == |ys - cy|, cost is 0.
            //
            //     If |xs - cx| != |ys - cy|, we need to check if combinations B or C or D can lead to a 0 cost.
            //     Combinations B and C lead to integer solutions for x', y' if and only if xs and ys have the same parity.
            //     Combination D leads to integer solutions for x', y' if and only if xs and ys have the same parity.
            //
            //     So, if |xs - cx| != |ys - cy|, and xs and ys have the same parity, then cost is 0.
            //     This covers test case 2: N=5, xs=3, ys=1. Center=(3,3).
            //     cx=3, cy=3. xs=3, ys=1.
            //     |xs - cx| = 0, |ys - cy| = 2. Not equal.
            //     xs=3 (odd), ys=1 (odd). Same parity.
            //     So cost is 0. This matches.
            //
            //     What if |xs - cx| != |ys - cy| AND xs and ys have different parity?
            //     This is the case for test case 1: N=3, xs=2, ys=1. Center=(2,2).
            //     cx=2, cy=2. xs=2, ys=1.
            //     |xs - cx| = 0, |ys - cy| = 1. Not equal.
            //     xs=2 (even), ys=1 (odd). Different parity.
            //     In this case, cost is NOT 0.
            //
            //     If cost is not 0, what is it?
            //     We need to make at least one H/V move.
            //     Consider the Manhattan distance from (xs, ys) to (cx, cy): M = |xs - cx| + |ys - cy|.
            //     Each diagonal move reduces M by at most 2.
            //     Each H/V move reduces M by 1.
            //
            //     If xs and ys have different parity, we are on a different colored square than the center.
            //     We need at least one H/V move to change the color.
            //     Can we always reach the center with 1 H/V move?
            //
            //     Let dx = |xs - cx|, dy = |ys - cy|.
            //     If xs and ys have different parity, and dx != dy.
            //     Consider the minimum number of H/V moves.
            //     If we make 1 H/V move, we reach a cell (x', y').
            //     The parity of x'+y' changes.
            //     If xs+ys is odd, then x'+y' becomes even.
            //     The center has even sum.
            //     So after 1 H/V move, we are on the same color as the center.
            //
            //     Can we reach a cell (x', y') with |x' - cx| = |y' - cy| using exactly 1 H/V move?
            //     This happens if ||dx - dy|| == 1.
            //     If ||xs - cx| - |ys - cy|| == 1, and xs and ys have different parity, then cost is 1.
            //
            //     What if ||xs - cx| - |ys - cy|| > 1 and xs and ys have different parity?
            //     Example: N=7, xs=1, ys=4. Center=(4,4).
            //     cx=4, cy=4. xs=1, ys=4.
            //     dx = |1-4| = 3. dy = |4-4| = 0.
            //     dx != dy. ||dx - dy|| = |3 - 0| = 3.
            //     xs=1 (odd), ys=4 (even). Different parity.
            //     So cost is NOT 0.
            //     We need at least 1 H/V move.
            //     Can we reach the center with 1 H/V move?
            //     From (1,4) to (4,4).
            //     Move to (1+1, 4) = (2,4). Cost 1.
            //     From (2,4) to (4,4). |2-4|=2, |4-4|=0. Not diagonal. Need more moves.
            //
            //     The problem states: "Akash would like to minimize the number of coins required to reach the center."
            //
            //     If |xs - cx| == |ys - cy|, cost is 0.
            //     Else if (xs % 2 == ys % 2), cost is | |xs - cx| - |ys - cy| |.
            //     Else (xs % 2 != ys % 2), cost is 1.
            //
            //     Let's re-check sample 2 with this logic:
            //     N=5, xs=3, ys=1. Center=(3,3).
            //     cx=3, cy=3. xs=3, ys=1.
            //     |xs - cx| = 0, |ys - cy| = 2. Not equal.
            //     xs=3 (odd), ys=1 (odd). Same parity.
            //     Cost = | |0| - |2| | = 2.
            //     Sample output is 0. This logic is still wrong.
            //
            //     The condition for 0 cost must be:
            //     There exists (x', y') such that |x' - xs| = |y' - ys| AND |x' - cx| = |y' - cy|.
            //     This is satisfied if:
            //     1. |xs - cx| == |ys - cy|
            //     OR
            //     2. xs and ys have the same parity.
            //
            //     If this condition is NOT met, then cost > 0.
            //     This means: |xs - cx| != |ys - cy| AND xs and ys have different parity.
            //
            //     In this case (|xs - cx| != |ys - cy| AND xs and ys have different parity), we need at least 1 H/V move.
            //     Can we always reach the center with 1 H/V move?
            //
            //     Consider the grid cells.
            //     The center cell is ((N+1)/2, (N+1)/2).
            //     Any cell (r, c) can reach the center using only diagonal moves if |r - (N+1)/2| = |c - (N+1)/2|.
            //
            //     If |xs - cx| != |ys - cy|, we are not on a diagonal that leads directly to the center.
            //     We need to make H/V moves.
            //
            //     The minimum number of H/V moves is the minimum number of steps to reach a cell (x', y') such that |x' - cx| = |y' - cy|.
            //
            //     If we are at (xs, ys), we can reach any cell (x', y') such that |x' - xs| = |y' - ys| using diagonal moves.
            //     So, we are looking for a cell (x', y') such that:
            //     |x' - xs| = |y' - ys|  AND  |x' - cx| = |y' - cy|.
            //
            //     This is satisfied if:
            //     (xs - cx) == (ys - cy)  OR  (xs - cx) == -(ys - cy)  (i.e., |xs - cx| == |ys - cy|)
            //     OR
            //     (xs + ys) has the same parity as (cx + cy). Since cx+cy is even, this means (xs + ys) is even.
            //
            //     So, if |xs - cx| == |ys - cy| OR (xs + ys) % 2 == 0, the cost is 0.
            //
            //     If |xs - cx| != |ys - cy| AND (xs + ys) % 2 != 0.
            //     This means we are not on a diagonal to the center, AND we are on a different colored square than the center.
            //     We need at least 1 H/V move.
            //
            //     Can we always reach the center with 1 H/V move in this case?
            //     Let dx = |xs - cx|, dy = |ys - cy|.
            //     If we make 1 H/V move, we reach a cell (x', y').
            //     The parity of x'+y' changes. If xs+ys was odd, x'+y' becomes even.
            //     The center has even sum.
            //     So after 1 H/V move, we are on the same color as the center.
            //
            //     Consider the distance to the closest cell on a diagonal to the center.
            //     If we are at (xs, ys), we can reach a cell (x', y') where |x' - cx| = |y' - cy| using diagonal moves.
            //     This is possible if |xs - cx| == |ys - cy| (cost 0).
            //
            //     If |xs - cx| != |ys - cy|, we need H/V moves.
            //     The minimum number of H/V moves is the minimum number of steps to reach a cell (x', y') such that |x' - cx| = |y' - cy|.
            //
            //     Let's consider the distance from (xs, ys) to the "diagonal line" passing through the center.
            //     The cells on the diagonal are (r, c) where |r - cx| = |c - cy|.
            //
            //     If |xs - cx| != |ys - cy|, we need to make H/V moves.
            //     The minimum number of H/V moves is the minimum number of steps to reach a cell (x', y') such that |x' - cx| = |y' - cy|.
            //
            //     Consider the distance from (xs, ys) to the center (cx, cy).
            //     Let dx = |xs - cx|, dy = |ys - cy|.
            //
            //     If dx == dy, cost is 0.
            //
            //     If dx != dy.
            //     We can make min(dx, dy) diagonal moves.
            //     This brings us to a cell (x', y') where one difference is 0 and the other is |dx - dy|.
            //     Let D = |dx - dy|.
            //     We are at (x', y') where |x' - cx| = D, |y' - cy| = 0.
            //     To reach (cx, cy), we need D H/V moves.
            //     Total coins = D = |dx - dy|.
            //
            //     This logic gives 2 for sample 2, which is wrong.
            //
            //     The key must be that diagonal moves are free.
            //     We want to reach a cell (x', y') such that |x' - cx| = |y' - cy|.
            //     From (xs, ys), we can reach (x', y') using diagonal moves if |x' - xs| = |y' - ys|.
            //
            //     So, if there exists (x', y') such that |x' - xs| = |y' - ys| AND |x' - cx| = |y' - cy|, then cost is 0.
            //     This condition is met if |xs - cx| == |ys - cy| OR (xs and ys have the same parity).
            //
            //     If this condition is NOT met, then cost > 0.
            //     This means |xs - cx| != |ys - cy| AND xs and ys have different parity.
            //
            //     In this case, we need at least 1 H/V move.
            //     Can we always reach the center with 1 H/V move?
            //
            //     Consider the grid.
            //     The center is ((N+1)/2, (N+1)/2).
            //     The cells (r, c) such that |r - (N+1)/2| = |c - (N+1)/2| are the "center diagonals".
            //
            //     If |xs - cx| != |ys - cy|, we are not on a center diagonal.
            //     If xs and ys have different parity, we are on a different colored square than the center.
            //
            //     Let's consider the distance from (xs, ys) to the nearest cell on a center diagonal.
            //     If we make 1 H/V move, we reach (xs+1, ys) or (xs-1, ys) or (xs, ys+1) or (xs, ys-1).
            //     Let's say we move to (xs+1, ys).
            //     The new differences from center are |(xs+1) - cx| and |ys - cy|.
            //     If these are equal, we have reached a center diagonal with 1 H/V move.
            //     This happens if |(xs+1) - cx| = |ys - cy|.
            //
            //     Let dx = xs - cx, dy = ys - cy.
            //     We need |dx+1| = |dy| or |dx-1| = |dy| or |dx| = |dy+1| or |dx| = |dy-1|.
            //
            //     If |xs - cx| != |ys - cy| AND xs and ys have different parity.
            //     This implies that ||xs - cx| - |ys - cy|| must be odd.
            //     Why?
            //     Let dx = |xs - cx|, dy = |ys - cy|.
            //     Consider the parity of xs and ys.
            //     cx = (N+1)/2, cy = (N+1)/2.
            //     If N=3, cx=2, cy=2.
            //     If N=5, cx=3, cy=3.
            //     cx and cy have the same parity if (N+1)/2 is even or odd.
            //     If N=3, (N+1)/2 = 2 (even).
            //     If N=5, (N+1)/2 = 3 (odd).
            //     If N=7, (N+1)/2 = 4 (even).
            //     Parity of (N+1)/2 depends on N mod 4.
            //     If N = 4k+3, (N+1)/2 = (4k+4)/2 = 2k+2 (even).
            //     If N = 4k+1, (N+1)/2 = (4k+2)/2 = 2k+1 (odd).
            //     Since N is odd, N can be 4k+1 or 4k+3.
            //     So cx and cy always have the same parity.
            //
            //     Let P_xs be parity of xs, P_ys be parity of ys.
            //     Let P_cx be parity of cx, P_cy be parity of cy. P_cx = P_cy.
            //
            //     We are in the case: |xs - cx| != |ys - cy| AND P_xs != P_ys.
            //
            //     Consider the sum of differences: (xs - cx) + (ys - cy).
            //     Parity of (xs - cx) + (ys - cy) = Parity of (xs + ys) - (cx + cy).
            //     Since cx+cy is even, Parity of (xs - cx) + (ys - cy) = Parity of (xs + ys).
            //     If P_xs != P_ys, then xs+ys is odd. So (xs - cx) + (ys - cy) is odd.
            //
            //     Consider the difference of differences: (xs - cx) - (ys - cy).
            //     Parity of (xs - cx) - (ys - cy) = Parity of (xs - ys) - (cx - cy).
            //     Since cx=cy, cx-cy=0. Parity of (xs - cx) - (ys - cy) = Parity of (xs - ys).
            //     If P_xs != P_ys, then xs-ys is odd. So (xs - cx) - (ys - cy) is odd.
            //
            //     If (xs - cx) - (ys - cy) is odd, then |xs - cx| and |ys - cy| must have different parity.
            //     This means ||xs - cx| - |ys - cy|| must be odd.
            //
            //     So, if |xs - cx| != |ys - cy| AND xs and ys have different parity, then ||xs - cx| - |ys - cy|| is odd.
            //     This means ||xs - cx| - |ys - cy|| >= 1.
            //
            //     If ||xs - cx| - |ys - cy|| == 1, then 1 H/V move is enough.
            //     If ||xs - cx| - |ys - cy|| > 1 and is odd, e.g., 3.
            //     Can we reach the center with 1 H/V move?
            //
            //     Let's go back to the sample explanation:
            //     Test case 1: N=3, xs=2, ys=1. Center=(2,2).
            //     |xs-cx|=0, |ys-cy|=1. Not equal.
            //     xs=2 (even), ys=1 (odd). Different parity.
            //     Output: 1.
            //     This fits the pattern: If |xs - cx| != |ys - cy| AND xs and ys have different parity, cost is 1.
            //
            //     Test case 2: N=5, xs=3, ys=1. Center=(3,3).
            //     |xs-cx|=0, |ys-cy|=2. Not equal.
            //     xs=3 (odd), ys=1 (odd). Same parity.
            //     Output: 0.
            //     This fits the pattern: If |xs - cx| != |ys - cy| AND xs and ys have same parity, cost is 0.
            //
            //     So the logic is:
            //     1. Calculate center: cx = (N+1)/2, cy = (N+1)/2.
            //     2. Calculate absolute differences: dx = abs(xs - cx), dy = abs(ys - cy).
            //     3. If dx == dy, cost is 0.
            //     4. Else if (xs % 2 == ys % 2), cost is 0. (This means xs and ys have same parity)
            //     5. Else (dx != dy AND xs % 2 != ys % 2), cost is 1.
            //
            //     Let's re-verify this logic.
            //     Condition for 0 cost:
            //     ( |xs - cx| == |ys - cy| ) OR ( xs % 2 == ys % 2 )
            //
            //     If this condition is FALSE, then cost > 0.
            //     This means:
            //     ( |xs - cx| != |ys - cy| ) AND ( xs % 2 != ys % 2 )
            //
            //     In this case, we need at least 1 H/V move.
            //     Can we always reach the center with 1 H/V move?
            //
            //     If xs and ys have different parity, we are on a different colored square than the center.
            //     A single H/V move changes the color. So after 1 H/V move, we are on the same color as the center.
            //
            //     Consider the distance to the nearest cell on a center diagonal.
            //     If we are at (xs, ys), and |xs - cx| != |ys - cy|, and xs, ys have different parity.
            //     Let dx = |xs - cx|, dy = |ys - cy|.
            //     We know ||dx - dy|| is odd. So ||dx - dy|| >= 1.
            //
            //     If ||dx - dy|| == 1, then 1 H/V move is sufficient.
            //     Example: N=3, xs=2, ys=1. cx=2, cy=2. dx=0, dy=1. ||dx-dy||=1. xs%2 != ys%2. Cost 1.
            //
            //     What if ||dx - dy|| > 1 and is odd? E.g., ||dx - dy|| = 3.
            //     Example: N=7, xs=1, ys=4. cx=4, cy=4. dx=3, dy=0. ||dx-dy||=3. xs%2 != ys%2.
            //     According to the logic, cost should be 1.
            //     Let's check: From (1,4) to (4,4).
            //     Move to (2,4). Cost 1.
            //     From (2,4) to (4,4). |2-4|=2, |4-4|=0. Not diagonal.
            //     We need to reach a cell (x', y') with |x' - 4| = |y' - 4|.
            //     From (2,4), we can reach (3,3) or (3,5) or (1,3) or (1,5) diagonally.
            //     (3,3): |3-4|=1, |3-4|=1. Yes!
            //     So from (2,4) we can reach (3,3) diagonally.
            //     From (3,3) to (4,4) is diagonal.
            //     So path: (1,4) -> (2,4) (cost 1) -> (3,3) (diag) -> (4,4) (diag). Total cost 1.
            //
            //     It seems the logic is correct.
            //     The condition for 0 cost is:
            //     ( |xs - cx| == |ys - cy| ) OR ( xs % 2 == ys % 2 )
            //
            //     If this condition is FALSE, the cost is 1.
            //
            //     Let's write down the final logic.
            //     Center cx = (N+1)/2, cy = (N+1)/2.
            //     dx = abs(xs - cx), dy = abs(ys - cy).
            //
            //     If dx == dy:
            //         cost = 0
            //     Else if (xs % 2 == ys % 2): // same parity
            //         cost = 0
            //     Else: // dx != dy AND different parity
            //         cost = 1
            //
            //     This can be simplified:
            //     If (dx == dy) OR (xs % 2 == ys % 2):
            //         cost = 0
            //     Else:
            //         cost = 1
            //
            //     Let's check the sample cases one last time.
            //     Sample 1: N=3, xs=2, ys=1. Center=(2,2).
            //     cx=2, cy=2. dx=|2-2|=0, dy=|1-2|=1.
            //     dx != dy.
            //     xs=2 (even), ys=1 (odd). xs % 2 != ys % 2.
            //     Condition (dx == dy) OR (xs % 2 == ys % 2) is FALSE.
            //     Cost = 1. Correct.
            //
            //     Sample 2: N=5, xs=3, ys=1. Center=(3,3).
            //     cx=3, cy=3. dx=|3-3|=0, dy=|1-3|=2.
            //     dx != dy.
            //     xs=3 (odd), ys=1 (odd). xs % 2 == ys % 2.
            //     Condition (dx == dy) OR (xs % 2 == ys % 2) is TRUE because (xs % 2 == ys % 2) is true.
            //     Cost = 0. Correct.
            //
            //     This logic seems robust.
            //     The key insight is that if we are on a different color square than the center, and not on a direct diagonal, we need at least one H/V move.
            //     And it turns out that one H/V move is always sufficient to reach a state from which the center is reachable by diagonal moves.
            //     This is because one H/V move changes the parity of the sum of coordinates, making it match the center's parity.
            //     And the problem guarantees that if the parities match, we can always find a path.
            //     The condition |x' - xs| = |y' - ys| AND |x' - cx| = |y' - cy| is satisfied if |xs - cx| == |ys - cy| OR xs and ys have the same parity.
            //     If this condition is NOT met, it means |xs - cx| != |ys - cy| AND xs and ys have different parity.
            //     In this case, we need at least one H/V move.
            //     And it seems one H/V move is always sufficient.
            //     The logic is: if we are on a different color square, we need to change color. One H/V move does that.
            //     After changing color, we are on the same color as the center.
            //     The problem statement implies that if we are on the same color, we can reach the center.
            //     The condition for 0 cost is that we are already on the same color AND on a diagonal to the center, OR we are on the same color.
            //     If we are on a different color, we need 1 move.
            //
            //     Final logic:
            //     Center cx = (N+1)/2, cy = (N+1)/2.
            //     dx = abs(xs - cx), dy = abs(ys - cy).
            //
            //     If dx == dy:
            //         cost = 0
            //     Else if (xs % 2 == ys % 2): // same parity
            //         cost = 0
            //     Else: // dx != dy AND different parity
            //         cost = 1
            //
            //     This is equivalent to:
            //     If (abs(xs - center) == abs(ys - center)) OR (xs % 2 == ys % 2):
            //         cost = 0
            //     Else:
            //         cost = 1
            //
            //     This seems correct and covers all cases.
            //     The constraints are N up to 2e4, T up to 1e4.
            //     Calculations are O(1) per test case. Total time complexity O(T).
            //     Space complexity O(1).
            
            long long center_coord = (n + 1) / 2;
            long long dist_x_abs = std::abs(xs - center_coord);
            long long dist_y_abs = std::abs(ys - center_coord);
            
            if (dist_x_abs == dist_y_abs) {
                std::cout << 0 << "\n";
            } else {
                // Check parity of starting cell coordinates
                // Center cell (cx, cy) has cx = cy = (N+1)/2.
                // cx + cy = N+1. Since N is odd, N+1 is even.
                // The center cell has an even sum of coordinates.
                // A cell (r, c) has the same color as the center if r+c is even.
                // This means r and c have the same parity.
                // If xs and ys have the same parity, then xs+ys is even.
                // This means (xs, ys) is on the same color square as the center.
                // If they have different parity, then xs+ys is odd.
                // This means (xs, ys) is on a different color square than the center.
                
                if ((xs % 2) == (ys % 2)) { // Same parity, same color as center
                    // If not on a direct diagonal, we need to reach a cell from which center is reachable diagonally.
                    // The condition for 0 cost is:
                    // (|xs - cx| == |ys - cy|) OR (xs and ys have the same parity)
                    // We are in the case |xs - cx| != |ys - cy|.
                    // So if xs and ys have the same parity, cost is 0.
                    std::cout << 0 << "\n";
                } else { // Different parity, different color from center
                    // We need at least one horizontal/vertical move to change color.
                    // It turns out 1 move is always sufficient.
                    std::cout << 1 << "\n";
                }
            }
        }
    }
    return 0;
}