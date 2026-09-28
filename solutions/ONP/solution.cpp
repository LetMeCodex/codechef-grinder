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