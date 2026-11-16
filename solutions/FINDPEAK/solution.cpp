#include <vector>   // Required for std::vector

// The problem statement implies that the function findPeakElement should be provided.
// CodeChef often wraps such functions in a class named 'Solution'.
// The compilation errors indicate this is the expected structure.
class Solution {
public:
    // Function to find the index of a peak element
    int findPeakElement(const std::vector<int>& nums) {
        int N = nums.size();
        
        // Edge case: If there's only one element, it's always a peak.
        // Based on problem constraints (N >= 1), this is a valid scenario.
        if (N == 1) {
            return 0;
        }

        int low = 0;
        int high = N - 1;

        // Binary search for a peak element.
        // The loop condition low <= high ensures that the search space is valid
        // and covers all possible indices.
        while (low <= high) {
            // Calculate mid to prevent potential integer overflow for large low/high values.
            int mid = low + (high - low) / 2;

            // Determine if nums[mid] is strictly greater than its left neighbor.
            // If mid is 0, its left neighbor is considered -infinity, so nums[0] is always greater.
            bool is_greater_than_left;
            if (mid == 0) {
                is_greater_than_left = true;
            } else {
                is_greater_than_left = (nums[mid] > nums[mid - 1]);
            }

            // Determine if nums[mid] is strictly greater than its right neighbor.
            // If mid is N-1, its right neighbor is considered -infinity, so nums[N-1] is always greater.
            bool is_greater_than_right;
            if (mid == N - 1) {
                is_greater_than_right = true;
            } else {
                is_greater_than_right = (nums[mid] > nums[mid + 1]);
            }

            // If both conditions are true, nums[mid] is a peak element.
            if (is_greater_than_left && is_greater_than_right) {
                return mid;
            } 
            // If nums[mid] is not greater than its left neighbor, it means nums[mid] < nums[mid-1]
            // (since mid=0 case makes is_greater_than_left true).
            // This implies we are on a decreasing slope. A peak must exist to the left of mid
            // (including mid-1, which is now the largest element in the left segment).
            // So, we discard mid and search in the left half.
            else if (!is_greater_than_left) {
                high = mid - 1;
            } 
            // If nums[mid] is greater than its left neighbor but not its right neighbor,
            // it means nums[mid] > nums[mid-1] AND nums[mid] < nums[mid+1]
            // (since mid=N-1 case makes is_greater_than_right true).
            // This implies we are on an increasing slope. A peak must exist to the right of mid
            // (including mid+1, which is now the largest element in the right segment).
            // So, we discard mid and search in the right half.
            else { // !is_greater_than_right
                low = mid + 1;
            }
        }
        
        // A peak element is guaranteed to exist based on the problem constraints and boundary conditions.
        // Therefore, this line should theoretically never be reached.
        // It's good practice to have a return statement for all paths, even if unreachable.
        return -1; 
    }
};

// The main function and fast I/O setup are typically provided by the CodeChef platform
// when submitting a class-based solution. Therefore, it should not be included in your submission.