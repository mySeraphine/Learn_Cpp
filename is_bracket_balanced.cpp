//
// Created by Xiang_Duan on 2021/2/4.
//
#include <stack>
#include <string>
#include <iostream>


bool is_balanced(const std::string &expression) {
    const char LEFT_PARENTHESIS = '(';
    const char RIGHT_PARENTHESIS = ')';

    std::stack<char> store;

    std::string::size_type L;
    char next;
    bool failed = false;
    for (L = 0; !failed && L < expression.length(); ++L) {
        next = expression.at(L);
        if (next == LEFT_PARENTHESIS) { //如果是左括号，入栈
            store.push(next);
        } else if (next == RIGHT_PARENTHESIS && (!store.empty())) { //如果是右括号，且栈不为空，删除栈内的左括号
            store.pop();
        } else if (next == RIGHT_PARENTHESIS && (store.empty())) {  //如果是右括号，且栈为空，修改当前flag，表示括号匹配
            failed = true;
        }
    }
    return (store.empty()) && !failed;  //如果栈为空，且括号匹配，则输出true
}

//test 
int main() {
    std::string str = "((()))";
    std::cout << is_balanced(str);

}
