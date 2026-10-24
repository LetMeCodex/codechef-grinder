#include <iostream>
#include <vector>
#include <algorithm>

bool is_pseudo_sorted(const std::vector<int>& a) {
    int n = a.size();
    int inversion_index = -1;
    int inversion_count = 0;

    for (int i = 0; i < n - 1; ++i) {
        if (a[i] > a[i+1]) {
            inversion_count++;
            if (inversion_count > 1) {
                return false; // More than one adjacent inversion, cannot be sorted with one swap
            }
            inversion_index = i;
        }
    }

    if (inversion_count == 0) {
        return true; // Already sorted
    }

    // Exactly one inversion found at inversion_index
    // Check if swapping a[inversion_index] and a[inversion_index+1] sorts the array

    // Condition 1: Check element before the swapped pair (if it exists)
    // The element at inversion_index-1 should be <= the new element at inversion_index (which was a[inversion_index+1])
    if (inversion_index > 0) {
        if (a[inversion_index - 1] > a[inversion_index + 1]) {
            return false;
        }
    }

    // Condition 2: Check element after the swapped pair (if it exists)
    // The new element at inversion_index+1 (which was a[inversion_index]) should be <= the element at inversion_index+2
    if (inversion_index + 1 < n - 1) {
        if (a[inversion_index] > a[inversion_index + 2]) {
            return false;
        }
    }

    // If we passed the checks, it means swapping the single inversion pair sorts the array
    return true;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
        }
        
        if (is_pseudo_sorted(a)) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
    
    return 0;
}