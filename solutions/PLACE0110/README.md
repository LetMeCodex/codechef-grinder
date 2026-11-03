# Placing 01 And 10 (PLACE0110)

- **Difficulty Rating**: 1114
- **Solved in**: 1 attempt(s)

## Problem Summary

We are given two integers, $X$ and $Y$. We need to construct a binary string by concatenating $X$ copies of the string "01" and $Y$ copies of the string "10". The goal is to arrange these $X+Y$ strings in a sequence such that the total number of adjacent character flips in the resulting concatenated string is minimized. We need to output this minimum number of flips.

A flip occurs when two adjacent characters in the binary string are different (e.g., '01' or '10').

## Intuition & Mathematical Observation

Let's analyze the contribution of each type of string ("01" and "10") to the total number of flips.

Each "01" string contributes exactly one flip internally (the transition from '0' to '1').
Each "10" string contributes exactly one flip internally (the transition from '1' to '0').

So, if we simply concatenate all $X$ "01" strings and all $Y$ "10" strings in any order, the total number of internal flips will always be $X + Y$. The problem then reduces to minimizing the number of flips that occur at the *junctions* between these concatenated strings.

Consider two strings being concatenated:
1.  **"01" + "01"**: The junction is '1' + '0'. This creates a flip ('10').
2.  **"01" + "10"**: The junction is '1' + '1'. This creates no flip ('11').
3.  **"10" + "01"**: The junction is '0' + '0'. This creates no flip ('00').
4.  **"10" + "10"**: The junction is '0' + '1'. This creates a flip ('01').

To minimize flips at junctions, we want to maximize the occurrences of "01" + "10" and "10" + "01" junctions, as these contribute zero flips. Conversely, we want to minimize "01" + "01" and "10" + "10" junctions, as these contribute one flip each.

Let's consider two cases:

**Case 1: $X = Y$**

If the number of "01" strings equals the number of "10" strings, we can perfectly alternate them. For example, if $X=Y=2$, we can arrange them as "01" + "10" + "01" + "10".
The junctions are:
- "01" + "10" (ends in '1', starts with '1' -> '11', 0 flips)
- "10" + "01" (ends in '0', starts with '0' -> '00', 0 flips)
- "01" + "10" (ends in '1', starts with '1' -> '11', 0 flips)

In this scenario, all $X+Y-1$ junctions are between different types of strings ("01" and "10"), resulting in zero additional flips at the junctions. The total number of flips is simply the sum of internal flips: $X + Y$.

**Case 2: $X \neq Y$**

Without loss of generality, let's assume $X > Y$. This means we have more "01" strings than "10" strings.
To minimize junction flips, we should try to arrange the strings such that we use as many "01" + "10" or "10" + "01" transitions as possible.

We can form an alternating sequence using all $Y$ "10" strings and $Y+1$ "01" strings. For example, we can arrange them as:
"01" + "10" + "01" + "10" + ... + "01" + "10" + "01"

This sequence uses $Y$ "10"s and $Y+1$ "01"s, totaling $2Y+1$ strings. All $2Y$ junctions in this part are either "01"+"10" or "10"+"01", contributing zero flips. The internal flips from these $2Y+1$ strings are $2Y+1$.

We are left with $X - (Y+1)$ "01" strings. These must be appended to the end of our current sequence. The current sequence ends with a "01". So, we will be concatenating "01" + "01".
Each such "01" + "01" concatenation creates a junction '1' + '0', which results in one flip.
We have $X - (Y+1)$ such "01" + "01" concatenations.

The total number of flips will be:
(Internal flips from $Y$ "10"s and $Y+1$ "01"s) + (Junction flips from remaining "01"s)
$= (Y + (Y+1)) + (X - (Y+1))$
$= 2Y + 1 + X - Y - 1$
$= X + Y$

Wait, this calculation seems to suggest $X+Y$ again. Let's re-evaluate the junction flips.

