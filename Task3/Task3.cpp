#include <iostream>
#include <stack>
using namespace std;

bool check_operator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int evaluatePostfix(char exp[]) {
    stack<int> S;
    int num = 0; // for multi-digit numbers
    bool isNum = false; // flag to indicate if we are in the middle of a number

    for (int i = 0; exp[i]; i++) {
        if (exp[i] == ' ') {
            if (isNum) { // if we were in the middle of a number, push it to the stack
                S.push(num);
                num = 0;
                isNum = false;
            }
        }
        else if (!check_operator(exp[i])) { // if it's a digit
            num = num * 10 + (exp[i] - '0'); // append to num
            isNum = true;
        }
        else { // operator
            int val1 = S.top(); S.pop();
            int val2 = S.top(); S.pop();

            switch (exp[i]) {
            case '+': S.push(val2 + val1); break;
            case '-': S.push(val2 - val1); break;
            case '*': S.push(val2 * val1); break;
            case '/': S.push(val2 / val1); break;
            }
        }
    }

    // if there are still numbers left in num
    if (isNum) {
        S.push(num);
    }

    return S.top();
}

int main() {
    char input[] = "20 30 * 2 +";
    cout << "Evaluation = " << evaluatePostfix(input) << endl;
    return 0;
}