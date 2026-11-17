# [Similar Dishes (SIMDISH)](https://www.codechef.com/problems/SIMDISH)
- **Difficulty Rating**: 1142
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine if two dishes are "similar". Each dish consists of exactly four ingredients, given as strings. Two dishes are considered similar if at least two of their ingredients are common. We need to process multiple test cases.

## Intuition & Mathematical Observation

The core of the problem is to count the number of common ingredients between two lists of four ingredients.

1.  **Storing Ingredients**: To efficiently check for common ingredients, we need a way to quickly look up if an ingredient from the second dish exists in the first dish.
2.  **Efficient Lookup**: A `std::set` in C++ is an excellent data structure for this purpose. When we insert ingredients into a `std::set`, it automatically handles uniqueness (though not strictly required here as we just need presence) and provides very fast average-case lookup times (logarithmic with respect to the number of elements).
3.  **Counting Common Ingredients**:
    *   We can store all four ingredients of the first dish into a `std::set<std::string>`.
    *   Then, for each of the four ingredients of the second dish, we check if it exists in the set created from the first dish.
    *   We maintain a counter for common ingredients.
    *   If the counter reaches 2 or more, the dishes are similar. Otherwise, they are dissimilar.

Since the number of ingredients (4) is very small, the logarithmic factor in set operations becomes a tiny constant, making the overall approach very fast.

## Complexity Analysis

Let $T$ be the number of test cases and $L$ be the maximum length of an ingredient string.

-   **Time Complexity**: $O(T \cdot L)$
    *   For each test case:
        *   Reading 4 ingredient strings for the first dish: $4 \times O(L)$ operations.
        *   Inserting 4 strings into `std::set<std::string>`: Each insertion involves string comparison/hashing (cost $O(L)$) and tree operations (cost $O(\log k)$ where $k$ is the current size of the set). Since $k \le 4$, $\log k$ is a very small constant. So, $4 \times O(L \log 4) \approx O(L)$.
        *   Reading 4 ingredient strings for the second dish: $4 \times O(L)$ operations.
        *   Iterating through the 4 ingredients of the second dish: For each ingredient, checking its presence in the `std::set` using `count()` takes $O(L \log 4)$ time. So, $4 \times O(L \log 4) \approx O(L)$.
    *   Combining these, the total time complexity per test case is $O(L)$.
    *   Since there are $T$ test cases, the overall time complexity is $O(T \cdot L)$.

-   **Space Complexity**: $O(L)$
    *   For each test case:
        *   `dish1_ingredients` (a `std::set<std::string>`) stores 4 strings. The total space required is proportional to the sum of lengths of these strings. If the maximum string length is $L$, this is $O(4 \cdot L) = O(L)$.
        *   `dish2_ingredients` (a `std::vector<std::string>`) stores 4 strings. Similarly, this requires $O(4 \cdot L) = O(L)$ space.
    *   Thus, the total space complexity per test case is $O(L)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries like iostream, string, vector, set

// Using namespace std; as requested by the problem statement.
using namespace std;

// Function to solve a single test case
void solve() {
    // Create a set to store ingredients of the first dish.
    // A set provides efficient O(log N) average time complexity for insertion and lookup,
    // where N is the number of elements. For N=4, this is very fast.
    set<string> dish1_ingredients;
    for (int i = 0; i < 4; ++i) {
        string s;
        cin >> s; // Read each ingredient string
        dish1_ingredients.insert(s); // Add it to the set
    }

    // Create a vector to store ingredients of the second dish.
    // We will iterate through this vector to check for common ingredients.
    vector<string> dish2_ingredients(4);
    for (int i = 0; i < 4; ++i) {
        cin >> dish2_ingredients[i]; // Read each ingredient string
    }

    int common_count = 0; // Counter for common ingredients

    // Iterate through each ingredient of the second dish
    for (const string& ing : dish2_ingredients) {
        // Check if the current ingredient from dish2 is present in dish1_ingredients set.
        // set::count(element) returns 1 if the element is found, 0 otherwise.
        if (dish1_ingredients.count(ing)) {
            common_count++; // Increment count if ingredient is common
        }
    }

    // Determine if the dishes are similar based on the common_count.
    // "Similar" means at least half (2 out of 4) ingredients are the same.
    if (common_count >= 2) {
        cout << "similar\n";
    } else {
        cout << "dissimilar\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t; // Read the number of test cases

    // Loop through each test case
    while (t--) {
        solve(); // Call the solve function for the current test case
    }

    return 0; // Indicate successful execution
}
```