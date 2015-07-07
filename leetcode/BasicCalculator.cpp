//
// Created by Li Qiang on 15/6/9.
//

#include <iostream>
#include <stack>
using namespace std;

int calculate(string s)
{
    if (s.length() == 0)
        return 0;
    if (s.length() == 1)
        return s[0] - '0';

    stack<char> opStack;
    stack<int> numStack;
    int result = 0;
    char op;

    int i = 0;
    int a = 0;
    while(i < s.length())
    {
        char ch = s[i];
        switch (s[i]) {
            case '(':
                opStack.push(ch);
                i++;
                break;
            case '+':
            case '-':
                i++;
                if(opStack.empty() == true) {
                    opStack.push(ch);
                    break;
                }
                op = opStack.top();
                if (op == '(')
                    opStack.push(ch);
                else {
                    int a1 = numStack.top();
                    numStack.pop();
                    int a2 = numStack.top();
                    numStack.pop();
                    result = 0;
                    if (op == '+')
                        result = a1 + a2;
                    else if(op == '-')
                        result = a2 - a1;
                    numStack.push(result);
                    opStack.pop();
                    opStack.push(ch);
                }

                break;
            case ' ':
                i++;
                break;
            case ')':
                i++;
                op = opStack.top();
                opStack.pop();
                while (op != '(') {
                    int a1 = numStack.top();
                    numStack.pop();
                    int a2 = numStack.top();
                    numStack.pop();
                    result = 0;
                    if (op == '+')
                        result = a1 + a2;
                    else if(op == '-')
                        result = a2 - a1;
                    numStack.push(result);
                    op = opStack.top();
                    opStack.pop();
                }
                break;
            default:
                a = 0;
                while(ch >= '0' && ch <= '9') {

                    a = a*10 + ch - '0';
                    i++;
                    if(i < s.length())
                        ch = s[i];
                    else
                        break;
                }
                numStack.push(a);
                break;
        }
    }

    while (opStack.empty() == false) {
        op = opStack.top();
        opStack.pop();
        int a1 = numStack.top();
        numStack.pop();
        int a2 = numStack.top();
        numStack.pop();
        result = 0;
        if (op == '+')
            result = a1 + a2;
        else if(op == '-')
            result = a2 - a1;
        numStack.push(result);
    }

    while (numStack.empty() == false) {
        result = numStack.top();
        numStack.pop();
    }

    return result;
}

int main() {
    cout << calculate("(12345)") << endl;
    return 0;
}