#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int a, b;
    std::cin >> a >> b;
    
    // The first layer can be any color from 1 to A. There are A choices.
    // The second layer can be any color from 1 to B. There are B choices.
    // If there were no extra constraint, the total number of cakes would be A * B.
    
    // The extra constraint is that the first and second layer should not have the same color.
    // We need to subtract the cases where the colors are the same.
    
    // Case 1: Color of layer 1 is c, and color of layer 2 is also c.
    // This is only possible if c is a valid color for both layers.
    // So, c must be in the range [1, A] AND in the range [1, B].
    // This means c must be in the range [1, min(A, B)].
    // The number of such common colors is min(A, B).
    // For each such common color c, the cake (c, c) is disallowed.
    
    // Total possible cakes = (Total combinations without constraint) - (Combinations where colors are the same)
    // Total possible cakes = (A * B) - min(A, B)
    
    int common_colors = std::min(a, b);
    long long total_cakes = (long long)a * b - common_colors;
    
    std::cout << total_cakes << "\n";
    
    return 0;
}