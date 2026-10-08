# [Mileage matters (MILEAGE)](https://www.codechef.com/problems/MILEAGE)
- **Difficulty Rating**: 831
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine which type of car (petrol or diesel) is more cost-effective for Chef to travel a given distance `N`. We are provided with:
- `N`: The total distance Chef needs to travel.
- `X`: The cost of 1 liter of petrol.
- `Y`: The cost of 1 liter of diesel.
- `A`: The distance a petrol car can travel on 1 liter of petrol.
- `B`: The distance a diesel car can travel on 1 liter of diesel.

We need to output "PETROL" if the petrol car is cheaper, "DIESEL" if the diesel car is cheaper, and "ANY" if both cars cost the same for the journey.

## Intuition & Mathematical Observation

To decide which car is cheaper, Chef needs to compare the cost per kilometer for each car type. The total distance `N` is common for both cars, so it will simply scale the total cost but won't change which car is *relatively* cheaper. Thus, we only need to compare their respective costs per kilometer.

1.  **Cost per kilometer for a Petrol Car:**
    - A petrol car travels `A` kilometers using 1 liter of petrol.
    - 1 liter of petrol costs `X`.
    - Therefore, `A` kilometers cost `X`.
    - The cost per kilometer for a petrol car is `X / A`.

2.  **Cost per kilometer for a Diesel Car:**
    - A diesel car travels `B` kilometers using 1 liter of diesel.
    - 1 liter of diesel costs `Y`.
    - Therefore, `B` kilometers cost `Y`.
    - The cost per kilometer for a diesel car is `Y / B`.

3.  **Comparison:**
    We need to compare `X / A` with `Y / B`.
    To avoid potential floating-point precision issues that can arise from direct division, we can use cross-multiplication. Since `A` and `B` represent distances covered and are always positive, we can multiply both sides of the inequality by `A * B` without changing its direction:
    - Compare `X / A` vs `Y / B`
    - This is equivalent to comparing `(X / A) * (A * B)` vs `(Y / B) * (A * B)`
    - Which simplifies to comparing `X * B` vs `Y * A`.

    So, we calculate `petrol_cost_factor = X * B` and `diesel_cost_factor = Y * A`.
    - If `petrol_cost_factor < diesel_cost_factor`, the petrol car is cheaper.
    - If `diesel_cost_factor < petrol_cost_factor`, the diesel car is cheaper.
    - If `petrol_cost_factor == diesel_cost_factor`, both cars cost the same.

The total distance `N` is not needed for this comparison.

## Complexity Analysis

-   **Time Complexity**: $O(T)$
    For each test case, the solution performs a fixed number of arithmetic operations (two multiplications) and one comparison. These are constant time operations. If there are `T` test cases, the total time complexity will be `T * O(1)`, which simplifies to $O(T)$.

-   **Space Complexity**: $O(1)$
    The solution uses a constant amount of memory to store variables like `T`, `N`, `X`, `Y`, `A`, `B`, and the two cost factors. This memory usage does not depend on the input values (other than the number of test cases), making the space complexity constant.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries, as per problem instructions.
using namespace std; // Uses the standard namespace, as per problem instructions.

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming to avoid TLE (Time Limit Exceeded)
    // on problems with large inputs, as requested by the problem instructions.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases.

    // Loop through each test case.
    while (T--) {
        int N, X, Y, A, B;
        // Read the five space-separated integers for the current test case.
        // N: distance to travel
        // X: petrol cost per litre
        // Y: diesel cost per litre
        // A: distance per litre for petrol
        // B: distance per litre for diesel
        cin >> N >> X >> Y >> A >> B;

        // To minimize the total cost, Chef needs to choose the car with the lower cost per kilometer.
        // Cost per kilometer for petrol car = (Cost per litre of petrol) / (Distance per litre of petrol) = X / A
        // Cost per kilometer for diesel car = (Cost per litre of diesel) / (Distance per litre of diesel) = Y / B

        // We need to compare X/A and Y/B.
        // To avoid floating-point arithmetic and potential precision issues,
        // we can cross-multiply and compare the integer products:
        // X/A vs Y/B
        // This is equivalent to comparing X * B vs Y * A (since A and B are positive).
        // The total distance N is a common factor for both total costs (N * (X/A) vs N * (Y/B)),
        // so it cancels out in the comparison and does not affect the decision.

        // Calculate the "cost factor" for petrol and diesel.
        // These values represent the relative cost per kilometer.
        // Using long long for intermediate products, though int would suffice given constraints (100*100 = 10000).
        long long petrol_cost_factor = (long long)X * B;
        long long diesel_cost_factor = (long long)Y * A;

        // Compare the cost factors to determine which car is cheaper.
        if (petrol_cost_factor < diesel_cost_factor) {
            cout << "PETROL\n"; // Petrol car is cheaper.
        } else if (diesel_cost_factor < petrol_cost_factor) {
            cout << "DIESEL\n"; // Diesel car is cheaper.
        } else {
            cout << "ANY\n"; // Both cars have the same cost.
        }
    }

    return 0; // Indicate successful execution.
}
```