The total number of strings is $X+Y$. If we have $N$ strings, there are $N-1$ junctions.
If $X > Y$:
We can arrange $Y$ "10"s and $Y$ "01"s alternatingly: "01" "10" "01" "10" ... "01" "10". This uses $2Y$ strings and has $2Y-1$ junctions, all of which are "01"+"10" or "10"+"01" (0 flips).
We are left with $X-Y$ "01" strings.
If we append them one by one:
... "01" "10" + "01" (junction '0'+'0', 0 flips)
... "01" "10" + "01" + "01" (junction '1'+'0', 1 flip)
... "01" "10" + "01" + "01" + "01" (junction '1'+'0', 1 flip)

This is still not quite right. Let's think about the structure of the final string.
The total number of characters is $2(X+Y)$.
The number of '0's is $X$ (from "01") + $Y$ (from "10") = $X+Y$.
The number of '1's is $X$ (from "01") + $Y$ (from "10") = $X+Y$.

Consider the sequence of strings.
If $X=Y$, we can do "01" "10" "01" "10" ...
The junctions are '1'+'1' (0 flips) and '0'+'0' (0 flips).
Total flips = $X$ (from "01"s) + $Y$ (from "10"s) = $X+Y$.

If $X > Y$:
We have $X$ "01"s and $Y$ "10"s.
We can arrange them to minimize junction flips. The best we can do is to have at most one type of junction appear more than once.
Consider the sequence: "01" "10" "01" "10" ... "01" "10" (using $Y$ "01"s and $Y$ "10"s). This part has $2Y$ strings and $2Y-1$ junctions, all of which are "01"+"10" or "10"+"01" (0 flips).
We are left with $X-Y$ "01" strings.
If we append them: ... "01" "10" + "01" + "01" + ... + "01".
The junction between "10" and the first appended "01" is '0'+'0' (0 flips).
The junctions between the appended "01"s are '1'+'0' (1 flip each).
There are $(X-Y)-1$ such junctions.
Total flips = $X$ (internal "01") + $Y$ (internal "10") + $(X-Y-1)$ (junctions between appended "01"s).
Total flips = $X + Y + X - Y - 1 = 2X - 1$.

If $Y > X$:
Symmetrically, we can arrange $X$ "01"s and $X$ "10"s alternatingly: "10" "01" "10" "01" ... "10" "01". This uses $2X$ strings and has $2X-1$ junctions, all of which are "10"+"01" or "01"+"10" (0 flips).
We are left with $Y-X$ "10" strings.
If we append them: ... "10" "01" + "10" + "10" + ... + "10".
The junction between "01" and the first appended "10" is '1'+'1' (0 flips).
The junctions between the appended "10"s are '0'+'1' (1 flip each).
There are $(Y-X)-1$ such junctions.
Total flips = $X$ (internal "01") + $Y$ (internal "10") + $(Y-X-1)$ (junctions between appended "10"s).
Total flips = $X + Y + Y - X - 1 = 2Y - 1$.

Combining these:
- If $X = Y$, flips = $X + Y$.
- If $X > Y$, flips = $2X - 1$.
- If $Y > X$, flips = $2Y - 1$.

This can be summarized as:
- If $X = Y$, flips = $X + Y$.
- If $X \neq Y$, flips = $2 \times \max(X, Y) - 1$.

Let's test this with an example.
$X=2, Y=1$. Strings: "01", "01", "10".
Possible arrangements:
1. "01" "01" "10" -> "010110". Flips: 01, 10, 01, 11, 10. Total = 4.
   Internal: "01" (1), "01" (1), "10" (1) = 3.
   Junctions: "01"+"01" ('1'+'0', 1 flip), "01"+"10" ('1'+'1', 0 flips). Total junction flips = 1.
   Total = 3 + 1 = 4.
   Formula: $X=2, Y=1$. $X \neq Y$. $\max(X,Y) = 2$. $2 \times 2 - 1 = 3$. This doesn't match.

Let's re-think the junction flips.
The total number of strings is $N = X+Y$. There are $N-1$ junctions.
Each junction contributes 0 or 1 flip.
We want to maximize the number of 0-flip junctions.
0-flip junctions occur when:
- "01" + "10" (junction '1' + '1')
- "10" + "01" (junction '0' + '0')

1-flip junctions occur when:
- "01" + "01" (junction '1' + '0')
- "10" + "10" (junction '0' + '1')

