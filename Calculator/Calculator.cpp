#include <iostream>
#include "Stack/stack.h"

using namespace Charles;

int isp(char ch) {
    switch(ch) {
        case '(': return 0;
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
    }
}

int icp(char ch) {
    switch(ch) {
        case '(': return 3;
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
    }
}

bool Isnum(char ch) {
    return (ch>='0')&&(ch<='9');
}

std::string Postfix(std::string s) {
    Stack_Link<char> symbols;
    std::string result = "";
    int n = s.length();
    for (int i=0;i<n;i++) {
        char ch = s[i];
        if (Isnum(ch)) {
            result = result+ch;
            if (!Isnum(s[i+1])) {result = result + ' ';}
        }
        else if (ch==')') {
            while (symbols.Top()!='(') {
                result = result + symbols.Top();
                symbols.Pop();
            }
            symbols.Pop();
        }
        else {
            while ((!symbols.Isempty())&&(icp(ch)<=isp(symbols.Top()))) {
                result = result + symbols.Top();
                symbols.Pop();
            }
            symbols.Push(ch);
        }
    }
    while (!symbols.Isempty()) {
        result = result + symbols.Top();
        symbols.Pop();
    }
    return result;
}

double Calculate(std::string s) {
    Stack_Link<double> numbers;
    int n = s.length();
    double current = 0;
    for (int i=0;i<n;i++){
        char ch = s[i];
        if (Isnum(ch)) {current = current*10+ch-48;}
        else if (ch==' ') {
            numbers.Push(current);
            current = 0;
        }
        else {
            double a = numbers.Top();
            numbers.Pop();
            double b = numbers.Top();
            numbers.Pop();
            switch(ch) {
                case '+': numbers.Push(a+b);break;
                case '-': numbers.Push(b-a);break;
                case '*': numbers.Push(a*b);break;
                case '/': numbers.Push(b/a);break;
            }
        }
    }
    return numbers.Top();
}
int main(){
    std::string a;
    std::cin >> a;
    std::string ss = Postfix(a);
    std::cout << ss << std::endl;
    std::cout << Calculate(ss) << std::endl;
    return 0;
}