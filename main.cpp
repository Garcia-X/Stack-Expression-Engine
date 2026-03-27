#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <cctype>

#include "ArrayStack.h"

using namespace std;
static constexpr bool DEBUG_TOKENS = false;

// Token

struct Token {
    string value;   // number, operator, or parenthesis
};

// Tokenizer

vector<Token> tokenize(const string& line) {
    vector<Token> tokens;

    size_t i = 0;
    while (i < line.size()) {
        char c = line[i];

        if (isspace(static_cast<unsigned char>(c))) {
            ++i;
            continue;
        }

        if (isdigit(static_cast<unsigned char>(c))) {
            size_t j = i;
            while (j < line.size() && isdigit(static_cast<unsigned char>(line[j]))) ++j;
            tokens.push_back(Token{line.substr(i, j - i)});
            i = j;
            continue;
        }

        if (c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')') {
            tokens.push_back(Token{string(1, c)});
            ++i;
            continue;
        }

        tokens.push_back(Token{string(1, c)});
        ++i;
    }

    return tokens;
}
// Helpers

bool isOperator(const string& s) {
    return s == "+" || s == "-" || s == "*" || s == "/";
}

int precedence(const string& op) {
    // TODO
    return 0;
}

// Detection

bool isValidPostfix(const vector<Token>& tokens) {
    if (tokens.empty()) return false;

    int depth = 0;
    int numberCount = 0;

    for (const auto& t : tokens) {
        const string& v = t.value;

        if (v == "(" || v == ")") return false;

        bool isNumber = !v.empty();
        for (char ch : v) {
            if (!isdigit(static_cast<unsigned char>(ch))) {
                isNumber = false;
                break;
            }
        }

        if (isNumber) {
            ++depth;
            ++numberCount;
            continue;
        }

        if (isOperator(v)) {
            if (depth < 2) return false;
            --depth;  // consumes 2 operands, produces 1 result
            continue;
        }

        return false;  // invalid token
    }

    return numberCount > 0 && depth == 1;
}

bool isValidInfix(const vector<Token>& tokens) {
    // TODO
    return false;
}

// Conversion

vector<Token> infixToPostfix(const vector<Token>& tokens) {
    vector<Token> output;
    // TODO
    return output;
}

// Evaluation

double evalPostfix(const vector<Token>& tokens) {
    ArrayStack<double> stack;

    auto isNumberToken = [](const string& v) -> bool {
        if (v.empty()) return false;
        for (char ch : v) {
            if (!isdigit(static_cast<unsigned char>(ch))) return false;
        }
        return true;
    };

    for (const auto& t : tokens) {
        const string& v = t.value;

        if (isNumberToken(v)) {
            stack.push(static_cast<double>(stoll(v)));
            continue;
        }

        if (isOperator(v)) {
            if (stack.size() < 2) {
                throw runtime_error("invalid postfix expression");
            }

            double b = stack.top();
            stack.pop();
            double a = stack.top();
            stack.pop();

            if (v == "+") stack.push(a + b);
            else if (v == "-") stack.push(a - b);
            else if (v == "*") stack.push(a * b);
            else if (v == "/") stack.push(a / b);

            continue;
        }

        throw runtime_error("invalid token in postfix");
    }

    if (stack.size() != 1) {
        throw runtime_error("invalid postfix expression");
    }

    return stack.top();
}
// Main

int main() {
    string line;
    getline(cin, line);

    vector<Token> tokens = tokenize(line);

    if (DEBUG_TOKENS) {
        cout << "TOKENS: ";
        for (const auto& t : tokens) cout << "[" << t.value << "] ";
        cout << "\n";
    }

    if (isValidPostfix(tokens)) {
        cout << "FORMAT: POSTFIX\n";
        cout << "RESULT: " << evalPostfix(tokens) << "\n";
    }
    else if (isValidInfix(tokens)) {
        vector<Token> postfix = infixToPostfix(tokens);
        cout << "FORMAT: INFIX\n";
        cout << "POSTFIX: ";
        for (const auto& t : postfix) {
            cout << t.value << " ";
        }
        cout << "\n";
        cout << "RESULT: " << evalPostfix(postfix) << "\n";
    }
    else {
        cout << "FORMAT: NEITHER\n";
        cout << "ERROR: invalid expression\n";
    }

    return 0;
}