Consider the sequence of strings.
If $X=Y$: "01" "10" "01" "10" ...
Junctions: '1'+'1', '0'+'0', '1'+'1', '0'+'0', ...
All $X+Y-1$ junctions are 0-flip.
Total flips = $X$ (internal "01") + $Y$ (internal "10") + 0 (junctions) = $X+Y$. This is correct.

If $X > Y$:
We have $X$ "01"s and $Y$ "10"s.
We can form a sequence that uses all $Y$ "10"s and $Y$ "01"s alternatingly:
"01" "10" "01" "10" ... "01" "10"
This uses $2Y$ strings. The junctions are '1'+'1' and '0'+'0', all 0-flip.
We are left with $X-Y$ "01" strings.
We must append these $X-Y$ "01" strings.
The sequence ends with "10". So the first appended string is "01".
... "01" "10" + "01"
Junction is '0'+'0' (0 flips).
Now we have $X-Y-1$ "01" strings left. We append them:
... "01" "10" "01" + "01" + "01" ...
The junction between the first two appended "01"s is '1'+'0' (1 flip).
The junction between the next two appended "01"s is '1'+'0' (1 flip).
...
There are $(X-Y)-1$ such junctions between the appended "01" strings.
Total flips = $X$ (internal "01") + $Y$ (internal "10") + 0 (first junction) + $(X-Y-1)$ (junctions between appended "01"s).
Total flips = $X + Y + 0 + X - Y - 1 = 2X - 1$.

If $Y > X$:
Symmetrically, we have $X$ "01"s and $Y$ "10"s.
We can form a sequence that uses all $X$ "01"s and $X$ "10"s alternatingly:
"10" "01" "10" "01" ... "10" "01"
This uses $2X$ strings. The junctions are '0'+'0' and '1'+'1', all 0-flip.
We are left with $Y-X$ "10" strings.
The sequence ends with "01". So the first appended string is "10".
... "10" "01" + "10"
Junction is '1'+'1' (0 flips).
Now we have $Y-X-1$ "10" strings left. We append them:
... "10" "01" "10" + "10" + "10" ...
The junction between the first two appended "10"s is '0'+'1' (1 flip).
The junction between the next two appended "10"s is '0'+'1' (1 flip).
...
There are $(Y-X)-1$ such junctions between the appended "10" strings.
Total flips = $X$ (internal "01") + $Y$ (internal "10") + 0 (first junction) + $(Y-X-1)$ (junctions between appended "10"s).
Total flips = $X + Y + 0 + Y - X - 1 = 2Y - 1$.

So the logic seems to be:
- If $X = Y$, total flips = $X + Y$.
- If $X > Y$, total flips = $2X - 1$.
- If $Y > X$, total flips = $2Y - 1$.

This can be written as:
If $X == Y$, result is $X + Y$.
Else, result is $2 * \max(X, Y) - 1$.

Let's re-check the example $X=2, Y=1$.
$X \neq Y$. $\max(X,Y) = 2$.
Result = $2 \times 2 - 1 = 3$.

Let's construct the string for $X=2, Y=1$ to get 3 flips.
We have two "01"s and one "10".
According to the logic for $X > Y$:
We use $Y=1$ "10" and $Y=1$ "01" alternatingly: "01" "10". Junction '1'+'1' (0 flips).
We are left with $X-Y = 2-1 = 1$ "01".
Append it: "01" "10" + "01".
The sequence is "011001".
Internal flips: "01" (1), "10" (1), "01" (1) = 3.
Junctions:
"01" + "10" -> '1'+'1' (0 flips)
"10" + "01" -> '0'+'0' (0 flips)
Total flips = 3 + 0 = 3.
This matches the formula $2 \times \max(2,1) - 1 = 3$.

Let's try another example: $X=1, Y=2$. Strings: "01", "10", "10".
$X \neq Y$. $\max(X,Y) = 2$.
Formula result = $2 \times 2 - 1 = 3$.
Logic for $Y > X$:
Use $X=1$ "01" and $X=1$ "10" alternatingly: "10" "01". Junction '0'+'0' (0 flips).
We are left with $Y-X = 2-1 = 1$ "10".
Append it: "10" "01" + "10".
The sequence is "100110".
Internal flips: "10" (1), "01" (1), "10" (1) = 3.
Junctions:
"10" + "01" -> '0'+'0' (0 flips)
"01" + "10" -> '1'+'1' (0 flips)
Total flips = 3 + 0 = 3.
This matches the formula $2 \times \max(1,2) - 1 = 3$.

