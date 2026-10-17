# [Travel Pass (TRAVELPS)](https://www.codechef.com/problems/TRAVELPS)
- **Difficulty Rating**: 1118
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to calculate the minimum time required to travel between cities. We are given the number of cities ($n$), the cost of traveling between two adjacent cities within the same district ($a$), and the cost of traveling between two adjacent cities in different districts ($b$). We are also given a string of '0's and '1's representing the path taken. A '0' signifies travel between two adjacent cities within the same district, and a '1' signifies travel between two adjacent cities in different districts.

## Intuition & Mathematical Observation
The problem statement directly provides the cost for each type of travel segment. We are given a sequence of travel segments represented by the string `s`. Each character in `s` corresponds to one unit of travel between two adjacent cities.

- If a character is '0', it means the travel is within the same district, and the cost for this segment is $a$.
- If a character is '1', it means the travel is between different districts, and the cost for this segment is $b$.

To find the total minimum time, we simply need to sum up the costs of all the travel segments. This can be achieved by iterating through the given string `s`. We can count the number of '0's and '1's. Let `inter_district_count` be the number of '0's and `inter_state_count` be the number of '1's.

The total time will then be:
`total_time = (inter_district_count * a) + (inter_state_count * b)`

This approach directly translates the problem's conditions into a calculation, making it straightforward. There are no complex optimizations or dynamic programming needed because the cost of each segment is fixed and independent of other segments.

## Complexity Analysis
- **Time Complexity**: $O(N)$
  The solution iterates through the input string `s` once to count the occurrences of '0' and '1'. The length of the string `s` is $N$. Therefore, the time complexity is directly proportional to the length of the string, which is $O(N)$.

- **Space Complexity**: $O(1)$
  The solution uses a few variables to store counts (`inter_district_count`, `inter_state_count`) and the input parameters ($n$, $a$, $b$). The space required for these variables is constant and does not depend on the input size $N$. The input string `s` itself takes $O(N)$ space, but this is considered input space and not auxiliary space used by the algorithm. If we consider the space for the input string, it would be $O(N)$. However, typically, space complexity refers to auxiliary space.

## Solution Code
```cpp
#include <iostream>
#include <string>
#include <vector>

int main() {
    // Optimize C++ standard streams for competitive programming
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; // Number of test cases
    std::cin >> t;
    while (t--) {
        int n; // Number of cities (not directly used in calculation, but part of input)
        int a; // Cost of travel within the same district
        int b; // Cost of travel between different districts
        std::cin >> n >> a >> b;
        std::string s; // String representing the path
        std::cin >> s;
        
        long long inter_district_count = 0; // Counter for '0's (travel within district)
        long long inter_state_count = 0;   // Counter for '1's (travel between districts)
        
        // Iterate through the path string to count '0's and '1's
        for (char c : s) {
            if (c == '0') {
                inter_district_count++;
            } else { // c == '1'
                inter_state_count++;
            }
        }
        
        // Calculate the total time based on the counts and costs
        long long total_time = (inter_district_count * a) + (inter_state_count * b);
        
        // Output the total time for the current test case
        std::cout << total_time << "\n";
    }
    return 0;
}
```