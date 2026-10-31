# [Maximum Capacity (MAXCAP)](https://www.codechef.com/problems/MAXCAP)
- **Difficulty Rating**: -1
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to determine if a group of $x$ friends, each weighing $y$ kilograms, can fit into a lift. The lift has two constraints: a maximum weight capacity of 500 kilograms and a maximum people capacity of 8 people. We need to output "YES" if they can fit, and "NO" otherwise.

## Intuition & Mathematical Observation
The core of the problem lies in checking two independent conditions that must both be satisfied for the friends to fit into the lift:

1.  **People Capacity:** The number of friends ($x$) must not exceed the maximum number of people the lift can hold. The problem states this limit is 8.
2.  **Weight Capacity:** The total weight of all friends must not exceed the maximum weight the lift can carry. The problem states this limit is 500 kilograms.

Let $x$ be the number of friends and $y$ be the weight of each friend in kilograms.

The conditions can be translated into mathematical inequalities:

1.  $x \le 8$
2.  $x \times y \le 500$

If both of these inequalities hold true, then the friends can use the lift, and we should output "YES". If either of these inequalities is false, then they cannot use the lift, and we should output "NO".

The solution code directly implements these checks. It first checks if $x > 8$. If it is, it immediately prints "NO". Otherwise, it proceeds to calculate the `total_weight` as $x \times y$. It's important to use `long long` for `total_weight` to prevent potential integer overflow if $x$ and $y$ are large, although in this specific problem with $x \le 8$ and $y$ likely within reasonable bounds, `int` might suffice for the product. However, using `long long` is a good practice for weight calculations. Finally, it checks if `total_weight > 500`. If it is, it prints "NO"; otherwise, it prints "YES".

## Complexity Analysis
- **Time Complexity**: $O(1)$
    The solution involves a fixed number of arithmetic operations and comparisons for each test case. The number of operations does not depend on the input values $x$ and $y$ (beyond their magnitude, which is handled by standard integer types). Therefore, the time complexity per test case is constant. Since there are $t$ test cases, the total time complexity is $O(t)$. However, if we consider the complexity per test case, it's $O(1)$.

- **Space Complexity**: $O(1)$
    The solution uses a fixed amount of memory to store variables like `t`, `x`, `y`, and `total_weight`. This memory usage does not grow with the input size. Thus, the space complexity is constant.