Let's try $X=3, Y=3$.
$X=Y$. Formula result = $X+Y = 3+3 = 6$.
Arrangement: "01" "10" "01" "10" "01" "10".
String: "011001100110".
Internal flips: 3 from "01"s, 3 from "10"s = 6.
Junctions: '1'+'1', '0'+'0', '1'+'1', '0'+'0', '1'+'1'. All 0 flips.
Total flips = 6. Correct.

The logic seems solid. The key is to realize that when $X \neq Y$, we can arrange the strings such that all but one type of string are perfectly alternated with the other type, and the excess strings of the more numerous type are appended. This creates a block of $k-1$ identical junctions (where $k$ is the number of excess strings), each contributing one flip.

The number of internal flips is always $X+Y$.
The number of junction flips is:
- 0 if $X=Y$. Total = $X+Y$.
- If $X > Y$: We have $X-Y$ excess "01"s. The sequence ends with "10" + "01" (0 flips). Then we append $X-Y$ "01"s. The first junction is "01"+"01" ('1'+'0', 1 flip). The remaining $(X-Y)-1$ junctions are also "01"+"01" ('1'+'0', 1 flip). Total junction flips = $1 + (X-Y-1) = X-Y$.
  Wait, this is not what I derived before.

Let's re-examine the structure when $X > Y$.
We have $X$ "01"s and $Y$ "10"s.
Consider the arrangement:
"01" "10" "01" "10" ... "01" "10" (using $Y$ "01"s and $Y$ "10"s). This part has $2Y$ strings.
The junctions are '1'+'1' and '0'+'0', all 0-flip.
We are left with $X-Y$ "01" strings.
The sequence ends with "10".
So we append: "01" "10" + "01" + "01" + ... + "01".
The junction between "10" and the first appended "01" is '0'+'0' (0 flips).
The junctions between the appended "01"s are '1'+'0' (1 flip each).
There are $(X-Y)-1$ such junctions.
Total junction flips = 0 (from the first $2Y-1$ junctions) + 0 (from "10"+"01") + $(X-Y-1)$ (from "01"+"01").
Total junction flips = $X-Y-1$.
Total flips = (Internal flips) + (Junction flips)
Total flips = $(X+Y) + (X-Y-1) = 2X - 1$.

This matches my previous derivation. The key is that the arrangement "01" "10" ... "01" "10" followed by appending the excess strings is optimal.
The number of strings is $X+Y$.
If $X=Y$, we have $X+Y-1$ junctions, all 0-flip. Total flips = $X+Y$.
If $X > Y$, we have $X+Y-1$ junctions.
The arrangement is: $Y$ pairs of ("01", "10") followed by $X-Y$ "01"s.
Example: $X=3, Y=1$. Strings: "01", "01", "01", "10".
Arrangement: "01" "10" + "01" + "01".
Sequence: "01100101".
Internal flips: 3 from "01"s, 1 from "10" = 4.
Junctions:
"01" + "10" -> '1'+'1' (0 flips)
"10" + "01" -> '0'+'0' (0 flips)
"01" + "01" -> '1'+'0' (1 flip)
"01" + "01" -> '1'+'0' (1 flip)
Total junction flips = 0 + 0 + 1 + 1 = 2.
Total flips = 4 (internal) + 2 (junction) = 6.

Formula for $X=3, Y=1$: $X > Y$. $2X-1 = 2(3)-1 = 6-1 = 5$.
This is still not matching.

Let's reconsider the structure of the problem. We are minimizing flips.
The total number of characters is $2(X+Y)$.
The number of '0's is $X+Y$. The number of '1's is $X+Y$.
A flip occurs at a boundary between a '0' and a '1'.
The total number of flips is the number of times a '0' is followed by a '1' or a '1' is followed by a '0'.

