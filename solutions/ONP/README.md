# Transform the Expression (ONP)

- **Difficulty Rating**: 1300
- **Solved in**: 2 attempt(s)

## Problem Summary

The problem asks us to convert an infix mathematical expression to its equivalent Reverse Polish Notation (RPN) form. The infix expressions will contain single-letter operands, operators `+`, `-`, `*`, `/`, `^` (exponentiation), and parentheses `(` and `)`. The operators have standard precedence and associativity rules: `^` is right-associative, while `+`, `-`, `*`, `/` are left-associative.

## Intuition & Mathematical Observation

The conversion from infix to RPN is a classic problem that can be solved using a stack-based algorithm. The core idea is to process the infix expression from left to right and decide where each element (operand or operator) should go in the RPN output.

Here's the general approach:

1.  **Operands**: When an operand (a letter) is encountered, it is immediately appended to the RPN output string. Operands in RPN appear in the same order as they do in the infix expression.

2.  **Opening Parenthesis `(`**: When an opening parenthesis is encountered, it is pushed onto an operator stack. This signifies the start of a sub-expression that needs to be evaluated before operators outside the parentheses.

3.  **Closing Parenthesis `)`**: When a closing parenthesis is encountered, operators are popped from the operator stack and appended to the RPN output until an opening parenthesis `(` is found at the top of the stack. The opening parenthesis is then popped from the stack and discarded (as it's no longer needed). This ensures that all operators within the parentheses are processed before any operators outside them.

4.  **Operators**: When an operator is encountered, we need to consider its precedence and associativity relative to the operator at the top of the stack.
    *   If the stack is empty, or the top of the stack is an opening parenthesis, the current operator is pushed onto the stack.
    *   If the operator at the top of the stack has *higher* precedence than the current operator, the operator from the stack is popped and appended to the RPN output. This process continues until the stack is empty, the top is an opening parenthesis, or the operator at the top has *lower or equal* precedence than the current operator.
    *   If the operator at the top of the stack has *lower* precedence than the current operator, the current operator is pushed onto the stack.
    *   If the operator at the top of the stack has *equal* precedence to the current operator:
        *   For left-associative operators (`+`, `-`, `*`, `/`), the operator from the stack is popped and appended to the RPN output, and then the current operator is pushed.
        *   For right-associative operators (`^`), the current operator is pushed directly onto the stack.

5.  **End of Expression**: After processing the entire infix expression, any remaining operators on the stack are popped and appended to the RPN output.

The `getPrecedence` function is crucial for implementing the operator precedence logic. We assign higher values to operators with higher precedence. Parentheses are given a low precedence when on the stack to ensure they are not popped prematurely.

The `isOperator` and `isOperand` helper functions simplify the character classification.

The `main` function handles reading the number of test cases and calling the `solve` function for each. `std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);` are standard optimizations for faster I/O in C++ competitive programming.

## Complexity Analysis

*   **Time Complexity**: $O(N)$, where $N$ is the length of the infix expression. Each character in the infix expression is processed exactly once. Each character is pushed onto and popped from the stack at most once. Appending to the RPN string also takes amortized constant time per character.

*   **Space Complexity**: $O(N)$, where $N$ is the length of the infix expression. In the worst case, the operator stack might store all operators and parentheses if the expression is structured like `((((a+b)*c)-d)/e)`. The RPN output string also takes $O(N)$ space.

## Solution Code

```cpp
#include <iostream> // Required for input/output operations (cin, cout)
#include <string>   // Required for std::string
#include <stack>    // Required for std::stack
#include <cctype>   // Required for std::isalpha to check if a character is an alphabet

// Function to determine the precedence of an operator.
// Higher return value means higher precedence.
// Parentheses '(' are given the lowest effective precedence to ensure they stay on the stack
// until a matching ')' is encountered.
int getPrecedence(char op) {
    if (op == '^') return 3; // Exponentiation has the highest precedence
    if (op == '*' || op == '/') return 2; // Multiplication and division have medium precedence
    if (op == '+' || op == '-') return 1; // Addition and subtraction have the lowest precedence
    return 0; // For '(' or any other non-operator character, effectively lowest
}

// Function to check if a character is one of the supported operators.
bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

// Function to check if a character is an operand (a letter).
// The problem statement specifies single letters.
bool isOperand(char c) {
    return std::isalpha(c); // Checks if c is an alphabetic character
}

// Solves a single test case by converting an infix expression to RPN.
void solve() {
    std::string infix_expression;
    std::cin >> infix_expression; // Read the infix expression

    std::string rpn_output = ""; // String to store the resulting RPN expression
    std::stack<char> op_stack;   // Stack to hold operators and opening parentheses

    // Iterate through each character of the infix expression
    for (char c : infix_expression) {
        if (isOperand(c)) {
            // If the character is an operand, append it directly to the output.
            rpn_output += c;
        } else if (c == '(') {
            // If it's an opening parenthesis, push it onto the operator stack.
            op_stack.push(c);
        } else if (c == ')') {
            // If it's a closing parenthesis:
            // Pop operators from the stack and append to output until an opening parenthesis is found.
            while (!op_stack.empty() && op_stack.top() != '(') {
                rpn_output += op_stack.top();
                op_stack.pop();
            }
            // After the loop, if the stack is not empty and the top is '(', pop it (discarding it).
            // The problem statement guarantees valid expressions, so we don't need to worry about mismatched '('.
            if (!op_stack.empty() && op_stack.top() == '(') {
                op_stack.pop();
            }
        } else if (isOperator(c)) {
            // If the character is an operator (let's call it op1):
            // Pop operators (op2) from the stack and append to output as long as:
            // 1. The stack is not empty.
            // 2. The top of the stack is not an opening parenthesis.
            // 3. op2 has higher precedence than op1, OR
            //    op2 has the same precedence as op1 AND op1 is left-associative.
            //    (All operators except '^' are left-associative. '^' is right-associative.)
            while (!op_stack.empty() && op_stack.top() != '(' &&
                   (getPrecedence(op_stack.top()) > getPrecedence(c) ||
                    (getPrecedence(op_stack.top()) == getPrecedence(c) && c != '^'))) {
                rpn_output += op_stack.top();
                op_stack.pop();
            }
            // Push the current operator (op1) onto the stack.
            op_stack.push(c);
        }
    }

    // After processing the entire infix expression, pop any remaining operators from the stack
    // and append them to the output.
    while (!op_stack.empty()) {
        rpn_output += op_stack.top();
        op_stack.pop();
    }

    std::cout << rpn_output << std::endl; // Print the final RPN expression
}

int main() {
    // Optimize C++ standard streams for faster input/output operations.
    // This is a common practice in competitive programming.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t; // Read the number of test cases
    while (t--) {
        solve(); // Call the solve function for each test case
    }

    return 0; // Indicate successful execution
}
```