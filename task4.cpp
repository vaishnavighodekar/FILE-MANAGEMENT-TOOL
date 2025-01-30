#include <iostream>
#include <string>
#include <stdexcept>
#include <cctype>

using namespace std;

class SimpleCompiler {
    string expression;
    size_t pos;

    char peek() {
        return (pos < expression.length()) ? expression[pos] : '\0';
    }

    char get() {
        return (pos < expression.length()) ? expression[pos++] : '\0';
    }

    double parseNumber() {
        double number = 0;
        while (isdigit(peek())) {
            number = number * 10 + (get() - '0');
        }

        if (peek() == '.') {
            get(); // consume '.'
            double factor = 0.1;
            while (isdigit(peek())) {
                number += (get() - '0') * factor;
                factor *= 0.1;
            }
        }

        return number;
    }

    double parseFactor() {
        if (peek() == '(') {
            get(); // consume '('
            double result = parseExpression();
            if (peek() == ')') {
                get(); // consume ')'
            } else {
                throw runtime_error("Expected closing parenthesis");
            }
            return result;
        } else if (isdigit(peek()) || peek() == '.') {
            return parseNumber();
        } else {
            throw runtime_error("Unexpected character");
        }
    }

    double parseTerm() {
        double result = parseFactor();
        while (peek() == '*' || peek() == '/') {
            char op = get();
            if (op == '*') {
                result *= parseFactor();
            } else if (op == '/') {
                double divisor = parseFactor();
                if (divisor == 0) {
                    throw runtime_error("Division by zero");
                }
                result /= divisor;
            }
        }
        return result;
    }

    double parseExpression() {
        double result = parseTerm();
        while (peek() == '+' || peek() == '-') {
            char op = get();
            if (op == '+') {
                result += parseTerm();
            } else if (op == '-') {
                result -= parseTerm();
            }
        }
        return result;
    }

public:
    double evaluate(const string &expr) {
        expression = expr;
        pos = 0;
        return parseExpression();
    }
};

int main() {
    SimpleCompiler compiler;
    string input;

    cout << "Enter arithmetic expressions (type 'exit' to quit):\n";
    while (true) {
        cout << "> ";
        getline(cin, input);
        if (input == "exit") {
            break;
        }
        try {
            double result = compiler.evaluate(input);
            cout << "Result: " << result << "\n";
        } catch (const exception &e) {
            cout << "Error: " << e.what() << "\n";
        }
    }

    return 0;
}