Consider the sequence of strings.
If $X=Y$: "01" "10" "01" "10" ...
The string looks like: 01100110...
The boundaries are:
01 (flip)
11 (no flip)
10 (flip)
00 (no flip)
01 (flip)
11 (no flip)
...
The pattern of characters at junctions is '1' from "01" and '1' from "10" (no flip), or '0' from "10" and '0' from "01" (no flip).
So, if $X=Y$, all $X+Y-1$ junctions are 0-flip.
Total flips = $X$ (from "01"s) + $Y$ (from "10"s) = $X+Y$. This is correct.

If $X > Y$:
We have $X$ "01"s and $Y$ "10"s.
To minimize flips, we want to avoid "01"+"01" and "10"+"10" junctions.
We can arrange $Y$ "10"s and $Y$ "01"s alternatingly: "01" "10" "01" "10" ... "01" "10".
This uses $2Y$ strings. The junctions are '1'+'1' and '0'+'0', all 0-flip.
We are left with $X-Y$ "01" strings.
The sequence ends with "10".
We append the $X-Y$ "01" strings: "01" "10" + "01" + "01" + ... + "01".
The junction "10" + "01" is '0'+'0' (0 flips).
The junctions "01" + "01" are '1'+'0' (1 flip).
There are $(X-Y)-1$ such junctions.
Total junction flips = 0 (from first $2Y-1$ junctions) + 0 (from "10"+"01") + $(X-Y-1)$ (from "01"+"01").
Total junction flips = $X-Y-1$.
Total flips = (Internal flips) + (Junction flips)
Total flips = $(X+Y) + (X-Y-1) = 2X - 1$.

This logic seems to be correct. Let's re-verify the example $X=3, Y=1$.
$X > Y$. Formula: $2X-1 = 2(3)-1 = 5$.
Arrangement: "01" "10" + "01" + "01".
Sequence: "01100101".
Internal flips: "01" (1), "10" (1), "01" (1), "01" (1) = 4.
Junctions:
"01" + "10" -> '1'+'1' (0 flips)
"10" + "01" -> '0'+'0' (0 flips)
"01" + "01" -> '1'+'0' (1 flip)
Total junction flips = 0 + 0 + 1 = 1.
Total flips = 4 (internal) + 1 (junction) = 5.
This matches the formula $2X-1$.

The confusion was in counting the internal flips. The internal flips are always $X+Y$. The problem is to minimize the *additional* flips at junctions.

Let's re-state the number of junction flips:
- If $X=Y$: 0 junction flips. Total flips = $X+Y$.
- If $X > Y$: We have $X-Y$ excess "01"s. The arrangement is $Y$ pairs of ("01", "10") followed by $X-Y$ "01"s.
  The sequence of string types is: "01", "10", "01", "10", ..., "01", "10" (Y pairs) followed by "01", "01", ..., "01" ($X-Y$ times).
  The junctions are:
  - Between "01" and "10": '1'+'1' (0 flips)
  - Between "10" and "01": '0'+'0' (0 flips)
  - Between "01" and "01": '1'+'0' (1 flip)
  The sequence of junctions:
  ("01" + "10") -> '1'+'1' (0 flips)
  ("10" + "01") -> '0'+'0' (0 flips)
  ... (this pattern repeats Y-1 times)
  ("10" + "01") -> '0'+'0' (0 flips)
  ("01" + "01") -> '1'+'0' (1 flip)
  ("01" + "01") -> '1'+'0' (1 flip)
  ... ($X-Y-1$ times)
  Total junction flips = $(X-Y-1) \times 1 = X-Y-1$.
  Total flips = $(X+Y)$ (internal) + $(X-Y-1)$ (junctions) = $2X-1$.

