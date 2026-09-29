#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<std::vector<int>> triangle(n);
        for (int i = 0; i < n; ++i) {
            triangle[i].resize(i + 1);
            for (int j = 0; j <= i; ++j) {
                std::cin >> triangle[i][j];
            }
        }

        // Dynamic programming approach
        // We can compute the maximum path sum ending at each element
        // by working from the bottom up.
        // For an element at row i, column j (0-indexed),
        // the maximum path sum ending at this element is its value
        // plus the maximum of the path sums ending at the elements
        // directly below it (i+1, j) and below-right (i+1, j+1).
        // However, it's more efficient to modify the triangle in place
        // from bottom-up.
        // For an element at row i, column j, the maximum path sum
        // starting from this element to the base is its value plus
        // the maximum of the maximum path sums starting from the
        // elements directly below it (i+1, j) and below-right (i+1, j+1).

        for (int i = n - 2; i >= 0; --i) {
            for (int j = 0; j <= i; ++j) {
                triangle[i][j] += std::max(triangle[i + 1][j], triangle[i + 1][j + 1]);
            }
        }

        // The maximum path sum from the top will be at the root (triangle[0][0])
        std::cout << triangle[0][0] << "\n";
    }
    return 0;
}