//
// Created by Xiang_Duan on 2021/2/4.
//
#include <cctype>
#include <cstring>
#include <iostream>
#include <stack>

using namespace std;

double read_and_evaluate(istream &ins);

void evaluate_stack_tops(stack<double> &numbers, stack<char> &operations);

int main() {
    double answer;
    cout << "Type a fully parenthesised arithmetic expression: " << endl;
    answer = read_and_evaluate(cin);
    cout << "That evaluates to " << answer << endl;

    return 0;
}

double read_and_evaluate(istream &ins) {
    const char DECIMAL = '.';
    const char RIGHT_PARENTHESIS = ')';
    stack<double> numbers;
    stack<char> operations;
    double number;
    char symbol;

    while (ins && ins.peek() != '\n') {
        if (isdigit(ins.peek()) || (ins.peek() == DECIMAL)) {
            ins >> number;
            numbers.push(number);
        } else if (strchr("+-*/", ins.peek()) != nullptr) { //查找是否有+-*/号
            ins >> symbol;
            operations.push(symbol);

        } else if (ins.peek() == RIGHT_PARENTHESIS) {
            ins.ignore();
            evaluate_stack_tops(numbers, operations);

        } else {
            ins.ignore();
        }
    }
    return numbers.top();
}

void evaluate_stack_tops(stack<double> &numbers, stack<char> &operations) {
    double number1, number2;
    number2 = numbers.top();
    numbers.pop();
    number1 = numbers.top();
    numbers.pop();

    switch (operations.top()) {
        case '+':
            numbers.push(number1 + number2);
            break;
        case '-':
            numbers.push(number1 - number2);
            break;
        case '*':
            numbers.push(number1 * number2);
            break;
        case '/':
            numbers.push(number1 / number2);
            break;
    }
    operations.pop();
}