- If $Y > X$: We have $Y-X$ excess "10"s. The arrangement is $X$ pairs of ("10", "01") followed by $Y-X$ "10"s.
  The sequence of string types is: "10", "01", "10", "01", ..., "10", "01" (X pairs) followed by "10", "10", ..., "10" ($Y-X$ times).
  The junctions are:
  - Between "10" and "01": '0'+'0' (0 flips)
  - Between "01" and "10": '1'+'1' (0 flips)
  - Between "10" and "10": '0'+'1' (1 flip)
  The sequence of junctions:
  ("10" + "01") -> '0'+'0' (0 flips)
  ("01" + "10") -> '1'+'1' (0 flips)
  ... (this pattern repeats X-1 times)
  ("01" + "10") -> '1'+'1' (0 flips)
  ("10" + "10") -> '0'+'1' (1 flip)
  ("10" + "10") -> '0'+'1' (1 flip)
  ... ($Y-X-1$ times)
  Total junction flips = $(Y-X-1) \times 1 = Y-X-1$.
  Total flips = $(X+Y)$ (internal) + $(Y-X-1)$ (junctions) = $2Y-1$.

The logic holds. The result is:
- If $X = Y$: $X+Y$
- If $X \neq Y$: $2 \times \max(X, Y) - 1$

This can be implemented directly.

## Complexity Analysis

- **Time Complexity**: $O(1)$
  The solution involves a few arithmetic operations and a comparison. The time taken does not depend on the magnitude of $X$ and $Y$ beyond what fits into standard integer types.

- **Space Complexity**: $O(1)$
  The solution uses a constant amount of extra space to store variables like $X$, $Y$, and the result.

## Solution Code

```cpp
#include <iostream>
#include <algorithm> // Required for std::max

void solve() {
    int X, Y;
    std::cin >> X >> Y;

    int result;
    if (X == Y) {
        // If X equals Y, we can perfectly alternate "01" and "10" strings.
        // For example, "01", "10", "01", "10", ...
        // All junctions between strings will be "01"+"10" (ends in '1', starts with '1' -> '11', 0 flips)
        // or "10"+"01" (ends in '0', starts with '0' -> '00', 0 flips).
        // Thus, there are no additional flips at the junctions.
        // The total flips are only the internal flips of each string.
        // Each "01" has 1 flip, each "10" has 1 flip.
        // So, total flips = X (from "01"s) + Y (from "10"s) = X + Y.
        result = X + Y;
    } else {
        // If X is not equal to Y, one type of string is more numerous.
        // Let's say X > Y. We have X "01"s and Y "10"s.
        // To minimize junction flips, we arrange Y pairs of ("01", "10") alternatingly:
        // "01" "10" "01" "10" ... "01" "10". This uses 2Y strings.
        // The junctions are "01"+"10" ('1'+'1', 0 flips) and "10"+"01" ('0'+'0', 0 flips).
        // We are left with X - Y "01" strings.
        // The sequence ends with "10". We append the remaining "01"s:
        // ... "01" "10" + "01" + "01" + ... + "01".
        // The junction "10" + "01" is '0'+'0' (0 flips).
        // The subsequent junctions are "01" + "01", which are '1'+'0' (1 flip each).
        // There are (X - Y) - 1 such "01"+"01" junctions.
        // Total junction flips = 0 (from alternating part) + 0 (from "10"+"01") + (X - Y - 1) (from "01"+"01") = X - Y - 1.
        // Total flips = (Internal flips) + (Junction flips)
        // Total flips = (X + Y) + (X - Y - 1) = 2X - 1.
        //
        // Symmetrically, if Y > X, we have Y - X excess "10"s.
        // The arrangement is X pairs of ("10", "01") followed by Y - X "10"s.
        // The junctions are "10"+"01" ('0'+'0', 0 flips) and "01"+"10" ('1'+'1', 0 flips).
        // The sequence ends with "01". We append the remaining "10"s:
        // ... "10" "01" + "10" + "10" + ... + "10".
        // The junction "01" + "10" is '1'+'1' (0 flips).
        // The subsequent junctions are "10" + "10", which are '0'+'1' (1 flip each).
        // There are (Y - X) - 1 such "10"+"10" junctions.
        // Total junction flips = (Y - X - 1).
        // Total flips = (X + Y) + (Y - X - 1) = 2Y - 1.
        //
        // In general, when X != Y, the total flips are 2 * max(X, Y) - 1.
        result = 2 * std::max(X, Y) - 1;
    }

    std::cout << result << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t; // Read the number of test cases
    while (t--) {
        solve(); // Solve each test case
    }

    return 0;
}
```