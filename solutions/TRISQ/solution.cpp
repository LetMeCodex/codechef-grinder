#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int b;
        cin >> b;

        // The problem asks for the maximum number of 2x2 squares that can fit
        // in a right-angled isosceles triangle with base B.
        // The base is the shortest side.
        // Let the two equal sides of the isosceles triangle be of length L.
        // Since it's a right-angled isosceles triangle, the base B is the hypotenuse.
        // The two equal sides are perpendicular to each other.
        // The problem statement says "Base is the shortest side of the triangle".
        // This implies the triangle is oriented such that the right angle is at the top,
        // and the base B is the horizontal side.
        // The two equal sides are of length B.
        // The vertices are (0,0), (B,0), (0,B).
        // The hypotenuse is the line segment connecting (B,0) and (0,B), which has length sqrt(B^2 + B^2) = B*sqrt(2).
        // This contradicts "Base is the shortest side".

        // Let's re-interpret based on typical geometry problems and the sample cases.
        // A right-angled isosceles triangle has angles 45-45-90.
        // If the base is B, and it's the shortest side, then the two equal sides must be longer.
        // This means the right angle is NOT between the two equal sides.
        // The right angle must be opposite the base.
        // So, the two equal sides are the legs, and the base is the hypotenuse.
        // Let the equal sides be of length S. Then the hypotenuse B = S * sqrt(2).
        // This means S = B / sqrt(2).
        // This also contradicts "Base is the shortest side".

        // The most common interpretation for "right-angled isosceles triangle of base B"
        // where B is the shortest side is that the two equal sides are of length B,
        // and the right angle is between them. The hypotenuse is B*sqrt(2).
        // However, the problem states "Base is the shortest side".
        // This implies the triangle is oriented with the right angle at the top,
        // and the base B is the horizontal side. The two equal sides are of length B.
        // The vertices are (0,0), (B,0), and (B/2, B/2). This is not a right-angled triangle.

        // Let's consider the orientation where the two equal sides are along the axes.
        // Vertices: (0,0), (B,0), (0,B). This is a right-angled isosceles triangle.
        // The hypotenuse is the line y = -x + B.
        // The base is usually considered the side on which the triangle "rests".
        // If the base is B, and it's the shortest side, then the two equal sides must be longer.
        // This means the right angle is opposite the base.
        // So, the two equal sides are the legs, and the base is the hypotenuse.
        // Let the equal sides be of length S. Then the hypotenuse B = S * sqrt(2).
        // This means S = B / sqrt(2).
        // This interpretation also seems problematic with "Base is the shortest side".

        // The most consistent interpretation with the sample cases and the phrase
        // "One side of the square must be parallel to the base of the isosceles triangle"
        // is that the triangle has vertices at (0,0), (B,0), and (0,B).
        // The hypotenuse is the line segment from (B,0) to (0,B).
        // The "base" here refers to the side of length B along the x-axis (or y-axis).
        // The problem statement "Base is the shortest side of the triangle" is confusing.
        // In a right-angled isosceles triangle with legs of length L, the hypotenuse is L*sqrt(2).
        // If B is the base and shortest side, it must be L. So L=B.
        // The triangle has legs of length B. Vertices (0,0), (B,0), (0,B). Hypotenuse length B*sqrt(2).
        // The squares are 2x2.
        // We are fitting squares with one side parallel to the base.
        // Let's assume the base is the side along the x-axis.
        // The triangle is defined by x >= 0, y >= 0, x + y <= B.
        // We need to fit 2x2 squares.
        // A 2x2 square has its bottom-left corner at (x,y).
        // Its top-right corner is at (x+2, y+2).
        // For the square to be inside the triangle:
        // 1. x >= 0
        // 2. y >= 0
        // 3. (x+2) + (y+2) <= B  => x + y <= B - 4

        // Consider the largest possible square that can fit.
        // If we place a square with its bottom-left corner at (0,0), its top-right is (2,2).
        // This requires 2+2 <= B, so B >= 4.
        // If B=4, we can fit one 2x2 square.
        // The sample output for B=4 is 1. This matches.
        // If B=3, we cannot fit any 2x2 square. Sample output is 0. Matches.
        // If B=5, we can fit one 2x2 square. Sample output is 1. Matches.
        // If B=6, we can fit one 2x2 square. Sample output is 3. This is where it gets tricky.

        // Let's re-evaluate the triangle shape and orientation.
        // "Right angled isosceles triangle of base B".
        // If B is the base, and it's the shortest side, then the two equal sides are longer.
        // This means the right angle is opposite the base.
        // Let the equal sides be of length L. The base B is the hypotenuse.
        // B = L * sqrt(2). So L = B / sqrt(2).
        // This triangle has vertices at (0,0), (L,0), (0,L).
        // The hypotenuse is the line segment from (L,0) to (0,L).
        // The equation of the hypotenuse is x + y = L.
        // Substituting L = B / sqrt(2), we get x + y = B / sqrt(2).
        // This triangle is defined by x >= 0, y >= 0, x + y <= B / sqrt(2).
        // We are fitting 2x2 squares.
        // A 2x2 square with bottom-left at (x,y) requires (x+2) + (y+2) <= B / sqrt(2).
        // x + y <= B / sqrt(2) - 4.

        // This interpretation doesn't seem to lead to the sample outputs easily.

        // Let's go back to the interpretation that the triangle has legs of length B.
        // Vertices (0,0), (B,0), (0,B).
        // The hypotenuse is x + y = B.
        // We are fitting 2x2 squares.
        // The constraint is that one side of the square must be parallel to the base.
        // Let's assume the base is the side along the x-axis.
        // So, the squares are axis-aligned.
        // A 2x2 square with bottom-left corner at (x,y) is inside if:
        // x >= 0, y >= 0, x+2 <= B, y+2 <= B, and (x+2) + (y+2) <= B.
        // The last condition is the most restrictive: x + y <= B - 4.

        // Consider the sample case B=6. Output is 3.
        // Triangle: x>=0, y>=0, x+y <= 6.
        // Squares are 2x2.
        // If we place a square at (0,0), it occupies [0,2]x[0,2]. Requires 2+2 <= 6. Yes.
        // If we place a square at (2,0), it occupies [2,4]x[0,2]. Requires 4+2 <= 6. Yes.
        // If we place a square at (0,2), it occupies [0,2]x[2,4]. Requires 2+4 <= 6. Yes.
        // If we place a square at (4,0), it occupies [4,6]x[0,2]. Requires 6+2 <= 6. No.
        // If we place a square at (0,4), it occupies [0,2]x[4,6]. Requires 2+6 <= 6. No.
        // If we place a square at (2,2), it occupies [2,4]x[2,4]. Requires 4+4 <= 6. No.

        // This suggests the triangle is oriented differently.
        // What if the triangle is oriented with the right angle at the top?
        // Vertices: (0, H), (-B/2, 0), (B/2, 0). This is isosceles.
        // For it to be right-angled, the angle at (0,H) must be 90 degrees.
        // This means the slopes of the sides from (0,H) to (-B/2, 0) and (0,H) to (B/2, 0) must be negative reciprocals.
        // Slope 1: (0-H) / (-B/2 - 0) = -H / (-B/2) = 2H/B
        // Slope 2: (0-H) / (B/2 - 0) = -H / (B/2) = -2H/B
        // Product of slopes: (2H/B) * (-2H/B) = -4H^2 / B^2.
        // For right angle, this product must be -1.
        // -4H^2 / B^2 = -1 => 4H^2 = B^2 => H = B/2.
        // So vertices are (0, B/2), (-B/2, 0), (B/2, 0).
        // The base is the segment from (-B/2, 0) to (B/2, 0), length B.
        // The two equal sides have length sqrt((B/2)^2 + (B/2)^2) = sqrt(B^2/4 + B^2/4) = sqrt(B^2/2) = B/sqrt(2).
        // This triangle has legs shorter than the base. This contradicts "Base is the shortest side".

        // The only interpretation that makes sense with "Base is the shortest side"
        // and the sample outputs is that the triangle has legs of length B,
        // and the right angle is at the vertex where these legs meet.
        // The hypotenuse is B*sqrt(2).
        // The problem statement "Base is the shortest side" is likely a red herring or poorly phrased.
        // Let's assume the triangle has legs of length B, and the right angle is at the origin (0,0).
        // Vertices: (0,0), (B,0), (0,B).
        // The hypotenuse is the line x + y = B.
        // We are fitting 2x2 squares.
        // "One side of the square must be parallel to the base of the isosceles triangle."
        // Let's assume the base is the side along the x-axis.
        // So squares are axis-aligned.
        // A 2x2 square with bottom-left corner (x,y) is inside if:
        // x >= 0, y >= 0, x+2 <= B, y+2 <= B, and (x+2) + (y+2) <= B.
        // The last condition is x + y <= B - 4.

        // Let's consider the available "space" for the bottom-left corner (x,y) of a 2x2 square.
        // The region is x >= 0, y >= 0, x + y <= B - 4.
        // This is a smaller triangle with vertices (0,0), (B-4,0), (0,B-4).
        // We are placing 2x2 squares.
        // If we place the bottom-left corner of a square at (x,y), the square occupies [x, x+2] x [y, y+2].
        // The constraint is that the top-right corner (x+2, y+2) must be within the triangle.
        // So, (x+2) + (y+2) <= B => x + y <= B - 4.

        // Consider the effective "width" available for placing squares.
        // If we have a triangle with legs of length B, the hypotenuse is x+y=B.
        // We are fitting 2x2 squares.
        // The squares are placed such that their bottom-left corner (x,y) satisfies x>=0, y>=0, and the square is within the triangle.
        // The top-right corner of the square is (x+2, y+2).
        // This point must be below or on the hypotenuse: (x+2) + (y+2) <= B => x + y <= B - 4.

        // Let's consider the number of squares we can place along one leg.
        // If we place squares along the x-axis, their bottom-left corners can be at (0,0), (2,0), (4,0), ...
        // The x-coordinate of the bottom-left corner can be 0, 2, 4, ..., 2k.
        // The square occupies [2k, 2k+2] x [0, 2].
        // For this square to be inside the triangle, the point (2k+2, 2) must be within the triangle.
        // (2k+2) + 2 <= B => 2k + 4 <= B => 2k <= B - 4 => k <= (B-4)/2.
        // The number of possible values for k (starting from 0) is floor((B-4)/2) + 1.
        // This is the number of squares we can place along the base, with their bottom edge on the x-axis.
        // This is floor((B-4)/2) + 1 if B >= 4, otherwise 0.
        // This is equivalent to floor((B-2)/2) if B >= 4.
        // For B=4: floor((4-2)/2) = floor(1) = 1.
        // For B=5: floor((5-2)/2) = floor(1.5) = 1.
        // For B=6: floor((6-2)/2) = floor(2) = 2.
        // This is not matching the sample output for B=6 (which is 3).

        // The problem is about packing squares.
        // Consider the available "height" for squares at a given x-coordinate.
        // For a triangle with vertices (0,0), (B,0), (0,B), the hypotenuse is y = B - x.
        // A 2x2 square with bottom-left corner (x,y) must satisfy:
        // x >= 0, y >= 0
        // x+2 <= B (square doesn't go beyond the right leg)
        // y+2 <= B (square doesn't go beyond the top leg)
        // (x+2) + (y+2) <= B (square doesn't go beyond the hypotenuse) => x + y <= B - 4.

        // Let's consider the number of squares that can fit along the "width" of the triangle.
        // The triangle has a "width" of B along the x-axis and B along the y-axis.
        // We are fitting 2x2 squares.
        // The number of 2-unit segments that can fit along a length B is floor(B/2).
        // If we consider the triangle as a grid, how many 2x2 cells can we fit?

        // Let's look at the sample cases and try to find a pattern.
        // B | Output
        // --|-------
        // 1 | 0
        // 2 | 0
        // 3 | 0
        // 4 | 1   (floor(4/2) - 1 = 2 - 1 = 1)
        // 5 | 1   (floor(5/2) - 1 = 2 - 1 = 1)
        // 6 | 3   (floor(6/2) - 1 = 3 - 1 = 2. Incorrect)
        // 7 | 3   (floor(7/2) - 1 = 3 - 1 = 2. Incorrect)
        // 8 | 6   (floor(8/2) - 1 = 4 - 1 = 3. Incorrect)
        // 9 | 6   (floor(9/2) - 1 = 4 - 1 = 3. Incorrect)
        // 10| 10  (floor(10/2) - 1 = 5 - 1 = 4. Incorrect)
        // 11| 10  (floor(11/2) - 1 = 5 - 1 = 4. Incorrect)

        // The pattern seems to be related to squares of integers.
        // 0, 0, 0, 1, 1, 3, 3, 6, 6, 10, 10
        // Differences: 0, 0, 1, 0, 2, 0, 3, 0, 4, 0
        // This looks like triangular numbers, but shifted or scaled.
        // Triangular numbers: 0, 1, 3, 6, 10, 15, 21, ...
        // T(n) = n*(n+1)/2
        // T(0)=0, T(1)=1, T(2)=3, T(3)=6, T(4)=10.

        // Let's try to relate B to the index 'n' of the triangular number.
        // B=1, 2, 3 -> 0 (T(0))
        // B=4, 5   -> 1 (T(1))
        // B=6, 7   -> 3 (T(2))
        // B=8, 9   -> 6 (T(3))
        // B=10, 11 -> 10 (T(4))

        // It seems that for B = 2k or B = 2k+1, the answer is T(k-1) for k>=2.
        // For B=4, k=2. T(2-1) = T(1) = 1. Correct.
        // For B=5, k=2. T(2-1) = T(1) = 1. Correct.
        // For B=6, k=3. T(3-1) = T(2) = 3. Correct.
        // For B=7, k=3. T(3-1) = T(2) = 3. Correct.
        // For B=8, k=4. T(4-1) = T(3) = 6. Correct.
        // For B=9, k=4. T(4-1) = T(3) = 6. Correct.
        // For B=10, k=5. T(5-1) = T(4) = 10. Correct.
        // For B=11, k=5. T(5-1) = T(4) = 10. Correct.

        // What about B=1, 2, 3?
        // If B=1, k=0 or k=1. T(0-1) is not defined.
        // If B=2, k=1. T(1-1) = T(0) = 0. Correct.
        // If B=3, k=1. T(1-1) = T(0) = 0. Correct.

        // So, the formula seems to be:
        // If B < 4, answer is 0.
        // If B >= 4, let k = floor(B/2). The answer is T(k-1).
        // T(n) = n*(n+1)/2.
        // So, T(k-1) = (k-1) * ((k-1)+1) / 2 = (k-1) * k / 2.

        // Let's check this formula:
        // B=1: B < 4, ans = 0. Correct.
        // B=2: B < 4, ans = 0. Correct.
        // B=3: B < 4, ans = 0. Correct.
        // B=4: k = floor(4/2) = 2. Ans = T(2-1) = T(1) = 1*(1+1)/2 = 1. Correct.
        // B=5: k = floor(5/2) = 2. Ans = T(2-1) = T(1) = 1*(1+1)/2 = 1. Correct.
        // B=6: k = floor(6/2) = 3. Ans = T(3-1) = T(2) = 2*(2+1)/2 = 3. Correct.
        // B=7: k = floor(7/2) = 3. Ans = T(3-1) = T(2) = 2*(2+1)/2 = 3. Correct.
        // B=8: k = floor(8/2) = 4. Ans = T(4-1) = T(3) = 3*(3+1)/2 = 6. Correct.
        // B=9: k = floor(9/2) = 4. Ans = T(4-1) = T(3) = 3*(3+1)/2 = 6. Correct.
        // B=10: k = floor(10/2) = 5. Ans = T(5-1) = T(4) = 4*(4+1)/2 = 10. Correct.
        // B=11: k = floor(11/2) = 5. Ans = T(5-1) = T(4) = 4*(4+1)/2 = 10. Correct.

        // The formula seems to be:
        // If B < 4, answer is 0.
        // If B >= 4, let m = floor((B-2)/2). The answer is T(m) = m*(m+1)/2.
        // Let's re-check this new formulation.
        // B=1: B < 4, ans = 0.
        // B=2: B < 4, ans = 0.
        // B=3: B < 4, ans = 0.
        // B=4: m = floor((4-2)/2) = floor(1) = 1. Ans = T(1) = 1*(1+1)/2 = 1. Correct.
        // B=5: m = floor((5-2)/2) = floor(1.5) = 1. Ans = T(1) = 1*(1+1)/2 = 1. Correct.
        // B=6: m = floor((6-2)/2) = floor(2) = 2. Ans = T(2) = 2*(2+1)/2 = 3. Correct.
        // B=7: m = floor((7-2)/2) = floor(2.5) = 2. Ans = T(2) = 2*(2+1)/2 = 3. Correct.
        // B=8: m = floor((8-2)/2) = floor(3) = 3. Ans = T(3) = 3*(3+1)/2 = 6. Correct.
        // B=9: m = floor((9-2)/2) = floor(3.5) = 3. Ans = T(3) = 3*(3+1)/2 = 6. Correct.
        // B=10: m = floor((10-2)/2) = floor(4) = 4. Ans = T(4) = 4*(4+1)/2 = 10. Correct.
        // B=11: m = floor((11-2)/2) = floor(4.5) = 4. Ans = T(4) = 4*(4+1)/2 = 10. Correct.

        // This formula works for all sample cases.
        // The logic behind this formula is likely related to how many layers of squares can be packed.
        // Consider a triangle with legs of length B.
        // The number of 2x2 squares that can fit along one leg is floor(B/2).
        // Let's say we can fit `N = floor(B/2)` squares along the base.
        // If B=6, N = floor(6/2) = 3.
        // We can place squares with bottom-left corners at (0,0), (2,0), (4,0).
        // Square 1: [0,2]x[0,2]. Top-right (2,2). 2+2 <= 6. OK.
        // Square 2: [2,4]x[0,2]. Top-right (4,2). 4+2 <= 6. OK.
        // Square 3: [4,6]x[0,2]. Top-right (6,2). 6+2 <= 6. NOT OK.
        // This simple linear packing doesn't work.

        // The problem is equivalent to finding the number of 2x2 squares that can be placed
        // such that their bottom-left corner (x,y) satisfies x >= 0, y >= 0, and x+y <= B-4.
        // This is a region of a triangle with vertices (0,0), (B-4,0), (0,B-4).
        // We are placing 2x2 squares.
        // The number of squares that can fit in a triangle of base `b_eff` and height `h_eff`
        // where `b_eff = h_eff = B-4` is not straightforward.

        // Let's consider the number of squares that can fit in a right triangle with legs of length L.
        // The number of 1x1 squares is L*(L+1)/2.
        // We are fitting 2x2 squares.
        // If we have a triangle with legs of length B, the hypotenuse is x+y=B.
        // The number of 2x2 squares that can fit is related to the number of 1x1 squares that can fit in a smaller triangle.
        // Consider a triangle with legs of length B.
        // The number of 2x2 squares that can fit is the number of 1x1 squares that can fit in a triangle with legs of length floor((B-2)/2).
        // Let L_eff = floor((B-2)/2).
        // The number of 1x1 squares in a triangle with legs L_eff is L_eff * (L_eff + 1) / 2.
        // This matches the formula derived from sample cases.

        // Let's verify the logic for L_eff = floor((B-2)/2).
        // If B=4, L_eff = floor((4-2)/2) = 1. Number of squares = 1*(1+1)/2 = 1.
        // This means we can fit one 2x2 square.
        // The triangle has legs of length 4. Vertices (0,0), (4,0), (0,4). Hypotenuse x+y=4.
        // A 2x2 square at (0,0) has top-right at (2,2). 2+2=4 <= 4. Fits.
        // If we try to place another square, e.g., at (2,0), top-right is (4,2). 4+2=6 > 4. Doesn't fit.
        // If we try to place at (0,2), top-right is (2,4). 2+4=6 > 4. Doesn't fit.

        // If B=6, L_eff = floor((6-2)/2) = 2. Number of squares = 2*(2+1)/2 = 3.
        // Triangle legs length 6. Vertices (0,0), (6,0), (0,6). Hypotenuse x+y=6.
        // We need to fit 2x2 squares.
        // The effective triangle for placing the bottom-left corner (x,y) is x+y <= B-4.
        // For B=6, x+y <= 6-4 = 2.
        // This is a triangle with vertices (0,0), (2,0), (0,2).
        // We are placing 2x2 squares.
        // The number of 2x2 squares that can fit inside a triangle with legs of length L is the same as the number of 1x1 squares that can fit inside a triangle with legs of length floor((L-2)/2).
        // This is because each 2x2 square can be thought of as a "unit" of size 2.
        // If we scale down the triangle by a factor of 2, we are essentially asking how many 1x1 squares fit.
        // The constraint for a 2x2 square with bottom-left (x,y) is x+y <= B-4.
        // Let X = x/2, Y = y/2. Then (2X) + (2Y) <= B-4 => X + Y <= (B-4)/2.
        // This is a triangle with legs of length (B-4)/2.
        // The number of 1x1 squares in a triangle with legs L is L*(L+1)/2.
        // So, we need to fit 1x1 squares in a triangle with legs of length (B-4)/2.
        // The number of 1x1 squares is floor((B-4)/2) * (floor((B-4)/2) + 1) / 2.
        // This is not matching the formula.

        // Let's consider the number of squares that can be placed along the hypotenuse.
        // The hypotenuse has length B*sqrt(2).
        // A 2x2 square has diagonal sqrt(2^2 + 2^2) = sqrt(8) = 2*sqrt(2).
        // This is not directly helpful.

        // The formula derived from sample cases is:
        // Let m = floor((B-2)/2).
        // Answer = m * (m+1) / 2.
        // This is the m-th triangular number.

        // Let's consider the number of squares that can be placed in layers.
        // The first layer of squares can be placed along the base.
        // If B=6, we can place squares with bottom-left at (0,0), (2,0).
        // Square 1: [0,2]x[0,2]. Top-right (2,2). 2+2 <= 6. OK.
        // Square 2: [2,4]x[0,2]. Top-right (4,2). 4+2 <= 6. OK.
        // Square 3: [4,6]x[0,2]. Top-right (6,2). 6+2 > 6. Not OK.
        // So, we can fit 2 squares in the first row along the base.

        // Now consider the next row of squares.
        // Their bottom-left corners (x,y) must satisfy y >= 2.
        // And x+y <= B-4.
        // For B=6, x+y <= 2.
        // If y=2, then x <= 0. So only x=0 is possible.
        // Square at (0,2): [0,2]x[2,4]. Top-right (2,4). 2+4 <= 6. OK.
        // This gives 2 + 1 = 3 squares. This matches B=6.

        // Let's try B=8. Formula gives 6.
        // Triangle legs length 8. Hypotenuse x+y=8.
        // Constraint for bottom-left (x,y): x+y <= B-4 = 8-4 = 4.
        // Row 1 (y=0): x+0 <= 4 => x <= 4. Possible x: 0, 2. (Squares at (0,0), (2,0)). 2 squares.
        // Row 2 (y=2): x+2 <= 4 => x <= 2. Possible x: 0, 2. (Squares at (0,2), (2,2)). 2 squares.
        // Row 3 (y=4): x+4 <= 4 => x <= 0. Possible x: 0. (Square at (0,4)). 1 square.
        // Total squares = 2 + 2 + 1 = 5.
        // This is not 6.

        // The formula m = floor((B-2)/2) and T(m) is correct.
        // Let's re-examine the number of squares in layers.
        // For a triangle with legs of length B, the number of 2x2 squares is the sum of
        // floor((B - 2*i - 2)/2) for i from 0 up to some limit.
        // This is related to the number of squares that can fit in a triangle of decreasing size.

        // Consider the number of squares that can fit along the base.
        // The available length for the bottom edge of a 2x2 square is B.
        // The number of 2-unit segments that can fit is floor(B/2).
        // If we place squares along the base, their bottom-left corners are at (0,0), (2,0), (4,0), ...
        // The x-coordinate of the bottom-left corner can be 0, 2, ..., 2k.
        // The square occupies [2k, 2k+2] x [0, 2].
        // For this square to be inside the triangle, the point (2k+2, 2) must be within the triangle.
        // (2k+2) + 2 <= B => 2k + 4 <= B => 2k <= B - 4 => k <= (B-4)/2.
        // The number of possible values for k (starting from 0) is floor((B-4)/2) + 1.
        // This is the number of squares in the first row.
        // For B=6: floor((6-4)/2) + 1 = floor(1) + 1 = 1 + 1 = 2.
        // For B=8: floor((8-4)/2) + 1 = floor(2) + 1 = 2 + 1 = 3.

        // Now consider the second row of squares. Their bottom edge is at y=2.
        // The available length for the bottom edge of a 2x2 square at height y=2 is B - 2.
        // The number of 2-unit segments that can fit is floor((B-2)/2).
        // The x-coordinates of the bottom-left corners can be 0, 2, ..., 2k'.
        // The square occupies [2k', 2k'+2] x [2, 4].
        // For this square to be inside the triangle, the point (2k'+2, 4) must be within the triangle.
        // (2k'+2) + 4 <= B => 2k' + 6 <= B => 2k' <= B - 6 => k' <= (B-6)/2.
        // The number of possible values for k' (starting from 0) is floor((B-6)/2) + 1.
        // For B=6: floor((6-6)/2) + 1 = floor(0) + 1 = 0 + 1 = 1.
        // For B=8: floor((8-6)/2) + 1 = floor(1) + 1 = 1 + 1 = 2.

        // Third row (y=4):
        // Available length for bottom edge is B - 4.
        // Number of 2-unit segments is floor((B-4)/2).
        // x-coordinates: 0, 2, ..., 2k''.
        // Square occupies [2k'', 2k''+2] x [4, 6].
        // Point (2k''+2, 6) must be inside.
        // (2k''+2) + 6 <= B => 2k'' + 8 <= B => 2k'' <= B - 8 => k'' <= (B-8)/2.
        // Number of squares = floor((B-8)/2) + 1.
        // For B=6: floor((6-8)/2) + 1 = floor(-1) + 1 = -1 + 1 = 0. (Correct, no third row)
        // For B=8: floor((8-8)/2) + 1 = floor(0) + 1 = 0 + 1 = 1.

        // Total for B=6: 2 (row 1) + 1 (row 2) = 3. Correct.
        // Total for B=8: 3 (row 1) + 2 (row 2) + 1 (row 3) = 6. Correct.

        // The number of squares in row `i` (starting from i=0 for the bottom row) is:
        // `max(0, floor((B - 2*i - 2)/2) + 1)`
        // The height of row `i` is `2*i`. The square occupies `[2*i, 2*i+2]` in y-dimension.
        // The top edge is at `2*i + 2`.
        // The constraint for the top-right corner (x_tr, y_tr) is x_tr + y_tr <= B.
        // For a square in row `i`, its top-right corner is (x_bl + 2, 2*i + 2).
        // So, (x_bl + 2) + (2*i + 2) <= B => x_bl + 2*i + 4 <= B => x_bl <= B - 2*i - 4.
        // The possible values for x_bl are 0, 2, 4, ..., 2k.
        // 2k <= B - 2*i - 4 => k <= (B - 2*i - 4) / 2.
        // Number of squares in row `i` is floor((B - 2*i - 4) / 2) + 1.
        // This is valid as long as B - 2*i - 4 >= 0.
        // So, number of squares in row `i` is `max(0, floor((B - 2*i - 4) / 2) + 1)`.

        // Let's re-evaluate the number of squares in row `i` (0-indexed from bottom).
        // The bottom edge of squares in row `i` is at y = 2*i.
        // The top edge is at y = 2*i + 2.
        // The squares are of size 2x2.
        // The x-coordinates of the bottom-left corners can be 0, 2, 4, ..., 2k.
        // The square occupies [2k, 2k+2] x [2i, 2i+2].
        // The top-right corner is (2k+2, 2i+2).
        // This point must be inside the triangle x+y <= B.
        // So, (2k+2) + (2i+2) <= B
        // 2k + 2i + 4 <= B
        // 2k <= B - 2i - 4
        // k <= (B - 2i - 4) / 2
        // The number of possible values for k (starting from 0) is floor((B - 2i - 4) / 2) + 1.
        // This is valid only if B - 2i - 4 >= 0.
        // So, the number of squares in row `i` is `max(0, floor((B - 2*i - 4) / 2) + 1)`.

        // The maximum value of `i` is such that `2*i + 2 <= B`.
        // `2*i <= B - 2`
        // `i <= (B - 2) / 2`.
        // So `i` goes from 0 to `floor((B-2)/2)`.

        // Let's sum this up.
        // Total squares = sum_{i=0}^{floor((B-2)/2)} max(0, floor((B - 2*i - 4) / 2) + 1)

        // Let's test this sum for B=6.
        // floor((6-2)/2) = floor(2) = 2. So i goes from 0 to 2.
        // i=0: max(0, floor((6 - 0 - 4)/2) + 1) = max(0, floor(2/2) + 1) = max(0, 1 + 1) = 2.
        // i=1: max(0, floor((6 - 2 - 4)/2) + 1) = max(0, floor(0/2) + 1) = max(0, 0 + 1) = 1.
        // i=2: max(0, floor((6 - 4 - 4)/2) + 1) = max(0, floor(-2/2) + 1) = max(0, -1 + 1) = 0.
        // Total = 2 + 1 + 0 = 3. Correct.

        // Let's test for B=8.
        // floor((8-2)/2) = floor(3) = 3. So i goes from 0 to 3.
        // i=0: max(0, floor((8 - 0 - 4)/2) + 1) = max(0, floor(4/2) + 1) = max(0, 2 + 1) = 3.
        // i=1: max(0, floor((8 - 2 - 4)/2) + 1) = max(0, floor(2/2) + 1) = max(0, 1 + 1) = 2.
        // i=2: max(0, floor((8 - 4 - 4)/2) + 1) = max(0, floor(0/2) + 1) = max(0, 0 + 1) = 1.
        // i=3: max(0, floor((8 - 6 - 4)/2) + 1) = max(0, floor(-2/2) + 1) = max(0, -1 + 1) = 0.
        // Total = 3 + 2 + 1 + 0 = 6. Correct.

        // This summation formula seems correct.
        // Let's simplify it.
        // Let m = floor((B-2)/2).
        // The terms are:
        // i=0: floor((B-4)/2) + 1
        // i=1: floor((B-6)/2) + 1
        // i=2: floor((B-8)/2) + 1
        // ...
        // i=m: floor((B - 2*m - 4)/2) + 1

        // Let's consider the formula m = floor((B-2)/2) and T(m) = m*(m+1)/2.
        // This formula is equivalent to summing `m - i` for `i` from 0 to `m-1`.
        // Sum = (m) + (m-1) + ... + 1 = m*(m+1)/2.
        // This means the number of squares in row `i` is `m - i`.
        // Let's check if `floor((B - 2*i - 4) / 2) + 1` is equal to `m - i`.
        // `m = floor((B-2)/2)`.
        // If B is even, B=2k. m = floor((2k-2)/2) = k-1.
        // If B is odd, B=2k+1. m = floor((2k+1-2)/2) = floor((2k-1)/2) = k-1.
        // So, if B=2k, m=k-1. If B=2k+1, m=k-1.
        // This means `m = floor(B/2) - 1` for B >= 2.
        // For B=4, m=1. floor(4/2)-1 = 2-1=1.
        // For B=5, m=1. floor(5/2)-1 = 2-1=1.
        // For B=6, m=2. floor(6/2)-1 = 3-1=2.
        // For B=7, m=2. floor(7/2)-1 = 3-1=2.
        // This matches the `m` in the formula `T(m)`.

        // So, the number of squares in row `i` is `m - i`.
        // Let's check if `floor((B - 2*i - 4) / 2) + 1 == m - i`.
        // `m = floor((B-2)/2)`.
        // Let's use B=8. m=3.
        // i=0: floor((8-4)/2)+1 = 3. m-i = 3-0 = 3. Matches.
        // i=1: floor((8-6)/2)+1 = 2. m-i = 3-1 = 2. Matches.
        // i=2: floor((8-8)/2)+1 = 1. m-i = 3-2 = 1. Matches.
        // i=3: floor((8-10)/2)+1 = 0. m-i = 3-3 = 0. Matches.

        // The formula `m = floor((B-2)/2)` and `T(m) = m*(m+1)/2` is correct.
        // This formula works for B >= 2.
        // For B=1, m = floor((1-2)/2) = floor(-0.5) = -1. T(-1) is not standard.
        // The problem states B >= 1.
        // If B < 4, the answer is 0.
        // This covers B=1, 2, 3.
        // For B >= 4, we can use the formula.
        // Let's check B=4. m = floor((4-2)/2) = 1. T(1) = 1*(2)/2 = 1. Correct.
        // So the condition is B < 4, ans = 0.
        // Otherwise, calculate m = floor((B-2)/2) and ans = m*(m+1)/2.

        if (b < 4) {
            cout << 0 << "\n";
        } else {
            // Calculate m = floor((B-2)/2)
            // Integer division `(b - 2) / 2` in C++ for positive numbers is equivalent to floor.
            long long m = (b - 2) / 2;
            // Calculate the m-th triangular number: m * (m + 1) / 2
            long long ans = m * (m + 1) / 2;
            cout << ans << "\n";
        }
    }
    return 0;
}