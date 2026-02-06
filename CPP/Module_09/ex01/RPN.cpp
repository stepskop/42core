#include "RPN.hpp"

RPN::RPN(void)
{
}

RPN::RPN(const RPN &src)
{
	*this = src;
}

RPN &RPN::operator = (const RPN &src)
{
    return *this;
}

RPN::~RPN(void)
{
}

void RPN::evaluate(const std::string &expression)
{
    int pos = 0;
    std::stack<int> stack;

    while (expression[pos]) {

        char c = expression[pos];

        if (std::isdigit(c)) {
            stack.push(c - '0');
        }

        if (c == '+' || c == '-' || c == '*' || c == '/') {
            if (stack.size() < 2) {
                std::cerr << "Error: invalid expression." << std::endl;
                return;
            }

            int b = stack.top();
            stack.pop();

            int a = stack.top();
            stack.pop();

            int res;

            switch (c) {
                case '+': res = a + b; break;
                case '-': res = a - b; break;
                case '*': res = a * b; break;
                case '/':
                    if (b == 0) {
                        std::cerr << "Error: division by zero." << std::endl;
                        return;
                    }
                    res = a / b; break;
                default:
                std::cerr << "Error: unknown operator." << std::endl;
                return;
            }

            stack.push(res);
        }

        pos++;
    }

    if (stack.size() != 1) {
        std::cerr << "Error: invalid expression." << std::endl;
        return;
    }

    std::cout << stack.top() << std::endl;
}
